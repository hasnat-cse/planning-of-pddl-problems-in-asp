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
 * File: utilities.c
 * Description: utilities.
 *
 *   PDDL 2.1 version without conditional and quantified effects 
 *
 * Authors: Alfonso Gerevini, Marco Lazzaroni, Alessandro Saetti, 
 *          Ivan Serina, Sergio Spinoni
 *
 *********************************************************************/





#include <sys/signal.h>
#include <math.h>
#include <values.h>
#include "lpg.h"
#include "utilities.h"
#include "output.h"
#include "DistributeSearch.h"
#include "time.h"


void
get_total_time_plan ()
{

}







float
weight_cost (node_cost_list n_cost)
{

  if (GpG.weight_cost < GpG.weight_time)
    return n_cost->act_time;
  else
    return n_cost->act_cost;

}











float
get_action_cost (int pos)
{
  float tot = 0.0;


  if (pos < 0)
    return 0.0;

  if (GpG.optimize == OPT_ACT_COST)
    tot = gef_conn[pos].cost;
  else if (GpG.optimize == OPT_PLAN_SIMILARITY)
    tot = POSITIVE (gef_conn[pos].cost);
  else
    tot = 1.0;

  return (tot);
}



float
get_action_time (int pos, int level)
{
  float tot;
/*

  if (pos < 0)
    return 0.0;

  if (!GpG.durative_actions_in_domain)
    return STRIPS_ACTIONS_DURATION;


  if (GpG.variable_duration && level >= 0)


    if (vectlevel[level] != NULL && gef_conn[pos].duration_rvals != NULL)
      {

	eval_comp_var_non_recursive (gef_conn[pos].dur_var_index,
				     vectlevel[level]->numeric->values,
				     vectlevel[level]->numeric->values, level,
				     level);
	gef_conn[pos].duration =
	  vectlevel[level]->numeric->values[gef_conn[pos].dur_var_index];

	gef_conn[pos].duration = ROUND_TO_1_1000 (gef_conn[pos].duration);

      }

  if (GpG.optimize == OPT_ACT_COST)
    tot = gef_conn[pos].duration;
  else if (GpG.optimize == OPT_PLAN_SIMILARITY)
    tot = POSITIVE (gef_conn[pos].duration);
  else
    tot = 1.0;
*/
  return (tot);

}











int
get_index_of_constant (char *arg)
{
  int i;

  for (i = 0; i < gnum_constants; i++)
    {
      if (strcmp (gconstants[i], arg) == SAME)
	return i;
    }
  printf
    ("\n\nget_index_of_constant: constant name %s not found in params\n\n",
     arg);
  exit (1);
  return -1;
}


FILE *
open_plan_file (char *file_name)
{
  FILE *fp;

  fp = fopen (file_name, "r");

  if (fp == NULL)
    {
      printf ("\nGPG: can't find plan file %s ! \n\n", file_name);
      exit (2);
    }

  return (fp);
}



float
extract_level (char *cStr)
{
  int n;
  float m;
  char push;
  n = strlen (cStr) - 1;
  push = cStr[n];
  cStr[n] = '\n';
  m = atof (cStr);
  cStr[n] = push;
  return (m);
}

int
get_action_index (char *opname, int *index_of_arg)
{
  int i, j;




  for (i = 0; i < gnum_ef_conn; i++)
    {

      if (strcmp (opname, gop_conn[gef_conn[i].op].action->name) != SAME)
	continue;

      for (j = 0; j < gop_conn[gef_conn[i].op].action->num_name_vars; j++)

	if (index_of_arg[j] !=
	    gop_conn[gef_conn[i].op].action->name_inst_table[j])
	  break;

      if (j == gop_conn[gef_conn[i].op].action->num_name_vars)
	return i;
    }



  return -1;
}











PlanAction *
new_PlanAction (int act_pos, float start_time, float duration)
{
  PlanAction *pa = (PlanAction *) calloc (1, sizeof (PlanAction));
  pa->act_pos = act_pos;
  pa->start_time = start_time;
  pa->duration = duration;
  pa->cost = get_action_cost (act_pos);
  pa->previous = NULL;
  pa->next = NULL;
  return pa;
}



void
insert_plact_after (PlanAction * plAct, PlanAction * pla_before)
{


  if (!pla_before)
    return;


  plAct->next = pla_before->next;
  plAct->previous = pla_before;

  pla_before->next = plAct;
  if (plAct->next)
    plAct->next->previous = plAct;


}


