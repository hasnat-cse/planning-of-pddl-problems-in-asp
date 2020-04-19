
/*********************************************************************
 * (C) Copyright 2006  Washington University in Saint Louis
 *     Department of Computer science and engineering
 *     One Brookings Hall, Saint Louis, MO 63130 USA
 *
 * All rights reserved. Use of this software is permitted ONLY for
 * non-commercial research purposes, and it may be copied only
 * for that use only. All copies must include this copyright message.
 * This software is made available AS IS, and neither the authors
 * nor the Washington University in St.Louis make any warranty about the
 * software or its performance.
 *
 *********************************************************************/


/***********************************************************************
 * File: dis_cg_partial_plan.c
 * Description: functions for generating londex constraints
 *
 * Author: Ruoyun Huang, Yixin Chen 2006
 *
 *********************************************************************/ 

#include "dis_ff.h"
#include "casual_graph.h"

const int CALC_LEVEL = 2;
const int MAX_PATH_LEN = 1000;


int get_dijkstra_distance(dis_TransitiveGraph* tg, int fromIndex, int toIndex, int* path){

	if( fromIndex == toIndex ){
		path[0] = fromIndex;
		return 1;
	}

	if( fromIndex >= tg->elementSize || toIndex >= tg->elementSize ){
		printf("function call of get_dijkstra_distance() error.\n");
		return INF;
	}

	int i,j;
	int NOT_VISITED = -100;
//	int START_INDEX = -1;

	int visited[MAX_DTG_SIZE];
	int distance = 0;
	for( i=0;i<tg->elementSize;i++) visited[i] = NOT_VISITED;
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
			for( j=0 ; j<tg->elementSize ; j++ ){
				dis_TransitiveEdge *edge = tg->edge[expanding*tg->elementSize+j];
				if( visited[j] != NOT_VISITED ) continue;

				if ( edge!=NULL && edge->actionSize ){
					no_new_expansion = 0;
					visited[j] = expanding;
					tmp_list[tmp_list_size++] = j;
					//printf("    -->MARKING:%d\n",j);
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

	}while(!no_new_expansion);

	return INF;
}


const int MAX_FACT;
const int MAX_ACTION;
int *factDistance;
int *actionDistance;


void print_fact_distance(){
	int t,i,j;
	int dimen = dis_gnum_relevant_facts;
	for(i=0;i<dis_gnum_relevant_facts;i++)
	for(j=0;j<dis_gnum_relevant_facts;j++)
		factDistance[i*dimen+j]=-1;
		
	for(t=0;t<num_transitiveGraph;t++){
		dis_TransitiveGraph *tg = &(transitiveGraph[t]);
		
		int path[1000];
		for(i=0;i<tg->elementSize;i++)
		for(j=0;j<tg->elementSize;j++){
			int dist = get_dijkstra_distance( tg, i, j,path );
			if (dist!=INF)
				dist--;

			factDistance[tg->element[i]*dimen + tg->element[j]] = dist;
		}
	}
	
	printf("Fact distances:\n");
	for(i=0;i<dis_gnum_relevant_facts;i++)
	for(j=0;j<dis_gnum_relevant_facts;j++){
		if(factDistance[i*dimen+j]==-1 || i==j ) continue;
		
		printf("(");
		dis_print_ft_name(i);
		printf(" -> ");
		dis_print_ft_name(j);
		printf("):%d\n",factDistance[i*dimen+j]);
	}
}

void print_action_distance(){
	int i,j,k,l,a1,a2;
	int dimen = dis_gnum_actions;
	for(i=0;i<dis_gnum_actions;i++)
	for(j=0;j<dis_gnum_actions;j++)
		actionDistance[i*dimen+j]=-1;
		
	for(i=0;i<dis_gnum_actions;i++)
	for(j=0;j<dis_gnum_actions;j++){
		
		int effectId1 = dis_gop_conn[i].E[0];
		int effectId2 = dis_gop_conn[j].E[0];
		if(i==j) continue;
		
		for(k=0;k<dis_gef_conn[effectId1].num_A;k++)
		for(l=0;l<dis_gef_conn[effectId2].num_A;l++){
			int f1 = dis_gef_conn[effectId1].A[k];
			int f2 = dis_gef_conn[effectId2].A[l];
			int dist = factDistance[f1*dis_gnum_relevant_facts+f2];	
			if(dist==-1) continue;
			
			if(actionDistance[i*dimen+j]<dist)
				actionDistance[i*dimen+j] = dist; 	
		}
		
		for(k=0;k<dis_gef_conn[effectId1].num_A;k++)
		for(l=0;l<dis_gef_conn[effectId2].num_PC;l++){			
			int f1 = dis_gef_conn[effectId1].A[k];
			int f2 = dis_gef_conn[effectId2].PC[l];
			int dist = factDistance[f1*dis_gnum_relevant_facts+f2];	
			if(dist==-1) continue;
			
			if( dist!=INF )
				dist = dist +1;
			
			if( actionDistance[i*dimen+j ] < dist )
				actionDistance[i*dimen+j] = dist;	
		}
		
		for(k=0;k<dis_gef_conn[effectId1].num_PC;k++)
		for(l=0;l<dis_gef_conn[effectId2].num_A;l++){			
			int f1 = dis_gef_conn[effectId1].PC[k];
			int f2 = dis_gef_conn[effectId2].A[l];
			int dist = factDistance[f1*dis_gnum_relevant_facts+f2];	
			if(dist==-1) continue;
			
			if( dist!=INF )
				dist = dist -1;
			
			if(actionDistance[i*dimen+j]<dist)
				actionDistance[i*dimen+j] = dist; 	
		}
		
		for(k=0;k<dis_gef_conn[effectId1].num_PC;k++)
		for(l=0;l<dis_gef_conn[effectId2].num_PC;l++){			
			int f1 = dis_gef_conn[effectId1].PC[k];
			int f2 = dis_gef_conn[effectId2].PC[l];
			int dist = factDistance[f1*dis_gnum_relevant_facts+f2];	
			if(dist==-1) continue;
			
			if(actionDistance[i*dimen+j]<dist)
				actionDistance[i*dimen+j] = dist;
		}
	}
	
	printf("\n\nAction distance:\n");
	for(i=0;i<dis_gnum_actions;i++)
	for(j=0;j<dis_gnum_actions;j++){
		
		if(actionDistance[i*dimen+j]<=0 || i==j ) continue;
		printf("(");
		dis_print_op_name(i);
		printf(" -> ");
		dis_print_op_name(j);
		printf("):%d\n",actionDistance[i*dimen+j]);
		
	}
}


void print_londex(){
	factDistance = malloc( sizeof(int) * dis_gnum_relevant_facts * dis_gnum_relevant_facts);
	actionDistance = malloc( sizeof(int) * dis_gnum_actions * dis_gnum_actions);
	print_fact_distance();
	print_action_distance();	
}
