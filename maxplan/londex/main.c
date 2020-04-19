/*********************************************************************
 * (C) Copyright 2002  Universita' degli Studi di Brescia
 *     Dipartimento di Elettronica per l'Automazione
 *     Via Branze 38, 25123 Brescia, Italy
 *
 * All rights reserved. Use of this software is permitted ONLY for
 * non-commercial research purposes, and it may be copied only
 * for that use only. All copies must include this copyright message.
 * This software is made available AS IS, and neither the authors
 * nor the University of Brescia make any warranty about the
 * software or its performance.
 *
 *********************************************************************/



/********************************************************************
 * File: main.c 
 * Description:  Main routines of LPG.
 *
 *   PDDL 2.1 version without conditional and quantified effects 
 *
 * Authors: Alfonso Gerevini, Marco Lazzaroni, Alessandro Saetti, 
 *          Ivan Serina, Sergio Spinoni
 *
 *********************************************************************/ 



#include <math.h>
#include <sys/time.h>
#include "lpg.h"
#include "inst_utils.h"
#include "utilities.h"
#include "DistributeSearch.h"
#include <values.h>
#include "ff.h"
#include "dis_ff.h"
#include "dis_output.h"
#include "dis_inst_final.h"

/******************************************************************************
 *                             GLOBAL VARIABLES                               *
 ******************************************************************************/

//extern void mffDistributedSearch(char *, char *);
//extern void DistributeSearch(State *, State *, PlanAction **);

/**
 * PARSING
 **/

/* used for pddl parsing, flex only allows global variables */
int gbracket_count;
char *gproblem_name;

/* The current input line number */
int lineno = 1;

/* The current input filename */
char *gact_filename;

/* The pddl domain name */
char *gdomain_name = NULL;

/* loaded, uninstantiated operators */
PlOperator *gloaded_ops = NULL;

PlOperator *gloaded_pl2ops = NULL;

/* constraints */
ConNode *gloaded_constraints = NULL;
dis_ConNode *dis_gloaded_constraints = NULL;
/* preferences */
PrefNode *gloaded_preferences = NULL;
dis_PrefNode *dis_gloaded_preferences = NULL;
int num_preference = 0, num_constraint = 0;
int dis_num_preference = 0, dis_num_constraint = 0;

int num_dur = 0;
/* derived predicates */
PlDP *gloaded_dps = NULL;

/* stores initials as fact_list */
PlNode *gorig_initial_facts = NULL;

/* not yet preprocessed goal facts  */

PlNode *gorig_goal_facts = NULL;

/* metric for the plan*/
PlNode *gmetric_exp = NULL;

/* axioms as in UCPOP before being changed to ops */
PlOperator *gloaded_axioms = NULL;

/* the types, as defined in the domain file */
TypedList *gparse_types = NULL;

/* the constants, as defined in domain file */
TypedList *gparse_constants = NULL;

/* the predicates and their arg types, as defined in the domain file */
TypedListList *gparse_predicates = NULL;

/* PDDL2--*/
TypedListList *gparse_functions = NULL;

/* the objects, declared in the problem file */
TypedList *gparse_objects = NULL;

/* connection to instantiation ( except ops, goal, initial ) */

/* all typed objects  */
FactList *gorig_constant_list = NULL;

/* the predicates and their types */
FactList *gpredicates_and_types = NULL;

FactList *gfunctions_and_types = NULL;



/**
 * INSTANTIATING
 **/

/* global arrays of constant names,
 *               type names (with their constants),
 *               predicate names,
 *               predicate aritys,
 *               defined types of predicate args
 */
Token gconstants[MAX_CONSTANTS];
int gnum_constants = 0;
Token gtype_names[MAX_TYPES];
int gtype_consts[MAX_TYPES][MAX_TYPE];
Bool gis_member[MAX_CONSTANTS][MAX_TYPES];
int gtype_size[MAX_TYPES];
int gnum_types = 0;

