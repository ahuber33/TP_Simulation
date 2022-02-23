 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_N-15_100µSv_${i} 72722052 vrml_N15.mac &
   sleep 10

done

 ./TPSim Dolphy_Beta_N-15_100µSv_10 72722052 vrml_N15.mac



