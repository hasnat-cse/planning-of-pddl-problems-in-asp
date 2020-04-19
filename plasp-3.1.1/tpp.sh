



i=1
while [ $i -le 9 ]
do


echo "translating TPP problem #$i"

./plasp  translate ../domains/TPP-Propositional-IPC5/domain.pddl  ../domains/TPP-Propositional-IPC5/p0$i.pddl  >  ./TPP-plasp-translated/instance_0$i


i=`expr $i + 1`
done



i=10
while [ $i -le 30 ]
do





echo "Translating TPP problem #$i"

./plasp  translate ../domains/TPP-Propositional-IPC5/domain.pddl  ../domains/TPP-Propositional-IPC5/p$i.pddl  >  ./TPP-plasp-translated/instance_$i



i=`expr $i + 1`
done


