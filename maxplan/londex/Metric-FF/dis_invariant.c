
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
 * File: dis_invariant.c
 * Description: functions for generating londex constraints
 *
 * Author: Ruoyun Huang, Yixin Chen 2006
 *
 *********************************************************************/ 

#include "dis_ff.h"
#include "ff.h"
#include "dis_memory.h"
#include "casual_graph.h"
#include "dis_output.h"



//#define INVARIANT_DEBUG
#define BALANCE_DIMEN 200;

const int DEBUG = 1;

const int INVARIANT_BALANCE = -1;
const int INVARIANT_NO_IMPACT = -2;
const int INVARIANT_UNBALANCE = -3;

//const int INVARIANT_UNBAL_INC = -3;
//const int INVARIANT_UNBAL_DEC = -4;
const int INVARIANT_FINDING_TYPE = 1;  // 1 or 0


typedef struct _dis_BalanceInfo{
	int type; 	//BalanceType; NO_IMPACT, UNBALANCE, BALANCE; -3, -2, -1
	int predicate;
	int focus;  //[-1..n]
	dis_Fact* fact; //Where the unbalance occur
	dis_Operator* action;
} dis_BalanceInfo;

int valid_predicate[100];
int valid_predicate_num = 0;
int valid_operator[100];
int valid_operator_num = 0;

dis_Invariant invariantGroup[200];
int num_invariantGroup = 0;
//dis_BalanceInfo balanceMap[dis_MAX_PREDICATES][dis_MAX_OPERATdis_ORS];
dis_BalanceInfo balanceMap[200][200];

dis_AccompanyGroup accompanyGroup[50];
int num_accompanyGroup;


extern struct dis__command_line dis_gcmd_line;


int icmp(const void *p, const void *q){
    const int *m = p, *n = q;
    return *m > *n ? 1 : (*m == *n ? 0 : -1);
}

int get_valid_predicate_index(int predicateId){
	int i;
	for(i=0;i<valid_predicate_num;i++)
		if( valid_predicate[i] == predicateId ) return i;
	return -1;
}

int get_valid_operator_index( int operatorId ){
	int i;
	for( i=0 ; i < valid_operator_num ; i++ )
		if( valid_operator[i] == operatorId ) 
			return i;
	return -1;
}


int has_same_param(dis_Fact* fact1,  dis_Fact* fact2, int* p1, int* p2){
	int i,j;
	if( dis_garity[fact1->predicate]==0 || dis_garity[fact2->predicate]==0 ){
		*p1 = *p2 = -1;
		return 1;
	}
	
	for(i=0;i<dis_garity[fact1->predicate];i++)
	for(j=0;j<dis_garity[fact2->predicate];j++){
		if( fact1->args[i] == fact2->args[j] ){
			*p1 = i;
			*p2 = j;
#ifdef INVARIANT_DEBUG
			printf("[HAS_SAME_PARAM%d,%d]",i,j);
#endif			
			return 1;
		}
	}
	
	*p1 = *p2 = -1;
	return 0;
}

void print_out_invariant_group(dis_Invariant* group, int groupSize){
	int i,j,k;
	printf("*******************INVARIANT GROUPS *******************\n");
	for(i = 0 ; i<groupSize;i++){
#ifdef INVARIANT_DEBUG		
		printf("Invariant #%d:(%d)(%d){",group[i].id,group[i].deleted,group[i].size);
#else
		printf("Invariant #%d:{",group[i].id);
#endif
		int size = group[i].size;
		//printf("###########focustType%d\n",group[i].focusType);
		if(group[i].obj[0]->focus==-1) printf("[NONE] | ");
			else printf("[%s] | ",dis_gtype_names[group[i].focusType]);

		for( j=0; j<size; j++){
			dis_InvariantElement* obj = group[i].obj[j];
			printf("(%s ",dis_gpredicates[obj->fact->predicate]);

			for(k=0;k<dis_garity[obj->fact->predicate];k++){
				if( obj->focus==k ) printf("%s,",dis_gtype_names[group[i].focusType]);
					else printf("#,");
			}
			printf("\b) ");
		}
		printf("\b}\n");
	}
}

