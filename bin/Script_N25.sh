 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_N-25_100µSv_${i} 30506823 vrml_N25.mac &
   sleep 10

done

 ./TPSim Dolphy_Beta_N-25_100µSv_10 30506823 vrml_N25.mac 


