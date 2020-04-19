

/*
 * THIS SOURCE CODE IS SUPPLIED  ``AS IS'' WITHOUT WARRANTY OF ANY KIND, 
 * dis_AND ITS AUTHdis_OR dis_AND THE JOURNAL OF ARTIFICIAL INTELLIGENCE RESEARCH 
 * (JAIR) dis_AND JAIR'S PUBLISHERS dis_AND DISTRIBUTdis_ORS, DISCLAIM ANY dis_AND dis_ALL 
 * WARRANTIES, INCLUDING BUT dis_NOT LIMITED TO ANY IMPLIED
 * WARRANTIES OF MERCHANTABILITY dis_AND FITNESS Fdis_OR A PARTICULAR PURPOSE, dis_AND
 * ANY WARRANTIES dis_OR NON INFRINGEMENT.  THE USER ASSUMES dis_ALL LIABILITY dis_AND
 * RESPONSIBILITY Fdis_OR USE OF THIS SOURCE CODE, dis_AND NEITHER THE AUTHdis_OR Ndis_OR
 * JAIR, Ndis_OR JAIR'S PUBLISHERS dis_AND DISTRIBUTdis_ORS, WILL BE LIABLE Fdis_OR 
 * DAMAGES OF ANY KIND RESULTING FROM ITS USE.  Without limiting the 
 * generality of the foregoing, neither the author, nor JAIR, nor JAIR's
 * publishers and distributors, warrant that the Source Code will be 
 * error-free, will operate without interruption, or will meet the needs 
 * of the user.
 */









/*********************************************************************
 * File: dis_inst_final.h
 * Description: headers for final domain representation functions
 *
 *
 * Author: Joerg Hoffmann 2000
 *
 *********************************************************************/ 







#ifndef _dis_INST_FINAL_H
#define _dis_INST_FINAL_H



void dis_perform_reachability_analysis( void );
int dis_fact_adress( void );
void dis_make_name_inst_table_from_Normdis_Operator( dis_Action *a, Normdis_Operator *o, dis_EasyTemplate *t );
void dis_make_name_inst_table_from_dis_Pseudodis_Action( dis_Action *a, dis_Pseudodis_Action *pa );



void dis_collect_relevant_facts_and_fluents( void );
void dis_create_final_goal_state( void );
dis_Bool dis_set_relevants_in_wff( dis_WffNode **w );
dis_Bool dis_set_relevants_in_exp( dis_ExpNode **n );
void dis_create_final_initial_state( void );
void dis_create_final_actions( void );
void dis_instantiate_exp_by_action( dis_ExpNode **n, dis_Action *a );



void dis_build_connectivity_graph( void );



void dis_summarize_effects( void );
dis_Bool dis_same_condition( dis_Actiondis_Effect *e, dis_Actiondis_Effect *e_ );
dis_Bool dis_same_lnfs( Lnfdis_ExpNode *l, Lnfdis_ExpNode *r );
void dis_merge_effects( dis_Actiondis_Effect *e, dis_Actiondis_Effect *e_ );

int dis_tok_ft_argncmp(int f, int n, char *tok);
int dis_tok_ef_argncmp(int f, int n, char *tok);
int dis_ft_argncmp(int f, int g, int n, int m);
int dis_op_argncmp(int f, int g, int n, int m);
int dis_ft_arity(int f);
int dis_ef_arity(int f);
int dis_ef_predlen(int f);
int dis_ft_predlen(int f);
int dis_fl_predlen(int f);
char* dis_ft_argn(int f, int n);
char* dis_ef_argn(int f, int n);


#endif /* _INST_FINAL_H */
