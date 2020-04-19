
This release mostly based on SATPlan04's parser and encoding, 
but with additional pruning techinques.

1. To Run It

*It requires an additional executable `londex', for the purpose of generating 
SAS+ formulations (which may not be complete). If you found the executable in 
this directory not runnable, compile it by yourself in the directory 'londex'.

How to run:

	./maxplan -domain XXX1 -problem XXX2 -cgdomain YYY1 -cgproblem YYY2

The option '-cgdomain' and '-cgproblem' are for the external executable 
`londex's use. Note that the executable londex *will not* take grounded 
STRIPS domains, i.e., If a domain doesn't have an ADL definition, then 
make XXX1 equal to YYY1, and XXX2 equal to YYY2. Otherwise, if a domain
comes with two domain definitions, ADL and grounded-STRIPs, then use 
different definition accordingly.


eg:
	./maxplan -problem p03.pddl -cgproblem p03.pddl -domain domain_p03.pddl 
				-cgdomain domain.pddl -timeout 3600



eg:(TPP, which don't have an ADL definition)
	 ./maxplan 	-domain ~/domains/TPP/Propositional/domain.pddl 
	 			-problem ~/domains/TPP/Propositional/p01.pddl 
	 			-cgdomain ~/domains/TPP/Propositional/domain.pddl 
	 			-cgproblem ~/domains/TPP/Propositional/p01.pddl

eg:(Rover, which has ADL and grounded strips. 
	Use the ADL one for '-cgXX'; use grounded-strips for the normal options)
	 ./maxplan 	-domain ~/domains/Rovers/Propositional/Strips/domain_p01.pddl 
	 			-problem ~/domains/Rovers/Propositional/Strips/p01.pddl 
	 			-cgdomain ~/domains/Rovers/Propositional/domain.pddl 
	 			-cgproblem ~/domains/Rovers/Propositional/p01.pddl
	 			

 
There are also two scripts, "rover.sh" and "TPP.sh" in this directory. You
may need to change the PDDL files' direction accordingly to run it.