Token gpredicates[MAX_PREDICATES];
int garity[MAX_PREDICATES];
int gpredicates_args_type[MAX_PREDICATES][MAX_ARITY];
int gnum_predicates = 0;

Token gfunctions[MAX_FUNCTIONS];
int gfunarity[MAX_FUNCTIONS];
int gfunctions_args_type[MAX_FUNCTIONS][MAX_ARITY];
int gnum_functions = 0;

/* derived predicates */
int gnum_deripreds = 0;
DerivePred* gderipreds;

/* timed initial literals */
int gnum_tils = 0;
TimedInitial *gtils = NULL, *g_tils = NULL;



/* the domain in integer (Fact) representation
 */
Operator_pointer goperators[MAX_OPERATORS];
int gnum_operators = 0;
Fact gfull_initial[MAX_INITIAL];
int gnum_full_initial = 0;


NumVar **gfullnum_initial = NULL;
int gnum_fullnum_initial = 0;
int gnum_fullnum_blocks;

int gnum_mipsnum = 0;
int gmipsnum[MAXMIPSNUM];
		
int max_num_value = 30000; //MAX_NUM_INITIAL

int gnum_comp_var = 0;
int gnum_block_compvar;
int *gis_inertial = NULL;
int goptimization_exp = -1;
int *gis_not_appliable;



WffNode *ggoal = NULL;


/* stores inertial - information: is any occurence of the predicate
 * added / deleted in the uninstantiated ops ?
 */
Bool gis_added[MAX_PREDICATES];
Bool gis_deleted[MAX_PREDICATES];



/* splitted initial state:
 * initial non static facts,
 * initial static facts, divided into predicates
 * (will be two dimensional arrays, allocated directly before need)
 */
Facts *ginitial = NULL;
int gnum_initial = 0;
Fact **ginitial_predicate;
int *gnum_initial_predicate;



/* the type numbers corresponding to any unary inertia
 */
int gtype_to_predicate[MAX_PREDICATES];
int gpredicate_to_type[MAX_TYPES];

/* (ordered) numbers of types that new type is intersection of
 */
TypeArray gintersected_types[MAX_TYPES];
int gnum_intersected_types[MAX_TYPES];



/* splitted domain: hard n easy ops
 */
Operator_pointer *ghard_operators;
int gnum_hard_operators;
NormOperator_pointer *geasy_operators;
int gnum_easy_operators;



/* so called Templates for easy ops: possible inertia constrained
 * instantiation constants
 */
EasyTemplate *geasy_templates;
int gnum_easy_templates;



/* first step for hard ops: create mixed operators, with conjunctive
 * precondition and arbitrary effects
 */
MixedOperator *ghard_mixed_operators;
int gnum_hard_mixed_operators;



/* hard ''templates'' : pseudo actions
 */
PseudoAction_pointer *ghard_templates;
int gnum_hard_templates;



/* store the final "relevant facts"
 */
Fact grelevant_facts[MAX_RELEVANT_FACTS];
int gnum_relevant_facts;
int gnum_pp_facts;



/* the final actions and problem representation
 */
Action *gactions;
int gnum_actions;
State ginitial_state;
State ggoal_state;
State saved_ginitial_state;
State saved_ggoal_state;

int cvar_hash_table[HASH_SIZE];
int tot = 0, compl = 0;

//char *lvar_names[MAX_VARS];
//int lvar_types[MAX_VARS];
int **l_vals = NULL; 
int **lstar_vals = NULL;
int **r_vals = NULL;
int **tested_vars = NULL;

/* for facts and mutex
*/
int *F;			/*[MAX_RELEVANT_FACTS/32+1]; */


const char *goperator_table[] = {
  "MUL_OP",
  "DIV_OP",
  "MINUS_OP",
  "UMINUS_OP",
  "PLUS_OP",

  "FIX_NUMBER",
  "VARIABLE_OP",

  "INCREASE_OP",
  "DECREASE_OP",
  "SCALE_UP_OP",
  "SCALE_DOWN_OP",
  "ASSIGN_OP",

  "LESS_THAN_OP",
  "LESS_THAN_OR_EQUAL_OP",
  "EQUAL_OP",
  "GREATER_THAN_OP",
  "GREATER_OR_EQUAL_OP",

  "MINIMIZE_OP",
  "MAXIMIZE_OP"
};




