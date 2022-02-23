/// TPSimEventAction.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#ifndef TPSimEventAction_h
#define TPSimEventAction_h 1
#include "G4ParticleGun.hh"
#include "G4UserEventAction.hh"
#include "TH1F.h"
#include "TROOT.h"
#include "TTree.h"
#include "TBranch.h"
#include "TFile.h"
#include "TCanvas.h"
#include "CLHEP/Units/SystemOfUnits.h"
#include <vector>
#include "TVector.h"

class G4Event;


//This struct carries statistics for the whole Run
struct RunTally {
  float  IncidentE;
  float  Deposit;
  int    Generated;
  int    Absorbed;
  int    BulkAbs;
  int    Escaped;
  int    Failed;
  int    Detected_without_CU;
  int    Lost;
  int    WLS;
  int    Detected;
  float  FWHM;
  float  FWHM_final;
  float  Frac_Detected;
  float  Frac_Transmitted;
  float Total_Track_Length_e;
  int Count_Scintillation;
  int Count_Cerenkov;

  inline int operator ==(const RunTally& right) const
    {return (this==&right);}
};


//This struct carries statistics for the whole Run
struct RunTallybis {
  float  Angle;
  float  PositionX;
  float  PositionY;
  float  PositionZ;
  float  DeathLambda;
  float  BirthLambda;
  //float  Theta;
  //float  Phi;
  int Total_Reflections;
  int Wrap_Reflections;
  float TotalLength;

  inline int operator ==(const RunTallybis& right) const
    {return (this==&right);}
};



struct RunTallyEmitted {
  float E_emitted_Elec;
  float E_emitted_Alpha;
  float E_emitted_Gamma;

  inline int operator ==(const RunTallyEmitted& right) const
    {return (this==&right);}
};



struct RunTallyPosition {
  float Position_x;
  float Position_y;
  float Position_z;

  inline int operator ==(const RunTallyPosition& right) const
    {return (this==&right);}
};


struct RunTallySphere {
  float E_start;
  std::vector<float> E_dep_Gamma;
  std::vector<float> Gamma_Interaction_X;
  std::vector<float> Gamma_Interaction_Y;
  std::vector<float> Gamma_Interaction_Z;
  std::vector<int> Interaction_Location;
  float TotalLength;
  float E_dep_Electron;
  int N_Electron_Gaz;
  int TrackID;
  float Rmin;
  float Rmax;
  float DeltaR;
  // float PosX;
  // float PosY;
  // float PosZ;

  inline int operator ==(const RunTallySphere& right) const
    {return (this==&right);}
};



class TPSimEventAction : public G4UserEventAction
{
  public:
    TPSimEventAction(char*);
   ~TPSimEventAction();

public:
  void BeginOfEventAction(const G4Event*);
  void EndOfEventAction(const G4Event*);
  //Keeps track of the total number of generated photons
  void AddGenerated(G4int numgenerated){Statistics.Generated+=numgenerated;}
  //Keeps track of the total energy deposited in the scintillator
  void AddEdep(G4double edep){Statistics.Deposit+=edep;}

  //void CountDetected(Tally);
  void CountDetected_without_CU(){Statistics.Detected_without_CU++;}
  void CountDetected(){Statistics.Detected++;}
  void CountWLS(){Statistics.WLS++;}
  void CountAbsorbed(){Statistics.Absorbed++;}
  void CountBulkAbs(){Statistics.BulkAbs++;}
  void CountEscaped(){Statistics.Escaped++;}
  void CountFailed(){Statistics.Failed++;}
  void E_emitted_Elec(float e) {Statsemitted.E_emitted_Elec =e;}
  void E_emitted_Alpha(float e) {Statsemitted.E_emitted_Alpha =e;}
  void E_emitted_Gamma(float e) {Statsemitted.E_emitted_Gamma =e;}

  void Setcpt_without_CU(G4int e){ cpt_without_CU = e;}
  G4int Getcpt_without_CU(){return cpt_without_CU;}

  void Setcpt_photons_lost(G4int d){ cpt_photons_lost = d;}
  G4int Getcpt_photons_lost(){return cpt_photons_lost;}

  void Setnph(int d){ nph = d;}
  int Getnph() {return nph;}

  void CountCerenkov(){Statistics.Count_Cerenkov++;}
  int GetCountCerenkov(){return Statistics.Count_Cerenkov;}
  void CountScintillation(){Statistics.Count_Scintillation++;}
  int GetCountScintillation(){return Statistics.Count_Scintillation;}





  void Fill_E_dep_Gamma (G4float E) {Statssphere.E_dep_Gamma.push_back(E);};
  void Fill_Gamma_Interaction_X (G4float x) {Statssphere.Gamma_Interaction_X.push_back(x);};
  void Fill_Gamma_Interaction_Y (G4float y) {Statssphere.Gamma_Interaction_Y.push_back(y);};
  void Fill_Gamma_Interaction_Z (G4float z) {Statssphere.Gamma_Interaction_Z.push_back(z);};
  void Fill_Interaction_Location (G4float a) {Statssphere.Interaction_Location.push_back(a);};
  void AddTrackLength(G4double d){Statssphere.TotalLength+=d;}
  float GetTotalTrackLength(){return Statssphere.TotalLength;}
  void AddEdepElectron(G4double d){Statssphere.E_dep_Electron+=d;}
  float GetEdepElectron(){return Statssphere.E_dep_Electron;}
  void AddElectronGaz(){Statssphere.N_Electron_Gaz++;}
  int GetElectronGaz(){return Statssphere.N_Electron_Gaz;}
  void SetTrackID(int a){Statssphere.TrackID = a;}
  int GetTrackID(){return Statssphere.TrackID;}
  void SetRmin(float a){Statssphere.Rmin = a;}
  float GetRmin(){return Statssphere.Rmin;}
  void SetRmax(float a){Statssphere.Rmax = a;}
  float GetRmax(){return Statssphere.Rmax;}
  void SetDeltaR(float a){Statssphere.DeltaR = a;}
  float GetDeltaR(){return Statssphere.DeltaR;}
  void SetEstart(float a){Statssphere.E_start = a;}
  float GetEstart(){return Statssphere.E_start;}
  // void SetPosX(float a){Statssphere.PosX = a;}
  // float GetPosX(){return Statssphere.PosX;}
  // void SetPosY(float a){Statssphere.PosX = a;}
  // float GetPosY(){return Statssphere.PosX;}
  // void SetPosZ(float a){Statssphere.PosZ = a;}
  // float GetPosZ(){return Statssphere.PosZ;}


  //Keeps track of the incident energy of the primary particle
  void SetIncidentE(G4double ince){Statistics.IncidentE=ince;}


private:

  TTree *EventTree;
  TBranch *EventBranch;
  //Tally BranchFiller;
  RunTally Statistics;
  RunTallybis Statsbis;
  RunTallyEmitted Statsemitted;
  RunTallyPosition Statsposition;
  RunTallySphere Statssphere;
  G4int cpt_without_CU;
  G4int cpt_with_CU;
  G4int cpt_photons_lost;
  G4int nph;
  G4int nph_cerenkov;
  G4int nph_scintillation;
  G4int Track;
  G4String suffixe;





};


#endif
