/// TPSimPhysics.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimPhysics.hh"
//#include "G4MuNuclearInteraction.hh"
#include "G4KokoulinMuonNuclearXS.hh"
#include "globals.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleWithCuts.hh"
#include "G4ProcessManager.hh"
#include "G4ProcessVector.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"
#include "G4ShortLivedConstructor.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4Scintillation.hh"
#include "G4OpAbsorption.hh"
#include "G4OpRayleigh.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4ios.hh"
#include "G4OpWLS.hh"
#include "G4GenericIon.hh"
#include "G4Decay.hh"
#include "G4IonConstructor.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4ParticleDefinition.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4SystemOfUnits.hh"
#include "G4ProcessManager.hh"
#include "G4Cerenkov.hh"
#include "G4Scintillation.hh"
#include "G4OpAbsorption.hh"
#include "G4OpRayleigh.hh"
#include "G4OpMieHG.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4LossTableManager.hh"
#include "G4EmSaturation.hh"
#include "G4BraggIonGasModel.hh"
#include "G4BetheBlochIonGasModel.hh"
#include "G4EmConfigurator.hh"
#include "G4IonFluctuations.hh"
#include "G4UniversalFluctuation.hh"
#include "G4ionIonisation.hh"
#include "G4IonParametrisedLossModel.hh"
#include "G4UrbanMscModel.hh"
#include "G4BraggIonModel.hh"
#include "G4BraggModel.hh"
#include "G4BetheBlochModel.hh"
#include "G4FastSimulationManagerProcess.hh"


using namespace CLHEP;

// Taken from N06 and LXe examples in GEANT4

TPSimPhysics::TPSimPhysics():  G4VModularPhysicsList()
{
  // Here used the default cut value you have typed in
  //defaultCutValue = 0.001*mm; //0.001
  defaultCutValue = 0.1*mm; //0.001
  //was 0.5*mm

  SetVerboseLevel(1);

  //default physics
  particleList = new G4DecayPhysics();

  //default physics
  raddecayList = new G4RadioactiveDecayPhysics();

  // EM physics
  emPhysicsList = new G4EmStandardPhysics_option3();
  //emPhysicsList = new G4EmStandardPhysics();


}

TPSimPhysics::~TPSimPhysics(){
  delete raddecayList;
  delete emPhysicsList;
}

void TPSimPhysics::ConstructParticle()
{
  // Here are constructed all particles you have chosen
  particleList->ConstructParticle();

  //  ions
  //G4IonConstructor iConstructor;
  //iConstructor.ConstructParticle();
}


void TPSimPhysics::ConstructProcess()
{
  // Transportation, electromagnetic and general processes

  AddTransportation();
  //ConstructEM();
  //ConstructGeneral();
  // Electromagnetic physics list
  emPhysicsList->ConstructProcess();
  particleList->ConstructProcess();
  raddecayList->ConstructProcess();
  ConstructOp();
  AddParameterisation();
  //AddIonGasModels();  // Be careful, use only for the TP!!! Process ionIoni not taken into account for neutral nucleus !!!

}

void TPSimPhysics::AddIonGasModels()
{
  G4EmConfigurator* em_config =
  G4LossTableManager::Instance()->EmConfigurator();
  auto particleIterator=GetParticleIterator();
  particleIterator->reset();
  while ((*particleIterator)())
  {
    G4ParticleDefinition* particle = particleIterator->value();
    G4String partname = particle->GetParticleName();
    if(partname == "alpha" || partname == "He3" || partname == "GenericIon") {
      G4BraggIonGasModel* mod1 = new G4BraggIonGasModel();
      G4BetheBlochIonGasModel* mod2 = new G4BetheBlochIonGasModel();
      G4double eth = 2.*MeV*particle->GetPDGMass()/proton_mass_c2;
      //G4double eth = 0.0001*eV;
      //G4cout << "ETH = " << eth << G4endl;

      // G4IonParametrisedLossModel* mod3 = new G4IonParametrisedLossModel();
      // em_config->SetExtraEmModel(partname,"ionIoni",mod3,"Sc",0.0,100*TeV,new G4UniversalFluctuation());

      em_config->SetExtraEmModel(partname,"ionIoni",mod1,"",0.0,eth,
      new G4IonFluctuations());
      em_config->SetExtraEmModel(partname,"ionIoni",mod2,"",eth,100*TeV,
      new G4UniversalFluctuation());

    }
  }
}


