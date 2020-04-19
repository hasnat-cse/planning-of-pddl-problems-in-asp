%{
#ifdef YYDEBUG
  extern int yydebug=1;
#endif


#include <stdio.h>
#include <string.h> 
#include "dis_ff.h"
#include "dis_memory.h"
#include "dis_parse.h"
#include "lpg.h"
#include "dis_constraints.h"

#ifndef SCAN_ERR
#define SCAN_ERR
#define DOMDEF_dis_EXPECTED            0
#define DOMAIN_dis_EXPECTED            1
#define DOMNAME_dis_EXPECTED           2
#define LBRACKET_dis_EXPECTED          3
#define RBRACKET_dis_EXPECTED          4
#define DOMDEFS_dis_EXPECTED           5
#define REQUIREM_dis_EXPECTED          6
#define TYPEDLIST_dis_EXPECTED         7
#define LITERAL_dis_EXPECTED           8
#define PRECONDDEF_UNCdis_ORRECT       9
#define TYPEDEF_dis_EXPECTED          10
#define CONSTLIST_dis_EXPECTED        11
#define PREDDEF_dis_EXPECTED          12 
#define NAME_dis_EXPECTED             13
#define VARIABLE_dis_EXPECTED         14
#define ACTIONFUNCTdis_OR_dis_EXPECTED    15
#define dis_ATOM_Fdis_ORMULA_dis_EXPECTED     16
#define EFFECT_DEF_dis_EXPECTED       17
#define NEG_Fdis_ORMULA_dis_EXPECTED      18
#define dis_NOT_SUPPdis_ORTED             19
#define ACTION                    20
#define CONSTRAINTLIST_EXPECTED	  21
#endif


#define dis_NAME_STR "name\0"
#define dis_VARIABLE_STR "variable\0"
#define dis_STdis_ANDARD_TYPE "OBJECT\0"
 

static char *serrmsg[] = {
  "domain definition expected",
  "'domain' expected",
  "domain name expected",
  "'(' expected",
  "')' expected",
  "additional domain definitions expected",
  "requirements (e.g. ':STRIPS') expected",
  "typed list of <%s> expected",
  "literal expected",
  "uncorrect precondition definition",
  "type definition expected",
  "list of constants expected",
  "predicate definition expected",
  "<name> expected",
  "<variable> expected",
  "action functor expected",
  "atomic formula expected",
  "effect definition expected",
  "negated atomic formula expected",
  "requirement %s not dis_supported by this FF version",  
  "action definition is not correct",
  "constraint definition is not correct",
  NULL
};


void dis_opserr( int errno, char *par );


static int sact_err;
static char *sact_err_par = NULL;
static dis_Pldis_Operator *scur_op = NULL, *scur_op1 = NULL;
static dis_Bool sis_negated = dis_FALSE;
static char *preference_pointer = NULL;
static char *preference_pointer1 = NULL;
static dis_TypedList *forall_tl = NULL;
static dis_Parsedis_ExpNode *duration_exp = NULL;

int dis_supported( char *str )

{

  int i;
	/* derived predicates */
	/* timed initial literals */
  char * sup[] = { ":STRIPS", ":TYPING", ":NEGATIVE-PRECONDITIONS",
		   ":DISJUNCTIVE-PRECONDITIONS", ":EQUALITY", 
		   ":EXISTENTIAL-PRECONDITIONS", ":UNIVERSAL-PRECONDITIONS", 
		   ":QUANTIFIED-PRECONDITIONS", ":CONDITIONAL-EFFECTS", 
		   ":FLUENTS", ":ADL", ":DURATIVE-ACTIONS", 
		   ":DERIVED-PREDICATES", ":TIMED-INITIAL-LITERALS", 
		   ":PREFERENCES", ":CONSTRAINTS", NULL };    

  for (i=0; NULL != sup[i]; i++) {
    if ( SAME == strcmp(sup[i], str) ) {
	switch(i)
	{
	case 2:
		GpG.is_negative = TRUE;
		break;
	case 3:
		GpG.is_disjunctive = TRUE;
		break;
	case 4:
		GpG.is_equality = TRUE;
		break;
	case 5:
		GpG.is_existential = TRUE;
		break;
	case 6:
		GpG.is_universal = TRUE;
		break;
	case 7:
		GpG.is_existential = GpG.is_universal = TRUE;
		break;
	case 8:
		GpG.is_conditional = TRUE;
		break;
	case 9:
		GpG.is_fluents = TRUE;
		break;
	case 10:
		GpG.is_negative = GpG.is_disjunctive = GpG.is_equality = 
		GpG.is_conditional = TRUE;
		break;
	case 11:
		GpG.is_durative = TRUE;
		break;
	case 12:
		GpG.is_deripred = TRUE;
		break;
	case 13:
		GpG.is_til = TRUE;
		break;
	case 14:
		GpG.is_preferences = TRUE;
		break;
	case 15:
		GpG.is_constraints = TRUE;
		break;
	}
      return dis_TRUE;
    }
  }
  return dis_FALSE;

}

%}


%start file


%union {

  char string[dis_MAX_LENGTH];
  char *pstring;
  dis_Parsedis_ExpNode *pdis_Parsedis_ExpNode;
  dis_PlNode *pdis_PlNode;
  dis_FactList *pdis_FactList;
  dis_TokenList *pdis_TokenList;
  dis_TypedList *pdis_TypedList;
  /* PDDL 3 */
  dis_ConNode *pdis_ConNode;
  
}


%type <pdis_PlNode> adl_effect
%type <pdis_PlNode> adl_effect_star
%type <pdis_PlNode> adl_goal_description
%type <pdis_PlNode> adl_goal_description1
%type <pdis_PlNode> adl_goal_description_star
%type <pdis_Parsedis_ExpNode> f_head
%type <pdis_Parsedis_ExpNode> f_exp
%type <pdis_TokenList> literal_term
%type <pdis_TokenList> term_star
%type <pdis_TypedList> typed_list_name
%type <pdis_TypedList> typed_list_variable
%type <pstring> term
%type <pdis_TokenList> atomic_formula_term
%type <pdis_TokenList> name_plus
%type <pstring> predicate
/* durative actions */
%type <pdis_PlNode> da_adl_effect
%type <pdis_PlNode> timed_adl_effect
%type <pdis_PlNode> timed_adl_effect_plus
%type <pdis_PlNode> timed_adl_goal_description
%type <pdis_PlNode> timed_adl_goal_description_plus
%type <pdis_PlNode> da_adl_goal_description
%type <pdis_PlNode> duration_constraint
/*%type <pdis_PlNode> simple_duration_constraint
%type <pdis_PlNode> simple_duration_constraint_plus
%type <pdis_Parsedis_ExpNode> d_value*/
%type <pdis_PlNode> f_assign_da
%type <pdis_Parsedis_ExpNode> f_exp_da
%type <pdis_Parsedis_ExpNode> f_exp_t
/*PDDL3--*/
%type <pdis_ConNode> con_GD
%type <pdis_ConNode> con_GD1
%type <pdis_ConNode> con_GD_star
%type <pdis_PlNode> pre_GD
%type <pdis_PlNode> pre_GD_star
%type <pdis_PlNode> pref_GD
%type <pdis_PlNode> da_GD
%type <pdis_PlNode> da_GD_star
%type <pdis_PlNode> pref_timed_GD
/*--PDDL3*/