void
store_action_vect (PlanAction ** plan_actions, int act_pos, float start_time,
		   float duration)
{
  PlanAction *plAct, *pl;

  plAct = new_PlanAction (act_pos, ROUND_TO_1_1000(start_time), duration);


  if (*plan_actions == NULL)
    {
      *plan_actions = plAct;
      return;
    }

  for (pl = *plan_actions; pl; pl = pl->next)
    if (pl->next)
      {
	if ((plAct->start_time >= pl->start_time)
	    && (plAct->start_time < pl->next->start_time))
	  {
	    insert_plact_after (plAct, pl);
	    return;
	  }
	if (!pl->next)
	  {
	    insert_plact_after (plAct, pl);
	    return;
	  }
      }
    else
      {

	if (plAct->start_time < pl->start_time)
	  {
	    plAct->next = *plan_actions;
	    (*plan_actions)->previous = plAct;
	    *plan_actions = plAct;
	    return;
	  }
	if (!pl->next)
	  {
	    insert_plact_after (plAct, pl);
	    return;
	  }
      }

}




void
free_gplan_actions (PlanAction * gplan_actions)
{
  PlanAction *ptr, *prev_ptr;
  for (prev_ptr = ptr = gplan_actions; ptr;)
    {
      prev_ptr = ptr;
      ptr = ptr->next;
      free (prev_ptr);

    }

}




void
initialize_preset_values (void)
{

  GpG.static_noise = TRUE;
  GpG.count_escl = TRUE;
  GpG.numerator = GpG.init_numerator = 10;
  GpG.denominator = 100;
  GpG.numrun = 50;
  GpG.numtry = 500;
  GpG.assign = 0;
  GpG.choose_1_2_level = 0;
  GpG.best_min_inc = 10;
  GpG.min_inc = 10;
  GpG.prec_par = 1.0;
  GpG.excl_par = 1.0;
  GpG.add_effect_par = 0.0;
  GpG.add_effect_goal = 0.0;

  GpG.used_prec_par = 0.0;
  GpG.used_excl_par = 0.0;
  GpG.used_add_effect_par = 1.0;
  GpG.used_add_effect_goal = 1.0;
  GpG.num_act_cons = 100;
  GpG.weight_fact = 1.0;
  GpG.init_tabu_length = 0;
  GpG.local = 0;
  GpG.fast_greedy = 1;
  GpG.delta = 0.1;
  GpG.partial_timeout = MAXINT;
  GpG.timeout = MAXINT;

  GpG.search_type = DIS_SEARCH;
  GpG.initialize = INIT_EMPTY_PLAN;
  GpG.levels = FALSE;
  GpG.double_move = FALSE;
  GpG.num_false_act = 0;
  GpG.num_false_fa = 0;
  GpG.num_false_tot = 0;
  GpG.noopmode = 0;

  GpG.accurate_cost = COMPUTE_DG_LIST_COST;
  GpG.optimize = OPT_ACT_COST;
  GpG.cost = 1.0;
  GpG.best_cost = 100000.0;

  GpG.orig_weight_cost = 0.5;
  GpG.orig_weight_time = 0.0;
  GpG.inc_run = 1.1;
  GpG.increase_type = 0;
  GpG.down_vectlevel = FALSE;
  GpG.max_num_solutions = 0;
  GpG.incr_mutex = TRUE;
  GpG.consider_current_level = TRUE;
  GpG.approximation_level = 1;
  GpG.temporal_plan = FALSE;
  GpG.do_best_first = TRUE;
  GpG.forward_time = 1;

  GpG.inc_choice_type = MIN_LEVEL_INC;
  GpG.durative_actions_in_domain = FALSE;
  GpG.variable_duration = FALSE;
  GpG.non_strips_domain = FALSE;
  GpG.temp_plan_actions = (PlanAction *) calloc (1, sizeof (PlanAction));
  GpG.inst_duplicate_param = FALSE;
  GpG.advanced_temporal_setting = 0;
  GpG.verbose = TRUE;
  GpG.info_search = 0;
  GpG.noout = FALSE;
  GpG.out_file_name = FALSE;
  GpG.lowmemory = FALSE;
  GpG.max_cputime = -1.0;
  GpG.constraint_type = TRUE;
  GpG.max_temp_vect = 0;
  GpG.total_time_goal = FALSE;
  GpG.verify_init = 0;
  GpG.verify_Af = 0;
  GpG.verify_inc_choice = 0;
  GpG.cri_evaluate_preconditions = COMPUTE_DG_LIST_COST;
  GpG.H_positive_benefits = TRUE;
  GpG.relaxed_examination_type = 0;
  GpG.relax_list_fact_cost = FALSE;
  GpG.evaluation_function = 1;
  GpG.lagrange_multipl = FALSE;
  GpG.sqr_s_s = 0.0000005;
  GpG.sqr_s_s_me = GpG.sqr_s_s;
  GpG.s_s_step = 0.001;
  GpG.s_s_step_me = GpG.s_s_step;
  GpG.lm_multilevel = 0;
  GpG.flag_decr_lm_goal = 0;
  GpG.goal_lambda = 1.0;

  GpG.esp_search = 0;
  
  Hvar.dg_inform_array = NULL;
  Hvar.dg_delete_array = NULL;
  Hvar.a_start_level = -1;
    
  GpG.MFF_parser = FALSE;
  GpG.is_deripred = FALSE;

  GpG.glob_dist_time = 0.0;
}