/**
 * CONNECTIVITY GRAPH
 **/


/* one ops (actions) array ... */
OpConn *gop_conn;
int gnum_op_conn;



/* one effects array ... */
EfConn *gef_conn;
int gnum_ef_conn;



/* one facts array. */
FtConn *gft_conn;
int gnum_ft_conn;

FtConn *gnoop_conn;

int gnum_ft_block;
int gnum_ef_block;




/**
 * FF SEARCHING NEEDS
 **/

/* the goal state, divided into subsets
 *  */
State *ggoal_agenda;
int gnum_goal_agenda;



/* byproduct of fixpoint: applicable actions */
int *gA;
int gnum_A;



/* communication from extract 1.P. to search engines:
 * 1P action choice */
int *gH;
int gnum_H;



/* the effects that are considered true in relaxed plan */
int *gin_plan_E;
int gnum_in_plan_E;


/* always stores (current) serial plan */
int gplan_ops[MAX_PLAN_LENGTH];
int gnum_plan_ops = 0;
int gtot_plan_ops = 0;


/* stores the states that the current plan goes through
 * ( for knowing where new agenda entry starts from ) */
State gplan_states[MAX_PLAN_LENGTH + 1];
State gbfs_state;

PlanAction *subplan_actions = NULL;




int num_try;
int return_count;
unsigned int seed;


constraints_list treated_c_l[MAX_FALSE];
constraints_list unsup_fact[MAX_FALSE];
constraints_list unsup_num_fact[MAX_FALSE];

neighb_list neighb_vect[MAX_MAX_NODES];
int num_neighborhood;

/* final sort of actions in temp_vect */  
int *pos_temp_vect;//[MAX_MAX_NODES];

def_level * vectlevel[MAX_PLAN_LENGTH + 1];
def_level * temp_vectlevel[MAX_PLAN_LENGTH + 1];


inform_list *remove_act_chain; //[MAX_PLAN_LENGTH];
int ind_remove_act_chain;

/* Used for action <--> noop mutex 
 */
noop_not_in *noop_free_list; 

unsigned long tot_alloc_mem_size;

char fct_file[MAX_LENGTH];

/* Statistical data about Lagrange multipliers
*/
#ifdef __STATISTIC_LM__

 /* global variables used to compute average, total maximum value, minimum value of
   Lagrange multipliers for preconditions and mutex 
  */
 
 float average_prec_final = 0.0;
 float average_me_final = 0.0;
 float var_prec_final = 0.0;
 float var_me_final = 0.0;

 float lm_prec_min_final,lm_prec_max_final,lm_me_min_final,lm_me_max_final;
 
/*Vars used for files
 */

 FILE *file_average_prec;
 FILE *file_var_prec;
 FILE *file_average_me;
 FILE *file_var_me;

#endif // end __STATISTIC_LM__



/**
 * COMPUTE MUTEX
 **/


/* Number of set mutex and level
 */
int gnum_mutex;
int gmutex_level;
/* Total number of fact-action mutex, action-fact mutex, 
   action-action mutex, fact-fact mutex 
 */
int total_ft_ef_mutex = 0;
int total_ef_ft_mutex = 0;
int total_ef_ef_mutex = 0;
int total_ft_ft_mutex = 0;

/* fact-fact mutex matrix
 */
int **FT_FT_mutex = NULL;
/* fact-action mutex matrix
 */
int **FT_EF_mutex = NULL;
/* action-action mutex matrix
 */
int **EF_EF_mutex = NULL;
/* action-fact mutex matrix
 */
int **EF_FT_mutex = NULL;


/**
 * NUMERIC PLANNING
 **/

