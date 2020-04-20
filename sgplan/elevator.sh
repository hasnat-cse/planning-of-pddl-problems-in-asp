
i=1
while [ $i -le 30 ]
do


echo "solving Elevator problem #$i-0"

./sgplan522/sgplan522  -o ../domains/Elevator-IPC2/domain.pddl  -f ../domains/Elevator-IPC2/s$i-0.pddl  -out ./Elevator_solutions/sol_s$i-0


i=`expr $i + 1`
done


