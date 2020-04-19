

i=5
while [ $i -le 9 ]
do


echo "solving Childsnack problem #$i"

./maxplan  -domain ../../domains/Childsnack-IPC8/domain.pddl  -problem ../../domains/Childsnack-IPC8/child-snack_pfile0$i.pddl -cgdomain ../../domains/Childsnack-IPC8/domain.pddl  -cgproblem ../../domains/Childsnack-IPC8/child-snack_pfile0$i.pddl



i=`expr $i + 1`
done



i=10
while [ $i -le 19 ]
do




echo "solving Childsnack problem #$i"

./maxplan  -domain ../../domains/Childsnack-IPC8/domain.pddl  -problem ../../domains/Childsnack-IPC8/child-snack_pfile$i.pddl -cgdomain ../../domains/Childsnack-IPC8/domain.pddl  -cgproblem ../../domains/Childsnack-IPC8/child-snack_pfile$i.pddl



i=`expr $i + 1`
done