int
set_param (int num_unsat)
{
   static int position = 0;
   float mean,  var,  diff;
   int i, min,  max;
   static int unsat_vector[UNS_VECT];

   if (GpG.static_noise==TRUE)
     return TRUE;

   if (position < (UNS_VECT-1) )
     {
       unsat_vector[position++] = num_unsat;
       return TRUE;
     }
   
   else
    {
      if (GpG.optimize && GpG.orig_local_search != GpG.local)
	GpG.local = GpG.orig_local_search;
      unsat_vector[position] = num_unsat;
      position = 0;
      mean = min = max = unsat_vector[0];
      for (i = 1; i < UNS_VECT; i++)
	mean += unsat_vector[i];
      mean /= (UNS_VECT);
  
      var = 0.0;
      for (i = 0; i < UNS_VECT; i++)
	{
	  if (unsat_vector[i] < min)
	      min = unsat_vector[i];
	  if (unsat_vector[i] > max)
	    max = unsat_vector[i];	    
	  diff = unsat_vector[i] - mean;
	  var += pow (diff, 2.0);
	}
      var /= (UNS_VECT-1);
      if (DEBUG1 && FALSE)
	{
	  printf ("\nMean %3.3f, var %4.3f, min %d , max %d ", mean, var,
		  min, max);
	  printf (" N %d, L %d \n\n", GpG.numerator, GpG.tabu_length);
	}
      if (var > 1.0)
	{
	  GpG.numerator = GpG.init_numerator;
	  GpG.tabu_length = GpG.init_tabu_length;
	}       
      else
	{
	  if(GpG.numerator<40)
	    {
	      GpG.numerator *= 1.5;
	      GpG.tabu_length *= 1.5;
	    }
	 }
        

    }
   return TRUE;
}















void
reset_bitarray (register int *vector, register int dim)
{
  register int i;
  for (i = 0; i < dim; i++)
    *(vector + i) = 0;
}



inline int
count_bit1 (register int mask)
{
  register int num;
  if (mask)
    {
      num = 0;
      if (mask & FIRST_1)
	{
	  num++;
	  mask &= 0x07fffffff;
	}
      while (mask)
	{
	  while (!(mask & 0x1))
	    mask >>= 1;
	  num++;
	  mask >>= 1;
	}
    }

  else
    return (0);
  return (num);
}





void
reset_neighborhood ()
{

  num_neighborhood = 0;

}


void
insert_element_in_neighb (neighb_list n_elem)
{

    
  if (neighb_vect[num_neighborhood] == NULL)
    neighb_vect[num_neighborhood] = (neighb_list) malloc (sizeof (neighb));
  memcpy (neighb_vect[num_neighborhood], n_elem, sizeof (neighb));

  num_neighborhood++;

  if (num_neighborhood >= MAX_MAX_NODES)
    {
        printf("\ngooottta yaa\n");
      exit (1);
    }


}










