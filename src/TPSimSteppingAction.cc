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

    //#####################
    // Déclaration of Trees
    //#####################
    //RunTally Statistics;
    RunTallybis Statisticsbis;
    RunTallybis Statssphere;
    //RunTallyter Statisticster;


    //###################################
    // Déclaration of functions/variables
    //###################################
    G4Track* theTrack = aStep->GetTrack();
    TPSimTrackInformation *trackInformation = (TPSimTrackInformation*)theTrack->GetUserInformation();
    G4String partname = aStep->GetTrack()->GetDefinition()->GetParticleName();
    TPSimRunAction *runac = (TPSimRunAction*)(G4RunManager::GetRunManager()->GetUserRunAction());
    G4EventManager *evtman = G4EventManager::GetEventManager();
    TPSimEventAction *evtac = (TPSimEventAction*)evtman->GetUserEventAction();
    TPSimTrackInformation* info = (TPSimTrackInformation*)(aStep->GetTrack()->GetUserInformation());
    G4String endproc = aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
    G4int Parent_ID = aStep->GetTrack()->GetParentID();
    G4int StepNo = aStep->GetTrack()->GetCurrentStepNumber();

    G4double x = aStep->GetTrack()->GetPosition().x();
    G4double y = aStep->GetTrack()->GetPosition().y();
    G4double z = aStep->GetTrack()->GetPosition().z();
    G4double z_origine = 90. -z; // Limits of photocathode in z plane => Define origine for determine cathode uniformity !!!!
    G4double r = sqrt(x*x + y*y);
    G4double theta = acos((z_origine)/r)/deg;
    G4double my_dist_after = aStep->GetTrack()->GetTrackLength()/mm;




    if(0){                       //set to 1 to ignore generated photons
      if(theTrack->GetDefinition()->GetParticleName()=="opticalphoton")
      theTrack->SetTrackStatus(fStopAndKill);
    }


    //The following lines are for debugging purposes
    if(partname == "opticalphoton" && aStep->GetTrack()->GetUserInformation() ==0) G4cout << "WARNING! No user info attached to photon" << G4endl;


    //if more than 1 secondary is generated, update scintillation statistics

    // if(fpSteppingManager->GetfN2ndariesPostStepDoIt()>0) {
    //
    //   //these two will give you the number of wls photons
    //   //if(theTrack->GetDefinition()->GetParticleName()=="opticalphoton"){
    //    //evtac->AddGenerated(fpSteppingManager->GetfN2ndariesPostStepDoIt());}
    //
    //   //evtac->AddGenerated(fpSteppingManager->GetfN2ndariesPostStepDoIt());
    //   evtac->AddTrackLength(aStep->GetTrack()->GetStepLength()/mm);
    //   //G4cout << " Track Length = " << aStep->GetTrack()->GetTrackLength()/mm << G4endl;
    //   //G4cout << "Count ph" << G4endl;
    // }


    //#######################################################################
    //#######################################################################
    //##########################START OPTICAL PART###########################
    //#######################################################################
    //#######################################################################


    G4OpBoundaryProcessStatus boundaryStatus=Undefined;
    static G4OpBoundaryProcess* boundary=NULL;

    //find the boundary process only once
    if(!boundary){
      G4ProcessManager* pm = aStep->GetTrack()->GetDefinition()->GetProcessManager();
      G4int nprocesses = pm->GetProcessListLength();
      G4ProcessVector* pv = pm->GetProcessList();
      G4int i;
      for( i = 0; i < nprocesses; i++){
        if((*pv)[i]->GetProcessName()=="OpBoundary"){
          boundary = (G4OpBoundaryProcess*)(*pv)[i];
          break;
        }
      }
    }

    if(partname =="opticalphoton"){ //ALL the code in relation with Optical needs to be here !!!!
      boundaryStatus = boundary->GetStatus();
      //G4cout << "BirthLambda = " << info->GetBirthLambda() << G4endl;

      Statisticsbis.Angle = theta;
      Statisticsbis.PositionX = x;
      Statisticsbis.PositionY = y;
      Statisticsbis.PositionZ = z;
      Statisticsbis.DeathLambda = 1240*eV/(aStep->GetTrack()->GetTotalEnergy());
      Statisticsbis.BirthLambda = info->GetBirthLambda();
      Statisticsbis.TotalLength = aStep->GetTrack()->GetTrackLength()/mm;
      Statisticsbis.Time = aStep->GetPostStepPoint()->GetGlobalTime()/ns;
      Statisticsbis.Rayleigh = ((TPSimTrackInformation*) (aStep->GetTrack()->GetUserInformation()))->GetRayleigh();
      Statisticsbis.Total_Reflections = ((TPSimTrackInformation*) (aStep->GetTrack()->GetUserInformation()))->GetTotalInternalReflections();
      Statisticsbis.Wrap_Reflections = ((TPSimTrackInformation*)(aStep->GetTrack()->GetUserInformation()))->GetReflections();

      //G4cout << "Time =" << aStep->GetPostStepPoint()->GetGlobalTime()/ns << G4endl;

      if(endproc == "OpAbsorption")
      {
        evtac->CountBulkAbs();
        //G4cout << "Photon BulkAbsorbed" << G4endl;
        //runac->UpdateStatisticsbis(Statisticsbis);
      }


      if(endproc == "OpRayleigh")
      {
        ((TPSimTrackInformation*)(aStep->GetTrack()->GetUserInformation()))->CountRayleighScattering();
        //G4cout << "Rayleigh scattering" << G4endl;
        //G4cout << "Number of scattering = " << ((ENLOpticalSimTrackInformation*) (aStep->GetTrack()->GetUserInformation()))->GetRayleigh() << G4endl;
      }

      // If WLS -> Use this !!!
      /*
      else if (endproc == "OpWLS")
      {
      evtac->CountWLS();
      my_dist_after = my_dist_after + aStep->GetTrack()->GetTrackLength()/mm;
      //G4cout << "Count WLS true = " << info->GetWLSCount() << G4endl;
      //G4cout << "Distance d = " << d << G4endl;

      //{
      if (info->GetWLSCount() == 0)
      {
      Length_Track = aStep->GetTrack()->GetTrackLength()/mm;
      //G4cout << "Count WLS = " << info->GetWLSCount() << G4endl;
    }

    if (info->GetWLSCount() > 0)
    {
    Length_Track += aStep->GetTrack()->GetTrackLength()/mm;
    //G4cout << "Count WLS = " << info->GetWLSCount() << G4endl;
  }
  //G4cout << "Track Length = " << aStep->GetTrack()->GetTrackLength()/mm << G4endl;
  //G4cout << "Total Length Track (for different OpWLS) = " << Total_Length_Track << G4endl;
}
*/

else if(partname == "opticalphoton" && endproc != "Transportation")
G4cout << endproc << G4endl;


if(aStep->GetPostStepPoint()->GetStepStatus()==fGeomBoundary){

  switch(boundaryStatus){
    case Detection:
    {
      evtac->CountDetected();
      //G4cout << "Photon detecté" << G4endl;
      //  evtac->CountDetected_without_CU();
      //evtac->CountDetected(aTally);
      runac->UpdateStatisticsbis(Statisticsbis);

      break;
      case Absorption:    // used to get the number TRANSMITTED!!

      if (theTrack->GetNextVolume()->GetName()=="Photocathode")
      {
        evtac->CountFailed();
        //runac->UpdateStatisticsbis(Statisticsbis);

        //  Note that currently it is not set up to root output...see void CountDetected();
        //G4cout << "Photon failed" << G4endl;
      }
      else{  // if not bulk, transmitted, or detected...it must be surface!
        evtac->CountAbsorbed();

        //G4cout << "Photon surface absorbed" << G4endl;
      }

      break;
      case Undefined: G4cout<<"Undefined Boundary Process!"<<G4endl;
      break;
      case NoRINDEX:
      {
        evtac->CountEscaped();
        //G4cout << "count escaped" << G4endl;

      }
      break;

      // if we have any kind of reflections, count them
      case LambertianReflection:
      case LobeReflection:
      case SpikeReflection:
      {
        ((TPSimTrackInformation*)(aStep->GetTrack()->GetUserInformation()))->CountReflections();
        //G4cout << "Reflection" << G4endl;
        break;}
        case TotalInternalReflection:
        {
          ((TPSimTrackInformation*)(aStep->GetTrack()->GetUserInformation()))->CountTotalInternalReflections();
          //G4cout << "Reflection totale" << G4endl;
          break;
        }
        default:
        break;
      }
    }
  }


  if(partname == "opticalphoton" && aStep->GetTrack()->GetCreatorProcess()->GetProcessName() == "Scintillation" && StepNo ==1)
  {
    //G4cout << " Photon Scintillation!!!" << G4endl;
    evtac->CountScintillation();
    //G4cout << "n sc = " << evtac->GetCountScintillation() << G4endl;
    //runac->UpdateStatisticsbis(Statisticsbis);

  }

  if(partname == "opticalphoton" && aStep->GetTrack()->GetCreatorProcess()->GetProcessName() == "Cerenkov" && StepNo ==1)
  {
    //G4cout << " Photon Cerenkov !!!" << G4endl;
    evtac->CountCerenkov();
    //G4cout << "n cerenkov = " << evtac->GetCountCerenkov() << G4endl;
    //G4cout << " Birth = " << info->GetBirthLambda() << G4endl;
    //Statisticsbis.BirthLambda = info->GetBirthLambda();
    //runac->UpdateStatisticsbis(Statisticsbis);
  }


  //If you want to access to the properties of generated photons !!!!
  //if(partname == "opticalphoton" && StepNo==1){runac->UpdateStatisticsbis(Statisticsbis);}

}

//#######################################################################
//#######################################################################
//############################END OPTICAL PART###########################
//#######################################################################
//#######################################################################



//#######################################################################
//#######################################################################
//###########################START EM INFOS PART#########################
//#######################################################################
//#######################################################################


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


if (Parent_ID ==0)
{
  if(StepNo==1)
  {
    evtac->SetEstartElectron(aStep->GetPreStepPoint()->GetKineticEnergy()/keV);
    evtac->SetIncidentE(aStep->GetPreStepPoint()->GetKineticEnergy()/keV);
  }
}
if(aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "Scintillator" && partname != "opticalphoton") {evtac->AddEdep(aStep->GetTotalEnergyDeposit()/keV);}

//
// if(Parent_ID>0)// && aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName() == "PhysicalWorld")
//   {
//     //G4cout << "Ici" << G4endl
//     theTrack->SetTrackStatus(fStopAndKill);
//   }






}