%token DEFINE_TOK
%token DOMAIN_TOK
%token REQUIREMENTS_TOK
%token TYPES_TOK
%token EITHER_TOK
%token CONSTANTS_TOK
%token PREDICATES_TOK
%token FUNCTIONS_TOK
%token ACTION_TOK
%token VARS_TOK
%token IMPLIES_TOK
%token PRECONDITION_TOK
%token PARAMETERS_TOK
%token EFFECT_TOK
%token dis_AND_TOK
%token dis_NOT_TOK
%token dis_WHEN_TOK
%token Fdis_ORdis_ALL_TOK
%token IMPLY_TOK
%token dis_OR_TOK
%token dis_EXISTS_TOK
%token LE_TOK
%token LEQ_TOK
%token EQ_TOK
%token GEQ_TOK
%token GE_TOK
%token MINUS_TOK
%token AD_TOK
%token MU_TOK
%token DI_TOK
%token ASSIGN_TOK
%token SCALE_UP_TOK
%token SCALE_DOWN_TOK
%token INCREASE_TOK
%token DECREASE_TOK
%token <string> NAME
%token <string> VARIABLE
%token <string> NUM
%token OPEN_PAREN
%token CLOSE_PAREN
/*PDDL3--*/
%token	CONSTRAINTS_TOK
%token  PREFERENCE_TOK
%token  WITHIN_TOK  
%token  SOMETIME_TOK
%token  ALWAYS_TOK  
%token  AT_MOST_ONCE_TOK
%token  SOMETIME_AFTER_TOK
%token  SOMETIME_BEFORE_TOK
%token  ALWAYS_WITHIN_TOK
%token  HOLD_DURING_TOK
%token  HOLD_AFTER_TOK
/*--PDDL3*/
/* derived predicates */
%token DERIVED_TOK
/* durative actions */
%token AT_START
%token AT_END
%token OVER_ALL
%token DURATION_TOK
%token DURATIVE_ACTION_TOK
%token DURATION_VAR_TOK
%token CONDITION_TOK
%token TIME_TOK

%left MINUS_TOK PLUS_TOK    
%left MUL_TOK DIV_TOK
%left UMINUS

%%

/**********************************************************************/
file:
{ 
  dis_opserr( DOMDEF_dis_EXPECTED, NULL ); 
}
domain_definition 
;
/* can be extended to support 'addenda' and similar stuff */


/**********************************************************************/
domain_definition : 
OPEN_PAREN  DEFINE_TOK  domain_name       
{ 
}
optional_domain_defs 
{
  if ( dis_gcmd_line.display_info >= 1 ) {
    /*printf("\ndomain '%s' defined\n", dis_gdomain_name);*/
  } 
}
;


/**********************************************************************/
domain_name :
OPEN_PAREN  DOMAIN_TOK  NAME  CLOSE_PAREN 
{ 
  dis_gdomain_name = dis_new_dis_Token( strlen($3)+1 );
  strcpy( dis_gdomain_name, $3);
}
;


/**********************************************************************/
optional_domain_defs:
CLOSE_PAREN  /* end of domain */
|
require_def  optional_domain_defs
|
constants_def  optional_domain_defs
|
types_def  optional_domain_defs
|
predicates_def  optional_domain_defs
|
functions_def  optional_domain_defs
|
action_def  optional_domain_defs
/* durative actions */
|
durative_action_def optional_domain_defs
/* derived predicates */
|
derived_def optional_domain_defs
/* constraints */
|
constraints_def optional_domain_defs
;


/**********************************************************************/
predicates_def :
OPEN_PAREN PREDICATES_TOK  predicates_list 
{
}
CLOSE_PAREN
{ 
}
;
/**********************************************************************/
predicates_list :
/* empty = finished */
{}
|
OPEN_PAREN  NAME typed_list_variable  CLOSE_PAREN
{

  dis_TypedListList *tll;

  if ( dis_gparse_predicates ) {
    tll = dis_gparse_predicates;
    while ( tll->next ) {
      tll = tll->next;
    }
    tll->next = dis_new_dis_TypedListList();
    tll = tll->next;
  } else {
    tll = dis_new_dis_TypedListList();
    dis_gparse_predicates = tll;
  }

  tll->predicate = dis_new_dis_Token( strlen( $2 ) + 1);
  strcpy( tll->predicate, $2 );

  tll->args = $3;

}
predicates_list
;


/**********************************************************************/
functions_def :
OPEN_PAREN FUNCTIONS_TOK  functions_list 
{
}
CLOSE_PAREN
{ 
}
;
/**********************************************************************/
functions_list :
/* empty = finished */
{}
|
OPEN_PAREN  NAME typed_list_variable  CLOSE_PAREN
{

  dis_TypedListList *tll;

  if ( dis_gparse_functions ) {
    tll = dis_gparse_functions;
    while ( tll->next ) {
      tll = tll->next;
    }
    tll->next = dis_new_dis_TypedListList();
    tll = tll->next;
  } else {
    tll = dis_new_dis_TypedListList();
    dis_gparse_functions = tll;
  }

  tll->predicate = dis_new_dis_Token( strlen( $2 ) + 1);
  strcpy( tll->predicate, $2 );

  tll->args = $3;

}
functions_list
;


/**********************************************************************/
require_def:
OPEN_PAREN  REQUIREMENTS_TOK 
{ 
  dis_opserr( REQUIREM_dis_EXPECTED, NULL ); 
}
NAME
{ 
  if ( !dis_supported( $4 ) ) {
    dis_opserr( dis_NOT_SUPPdis_ORTED, $4 );
    yyerror();
  }
}
require_key_star  CLOSE_PAREN
|
OPEN_PAREN  REQUIREMENTS_TOK 
{ 
  dis_opserr( REQUIREM_dis_EXPECTED, NULL ); 
}
CONSTRAINTS_TOK require_key_star  CLOSE_PAREN
{
	GpG.is_constraints = TRUE;
}
;


/**********************************************************************/
require_key_star:
/* empty */
|
NAME
{ 
  if ( !dis_supported( $1 ) ) {
    dis_opserr( dis_NOT_SUPPdis_ORTED, $1 );
    yyerror();
  }
}
require_key_star
|
CONSTRAINTS_TOK require_key_star
{
	GpG.is_constraints = TRUE;
}
;