/*
int
check_mutex_action (register int act_position, int level)
{
  int act_pos = GET_ACTION_POSITION_OF_LEVEL (level);

  if (!GpG.lowmemory)
    {
      if (CHECK_ACTION_OF_LEVEL (level)
	  && (CONVERT_ACTION_TO_VERTEX (act_position)->
	      ef_exclusive_vect[GUID_BLOCK (act_pos)] & GUID_MASK (act_pos)))
	return (act_pos);
      else
	return (-1);
    }

  else
    {

      if (CHECK_ACTION_OF_LEVEL (level)
	  && are_mutex_ops (act_pos, act_position))
	return (act_pos);
      else
	return (-1);

    }

}

*/


int
check_mutex_noop (register int position, int level)
{
  int act_pos = GET_ACTION_POSITION_OF_LEVEL (level);

  if (position < 0)
    {
      printf ("\ncheck_mutex_noop_1");
      exit (0);
    }

  if (CHECK_ACTION_OF_LEVEL (level)
      && (CONVERT_NOOP_TO_VERTEX (position)->
	  ef_exclusive_vect[GUID_BLOCK (act_pos)] & GUID_MASK (act_pos)))
    return (act_pos);

  else
    return (-1);
}


int
check_mutex_noop_durative (register int position, int level)
{
  int act_pos = GET_ACTION_POSITION_OF_LEVEL (level);

  if (position < 0)
    {
      printf ("\ncheck_mutex_noop_durative_1");
      exit (0);
    }

  if (CHECK_ACTION_OF_LEVEL (level)
      && (CONVERT_NOOP_TO_VERTEX (position)->
	  ef_exclusive_vect[GUID_BLOCK (act_pos)] & GUID_MASK (act_pos))
      && vectlevel[level]->noop_act[position].w_is_overall != ADD_DEL
      && vectlevel[level]->noop_act[position].w_is_overall != NADD_DEL)
    return (act_pos);

  else
    return (-1);
}








int
is_fact_in_additive_effects (int act_pos, int fact_pos)
{
  register int i;


  if (act_pos < 0)
    return 0;

  for (i = 0; i < gef_conn[act_pos].num_A; i++)
    if (gef_conn[act_pos].A[i] == fact_pos)
      {
	return TRUE;
      }

  return 0;

}


int
is_fact_in_delete_effects (int act_pos, int fact_pos)
{
  register int i;


  if (act_pos < 0)
    return 0;

  for (i = 0; i < gef_conn[act_pos].num_D; i++)
    if (gef_conn[act_pos].D[i] == fact_pos)
      {

	return TRUE;
      }

  return 0;

}


int
is_fact_in_additive_effects_start (int act_pos, int fact_pos)
{

  register int i;


  if (act_pos < 0)
    return 0;

  if (gef_conn[act_pos].sf == NULL)
    return 0;

  for (i = 0; i < gef_conn[act_pos].sf->num_A_start; i++)
    if (gef_conn[act_pos].sf->A_start[i] == fact_pos)
      {
	return (TRUE);
      }

  return 0;

}



int
is_fact_in_delete_effects_start (int act_pos, int fact_pos)
{

  register int i;


  if (act_pos < 0)
    return 0;

  if (gef_conn[act_pos].sf == NULL)
    return 0;

  for (i = 0; i < gef_conn[act_pos].sf->num_D_start; i++)
    if (gef_conn[act_pos].sf->D_start[i] == fact_pos)
      {
	return (TRUE);
      }

  return 0;

}


int
is_fact_in_preconditions (int act_pos, int fact_pos)
{

  register int i;


  if (act_pos < 0)
    return 0;

  for (i = 0; i < gef_conn[act_pos].num_PC; i++)
    if (gef_conn[act_pos].PC[i] == fact_pos)
      {

	return TRUE;
      }


  return 0;

}



int
is_fact_in_preconditions_overall (int act_pos, int fact_pos)
{


  register int i;

  if (act_pos < 0)
    return 0;

  if (gef_conn[act_pos].sf == NULL)
    return 0;

  for (i = 0; i < gef_conn[act_pos].sf->num_PC_overall; i++)
    if (gef_conn[act_pos].sf->PC_overall[i] == fact_pos)
      {
	return (TRUE);
      }

  return 0;

}


int
is_fact_in_preconditions_end (int act_pos, int fact_pos)
{


  register int i;

  if (act_pos < 0)
    return 0;

  if (gef_conn[act_pos].sf == NULL)
    return 0;

  for (i = 0; i < gef_conn[act_pos].sf->num_PC_end; i++)
    if (gef_conn[act_pos].sf->PC_end[i] == fact_pos)
      {
	return (TRUE);
      }

  return 0;

}















