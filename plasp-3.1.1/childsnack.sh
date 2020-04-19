



i=5
while [ $i -le 9 ]
do


echo "translating Childsnack problem #$i"

./plasp  translate ../domains/Childsnack-IPC8/domain.pddl  ../domains/Childsnack-IPC8/child-snack_pfile0$i.pddl  >  ./Childsnack-plasp-translated/instance_0$i


i=`expr $i + 1`
done



i=10
while [ $i -le 19 ]
do





echo "Translating Childsnack problem #$i"

./plasp  translate ../domains/Childsnack-IPC8/domain.pddl  ../domains/Childsnack-IPC8/child-snack_pfile$i.pddl  >  ./Childsnack-plasp-translated/instance_$i



i=`expr $i + 1`
done


