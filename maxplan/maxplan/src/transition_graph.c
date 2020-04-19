#include "bb.h"

#include "output.h"
#include "memory.h"

#include "cg_encoding.h"
#include "utilities.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define DTG_DEBUG 0
#define IMP_DEBUG 0

int icmp(const void *p, const void *q){
    const int *m = p, *n = q;
    return *m > *n ? 1 : (*m == *n ? 0 : -1);
}


int exist_in_tg(TransitionGraph *graph, int fact1 , int fact2){
	
	if(fact1==fact2 || fact1==-1 || fact2==-1 ) return -1;    
    int value = fact1;
    
    int *pos = bsearch(&value, graph->element , graph->elementSize, sizeof(int), icmp );
    if ( pos == NULL ) return 0;
    value = fact2;
    pos = bsearch(&value, graph->element , graph->elementSize, sizeof(int), icmp );
    if (pos == NULL) return 0;
    return 1;
}

int coexist(int fact1, int fact2){
	int i;
	if(fact1==fact2 || fact1==-1 || fact2==-1 ) return -1;

	for(i=0;i<transGraphNum;i++)
		if(exist_in_tg(&(transGraph[i]),fact1,fact2)) return i;
	return -1;
}

void print_out_transition_graph(TransitionGraph *graph, int print_option){
    int i,j,l,k,edgeCount=0;

    for(i=0;i<graph->elementSize;i++)
	for(j=0;j<graph->elementSize;j++){
	    TransitionEdge* edge = graph->edge[i][j];
	    if( edge!=NULL && edge->num_action!=0 )
		edgeCount++;
	}

	printf("Graph#%d: [Size%d]; ", graph->id, graph->elementSize);
	if(graph->actor==NULL) printf("[Object: n_ptr]\n");
	    else printf("[actor:%s]" , graph->actor);
	printf("[Edge Count:%d]\n",edgeCount);
	printf("Group elements:");
	for(i=0;i<graph->elementSize;i++){
	    printf("[%d]",graph->element[i]);
	    print_ft_name( graph->element[i] );
	}
	printf("\n");


	for(j=0;j<graph->elementSize;j++)
    for(k=0;k<graph->elementSize;k++){
	    TransitionEdge* edge = graph->edge[j][k];

	    if( edge != NULL && edge->num_action ){

			print_ft_name(graph->element[j]);
			printf(" -->> ");
			print_ft_name(graph->element[k]);
			printf("Action_NUM:(%d)", edge->num_action);
	
			printf("\n");
			for( l=0 ; l<edge->num_action ; l++ ) {
			    printf("   [%d",edge->action[l]);
			    print_op_name(edge->action[l]);
			    printf("[PRE:%d]",gop_conn[edge->action[l]].num_P);
	
			    printf("] {");
			    printf("}\n");
			}
	    }
    }
    
	for(j=0;j<graph->elementSize;j++){
	    for(k=0;k<graph->elementSize;k++){
	    	printf("[%d]",graph->localDistance[j][k]);	
	    }
	    printf("\n");
	}
    printf("\n");
}


void calc_local_distance(TransitionGraph *graph, int *distance_array,  int fromIndex){

    int elementSize = graph->elementSize;
    int visited[MAX_FACT_IN_MUX];
    int expand_list[MAX_FACT_IN_MUX];
    expand_list[0] = fromIndex;
    int expand_list_size = 1;
    int distance = 0;
    int  i,j;

    for( i=0 ; i<elementSize; i++ ){
		visited[i] = 0;
		distance_array[i] = INFINITY_DISTANCE; /**65535 is the largest distance for facts**/
    }

    distance_array[fromIndex] = 0;
	

    do{
		for( i=0 ; i< expand_list_size ; i++)
		    visited[ expand_list[i] ] = 1;

		if(DTG_DEBUG){
			printf("#%d:",distance);
			for(i=0;i<expand_list_size;i++){
				print_ft_name(graph->element[expand_list[i]]);
				printf(";");
			}
			printf("\n");
		}
	
		distance++;
		int tmp_list[MAX_FACT_IN_MUX];
		int tmp_list_size = 0;
	
		for( i=0 ; i<expand_list_size; i++)
		    for( j=0 ; j<elementSize; j++ ){
		    	
		    	TransitionEdge* edge = graph->edge[expand_list[i]][j]; 
			    if (edge!=NULL && edge->num_action!=0  && !visited[j] ) {
					distance_array[ j ] = distance;
					tmp_list[tmp_list_size++] = j;
			    }
		    }

	    expand_list_size = 0;
	    for(i=0;i<tmp_list_size;i++)
			expand_list[ expand_list_size++ ] = tmp_list[i];
    }while( expand_list_size );
    
	if(DTG_DEBUG) printf("done in calc_local_distance()\n");
}


