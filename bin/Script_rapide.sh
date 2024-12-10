 #!/bin/bash


for (( i=1 ; i<=40 ; i++ ))
do
    while [[ $(pgrep -x TPSim | wc -l) -gt 60 ]]
    do
	sleep 10
    done
    ./TPSim proton_lens_300mm_ZnS_01mm_${i} 2000000 vrml.mac &
    #./TPSim proton_Sc_contact_0.1mm_${i} 10000 vrml.mac &
    sleep 10
    done
