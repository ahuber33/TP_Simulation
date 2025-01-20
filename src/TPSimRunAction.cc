/// TPSimRunAction.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimRunAction.hh"

G4Mutex TPSimRunAction::fileMutex = G4MUTEX_INITIALIZER;
const G4String TPSimRunAction::path = "../simulation_input_files/";

TPSimRunAction::TPSimRunAction(const char *suff, G4bool pMT)
    : suffixe(suff),
      flag_MT(pMT)
{
}
TPSimRunAction::~TPSimRunAction() {}

void TPSimRunAction::CreateROOTFile(G4String suffixe)
{
  f = new TFile(fileName.c_str(), "RECREATE");
  Tree_Optical = new TTree("Optical", "Optical_Information");
  Tree_TP = new TTree("TP", "TP Information"); // Tree to access position of energy deposition

  //*****************************INFORMATION FROM OPTICAL PART************************************
  RunBranch = Tree_Optical->Branch("IncidentE", &StatsOptical.IncidentE, "IncidentE/F");
  // RunBranch = Tree_Optical->Branch("DepositZnS", &StatsOptical.DepositZnS, "DepositZnS/F");
  // RunBranch = Tree_Optical->Branch("DepositSc", &StatsOptical.DepositSc, "DepositSc/F");
  //  RunBranch = Tree_Optical->Branch("ScintillationZnS", &StatsOptical.ScintillationZnS, "ScintillationZnS/I");
  //  RunBranch = Tree_Optical->Branch("CerenkovZnS", &StatsOptical.CerenkovZnS, "CerenkovZnS/I");
  // RunBranch = Tree_Optical->Branch("ScintillationSc", &StatsOptical.ScintillationSc, "ScintillationSc/I");
  //  RunBranch = Tree_Optical->Branch("CerenkovSc", &StatsOptical.CerenkovSc, "CerenkovSc/I");
  //  RunBranch = Tree_Optical->Branch("BulkAbsZnS", &StatsOptical.BulkAbsZnS, "BulkAbsZnS/I");
  // RunBranch = Tree_Optical->Branch("BulkAbsSc", &StatsOptical.BulkAbsSc, "BulkAbsSc/I");
  //  RunBranch = Tree_Optical->Branch("Absorbed", &StatsOptical.Absorbed, "Absorbed/I");
  // RunBranch = Tree_Optical->Branch("Escaped", &StatsOptical.Escaped, "Escaped/I");
  // RunBranch = Tree_Optical->Branch("Failed", &StatsOptical.Failed, "Failed/I");
  // RunBranch = Tree_Optical->Branch("Detected", &StatsOptical.Detected, "Detected/I");
  // RunBranch = Tree_Optical->Branch("ExitLightPositionX", "vector<float>", &StatsOptical.ExitLightPositionX);
  // RunBranch = Tree_Optical->Branch("ExitLightPositionY", "vector<float>", &StatsOptical.ExitLightPositionY);
  // RunBranch = Tree_Optical->Branch("LensPositionX", "vector<float>", &StatsOptical.LensPositionX);
  // RunBranch = Tree_Optical->Branch("LensPositionY", "vector<float>", &StatsOptical.LensPositionY);
  RunBranch = Tree_Optical->Branch("DetectorPositionX", "vector<float>", &StatsOptical.DetectorPositionX);
  RunBranch = Tree_Optical->Branch("DetectorPositionY", "vector<float>", &StatsOptical.DetectorPositionY);
  // RunBranch = Tree_Optical->Branch("DetectorPositionZ", "vector<float>", &StatsOptical.DetectorPositionZ);
  // RunBranch = Tree_Optical->Branch("PhotonTrajectoryX", "vector<float>", &StatsOptical.PhotonTrajectoryX);
  // RunBranch = Tree_Optical->Branch("PhotonTrajectoryY", "vector<float>", &StatsOptical.PhotonTrajectoryY);
  // RunBranch = Tree_Optical->Branch("PhotonTrajectoryZ", "vector<float>", &StatsOptical.PhotonTrajectoryZ);
  // RunBranch = Tree_Optical->Branch("PhotonTrajectoryNStep", "vector<int>", &StatsOptical.PhotonTrajectoryNStep);
  RunBranch = Tree_Optical->Branch("MomentumX", "vector<float>", &StatsOptical.MomentumX);
  RunBranch = Tree_Optical->Branch("MomentumY", "vector<float>", &StatsOptical.MomentumY);
  RunBranch = Tree_Optical->Branch("MomentumZ", "vector<float>", &StatsOptical.MomentumZ);
  RunBranch = Tree_Optical->Branch("BirthLambda", "vector<float>", &StatsOptical.BirthLambda);
  RunBranch = Tree_Optical->Branch("Time", "vector<float>", &StatsOptical.Time);
  //  RunBranch = Tree_Optical->Branch("Rayleigh", "vector<float>", &StatsOptical.Rayleigh);
  //  RunBranch = Tree_Optical->Branch("Total_Reflections", "vector<float>", &StatsOptical.Total_Reflections);
  //  RunBranch = Tree_Optical->Branch("Wrap_Reflections", "vector<float>", &StatsOptical.Wrap_Reflections);
  // RunBranch = Tree_Optical->Branch("TotalLength", "vector<float>", &StatsOptical.TotalLength);
  RunBranch = Tree_Optical->Branch("Angle_creation", "vector<float>", &StatsOptical.Angle_creation);
  RunBranch = Tree_Optical->Branch("Angle_detection", "vector<float>", &StatsOptical.Angle_detection);
  // RunBranch = Tree_Optical->Branch("Final_state_photon", "vector<int>", &StatsOptical.FinalState);

  //*****************************INFORMATION FROM THE TP**************************************
  // RunBranch = Tree_TP->Branch("ParticuleID", &StatsTP.ParticuleID, "ParticuleID/I" );
  RunBranch = Tree_TP->Branch("E_start", &StatsTP.E_start, "E_start/F");
  RunBranch = Tree_TP->Branch("E_dep", &StatsTP.E_dep, "E_dep/F");
  // RunBranch = Tree_TP->Branch("PositionX", &StatsTP.PositionX, "PositionX/F" );
  RunBranch = Tree_TP->Branch("PositionY", &StatsTP.PositionY, "PositionY/F");
  RunBranch = Tree_TP->Branch("PositionZ", &StatsTP.PositionZ, "PositionZ/F");
  // RunBranch = Tree_TP->Branch("Time", &StatsTP.Time, "Time/F" );
  // RunBranch = Tree_TP->Branch("TotalLength", &StatsTP.TotalLength, "TotalLength/F" );
}

