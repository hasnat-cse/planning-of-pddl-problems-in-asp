
#include "bb.h"

#include "output.h"
#include "memory.h"

#include "instantiateI.h"
#include "instantiateII.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "cg_encoding.h" 


/*
 * 	This File includes:
 * 		1. Running londex executbale
 * 		2. Parse londex's output
 */
int gnum_mux_conn;
MuxConn *gmux_conn;
int ff_action[MAX_SOLUTION_ACTION];
int ff_t[MAX_SOLUTION_ACTION];
int ff_level;

int num_ff_action;

int mux_table[MAX_FACT_IN_MUX];
int *mux_connectivity;
int *mux_distance;
int gnum_mux_bit;
int num_fact_in_mutex_group;

struct DisAction *distance_action;


int Mux_BitVector_AND( BitVector *vec1, BitVector *vec2, int vec_len ){
	int i;
	for (i=0; i < vec_len; i++)
	if ( vec1[i]&vec2[i] ) return 1;  

	return 0;
}




int Mux_BitVector( BitVector *vec, int vec_len ){
	int i; 
	for (i=0; i < vec_len; i++)
    	if (vec[i]) return 1;

 	return 0;
}


int position_in_fact_table( char *cg_fact ){

    char str[MAX_LENGTH],cg_upcase[MAX_LENGTH];
    int i,j;

    for(j=0;j<=strlen(cg_fact);j++){
		cg_upcase[j]=toupper(cg_fact[j]);
		if (cg_upcase[j]=='_') cg_upcase[j]='-';
    }

    for ( i=0; i<gnum_ft_conn; i++ ) {
		get_ft_name( i, str );
		if( str[0] =='N' && str[1] =='O' && str[2] =='T' && str[3] =='_') continue;

		for(j=0;j<=strlen(str);j++){
		    str[j]=toupper(str[j]);
		    if (str[j]=='_') str[j]='-';
		}
	
		if ( str == cg_upcase ||
		    /**strcmp( str, cg_upcase ) == SAME||strstr(str,cg_upcase)!=NULL) {**/
			(strcmp( str, cg_upcase ) == SAME && strlen(str)==strlen(cg_upcase) )
			|| ( strstr(str,cg_upcase)!=NULL && strstr(cg_upcase,str)!=NULL )) {
		    break;
		}
    }
    return ( i == gnum_ft_conn ) ? -1 : i;
}


int position_in_action_table( char *ff_action ){
  	char str[MAX_LENGTH],ff_upcase[MAX_LENGTH];
  	int i,j;

	for(j=0;j<=strlen(ff_action);j++){
   		ff_upcase[j]=toupper(ff_action[j]);
   		if (ff_upcase[j]=='_') ff_upcase[j]='-';
   	}

	for ( i=0; i<gnum_op_conn-gnum_relevant_facts; i++ ) {
   		get_op_name( i, str );

		for(j=0;j<=strlen(str);j++){
			str[j]=toupper(str[j]);
	   		if (str[j]=='_') str[j]='-';
		}
	
	    if ( str == ff_upcase ||
		 /**strcmp( str, ff_upcase ) == SAME||strstr(str,ff_upcase)!=NULL) {**/
		  strcmp( str, ff_upcase ) == SAME) {
	      break;
	    }
  	}
  	
	return ( i == gnum_op_conn-gnum_relevant_facts ) ? -1 : i;
}



int position_in_mutex_table(int fact){
	int i;
	for ( i=0; i<num_fact_in_mutex_group; i++ )
		if (mux_table[i]==fact)   break;

  	return ( i == num_fact_in_mutex_group ) ? -1 : i;
}


