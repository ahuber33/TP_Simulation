/// TPSimRunAction.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#ifndef TPSimRunAction_h
#define TPSimRunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "TROOT.h"
#include "TTree.h"
#include "TPSimEventAction.hh"
#include "TPSimGeometry.hh"
#include <TFile.h>
#include <vector>
#include <mutex>
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4RegionStore.hh"
#include "G4GeometryManager.hh"
#include "G4Threading.hh"
#include "G4VVisManager.hh"

class G4Run;

class TPSimRunAction : public G4UserRunAction
{

public:
  TPSimRunAction(const char*, G4bool);
  ~TPSimRunAction();

public:
  void BeginOfRunAction(const G4Run*);
  void EndOfRunAction(const G4Run*);
  void CreateROOTFile(G4String);
  void WriteROOTFile(TFile*);
  void DisplayRunTime(time_t, time_t);
  void CleanGeometry();

  //adds the photon fates from an event to the run tree
  void UpdateStatisticsOptical(RunTallyOptical);
  void UpdateStatisticsTP(RunTallyTP);



private:
  static const G4String path;
  G4String suffixe;
  G4bool flag_MT;
  G4int NumPMTs;
  G4int NumFibers;
  RunTallyOptical StatsOptical;
  RunTallyTP StatsTP;
  TFile *f;
  TTree *Tree_Optical;
  TTree *Tree_TP;
  TBranch *RunBranch;
  time_t start;
  time_t end;
  static G4Mutex fileMutex;
  G4String fileName;
  G4long seed;
  int threadID;
  

};

#endif
