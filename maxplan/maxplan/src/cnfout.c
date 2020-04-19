
/*********************************************************************
 * (C) Copyright 1999 Albert Ludwigs University Freiburg
 *     Institute of Computer Science
 *
 * All rights reserved. Use of this software is permitted for 
 * non-commercial research purposes, and it may be copied only 
 * for that use.  All copies must include this copyright message.
 * This software is made available AS IS, and neither the authors
 * nor the  Albert Ludwigs University Freiburg make any warranty
 * about the software or its performance. 
 *********************************************************************/










/*********************************************************************
 * File: backdoors.c
 * Description: functions for cnf output
 *
 * Author: Joerg Hoffmann 2003
 *********************************************************************/ 




#include "vec.h"
#include "bb.h"

#include "output.h"
#include "memory.h"

#include "instantiateI.h"
#include "instantiateII.h"

#include "graph.h"

#include "cnfout.h"
#include "cg_encoding.h"
#include "solver.h"
#include "utilities.h"

#include <time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h> 

int **lclause;
int *lclause_size;
int lnum_clauses;


extern const int UNSAT; //2
extern const int SAT;	//0

int minisat_initialized = 0;
void init_solver(); /* Use global variables */
solver* minisat = NULL;
float encoding_time = 0, solving_time = 0;

int do_cnf_output(int create)
{
	float time_slice;
	gcmd_line.cnfout = 1;		
	times(&start);
	
	int result;
    if ( gcmd_line.cnfout == 1 ) {
    	
		result = print_action_based_encoding( gcmd_line.cnflayer, create );
    
    }else{
	
	    printf("\n\nEXIT: cnf out %d not implemented\n\n", gcmd_line.cnfout);
		exit(1);
    }

	times(&end);
	TIME( encoding_time );
    return result;
}



extern struct DisAction* distance_action;
int *F, *A;   
    
/* action-based
 */
