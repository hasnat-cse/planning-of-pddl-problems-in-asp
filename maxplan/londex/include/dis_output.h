



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
 * File: dis_output.h
 * Description: print headers
 *
 * Author: Joerg Hoffmann 1999
 *
 *********************************************************************/ 





#ifndef _dis_OUTPUT_H
#define _dis_OUTPUT_H



void dis_print_dis_FactList( dis_FactList *list, char *sepf, char *sept );
void dis_print_hidden_dis_TokenList( dis_TokenList *list, char *sep );
void dis_print_indent( int indent );
void dis_print_dis_Parsedis_ExpNode( dis_Parsedis_ExpNode *n );
void dis_print_dis_PlNode( dis_PlNode *plnode, int indent );
void dis_print_dis_ExpNode( dis_ExpNode *n );
void dis_print_Wff( dis_WffNode *n, int indent );
void dis_print_plops( dis_Pldis_Operator *plop );
void dis_print_dis_Operator( dis_Operator *o );
void dis_print_Normdis_Operator( Normdis_Operator *o );
void dis_print_Mixeddis_Operator( Mixeddis_Operator *o );
void dis_print_dis_Pseudodis_Action( dis_Pseudodis_Action *o );
void dis_print_dis_Action( dis_Action *a );
void dis_print_dis_Action_name( dis_Action *a );
void dis_print_lnf_dis_Action( dis_Action *a );
void dis_print_type( int t );
void dis_print_dis_Fact( dis_Fact *f ); 
void dis_print_dis_Fluent( dis_Fluent *f );
void dis_print_ft_name( int index );
void dis_print_ft_name_string( int index, char* string );
void dis_print_op_name( int index );
void dis_print_fl_name( int index );
void dis_print_Lnfdis_ExpNode( Lnfdis_ExpNode *n );
void dis_print_dis_State( dis_State S );
void dis_print_dis_Fact_string( dis_Fact *f, char *str);


void dis_print_plan( void );



#endif /* _OUTPUT_H */
