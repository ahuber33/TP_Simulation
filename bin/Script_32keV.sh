 #!/bin/bash





for (( i=1 ; i<=9 ; i++ ))
do

 

 ./TPSim Dolphy_Beta_32keV_1000µSv_${i} 6710352 vrml_32keV.mac &
   sleep 10


done

 ./TPSim Dolphy_Beta_32keV_1000µSv_10 6710352 vrml_32keV.mac 



