 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_N-200_100µSv_${i} 34560976 vrml_N200.mac &
   sleep 10

done

 ./TPSim Dolphy_Beta_N-200_100µSv_10 34560976 vrml_N200.mac



