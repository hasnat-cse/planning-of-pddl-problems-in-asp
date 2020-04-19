
i=5
while [ $i -le 9 ]
do


echo "solving Childsnack problem #$i"

./SatPlan2006_LinuxBin/satplan  -domain ../domains/Childsnack-IPC8/domain.pddl  -problem ../domains/Childsnack-IPC8/child-snack_pfile0$i.pddl  -solution ./Childsnack_solutions/sol_0$i


i=`expr $i + 1`
done



i=10
while [ $i -le 19 ]
do



echo "solving Childsnack problem #$i"

./SatPlan2006_LinuxBin/satplan  -domain ../domains/Childsnack-IPC8/domain.pddl  -problem ../domains/Childsnack-IPC8/child-snack_pfile$i.pddl  -solution ./Childsnack_solutions/sol_$i



i=`expr $i + 1`
done
