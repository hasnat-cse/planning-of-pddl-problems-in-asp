
i=5
while [ $i -le 9 ]
do


echo "solving Childsnack problem #$i"

./sgplan522/sgplan522  -o ../domains/Childsnack-IPC8/domain.pddl  -f ../domains/Childsnack-IPC8/child-snack_pfile0$i.pddl  -out ./Childsnack_solutions/sol_0$i


i=`expr $i + 1`
done



i=10
while [ $i -le 19 ]
do



echo "solving Childsnack problem #$i"

./sgplan522/sgplan522  -o ../domains/Childsnack-IPC8/domain.pddl  -f ../domains/Childsnack-IPC8/child-snack_pfile$i.pddl  -out ./Childsnack_solutions/sol_$i



i=`expr $i + 1`
done
