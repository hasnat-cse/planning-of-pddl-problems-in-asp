



i=1
while [ $i -le 9 ]
do


echo "solving TPP problem #$i"

./sgplan522/sgplan522  -o ../domains/TPP-Propositional-IPC5/domain.pddl  -f ../domains/TPP-Propositional-IPC5/p0$i.pddl  -out ./TPP_solutions/sol_0$i


i=`expr $i + 1`
done



i=10
while [ $i -le 30 ]
do



echo "solving TPP problem #$i"

./sgplan522/sgplan522  -o ../domains/TPP-Propositional-IPC5/domain.pddl  -f ../domains/TPP-Propositional-IPC5/p$i.pddl  -out ./TPP_solutions/sol_$i



i=`expr $i + 1`
done


