



i=1
while [ $i -le 9 ]
do

rm ff_temp -f
rm CG_temp -f 

echo "solving Rover problem #$i"

./maxplan  -problem "/home/cic/rh11/domains/Rovers/Propositional/Strips/p0$i.pddl"  -cgproblem "/home/cic/rh11/domains/Rovers/Propositional/p0$i.pddl" -domain "/home/cic/rh11/domains/Rovers/Propositional/Strips/domain_p0$i.pddl" -cgdomain "/home/cic/rh11/domains/Rovers/Propositional/domain.pddl"  -timeout 3600 -londexMode 1  >rover_result$i




i=`expr $i + 1`
done



i=10
while [ $i -le 40 ]
do



rm ff_temp -f
rm CG_temp -f 

echo "solving Rover problem #$i"

./maxplan  -problem "/home/cic/rh11/domains/Rovers/Propositional/Strips/p$i.pddl"  -cgproblem "/home/cic/rh11/domains/Rovers/Propositional/p$i.pddl" -domain "/home/cic/rh11/domains/Rovers/Propositional/Strips/domain_p$i.pddl" -cgdomain "/home/cic/rh11/domains/Rovers/Propositional/domain.pddl"  -timeout 3600 -londexMode 1 >rover_result$i



i=`expr $i + 1`
done


rm solverout* -f
rm original* -f 
rm CG_Temp -f 
rm ff_Temp -f 
#rm *_result* -f 