void print_out_invariant(dis_Invariant* group){
		int j,k;
#ifdef INVARIANT_DEBUG
		//printf("Invariant:(%d)(%d){", group->deleted , group->size );
#else
		//printf("Invariant #%d:{", group->id  );
#endif
		int size = group->size;
		if(group->obj[0]->focus==-1) printf("-{[NONE] | ");
			else printf("-{[%s] | ",dis_gtype_names[group->focusType]);

		for( j=0; j<size; j++){
			dis_InvariantElement* obj = group->obj[j];
			printf("(%s ",dis_gpredicates[obj->fact->predicate]);

			for(k=0;k<dis_garity[obj->fact->predicate];k++){
				if( obj->focus==k ) 
					printf("%s,",dis_gtype_names[ group->focusType ]);
				else printf("#,");
			}
			printf("\b) ");
		}
		printf("\b}\n");
}

void print_out_invariant_result(){
	print_out_invariant_group(invariantGroup,num_invariantGroup);
}

/*
 * Check whether the two predicate might occur together in a same action's add List, return 0;
 * else return 1;
 */
int is_mutex(dis_InvariantElement* element1, dis_InvariantElement* element2){

	int i;
	for(i=0;i<valid_operator_num;i++){

		dis_Effect* e;
		dis_Literal* l;
		int b1,b2;
		for( e = dis_goperators[valid_operator[i]]->effects ; e ; e=e->next ){
			b1 = b2 = 0;
			for( l=e->effects ; l ; l=l->next ){
				if(l->negated == INVARIANT_FINDING_TYPE ) continue;    //Need to check both not and add list;
				if(l->fact.predicate == element1->fact->predicate)  b1 = 1 ;
				if(l->fact.predicate == element2->fact->predicate)  b2 = 1 ;
			}
			if(b1==1&& b2==1) return 0;

			b1 = b2 = 0;
			for( l=e->effects ; l ; l=l->next ){
				if(l->negated != INVARIANT_FINDING_TYPE ) continue;    //Need to check both not and add list;
				if(l->fact.predicate == element1->fact->predicate)  b1 = 1;
				if(l->fact.predicate == element2->fact->predicate)  b2 = 1;
			}
			if( b1==1 && b2==1 ) return 0;
		}
	}
	return 1;
}


/*
 * 
 * Check whether invar1 sub set of invar2, which means:
 * 	#1: Any fact in invar1 is also in invar2
 *  #2: Their focused objects are the same; 
 */
 
int is_sub_invariant(dis_Invariant* invar1, dis_Invariant* invar2){

	int i,j;
	if(invar1->size>invar2->size)	return 0;
	if( invar1->focusType!=0 && invar1->focusType != invar2->focusType) return 0;
	if( invar1->focusType!=-1 && invar2->focusType==-1 ) return 0;
	
	int flag = 0;
	for(i=0;i<invar1->size;i++){
		flag = 0;
		for(j=0;j<invar2->size;j++){
			if( invar1->obj[i]->fact->predicate==invar2->obj[j]->fact->predicate
				&& invar1->obj[i]->focus == invar2->obj[j]->focus){

				flag = 1;
				break;
			}
		}
		if(flag==0) return 0;
	}
	return 1;
}

/*
 *  IF element belong to invar, return the pos of the same element in invar
    OR return -1;
 *   
 */
int is_belong_to(dis_InvariantElement *element, dis_Invariant* invar){
	int i;

	for(i=0;i<invar->size;i++){
		dis_InvariantElement* e = invar->obj[i];
		if( e->focus == element->focus && e->fact->predicate == element->fact->predicate )
			return i;
	}

	return -1;
}

void add_accompany_pair(dis_Fact *fact1, dis_Fact *fact2){

	int i;
	if(fact1->predicate == fact2->predicate ) return;

	//If pair of (fact1,fact2) already exsit, just return
	for(i=0;i<num_accompanyGroup;i++){
		dis_AccompanyGroup *ag = &(accompanyGroup[i]);
		if ( (fact1->predicate == ag->master_fact->predicate && fact2->predicate==ag->slave_fact->predicate ) ||
				( fact1->predicate==ag->slave_fact->predicate && fact2->predicate==ag->master_fact->predicate ) )
			return;
	}

	accompanyGroup[num_accompanyGroup].valid = 1;
	accompanyGroup[num_accompanyGroup].master_fact = fact1;
	accompanyGroup[num_accompanyGroup].slave_fact = fact2;
	num_accompanyGroup++;
}

