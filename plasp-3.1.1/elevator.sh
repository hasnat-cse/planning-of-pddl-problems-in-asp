



i=1
while [ $i -le 30 ]
do


echo "translating Elevator problem #$i-0"

./plasp  translate --parsing-mode=compatibility ../domains/Elevator-IPC2/domain.pddl  ../domains/Elevator-IPC2/s$i-0.pddl  >  ./Elevator-plasp-translated/instance$i-0.lp


i=`expr $i + 1`
done


