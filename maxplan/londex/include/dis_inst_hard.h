


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
 * File: dis_inst_hard.h
 * Description: headers for multiplying hard operators.
 *
 *
 * Author: Joerg Hoffmann 2000
 *
 *********************************************************************/ 








#ifndef _dis_INST_HARD_H
#define _dis_INST_HARD_H



void dis_build_hard_action_templates( void );



void dis_cleanup_hard_domain( void );
dis_Bool dis_var_used_in_literals( int code_var, dis_Literal *ef );
dis_Bool dis_var_used_in_numeric_effects( int code_var, dis_Numericdis_Effect *ef );
void dis_decrement_inferior_vars_in_literals( int var, dis_Literal *ef );
void dis_decrement_inferior_vars_in_numeric_effects( int var, dis_Numericdis_Effect *ef );



void dis_multiply_hard_op_parameters( void );
void dis_create_hard_mixed_operators( dis_Operator *o, int curr_var );
dis_Effect *dis_instantiate_dis_Effect( dis_Effect *e );
dis_WffNode *dis_instantiate_wff( dis_WffNode *w );
void dis_instantiate_exp( dis_ExpNode **n );
dis_Bool dis_full_dis_possibly_positive( dis_Fact *f );
dis_Bool dis_full_dis_possibly_negative( dis_Fact *f );
int instantiated_dis_fact_adress( dis_Fact *f );



void dis_multiply_hard_effect_parameters( void );
void dis_create_hard_pseudo_effects( dis_Pseudodis_Action *a, dis_Effect *e, int curr_var );
void dis_make_instantiate_literals( dis_Pseudodis_Actiondis_Effect *e, dis_Literal *ll );
void dis_make_instantiate_numeric_effects( dis_Pseudodis_Actiondis_Effect *e, dis_Numericdis_Effect *ne );



#endif /* _INST_HARD_H */