void TPSimPhysics::ConstructOp()
{
  G4Cerenkov *theCerenkovProcess = new G4Cerenkov("Cerenkov");
  G4Scintillation *theScintillationProcess = new G4Scintillation("Scintillation");
  G4Scintillation *theQuenchingScintillationProcess = new G4Scintillation("Scintillation");
  G4OpAbsorption *theAbsorptionProcess     = new G4OpAbsorption();
  G4OpRayleigh *theRayleighScatteringProcess = new G4OpRayleigh();
  G4OpBoundaryProcess *theBoundaryProcess  = new G4OpBoundaryProcess();
  G4OpWLS *theWLSProcess = new G4OpWLS();

  G4int verbosity=0;

  //theCerenkovProcess->SetMaxNumPhotonsPerStep(1);
  //theCerenkovProcess->SetMaxBetaChangePerStep(1);
  theCerenkovProcess->SetTrackSecondariesFirst(false);
  theCerenkovProcess->SetVerboseLevel(verbosity);
  //theCerenkovProcess->DumpPhysicsTable();

  theScintillationProcess->SetVerboseLevel(verbosity);
  theQuenchingScintillationProcess->SetVerboseLevel(verbosity);

  theAbsorptionProcess->SetVerboseLevel(verbosity);
  theRayleighScatteringProcess->SetVerboseLevel(verbosity);
  theBoundaryProcess->SetVerboseLevel(verbosity);
  theWLSProcess->SetVerboseLevel(0);

  //theScintillationProcess->SetScintillationYieldFactor(1.);
  theScintillationProcess->SetTrackSecondariesFirst(true);
  //theQuenchingScintillationProcess->SetScintillationYieldFactor(1.);
  theQuenchingScintillationProcess->SetTrackSecondariesFirst(true);

  G4EmSaturation* emSaturation = G4LossTableManager::Instance()->EmSaturation();
  theQuenchingScintillationProcess->AddSaturation(emSaturation);

  //G4OpticalSurfaceModel themodel = unified;
  //theBoundaryProcess->SetModel(themodel);

  G4ProcessManager * pManager = 0;
  pManager = G4OpticalPhoton::OpticalPhoton()->GetProcessManager();
  pManager->AddDiscreteProcess(theAbsorptionProcess);
  pManager->AddDiscreteProcess(theRayleighScatteringProcess);
  pManager->AddDiscreteProcess(theBoundaryProcess);
  pManager->AddDiscreteProcess(theWLSProcess);

  auto theParticleIterator = GetParticleIterator();
  theParticleIterator->reset();
  while( (*theParticleIterator)() ){
    G4ParticleDefinition* particle = theParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();

    if (theCerenkovProcess->IsApplicable(*particle))
      {
    	pmanager->AddProcess(theCerenkovProcess);
    	pmanager->SetProcessOrdering(theCerenkovProcess, idxPostStep);
      }

    if(particle->GetParticleName() == "e-")
    {
      pmanager->AddProcess(theQuenchingScintillationProcess);
      pmanager->SetProcessOrderingToLast(theQuenchingScintillationProcess, idxAtRest);
      pmanager->SetProcessOrderingToLast(theQuenchingScintillationProcess, idxPostStep);
    }

    else if (theScintillationProcess->IsApplicable(*particle))
    {
      pmanager->AddProcess(theScintillationProcess);
      pmanager->SetProcessOrderingToLast(theScintillationProcess, idxAtRest);
      pmanager->SetProcessOrderingToLast(theScintillationProcess, idxPostStep);
    }


  }
}


void TPSimPhysics::AddParameterisation() {

  G4FastSimulationManagerProcess* fastSimProcess =
   new G4FastSimulationManagerProcess("G4FSMP");

  // Registers the fastSimProcess with all the particles as a discrete and
  // continuous process (this works in all cases; in the case that parallel
  // geometries are not used, as in this example, it would be enough to
  // add it as a discrete process).
   auto particleIterator=GetParticleIterator();
   particleIterator->reset();
  while ( (*particleIterator)() ) {
  G4ParticleDefinition* particle = particleIterator->value();
   G4ProcessManager* pmanager = particle->GetProcessManager();
    pmanager->SetVerboseLevel(0);

  if(particle->GetParticleName() == "opticalphoton")
    //pmanager->AddDiscreteProcess( fastSimProcess );    // No parallel geometry
    pmanager->AddProcess( fastSimProcess, -1, 0, 0 );  // General
  }



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
