/// TPSimPhysics.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#ifndef  TPSimPhysics_h
#define   TPSimPhysics_h  1

#include "G4VModularPhysicsList.hh"
#include "CLHEP/Units/SystemOfUnits.h"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4IonConstructor.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4HadronElasticPhysicsHP.hh"
#include "G4StoppingPhysics.hh"
#include "G4NuclideTable.hh"
#include "G4IonElasticPhysics.hh"
#include "G4IonPhysicsXS.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4OpticalPhysics.hh"

class  TPSimPhysics:  public G4VModularPhysicsList
{      public:
  TPSimPhysics();
  virtual ~TPSimPhysics();

protected:
  virtual void SetCuts();

private:
  G4VPhysicsConstructor*  emPhysicsList;
  G4VPhysicsConstructor*  particleList;
  G4VPhysicsConstructor*  raddecayList;
  std::vector<G4VPhysicsConstructor*>  hadronPhys;
};
#endif
