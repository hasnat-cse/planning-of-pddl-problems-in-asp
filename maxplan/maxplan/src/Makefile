#!/bin/sh
#
#


####### FLAGS

TYPE	= 
ADDONS	= 

CC      = gcc
CFLAGS	= -O6 -Wall -std=c99 -static $(TYPE) $(ADDONS) 

LIBS    = -lm

CPP     = g++
CPPFLAGS = -ansi -Wall -pedantic -static

SRC_HEADER =./include
PATH_HEADERS = -I$(SRC_HEADER)

SUB_DIRS = 
####### Files

PDDL_PARSER_SRC	= scan-fct_pddl.tab.c \
	scan-ops_pddl.tab.c \
	scan-probname.tab.c \
	lex.fct_pddl.c \
	lex.ops_pddl.c 

PDDL_PARSER_OBJ = scan-fct_pddl.tab.o \
	scan-ops_pddl.tab.o 


SOURCES = main.c \
	memory.c \
	output.c \
	parse.c \
	instantiateI.c \
	instantiateII.c \
	graph.c \
	cnfout.c \
	cg_encoding.c \
	transition_graph.c \
	solver.c \
	utilities.c \
	
CPP_SOURCES = SatPlan.cpp \
	      StringAlgorithms.cpp \
				Input.cpp \


OBJECTS = $(SOURCES:.c=.o)

CPPOBJECTS = $(CPP_SOURCES:.cpp=.o)

####### Implicit rules

.SUFFIXES:

.SUFFIXES: .c .o

.SUFFIXES: .cpp .o

.c.o:; $(CC) $(PATH_HEADERS) -c $(CFLAGS) $<

.cpp.o:; $(CPP) $(PATH_HEADERS) -c $(CPPFLAGS) $<

####### Build rules

all: maxplan

#maxplan: $(CPPOBJECTS)
#	$(CPP) $(PATH_HEADERS) -o maxplan $(CPPOBJECTS)  $(CPPFLAGS)

maxplan: COMPILE_SUB $(OBJECTS) $(PDDL_PARSER_OBJ) 
	$(CC) $(PATH_HEADERS) -o maxplan $(OBJECTS)  $(PDDL_PARSER_OBJ) $(CFLAGS) $(LIBS)

# pddl syntax
scan-fct_pddl.tab.c: scan-fct_pddl.y lex.fct_pddl.c
#	bison -pfct_pddl -bscan-fct_pddl scan-fct_pddl.y

scan-ops_pddl.tab.c: scan-ops_pddl.y lex.ops_pddl.c
#	bison -pops_pddl -bscan-ops_pddl scan-ops_pddl.y

lex.fct_pddl.c: lex-fct_pddl.l
	flex -Pfct_pddl lex-fct_pddl.l

lex.ops_pddl.c: lex-ops_pddl.l
	flex -Pops_pddl lex-ops_pddl.l


####### CPP Dependencies
GENERALFILES = ./include/Assertion.h ./include/ByLine.h ./include/CommonErrors.h ./include/Conversion.h ./include/Exceptions.h \
               ./include/Input.h ./include/StandardFiles.h ./include/StringAlgorithms.h \
                ./include/Timer.h ./include/Typify.h

SOLVERFILES =  ./include/Factory.h ./include/SingletonType.h ./include/SolverInterface.h ./include/SolverTraits.h 


GeneralSolver.o: $(GENERALFILES) $(SOLVERFILES) ./include/GeneralSolver.h

Input.o: $(GENERALFILES) $(SOLVERFILES) ./include/PreferredSource.h

#MiniSatSolver.o: $(GENERALFILES) $(SOLVERFILES) ./include/MiniSatSolver.h

SatPlan.o: $(GENERALFILES) $(SOLVERFILES) ./include/CNFEncoding.h ./include/PreferredSource.h

SolverInterface.o: $(GENERALFILES) $(SOLVERFILES)

StringAlgorithms.o: ./include/StandardFiles.h ./include/StringAlgorithms.h



# misc
clean:
	rm -f maxplan *.exe bb *.o *.bak *~ *% core  \
        \#*\# $(RES_PARSER_SRC)
	@ for i in $(SUB_DIRS); do $(MAKE) -C $$i clean; done
	
##$(PDDL_PARSER_SRC)

veryclean: clean
	rm -f maxplan bb *.symbex gmon.out \
##$(PDDL_PARSER_SRC) \
	lex.fct_pddl.c lex.ops_pddl.c lex.probname.c \
	*.output DATA CNF

depend:
	makedepend -- $(SOURCES) $(CPP_SOURCES) $(PDDL_PARSER_SRC)


COMPILE_SUB:
	@ for i in $(SUB_DIRS); do $(MAKE) -C $$i CFLAGS='$(CFLAGS)'; done
	

lint:
	lclint -booltype Bool $(SOURCES) 2> output.lint

# DO NOT DELETE