/**********************************************************************/
types_def:
OPEN_PAREN  TYPES_TOK
{ 
  dis_opserr( TYPEDEF_dis_EXPECTED, NULL ); 
}
typed_list_name  CLOSE_PAREN
{
  dis_gparse_types = $4;
}
; 


/**********************************************************************/
constants_def:
OPEN_PAREN  CONSTANTS_TOK
{ 
  dis_opserr( CONSTLIST_dis_EXPECTED, NULL ); 
}
typed_list_name  CLOSE_PAREN
{
  dis_gparse_constants = $4;
}
;

/* PDDL 3*/
constraints_def:
OPEN_PAREN CONSTRAINTS_TOK
{
	dis_opserr( CONSTRAINTLIST_EXPECTED, NULL ); 
}
con_GD CLOSE_PAREN
{ 
        dis_ConNode *p;
        if (dis_gloaded_constraints)
        {
                for (p=dis_gloaded_constraints;p->next;p=p->next)
                        ;
                p->next = $4;
        }
        else
                p = $4;
}
;

con_GD:
con_GD1
{
        dis_PrefNode *pref;
        char temp[128];

        sprintf(temp, "CONSTRAINTS%d", dis_num_preference);
        pref = new_dis_PrefNode(temp, "CONSTRAINTS", "CONSTRAINTS");
        pref->body = $1;
        pref->args = copy_dis_TypedList(forall_tl);
        pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref;
        dis_num_preference++;
        $$ = NULL;
}
|
OPEN_PAREN dis_AND_TOK con_GD_star CLOSE_PAREN
{
	$$ = new_dis_ConNode(dis_AND_c_c);  
	$$->sons_c = $3;
}
|
OPEN_PAREN Fdis_ORdis_ALL_TOK OPEN_PAREN typed_list_variable 
{
	forall_tl = $4;
}
CLOSE_PAREN con_GD CLOSE_PAREN
{
	dis_ConNode *pln;
	
	if ($7)
	{
	pln = new_dis_ConNode(dis_ALL_c_c);
	pln->parse_vars = $4;
	forall_tl = NULL;
	$$ = pln;
	pln->sons_c = $7;
	}
	else
		$$ = NULL;
}
;

con_GD1:
OPEN_PAREN AT_END adl_goal_description CLOSE_PAREN
{
	$$ = new_dis_ConNode(dis_AT_END_c);
	$$->sons = $3;
}
|
OPEN_PAREN ALWAYS_TOK adl_goal_description CLOSE_PAREN
{
	$$ = new_dis_ConNode(dis_ALWAYS_c);
	$$->sons = $3;
}
|
OPEN_PAREN SOMETIME_TOK adl_goal_description CLOSE_PAREN
{
	$$ = new_dis_ConNode(dis_SOMETIME_c);
	$$->sons = $3;
}
|
OPEN_PAREN WITHIN_TOK NUM adl_goal_description CLOSE_PAREN
{
	$$ = new_dis_ConNode(dis_WITHIN_c);
	$$->number = atof($3);
	$$->sons = $4;
}
|
OPEN_PAREN AT_MOST_ONCE_TOK adl_goal_description CLOSE_PAREN
{
	$$ = new_dis_ConNode(dis_AT_MOST_ONCE_c);
	$$->sons = $3;
}
|
OPEN_PAREN SOMETIME_AFTER_TOK adl_goal_description adl_goal_description CLOSE_PAREN
{
	$$ = new_dis_ConNode(dis_SOMETIME_AFTER_c);
	$$->sons = $3;
	$$->sons2 = $4;
}
|
OPEN_PAREN SOMETIME_BEFORE_TOK adl_goal_description adl_goal_description CLOSE_PAREN
{
	$$ = new_dis_ConNode(dis_SOMETIME_BEFORE_c);
	$$->sons = $3;
	$$->sons2 = $4;
}
|
OPEN_PAREN ALWAYS_WITHIN_TOK NUM adl_goal_description adl_goal_description CLOSE_PAREN
{
	$$ = new_dis_ConNode(dis_ALWAYS_WITHIN_c);
	$$->number = atof($3);
	$$->sons = $4;
	$$->sons2 = $5;
}
|
OPEN_PAREN HOLD_DURING_TOK NUM NUM adl_goal_description CLOSE_PAREN
{
	$$ = new_dis_ConNode(dis_HOLD_DURING_c);
	$$->number = atof($3);
	$$->number2 = atof($4);
	$$->sons = $5;
}
|
OPEN_PAREN HOLD_AFTER_TOK NUM adl_goal_description CLOSE_PAREN
{
	$$ = new_dis_ConNode(dis_HOLD_AFTER_c);
	$$->number = atof($3);
	$$->sons = $4;
}
;

con_GD_star:
/* empty */
{
	$$ = NULL;
}
|
con_GD con_GD_star
{
	$$ = NULL;
//	$1->next = $2;
//	$$ = $1;
}
;      


/**********************************************************************
 * actions and their optional definitions
 **********************************************************************/
action_def:
OPEN_PAREN  ACTION_TOK  
{ 
  dis_opserr( ACTION, NULL ); 
}  
NAME
{ 
  scur_op = dis_new_dis_Pldis_Operator( $4 );
  preference_pointer = NULL;
}
param_def  action_def_body  CLOSE_PAREN
{
  dis_PlNode *p;
  char temp[128]; 
  
  if (preference_pointer)
  {
    p = dis_new_dis_PlNode(dis_AND);
    p->sons = dis_new_dis_PlNode(dis_NOT);
    p->sons->sons = dis_new_dis_PlNode(dis_ATOM);
    p->sons->sons->atom = dis_new_dis_TokenList();
    p->sons->sons->atom->item = dis_copy_dis_Token(preference_pointer);
  
    sprintf(temp, "_%s_VIO", preference_pointer1);
    p->sons->next = dis_new_dis_PlNode(dis_NEF);
    p->sons->next->neft = ASSIGN;
    p->sons->next->lh = dis_new_dis_Parsedis_ExpNode( FHEAD ); 
    p->sons->next->lh->atom = dis_new_dis_TokenList();
    p->sons->next->lh->atom->item = dis_copy_dis_Token(temp);
    p->sons->next->rh = dis_new_dis_Parsedis_ExpNode( NUMBER );
    p->sons->next->rh->atom = dis_new_dis_TokenList();
    p->sons->next->rh->atom->item = dis_copy_dis_Token("1");
    p->sons->next->next = copy_dis_PlNode(scur_op->effects);  

    sprintf(temp, "+%s_%s", preference_pointer, scur_op->name);
    scur_op1 = dis_new_dis_Pldis_Operator( temp );
    scur_op1->params = scur_op->params;
    scur_op1->number_of_real_params = scur_op->number_of_real_params;
    scur_op1->parse_params = copy_dis_TypedList(scur_op->parse_params);
    scur_op1->preconds = copy_dis_PlNode(scur_op->preconds);
    scur_op1->effects = p;
    scur_op1->next = dis_gloaded_ops;
    dis_gloaded_ops = scur_op1; 
  }
  scur_op->next = dis_gloaded_ops;
  dis_gloaded_ops = scur_op; 
  scur_op = NULL;
}
;


