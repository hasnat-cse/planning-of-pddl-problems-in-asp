#!/bin/bash

if [[ $# -ne 2 ]]
then
	echo "usage: ./incremental_solver.sh domain_file problem_file"
	exit 1
fi


start=`date +%s%N`



i=1
while true
do

echo
echo
echo
echo "solving domain $1 problem $2 with steps $i"
echo


output=$(./clingo  $1  $2  -c steps=$i)

echo "$output"

if [[ $output = *SATISFIABLE* ]] && [[ $output != *UNSATISFIABLE* ]]
then
	break  
fi


i=`expr $i + 1`

done



end=`date +%s%N`

runtime=$((end - start))

echo
echo "Total plan steps: $i" 
echo "Total time taken: `echo "scale=3; $runtime/1000000000" | bc`s"
