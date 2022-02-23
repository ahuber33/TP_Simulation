 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_N-150_100µSv_${i} 46889442 vrml_N150.mac &
   sleep 10

done

 ./TPSim Dolphy_Beta_N-150_100µSv_10 46889442 vrml_N150.mac 



