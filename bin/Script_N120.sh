 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_N-120_100µSv_${i} 53702438 vrml_N120.mac &
   sleep 10

done

 ./TPSim Dolphy_Beta_N-120_100µSv_10 53702438 vrml_N120.mac



