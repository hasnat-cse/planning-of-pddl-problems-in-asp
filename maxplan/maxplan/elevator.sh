

i=1
while [ $i -le 30 ]
do

rm ff_temp -f
rm CG_temp -f 

echo "solving Elevator problem #$i-0"

./maxplan  -domain ../../domains/Elevator-IPC2/domain.pddl  -problem ../../domains/Elevator-IPC2/s$i-0.pddl -cgdomain ../../domains/Elevator-IPC2/domain.pddl  -cgproblem ../../domains/Elevator-IPC2/s$i-0.pddl



i=`expr $i + 1`
done



rm solverout* -f
rm original* -f 
rm CG_Temp -f 
rm ff_Temp -f 