/**********************************************************************/
param_def:
/* empty */
{ 
  scur_op->params = NULL; 
}
|
PARAMETERS_TOK  OPEN_PAREN  typed_list_variable  CLOSE_PAREN
{
  dis_TypedList *tl;
  scur_op->parse_params = $3;
  for (tl = scur_op->parse_params; tl; tl = tl->next) {
    /* to be able to distinguish params from :VARS 
     */
    scur_op->number_of_real_params++;
  }
}
;

/**********************************************************************/
action_def_body:
/* empty */
|
VARS_TOK  OPEN_PAREN  typed_list_variable  CLOSE_PAREN  action_def_body
{
  dis_TypedList *tl = NULL;

  /* add vars as parameters 
   */
  if ( scur_op->parse_params ) {
    for( tl = scur_op->parse_params; tl->next; tl = tl->next ) {
      /* empty, get to the end of list 
       */
    }
    tl->next = $3;
    tl = tl->next;
  } else {
    scur_op->parse_params = $3;
  }
}
|
/* PDDL 3 */
/* PRECONDITION_TOK  adl_goal_description */
PRECONDITION_TOK pre_GD
{ 
  scur_op->preconds = $2; 
}
action_def_body
|
EFFECT_TOK  adl_effect
{ 
  scur_op->effects = $2; 
}
action_def_body
;

pre_GD:
OPEN_PAREN CLOSE_PAREN
{
        $$ = NULL;
}
|
pref_GD
{
        $$ = $1;
}
|
OPEN_PAREN dis_AND_TOK pre_GD_star CLOSE_PAREN
{
        $$ = dis_new_dis_PlNode(dis_AND);
        $$->sons = $3;
}
|
OPEN_PAREN  Fdis_ORdis_ALL_TOK
OPEN_PAREN  typed_list_variable  CLOSE_PAREN
pre_GD  CLOSE_PAREN
{ 
  
  dis_PlNode *pln;
  
  pln = dis_new_dis_PlNode(dis_ALL);
  pln->parse_vars = $4; 

  $$ = pln;
  pln->sons = $6;

}
;

pre_GD_star:
/* empty */ 
{
        $$ = NULL;
}
|
pre_GD pre_GD_star
{
        if ($1)
        {
                $1->next = $2;
                $$ = $1;
        }
        else
                $$ = $2;
}
;

pref_GD:
OPEN_PAREN PREFERENCE_TOK NAME adl_goal_description CLOSE_PAREN
{
        dis_PrefNode *pref;
        dis_ConNode *con;
        char temp[128];

        sprintf(temp, "%s%d", $3, dis_num_preference);
        if (scur_op)
	        pref = new_dis_PrefNode(temp, scur_op->name, $3);
	else
	        pref = new_dis_PrefNode(temp, "CONSTRAINTS", $3);

        con = new_dis_ConNode(dis_ATOM_c);
        con->sons = $4;
        pref->body = con;
        pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref; 
        dis_num_preference++;
        preference_pointer = pref->name;
        preference_pointer1 = pref->pname;
        $$ = $4;
        $$->value = -1;
}
|
OPEN_PAREN PREFERENCE_TOK adl_goal_description CLOSE_PAREN
{
        dis_PrefNode *pref;
        dis_ConNode *con;
        char temp[128];

        sprintf(temp, "ANONYMOUS%d", dis_num_preference);
        if (scur_op)
	        pref = new_dis_PrefNode(temp, scur_op->name, "ANONYMOUS");
	else
	        pref = new_dis_PrefNode(temp, "CONSTRAINTS", "ANONYMOUS");

        con = new_dis_ConNode(dis_ATOM_c);
        con->sons = $3;
        pref->body = con;
        pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref; 
        dis_num_preference++;
        preference_pointer = pref->name;
        preference_pointer1 = pref->pname;
        $$ = $3;
        $$->value = -1;
}
|
adl_goal_description1
{
        $$ = $1;
}
;


/* derived predicates */
derived_def:
OPEN_PAREN DERIVED_TOK OPEN_PAREN predicate typed_list_variable 
CLOSE_PAREN adl_goal_description CLOSE_PAREN
{
	char temp[200];
	dis_TypedList *tl;
	dis_TokenList *t;
	sprintf(temp, "deripred-%d>%s", ++dis_gnum_deripreds, $4);
	scur_op = dis_new_dis_Pldis_Operator(temp);

	scur_op->effects = dis_new_dis_PlNode(dis_AND);   
	scur_op->effects->parse_vars = NULL;
	scur_op->effects->next = NULL;    
	scur_op->effects->atom = NULL;
	scur_op->effects->sons = dis_new_dis_PlNode(dis_ATOM);
	scur_op->effects->sons->parse_vars = NULL;
	scur_op->effects->sons->next = NULL;
	scur_op->effects->sons->atom = dis_new_dis_TokenList();
	scur_op->effects->sons->atom->item = $4;
	scur_op->effects->sons->sons = NULL;

	t = scur_op->effects->sons->atom;
  scur_op->parse_params = $5;
  for (tl = scur_op->parse_params; tl; tl = tl->next) {
    /* to be able to distinguish params from :VARS
     */  
    scur_op->number_of_real_params++;
	t->next = dis_new_dis_TokenList();
	t->next->item = dis_new_dis_Token(strlen(tl->name)+1);
	strcpy(t->next->item, tl->name);
	t = t->next;
  }
	 	
	scur_op->preconds = $7;
	scur_op->next = dis_gloaded_ops;
	dis_gloaded_ops = scur_op; 
}
;

/**********************************************************************
 * Goal description providing full ADL.
 * RETURNS a tree with the connectives in the nodes and the atomic 
 * predicates in the leafs.
 **********************************************************************/
adl_goal_description:
adl_goal_description1
{
        $$ = $1;
}
|
OPEN_PAREN  dis_AND_TOK  adl_goal_description_star  CLOSE_PAREN
{ 
  $$ = dis_new_dis_PlNode(dis_AND);
  $$->sons = $3;
}
|
OPEN_PAREN  Fdis_ORdis_ALL_TOK 
OPEN_PAREN  typed_list_variable  CLOSE_PAREN 
adl_goal_description1  CLOSE_PAREN
{ 

  dis_PlNode *pln;

  pln = dis_new_dis_PlNode(dis_ALL);
  pln->parse_vars = $4;

  $$ = pln;
  pln->sons = $6;

}
;

