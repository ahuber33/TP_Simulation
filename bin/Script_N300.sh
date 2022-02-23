 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_N-300_100µSv_${i} 24893762 vrml_N300.mac &
   sleep 10

done

 ./TPSim Dolphy_Beta_N-300_100µSv_10 24893762 vrml_N300.mac 



