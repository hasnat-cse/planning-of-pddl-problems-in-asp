
#include "bb.h"
#include "cg_encoding.h" 
#include "utilities.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <unistd.h>

float getVmRSS(){
	int pid;
	char buffer[1024];
	FILE* fp;
	pid = getpid();
	sprintf( buffer, "/proc/%i/status", pid );
	
	fp = fopen( buffer, "r" );
	
	if(fp==NULL) printf("ERROR while reading VmRSS!!!!\n"),exit(0);
	
	char columnHead[50] = "VmRSS";
	while(fgets(buffer,1024,fp)!=NULL){
		if(strncmp(buffer,columnHead,strlen(columnHead))==0){
			int start=0,i,end=0;
			for(i=0;i<strlen(buffer);i++)
				if(isdigit(buffer[i])) {
					start = i;
					break;
				}
			
			do{
				if(!isdigit(buffer[i])){
					end = i;
					break;
				}
			}while(++i<strlen(buffer));
			
			char ns[50];
			for(i=0;i<end-start;i++) ns[i]= buffer[start+i];
			ns[i++] = '\0';
			int num = atoi(ns);
			fclose(fp);
			return (float)num/1024;
		}
	}
	
	//FAIL to find one.
	printf("Something is wrong with the VmRSS reading.!!!!!!!!!!!!!\n");
	return -1;	
}

void check_memory_usage(){
// If this program runs on cygwin, we don't want it to check memory; 
//Error may occur;
#ifndef OS_CYGWIN
	float current = getVmRSS();
	if( current - max_memory_usage > 0.001)
		max_memory_usage = current;
	printf( "Memory usage at this check point is %lf\n", current);	
#endif
}



double get_global_time(){
	
	struct rusage us;
	getrusage(RUSAGE_SELF, &us);
	double res = (double)us.ru_utime.tv_sec + (double)us.ru_utime.tv_usec/1000000;
	return res;
}

long get_global_time_int(){
	struct rusage us;
	getrusage(RUSAGE_SELF, &us);
	return us.ru_utime.tv_sec;	
}

int check_timeout(){
	//long current = (long)get_global_time();
	if( get_global_time_int() > gcmd_line.tlimit ){
		printf("Solver runs with time out.(%d seconds)\n Failed to find a solution.\n", gcmd_line.tlimit );
		exit(0);
	}
	return 0;
}