void TPSimRunAction::WriteROOTFile(TFile* f)
{
  f->cd();
  Tree_Optical->Write();
  Tree_TP->Write();
  f->Close();
  delete f;
  f=nullptr;

  G4cout << "Write ROOT file" << G4endl;
}

void TPSimRunAction::DisplayRunTime(time_t start, time_t end)
{
  G4int elapsed = end - start;
  G4cout << "Run Completed in " << elapsed / 3600
         << ":" << (elapsed % 3600) / 60 << ":"
         << ((elapsed % 3600) % 60) << G4endl;

  // Output the time in the file Runtime.out
  std::ofstream timeout;
  timeout.open("Runtime.out", std::ios::app);
  timeout << "Run " 
          << ": " << elapsed / 3600
          << ":" << (elapsed % 3600) / 60
          << ":" << ((elapsed % 3600) % 60) << G4endl;
  timeout.close();
}

//-----------------------------------------------------
//  BeginOfRunAction:  used to calculate the start time and
//  to set up information in the run tree.
//-----------------------------------------------------
void TPSimRunAction::BeginOfRunAction(const G4Run *aRun)
{
  threadID = G4Threading::G4GetThreadId();
   // Obtenir la table des matériaux
  G4AutoLock lock(&fileMutex); // Verrouillage automatique du mutex

  if (flag_MT == false)
  {
    start = time(NULL); // start the timer clock to calculate run times
    seed = start;
    G4Random::setTheSeed(seed);
    G4cout << "seed = " << seed << G4endl;
    fileName = suffixe + ".root";
    CreateROOTFile(fileName);
    G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
  }

  else
  {
    if (G4Threading::IsMasterThread())
    {
      start = time(NULL); // start the timer clock to calculate run times
      seed = start;
      G4Random::setTheSeed(seed);
      fileName = suffixe + ".root";
      G4cout << "### Run MT " << aRun->GetRunID() << " start." << G4endl;
    }

    else
    {
      G4String s = std::to_string(threadID);
      fileName = suffixe + "_" + s + ".root";
      CreateROOTFile(fileName);
      G4cout << "filename = " << fileName << G4endl;
    }
    
  }

  //CreateROOTFile(fileName);

  if (G4VVisManager::GetConcreteInstance())
  {
    G4UImanager *UI = G4UImanager::GetUIpointer();
    UI->ApplyCommand("/vis/scene/notifyHandlers");
  }

} // end BeginOfRunAction

//-----------------------------------------------------
//  EndOfRunAction:  used to calculate the end time and
//  to write information to the run tree.
//-----------------------------------------------------
void TPSimRunAction::EndOfRunAction(const G4Run *aRun)
{
  G4AutoLock lock(&fileMutex); // Verrouillage automatique du mutex

  if (flag_MT == false)
  {
    end = time(NULL);
    WriteROOTFile(f);
    DisplayRunTime(start, end);
  }

  else
  {
    if (G4Threading::IsMasterThread())
    {
      end = time(NULL);
      DisplayRunTime(start, end);
      //WriteROOTFile(f);
    }

    else
    {
      WriteROOTFile(f);
    }
  }


  if (G4VVisManager::GetConcreteInstance())
  {
    G4UImanager::GetUIpointer()->ApplyCommand("/vis/viewer/update");
  }

  G4cout << "Leaving Run Action" << G4endl;
}

//---------------------------------------------------------
//  For each event update the statistics in the Run tree
//---------------------------------------------------------

void TPSimRunAction::UpdateStatisticsOptical(RunTallyOptical aRunTallyOptical)
{
  G4AutoLock lock(&fileMutex); // Verrouillage automatique du mutex
  StatsOptical = aRunTallyOptical;
  Tree_Optical->Fill();
}

void TPSimRunAction::UpdateStatisticsTP(RunTallyTP aRunTallyTP)
{
  G4AutoLock lock(&fileMutex); // Verrouillage automatique du mutex
  StatsTP = aRunTallyTP;
  Tree_TP->Fill();
}