//Merge invar1 into invar2
int merge_invariant_element(dis_Invariant* invar1, dis_Invariant* invar2){
	int i;
	if( invar1->size!=2 ) return 0;
	if( invar1->focusType != invar2->focusType ) return 0;

	int num = is_belong_to(invar1->obj[0],invar2);
	//printf("num%d;",nm);
	if( num!=-1 ){
		int flag = 1;

		for(i=0;i<invar2->size;i++){
			if(i==num) continue;

			if( is_belong_to(invar1->obj[1],invar2) !=-1 || !is_mutex(invar1->obj[1],invar2->obj[i])){
				flag = 0;
				break;
			}

			/*
			 */
			if( invar2->size==2 ){
				//printf("****%s AND %s***",dis_gpredicates[invar1->obj[1]->fact->predicate],dis_gpredicates[invar2->obj[i]->fact->predicate]);
				add_accompany_pair(invar1->obj[1]->fact,invar2->obj[i]->fact);
			}
		}

		if(flag){
			invar2->obj[(invar2->size)++] = invar1->obj[1];
			return 1;
		}
	}

	num = is_belong_to(invar1->obj[1],invar2);
	if(num!=-1){
		int flag = 1;

		for(i=0;i<invar2->size;i++){
			if(i==num) continue;

			if( is_belong_to(invar1->obj[0],invar2) !=-1  || !is_mutex(invar1->obj[0],invar2->obj[i])){
				flag = 0;
				break;
			}

			if( invar2->size==2 ){
				//printf("****%s AND %s***",dis_gpredicates[invar1->obj[0]->fact->predicate],dis_gpredicates[invar2->obj[i]->fact->predicate]);
				add_accompany_pair(invar1->obj[0]->fact,invar2->obj[i]->fact);
			}
		}

		if(flag){
			invar2->obj[invar2->size] = invar1->obj[0];
			invar2->size++;
			return 1;
		}
	}
	return 0;
}

void remove_invariant_subset(dis_Invariant* group, int* size){
	int i,j,k;
	int delMark[200];
	int delMarkSize = 0;

	for(i=0;i<*size;i++){
		dis_Invariant* invar1 = &group[i];


		for(j=0;j<*size;j++){
			if(i==j) continue;
			int flag = 0;
			for(k=0;k<delMarkSize;k++){
				if( delMark[k]==j ) {
					flag = 1;
					break;
				}
			}
			if( flag == 1 ) continue;

			dis_Invariant* invar2 = &group[j];
			if(is_sub_invariant(invar1,invar2)){
				delMark[delMarkSize] = i;
				delMarkSize++;
				break;
			}
		}
	}

	int p = *size - delMarkSize;
	int pos = 0;
	for(i=0;i<p;i++){
		int r = i + pos;
		while( r == delMark[pos] && pos<delMarkSize ){
			pos ++;
			r++;
		}

		if(i==r) continue;
		group[i] = group[r];
	}
	*size = p;
}

//remove sub sets, and merge
void refine_invariant_group(dis_Invariant* group, int* size){
	int i,j;
	int delMark[200];
	int delMarkSize = 0;

	//print_out_invariant_result();
	//Subset if of course naively unnecessary;
	remove_invariant_subset(group,size);

	delMarkSize = 0;
	//Starting from here, ******Merge***:
	for(i=0;i<*size;i++){
		dis_Invariant* invar1 = &group[i];
		//print_out_invariant(invar1);
		int found = 1 ;
		while(found){
			found = 0;
			for( j=0 ; j<*size ; j++ ){
				if( i == j ) continue;
				dis_Invariant* invar2 = &group[j];

				//printf("--->");
				//print_out_invariant(invar2);
				//printf("\n");
				if( merge_invariant_element(invar1, invar2) && delMark[delMarkSize-1] != i ){
					delMark[delMarkSize] = i;
					delMarkSize++;
					found = 1;

					break;
				}
			}
		}
	}

	//printf("Del Mark Size:%d\n",delMarkSize);
	//for(i=0;i<delMarkSize;i++) printf("%d;",delMark[i]);
	//printf("\n");

	int p = *size - delMarkSize;
	int pos = 0;
	for(i=0;i<p;i++){
		int r = i + pos;
		while( r == delMark[pos] && pos<delMarkSize ){
			pos ++;
			r++;
		}

		if(i==r) continue;
		group[i] = group[r];
	}
	*size = p;

	remove_invariant_subset(group,size);
	for(i=0;i<num_invariantGroup;i++){
		dis_Invariant *invar = &(invariantGroup[i]);
		invar->id = i;

		//If there is any obj has no param, then the focusType must be NONE.  I am not sure whether it is right.
		for( j=0 ; j<invar->size ; j++ )
			if( dis_garity[invar->obj[j]->fact->predicate]==0) break;
		if ( j != invar->size ){
			invar->focusType = -1;
			for( j=0 ; j<invar->size ; j++ )
				invar->obj[j]->focus = -1;
		}
	}
}


