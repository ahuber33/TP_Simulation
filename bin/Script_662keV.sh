 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_662keV_1000µSv_${i} 82663758 vrml_662keV.mac &
   sleep 10



done

 ./TPSim Dolphy_Beta_662keV_1000µSv_10 82663758 vrml_662keV.mac 