int print_action_based_encoding( int layer, int create )
{
	check_memory_usage();
    FILE *CNF, *VARFILE;

    int i, j, t, k, ft, op, prevcl, l, result=0;
    int tmpNumber;

    int *lop_pos1, *lop_pos2;
    
    int nGclauses = 0, nAclauses = 0, nEclauses = 0;

    lclause = ( int ** ) calloc( MAX_CLAUSES, sizeof( int * ) );
    lclause_size = ( int * ) calloc( MAX_CLAUSES, sizeof( int ) );
    lop_pos1 = ( int * ) calloc( MAX_CNF_VARS, sizeof( int ) );  
    lop_pos2 = ( int * ) calloc( MAX_CNF_VARS, sizeof( int ) );      
    lcode = ( int ** ) calloc( layer, sizeof( int * ) );
    lop_to_code = ( int * ) calloc( MAX_CNF_VARS, sizeof( int ) );
    ltime_to_code = ( int * ) calloc( MAX_CNF_VARS, sizeof( int ) );
    for ( i = 0; i < layer; i++ ) {
		lcode[i] = ( int * ) calloc( gnum_op_conn, sizeof( int ) );
		for ( j = 0; j < gnum_op_conn; j++ )
		    lcode[i][j] = -1;
    }
    
	for(i=0;i<MAX_CNF_VARS;i++) lop_pos1[i]=-1;

    F  = ( int * ) calloc( gnum_ft_conn, sizeof( int ) );
    for ( i = 0; i < gnum_ft_conn; i++ )
		F[i] = -1;
		
    /* no-ops are included in the gop_conn!
     */
    A  = ( int * ) calloc( gnum_op_conn, sizeof( int ) );
    for ( i = 0; i < gnum_op_conn; i++ )
		A[i] = -1;

    /* layer 0 */
    for ( i = 0; i < ginitial_state.num_F; i++ )
		F[ginitial_state.F[i]] = 0;
	
    printf("\ncreating action-based encoding:");

    /* prec constraints, + code assignment.
     */
    lnum_clauses = 0;
    code = 1; /* variables numbered 1 .. n */
    printf("\n        building rplan graph layers, up to layer [%d];", layer);
    for ( t = 0; t < layer; t++ ) {	
	for ( i = 0; i < gnum_op_conn; i++ ) {
	    if ( A[i] == -1 ) {
			for ( j = 0; j < gop_conn[i].num_P; j++ )
			    if ( F[gop_conn[i].P[j]] == -1 || F[gop_conn[i].P[j]] > t ) 
			    	break;
			if ( j < gop_conn[i].num_P ) continue;
			/* now i is an op that comes in here.
			 */
			A[i] = t;
			/* mark its add effects.
			 */
			for ( j = 0; j < gop_conn[i].num_A; j++ ) {
			    ft =  gop_conn[i].A[j];
			    if ( F[ft] != -1 ) continue;
			    F[ft] = t+1;
			}
	    }

	    /* insert prec clauses, if at t > 0.
	     */
	    if ( t == 0 ) {
			continue;
	    }
	    for ( j = 0; j < gop_conn[i].num_P; j++ ) {
			ft =  gop_conn[i].P[j];
	
			if ( lnum_clauses == MAX_CLAUSES ) {
			    printf("\n\nEXIT: too many clauses. increase MAX_CLAUSES.\n\n");
			    exit( 1 );
			}
			lclause[lnum_clauses] = ( int * ) calloc( gft_conn[ft].num_A+1, sizeof( int ) );
			/* here the op i is used at t, for the 1st time. assign the code.
			 */
			if ( j == 0 ) {
			    if ( lcode[t][i] != -1 ) {
					printf("\n\nEXIT: op code %d at %d already assigned??\n\n", i, t);
					exit( 1 );
			    }
			    lcode[t][i] = code++;
			    if ( code == MAX_CNF_VARS + 1 ) {
					printf("\n\nEXIT: too many cnf vars. increase MAX_CNF_VARS.\n\n");
					exit( 1 );
			    }
			    lop_to_code[code-1] = i;
			    ltime_to_code[code-1] = t;
			}
	
			lclause[lnum_clauses][0] = (-1) * lcode[t][i];
			lclause_size[lnum_clauses] = 1;
			for ( k = 0; k < gft_conn[ft].num_A; k++ ) {
			    op = gft_conn[ft].A[k];
			    if ( A[op] == -1 || A[op] > t-1 )
					continue;
			    if ( lcode[t-1][op] == -1 ) {
					lcode[t-1][op] = code++;
					if ( code == MAX_CNF_VARS + 1 ) {
					    printf("\n\nEXIT: too many cnf vars. increase MAX_CNF_VARS.\n\n");
					    exit( 1 );
					}
					lop_to_code[code-1] = op;
					ltime_to_code[code-1] = t-1;
			    }
			    lclause[lnum_clauses][lclause_size[lnum_clauses]++] = lcode[t-1][op];
			}
			if ( lclause_size[lnum_clauses] == 1 ) {
				lnum_clauses++;
			    printf("\n\nEXIT: no achiever in at t>0??\n\n");
			    //exit( 1 );
			    result = UNSAT;
			    goto freeandquit;
			}
			nAclauses++;
			lnum_clauses++;
	    } /* pres of i-op */
	} /* i -- op */
    } /* t */


    /* goal constraints
     */
    printf("\n        goal constraints;");
    for ( i = 0; i < ggoal_state.num_F; i++ ) {
		ft = ggoal_state.F[i];
	
		if ( lnum_clauses == MAX_CLAUSES ) {
		    printf("\n\nEXIT: too many clauses. increase MAX_CLAUSES.\n\n");
		    exit( 1 );
		}
		lclause[lnum_clauses] = ( int * ) calloc( gft_conn[ft].num_A, sizeof( int ) );
		lclause_size[lnum_clauses] = 0;
		for ( k = 0; k < gft_conn[ft].num_A; k++ ) {
		    op = gft_conn[ft].A[k];
		    if ( A[op] == -1 || A[op] > layer-1 )
				continue;
		    if ( lcode[layer-1][op] == -1 ) {
				lcode[layer-1][op] = code++;
				if ( code == MAX_CNF_VARS + 1 ) {
				    printf("\n\nEXIT: too many cnf vars. increase MAX_CNF_VARS.\n\n");
				    exit( 1 );
				}
				lop_to_code[code-1] = op;
				ltime_to_code[code-1] = layer-1;
		    }
		    lclause[lnum_clauses][lclause_size[lnum_clauses]++] = lcode[layer-1][op];
		}
		if ( lclause_size[lnum_clauses] == 0 ) {
		    printf("\n\nno achiever in for goal?? deadline too low!#001\n\n");
		    lnum_clauses++;
		    //exit(UNSAT);
		    result = UNSAT;
		    goto freeandquit;
		}
		lnum_clauses++;
		nGclauses++;
    } /* goals */

 
    /* exclusion constraints. implementation a bit smart, to avoid
     * time-consuming all-op-pairs-check.
     */
	printf("\n        building exclusion constraints --> up to layer %d...", layer);fflush(stdout);
    for ( t = 0; t < layer; t++ ) {
	for ( i = 0; i < gnum_op_conn; i++ ) {
	    if ( A[i] == -1 || A[i] > t ) continue;
	    prevcl = lnum_clauses;
	    for ( j = 0; j < gop_conn[i].num_D; j++ ) {
			ft = gop_conn[i].D[j];
			for ( k = 0; k < gft_conn[ft].num_P; k++ ) {
			    op = gft_conn[ft].P[k];
			    if ( op <= i ) continue; /* only in one of the two dirs we'll get */
			    if ( A[op] == -1 || A[op] > t ) continue;
			    /* did we make op excl of i already?
			     */
			    if ( lcode[t][op] != -1 ) {
					for ( l = prevcl; l < lnum_clauses; l++ ) {
					    if ( lclause[l][1] == (-1) * lcode[t][op] ) break;
					}
					if ( l < lnum_clauses ) continue; /* yes. */
			    }
			    /* record the clause.
			     */
			    if ( lnum_clauses == MAX_CLAUSES ) {
					printf("\n\nEXIT: too many clauses. increase MAX_CLAUSES.\n\n");
					exit( 1 );
			    }
			    lclause[lnum_clauses] = ( int * ) calloc( 2, sizeof( int ) );
			    if ( lcode[t][i] == -1 ) {
					lcode[t][i] = code++;
					if ( code == MAX_CNF_VARS + 1 ) {
					    printf("\n\nEXIT: too many cnf vars. increase MAX_CNF_VARS.\n\n");
					    exit( 1 );
					}
					lop_to_code[code-1] = i;
					ltime_to_code[code-1] = t;
			    }
				lop_pos1[lcode[t][i]]=prevcl;
			    lclause[lnum_clauses][0] = (-1) * lcode[t][i];
			    if ( lcode[t][op] == -1 ) {
					lcode[t][op] = code++;
					if ( code == MAX_CNF_VARS + 1 ) {
					    printf("\n\nEXIT: too many cnf vars. increase MAX_CNF_VARS.\n\n");
					    exit( 1 );
					}
					lop_to_code[code-1] = op;
					ltime_to_code[code-1] = t;
			    }
			    lclause[lnum_clauses][1] = (-1) * lcode[t][op];
			    lclause_size[lnum_clauses] = 2;
				lop_pos2[lcode[t][i]]=lnum_clauses;
			    lnum_clauses++;
			    nEclauses++;
			} /* k: ops that ft is pre of */
			for ( k = 0; k < gft_conn[ft].num_A; k++ ) {
			    op = gft_conn[ft].A[k];
			    if ( op <= i ) continue; /* only in one of the two dirs we'll get */
			    if ( A[op] == -1 || A[op] > t ) continue;
			    /* did we make op excl of i already?
			     */
			    if ( lcode[t][op] != -1 ) {
					for ( l = prevcl; l < lnum_clauses; l++ ) {
					    if ( lclause[l][1] == (-1) * lcode[t][op] ) break;
					}
					if ( l < lnum_clauses ) continue; /* yes. */
			    }
			    /* record the clause.
			     */
			    if ( lnum_clauses == MAX_CLAUSES ) {
					printf("\n\nEXIT: too many clauses. increase MAX_CLAUSES.\n\n");
					exit( 1 );
			    }
			    lclause[lnum_clauses] = ( int * ) calloc( 2, sizeof( int ) );
			    if ( lcode[t][i] == -1 ) {
					lcode[t][i] = code++;
					if ( code == MAX_CNF_VARS + 1 ) {
					    printf("\n\nEXIT: too many cnf vars. increase MAX_CNF_VARS.\n\n");
					    exit( 1 );
					}
					lop_to_code[code-1] = i;
					ltime_to_code[code-1] = t;
			    }
				lop_pos1[lcode[t][i]]=prevcl;			    
			    lclause[lnum_clauses][0] = (-1) * lcode[t][i];
			    if ( lcode[t][op] == -1 ) {
					lcode[t][op] = code++;
					if ( code == MAX_CNF_VARS + 1 ) {
					    printf("\n\nEXIT: too many cnf vars. increase MAX_CNF_VARS.\n\n");
					    exit( 1 );
					}
					lop_to_code[code-1] = op;
					ltime_to_code[code-1] = t;
			    }
			    lclause[lnum_clauses][1] = (-1) * lcode[t][op];
			    lclause_size[lnum_clauses] = 2;
				lop_pos2[lcode[t][i]]=lnum_clauses;
			    lnum_clauses++;
			    nEclauses++;
			} /* k: ops that ft is added by */
	    } /* j: fts that i dels */


	    for ( j = 0; j < gop_conn[i].num_P; j++ ) {
			ft = gop_conn[i].P[j];
			for ( k = 0; k < gft_conn[ft].num_D; k++ ) {
			    op = gft_conn[ft].D[k];
			    if ( op <= i ) continue; /* only in one of the two dirs we'll get */
			    if ( A[op] == -1 || A[op] > t ) continue;
			    /* did we make op excl of i already?
			     */
			    if ( lcode[t][op] != -1 ) {
					for ( l = prevcl; l < lnum_clauses; l++ ) {
					    if ( lclause[l][1] == (-1) * lcode[t][op] ) break;
					}
					if ( l < lnum_clauses ) continue; /* yes. */
			    }
			    /* record the clause.
			     */
			    if ( lnum_clauses == MAX_CLAUSES ) {
				printf("\n\nEXIT: too many clauses. increase MAX_CLAUSES.\n\n");
				exit( 1 );
			    }
			    lclause[lnum_clauses] = ( int * ) calloc( 2, sizeof( int ) );
			    if ( lcode[t][i] == -1 ) {
					lcode[t][i] = code++;
					if ( code == MAX_CNF_VARS + 1 ) {
					    printf("\n\nEXIT: too many cnf vars. increase MAX_CNF_VARS.\n\n");
					    exit( 1 );
					}
					lop_to_code[code-1] = i;
					ltime_to_code[code-1] = t;
			    }
				lop_pos1[lcode[t][i]]=prevcl;			    
			    lclause[lnum_clauses][0] = (-1) * lcode[t][i];
			    if ( lcode[t][op] == -1 ) {
					lcode[t][op] = code++;
					if ( code == MAX_CNF_VARS + 1 ) {
					    printf("\n\nEXIT: too many cnf vars. increase MAX_CNF_VARS.\n\n");
					    exit( 1 );
					}
					lop_to_code[code-1] = op;
					ltime_to_code[code-1] = t;
			    }
			    lclause[lnum_clauses][1] = (-1) * lcode[t][op];
			    lclause_size[lnum_clauses] = 2;
				lop_pos2[lcode[t][i]]=lnum_clauses;			    
			    lnum_clauses++;
			    nEclauses++;
			} /* k: ops that ft is del by */
	    } /* j: fts that i has as prec */

	    for ( j = 0; j < gop_conn[i].num_A; j++ ) {
			ft = gop_conn[i].A[j];
			for ( k = 0; k < gft_conn[ft].num_D; k++ ) {
			    op = gft_conn[ft].D[k];
			    if ( op <= i ) continue; /* only in one of the two dirs we'll get */
			    if ( A[op] == -1 || A[op] > t ) continue;
			    /* did we make op excl of i already?
			     */
			    if ( lcode[t][op] != -1 ) {
					for ( l = prevcl; l < lnum_clauses; l++ ) {
					    if ( lclause[l][1] == (-1) * lcode[t][op] ) break;
					}
					if ( l < lnum_clauses ) continue; /* yes. */
			    }
			    /* record the clause.
			     */
			    if ( lnum_clauses == MAX_CLAUSES ) {
					printf("\n\nEXIT: too many clauses. increase MAX_CLAUSES.\n\n");
					exit( 1 );
			    }
			    lclause[lnum_clauses] = ( int * ) calloc( 2, sizeof( int ) );
			    if ( lcode[t][i] == -1 ) {
					lcode[t][i] = code++;
					if ( code == MAX_CNF_VARS + 1 ) {
					    printf("\n\nEXIT: too many cnf vars. increase MAX_CNF_VARS.\n\n");
					    exit( 1 );
					}
					lop_to_code[code-1] = i;
					ltime_to_code[code-1] = t;
			    }
				lop_pos1[lcode[t][i]]=prevcl;		    
			    lclause[lnum_clauses][0] = (-1) * lcode[t][i];
			    if ( lcode[t][op] == -1 ) {
					lcode[t][op] = code++;
					if ( code == MAX_CNF_VARS + 1 ) {
					    printf("\n\nEXIT: too many cnf vars. increase MAX_CNF_VARS.\n\n");
					    exit( 1 );
					}
					lop_to_code[code-1] = op;
					ltime_to_code[code-1] = t;
			    }
			    lclause[lnum_clauses][1] = (-1) * lcode[t][op];
			    lclause_size[lnum_clauses] = 2;
				lop_pos2[lcode[t][i]]=lnum_clauses;		    
			    lnum_clauses++;
			    nEclauses++;
			} /* k: ops that ft is del by */
	    } /* j: fts that i adds */
	} /* i: ops at t */
    } /* t */


    /* that's it. print CNF file.
     */
    if ( gcmd_line.debug ) {
		if ( (VARFILE = fopen( gcmd_line.varFileName, "w" )) == NULL ) {
		    printf("\n\nEXIT: can't open VARFILE file.\n\n");
		    exit( 1 );
		}
		fprintf(VARFILE, "\n\nc DECISION LAYER %d, ACTION-BASED ENCODING.", layer);
		fprintf(VARFILE, "\n\nc VARS:");
	
	        
		for ( i = 1; i < code; i++ ) {
			fprintf(VARFILE, "\nc var %2d action (", i);
	  	    print_op_nameToFile( lop_to_code[i], VARFILE );
		    fprintf(VARFILE, ") %d", ltime_to_code[i] );
		} 
	
        fclose(VARFILE);
    }

    printf("\n\nDECISION LAYER %d, WRITING ACTION-BASED ENCODING WITH %d VARS, %d CLAUSES.", 
	   layer, code-1, lnum_clauses);
    printf("\n%d G clauses, %d A clauses, %d E clauses.", 
	   nGclauses, nAclauses, nEclauses);
    
	
	if ( create == 0 ) {

		printf("c CNF file planning task -p %s, -o %s, -f %s, bound %d, action based encoding\n",
			gcmd_line.path, gcmd_line.ops_file_name, gcmd_line.fct_file_name, layer);
      
		tmpNumber = lnum_clauses;
		if ( gcmd_line.binary_clause_only != 0 ) {
			for ( i = 0; i < tmpNumber; ++i ) {
				if ( lclause_size[i] > 2 ) --lnum_clauses;
			}
      	}
		printf("In building up solver: p cnf %d %d\n", code-1, lnum_clauses);
      
		veci tmp_lits;
    	veci_new(&tmp_lits);
    	
		for ( i = 0; i <tmpNumber ; i++ ) {
	        lit* begin;
			veci_resize(&tmp_lits,0);
		  	
		  	for ( j = 0; j < lclause_size[i]; j++ ) {
		  		int var;
				var = abs(lclause[i][j])-1;
		    	/*fprintf(CNF, "%d ", lclause[i][j]);*/
				veci_push(&tmp_lits, (lclause[i][j] > 0 ? toLit(var) : lit_neg(toLit(var))));
			}
			
			begin = veci_begin(&tmp_lits);
	    	if (!solver_addclause( minisat, begin, begin+veci_size(&tmp_lits))){
	        	//veci_delete(&tmp_lits);
	        	//printf("CRITICAL ERROR! CANNOT ADD CLAUSE ANY MORE.\n");
	        	//exit(-1);
	        }
			free(lclause[i]);lclause[i]=NULL;
  		}
		free(lclause);
		lclause = NULL;
		veci_delete(&tmp_lits);
    }
    
  	freeandquit:
  		if(lop_pos1) free(lop_pos1);
  		if(lop_pos2) free(lop_pos2);
  		
    return result;
}


