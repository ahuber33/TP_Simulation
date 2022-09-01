/// TPSimPhysics.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#ifndef  TPSimPhysics_h
#define   TPSimPhysics_h  1

//#include "G4VUserPhysicsList.hh"
#include "G4VModularPhysicsList.hh"
#include "CLHEP/Units/SystemOfUnits.h"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
class  TPSimPhysics:  public G4VModularPhysicsList
{      public:
  TPSimPhysics();
  virtual ~TPSimPhysics();

protected:
  virtual void ConstructParticle();
  virtual void ConstructProcess();
  virtual void ConstructOp();
  virtual void AddIonGasModels();
  virtual void AddParameterisation();
  virtual void SetCuts();
protected:
  //virtual void ConstructBosons();
  //virtual void ConstructLeptons();
  //virtual void ConstructMesons();
  //virtual void ConstructBaryons();
protected:
  //virtual void ConstructGeneral();
  //virtual void ConstructEM();
  //virtual void ConstructAllShortLiveds();

private:
  G4VPhysicsConstructor*  emPhysicsList;
  G4VPhysicsConstructor*  particleList;
  G4VPhysicsConstructor*  raddecayList;
  std::vector<G4VPhysicsConstructor*>  hadronPhys;
};
#endif
