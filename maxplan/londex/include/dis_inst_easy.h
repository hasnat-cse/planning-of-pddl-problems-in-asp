


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
 * File: dis_inst_easy.h
 * Description: headers for multiplying easy operators.
 *
 *
 * Author: Joerg Hoffmann 2000
 *
 *********************************************************************/ 








#ifndef _dis_INST_EASY_H
#define _dis_INST_EASY_H



void dis_build_easy_action_templates( void );



void dis_cleanup_easy_domain( void );
dis_Bool dis_identical_fact( dis_Fact *f1, dis_Fact *f2 );
void dis_handle_empty_easy_parameters( void );



void dis_encode_easy_unaries_as_types( void );
int dis_create_intersected_type( dis_TypeArray T, int num_T );
int dis_find_intersected_type( dis_TypeArray T, int num_T );



void dis_multiply_easy_effect_parameters( void );
void dis_unify_easy_inertia_conditions( int curr_inertia );
void dis_multiply_easy_non_constrained_effect_parameters( int curr_parameter );



void dis_multiply_easy_op_parameters( void );
void dis_unify_easy_inertia_preconds( int curr_inertia );
void dis_multiply_easy_non_constrained_op_parameters( int curr_parameter );



#endif /* _INST_EASY_H */
