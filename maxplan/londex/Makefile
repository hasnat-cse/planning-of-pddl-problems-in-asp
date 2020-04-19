# Copyright (C) 2004, Board of Trustees of the University of Illinois.
#
# The program is copyrighted by the University of Illinois, and should
# not be distributed without prior approval.  Commercialization of this 
# product requires prior licensing from the University of Illinois.
# Commercialization includes the integration of this code in part or 
# whole into a product for resale. 
#
#-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
# Author: Y. X. Chen, C. W. Hsu, and B. W. Wah, University of Illinois
#-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#################################
# Modified from Makefile of LPG #
#################################


####### FLAGS

TARGET = londex
CFLAGS = -g -Wall
#CFLAGS	= -O3 -DNDEBUG -Wall
LIBS	= -lm -lnsl -lsocket
LIBS	= -lm

####### COMPILE

CC	= gcc 

PATH_HEADERS	= include


SOURCES = main.c \

OBJECTS = $(SOURCES:.c=.o) 

LPG_LIBS = Utilities/Utilities.a  Metric-FF/mff.a
#LPG_LIBS = Utilities/Utilities.a Parser/Parser.a Metric-FF/mff.a

SUB_DIRS =  Utilities   Metric-FF

find_header = $(wildcard $(dir)/*.h)

HEADERS := $(foreach dir,./include,$(find_header))

####### Implicit rules

.SUFFIXES:

.SUFFIXES: .c .o

.c.o:; $(CC) -I$(PATH_HEADERS) -c $(CFLAGS) $<


####### Build rules
londex:	islpg $(OBJECTS) COMPILE_SUB
	$(CC) -o $(TARGET) $(OBJECTS) $(LPG_LIBS) $(CFLAGS) $(LIBS) ##-static

islpg:	
#	rm -f LocalSearch/LocalSearch.a
#	rm -f Utilities/Utilities.a

COMPILE_SUB:
	@ for i in $(SUB_DIRS); do $(MAKE) -C $$i CFLAGS='$(CFLAGS)'; done

$(OBJECTS): $(HEADERS)

clean:
	@ for i in $(SUB_DIRS); do $(MAKE) -C $$i clean; done
	-rm -f *.o *~ londex* $(PATH_HEADERS)/*~ 

distclean:
	@ for i in $(SUB_DIRS); do $(MAKE) -C $$i clean; done
	-rm -f *.o *~ londex* $(PATH_HEADERS)/*~
#######