int
fact_is_supported (int Fact_position, int Fact_level)
{

  if (Fact_position < 0)
    return (is_num_prec_satisfied (Fact_position, Fact_level));

  if ((vectlevel[Fact_level]->
       fact_vect[GUID_BLOCK (Fact_position)]) & GUID_MASK (Fact_position))
    return TRUE;
  else
    return FALSE;

}






float
DeltaTime (struct tms start, struct tms end)
{
  return ((float) ((end.tms_utime - start.tms_utime + end.tms_stime -
		    start.tms_stime) / 100.0));
}


void
get_path (char *full_file_name, char *result)
{

  int last_slash = -1, i;
  for (i = 0; i < strlen (full_file_name); i++)
    if (full_file_name[i] == '/')
      last_slash = i;

  if (last_slash == -1)
    strcpy (result, "./");

  else
    {
      strcpy (result, full_file_name);
      result[last_slash + 1] = '\0';
    }
}


void
output_planner_info (void)
{

  printf
    ("\n\ntime spent: %7.2f seconds instantiating %d easy, %d hard action templates",
     gtempl_time, gnum_easy_templates, gnum_hard_mixed_operators);
  printf
    ("\n            %7.2f seconds reachability analysis, yielding %d facts and %d actions",
     greach_time, gnum_pp_facts, gnum_actions);
  printf
    ("\n            %7.2f seconds creating final representation with %d relevant facts",
     grelev_time, gnum_relevant_facts);
  printf ("\n            %7.2f seconds building connectivity graph",
	  gconn_time);

  printf
    ("\n            %7.2f seconds creating %d primary vars and %d numeric relations",
     gnum_time, gnum_fullnum_initial, gnum_comp_var);
  printf
    ("\n            %7.2f seconds creating %d mutex relations, in %d levels",
     gmutex_total_time, gnum_mutex, gmutex_level);
  printf ("\n            %12.2f seconds for mutex between facts",
	  gmutex_ft_time);
  printf ("\n            %12.2f seconds for other logical mutex",
	  gmutex_ops_time);
  printf ("\n            %12.2f seconds for mutex from numeric effects",
	  gmutex_num_time);


  printf
    ("\n            %7.2f seconds searching, evaluating %d states, to a max depth of %d",
     gsearch_time, gevaluated_states, gmax_search_depth);
  printf ("\n            %7.2f seconds total time",
	  gtempl_time + greach_time + grelev_time + gconn_time +
	  gsearch_time + gnum_time + gmutex_total_time);

  printf ("\n\n");
}



void
lpg_usage (void)
{

  printf ("\n%s settings:\n", VERSION);

 // printf ("\nNecessary Settings\n\n");


  printf
    ("-o <string>              specifies the file of the operators \n\n");


  printf
    ("-f <string>              specifies the file of (init/goal) facts\n\n");

  printf
    ("-out <string>            specifies the file name for computed plans\n\n");

  printf ("\n ");

}




