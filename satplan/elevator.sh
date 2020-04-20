
i=1
while [ $i -le 30 ]
do


echo "solving Elevator problem #$i-0"

./SatPlan2006_LinuxBin/satplan  -domain ../domains/Elevator-IPC2/domain.pddl  -problem ../domains/Elevator-IPC2/s$i-0.pddl  -solution ./Elevator_solutions/sol_s$i-0


i=`expr $i + 1`
done