void build_transition_graph(TransitionGraph *graph, int* element,int elementSize,int* connMatrix){

    int i,j,k,l,actionListSize;
    int MAX_TRAN_ACTION = 3000;
    graph->hasGoal = 0;
    int *actionList = malloc( sizeof(int)* MAX_TRAN_ACTION);
    graph->element = malloc( sizeof(int) * elementSize );
    graph->elementSize = 0;

    for( i=0 ; i<elementSize ; i++){

    	if( element[i]<0 ) 
    		printf("Warning[transition_graph.c]: Paring vertex of DTG error!\n" );
		graph->element[graph->elementSize++] = element[i];
		
		for(j=0;j<ggoal_state.num_F;j++)
			graph->hasGoal = (ggoal_state.F[j] == element[i]) ? 1 : 0;
    } 
    
    graph->edge = malloc( sizeof(TransitionEdge**) * elementSize  );
    for(i=0;i<elementSize;i++){
    	graph->edge[i] = malloc( sizeof(TransitionEdge*) * elementSize );
    	for(j=0;j<elementSize;j++) graph->edge[i][j] = NULL;
    }

    for( i=0;i<elementSize;i++)
    for( j=0;j<elementSize;j++){
		if(i==j) continue;
		
		if(DTG_DEBUG){
			printf("In building:");
			print_ft_name(graph->element[i]);printf(" and ");print_ft_name(graph->element[j]);printf("\n");	
		}
		
		actionListSize = 0;
		for(k=0;k<gft_conn[graph->element[i]].num_D;k++){

			int oper = 	gft_conn[graph->element[i]].D[k];
			for(l=0;l<gop_conn[oper].num_A;l++)
				if( graph->element[j] == gop_conn[oper].A[l] ) 
					break;
			if( l<gop_conn[oper].num_A )
		    	actionList[ actionListSize++ ] = oper;
		}
		
		TransitionEdge *edge = NULL;
		if ( actionListSize!=0 ){
		    graph->edge[i][j] = malloc( sizeof( TransitionEdge ) );
			edge = graph->edge[i][j];
			 
			edge->fromIndex = i;
			edge->toIndex = j;
		    edge->num_action = actionListSize;
		    edge->action = malloc( sizeof( int ) * actionListSize );
		    for( k=0;k<actionListSize;k++ )
				edge->action[k] = actionList[ k ];
		}
    }


    graph->localDistance = malloc2DimenArray(elementSize);
    graph->londexValue = malloc2DimenArray(elementSize);
    graph->disabledLondex = malloc2DimenArray(elementSize);
    graph->connMatrix = malloc2DimenArray(elementSize);

    for(i=0;i<elementSize;i++)
		calc_local_distance(graph, graph->localDistance[i], i);
		
    for(i=0;i<elementSize;i++)
	for(j=0;j<elementSize;j++){
	    graph->londexValue[i][j] = graph->localDistance[i][j];
	    graph->disabledLondex[i][j] = (i==j)? 1 :  0;
	    TransitionEdge *edge = graph->edge[i][j];
	    graph->connMatrix[i][j] = (edge!=NULL && edge->num_action) ? 1 : 0; 
	}
			
    for(i=0;i<elementSize;i++)
	for(j=0;j<elementSize;j++){
		if(i==j) continue;
		graph->londexValue[i][j] = graph->localDistance[i][j];
	}

    free( actionList );
    if(DTG_DEBUG)
    	printf("Graph Building done.\n");
}


int get_node_index(TransitionGraph *graph, int factId){
    assert( graph->id >=0 && graph->id<transGraphNum);
    assert( factId>=0 && factId<gnum_ft_conn);
    
	int *pos = bsearch(&factId, graph->element , graph->elementSize, sizeof(int), icmp );
		
	if(pos==NULL) return -1;
		else return  ( pos - graph->element );
}


