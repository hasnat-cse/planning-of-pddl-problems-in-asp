




#ifndef _UTILITIES_H
#define _UTILITIES_H

Bool process_command_line( int argc, char *argv[] );

double get_global_time();

float getVmRSS();

int check_timeout();
void check_memory_usage();

int** malloc2DimenArray(int size);
void  dispose2DimenArray(int **ptr, int size);

typedef struct _CalculaGraph{
	double total;
	double start_time;
} CalculaGraph;

#endif /* _OUTPUT_H */
