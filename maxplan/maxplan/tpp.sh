



#i=1
#while [ $i -le 9 ]
#do

#rm ff_temp -f
#rm CG_temp -f 

#echo "solving TPP problem #$i"

#./maxplan  -domain ../../domains/TPP-Propositional-IPC5/domain.pddl  -problem ../../domains/TPP-Propositional-IPC5/p0$i.pddl -cgdomain ../../domains/TPP-Propositional-IPC5/domain.pddl  -cgproblem ../../domains/TPP-Propositional-IPC5/p0$i.pddl



#i=`expr $i + 1`
#done



i=22
while [ $i -le 25 ]
do



rm ff_temp -f
rm CG_temp -f 

echo "solving TPP problem #$i"

./maxplan  -domain ../../domains/TPP-Propositional-IPC5/domain.pddl  -problem ../../domains/TPP-Propositional-IPC5/p$i.pddl -cgdomain ../../domains/TPP-Propositional-IPC5/domain.pddl  -cgproblem ../../domains/TPP-Propositional-IPC5/p$i.pddl



i=`expr $i + 1`
done


rm solverout* -f
rm original* -f 
rm CG_Temp -f 
rm ff_Temp -f 
#rm *_result* -f 