Bool process_command_line( int argc, char *argv[] )
{
	//Default Settings;
	gcmd_line.display_info = 1;
	gcmd_line.debug = 0;
	gcmd_line.min_time = 0;
  	gcmd_line.printEncoding = -1; 
  	gcmd_line.tlimit = 1800;
  	gcmd_line.londex_validation = 0;
  	gcmd_line.londexm = 0;
  	gcmd_line.londex_mode = 2;
  	gcmd_line.printLondex = 0;
  	gcmd_line.startLevel = 1;
  	
	memset(gcmd_line.ops_file_name, 0, MAX_LENGTH);
	memset(gcmd_line.fct_file_name, 0, MAX_LENGTH);
	memset(gcmd_line.path, 0, MAX_LENGTH);
  
	int i;
	for (i = 1; i < argc; i++){

		if ( argv[i][0] != '-' ) continue;
		else if( strcmp (argv[i], "-p") == 0 || strcmp (argv[i], "-path") == 0) 
			strncpy( gcmd_line.path, argv[++i], MAX_LENGTH );
		else if ( strcmp (argv[i], "-domain") == 0 || strcmp (argv[i], "-o") == 0 )
			strncpy( gcmd_line.ops_file_name, argv[++i], MAX_LENGTH );
		else if ( strcmp (argv[i], "-problem") == 0 || strcmp (argv[i], "-f") == 0 )
			strncpy( gcmd_line.fct_file_name, argv[++i], MAX_LENGTH );
		else if ( strcmp (argv[i], "-cgdomain") == 0 )
			strncpy( gcmd_line.cg_domain_file_name, argv[++i], MAX_LENGTH );
		else if ( strcmp (argv[i], "-cgproblem") == 0  )
			strncpy( gcmd_line.cg_problem_file_name, argv[++i], MAX_LENGTH );
		else if ( strcmp (argv[i], "-i") == 0 )
			sscanf( argv[++i], "%d", &gcmd_line.display_info );
		else if ( strcmp (argv[i], "-d") == 0 )
			sscanf( argv[++i], "%d", &gcmd_line.debug );				
		else if ( strcmp (argv[i], "-m") == 0 )
			sscanf( argv[++i], "%d", &gcmd_line.min_time );        
		else if ( strcmp (argv[i], "-l") == 0 )
			sscanf( argv[++i], "%d", &gcmd_line.cnflayer );
		else if ( strcmp (argv[i], "-C") == 0 )
			sscanf( argv[++i], "%d", &gcmd_line.cnfout );
		else if ( strcmp (argv[i], "-s") == 0 )			
			gcmd_line.solverOut = TRUE;
		else if ( strcmp (argv[i], "-t") == 0 )
			sscanf( argv[++i], "%d", &gcmd_line.binary_clause_only);
		else if ( strcmp (argv[i], "-P") == 0 )
			gcmd_line.prune = TRUE;
		else if ( strcmp (argv[i], "-b") == 0 )
			strncpy( gcmd_line.cnfFileName, argv[++i], MAX_LENGTH );
		else if ( strcmp (argv[i], "-G") == 0 )
			sscanf( argv[++i], "%d", &gcmd_line.makeCNF );
		else if ( strcmp (argv[i], "-S") == 0 )
			strncpy( gcmd_line.input_solution, argv[++i], MAX_LENGTH );
		else if ( strcmp (argv[i], "-F") == 0 )
			strncpy( gcmd_line.final_solution, argv[++i], MAX_LENGTH );
		else if ( strcmp (argv[i], "-V") == 0 )
			strncpy( gcmd_line.varFileName, argv[++i], MAX_LENGTH );
		else if ( strcmp (argv[i], "-mlimit") == 0 )
			sscanf( argv[++i], "%d", &gcmd_line.mlimit );
		else if ( strcmp (argv[i], "-tlimit") == 0 || strcmp (argv[i], "-timeout") == 0)
			sscanf( argv[++i], "%d", &gcmd_line.tlimit );
		else if ( strcmp (argv[i], "-tlimitLevel") == 0 )
			sscanf( argv[++i], "%d", &gcmd_line.level_tlimit );
		else if ( strcmp (argv[i], "-solution") == 0 )
			strncpy( gcmd_line.final_solution, argv[++i], MAX_LENGTH );
		else if ( strcmp (argv[i], "-printEncoding") == 0 )
			sscanf( argv[++i], "%d", &gcmd_line.printEncoding );
		else if ( strcmp (argv[i], "-londexMode") == 0 )
			sscanf( argv[++i], "%d", &gcmd_line.londex_mode );
		else if ( strcmp (argv[i], "-londexValidation") == 0 )
			gcmd_line.londex_validation = 1;
		else if ( strcmp (argv[i], "-londexm") == 0 || strcmp (argv[i], "-londex_m") == 0 )
			sscanf( argv[++i], "%d", &gcmd_line.londexm );
		else if ( strcmp (argv[i], "-startLevel") == 0 ||  strcmp (argv[i], "-levelFrom") == 0)
			sscanf( argv[++i], "%d", &gcmd_line.startLevel );
		else if ( strcmp (argv[i], "-printLondex") == 0 )
			gcmd_line.printLondex = 1;
	}
	
	if( gcmd_line.final_solution==NULL || strlen(gcmd_line.final_solution)==0 ){
		int i;
		char* filename = gcmd_line.fct_file_name;
		for(i=strlen(filename)-1;i>=0;i--)
			if( filename[i] == '/' ) break;
		i++;
		
		char absName[1000];
		strcpy(absName,filename+i);
		
		//char* dotPos = strchr(absName,'.');
		//if ( dotPos  )
		//	*dotPos = '\0';
		
		strcpy( gcmd_line.final_solution, absName);
		strcat( gcmd_line.final_solution, ".soln");
	}
	return TRUE;
}


int** malloc2DimenArray(int size){
	int **ptr = malloc( sizeof(*ptr) * size);
	int i;
	for(i=0;i<size;i++)
		ptr[i]= malloc(sizeof(int) * size);
	return ptr;
}

void dispose2DimenArray(int **ptr, int size){
	int i;
	for( i=0; i<size; i++ )
		free(ptr[i]);
	free(ptr);
}