void calc_distance_fact(int *distance_array,  int fromIndex){

    int visited[MAX_FACT_IN_MUX];
    int expand_list[MAX_FACT_IN_MUX];
    expand_list[0] = fromIndex;
    int expand_list_size = 1;
    int distance = 0;
    int  i,j;

    for( i=0 ; i<num_fact_in_mutex_group; i++ ){
		visited[i] = 0;
		distance_array[i] = INFINITY_DISTANCE; /**65535 is the biggest distance for facts**/
	}

    distance_array[fromIndex] = 0;

    do{
        for( i=0 ; i< expand_list_size ; i++)
            visited[ expand_list[i] ] = 1;

        distance++;
        int tmp_list[MAX_FACT_IN_MUX];
        int tmp_list_size = 0;

        for( i=0 ; i<expand_list_size; i++)
        for( j=0 ; j<num_fact_in_mutex_group; j++ ){
            if (mux_connectivity[expand_list[i]*num_fact_in_mutex_group+j]  && !visited[j] ) {
                distance_array[ j ] = distance;
                tmp_list[tmp_list_size++] = j;
            }
        }

        expand_list_size = 0;
        for(i=0;i<tmp_list_size;i++)
            expand_list[ expand_list_size++ ] = tmp_list[i];
            
    }while( expand_list_size );
    
}




void insert_action_distance(struct DisAction* distance_list, int actionID, int value ){
	struct DisAction * index, *preIndex, *index2;
	if( value <=0 ) return;
	
	preIndex=distance_list;
	for(index=distance_list->next;index&&index->actionID<actionID;preIndex=index,index=index->next);

	if (index==NULL){

	    index= calloc( 1, sizeof( struct DisAction) );
	    index->next=NULL;
	    index->value=value;
	    index->actionID=actionID;
	    preIndex->next=index;

	} else if (index->actionID==actionID)	  {

	    if (index->value<value) index->value=value;
	    
	}else if (index->actionID>actionID)	  {
		
	    index2= calloc( 1, sizeof( struct DisAction) );
	    index2->next=index;
	    index2->value=value;
	    index2->actionID=actionID;
	    preIndex->next=index2;
	}
}

int run_londex(){
    char args[1000];
	sprintf(args,"./londex -o %s -f %s > CG_Temp",gcmd_line.cg_domain_file_name,gcmd_line.cg_problem_file_name);
    int sysCall = system(args);
    
    return 0;
}


