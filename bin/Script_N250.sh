 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_N-250_100µSv_${i} 28559934 vrml_N250.mac &
   sleep 10

done

 ./TPSim Dolphy_Beta_N-250_100µSv_10 28559934 vrml_N250.mac 



