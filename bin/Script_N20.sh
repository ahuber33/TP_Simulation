 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_N-20_100µSv_${i} 32102930 vrml_N20.mac &
   sleep 10

done

 ./TPSim Dolphy_Beta_N-20_100µSv_10 32102930 vrml_N20.mac