/* Structure for numeric vars
 */

CompositeNumVar *gcomp_var;
float  *gcomp_var_value;
float  *gcomp_var_value_before;


/**
 * TEMPORAL PLANNING
 **/

char **mat_ord;
inform_list *act_ord_vect;
int num_act_ord;
short *prop_level_index;


/**
 * CPU TIME MANAGEMENT
 **/

struct tms start_time;
struct tms glob_start_time;
struct tms glob_end_time;
float gtotal_time, gparsing_time;
char gcomm_line[MAX_LENGTH * 2];
char gops_file[MAX_LENGTH];
char gfct_file[MAX_LENGTH];
char glpg_path[MAX_LENGTH];


/**
 * MISCELLANEUS
 **/

/* used to time the different stages of the planner
 */
float gtempl_time = 0, greach_time = 0, grelev_time = 0, gconn_time = 0, 
  gnum_time = 0, gmutex_total_time = 0, gmutex_ft_time = 0, 
  gmutex_ops_time = 0, gmutex_num_time = 0;
float gsearch_time = 0;

float build_ad_time, fixpoint_time;

/* the command line inputs
 */
struct _command_line gcmd_line;

/* number of states that got heuristically evaluated
 */
int gevaluated_states = 0;

/* maximal depth of breadth first search
 */
int gmax_search_depth = 0;

char temp_name[256];

node_cost *fact_costs; //[MAX_MAX_NODES];
/* Bitvector used by remove_temp_action to find facts that 
   become TRUE after it is removed
*/
int *new_true_facts;
/* Bitvector used by remove_temp_action to find facts that 
   become FALSE after it is removed
*/
int *new_false_facts;	

/* TRUE if termination condition is reached
 */
Bool is_terminated=FALSE;

Bool ComputeMutex;

char gops_file[MAX_LENGTH];
char gfct_file[MAX_LENGTH];


/********************************************************************
 *                           HEADERS FOR PARSING                    *
 ********************************************************************/

void load_ops_file (char *filename);
void load_fct_file (char *filename);

/*****************************************************************
 *                          MAIN ROUTINE                         *
 *****************************************************************/
        
// ugly way to tell if ADL
// no time to elaborate


#define MAX_LINE_CHARS    1024
int get_requirements(char *ops_file)
{                   
	FILE *inFile;
	char lineStringBuffer[MAX_LINE_CHARS];
	int i, x = 0;
  
	GpG.gis_ADL = FALSE;
	GpG.is_deripred = FALSE;
	GpG.is_til = FALSE;
	GpG.is_durative = FALSE;
	GpG.is_fluents = FALSE;
	if ((inFile = fopen(ops_file, "r")) == NULL) 
	{
		printf("Can not open %s\n", ops_file);
		exit(1);
	}
	while (!feof(inFile) && fgets(lineStringBuffer, MAX_LINE_CHARS, inFile))
	{
		for (i=0;lineStringBuffer[i];i++)
			lineStringBuffer[i] = (char) toupper((int) lineStringBuffer[i]);
		if (strstr(lineStringBuffer, ":ADL"))
			GpG.gis_ADL = TRUE;
		if (strstr(lineStringBuffer, ":DERIVED-PREDICATES"))
			GpG.is_deripred = TRUE;
		if (strstr(lineStringBuffer, ":FLUENTS"))
			GpG.is_fluents = TRUE;
		if (strstr(lineStringBuffer, ":TIMED-INITIAL-LITERALS"))
			GpG.is_til = TRUE;
		if (strstr(lineStringBuffer, ":DURATIVE-ACTIONS"))
			GpG.is_durative = TRUE;
		if (strstr(lineStringBuffer, " PSR"))
			x = 1;	
	}
	fclose(inFile);
	return x;
}