int get_dijkstra_distance(TransitionGraph* tg, int fromIndex, int toIndex, int* path){

    if( fromIndex == toIndex ){
		path[0] = tg->element[fromIndex];
		return 1;
    }

    if( fromIndex >= tg->elementSize || toIndex >= tg->elementSize ){
		printf("function call of get_dijkstra_distance() error. FromIndex %d, ToIndex%d\n",fromIndex, toIndex);
		return INFINITY_DISTANCE;
    }

    int i,j;
    int NOT_VISITED = -100;

    int visited[MAX_DTG_SIZE];
    int distance = 0;
    for( i=0; i<tg->elementSize ; i++ ) visited[i] = NOT_VISITED;
    visited[fromIndex] = fromIndex;
    int expanding_vertex_list[MAX_DTG_SIZE];
    expanding_vertex_list[0] = fromIndex;
    int expanding_vertex_list_size = 1;

    int no_new_expansion = 1;
    do{
		distance++;
		no_new_expansion = 1;

		int tmp_list[MAX_DTG_SIZE];
		int tmp_list_size = 0;
		int e;
		for( e = 0 ; e<expanding_vertex_list_size ; e++ ){
	
		    int expanding = expanding_vertex_list[e];
		    for( j=0 ; j < tg->elementSize ; j++ ){
				TransitionEdge *edge = tg->edge[expanding][j];
				if( visited[j] != NOT_VISITED ) continue;
		
				if ( edge!=NULL && edge->num_action ){ 
				//if(tg->connMatrix[expanding][j]){ 
				    no_new_expansion = 0;
				    visited[j] = expanding;
				    tmp_list[ tmp_list_size++ ] = j;
		
				    if( j == toIndex ){
						int k = distance;
						int trace_back = j;

						do{
						    path[k] = tg->element[trace_back];
						    k--;
						    trace_back = visited[trace_back];
						}while( k>=0 );

						path[distance++] = tg->element[toIndex];
						return distance;
				    }
				}
		    }
		}

		expanding_vertex_list_size = 0;
		for(i=0;i<tmp_list_size;i++)
		    expanding_vertex_list[expanding_vertex_list_size++] = tmp_list[i];

    }while( !no_new_expansion );

	if(DTG_DEBUG){
		printf("[[%d,%d]]",fromIndex,toIndex);
		i++;
	    printf("CRITICAL ERROR:FAILED to calc the facts:");
	    print_ft_name(tg->element[fromIndex]);
	    printf(" to "); 
	    print_ft_name(tg->element[toIndex]);
	    printf("\n");
	}
	
    return INFINITY_DISTANCE;
}

/*
 * In this function, there is an assumption that all the localDistance are calculated;
 */
int isCriticalPoint(TransitionGraph *graph, int from, int to,int point){
	
	if(point==from || point == to) return 1;
	
	int i,j;
	TransitionGraph tmpGraph;
	tmpGraph.element = malloc(sizeof(int) * graph->elementSize );
	tmpGraph.connMatrix = malloc( sizeof(int) * graph->elementSize * graph->elementSize );
	for(i=0;i<graph->elementSize;i++)
		tmpGraph.element[i] = graph->element[i];
	tmpGraph.elementSize = graph->elementSize;
	
	/* Remove that 'point' */
	for(i=0;i<graph->elementSize;i++)
	for(j=0;j<graph->elementSize;j++){
		if( i==point || j==point ) 
			tmpGraph.connMatrix[i*graph->elementSize+j] = 0;
					
		tmpGraph.connMatrix[i*graph->elementSize+j] = 
			graph->connMatrix[ i*graph->elementSize + j ];
	}
	
	/* Test the connectivity between 'from' and 'to' */
	int path[1000];
	int len = get_dijkstra_distance(&tmpGraph,from,to,path);
	int result = -1;
	if(len == INFINITY_DISTANCE ) result = 1;
		else result = 0;
	
	free(tmpGraph.connMatrix);
	free(tmpGraph.element);
	return result;
}


int get_min_DTG_cost(int fact1, int fact2){
	
	int id;
	int min = 65535;
	int found = 0;
	for(id=0;id<transGraphNum;id++){
		TransitionGraph* tg = &(transGraph[id]);
		
		int index1 = get_node_index(tg,fact1);
		if(index1 == -1 ) continue;
		
		int index2 = get_node_index(tg,fact2);
		if(index2 == -1) continue;
		
		int value = tg->localDistance[index1][index2];
		found = 1;
		if(value<min) min = value;
	}
	
	return found?min:-1;
}



/*
 * 
 * Result:  #1:Returns length of list; 
 * 			#2:Append the array with all the Shared Preconditions;Each cell is fact_id
 */