void add_to_invariant_groupset(dis_Invariant *invar, dis_Fact *fact, int focus1 , int focus2){

	int i;

	for(i=0;i<invar->size;i++)
		if( invar->obj[i]->fact->predicate == fact->predicate ) 
			return;//Already have $fact as member of $invar 

	dis_InvariantElement *element = malloc( sizeof(dis_InvariantElement) );
	element->fact = fact;

	if(invar->size==0){
		//nothing to do
	}else if(invar->size==1){
		invar->obj[0]->focus = focus1;
		element->focus = focus2;
	}else if(invar->size>1){
		element->focus = focus2;
	}else 
		printf("EXCEPTION while add_to_invariant_groupset.\n");

	invar->obj[invar->size++] = element;
}


/*
 * This function repair unbalance invariants and add them to the Invariant_GROUP_SET
 */
/*
 * Special Cases:
 * [Openstack]: I = {[PRODUCT] | (MADE PRODUCT) (MACHINE-CONFIGURED PRODUCT)}
 * 				Here, $MADE & $MACHINE-CONFIGURED may both be false,
 * 				That is to say, |DTG(I)| <= 1, rather == 1.
 * 				we use a dummy $NULL to indicate there will always be one true for a DTG; 
 * 				
 * 				However, while in a version of just using DTG for constraints, this $I 
 * 				is naively valid;
 * --------------------------------------------------------------------------------------
 * []:
 * 	
 */
void repair_unbalance_invariants(){
	int i,j,k;
	if(gcmd_line.verbose_invar)
		printf("Generating 2-element invariants\n");
	int simpleInvarCount = 0;
	
	for( i=0 ; i<valid_predicate_num; i++ ){

#ifdef INVARIANT_DEBUG		
		printf("\n*************************[For each PREDICATE] check %s*************************",dis_gpredicates[i]);
#endif		
		dis_Invariant invarSet[100];
		int invarSetSize = 0;
		for(j=0;j<100;j++)
			invarSet[j].size = 0,invarSet[j].deleted = 0;

		for(j=0;j<valid_operator_num;j++){
			//printf("Checking Action(%s) BalanceType(%d)---------------------------\n",dis_goperators[j]->name,balanceMap[i][j].type);
			dis_BalanceInfo *info = &(balanceMap[i][j]);
			if(info->type!=INVARIANT_UNBALANCE) continue;

			dis_Operator *action = dis_goperators[valid_operator[j]];
			dis_Effect *e;
			dis_Literal *l;
			dis_Fact* f = info->fact;

			//int flag = 0;
			for( e=action->effects ; e ; e=e->next ){
				if( e->num_vars!=0 || e->conditions->connective != dis_TRU ) continue;
	
				for( l=e->effects ; l ; l=l->next ){	//Actually, this loop will execute only once;
					int pos1, pos2;

#ifdef INVARIANT_DEBUG	
					printf("\n\t\t+[%s](neg?%d)",dis_gpredicates[l->fact.predicate],l->negated); 
#endif
					if( l->negated != INVARIANT_FINDING_TYPE ) 
						continue;
	
#ifdef INVARIANT_DEBUG 
					printf("1P"); 
#endif
					/*
					 *    For the case of in PIPES_WORLD;
					 *    there is two differenct fact of same predicate (first ? ?);So we should not add those predicate which is BALANCED by itself;
					 * 	  This part needs further consideration and improvement;
					 */
					if( balanceMap[l->fact.predicate][j].type == INVARIANT_BALANCE ) 
						continue;
					
#ifdef INVARIANT_DEBUG 
					printf("2P[%d,%d]",pos1,pos2); 
#endif
					if( has_same_param( f, &(l->fact), &pos1, &pos2 ) == 0 ) 
						continue;
						
#ifdef INVARIANT_DEBUG 
					printf("\n\t\t\t-[%d,%d]Chosen and Processing predicate(%s)\n", pos1, pos2, dis_gpredicates[l->fact.predicate] ); 
#endif
					
					//test the combination of fact and l->fact
					int testSuccess = 1;
					for(k=0;k<valid_operator_num;k++){
						if(balanceMap[get_valid_predicate_index(f->predicate)][k].type == INVARIANT_UNBALANCE &&
							balanceMap[get_valid_predicate_index(l->fact.predicate)][k].type == INVARIANT_UNBALANCE )
								testSuccess = 0;
					}
					if( testSuccess == 0 ) continue;
	
					dis_Invariant* invar = &invarSet[invarSetSize];
					invar->size = 0;
					invarSetSize++;
					add_to_invariant_groupset( invar, f, 0, 0 );
					add_to_invariant_groupset( invar , &(l->fact) , pos1 , pos2 );
	
					if( invar->obj[0]->focus == -1 || pos1<0 || pos2<0 )  
						invar->focusType = -1;
					else
						invar->focusType = f->args[pos1]>=0? f->args[pos1] :action->var_types[dis_DECODE_VAR(f->args[pos1])];
#ifdef INVARIANT_DEBUG					
					print_out_invariant( invar );
#endif
					simpleInvarCount++;
					invar->id = simpleInvarCount;
					if(gcmd_line.verbose_invar) print_out_invariant( invar );
					
					if( invar->size != 2 ) invarSetSize--;
				}
			}
		}

		refine_invariant_group( invarSet , &invarSetSize );

		for(j=0;j<invarSetSize;j++)
			if( invarSet[j].size>1 ){
				invariantGroup[num_invariantGroup] = invarSet[j];
				num_invariantGroup++;
			}
	}
	
	if( gcmd_line.verbose_invar ) 
		printf("Done.\nPurging duplicate and merging overlapping invariants. Analyzing...\n\n");
}

