
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
 * File: dis_memory.h
 * Description: Creation / Deletion functions for all data structures.
 *
 * Author: Joerg Hoffmann / Frank Rittinger
 *
 *********************************************************************/ 






#ifndef _dis_MEMdis_ORY_H
#define _dis_MEMdis_ORY_H





char *dis_new_dis_Token( int len );
dis_TokenList *dis_new_dis_TokenList( void );
dis_FactList *dis_new_dis_FactList( void );
dis_TypedList *dis_new_dis_TypedList( void );
dis_TypedListList *dis_new_dis_TypedListList( void );
dis_Parsedis_ExpNode *dis_new_dis_Parsedis_ExpNode( dis_Expdis_Connective c );
dis_PlNode *dis_new_dis_PlNode( dis_Connective c );
dis_Pldis_Operator *dis_new_dis_Pldis_Operator( char *name );
dis_Pldis_Operator *dis_new_axiom_op_list( void );


dis_Fact *dis_new_dis_Fact( void );
dis_Fluent *dis_new_dis_Fluent( void );
dis_FluentValue *dis_new_dis_FluentValue( void );
dis_Facts *dis_new_dis_Facts( void );
dis_FluentValues *dis_dis_new_dis_FluentValues( void );
dis_ExpNode *dis_new_dis_ExpNode( dis_Expdis_Connective c );
dis_WffNode *dis_new_dis_WffNode( dis_Connective c );
dis_Literal *dis_new_dis_Literal( void );
dis_Numericdis_Effect *dis_new_dis_Numericdis_Effect( void );
dis_Effect *dis_new_dis_Effect( void );
dis_Operator *dis_new_dis_Operator( char *name, int norp );
Normdis_Effect *dis_new_Normdis_Effect1( dis_Effect *e );
Normdis_Effect *dis_new_Normdis_Effect2( Normdis_Effect *e );
Normdis_Operator *dis_new_Normdis_Operator( dis_Operator *op );
dis_EasyTemplate *dis_new_dis_EasyTemplate( Normdis_Operator *op );
Mixeddis_Operator *dis_new_Mixeddis_Operator( dis_Operator *op );
dis_Pseudodis_Actiondis_Effect *dis_new_dis_Pseudodis_Actiondis_Effect( void );
dis_Pseudodis_Action *dis_new_dis_Pseudodis_Action( Mixeddis_Operator *op );
Lnfdis_ExpNode *dis_new_Lnfdis_ExpNode( void );
dis_Action *dis_new_dis_Action( void );
void dis_make_state( dis_State *pointer, int ft, int fl );
dis_EhcNode *dis_new_dis_EhcNode( void );
dis_EhcHashEntry *dis_new_dis_EhcHashEntry( void );
dis_PlanHashEntry *dis_new_dis_PlanHashEntry( void );
dis_BfsNode *dis_new_dis_BfsNode( void );
dis_BfsHashEntry *dis_new_dis_BfsHashEntry( void );







void dis_free_dis_TokenList( dis_TokenList *source );
void dis_free_dis_FactList( dis_FactList *source );
void dis_free_dis_Parsedis_ExpNode( dis_Parsedis_ExpNode *n );
void dis_free_dis_PlNode( dis_PlNode *node );
void dis_free_dis_Pldis_Operator( dis_Pldis_Operator *o );
void dis_free_dis_Operator( dis_Operator *o );
void dis_free_dis_ExpNode( dis_ExpNode *n );
void dis_free_dis_WffNode( dis_WffNode *w );
void dis_free_Normdis_Effect( Normdis_Effect *e );
void dis_free_partial_dis_Effect( dis_Effect *e );
void dis_free_Normdis_Operator( Normdis_Operator *o );
void dis_free_single_Normdis_Effect( Normdis_Effect *e );
void dis_free_single_dis_EasyTemplate( dis_EasyTemplate *t );
void dis_free_dis_TypedList( dis_TypedList *t );
void dis_free_dis_TypedListList( dis_TypedListList *t );
void dis_free_dis_Actiondis_Effect( dis_Actiondis_Effect *e );

dis_TypedList *copy_dis_TypedList(dis_TypedList *t);
dis_Parsedis_ExpNode *copy_dis_Parsedis_ExpNode( dis_Parsedis_ExpNode *p );
dis_PlNode *copy_dis_PlNode(dis_PlNode *t);

#endif /* _MEMdis_ORY_H */
