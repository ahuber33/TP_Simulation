/// TPSimSteppingAction.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimSteppingAction.hh"
#include "G4DynamicParticle.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "G4ProcessManager.hh"
#include "G4Track.hh"
#include "G4ParticleDefinition.hh"
#include "G4OpticalPhoton.hh"
#include "TPSimRunAction.hh"
#include "G4RunManager.hh"
#include "G4EventManager.hh"
#include "PMT.hh"
#include "TPSimEventAction.hh"
#include <iostream>
#include <fstream>
#include "G4Material.hh"
#include "G4Trajectory.hh"
#include "TPSimTrackInformation.hh"
#include "TPSimGeometry.hh"
#include "G4StepPoint.hh"
#include "TRandom3.h"
#include "TF1.h"
//#include "TPSimCaloMap.hh"
//#include "TPSimUniformityPMT.hh"



using namespace CLHEP;

const G4String TPSimSteppingAction::path = "../simulation_input_files/";

TPSimSteppingAction::TPSimSteppingAction()
{}

TPSimSteppingAction::~TPSimSteppingAction(){}
void TPSimSteppingAction::UserSteppingAction(const G4Step *aStep){

G4Track* theTrack = aStep->GetTrack();


G4double x = aStep->GetTrack()->GetPosition().x();
G4double y = aStep->GetTrack()->GetPosition().y();
G4double z = aStep->GetTrack()->GetPosition().z();
//G4double r = sqrt(x*x + y*y +z*z);
G4double r = sqrt(x*x + y*y);
//G4double d = sqrt(x*x + y*y + pow(z-116,2));
//G4cout << "x = " << x << G4endl;
//G4cout << "y = " << y << G4endl;
//G4cout << "z = " << z << G4endl;

G4int Parent_ID = aStep->GetTrack()->GetParentID();



TPSimTrackInformation *trackInformation;
trackInformation = (TPSimTrackInformation*)theTrack->GetUserInformation();

//  In case you want the previous or next step information...

//  G4StepPoint* thePrePoint = aStep->GetPreStepPoint();
//  G4VPhysicalVolume* thePrePV = thePrePoint->GetPhysicalVolume();

//  G4StepPoint* thePostPoint = aStep->GetPostStepPoint();
//  G4VPhysicalVolume* thePostPV = thePostPoint->GetPhysicalVolume();


if(1){                       //set to 1 to ignore generated photons
  if(theTrack->GetDefinition()->GetParticleName()=="opticalphoton")
    theTrack->SetTrackStatus(fStopAndKill);
}




//The following lines are for debugging purposes
G4String partname = aStep->GetTrack()->GetDefinition()->GetParticleName();

//Get the Event manager
G4EventManager *evtman = G4EventManager::GetEventManager();
TPSimEventAction *evtac = (TPSimEventAction*)evtman->GetUserEventAction();


//Get the Run manager
TPSimRunAction *runac = (TPSimRunAction*)(G4RunManager::GetRunManager()->GetUserRunAction());



//TPSimTrackInformation* info = (TPSimTrackInformation*)(aStep->GetTrack()->GetUserInformation());

G4double my_dist_after = aStep->GetTrack()->GetTrackLength()/mm;

//check for bulk absorption
G4String endproc = aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();

//RunTally Statistics;
RunTallybis Statisticsbis;
RunTallybis Statssphere;
//RunTallyter Statisticster;


  Statisticsbis.Angle = 0;
  Statisticsbis.PositionX = 0;
  Statisticsbis.PositionY = 0;
  Statisticsbis.PositionZ = 0;
  Statisticsbis.DeathLambda = 0;
  Statisticsbis.BirthLambda = 0;
  //Statisticsbis.Theta = 0;



G4int StepNo = aStep->GetTrack()->GetCurrentStepNumber();


if(partname == "proton"){
  if ((aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "Scintillator")
  && (aStep->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "Scintillator")){
    //G4cout << "Step Length = " << aStep->GetTrack()->GetStepLength()/mm << " mm" << G4endl;
    evtac->AddTrackLength(aStep->GetTrack()->GetStepLength()/mm);
    //G4cout << "Track Length dans Scintillateur = " << evtac->GetTotalTrackLength() << " mm"<< G4endl;
    evtac->AddEdepElectron(aStep->GetTotalEnergyDeposit()/keV);
    //G4cout << "E deposée = " << aStep->GetTotalEnergyDeposit()/keV << " keV" << G4endl;
    //G4cout << "E deposée totale = " << evtac->GetEdepElectron() << " keV" << G4endl;
    if(aStep->GetPostStepPoint()->GetKineticEnergy()/keV==0 && evtac->GetEdepElectron() == evtac->GetEstartElectron()){
      evtac->SetInteractionDepthElectron(50+z);
      //G4cout << "Interaction Depth = " << evtac->GetInteractionDepthElectron() << G4endl;
    }
  }
}

//
// if(partname == "e-")
//   {
//     if ((aStep->GetTrack()->GetCreatorProcess()->GetProcessName() == "compt")
//   ||(aStep->GetTrack()->GetCreatorProcess()->GetProcessName() == "phot"))
// {
//   if ((aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "GM_Gaz")
//       && (aStep->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "GM_Gaz"))
//     {
//
//       evtac->AddEdepElectron(aStep->GetTotalEnergyDeposit()/keV);
//       //G4cout << "E deposée = " << aStep->GetTotalEnergyDeposit()/keV << " keV" << G4endl;
//
// 	      //Si on cherche à discriminer les électrons Compton
//
// 	      // if ((evtac->GetTrackID() != 0)
// 	      // 	  && (aStep->GetTrack()->GetTrackID() != evtac->GetTrackID()))
// 	      // 	{
// 	      // 	  G4cout << "DOUBLE !!!!!" << G4endl;
// 	      // 	}
//
// 	      // G4cout << "Track ID = " << aStep->GetTrack()->GetTrackID() << G4endl;
// 	      // evtac->SetTrackID(aStep->GetTrack()->GetTrackID());
// 	      // G4cout << "Track ID mémoire = " << evtac->GetTrackID() << G4endl;
//     }
// }
//   }


// if(partname == "e-") // Potentiellement les autres électrons de la désintégrations aussi
//   {
//     if ((aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "Gaz_Diazote")
// 	  && (aStep->GetPostStepPoint()->GetPhysicalVolume()->GetName() == "Gaz_Diazote"))
// 	{
// 	  // G4cout << "E deposée = " << aStep->GetTotalEnergyDeposit()/keV << " keV" << G4endl;
// 	  evtac->AddEdepElectron(aStep->GetTotalEnergyDeposit()/keV);
// 	  //G4cout << "E dep TOT = " << evtac->GetEdepElectron() << G4endl;
// 	}
//   }

// if(partname == "gamma" )
//   {
//     if(endproc =="compt" || endproc =="phot")
// 	{
// 	  if ((aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName()  != "Air")
// 	      && (aStep->GetPostStepPoint()->GetPhysicalVolume()->GetName() != "Air"))
// 	    {
// 	      // if (aStep->GetTrack()->GetCreatorProcess()->GetProcessName() == "RadioactiveDecay")// Potentiellement du Brem!!!!
// 	      // 	{
// 		  G4double E_gamma = aStep->GetPreStepPoint()->GetKineticEnergy()/keV - aStep->GetPostStepPoint()->GetKineticEnergy()/keV;
// 		  evtac->Fill_E_dep_Gamma(E_gamma);
// 		  evtac->Fill_Gamma_Interaction_X(x);
// 		  evtac->Fill_Gamma_Interaction_Y(y);
// 		  evtac->Fill_Gamma_Interaction_Z(z);
// 		  // G4cout << "Processus de creation = " << aStep->GetTrack()->GetCreatorProcess()->GetProcessName() << G4endl;
// 		  // G4cout << "E pre = " << aStep->GetPreStepPoint()->GetKineticEnergy()/keV << " keV" << G4endl;
// 		  // G4cout << "E post = " << aStep->GetPostStepPoint()->GetKineticEnergy()/keV << " keV" << G4endl;
// 		  // G4cout << "Energie Compton/photoélectrique = " << E_gamma << " keV" << G4endl;
// 		  // G4cout << "Position interaction X = " << x << " mm" << G4endl;
// 		  // G4cout << "Position interaction Y = " << y << " mm" << G4endl;
// 		  // G4cout << "Position interaction Z = " << z << " mm" << G4endl;
//
// 		  if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "GM_LND"){evtac->Fill_Interaction_Location(1);}
// 		  else if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "GM_Gaz"){evtac->Fill_Interaction_Location(2);}
// 		  else if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "GM_Membrane"){evtac->Fill_Interaction_Location(3);}
// 		  else if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "Grille"){evtac->Fill_Interaction_Location(4);}
// 		  else if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "Protection_Grille"){evtac->Fill_Interaction_Location(5);}
// 		  else {evtac->Fill_Interaction_Location(10);}
// 		  // if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "GM_Rondelle"){evtac->Fill_Interaction_Location(5);}
// 		  // if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "GM_Isolant"){evtac->Fill_Interaction_Location(6);}
// 		  // if (aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "GM_Gaine"){evtac->Fill_Interaction_Location(7);}
//
// 	  //}
// 	    }
// 	}
//   }


if (Parent_ID ==0 && StepNo==1)
  {
    evtac->SetEstartElectron(aStep->GetPreStepPoint()->GetKineticEnergy()/keV);
    //G4cout << "Estart = " << aStep->GetPreStepPoint()->GetKineticEnergy()/keV << G4endl;
  }


//
if(Parent_ID>0)// && aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "PhysicalWorld")
  {
    //G4cout << "Ici" << G4endl
    theTrack->SetTrackStatus(fStopAndKill);
  }


}