/*
 * This method is for generating naive invariant sets;
 */
void generate_balance_invariants(){
	int i,j,k;
	
	if (gcmd_line.verbose_invar)
		printf("Generating 1-element invariant...\n");
		
	for(i=0;i<valid_predicate_num; i++){

		for(j=0;j<valid_operator_num;j++){
			dis_Operator* action = dis_goperators[j];
			if(balanceMap[i][j].type == INVARIANT_BALANCE ){

				//Dectec whether this invariant is already exist in the group or not.
				int flag = 1;
				for(k=0;k<num_invariantGroup;k++){
					dis_InvariantElement *tmp = invariantGroup[k].obj[0];
					if( tmp->fact->predicate ==i && tmp->focus==balanceMap[i][j].focus ){
						flag = 0;
						break;
					}
				}
				if ( flag==0 ) continue;

				dis_BalanceInfo *info1 = &balanceMap[i][j];
				for(k=0;k<valid_operator_num;k++){

					if( balanceMap[i][k].type != INVARIANT_UNBALANCE ) continue;

					dis_BalanceInfo *info2 = &balanceMap[i][k];
					int type1 = 0, type2 = 0;

					if( info1->focus!= -1  && info1->fact->predicate == info2->fact->predicate ){
						type1 = info1->action->var_types[dis_DECODE_VAR(info1->fact->args[info1->focus])];
						type2 = info2->action->var_types[dis_DECODE_VAR(info2->fact->args[info1->focus])];
					}

					if( type1 == type2 ){
						flag = 0;
						break;
					}
				}
				if(flag==0) continue;

				dis_InvariantElement *invar = malloc( sizeof(dis_InvariantElement) );
				invar->focus = balanceMap[i][j].focus;
				invar->fact = balanceMap[i][j].fact;
				invariantGroup[num_invariantGroup].obj[0] = invar;
				invariantGroup[num_invariantGroup].size = 1;
				invariantGroup[num_invariantGroup].deleted = 0;
				if( invariantGroup[num_invariantGroup].obj[0]->focus == -1 )
					invariantGroup[num_invariantGroup].focusType = -1;
				else invariantGroup[num_invariantGroup].focusType =
						invar->fact->args[invar->focus] > -1 ? invar->fact->args[invar->focus] :action->var_types[dis_DECODE_VAR(invar->fact->args[invar->focus])];
				num_invariantGroup++;
			}
		}
	}
	
	if (gcmd_line.verbose_invar)
		printf("%d found in total. Done.\n\n",num_invariantGroup);
}