adl_goal_description1:
OPEN_PAREN LE_TOK f_exp f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode(dis_COMP);
  $$->comp = LE;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN LEQ_TOK f_exp f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode(dis_COMP);
  $$->comp = LEQ;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN EQ_TOK f_exp f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode(dis_COMP);
  $$->comp = EQ;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN GEQ_TOK f_exp f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode(dis_COMP);
  $$->comp = GEQ;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN GE_TOK f_exp f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode(dis_COMP);
  $$->comp = GE;
  $$->lh = $3;
  $$->rh = $4;
}
|
literal_term
{ 
  if ( sis_negated ) {
    $$ = dis_new_dis_PlNode(dis_NOT);
    $$->sons = dis_new_dis_PlNode(dis_ATOM);
    $$->sons->atom = $1;
    sis_negated = dis_FALSE;
  } else {
    $$ = dis_new_dis_PlNode(dis_ATOM);
    $$->atom = $1;
  }
}
|
OPEN_PAREN  dis_OR_TOK  adl_goal_description_star  CLOSE_PAREN
{ 
  $$ = dis_new_dis_PlNode(dis_OR);
  $$->sons = $3;
}
|
OPEN_PAREN  dis_NOT_TOK  adl_goal_description  CLOSE_PAREN
{ 
  $$ = dis_new_dis_PlNode(dis_NOT);
  $$->sons = $3;
}
|
OPEN_PAREN  IMPLY_TOK  adl_goal_description  adl_goal_description  CLOSE_PAREN
{ 
  dis_PlNode *np = dis_new_dis_PlNode(dis_NOT);
  np->sons = $3;
  np->next = $4;

  $$ = dis_new_dis_PlNode(dis_OR);
  $$->sons = np;
}
|
OPEN_PAREN  dis_EXISTS_TOK 
OPEN_PAREN  typed_list_variable  CLOSE_PAREN 
adl_goal_description  CLOSE_PAREN
{ 

  dis_PlNode *pln;

  pln = dis_new_dis_PlNode(dis_EX);
  pln->parse_vars = $4;

  $$ = pln;
  pln->sons = $6;

}
;

/**********************************************************************/
adl_goal_description_star:
/* empty */
{
  $$ = NULL;
}
|
adl_goal_description  adl_goal_description_star
{
  $1->next = $2;
  $$ = $1;
}
;

/**********************************************************************
 * effects as allowed in pddl are saved in FF data structures
 * describes everything after the keyword :effect
 *********************************************************************/
adl_effect:
OPEN_PAREN ASSIGN_TOK f_head f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = ASSIGN;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN SCALE_UP_TOK f_head f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = SCALE_UP;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN SCALE_DOWN_TOK f_head f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = SCALE_DOWN;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN INCREASE_TOK f_head f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = INCREASE;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN DECREASE_TOK f_head f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = DECREASE;
  $$->lh = $3;
  $$->rh = $4;
}
|
literal_term
{ 
  if ( sis_negated ) {
    $$ = dis_new_dis_PlNode(dis_NOT);
    $$->sons = dis_new_dis_PlNode(dis_ATOM);
    $$->sons->atom = $1;
    sis_negated = dis_FALSE;
  } else {
    $$ = dis_new_dis_PlNode(dis_ATOM);
    $$->atom = $1;
  }
}
|
OPEN_PAREN  dis_AND_TOK  adl_effect_star  CLOSE_PAREN
{ 
  $$ = dis_new_dis_PlNode(dis_AND);
  $$->sons = $3;
}
|
OPEN_PAREN  Fdis_ORdis_ALL_TOK 
OPEN_PAREN  typed_list_variable  CLOSE_PAREN 
adl_effect  CLOSE_PAREN
{ 

  dis_PlNode *pln;

  pln = dis_new_dis_PlNode(dis_ALL);
  pln->parse_vars = $4;

  $$ = pln;
  pln->sons = $6;

}
|
OPEN_PAREN  dis_WHEN_TOK  adl_goal_description  adl_effect  CLOSE_PAREN
{
  /* This will be conditional effects in FF representation, but here
   * a formula like (dis_WHEN p q) will be saved as:
   *  [dis_WHEN]
   *  [sons]
   *   /  \
   * [p]  [q]
   * That means, the first son is p, and the second one is q. 
   */
  $$ = dis_new_dis_PlNode(dis_WHEN);
  $3->next = $4;
  $$->sons = $3;
}
;


/**********************************************************************/
adl_effect_star:
{ 
  $$ = NULL; 
}
|
adl_effect  adl_effect_star
{
  $1->next = $2;
  $$ = $1;
}
;


/**********************************************************************
 * some expressions used in many different rules
 **********************************************************************/
f_head:
OPEN_PAREN NAME term_star CLOSE_PAREN
{
  $$ = dis_new_dis_Parsedis_ExpNode( FHEAD );
  $$->atom = dis_new_dis_TokenList();
  $$->atom->item = dis_new_dis_Token( strlen($2)+1 );
  strcpy( $$->atom->item, $2 );
  $$->atom->next = $3;
}
|
NAME
{
  $$ = dis_new_dis_Parsedis_ExpNode( FHEAD );
  $$->atom = dis_new_dis_TokenList();
  $$->atom->item = dis_new_dis_Token( strlen($1)+1 );
  strcpy( $$->atom->item, $1 );
}
;



f_exp:
NUM
{ 
  $$ = dis_new_dis_Parsedis_ExpNode( NUMBER );
  $$->atom = dis_new_dis_TokenList();
  $$->atom->item = dis_new_dis_Token( strlen($1)+1 );
  strcpy( $$->atom->item, $1 );
}
|
f_head
{
  $$ = $1;
}
|
OPEN_PAREN MINUS_TOK f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_Parsedis_ExpNode( MINUS );
  $$->leftson = $3;
}
|
OPEN_PAREN AD_TOK f_exp f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_Parsedis_ExpNode( AD );
  $$->leftson = $3;
  $$->rightson = $4;
}
|
OPEN_PAREN MINUS_TOK f_exp f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_Parsedis_ExpNode( SU );
  $$->leftson = $3;
  $$->rightson = $4;
}
|
OPEN_PAREN MU_TOK f_exp f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_Parsedis_ExpNode( MU );
  $$->leftson = $3;
  $$->rightson = $4;
}
|
OPEN_PAREN DI_TOK f_exp f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_Parsedis_ExpNode( DI );
  $$->leftson = $3;
  $$->rightson = $4;
}
;


/**********************************************************************/
literal_term:
OPEN_PAREN  dis_NOT_TOK  atomic_formula_term  CLOSE_PAREN
{ 
  $$ = $3;
  sis_negated = dis_TRUE;
}
|
atomic_formula_term
{
  $$ = $1;
}
;


