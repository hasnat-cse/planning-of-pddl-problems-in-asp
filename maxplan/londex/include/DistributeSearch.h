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
 * File: LocalSearch.h
 * Description: header file for local-search strategies
 *
 *   PDDL 2.1 version without conditional and quantified effects 
 *
 * Authors: Alfonso Gerevini, Marco Lazzaroni, Alessandro Saetti, 
 *          Ivan Serina, Sergio Spinoni
 *
 *********************************************************************/ 

 
/***********************************************************************
 * File: DistributeSearch.h
 * Description: Changed from LocalSearch.h originally in LPG.
 *
 * Author: Ruoyun Huang, Yixin Chen 2006
 *
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
 *********************************************************************/ 


#ifndef __DISTRIBUTESEARCH_H 
#define __DISTRIBUTESEARCH_H  

#include "ff.h"
#include "lpg.h"

enum dStrategy {LPG_DIS, FF_DIS, HIBURY_DIS};

//extern gentry *iga_graph;
 
void mffDistributedSearch(char *ops_file, char *fct_file);

//direct_MFF_symmetry (State * start_state, State * end_state, PlanAction ** plan_actions);


void restore_subspace_actions();
//void output_esp_solution(PlanAction ** plan_actions);
void var_source_to_dest( State *dest, State *source );

void random_twist_goal_order(State * end_state);
void twist_goal_order(State * end_state);
void send_plan_actions(int fd, PlanAction **plan_actions);
void ff_send_plan_actions(int fd);
void ff_recv_plan_actions(int fd);
void mff_send_plan_actions(int fd);
void mff_recv_plan_actions(int fd);
void mff_send_time(int fd, float x);
void mff_recv_time(int fd);
void send_sol_state(int fd);
void recv_sol_state(int fd);
void dis_send_sol_state(int fd);
void dis_recv_sol_state(int fd);
void recv_plan_actions(int fd, PlanAction **plan_actions);
void FF_record_esp_sol();
void mff_record_esp_sol();
void printv(int *v, int s, char *str);
Bool contain_fact_state(State *state, int f);


void free_noop_not_in (inform * act);

void remove_false_fact (register inform_list inf_address);
void remove_treated_noop (register inform_list inf_address); 

void insert_unsup_fact (register inform_list inf_address);

int insert_remove_action (int act_pos, int act_level, int ins_rem, int propagation);
void insert_treated_fact (register inform_list act_address, int noop_pos);

//void choose_random_act_cost ();

int backward_precond_propagation (inform * fact);
int backward_precond_remotion (inform * fact, int propagation);
void reset_plan (int);

int initialize (State * start_state, State * end_state, int num_run);

void set_numeric_flag ();

void create_descnumeff_of_efconns (void);

void make_false_all_checks_on_not_init (void);

int choose_num_actions (constraints_list unsup_numeric_fact, int initialize);
int choose_min_cost_unsup_num_fact ();

void eval_comp_var_non_recursive (int cv_index, float *in_vect, float *out_vect, int in_level, int out_level);

void refresh_cvars (int level);
void propagate_cvars (int level_from, int level_to);

void copy_num_values_from_level_to_level (int level_from, int level_to, Bool check_variations);
void insert_values_unsup_num_fact (int status, int fact, int level);

IntList *free_intlist (IntList * ilist);

float try_num_eff_in_level (int cv_index, float *in_vect, float *out_vect);

Bool is_num_prec_satisfied_in_common_level (int cvar);
Bool is_num_prec_satisfied (int cvar, int level);

void apply_numeric_effect_in_common_level (int num_eff);
void apply_numeric_effects_of_action (int act_pos, int level);

void insert_unsup_numeric_fact (int cv_index, int level);

//int fix_unsup_num_fact (constraints_list unsup_numeric_fact);

void clean_unsup_num_fact ();

void remove_unsup_num_fact (int position);
void remove_numeric_effects_of_action (int act_pos, int level);

void remove_unappliable_actions ();

void sub_affects_list (int cv_index, int *bitarray);



#endif