/*For the potentially required solver initialization;*/ 
void init_solver(){
	int i,op;
	minisat = solver_new();


	/* It's important;
	 * for this part of constraints, they might be removed during searching;*/
	if( gcmd_line.londex_mode != LONDEX_MODE_NONE ) {
		/* This is only for londex's action-based encoding; 
		for(i=0; i<gnum_op_conn;i++){
			for ( op = i+1; op < gnum_op_conn; op++ )
				if( a_a_mutex[i][op-i-1] )
					insert_action_distance( &(distance_action[i]), op, 1 );
		}
		*/
	}
}

void post_solving(int solverResult){

	if( solverResult == SAT ) return;
	int i;
	if (minisat!=NULL) solver_delete(minisat);
	if(lclause_size!=NULL) free(lclause_size);
  	if(lclause){
  		for(i=0;i<lnum_clauses;i++)
  			if(lclause[i]) free(lclause[i]);
  		free(lclause);
  	}
  	
  	/* action coding */
  	if(lcode!=NULL){
  		for(i=0;i<gcmd_line.cnflayer;i++)
  			if (lcode[i]!=NULL) free(lcode[i]);
  		free(lcode);
  	}
  	if(lop_to_code!=NULL) free(lop_to_code);
  	if(ltime_to_code!=NULL) free(ltime_to_code);
  	
  	/* fact coding*/
  	if(fcode!=NULL){
  		for(i=0;i<gcmd_line.cnflayer;i++)
  			if (fcode[i]!=NULL) free(fcode[i]);
  		free(fcode);
  	}
  	if(fop_to_code!=NULL) free(fop_to_code);
  	if(ftime_to_code!=NULL) free(ftime_to_code);
  	  	  	
  	if(F!=NULL) free(F);
  	if(A!=NULL) free(A);
  	
  	free(code_type);
}

