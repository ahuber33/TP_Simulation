 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_Co60_100µSv_${i} 2584590 vrml_Co60.mac &
   sleep 10

done

 ./TPSim Dolphy_Beta_Co60_100µSv_10 2584590 vrml_Co60.mac 