Bool ADL_ops_file (char *ops_file)
{                   
    FILE *inFile;
    char lineStringBuffer[MAX_LINE_CHARS];
    char targetString[MAX_LINE_CHARS];
    char* pStr;
        
    if ((inFile = fopen(ops_file, "r")) == NULL) {
         printf("Can not open %s\n", ops_file);
         exit(1);
    }
    while (!feof(inFile) && fgets(lineStringBuffer, MAX_LINE_CHARS, inFile)) {
        sscanf(lineStringBuffer, "%s", targetString);
        if(strcmp(targetString, "(:requirements")==0) {
            pStr = &(lineStringBuffer[16]);
            sscanf(pStr, "%s", targetString);
            //printf("%s\n",targetString);  
            if(strcmp(targetString, ":adl")==0) {
               //     printf("ADL domain!\n"); 
                    return TRUE;
            } else {
                    return FALSE;
            }
        }
    }
    return FALSE;
}  
int main (int argc, char *argv[])
{

  /* resulting name for ops file */
  char ops_file[MAX_LENGTH] = "";
  /* same for fct file */
  char fct_file[MAX_LENGTH] = "";

  char sol_file[MAX_LENGTH] = "";

  struct tms start, end;

  struct timeval tv;
  struct timezone tz;

  State current_start, current_end;
  int i, j, k;
  Bool found_plan=0;


#ifdef __EFENCE__
  extern int EF_ALLOW_MALLOC_0;
  EF_ALLOW_MALLOC_0 = 1;
#endif


  dis_gcmd_line.display_info = 1;
  dis_gcmd_line.debug = 0;
  dis_gcmd_line.ehc = dis_TRUE;
  dis_gcmd_line.optimize = dis_FALSE;
  dis_gcmd_line.g_weight = 1;
  dis_gcmd_line.h_weight = 1;
  
  
  so_signal_management();

  strcpy (gcomm_line, "");
  for (i = 0; i < argc; i++)
    {
      strcat (gcomm_line, argv[i]);
      strcat (gcomm_line, " ");
    }
  get_path (*argv, glpg_path);
  initialize_preset_values ();


#ifdef __STATISTIC_LM__
  init_statistic();
#endif 

  /*Reset  hash-table
   */ 
  //reset_cvar_hash_table();

  /* Initialize random seed
   */
  gettimeofday (&tv, &tz);
  seed = ((tv.tv_sec & 0177) * 1000000) + tv.tv_usec;


  if (argc == 1 || (argc == 2 && *++argv[0] == '?'))
    {
      lpg_usage ();
      exit (1);
    }
    gcmd_line.out_file_name[0] = 0;
  if (!process_command_line (argc, argv))
    {
      lpg_usage ();
      exit (1);
    }


  if (!gcmd_line.ops_file_name || !gcmd_line.fct_file_name)
    {
      fprintf (stdout, "\n%s: two input files needed\n\n", NAMEPRG);
      lpg_usage ();
      exit (1);
    }

  sprintf (ops_file, "%s%s", gcmd_line.path, gcmd_line.ops_file_name);
  sprintf (fct_file, "%s%s", gcmd_line.path, gcmd_line.fct_file_name);

  strcpy (gops_file, ops_file);
  strcpy (gfct_file, fct_file);
  sprintf (sol_file, "%s%s", gcmd_line.path, gcmd_line.sol_file_name);


  times (&glob_start_time);
  times (&start);


  // ADL?
  GpG.gis_ADL = ADL_ops_file(ops_file);
  
  if(!get_requirements(ops_file) || !GpG.gis_ADL) {
    printf ("\nParsing domain file\n");
	fflush(stdout);

    /* it is important for the pddl language to define the domain before 
    * reading the problem 
    */
    if(gloaded_dps) {
      GpG.is_deripred = TRUE;
    }
    else {
      GpG.is_deripred = FALSE;
    }                 
  }
    
  /* ==================================================*/
  GpG.MFF_parser = 1;
  dis_MFF_main(ops_file, fct_file); 
  
  /*
  if(GpG.MFF_parser) {
    mffDistributedSearch(ops_file, fct_file);  
    exit(0);
  }
  */
}
