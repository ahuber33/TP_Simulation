 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_N-80_100µSv_${i} 61001800 vrml_N80.mac &
   sleep 10

done

 ./TPSim Dolphy_Beta_N-80_100µSv_10 61001800 vrml_N80.mac



