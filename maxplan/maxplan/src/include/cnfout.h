
/*********************************************************************
 * (C) Copyright 1999 Albert Ludwigs University Freiburg
 *     Institute of Computer Science
 *
 * All rights reserved. Use of this software is permitted for 
 * non-commercial research purposes, and it may be copied only 
 * for that use.  All copies must include this copyright message.
 * This software is made available AS IS, and neither the authors
 * nor the  Albert Ludwigs University Freiburg make any warranty
 * about the software or its performance. 
 *********************************************************************/





/*********************************************************************
 * File: cnfout.h
 * Description: headers for cnf output
 *
 * Author: Joerg Hoffmann 2003
 *
 *********************************************************************/ 

#ifndef _CNFOUT_H
#define _CNFOUT_H


#define MAX_CLAUSES 64000000
#define MAX_CNF_VARS 1500000


int do_cnf_output( int );


int code;

int **lcode;
int *lop_to_code;
int *ltime_to_code;

int **fcode;
int *fop_to_code;
int *ftime_to_code;

char *code_type;

int print_action_based_encoding( int layer, int toCreate );
int print_gpstyle_action_based_encoding( int layer, int toCreate );
int print_gp_based_encoding( int layer, int toCreate );
int print_thin_gp_based_encoding( int layer, int toCreate );


void init_solver();

int execute_solver();
void post_solving(int solverResult);

#endif /* _CNFOUT_H */
