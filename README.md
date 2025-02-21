# TPSim for Thomson Parabola Simulation [huber@cenbg.in2p3.fr, huberarnaud@gmail.com]

## INSTRUCTIONS TO USE THE SIMULATION
- Download the VMWare [Geant4.11.2.1](https://heberge.lp2ib.in2p3.fr/G4VM/index.html)

```
git clone https://github.com/ahuber33/TP_Simulation
```

- Go to build Folder and use this command :
```
cmake -DGeant4_DIR=$G4COMP ../
make -j4
```  
then compile it with make

- The executable TPSim will be add to your bin folder

- If you want to have a visualization, launch this command : 
```
./TPSim [name of ROOT file ]"
```  
It will generate 1 particle according to the vis.mac with QT and you will have a ROOT file with the name you gave in response located in the Resultats folder.

- If you want to have statistics without the visualization, use this command :
```
./TPSim [name of ROOT file] [number of events generated] [name of macro] [MultiThreading ON/OFF] [number of threads]
```  
According to the number of threads used if MT is ON, the simulation will create a ROOT file for each thread and at the end of the simulation, all ROOT files will be merged together with a name correspoding to the name given in [name of ROOT file]. The temporaries ROOT files will be removed after the merge.

Note that it's not necessary to indicate a [number of threads] if the condition on MT is OFF. In opposite, you need to put a value if MT is ON.

Personnaly, I used the vrml.mac but you can create another one. Just to remember that you need to write the name of your macro when you launch the simulation.

- In your macro, you need to specifiy some informations for the Messenger used :
```
/SteppingAction/SetVerbose 0
/SteppingAction/SetPhotonTrackStatus true
/EventAction/SetVerbose false
```

- **SteppingAction** corresponds to parameters which can be changed on SteppingAction :
    - SetVerbose manages the degree of verbose for debugging purpose according to its value
        - 0 = No Verbose
        - 1 = Basic Information on track & variables
        - 2 = Optical informations (Boundary)
    SetPhotonTrackStatus manages if the simulation needs to follow or not the optical photons created

- **EventAction** corresponds to parameters which can be changed on EventAction :
    - SetVerbose manages if the Results of Event are printed or not

- An TPSim.cfg file is located in bin directory. All the dimensions necessary are in this file to avoid recompilation when you want to change some parameters. If you add some other dimensions, don't forget to add the variables in Geometry.cc.
```
#----------Common variables----------
ScintillatorLength 76 mm
ScintillatorWidth 76 mm
ScintillatorThickness 1 mm
ZnSThickness 0.0 mm
ZnSLGThickness 0. mm
DetectorLength 51.6 mm
DetectorWidth 34.0 mm
DetectorThickness 2 um
LensThickness 0 mm
LensTranslation 0 mm
DetectorTranslation 175 mm

# ElectricField Plates dimensions
EF_Value 1000 kilovolt/m
EF_Dist_between_plates 10. mm
EF_Thickness_plates 1.0 mm
EF_Length_plates 200. mm
EF_Width_plates 55.0 mm

# MagneticField Plates dimensions
MF_Value 0.76 tesla
MF_Dist_between_plates 10. mm
MF_Thickness_plates 10.0 mm
MF_Length_plates 40. mm
MF_Width_plates 40. mm

# Pinhole dimensions
Pinhole_radius_ext 1.0 cm
Pinhole_radius_int 0.1 mm
Pinhole_thickness 10.0 mm

#Positions of Plates
Dist_between_plates 15.5 mm
Dist_EFPlates_Detector 45.1 mm
Dist_pinhole_MFPlates 15.5 mm
translation_pinhole 15.4 mm

#Fibers
Fiber_geometry 0 #0=round & 1=square
Fiber_multi_cladding 1 #0 or 1 to activate
Fiber_number_per_line 250
Fiber_space 0.01 mm
Fiber_width 0.2 mm
Fiber_cladding_ratio 0.02
Fiber_length 0.1 m
#ACTIVATION G4FastTrack
G4FAST 1

#Optical parameters
lightyield 8700
lightyieldZnS 46500
```

- Based on G4EmStandardPhysics_option3 with additional Optical part.

- DO NOT HESITATE TO REPORT BUGS OR ANY IDEAS THAT WILL IMPROVE THE SIMULATION !!!!

## ACCESS TO SIMULATION INFORMATIONS

- 2 Trees can be created in the **BeginOfRunAction** :
    -   **Tree_Optical** with the optical information from opticalphoton :
        - IncidentE : Incident energy of primary particle
        - DepositZnS : Energy deposited on ZnS part
        - DepositSc : Energy deposited on Sc part
        - ScintillationZnS : Number of photons generated by scintillation on ZnS
        - ScintillationSc : Number of photons generated by scintillation on Sc
        - CerenkovZnS : Number of photons generated by Cerenkov on ZnS
        - CerenkovSc : Number of photons generated by Cerenkov on Sc
        - BulkAbsZnS : Number of photons bulk absorbed by ZnS
        - BulkAbsSc : Number of photons bulk absorbed by Sc
        - Absorbed : Number of photons absorbed on surface
        - Escaped : Number of photons escaped (outside World)
        - WLS : Number of photons WLS
        - Failed : Number of photons transmitted (not detected by QE)
        - Detected : Number of photons detected
        - ExitLightPositionX : If Fibers geometry -> X Position at the exit of fiber
        - ExitLightPositionY : If Fibers geometry -> Y Position at the exit of fiber
        - LensPositionX : If Lens geometry -> X Position at the enter of lens
        - LensPositionY : If Lens geometry -> Y Position at the enter of lens
        - DetectorPositionX : X Position of interaction on the detector
        - DetectorPositionY : Y Position of interaction on the detector
        - DetectorPositionZ : Z Position of interaction on the detector
        - PhotonTrajectoryX : If Fibers geometry -> Storage of X positions on the Fibers
        - PhotonTrajectoryY : If Fibers geometry -> Storage of Y positions on the Fibers
        - PhotonTrajectoryNStep : If Fibers geometry -> Storage of NStep on the fibers
        - MomentumX : If Lens geometry -> X momentum at the enter of lens for reconstruction
        - MomentumY : If Lens geometry -> Y momentum at the enter of lens for reconstruction
        - MomentumZ : If Lens geometry -> Z momentum at the enter of lens for reconstruction
        - BirthLambda : Wavelength of the optical photon detected/transmitted according to condition on SteppingAction
        - Time : Time of opticalphoton detected
        - Rayleigh : Number of Rayleigh diffusion
        - Total_Reflections : Number of "Total internal reflection" occured
        - Wrap_Refelctions : Number of wrap reflections occured
        - TotalLength : Path of opticalphotons detected
        - Angle_creation : Creation angle of detected opticalphoton
        - Angle_detection : Detection angle of detected opticalphoton
        - FinalState : State of the opticalphoton at the end of the follow by simulation (Absorbed, escaped, detected,...)
        

    - **Tree_TP** with the informations of primary particles arriving on detector focal plan of the TP :
        - E_start : Incident energy of the primary particle
        - E_dep : Energy deposited on the scintillator part
        - PositionX : X Position on the scintillator part (primary particle)
        - PositionY : Y Position on the scintillator part (primary particle)
        - PositionZ : Z Position on the scintillator part (primary particle)
        - Time : Arrival time of the primary particle on the scintillator part
        - TotalLength : Length of the primary particle between emission et detection on scintillator

    
- Each variables is initialized at the **BeginOfEventAction**
- You can find all the variable functions on the **PALLAS_ColSimEventAction.hh**
- Each Trees is filled (sometimes under conditions) at the **EndOfEventAction**
- If you want to access where the informations are extracted, go to **PALLAS_CollSimSteppingAction.cc**
- A ROOT file with [name of ROOT file] given at the launch is created and wrote at the **EndOfEventAction** 
