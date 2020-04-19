


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
 * File: dis_parse.h
 * Description: Functions for the pddl parser
 *
 * Author: Frank Rittinger 1998 / Joerg Hoffmann 1999
 *
 *********************************************************************/ 





#ifndef _dis_PARSE_H
#define _dis_PARSE_H



char *dis_copy_dis_Token( char *s );
dis_TokenList *dis_copy_dis_TokenList( dis_TokenList *source );
void dis_strupcase( char *from );
char *dis_rmdash( char *s );



void dis_build_orig_constant_list( void );
void dis_collect_type_names_in_pl( dis_PlNode *n );
int dis_get_type( char *str );
void dis_make_either_ty( dis_TypedList *tyl );
void dis_make_either_ty_in_pl( dis_PlNode *n );
void dis_normalize_tyl_in_pl( dis_PlNode **n );



dis_Bool dis_make_adl_domain( void );
dis_Bool dis_make_conjunction_of_atoms( dis_PlNode **n );
dis_Bool dis_is_wff( dis_PlNode *n );
dis_Bool dis_make_effects( dis_PlNode **n );
dis_Bool dis_is_eff_literal( dis_PlNode *n );
dis_Bool dis_make_conjunction_of_literals( dis_PlNode **n );



#endif /* PARSE */