/**********************************************************************/
atomic_formula_term:
OPEN_PAREN  predicate  term_star  CLOSE_PAREN
{ 
  $$ = dis_new_dis_TokenList();
  $$->item = $2;
  $$->next = $3;
}
|
OPEN_PAREN  EQ_TOK  term_star  CLOSE_PAREN
{
  $$ = dis_new_dis_TokenList();
  $$->item = dis_new_dis_Token( 5 );
  $$->item = "=";
  $$->next = $3;
}
;


/**********************************************************************/
term_star:
/* empty */
{ $$ = NULL; }
|
term  term_star
{
  $$ = dis_new_dis_TokenList();
  $$->item = $1;
  $$->next = $2;
}
;


/**********************************************************************/
term:
NAME
{ 
  $$ = dis_new_dis_Token( strlen($1)+1 );
  strcpy( $$, $1 );
}
|
VARIABLE
{ 
  $$ = dis_new_dis_Token( strlen($1)+1 );
  strcpy( $$, $1 );
}
;


/**********************************************************************/
name_plus:
NAME
{
  $$ = dis_new_dis_TokenList();
  $$->item = dis_new_dis_Token( strlen($1)+1 );
  strcpy( $$->item, $1 );
}
|
NAME  name_plus
{
  $$ = dis_new_dis_TokenList();
  $$->item = dis_new_dis_Token( strlen($1)+1 );
  strcpy( $$->item, $1 );
  $$->next = $2;
}
;

/**********************************************************************/
predicate:
NAME
{ 
  $$ = dis_new_dis_Token( strlen($1)+1 );
  strcpy( $$, $1 );
}
;


/**********************************************************************/
typed_list_name:     /* returns dis_TypedList */
/* empty */
{ $$ = NULL; }
|
NAME  EITHER_TOK  name_plus  CLOSE_PAREN  typed_list_name
{ 

  $$ = dis_new_dis_TypedList();
  $$->name = dis_new_dis_Token( strlen($1)+1 );
  strcpy( $$->name, $1 );
  $$->type = $3;
  $$->next = $5;
}
|
NAME  MINUS_TOK NAME  typed_list_name   /* end of list for one type */
{
  $$ = dis_new_dis_TypedList();
  $$->name = dis_new_dis_Token( strlen($1)+1 );
  strcpy( $$->name, $1 );
  $$->type = dis_new_dis_TokenList();
  $$->type->item = dis_new_dis_Token( strlen($3)+1 );
  strcpy( $$->type->item, $3 );
  $$->next = $4;
}
|
NAME  typed_list_name        /* a list element (gets type from next one) */
{
  $$ = dis_new_dis_TypedList();
  $$->name = dis_new_dis_Token( strlen($1)+1 );
  strcpy( $$->name, $1 );
  if ( $2 ) {/* another element (already typed) is following */
    $$->type = dis_copy_dis_TokenList( $2->type );
  } else {/* no further element - it must be an untyped list */
    $$->type = dis_new_dis_TokenList();
    $$->type->item = dis_new_dis_Token( strlen(dis_STdis_ANDARD_TYPE)+1 );
    strcpy( $$->type->item, dis_STdis_ANDARD_TYPE );
  }
  $$->next = $2;
}
;


/***********************************************/
typed_list_variable:     /* returns dis_TypedList */
/* empty */
{ $$ = NULL; }
|
VARIABLE  EITHER_TOK  name_plus  CLOSE_PAREN  typed_list_variable
{ 
  $$ = dis_new_dis_TypedList();
  $$->name = dis_new_dis_Token( strlen($1)+1 );
  strcpy( $$->name, $1 );
  $$->type = $3;
  $$->next = $5;
}
|
VARIABLE  MINUS_TOK NAME  typed_list_variable   /* end of list for one type */
{
  $$ = dis_new_dis_TypedList();
  $$->name = dis_new_dis_Token( strlen($1)+1 );
  strcpy( $$->name, $1 );
  $$->type = dis_new_dis_TokenList();
  $$->type->item = dis_new_dis_Token( strlen($3)+1 );
  strcpy( $$->type->item, $3 );
  $$->next = $4;
}
|
VARIABLE  typed_list_variable        /* a list element (gets type from next one) */
{
  $$ = dis_new_dis_TypedList();
  $$->name = dis_new_dis_Token( strlen($1)+1 );
  strcpy( $$->name, $1 );
  if ( $2 ) {/* another element (already typed) is following */
    $$->type = dis_copy_dis_TokenList( $2->type );
  } else {/* no further element - it must be an untyped list */
    $$->type = dis_new_dis_TokenList();
    $$->type->item = dis_new_dis_Token( strlen(dis_STdis_ANDARD_TYPE)+1 );
    strcpy( $$->type->item, dis_STdis_ANDARD_TYPE );
  }
  $$->next = $2;
}
;

/* durative actions */
durative_action_def:
OPEN_PAREN  DURATIVE_ACTION_TOK
{                  
  dis_opserr( ACTION, NULL );
}                  
NAME               
{                  
  scur_op = dis_new_dis_Pldis_Operator( $4 );
  preference_pointer = NULL;
}                  
param_def  durative_action_def_body  CLOSE_PAREN
{                  
  char temp[128];
  dis_PlNode *p;
  
  if (preference_pointer)
  {
    p = dis_new_dis_PlNode(dis_AND);
    p->sons = dis_new_dis_PlNode(dis_NOT);
    p->sons->sons = dis_new_dis_PlNode(dis_ATOM);
    p->sons->sons->atom = dis_new_dis_TokenList();
    p->sons->sons->atom->item = dis_copy_dis_Token(preference_pointer);
  
    sprintf(temp, "_%s_VIO", preference_pointer1);
    p->sons->next = dis_new_dis_PlNode(dis_NEF);
    p->sons->next->neft = ASSIGN;
    p->sons->next->lh = dis_new_dis_Parsedis_ExpNode( FHEAD ); 
    p->sons->next->lh->atom = dis_new_dis_TokenList();
    p->sons->next->lh->atom->item = dis_copy_dis_Token(temp);
    p->sons->next->rh = dis_new_dis_Parsedis_ExpNode( NUMBER );
    p->sons->next->rh->atom = dis_new_dis_TokenList();
    p->sons->next->rh->atom->item = dis_copy_dis_Token("1");
    p->sons->next->next = copy_dis_PlNode(scur_op->effects);  

    sprintf(temp, "+%s_%s", preference_pointer, scur_op->name);
    scur_op1 = dis_new_dis_Pldis_Operator( temp );
    scur_op1->params = scur_op->params;
    scur_op1->number_of_real_params = scur_op->number_of_real_params;
    scur_op1->parse_params = copy_dis_TypedList(scur_op->parse_params);
    scur_op1->preconds = copy_dis_PlNode(scur_op->preconds);
    scur_op1->duration = copy_dis_PlNode(scur_op->duration);
    scur_op1->effects = p;
    scur_op1->next = dis_gloaded_ops;
    dis_gloaded_ops = scur_op1; 
    gnum_das++;
  }
  scur_op->next = dis_gloaded_ops;
  dis_gloaded_ops = scur_op;
  scur_op = NULL;
  gnum_das++;
}                  
;                  
/***********************************************/
durative_action_def_body:
DURATION_TOK duration_constraint
{                  
	scur_op->duration = $2
}
/* PDDL3 */                  
CONDITION_TOK  da_GD
{                  
	scur_op->preconds = $5;
}                  
EFFECT_TOK  da_adl_effect
{                  
	scur_op->effects = $8;
}                  
;