int get_shared_preconditions(TransitionGraph *tg, TransitionEdge *edge, int* list){

	int i,j,k,succ,chosen_pre;
	if(edge->num_action == 0 ) return 0;
	int list_len = 0;
	
	int first_action = edge->action[0];
		
	for(j=0;j<gop_conn[first_action].num_P;j++  ){
		
		chosen_pre = gop_conn[first_action].P[j]; 
		if (  chosen_pre == tg->element[edge->fromIndex] ) continue;
		
		succ = 1;
		for(i=1;i<edge->num_action;i++){
			
			for(k=0;k<gop_conn[edge->action[i]].num_P;k++)
				if( gop_conn[edge->action[i]].P[k] == chosen_pre )
					break;//found
			
			if( k == gop_conn[edge->action[i]].num_P){ //if not found
				succ = 0;
				break;
			}
		}
		
		if( i==edge->num_action  )
			list[ list_len++ ] = chosen_pre;
	}
	
	return list_len;
}


/*
 * Given two edges, enumerate all the shared-precondition pairs
 * 
 */
int get_depended_londex(TransitionGraph *graph, TransitionEdge *first_edge, TransitionEdge *last_edge){
	int i,j;
	
	int shared_pre_f[50],shared_pre_l[50];
	int shared_pre_f_len,shared_pre_l_len;
	
	shared_pre_f_len = get_shared_preconditions(graph,first_edge, shared_pre_f);
	shared_pre_l_len = get_shared_preconditions(graph,last_edge, shared_pre_l);
	
	int max = 0;
	for(i=0;i<shared_pre_f_len;i++)
	for(j=0;j<shared_pre_l_len;j++){
		
		if(DTG_DEBUG){
			printf("\t\t\tShared Preconditions:");
			print_ft_name(shared_pre_f[i]);
			printf(" and ");
			print_ft_name(shared_pre_l[j]);
			printf("\n");
		}
		
		int value = get_min_DTG_cost( shared_pre_f[i], shared_pre_l[j]);
		if ( max<value )
			max = value;
	}
	
	return max==0?-1:max;
}


/*
 * Get londex value of fact1 and fact2 in a given Transition Graph tg,
 * It only cares and looks for lower lever path value between the starting and end 
 * of the path.
 */
int get_londex(TransitionGraph* tg, int index1, int index2){
	
    if(DTG_DEBUG){
    	printf("Entering get_londex tg%d,  size[%d], index1[%d], index2[%d]", tg->id, tg->elementSize, index1, index2);
    	print_ft_name(tg->element[index1]);
    	printf(";");
    	print_ft_name(tg->element[index2]);
    	printf(";\n");	
    }
    
    int londex = INFINITY_DISTANCE;
    int path_length = 0,value;

    int *path = malloc( sizeof(int) * 1000 );
	
	int i;//,j,k,graphId;
	//int result = INFINITY_DISTANCE;
	
	int min = 65535;
	
	for(i=0;i<tg->elementSize;i++){
		if( tg->edge[index1][i]==NULL || tg->edge[i][index2]==NULL  ) continue;

		//for(j=0;j<tg->elementSize;j++){
		//	if (tg->edge[j][index2]==NULL) continue;	
			
			//if( i !=j )continue;
			
			/*
			path_length = get_dijkstra_distance( tg, i, j, path );
			if(DTG_DEBUG){
				printf("\t [In path]Succ chosen:");print_ft_name(tg->element[i]);
				printf(" and Pred");print_ft_name(tg->element[j]);printf("\n");
			}
			
			for( k=0;k<path_length;k++)
				if( path[k] == tg->element[index1] || path[k]== tg->element[index2] )
					break;
			if( k<path_length ) continue;
			*/
			
		int value = get_depended_londex(tg,tg->edge[index1][i],tg->edge[i][index2]);
		if(DTG_DEBUG) printf("sharted precondtion distance:%d\n",value);
		if( value != -1 ) value += 2;
			else value = 2;
		
		// We need the *maximum* one ammong all the  {index1->i} and {j->index2}
		if( value < min ) min = value;
		//}
	}
	
    free(path);
    return min == 65535 ? -1 : min;
}



