 #!/bin/bash


for (( i=1 ; i<=8 ; i++ ))
do
    while [[ $(pgrep -x TPSim | wc -l) -gt 7 ]]
    do
	sleep 10
    done
    ./TPSim b_${i} 100000 vrml.mac &
    sleep 10
    done