da_GD:
OPEN_PAREN CLOSE_PAREN
{
        $$ = NULL;
}
|
pref_timed_GD
{
        $$ = $1;
}
|
OPEN_PAREN dis_AND_TOK da_GD_star CLOSE_PAREN
{
        $$ = dis_new_dis_PlNode(dis_AND);
        $$->sons = $3;
}
|
OPEN_PAREN  Fdis_ORdis_ALL_TOK
OPEN_PAREN  typed_list_variable  CLOSE_PAREN
da_GD  CLOSE_PAREN
{ 
  
  dis_PlNode *pln;

  pln = dis_new_dis_PlNode(dis_ALL);
  pln->parse_vars = $4; 

  $$ = pln;
  pln->sons = $6;

}
;
 
da_GD_star:
/* empty */
{
        $$ = NULL;
}
|
da_GD da_GD_star
{
        if ($1)
        {
                $1->next = $2;
                $$ = $1;
        }   
        else
                $$ = $2;
}
;

pref_timed_GD:
OPEN_PAREN PREFERENCE_TOK NAME da_adl_goal_description CLOSE_PAREN
{
        dis_PrefNode *pref;
        dis_ConNode *con;
        char temp[128];

        sprintf(temp, "%s%d", $3, dis_num_preference);
        if (scur_op)
	        pref = new_dis_PrefNode(temp, scur_op->name, $3);
	else
	        pref = new_dis_PrefNode(temp,  "CONSTRAINTS", $3);

        con = new_dis_ConNode(dis_ATOM_c);
        con->sons = $4;  
        pref->body = con;
        pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref;
        dis_num_preference++;
        preference_pointer = pref->name;
        preference_pointer1 = pref->pname;
        $$ = $4;
        $$->value = -1;
}
|
OPEN_PAREN PREFERENCE_TOK da_adl_goal_description CLOSE_PAREN
{
        dis_PrefNode *pref;
        dis_ConNode *con;
        char temp[128];
        
        sprintf(temp, "ANONYMOUS%d", dis_num_preference);
        if (scur_op)
	        pref = new_dis_PrefNode(temp, scur_op->name, "ANONYMOUS");
	else
	        pref = new_dis_PrefNode(temp, "CONSTRAINTS", "ANONYMOUS");

        con = new_dis_ConNode(dis_ATOM_c);
        con->sons = $3;
        pref->body = con;
        pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref; 
        dis_num_preference++;
        preference_pointer = pref->name;
        preference_pointer1 = pref->pname;
        $$ = $3;
        $$->value = -1;
}
|
timed_adl_goal_description
{
        $$ = $1;
}
;

da_adl_goal_description:
timed_adl_goal_description
{                   
  $$ = dis_new_dis_PlNode(dis_AND);
  $$->sons = $1;    
}                   
|                   
OPEN_PAREN dis_AND_TOK timed_adl_goal_description_plus CLOSE_PAREN
{                   
  $$ = dis_new_dis_PlNode(dis_AND);
  $$->sons = $3;    
}                   
;                   

timed_adl_goal_description_plus:
timed_adl_goal_description
{                   
  $$=$1;            
}                   
|                   
timed_adl_goal_description timed_adl_goal_description_plus
{                   
  $$ = $1;          
  $$->next = $2;    
}                   
;                   

timed_adl_goal_description:
OPEN_PAREN AT_START adl_goal_description CLOSE_PAREN
{
	$$ = dis_new_dis_PlNode(dis_AT_START_CONN);                   
  $$->sons = $3;
	$$ = $3;    
}                   
|                   
OPEN_PAREN AT_END adl_goal_description CLOSE_PAREN
{                   
	$$ = dis_new_dis_PlNode(dis_AT_END_CONN);
  $$->sons = $3;    
	$$ = $3;
}                   
|                   
OPEN_PAREN OVER_ALL adl_goal_description CLOSE_PAREN
{                   
	$$ = dis_new_dis_PlNode(dis_OVER_ALL_CONN);
  $$->sons = $3;    
	$$ = $3;
}                   
;

duration_constraint:
OPEN_PAREN EQ_TOK DURATION_VAR_TOK f_exp CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode(dis_COMP);
  $$->comp = EQ;
  $$->lh = NULL;
  $$->rh = $4;
  duration_exp = copy_dis_Parsedis_ExpNode($4);
}
/*
OPEN_PAREN CLOSE_PAREN
{
}
|     
OPEN_PAREN dis_AND_TOK simple_duration_constraint_plus CLOSE_PAREN
{                        
  $$ = dis_new_dis_PlNode(dis_AND);  
  $$->sons = $3;         
}                        
|                        
simple_duration_constraint
{                        
  $$ = dis_new_dis_PlNode(dis_AND);  
  $$->sons = $1;         
}                        
;

simple_duration_constraint_plus:
simple_duration_constraint
{                        
  $$ = $1;               
}                        
|                        
simple_duration_constraint simple_duration_constraint_plus
{                        
  $$=$1;                 
  $$->next = $2;         
}                        
;
                        
simple_duration_constraint:
OPEN_PAREN LEQ_TOK DURATION_VAR_TOK d_value CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode(dis_COMP);
  $$->comp = LEQ;
  $$->lh = NULL;
  $$->rh = $4;
}
|
OPEN_PAREN EQ_TOK DURATION_VAR_TOK d_value CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode(dis_COMP);
  $$->comp = EQ;
  $$->lh = NULL;
  $$->rh = $4;
}
|
OPEN_PAREN GEQ_TOK DURATION_VAR_TOK d_value CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode(dis_COMP);
  $$->comp = GEQ;
  $$->lh = NULL;
  $$->rh = $4;
}
|
OPEN_PAREN AT_START simple_duration_constraint CLOSE_PAREN
{                        
  $$ = dis_new_dis_PlNode(dis_AND);  
}                        
|
OPEN_PAREN AT_END simple_duration_constraint CLOSE_PAREN
{                        
  $$ = dis_new_dis_PlNode(dis_AND);  
}                        
;                        

d_value:                 
f_exp                    
*/;

