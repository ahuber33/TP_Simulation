/// TPSimRunAction.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimRunAction.hh"
#include "Randomize.hh"
#include <time.h>
#include "G4Run.hh"
#include "G4UImanager.hh"
#include "G4VVisManager.hh"
#include "G4ios.hh"
#include "TFile.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH2I.h"
#include "TH1D.h"
#include "TAxis.h"
#include <fstream>
#include <iostream>

TPSimRunAction::TPSimRunAction(char* suff):suffixe(suff){}
TPSimRunAction::~TPSimRunAction(){}


//-----------------------------------------------------
//  BeginOfRunAction:  used to calculate the start time and
//  to set up information in the run tree.
//-----------------------------------------------------
void TPSimRunAction::BeginOfRunAction(const G4Run* aRun){

  //gROOT->ProcessLine("#include <vector>");

  G4String fileName = suffixe+".root";
  //f = new TFile("test.root","UPDATE");

    start = time(NULL);     //start the timer clock to calculate run times

    theRunTree = new TTree("theRunTree","Optical_Information");
    //theRunTree_bis = new TTree("theRunTree_bis","Photocathode_Information_Transmitted");
    //Tree_emitted = new TTree("Tree_emitted","Emitted Information");  //Tree to access energy emitted (except gammas)
    //Tree_position = new TTree("Tree_position","Position Information");  //Tree to access position of energy deposition

    Tree_sphere = new TTree("Tree_sphere","Sphere Information");  //Tree to access position of energy deposition


    // create the branch for each event.
    // Be careful of the data structure here!  /F is a float  /I is an integer
    RunBranch = theRunTree->Branch("Optical_Information",&Stats.IncidentE,"IncidentE/F:Deposit/F:Generated/I:Absorbed:BulkAbs:Escaped:Failed:Detected_without_CU:Lost:WLS:Detected:FWHM/F:FWHM_Final/F:Frac_Detected/F:Frac_Transmitted/F:Total_Track_Length_e/F:Count_Scintillation/I:Count_Cerenkov/I");

    //RunBranch = theRunTree_bis->Branch("Photocathode_Information",&Statsbis.Angle,"Angle/F:PositionX/F:PositionY/F:PositionZ/F:DeathLambda/F:BirthLambda/F:Total_Reflections/I:Wrap_Reflections/I:Total_Length/F");

    //RunBranch = Tree_emitted->Branch("Energy_Emitted",&Statsemitted.E_emitted_Elec,"E_emitted_Elec/F:E_emitted_Alpha/F");

    //RunBranch = Tree_position->Branch("Position_Interaction",&Statsposition.Position_x,"Position_x/F:Position_y/F:Position_z/F");

    // RunBranch = Tree_sphere->Branch("Sphere_Interaction",&Statssphere.Position_x,"Position_x/F:Position_y/F:Position_z/F:TotalLength/F");
    //
    RunBranch = Tree_sphere->Branch("E_start", &Statssphere.E_start, "E_start/F" );
    RunBranch = Tree_sphere->Branch("E_dep_Gamma", "vector<float>", &Statssphere.E_dep_Gamma );
    // RunBranch = Tree_sphere->Branch("Gamma_Interaction_X", "vector<float>", &Statssphere.Gamma_Interaction_X );
    // RunBranch = Tree_sphere->Branch("Gamma_Interaction_Y", "vector<float>", &Statssphere.Gamma_Interaction_Y );
    // RunBranch = Tree_sphere->Branch("Gamma_Interaction_Z", "vector<float>", &Statssphere.Gamma_Interaction_Z );
    RunBranch = Tree_sphere->Branch("Interaction_Location", "vector<int>", &Statssphere.Interaction_Location );
    RunBranch = Tree_sphere->Branch("TotalLength", &Statssphere.TotalLength, "TotalLength/F" );
    RunBranch = Tree_sphere->Branch("E_dep_Electron", &Statssphere.E_dep_Electron, "E_dep_Electron/F" );
    RunBranch = Tree_sphere->Branch("Rmin", &Statssphere.Rmin, "Rmin/F" );
    RunBranch = Tree_sphere->Branch("Rmax", &Statssphere.Rmax, "Rmax/F" );
    RunBranch = Tree_sphere->Branch("DeltaR", &Statssphere.DeltaR, "DeltaR/F" );
    // RunBranch = Tree_sphere->Branch("PosX", &Statssphere.PosX, "PosX/F" );
    // RunBranch = Tree_sphere->Branch("PosY", &Statssphere.PosX, "PosY/F" );
    // RunBranch = Tree_sphere->Branch("PosZ", &Statssphere.PosX, "PosZ/F" );
    // RunBranch = Tree_sphere->Branch("N_Electron_Gaz", &Statssphere.N_Electron_Gaz, "N_Electron_Gaz/I" );


    //set the random seed to the CPU clock
  //G4Random::setTheEngine(new CLHEP::HepJamesRandom);
    G4long seed = time(NULL);
    G4Random::setTheSeed(seed);
    G4cout << "seed = " << seed << G4endl;

/*
    G4long seed = time(NULL);
	G4cout << "seed = " << seed << G4endl;
    //time_t DateTime = time( NULL );
    CLHEP::HepRandom::setTheSeed(seed);
    */
    G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;

    if (G4VVisManager::GetConcreteInstance()){
      G4UImanager* UI = G4UImanager::GetUIpointer();
      UI->ApplyCommand("/vis/scene/notifyHandlers");
    }


}  //end BeginOfRunAction