void printStats(stats* stats, int cpu_time)
{
    double Time    = (float)(cpu_time)/(float)(CLOCKS_PER_SEC);
    printf("restarts          : %12d\n", stats->starts);
    printf("conflicts         : %12.0f           (%9.0f / sec      )\n",  (double)stats->conflicts   , (double)stats->conflicts   /Time);
    printf("decisions         : %12.0f           (%9.0f / sec      )\n",  (double)stats->decisions   , (double)stats->decisions   /Time);
    printf("propagations      : %12.0f           (%9.0f / sec      )\n",  (double)stats->propagations, (double)stats->propagations/Time);
    printf("inspects          : %12.0f           (%9.0f / sec      )\n",  (double)stats->inspects    , (double)stats->inspects    /Time);
    printf("conflict literals : %12.0f           (%9.2f %% deleted  )\n", (double)stats->tot_literals, (double)(stats->max_literals - stats->tot_literals) * 100.0 / (double)stats->max_literals);
    printf("CPU time          : %12.2f sec\n", Time);
}



/*
 * Return value is sat or not;
 */
int execute_solver(int create){
	
	if ( do_cnf_output(create)!=SAT )
		return UNSAT;
	
	int     clk = clock();

	check_memory_usage();
    minisat->verbosity = 1;	
    
    times(&start);
	lbool st = solver_solve( minisat , 0 , 0 );
	times(&end);
	TIME( solving_time );
	
	check_memory_usage();
	printStats(&minisat->stats, clock() - clk);
	printf( st == l_True ? "SATISFIABLE\n" : "UNSATISFIABLE\n" );
	
    FILE* wf = fopen("bb_solving_result_cnf", "w");	

    if ( st == l_True ){
        int i;
		fprintf(wf, "SAT");
		for (i = 0; i < minisat->model.size; i++)
			fprintf(wf, "%s%s%d", (i==0)?"":" ", (minisat->model.ptr[i]==l_True)?"":"-", i+1);
		fprintf(wf, " 0\n");
    }else
		fprintf(wf, "UNSAT\n");
	fclose(wf);
    
    return st==l_True? SAT : UNSAT;
}

