 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_N-60_100µSv_${i} 54165390 vrml_N60.mac &
   sleep 10


done

 ./TPSim Dolphy_Beta_N-60_100µSv_10 54165390 vrml_N60.mac