da_adl_effect:
OPEN_PAREN CLOSE_PAREN
{
}
|
OPEN_PAREN dis_AND_TOK timed_adl_effect_plus CLOSE_PAREN
{                   
  $$ = dis_new_dis_PlNode(dis_AND);
  $$->sons = $3;    
}                   
|                   
timed_adl_effect    
{                   
  $$ = dis_new_dis_PlNode(dis_AND);
  $$->sons = $1;    
}                   
|                   
OPEN_PAREN  Fdis_ORdis_ALL_TOK
OPEN_PAREN  typed_list_variable  CLOSE_PAREN
da_adl_effect  CLOSE_PAREN
{                   
  dis_PlNode *pln;      

  pln = dis_new_dis_PlNode(dis_ALL);
  pln->parse_vars = $4;

  $$ = pln;         
  pln->sons = $6;   
}                   
|                   
OPEN_PAREN  dis_WHEN_TOK  da_adl_goal_description  timed_adl_effect  CLOSE_PAREN
{                   
  /* This will be conditional effects in FF representation, but here
   * a formula like (WHEN p q) will be saved as:
   *  [WHEN]        
   *  [sons]        
   *   /  \         
   * [p]  [q]       
   * That means, the first son is p, and the second one is q.
   */               
  $$ = dis_new_dis_PlNode(dis_WHEN);
  $3->next = $4;    
  $$->sons = $3;    
}                   
|                   
OPEN_PAREN ASSIGN_TOK f_head f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = ASSIGN;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN SCALE_UP_TOK f_head f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = SCALE_UP;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN SCALE_DOWN_TOK f_head f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = SCALE_DOWN;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN INCREASE_TOK f_head f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = INCREASE;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN DECREASE_TOK f_head f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = DECREASE;
  $$->lh = $3;
  $$->rh = $4;
}
;                   

timed_adl_effect_plus:
timed_adl_effect    
{                   
  $$ = $1;          
}                   
|                   
timed_adl_effect timed_adl_effect_plus
{                   
  $$ = $1;          
  $$->next = $2;    
}                   
;                   

timed_adl_effect:
OPEN_PAREN AT_START adl_effect CLOSE_PAREN
{
	$$ = dis_new_dis_PlNode(dis_AT_START_CONN);
  $$->sons = $3;
	$$ = $3;
}
|
OPEN_PAREN AT_END adl_effect CLOSE_PAREN
{
	$$ = dis_new_dis_PlNode(dis_AT_END_CONN);
  $$->sons = $3;
	$$ = $3;
}
|
OPEN_PAREN AT_START f_assign_da CLOSE_PAREN
{
	$$ = dis_new_dis_PlNode(dis_AT_START_CONN);
  $$->sons = $3;
	$$ = $3;
}
|
OPEN_PAREN AT_END f_assign_da CLOSE_PAREN
{
	$$ = dis_new_dis_PlNode(dis_AT_END_CONN);
  $$->sons = $3;
	$$ = $3;
}
|
OPEN_PAREN INCREASE_TOK f_head f_exp_t CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = INCREASE;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN DECREASE_TOK f_head f_exp_t CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = DECREASE;
  $$->lh = $3;
  $$->rh = $4;
}
;                   

f_assign_da:
OPEN_PAREN ASSIGN_TOK f_head f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = ASSIGN;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN SCALE_UP_TOK f_head f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = SCALE_UP;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN SCALE_DOWN_TOK f_head f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = SCALE_DOWN;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN INCREASE_TOK f_head f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = INCREASE;
  $$->lh = $3;
  $$->rh = $4;
}
|
OPEN_PAREN DECREASE_TOK f_head f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_PlNode( dis_NEF );
  $$->neft = DECREASE;
  $$->lh = $3;
  $$->rh = $4;
}
;                   

f_exp_da:
OPEN_PAREN AD_TOK f_exp_da f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_Parsedis_ExpNode( AD );
  $$->leftson = $3;
  $$->rightson = $4;
}
|
OPEN_PAREN MINUS_TOK f_exp_da f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_Parsedis_ExpNode( SU );
  $$->leftson = $3;
  $$->rightson = $4;
}
|
OPEN_PAREN MU_TOK f_exp_da f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_Parsedis_ExpNode( MU );
  $$->leftson = $3;
  $$->rightson = $4;
}
|
OPEN_PAREN DI_TOK f_exp_da f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_Parsedis_ExpNode( DI );
  $$->leftson = $3;
  $$->rightson = $4;
}
|
OPEN_PAREN MINUS_TOK f_exp_da CLOSE_PAREN
{
  $$ = dis_new_dis_Parsedis_ExpNode( MINUS );
  $$->leftson = $3;
}
|
DURATION_VAR_TOK
{
//	$$ = dis_new_dis_Parsedis_ExpNode( DURATION );
	$$ = duration_exp;
	duration_exp = NULL;
}
|
f_exp
;

f_exp_t:	
OPEN_PAREN '*' f_exp TIME_TOK CLOSE_PAREN
{
	$$ = dis_new_dis_Parsedis_ExpNode( EXPT1 );
	$$->leftson = $3;
	$$->rightson = NULL;
}
|
OPEN_PAREN '*' TIME_TOK f_exp CLOSE_PAREN
{
	$$ = dis_new_dis_Parsedis_ExpNode( EXPT2 );
	$$->leftson = NULL;
	$$->rightson = $4;
}
|
TIME_TOK	
{
	$$ = dis_new_dis_Parsedis_ExpNode( EXPT3 );
	$$->leftson = NULL;
	$$->rightson = NULL;
}
;

%%
#include "lex.dis_ops_pddl.c"


/**********************************************************************
 * Functions
 **********************************************************************/

/* 
 * call	bison -pops -bscan-ops scan-ops.y
 */

void dis_opserr( int errno, char *par )

{

  sact_err = errno;

  if ( sact_err_par ) {
    free(sact_err_par);
  }
  if ( par ) {
    sact_err_par = dis_new_dis_Token(strlen(par)+1);
    strcpy(sact_err_par, par);
  } else {
    sact_err_par = NULL;
  }

}
  


int yyerror( char *msg )

{

  fflush(stdout);
  fprintf(stderr, "\n%s: syntax error in line %d, '%s':\n", 
	  dis_gact_filename, dis_lineno, yytext);

  if ( NULL != sact_err_par ) {
    fprintf(stderr, "%s %s\n", serrmsg[sact_err], sact_err_par);
  } else {
    fprintf(stderr, "%s\n", serrmsg[sact_err]);
  }

  exit( 1 );

}



void dis_load_ops_file( char *filename )

{

  FILE * fp;/* pointer to input files */
  char tmp[dis_MAX_LENGTH] = "";

  /* open operator file 
   */
  if( ( fp = fopen( filename, "r" ) ) == NULL ) {
    sprintf(tmp, "\nff: can't find operator file: %s\n\n", filename );
    perror(tmp);
    exit( 1 );
  }

  dis_gact_filename = filename;
  dis_lineno = 1; 
  yyin = fp;

  yyparse();

  fclose( fp );/* and close file again */

}
