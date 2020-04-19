
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
 * File: dis_constraints.c
 * Description: definitions of functions related PDDL3 constraints
                parsing and processing

 * Author: Ruoyun Huang, Yixin Chen 2006
 *
 *********************************************************************/ 



#ifndef _dis_CONSTRAINTS_H
#define _dis_CONSTRAINTS_H


typedef struct _ConConn
{   
  float weight, time1, time2;
  int *cond, num1, num, fact, fv;
} ConConn;

void dis_add_predicate(char *, dis_TypedList *);
void dis_add_function(char *);
void dis_add_initial_fv(char *);
void dis_add_constraints();
void dis_setup_grounded_constraints();
void print_dis_ConNode( dis_ConNode *plnode, int indent );
void print_dis_PrefNode( dis_PrefNode *plnode );
dis_ConNode *new_dis_ConNode( dis_Connective_Con c);
dis_PrefNode *new_dis_PrefNode( char *, char *, char *);   
float dis_metric_value(dis_State *);


int evaluate_goal_set(dis_State *state);
void dis_collect_H_ps_info( dis_State *source);

int evaluate_combine_ff(dis_State *S);
int dis_collect_cf_H_info(dis_State *source , int h);

extern int traj_n;
extern int traj_plan[5000];
extern float traj_time[5000];
extern dis_State S0;
extern int priority_threshold, *priority;
extern float g_weight;

int combined_fgoal_weight[1000];
int violation_facts[1000];
int violation_facts_num;

int violated_fact[100];
int violated_fact_num;
#endif 