void londex_analysis(){
    int i,j,graph_id,k,l;
	
	//This functionality is disabled in this release;
	printf("This functionality is disabled in this release, please don't use this option.\n");
	exit(0);
	
    for(graph_id=0;graph_id<transGraphNum;graph_id++){
		
		TransitionGraph *graph = &(transGraph[graph_id]);
		
		if(DTG_DEBUG)
		printf(">>Londex Analysis %d out of %d, size %d\n",graph_id, transGraphNum , graph->elementSize),fflush(stdout);
		
		
		for(i=0;i<graph->elementSize;i++)
		    for(j=0;j<graph->elementSize;j++){
				if( i==j || graph->localDistance[i][j]==1 || graph->localDistance[i][j]>=65535 ) continue;
				
				
				int value = get_londex( graph, i, j );
				int initValue = graph->londexValue[i][j];
				if(initValue==-1) continue;
				
				if( value!=-1 && value>initValue )
				    graph->londexValue[i][j] = value;
				
				if (DTG_DEBUG) 
					printf("Final value of londex is:[%d], while initial:%d\n\n",value,initValue);
		    }
    }
	
	
	/* I have to check whether all the infinite are INFINITE_DISTANCE, (or -1?)*/

	/*  2rd step of londex improvement computation */
	/*   i  -->  (k ->l)   -->j */
	/*             |---------------------------- IMPROVEMENT IS HERE */
/*
	for(graph_id=0;graph_id<transGraphNum;graph_id++){
		
		TransitionGraph *graph = &(transGraph[graph_id]);
		int size = graph->elementSize;
		for(i=0;i<size;i++)
		for(j=0;j<size;j++){
			
			if( i==j || graph->localDistance[i][j]==INFINITY_DISTANCE  ) continue;
			if( graph->londexValue[i][j] != graph->localDistance[i][j] ) continue; //To Avoid error, CRITICALLY IMPORTANT
			
			if(IMP_DEBUG){
				printf("checking...[");print_ft_name(graph->element[i]);printf(";");print_ft_name(graph->element[j]);printf("\n");	
			}
						
			for(k=0;k<size;k++){
				if(IMP_DEBUG)
					printf("   checking"),print_ft_name(graph->element[k]),printf("\n");
					
				if( j==k || graph->localDistance[i][k]==INFINITY_DISTANCE
					|| graph->localDistance[k][j]==INFINITY_DISTANCE ) continue;
				if( !isCriticalPoint(graph,i,j,k) ) continue;
				
				if(IMP_DEBUG)
					printf("   SUCCESS\n");
				
				for(l=0;l<size;l++){
					if(IMP_DEBUG) printf("      checking"),print_ft_name(graph->element[l]),printf("\n");
										
					if(i==l ||  k==l ) continue;
					if (graph->londexValue[k][l] == graph->localDistance[k][l] ) continue;  // CRITICALLY IMPORTANT
					if (graph->localDistance[k][l]==INFINITY_DISTANCE 
						|| graph->localDistance[i][l]==INFINITY_DISTANCE 
						|| graph->localDistance[l][j]==INFINITY_DISTANCE) continue;
					if( !isCriticalPoint(graph,i,j,l) ) continue;
					
					if(IMP_DEBUG)  printf("      SUCCESS\n");						
					graph->londexValue[ i][j ] = graph->londexValue[k][l] + graph->localDistance[i][k] + graph->localDistance[l][j];
					
					if (IMP_DEBUG){
						printf("      Londex Improvement:["),print_ft_name(graph->element[i]),printf(";"),print_ft_name(graph->element[j]),printf("[%d]\n",graph->londexValue[k][l]);
						printf("      Using ["),print_ft_name(graph->element[k]),printf(","),print_ft_name(graph->element[j]),printf("[%d]\n",graph->londexValue[i][j]);	
					}
				}
			}
		}
	}
*/
	// Check whether graph has goal in it 
	// If so, never ignore it 
    printf("End of Londex Analysis.\n");
    
    if( gcmd_line.printLondex ){
		print_out_londex();exit(0);
    }
}


void print_out_londex(){
	int i,j,g;
	printf("Printing londex:\n");
    for(g=0;g<transGraphNum;g++){
    	
		printf("%dth graph's constraint.\n",g);
		TransitionGraph *tg = &(transGraph[g]);
		for( i=0 ; i<tg->elementSize; i++ )
		    for( j=0 ; j<tg->elementSize; j++ ){
	
				if ( j==i ) continue;
				int londex = tg->londexValue[i][j];  
				if(londex == tg->localDistance[i][j]) continue; 
				
				
				printf("Londex ");
				printf("::[Impv%d]   [Orig%d]\t>>", londex , tg->localDistance[i][j] );
				print_ft_name(tg->element[i]);
				printf("-->");
				print_ft_name(tg->element[j]);
				printf("\n");
		    }
    }
}
