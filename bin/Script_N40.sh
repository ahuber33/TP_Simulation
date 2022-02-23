 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_N-40_100µSv_${i} 40959488 vrml_N40.mac &
   sleep 10

done

 ./TPSim Dolphy_Beta_N-40_100µSv_10 40959488 vrml_N40.mac



