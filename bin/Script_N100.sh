 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_N-100_100µSv_${i} 60531650 vrml_N100.mac &
   sleep 10

done

 ./TPSim Dolphy_Beta_N-100_100µSv_10 60531650 vrml_N100.mac



