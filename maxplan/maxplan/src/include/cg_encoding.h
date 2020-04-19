#ifndef CG_ENCODING_H
#define CG_ENCODING_H



#include "bb.h"

void calc_distance_fact(int *distance_array,  int fromIndex);

int position_in_mutex_table(int fact);
int position_in_fact_table( char *cg_fact );
int position_in_action_table( char *ff_action );

void insert_action_distance(struct DisAction* distance_list, int actionID, int value );
int coexist(int fact1, int fact2);


void scan_cg_file(void);
void process_ff_file(void);
int Is_M_Exclusion(int op1, int op2);
void insert_bit_vectors( void );


/**
 *    Structure of Domain Transition Graph
 */

typedef struct _TransitionEdge{
    int fromIndex,toIndex;   /* Redundent information; */
    int *action;
    int num_action;
} TransitionEdge;


typedef struct _TranstionGraph{
    int	id;
    char actor[100];
    int* element;
    int elementSize;
    int invariantId;
    
    int **londexValue;
    int **localDistance;
    int **connMatrix;
    int **disabledLondex;


    int hasGoal;

    TransitionEdge*** edge;
} TransitionGraph;

TransitionGraph *transGraph;
int transGraphNum;
int *dependencyMatrix;

#define MAX_DTG_NUM 500
#define MAX_DTG_SIZE  200
#define MAX_PATH_LEN  2000

int icmp(const void *p, const void *q);
void build_transition_graph(TransitionGraph *graph, int* element,int elementSize,int* connMatrix);
void print_out_transition_graph(TransitionGraph *graph, int print_option);
void londex_analysis();
void print_out_londex();

char ** a_a_mutex;
int ** f_f_mutex;

int Mux_BitVector_AND( BitVector *vec1, BitVector *vec2, int vec_len );
int Mux_BitVector( BitVector *vec, int vec_len );

int run_londex();
#endif // STANDARDFILES_H

