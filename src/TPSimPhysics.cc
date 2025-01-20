/// TPSimPhysics.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimPhysics.hh"

using namespace CLHEP;

// Taken from N06 and LXe examples in GEANT4

TPSimPhysics::TPSimPhysics():  G4VModularPhysicsList()
{
  // Here used the default cut value you have typed in
  //defaultCutValue = 0.001*mm; //0.001
  defaultCutValue = 1*mm; //0.001
  //was 0.5*mm

  G4int verb = 1;
  SetVerboseLevel(verb);
  
  const G4double meanLife = 1*nanosecond, halfLife = meanLife*std::log(2);
  G4NuclideTable::GetInstance()->SetThresholdOfHalfLife(halfLife);
     
  RegisterPhysics( new G4HadronElasticPhysicsHP(verb) );
  
  // Ion Elastic scattering
  RegisterPhysics( new G4IonElasticPhysics(verb));
  
  // Ion Inelastic physics
  RegisterPhysics( new G4IonPhysicsXS(verb));
  
  // stopping Particles
  RegisterPhysics( new G4StoppingPhysics(verb));
      
  // Gamma-Nuclear Physics
  //RegisterPhysics( new GammaNuclearPhysics("gamma"));
  ////RegisterPhysics( new GammaNuclearPhysicsLEND("gamma"));
  //RegisterPhysics( new G4EmExtraPhysics());
      
  // EM physics
  RegisterPhysics(new G4EmStandardPhysics_option3());
  
  // Decay
  RegisterPhysics(new G4DecayPhysics());

  // Radioactive decay
  RegisterPhysics(new G4RadioactiveDecayPhysics());  


  //Optical Physics
  RegisterPhysics(new G4OpticalPhysics);

}

TPSimPhysics::~TPSimPhysics(){
}


void TPSimPhysics::SetCuts()
{
  // defaultCutValue you have typed in is used

  if (verboseLevel >1){
    G4cout << "opticalPhysics::SetCuts:";
  }
  SetCutsWithDefault();
  //  SetCutValue(5*mm,"opticalphoton");
}