Bool
process_command_line (int argc, char *argv[])
{

  char *temp = "on";
  int i, heuristic;
  float noise;

  gcmd_line.display_info = 1;
  gcmd_line.debug = 0;

  gcmd_line.max_plan_ops = 0;
  gcmd_line.max_cpu_time = 0;
  gcmd_line.verbose_invar = 0;
  memset (gcmd_line.out_file_name, 0, MAX_LENGTH * sizeof (char));

  memset (gcmd_line.fct_file_name, 0, MAX_LENGTH * sizeof (char));
  memset (gcmd_line.path, 0, MAX_LENGTH * sizeof (char));

  for (i = 1; i < argc; i++)
    {
      if (argv[i][0] != '-')
	continue;
      if (strcmp (argv[i], "-p") == 0)
	strncpy (gcmd_line.path, argv[++i], MAX_LENGTH);

      else if (strcmp (argv[i], "-o") == 0)
	strncpy (gcmd_line.ops_file_name, argv[++i], MAX_LENGTH);
	  
	  else if( strcmp (argv[i], "-verboseinvar") == 0)
	gcmd_line.verbose_invar = 1;
      else if (strcmp (argv[i], "-f") == 0)
	strncpy (gcmd_line.fct_file_name, argv[++i], MAX_LENGTH);

      else if (strcmp (argv[i], "-P") == 0)
	strncpy (gcmd_line.sol_file_name, argv[++i], MAX_LENGTH);

      else if (strcmp (argv[i], "-info") == 0)
	sscanf (argv[++i], "%d", &gcmd_line.display_info);

      else if (strcmp (argv[i], "-d") == 0)
	sscanf (argv[++i], "%d", &gcmd_line.debug);

      else if (strcmp (argv[i], "-L") == 0)
	sscanf (argv[++i], "%d", &gcmd_line.max_plan_ops);

      else if (strcmp (argv[i], "-T") == 0)
	sscanf (argv[++i], "%f", &gcmd_line.max_cpu_time);

      else if (strcmp (argv[i], "-out") == 0)
	{
	  strncpy (gcmd_line.out_file_name, argv[++i], MAX_LENGTH);
	  GpG.out_file_name = TRUE;
	}

      else if (strcmp (argv[i], "-temporal") == 0)
	sscanf (argv[++i], "%c", &GpG.temporal_plan);

      else if (strcmp (argv[i], "-AdvancedTime") == 0)
	GpG.constraint_type = 2;

      else if (strcmp (argv[i], "-wcost") == 0)
	sscanf (argv[++i], "%f", &GpG.orig_weight_cost);

      else if (strcmp (argv[i], "-wtime") == 0)
	sscanf (argv[++i], "%f", &GpG.orig_weight_time);

      else if (strcmp (argv[i], "-heuristic") == 0)
	sscanf (argv[++i], "%d", &GpG.accurate_cost);

      else if (strcmp (argv[i], "-num_sol") == 0
	       || strcmp (argv[i], "-n") == 0)
	sscanf (argv[++i], "%d", &GpG.max_num_solutions);

      else if (strcmp (argv[i], "-lowmemory") == 0)
	GpG.lowmemory = TRUE;

      else if (strcmp (argv[i], "-total_time_goal") == 0)
	GpG.total_time_goal = TRUE;

      else if (strcmp (argv[i], "-incchoice") == 0
	       || strcmp (argv[i], "-ichoice") == 0
	       || strcmp (argv[i], "-i_choice") == 0)
	{
	  sscanf (argv[++i], "%d", &GpG.inc_choice_command_line);
	  GpG.inc_choice_type = GpG.inc_choice_command_line;
	}

      else if (strcmp (argv[i], "-seed") == 0)
	sscanf (argv[++i], "%d", &seed);

      else if (strcmp (argv[i], "-numtry") == 0
	       || strcmp (argv[i], "-num_flips") == 0
	       || strcmp (argv[i], "-search_steps") == 0)
	sscanf (argv[++i], "%d", &GpG.numtry);

      else if (strcmp (argv[i], "-numrun") == 0
	       || strcmp (argv[i], "-restarts") == 0
	       || strcmp (argv[i], "-num_tries") == 0)
	sscanf (argv[++i], "%d", &GpG.numrun);

      else if (strcmp (argv[i], "-info_search") == 0)
	{
	  sscanf (argv[++i], "%d", &GpG.info_search);
	  if (GpG.info_search > 5)
	    GpG.info_search = 5;
	}
      else if (strcmp (argv[i], "-bestfirst") == 0)
	GpG.do_best_first = TRUE;

      else if (strcmp (argv[i], "-local") == 0)
	GpG.search_type = LOCAL;
                            
      else if (strcmp (argv[i], "-nobestfirst") == 0)
	GpG.do_best_first = FALSE;
      						
      else if (strcmp (argv[i], "-esp") == 0)
	GpG.esp_search = 1;
      
      else if (strcmp (argv[i], "-hillesp") == 0)
	GpG.esp_search = 2;

      else if (strcmp (argv[i], "-stoesp") == 0)
	GpG.esp_search = 3;

      else if (strcmp (argv[i], "-mipsesp") == 0)
    GpG.esp_search = 4;
            
      else if (strcmp (argv[i], "-h") == 0)
	{
	  if (argv[i + 1] != NULL)
	    {
	      sscanf (argv[++i], "%d", &heuristic);
	      if (heuristic == COMPUTE_MAX_COST)
		GpG.accurate_cost = COMPUTE_MAX_COST;
	      else if (heuristic == COMPUTE_FAST_COST)
		GpG.accurate_cost = COMPUTE_FAST_COST;
	    }
	}

      else if (strcmp (argv[i], "-adaptfirst") == 0)
	GpG.do_adapt_first = TRUE;

      else if (strcmp (argv[i], "-noout") == 0)
	GpG.noout = TRUE;

      else if (strcmp (argv[i], "-fastadapt") == 0)
	GpG.do_fast_adapt = TRUE;

      else if (strcmp (argv[i], "-onlybestfirst") == 0)
	{
	  GpG.do_best_first = TRUE;
	  GpG.numrun = 0;
	}
      else if (strcmp (argv[i], "-onlyhill") == 0)
	{
	  GpG.do_hill_climb = TRUE;
	  GpG.numrun = 0;
	}               

      else if (strcmp (argv[i], "-inst_duplicate_param") == 0
	       || strcmp (argv[i], "-same_objects") == 0)
	GpG.inst_duplicate_param = TRUE;

      else if (strcmp (argv[i], "-maximize") == 0)
	GpG.maximize_plan = TRUE;

      else if (strcmp (argv[i], "-validate") == 0)
	GpG.validate = TRUE;

      else if (strcmp (argv[i], "-noise") == 0)
	{
	  sscanf (argv[++i], "%f", &noise);
	  GpG.init_numerator = (int) (noise * 100);
	  GpG.numerator = GpG.init_numerator;
	}

      else if (strcmp (argv[i], "-dynamic_noise") == 0)
	GpG.static_noise = FALSE;

      else if (strcmp (argv[i], "-advanced_temporal_setting") == 0)
	sscanf (argv[++i], "%d", &GpG.advanced_temporal_setting);


      else if (strcmp (argv[i], "-lagrange") == 0)
	sscanf (argv[++i], "%d", &GpG.lagrange_multipl);

      else if (strcmp (argv[i], "-lm_multilevel") == 0)
	GpG.lm_multilevel = 1;

      else if (strcmp (argv[i], "-lm_incrprec") == 0)
	sscanf (argv[++i], "%f", &GpG.s_s_step);

      else if (strcmp (argv[i], "-lm_decrprec") == 0)
	sscanf (argv[++i], "%f", &GpG.sqr_s_s);

      else if (strcmp (argv[i], "-lm_incrme") == 0)
	sscanf (argv[++i], "%f", &GpG.s_s_step_me);

      else if (strcmp (argv[i], "-lm_decrme") == 0)
	sscanf (argv[++i], "%f", &GpG.sqr_s_s_me);



      else if (strcmp (argv[i], "-cputime") == 0)
	sscanf (argv[++i], "%f", &GpG.max_cputime);

      else if (strcmp (argv[i], "-v") == 0)
	{
	  sscanf (argv[++i], "%s", temp);
	  if (strcmp (temp, "off") == 0)
	    GpG.verbose = FALSE;
	}
      else if (strcmp (argv[i], "-l_rate+") == 0)
	sscanf (argv[++i], "%f", &GpG.s_s_step);
      else if (strcmp (argv[i], "-l_rate-") == 0)
	sscanf (argv[++i], "%f", &GpG.sqr_s_s);
      else if (strcmp (argv[i], "-verifyinit") == 0)
	GpG.verify_init = 1;
      else if (strcmp (argv[i], "-verifyAf") == 0)
	GpG.verify_Af = 1;
      else if (strcmp (argv[i], "-verifyincchoice") == 0)
	GpG.verify_inc_choice = 0;
      else if (strcmp (argv[i], "-criprecond") == 0)
	sscanf (argv[++i], "%d", &GpG.cri_evaluate_preconditions);
      else if (strcmp (argv[i], "-relaxed_examination") == 0)
	GpG.relaxed_examination_type = 1;
      else if (strcmp (argv[i], "-evaluation_function") == 0)
	sscanf (argv[++i], "%d", &GpG.evaluation_function);
      else if (strcmp (argv[i], "-ri_list") == 0)
	GpG.relax_list_fact_cost = 1;
      else
	{
	  printf ("\n Unknown option: %s entered\n\n", argv[i]);
	  return FALSE;
	}

    }

  if (GpG.max_num_solutions < 1)
    {
        GpG.max_num_solutions = 1;
  //    printf ("\n Please specify the parameter '-n'\n\n");
  //    return FALSE;
    }
  return TRUE;

}








void
so_signal_management ()
{
#ifdef _SIGNAL_H
  struct sigaction saio;
  saio.sa_handler = 1;
  saio.sa_flags = 0;
  saio.sa_restorer = NULL;
  sigaction (SIGSEGV, &saio, NULL);
#endif
}
