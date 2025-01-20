/// TPSimEventAction.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
/// Copyright: 2017 (C) Projet BADGE - CARMELEC -P2R

#include "TPSimEventAction.hh"
#include "TPSimRunAction.hh"


using namespace CLHEP;

TPSimEventAction::TPSimEventAction(const char* suff):suffixe(suff)
{
  eMessenger = new G4GenericMessenger(this, "/EventAction/", "Control commands for my application");

  eMessenger->DeclareProperty("SetVerbose", VerbosityResults)
      .SetGuidance("Set the verbosity boolean.")
      .SetParameterName("VerbosityResults", false)
      .SetDefaultValue("false");
}

TPSimEventAction::~TPSimEventAction(){}


// Initialize all counters and set up the event branches for
// filling histograms with ROOT
void TPSimEventAction::BeginOfEventAction(const G4Event* evt){

  StatsOptical = {};
  
  TrackLengthFastSimulated=0;
  PhotonTrajectoryNStep=0;
  Air_Index=-1;

  StatsTP = {};

}


// Get the number of stored trajectories and calculate the statistics
void TPSimEventAction::EndOfEventAction(const G4Event* evt){
  //G4int event_id = evt->GetEventID();

  TPSimRunAction *runac = (TPSimRunAction*)(G4RunManager::GetRunManager()->GetUserRunAction());

  Absfrac = 0;
  BulkfracZnS = 0;
  BulkfracSc = 0;
  Escfrac = 0;
  Failfrac = 0;

  efficiency = 0;
  GeneratedSc = StatsOptical.ScintillationSc + StatsOptical.CerenkovSc;
  GeneratedZnS = StatsOptical.ScintillationZnS + StatsOptical.CerenkovZnS;
  Generated = GeneratedSc + GeneratedZnS;
  Scintillation = StatsOptical.ScintillationSc + StatsOptical.ScintillationZnS;
  Cerenkov = StatsOptical.CerenkovSc + StatsOptical.CerenkovZnS;
  Deposit = StatsOptical.DepositSc +  StatsOptical.DepositZnS;


  if (VerbosityResults == true)
  {
    efficiency = 100*(1.0*StatsOptical.Detected)/(1.0*Generated);
    Absfrac = 100*(1.0*StatsOptical.Absorbed)/(1.0*Generated);
    BulkfracZnS = 100*(1.0*StatsOptical.BulkAbsZnS)/(1.0*Generated);
    BulkfracSc = 100*(1.0*StatsOptical.BulkAbsSc)/(1.0*Generated);
    Escfrac = 100*(1.0*StatsOptical.Escaped)/(1.0*Generated);
    Failfrac = 100*(1.0*StatsOptical.Failed)/(1.0*Generated);
    //WLSfrac = 100*(1.0*StatsOptical.WLS)/(1.0*Generated);
    //Catfrac = 100 * (cpt_photons_lost/(1.0*Detected));
    efficiency = 100 * (StatsOptical.Detected/(1.0*Generated));

    // Output the results
    G4cout  << "\n\nRun " << G4RunManager::GetRunManager()->GetCurrentRun()->GetRunID() <<  " >>> Event " << evt->GetEventID() << G4endl;
    G4cout << "Incident Energy:                                 " << StatsOptical.IncidentE << " keV " << G4endl;
    G4cout << "Energy Deposited TOTAL:                          " << Deposit   << " keV " << G4endl;
    //G4cout << "     in ZnS:                                 " << StatsOptical.DepositZnS   << " keV " << G4endl;
    G4cout << "     in core Fiber :                             " << StatsOptical.DepositSc   << " keV " << G4endl;
    // G4cout << "Photons Generated in ZnS:                    " << GeneratedZnS     << G4endl;
    // G4cout << "     from Scintillation :                    " << StatsOptical.ScintillationZnS << "   (" << (float(StatsOptical.ScintillationZnS))/(float(GeneratedZnS))*100 << " %)"     << G4endl;
    // G4cout << "     from Cerenkov :                         " << StatsOptical.CerenkovZnS     << "    (" << (float(StatsOptical.CerenkovZnS))/(float(GeneratedZnS))*100 << " %)"     << G4endl;
    G4cout << "Photons Generated in Core Fiber:                 " << GeneratedSc     << G4endl;
    G4cout << "     from Scintillation :                        " << StatsOptical.ScintillationSc << "     (" << (float(StatsOptical.ScintillationSc))/(float(GeneratedSc))*100 << " %)"     << G4endl;
    G4cout << "     from Cerenkov :                             " << StatsOptical.CerenkovSc     << "      (" << (float(StatsOptical.CerenkovSc))/(float(GeneratedSc))*100 << " %)"     << G4endl;
    // G4cout << "TOTAL Photons Generated:                     " << Generated      << G4endl;
    // G4cout << "     from Scintillation :                    " << Scintillation << "   (" << (float(Scintillation))/(float(Generated))*100 << " %)"     << G4endl;
    // G4cout << "     from Cerenkov :                         " << Cerenkov     << "    (" << (float(Cerenkov))/(float(Generated))*100 << " %)"     << G4endl;

    G4cout << "Photons Surface Absorbed  :                      " << StatsOptical.Absorbed      << "       " << Absfrac << " % " << G4endl;
    //G4cout << "Photons Bulk Absorbed in ZnS :               " << StatsOptical.BulkAbsZnS       << "        " << BulkfracZnS << " % " << G4endl;
    G4cout << "Photons Bulk Absorbed :                          " << StatsOptical.BulkAbsSc       << "       " << BulkfracSc << " % " << G4endl;
    G4cout << "Photons Escaped:                                 " << StatsOptical.Escaped       << "      " << Escfrac << " % " << G4endl;
    G4cout << "Photons only Transmitted to Detection Device:    " << StatsOptical.Failed        << "       " << Failfrac << " % " << G4endl;
    G4cout << "Photons Collected (QE):                          " << StatsOptical.Detected      << "       " << efficiency << " % " << G4endl;
    G4cout << "Total Photons Considered:                        " << StatsOptical.Absorbed + StatsOptical.BulkAbsZnS + StatsOptical.BulkAbsSc + StatsOptical.Escaped + StatsOptical.Failed + StatsOptical.Detected  << "      " << Absfrac + BulkfracZnS + BulkfracSc + Escfrac + Failfrac + efficiency << " % " << G4endl;
    //G4cout << "Photons WL Shifted:                          " << StatsOptical.WLS           << "        " << WLSfrac << " % " << G4endl;
    G4cout << ""  <<  G4endl;
    G4cout << ""  <<  G4endl;

  }

if(Deposit>0)
{
  runac->UpdateStatisticsOptical(StatsOptical);
  runac->UpdateStatisticsTP(StatsTP);
}


}