//-----------------------------------------------------
//  EndOfRunAction:  used to calculate the end time and
//  to write information to the run tree.
//-----------------------------------------------------
void TPSimRunAction::EndOfRunAction(const G4Run*aRun){

    //update the temp root file
    G4String fileName = suffixe+".root";
    f = new TFile(fileName,"update");
    //theRunTree->Write();
    //theRunTree_bis->Write();
    //Tree_emitted->Write();
    //Tree_position->Write();
    Tree_sphere->Write();
  //   MakePMTHisto(f);   NOTE:  Use this for multiple PMTs!
    f->Close();

    if (G4VVisManager::GetConcreteInstance()){
      G4UImanager::GetUIpointer()->ApplyCommand("/vis/viewer/update");
    }

    //display run time and write to file Rntime.out
    time_t end = time(NULL);
    G4int elapsed = end-start;
    G4cout << "Run Completed in " << elapsed/3600
	   << ":" << (elapsed%3600)/60 << ":"
	   << ((elapsed%3600)%60) << G4endl;

    // Output the time in the file Runtime.out
    std::ofstream timeout;
    timeout.open("Runtime.out",std::ios::app);
    timeout << "Run " << aRun->GetRunID()
	    << ": " <<elapsed/3600
	    << ":" <<(elapsed%3600)/60
	    << ":" <<((elapsed%3600)%60) << G4endl;
    timeout.close();

      G4cout<<"Leaving Run Action"<<G4endl;
}

//---------------------------------------------------------
//  For each event update the statistics in the Run tree
//---------------------------------------------------------

void TPSimRunAction::UpdateStatistics(RunTally aRunTally){
    Stats = aRunTally;
    //theRunTree->Fill();
}


void TPSimRunAction::UpdateStatisticsbis(RunTallybis aRunTallybis){
    Statsbis = aRunTallybis;
    //theRunTree_bis->Fill();
}

void TPSimRunAction::UpdateStatisticsEmitted(RunTallyEmitted aRunTallyEmitted){
    Statsemitted = aRunTallyEmitted;
    //Tree_emitted->Fill();
}

void TPSimRunAction::UpdateStatisticsPosition(RunTallyPosition aRunTallyPosition){
    Statsposition = aRunTallyPosition;
    //Tree_position->Fill();
}


void TPSimRunAction::UpdateStatisticsSphere(RunTallySphere aRunTallySphere){
    Statssphere = aRunTallySphere;
    Tree_sphere->Fill();
}