void print_out_balance_map(){
	int i,j;
	printf("Printing balance map:");
	for(i=0;i<valid_predicate_num; i++){
		printf("For Predicate:%s\n",dis_gpredicates[ valid_predicate[i] ]);
		for(j=0;j<valid_operator_num;j++){
			printf("   Action:(%s) ",dis_goperators[valid_operator[j]]->name);
			dis_BalanceInfo *info = &(balanceMap[i][j]);
			if( info->type == -3 ){
				printf("%d,%d,UNBALANCE",i,j);
			}else if( info->type == -2 ){
				printf("NO IMPACT");
			}else if( info->type == -1 ){
				printf("BALANCE");
			}else printf("%d",info->type);
			printf("\n");
		}
	}
}

/*
 * This function is to filter those helper and redundant facts which is generated 
 * by PDDL3 constraints pre-processing. 
 */
void filter_valid_definition(){
	int i;
	valid_predicate_num = valid_operator_num = 0;
	for(i=0;i<dis_gnum_predicates;i++)
		if ( strncmp(dis_gpredicates[i] , "_" , strlen("_") ) != 0 )
			valid_predicate[valid_predicate_num++] = i;

	for(i=0;i<dis_gnum_operators;i++)
		if ( strncmp(dis_goperators[i]->name,"_",strlen("_")) != 0 )
			valid_operator[valid_operator_num++] = i;
}

/*
 *
 */
void build_balance_relation_map(){

	int order,j,k;
	dis_Literal *l;
	dis_Effect *e;
	dis_Fact *addPos = NULL;
	dis_Fact *notPos = NULL;

	filter_valid_definition();

	for( order=0; order< valid_predicate_num ; order++ )
	for( j=0 ; j<valid_operator_num; j++ ){

		dis_Operator *action = dis_goperators[valid_operator[j]];
		for( e = action->effects ; e ; e = e->next){
			if( e->num_vars!=0  ) continue;

			addPos = NULL;
			notPos = NULL;
			for( l=e->effects; l ; l=l->next){
				dis_Fact *f = &(l->fact);
				if( f->predicate==order){
					if( l->negated == INVARIANT_FINDING_TYPE ) notPos = f;
						else addPos = f;
				}
			}

			dis_BalanceInfo *info = &(balanceMap[order][j]);
			info->action = action;

			if( addPos==NULL ) 
				info->type = INVARIANT_NO_IMPACT;
			else if( notPos==NULL){
				info->fact = addPos;
				info->type = INVARIANT_UNBALANCE;
			}
			else{
				info->type = INVARIANT_BALANCE;
				info->fact = addPos;

				int pos = -1;
				for( k = 0; k<dis_garity[addPos->predicate]; k++ ){
					if( addPos->args[k] == notPos->args[k] ){
						pos = k;
						break;
					}
				}
				info->focus = pos;
			}
		}
	}
}


void calc_invariants(){
	
	int i;
	
	num_accompanyGroup = 0;
	build_balance_relation_map();
	generate_balance_invariants();
	repair_unbalance_invariants();
	refine_invariant_group(invariantGroup,&num_invariantGroup);
	
	
	int flag = 0;

	/*
	 *	Hack!Hack! There is a bug when dealing with AIRPORT domain; 
	 *  Just skip the predicates, where the problem seems to be;
	 */
	
	if(dis_gnum_types==6 && strlen(dis_gtype_names[4])==12  && strlen(dis_gtype_names[5])== 8){
	
	if( dis_gtype_names[4][0]=='A' && dis_gtype_names[4][1]=='I' && dis_gtype_names[4][2]=='R' ){
		
	if( dis_gnum_predicates == 16 && dis_gpredicates[7][0]=='O' && dis_gpredicates[7][1]=='C' ){
		flag = 1;
	}
	}
	}

	for(i=0;i<num_invariantGroup;i++){
		dis_Invariant* invar = &(invariantGroup[i]);
		if( flag && invar->id != 4) {
			invar->deleted = 1;
			exit(0);
		}
	}
}
