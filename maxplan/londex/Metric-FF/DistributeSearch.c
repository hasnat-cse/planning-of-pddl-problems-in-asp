
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
 * File: LocalSearch.c
 * Description: Local search method
 *
 *   PDDL 2.1 version without conditional and quantified effects 
 *
 * Authors: Alfonso Gerevini, Marco Lazzaroni, Alessandro Saetti, 
 *          Ivan Serina, Sergio Spinoni
 *
 *********************************************************************/


/***********************************************************************
 * File: DistributedSearch.c
 * Description: Changed from LocalSearch.c originally in LPG.
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


#include <math.h>

#include "DistributeSearch.h"
#include "dis_ff.h"
#include "dis_output.h"
#include "casual_graph.h"
#include "dis_memory.h"
#include "lpg.h"
#include "utilities.h"
#include "output.h" 
#include "dis_ff.h"
#include "inst_utils.h"






#define MAX_SUBPATHS 100
#define MAX_SUBPATH_LEN 20
#define MAX_LAG_SUB 112
#define MIN_LAG_SUB 45

extern int* decr_g;
extern void dis_make_state( dis_State *, int, int);




void
sub_affects_list (int cv_index, int *bitarray)
{
  IntList *il;
  RESET_BIT (bitarray, cv_index);
  for (il = gcomp_var[cv_index].affects; il; il = il->next)
    {
      if (GET_BIT (bitarray, il->item))
	{
	  RESET_BIT (bitarray, il->item);
	  sub_affects_list (il->item, bitarray);
	}
    }
}



Bool
is_num_prec_satisfied (int cvar, int level)
{
  if (cvar < 0)
    cvar = -cvar;

  return (abs (vectlevel[level]->numeric->values[cvar] - 1) < MAX_APPROX);
}









float
try_num_eff_in_level (int cv_index, float *in_vect, float *out_vect)
{
  CompositeNumVar *cv = &gcomp_var[cv_index];
  int first_op = cv->first_op;
  int second_op = cv->second_op;
  float tmp;

  assert (cv_index >= 0);
  first_op = gcomp_var[cv_index].first_op;
  second_op = gcomp_var[cv_index].second_op;

  switch (cv->operator)
    {
    case FIX_NUMBER:
    case VARIABLE_OP:
      out_vect[cv_index] = in_vect[cv_index];
      return out_vect[cv_index];
      break;
    case MUL_OP:
      out_vect[cv_index] =
	try_num_eff_in_level (first_op, in_vect,
			      out_vect) * try_num_eff_in_level (second_op,
								in_vect,
								out_vect);
      return out_vect[cv_index];
      break;
    case DIV_OP:
      tmp = try_num_eff_in_level (second_op, in_vect, out_vect);
      if (tmp == 0)
	{
	  printf ("\n\nWARNING: Division by zero in try_num_eff\n\n");
	  out_vect[cv_index] = 0;
	  return out_vect[cv_index];
	}
      out_vect[cv_index] =
	try_num_eff_in_level (first_op, in_vect, out_vect) / tmp;
      return out_vect[cv_index];
    case PLUS_OP:
      out_vect[cv_index] =
	try_num_eff_in_level (first_op, in_vect,
			      out_vect) + try_num_eff_in_level (second_op,
								in_vect,
								out_vect);
      return out_vect[cv_index];
      break;
    case MINUS_OP:
      out_vect[cv_index] =
	try_num_eff_in_level (first_op, in_vect,
			      out_vect) - try_num_eff_in_level (second_op,
								in_vect,
								out_vect);
      return out_vect[cv_index];
      break;
    case UMINUS_OP:
      out_vect[cv_index] =
	-try_num_eff_in_level (first_op, in_vect, out_vect);
      return out_vect[cv_index];
      break;
    case INCREASE_OP:
      out_vect[first_op] +=
	try_num_eff_in_level (second_op, in_vect, out_vect);
      return out_vect[first_op];
      break;
    case DECREASE_OP:
      out_vect[first_op] -=
	try_num_eff_in_level (second_op, in_vect, out_vect);
      return out_vect[first_op];
      break;
    case SCALE_UP_OP:
      out_vect[first_op] *=
	try_num_eff_in_level (second_op, in_vect, out_vect);
      return out_vect[first_op];
      break;
    case SCALE_DOWN_OP:
      out_vect[first_op] /= try_num_eff_in_level (second_op, in_vect,
						  out_vect);
      return out_vect[first_op];
      break;
    case ASSIGN_OP:
      out_vect[first_op] =
	try_num_eff_in_level (second_op, in_vect, out_vect);
      return out_vect[first_op];
      break;
    default:
      printf ("\n\nnot considered\n\n");
      exit (2);
      break;
    }

  return 0;
}







int* decr_g;
//int rsa_facts[MAX_FT_NUM];
//int rsa_actions[MAX_OP_NUM];







      
  











void mffDistributedSearch(char *ops_file, char *fct_file)
{

   dis_MFF_main(ops_file, fct_file); 


  return;
}
