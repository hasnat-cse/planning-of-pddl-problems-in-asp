
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
 * Description: functions for Parsing PDDL3  
 *
 * Author: Ruoyun Huang, Yixin Chen 2006
 *
 *********************************************************************/ 

#include "string.h"
#include "dis_ff.h"
#include "dis_parse.h"
#include "dis_memory.h"
#include "dis_output.h"
#include "dis_expressions.h"
#include "casual_graph.h"
#include "lpg.h"
#define MAX_CONSTRAINTS 200000
#define MAX_TEMPLATES 200000
#define MAXLEN_OF_GROUPLIST 10
#define MAX_EVAL_NODE 10000

typedef struct _ConConn
{   

  dis_Connective_Con connective;
  float weight, time1, time2;
  int *cond, num1, num, fact, fv;
} ConConn;

typedef struct _GroupList
{
  int n, i[MAXLEN_OF_GROUPLIST];
} GroupList;
GroupList gl;
int **gtemplates;
int gnum_templates;


int traj_n;
int traj_plan[10000];
float traj_time[10000];
dis_State S0;
float g_weight = 0.01, constraint_vio;
int priority_threshold, *priority;

extern dis_TypedListList *dis_gparse_predicates, *dis_gparse_functions;
extern dis_PlNode *dis_gorig_initial_facts;
extern dis_Pldis_Operator *dis_gloaded_ops;
extern dis_PrefNode *dis_gloaded_preferences;
extern dis_Facts *dis_ginitial;
extern DuraTab *table;
dis_Bool dis_depend_efs(int, int);




typedef struct _Event
{
  int op;
  double time;
} Event;
Event *efqueue;
int queue_size;



void print_dis_ConNode( dis_ConNode *plnode, int indent )
{
  dis_ConNode *i_son_c;

  if ( !plnode ) {
    printf("none\n");
    return;
  }
  
  switch (plnode->connective) {
  case dis_ALL_c_c: 
    printf("ALL ");
    dis_print_indent(indent);
    printf("(   ");
    print_dis_ConNode(plnode->sons_c,indent+4);
    dis_print_indent(indent);
    printf(")\n");
    break;
  case dis_AND_c_c: 
    printf("A(  ");
    print_dis_ConNode(plnode->sons_c, indent+4);
    if ( plnode->sons ) {
      for ( i_son_c = plnode->sons_c->next; i_son_c!=NULL; i_son_c = i_son_c->next ) {
	dis_print_indent(indent);
	printf("AND ");
	print_dis_ConNode(i_son_c,indent+4);
      }
    }
    dis_print_indent(indent);      
    printf(")\n");
    break;
  case dis_ATOM_c:
    printf("(");
    dis_print_dis_PlNode(plnode->sons, indent+4);
    printf(")\n");
    break;
  case dis_AT_END_c:
    printf ("(AT_END ");
    dis_print_dis_PlNode (plnode->sons, indent + 4);
    dis_print_indent (indent + 3);
    printf (")\n");
    break;
  case dis_ALWAYS_c:
    printf ("(ALWAYS ");
    dis_print_dis_PlNode (plnode->sons, indent + 4);
    dis_print_indent (indent + 3);
    printf (")\n");
    break;
  case dis_SOMETIME_c:
    printf ("(SOMETIME ");
    dis_print_dis_PlNode (plnode->sons, indent + 4);
    dis_print_indent (indent + 3);
    printf (")\n");
    break;
  case dis_WITHIN_c:
    printf ("(WITHIN %f ", plnode->number);
    dis_print_dis_PlNode (plnode->sons, indent + 4);
    dis_print_indent (indent + 3);
    printf (")\n");
    break;
  case dis_AT_MOST_ONCE_c:
    printf ("(AT_MOST_ONCE ");
    dis_print_dis_PlNode (plnode->sons, indent + 4);
    dis_print_indent (indent + 3);
    printf (")\n");
    break;
  case dis_SOMETIME_AFTER_c:
    printf ("SOMETIME_AFTER (");
    dis_print_dis_PlNode (plnode->sons, indent + 4);
    dis_print_indent (indent + 3);
    dis_print_dis_PlNode (plnode->sons2, indent + 4);
    dis_print_indent (indent + 3);
    printf (")\n");
    break;
  case dis_SOMETIME_BEFORE_c:
    printf ("SOMETIME_BEFORE (");
    dis_print_dis_PlNode (plnode->sons, indent + 4);
    dis_print_indent (indent + 3);
    dis_print_dis_PlNode (plnode->sons2, indent + 4);
    dis_print_indent (indent + 3);
    printf (")\n");
    break;
  case dis_ALWAYS_WITHIN_c:
    printf ("ALWAYS_WITHIN %f (", plnode->number);
    dis_print_dis_PlNode (plnode->sons, indent + 4);
    dis_print_indent (indent + 3);
    dis_print_dis_PlNode (plnode->sons2, indent + 4);
    dis_print_indent (indent + 3);
    printf (")\n");
    break;
  case dis_HOLD_DURING_c:
    printf ("(HOLD_DURING %f %f ", plnode->number, plnode->number2);
    dis_print_dis_PlNode (plnode->sons, indent + 4);
    dis_print_indent (indent + 3);
    printf (")\n");
    break;
  case dis_HOLD_AFTER_c:
    printf ("ALWAYS_WITHIN %f (", plnode->number);
    dis_print_dis_PlNode (plnode->sons, indent + 4);
    dis_print_indent (indent + 3);
    printf (")\n");
    break;
  default:
    printf("\n***** ERROR ****");
    printf("\nprint_plnode: %d > Wrong Node specifier\n", plnode->connective);
    exit(1);
  }     

  if (plnode->next)
  {
    printf("------------------------------\n");
    print_dis_ConNode(plnode->next, indent);
  }

} 

void print_dis_PrefNode( dis_PrefNode *plnode)
{
  printf("%s %s %s\n", plnode->name, plnode->opname, plnode->pname);
  print_dis_ConNode(plnode->body, 2);  
  printf("\n");
  if (plnode->next)
  {
    printf("------------------------------\n");
    print_dis_PrefNode(plnode->next);
  }
}

dis_ConNode *new_dis_ConNode( dis_Connective_Con c )

{

  dis_ConNode *result = ( dis_ConNode * ) calloc( 1, sizeof( dis_ConNode ) );
  dis_CHECK_PTR(result);

  result->connective = c;
  result->number = result->number2 = 0;
  result->sons = NULL;
  result->sons2 = NULL;
  result->sons_c = NULL;
  result->next = NULL;

  return result;

}

dis_PrefNode *new_dis_PrefNode( char *name, char *opname, char *pname)

{

  dis_PrefNode *result = ( dis_PrefNode * ) calloc( 1, sizeof( dis_PrefNode ) );
  dis_CHECK_PTR(result);
  
  result->name = (char *) malloc(strlen(name)+2);
  result->opname = (char *) malloc(strlen(opname)+1);
  result->pname = (char *) malloc(strlen(pname)+1);
  strcpy(result->name+1, name);
  result->name[0] = '_';
  strcpy(result->pname, pname);
  strcpy(result->opname, opname);
  result->body = NULL;
  result->next = NULL;

  return result;

}




