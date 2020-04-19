#!/bin/sh
#
#


####### FLAGS
all: executable

executable:
	cd ./src;make; cp maxplan ../
	
clean:
	rm maxplan
	cd src;make clean;
	
purge:
	rm *.soln
	
lint:
	lclint -booltype Bool $(SOURCES) 2> output.lint

# DO NOT DELETE
