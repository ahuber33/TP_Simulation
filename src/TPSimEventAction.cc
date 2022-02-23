/// TPSimEventAction.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
/// Copyright: 2017 (C) Projet BADGE - CARMELEC -P2R

#include "G4SteppingManager.hh"
#include "TPSimSteppingAction.hh"
#include "G4Run.hh"
#include "TPSimEventAction.hh"
#include "G4RunManager.hh"
#include "TPSimRunAction.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4VVisManager.hh"
#include "G4ios.hh"
#include <fstream>
#include <iostream>
#include "G4PrimaryVertex.hh"
#include <math.h>
#include "TRandom3.h"
#include "TGraph.h"

using namespace CLHEP;

TPSimEventAction::TPSimEventAction(char* suff):suffixe(suff){}

TPSimEventAction::~TPSimEventAction(){}


// Initialize all counters and set up the event branches for
// filling histograms with ROOT
void TPSimEventAction::BeginOfEventAction(const G4Event* evt){

  G4int event_id = evt->GetEventID();

  // if(event_id %100 ==1)
  // {
  //   G4cout << "Event " << event_id << " Start" << G4endl;
  //   //G4cout << "Starting EventAction..." << G4endl;
  // }

  Statistics.IncidentE = 0;
  Statistics.Deposit = 0;
  Statistics.Generated = 0;
  Statistics.WLS = 0;
  Statistics.Absorbed = 0;
  Statistics.BulkAbs = 0;
  Statistics.Escaped = 0;
  Statistics.Failed = 0;
  Statistics.Detected_without_CU = 0;
  Statistics.Lost = 0;
  Statistics.Detected = 0;
  Statistics.FWHM = 0;
  Statistics.FWHM_final = 0;
  Statistics.Frac_Detected = 0;
  Statistics.Frac_Transmitted = 0;
  Statistics.Total_Track_Length_e = 0;
  Statistics.Count_Scintillation = 0;
  Statistics.Count_Cerenkov = 0;
  cpt_without_CU =0;
  cpt_with_CU = 0;
  cpt_photons_lost =0;
  nph =0;
  nph_cerenkov =0;
  nph_scintillation =0;
  Statsemitted.E_emitted_Elec =0;
  Statsemitted.E_emitted_Alpha =0;

  Statssphere.E_dep_Gamma.clear();
  Statssphere.Gamma_Interaction_X.clear();
  Statssphere.Gamma_Interaction_Y.clear();
  Statssphere.Gamma_Interaction_Z.clear();
  Statssphere.Interaction_Location.clear();
  Statssphere.TotalLength =0;
  Statssphere.E_dep_Electron =0.;
  Statssphere.N_Electron_Gaz =0;
  Statssphere.TrackID =0;
  Statssphere.Rmin =1000.;
  Statssphere.Rmax =-10.;
  Statssphere.DeltaR =-10.;
  Statssphere.E_start =0.;
  // Statssphere.PosX =-1000.;
  // Statssphere.PosY =-1000.;
  // Statssphere.PosZ =-1000.;

}


// Get the number of stored trajectories and calculate the statistics
void TPSimEventAction::EndOfEventAction(const G4Event* evt){
    G4int event_id = evt->GetEventID();

  TPSimRunAction *runac = (TPSimRunAction*)(G4RunManager::GetRunManager()->GetUserRunAction());

  //if (Statssphere.E_dep_Gamma.size() != 0)
  if (Statssphere.E_dep_Electron != 0)
    {
      runac->UpdateStatisticsSphere(Statssphere);
    }

}
