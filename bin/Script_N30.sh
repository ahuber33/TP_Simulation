 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_N-30_100µSv_${i} 33671948 vrml_N30.mac &
   sleep 10

done

 ./TPSim Dolphy_Beta_N-30_100µSv_10 33671948 vrml_N30.mac