void scan_cg_file(void){

#ifndef OS_CYGWIN
	run_londex();
#endif
	
	printf("Start to read DTG info from file:CG_Temp;\n");fflush(stdout);
	FILE * cgFile;
	char  cg_fact[MAX_LENGTH];
	char  cg_fact1[MAX_LENGTH];
	char  cg_fact2[MAX_LENGTH];
	char  actor[MAX_LENGTH];
   
   transGraph = malloc( sizeof(TransitionGraph) * MAX_DTG_NUM );
   TransitionGraph *tg = NULL;
   char* s1="[";
   char* s2="]";
   int i,j,k,l,g;
   int mux,ft,ft1,ft2,op1,op2;
   int d_flag;
   int num_edge_in_mutex_group;
   int ft1_in_mutex,ft2_in_mutex, invariantId;
   struct DisAction *index;
   
   gnum_mux_conn=0;
   clock_t start_clock = clock();
	
   cgFile = fopen ("CG_Temp" , "r");
   if ( cgFile == NULL ) {
       perror ("Error opening file\n");
       exit(1);
   }

    while (! feof(cgFile))   {
		if(fscanf(cgFile, "%s", cg_fact)!=EOF){
		    if ( cg_fact == s1 || (strcmp( cg_fact, s1 ) == SAME) )
		    gnum_mux_conn++;
		}
    }
	
    gmux_conn = ( MuxConn * ) calloc( gnum_mux_conn, sizeof( MuxConn ) );
    CHECK_PTR( gmux_conn );

    gcword_size = sizeof( int ) * 8;
    for ( i = 0; i < gnum_mux_conn; i++ ) {
		gmux_conn[i].uid_block = ( int ) i / gcword_size;
		gmux_conn[i].uid_mask = 1 << ( i % gcword_size );
    }
    gnum_mux_bit = gmux_conn[i-1].uid_block + 1;

    for ( i = 0; i < gnum_op_conn; i++ )
		gop_conn[i].bit_Mux = new_BitVector( gnum_mux_bit );
    for ( i = 0; i < gnum_ft_conn; i++ )
       gft_conn[i].bit_Mux = new_BitVector( gnum_mux_bit );
       

    distance_action = ( struct DisAction *) calloc( gnum_op_conn, sizeof(struct  DisAction) );
    CHECK_PTR( distance_action );
    for ( i = 0; i < gnum_op_conn; i++ ) {
		distance_action[i].next=NULL;
		distance_action[i].value=i;
		distance_action[i].actionID=-1;
    }

    rewind(cgFile);
    mux = -1;
	
    d_flag=0;
    transGraphNum = 0;
    while( !feof(cgFile) ){
		if (d_flag<2){
	
		  if( fscanf(cgFile, "%s", cg_fact)!=EOF ){
		    if ( cg_fact == s1 || (strcmp( cg_fact, s1 ) == SAME) ) {
				mux++;
				d_flag=1;
				num_fact_in_mutex_group=0;
				/**printf("new line:\n");**/
		    }
		    else if ( cg_fact == s2 || (strcmp( cg_fact, s2 ) == SAME) )
			    /**printf("\n");**/
				d_flag=2;
		    else if (d_flag==1){
				/*
				 printf("FFFF%s:",cg_fact);
				printf("PPPP%d \n",position_in_fact_table(cg_fact));
				*/
				
				ft=position_in_fact_table(cg_fact);
							
				if (ft==-1)
				    printf("No match fact![%s]\n",cg_fact);
				else{
					
					for(i=0;i<num_fact_in_mutex_group;i++)
						if( mux_table[i] == ft )
							break;
					if( i<num_fact_in_mutex_group) continue;
					
				    gft_conn[ft].bit_Mux[gmux_conn[mux].uid_block] |= gmux_conn[mux].uid_mask;
					mux_table[num_fact_in_mutex_group++]=ft;
				}
		    }
		  }
	
	  	}else{
	
		    mux_connectivity = ( int *) calloc( num_fact_in_mutex_group * num_fact_in_mutex_group, sizeof( int ) );
		    mux_distance = ( int *) calloc( num_fact_in_mutex_group * num_fact_in_mutex_group, sizeof( int ) );
	
		    memset(mux_connectivity,0, num_fact_in_mutex_group*num_fact_in_mutex_group);
		    qsort(mux_table,num_fact_in_mutex_group,sizeof(int),icmp);
			
			invariantId = -1;
			
		    /*read in edges;*/
		    if( fscanf(cgFile, "%d", &num_edge_in_mutex_group)!=EOF ){
	
				fscanf(cgFile, "%d", &invariantId);
				fscanf(cgFile,"%s",actor);
				/*actorId = position_in_object_table(actor);
				printf("Actor:%s,%d\n",actor,actorId);  */
				for(i=0;i<num_edge_in_mutex_group;i++){
				    fscanf(cgFile, "%s %s",cg_fact1,cg_fact2);
					
				    ft1=position_in_fact_table(cg_fact1);
				    ft2=position_in_fact_table(cg_fact2);
				    if (ft1==-1|| ft2==-1 ) continue;
		
				    ft1_in_mutex = position_in_mutex_table(ft1);
				    ft2_in_mutex = position_in_mutex_table(ft2);
				    mux_connectivity[ ft1_in_mutex * num_fact_in_mutex_group + ft2_in_mutex ] = 1;
				}
		    }

		    for( i=0 ; i<num_fact_in_mutex_group; i++ )
				calc_distance_fact( mux_distance + i*num_fact_in_mutex_group , i );
	
		    /*I can build up graph here;*/
		    tg = &(transGraph[transGraphNum]);
		    tg->id = transGraphNum;
		    tg->invariantId = invariantId;
		    strcpy(tg->actor,actor);	    
		    build_transition_graph( tg, mux_table, num_fact_in_mutex_group, mux_connectivity );
		    transGraphNum++;
	
		    free( mux_distance );
		    free( mux_connectivity );
	
		    d_flag=0;
		}
    }/*end of outermost*/

	free( gmux_conn );
    fclose(cgFile);
   

	if( gcmd_line.londexm == 1 )
		londex_analysis();
						   
    if( gcmd_line.londex_mode != LONDEX_MODE_NONE || gcmd_line.londex_validation ){

	    printf("Inserting londex constraints of actions[by id]:\n");fflush(stdout);
	    for(g=0;g<transGraphNum;g++){
			
			printf("[%d]",g);fflush(stdout);
			TransitionGraph *tg = &(transGraph[g]);
					
			for( i=0 ; i<tg->elementSize; i++ )
		    for( j=0 ; j<tg->elementSize; j++ ){
		    	
				if ( j==i ) continue;
				int londex = 	gcmd_line.londexm == 1? 
								tg->londexValue[i][j] : 
								tg->localDistance[i][j];
			
					
				for(k=0;k<gft_conn[tg->element[i]].num_P;k++)
				for(l=0;l<gft_conn[tg->element[j]].num_P;l++){
	            	op1=gft_conn[tg->element[i]].P[k];
	              	op2=gft_conn[tg->element[j]].P[l];
	              	
					if( op1==op2 ) continue;
					insert_action_distance( &(distance_action[op1]), op2 , londex );
		    	}
	
				for(k=0;k<gft_conn[tg->element[i]].num_A;k++)
    			for(l=0;l<gft_conn[tg->element[j]].num_A;l++){
    				op1=gft_conn[tg->element[i]].A[k];
      				op2=gft_conn[tg->element[j]].A[l];
					if(op1==op2) continue; 
				
      				insert_action_distance( &(distance_action[op1]), op2, londex );
    			}

		         for(k=0;k<gft_conn[tg->element[i]].num_A;k++)
	            for(l=0;l<gft_conn[tg->element[j]].num_P;l++){
	             	op1=gft_conn[tg->element[i]].A[k];
	              	op2=gft_conn[tg->element[j]].P[l];
	              	
					if( op1==op2 ) continue;
	              	insert_action_distance( &(distance_action[op1]), op2, londex+1 );
	            }
	
				if(londex>=2)
				for(k=0;k<gft_conn[tg->element[i]].num_P;k++)
		        for(l=0;l<gft_conn[tg->element[j]].num_A;l++){
		            	op1=gft_conn[tg->element[i]].P[k];
		              	op2=gft_conn[tg->element[j]].A[l];

						if ( op1 == op2 ) continue;						
		              	insert_action_distance( &(distance_action[op1]), op2, londex-1 );
				}
		    }
	    }

		for ( i = 0; i < gnum_op_conn; i++ ) {
			for ( j = 0; j < gop_conn[i].num_P; j++ ) {
			      ft = gop_conn[i].P[j];
			      for (k=0; k < gnum_mux_bit; k++) 
			  		gop_conn[i].bit_Mux[k] |= gft_conn[ft].bit_Mux[k];
			}
			
			for ( j = 0; j < gop_conn[i].num_A; j++ ) {
		      	ft = gop_conn[i].A[j];
		      	for (k=0; k < gnum_mux_bit; k++) 
		  			gop_conn[i].bit_Mux[k] |= gft_conn[ft].bit_Mux[k];
		    }
	  	}

    	int time_used = (clock() - start_clock)/CLOCKS_PER_SEC;
    	printf( "\n-- CG parsing and Londex computation cost %d seconds.\n", time_used );fflush(stdout);
    }
    
    
    if ( gcmd_line.display_info == 113 ) {
		printf("\n\nFact ARRAY:");
		for ( i = 0; i < gnum_ft_conn; i++ ) {
		    print_ft_name( i );
		    print_BitVector( gft_conn[i].bit_Mux, gnum_mux_bit ); printf("\n");
		}
		printf("\n\nOP ARRAY:");
		for ( i = 0; i < gnum_op_conn; i++ ) {
		    print_op_name( i );
		    print_BitVector( gop_conn[i].bit_Mux, gnum_mux_bit );printf("\n");
		}
    }
  	
  	/*
  	 *  Process the pair of fact londex;
  	 */
  	 printf("processing fact londex...\n");
	f_f_mutex = malloc(sizeof(int*) * gnum_ft_conn );
	for( i=0; i<gnum_ft_conn; i++ ){
		f_f_mutex[i] = malloc( sizeof(int) * gnum_ft_conn );
		for( j=0; j<gnum_ft_conn; j++ )
			f_f_mutex[i][j] = -1;
	}

	for(g=0;g<transGraphNum;g++){
		
		tg = &(transGraph[g]);
		for(i=0;i<tg->elementSize;i++)
		for(j=0;j<tg->elementSize;j++){
			if(i==j) continue;
			
			int eI = tg->element[i];
			int eJ = tg->element[j];
			
			int value = 	gcmd_line.londexm == 1 ? 
							tg->londexValue[i][j] : 
							tg->localDistance[i][j];

			if( f_f_mutex[eI][eJ] == -1)
				f_f_mutex[eI][eJ] = value;
			else if ( f_f_mutex[eI][eJ] > value )
				f_f_mutex[eI][eJ] = value;
		}
	}
	// End of processing Fact_Fact_mutex data structure;
	
	/*
	 * process the pair to pair mutex;
	 */
	if( gcmd_line.londex_mode != LONDEX_MODE_NONE || gcmd_line.londex_validation){
	    int op;
		a_a_mutex = ( char ** ) calloc( gnum_op_conn, sizeof( char * ) );
		for ( i = 0; i < gnum_op_conn; i++ ) {
			a_a_mutex[i] = ( char * ) calloc( gnum_op_conn-i-1 , sizeof( char ) );
			for ( j = i+1; j < gnum_op_conn; j++ )
		    	a_a_mutex[i][j-i-1] = 0;
	    }
		
	
		for(i=0; i<gnum_op_conn;i++){
			if (!Mux_BitVector( gop_conn[i].bit_Mux, gnum_mux_bit)) continue;
		  	int ft1, ft2;
		  	
			for ( op = i+1; op < gnum_op_conn; op++ ) {
				if (  !Mux_BitVector_AND( gop_conn[i].bit_Mux,gop_conn[op].bit_Mux, gnum_mux_bit)) continue;
				int mux_flag = 0;
			   
				for ( j = 0; j < (gop_conn[i].num_P&&(!mux_flag)); j++ ) {
					ft1 = gop_conn[i].P[j];
					for ( k = 0; k < (gop_conn[op].num_P&&(!mux_flag)); k++ ) {
						ft2 = gop_conn[op].P[k];
						if ((ft1!=ft2) && Mux_BitVector_AND( gft_conn[ft1].bit_Mux, gft_conn[ft2].bit_Mux, gnum_mux_bit)) mux_flag=1;
					}	
				}
	
				for ( j = 0; j < gop_conn[i].num_P&&!mux_flag; j++ ) {
					ft1 = gop_conn[i].P[j];
					for ( k = 0; k < gop_conn[op].num_A&&!mux_flag; k++ ) {
						ft2 = gop_conn[op].A[k];
						if ((ft1!=ft2) && Mux_BitVector_AND( gft_conn[ft1].bit_Mux, gft_conn[ft2].bit_Mux, gnum_mux_bit)) mux_flag=1;
					}
				}
	
				for ( j = 0; j < gop_conn[i].num_A&&!mux_flag; j++ ) {
					ft1 = gop_conn[i].A[j];
					for ( k = 0; k < gop_conn[op].num_P&&!mux_flag; k++ ) {
						ft2 = gop_conn[op].P[k];
						if ((ft1!=ft2) && Mux_BitVector_AND( gft_conn[ft1].bit_Mux, gft_conn[ft2].bit_Mux, gnum_mux_bit) ) mux_flag=1;
					}
				}
	
				for ( j = 0; j < gop_conn[i].num_A&&!mux_flag; j++ ) {
					ft1 = gop_conn[i].A[j];
					for ( k = 0; k < gop_conn[op].num_A&&!mux_flag; k++ ) {
						ft2 = gop_conn[op].A[k];
						if ((ft1!=ft2) && Mux_BitVector_AND( gft_conn[ft1].bit_Mux, gft_conn[ft2].bit_Mux, gnum_mux_bit)) mux_flag=1;
					}
				}
	
				if (mux_flag) a_a_mutex[i][op-i-1]=1;
			 }
		}
	
		for(i=0;i<gnum_op_conn;i++) free(gop_conn[i].bit_Mux);
		for(i=0;i<gnum_ft_conn;i++) free(gft_conn[i].bit_Mux);
	}
}

