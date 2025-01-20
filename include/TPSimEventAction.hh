/// TPSimEventAction.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#ifndef TPSimEventAction_h
#define TPSimEventAction_h 1
#include "G4UserEventAction.hh"
#include "TROOT.h"
#include "TTree.h"
#include "TBranch.h"
#include "CLHEP/Units/SystemOfUnits.h"
#include <vector>
#include "G4Run.hh"
#include "TRandom3.h"
#include "G4GenericMessenger.hh"

class G4Event;


//This struct carries statistics OPTICAL part
struct RunTallyOptical {
  float  IncidentE;
  float  DepositZnS;
  float  DepositSc;
  G4int    ScintillationZnS;
  G4int    CerenkovZnS;
  G4int    ScintillationSc;
  G4int    CerenkovSc;
  G4int    BulkAbsZnS;
  G4int    BulkAbsSc;
  G4int    Absorbed;
  G4int    Escaped;
  G4int    Failed;
  G4int    Detected;
  std::vector<float>ExitLightPositionX;
  std::vector<float>ExitLightPositionY;
  std::vector<float>LensPositionX;
  std::vector<float>LensPositionY;
  std::vector<float>DetectorPositionX;
  std::vector<float>DetectorPositionY;
  std::vector<float>DetectorPositionZ;
  std::vector<float>PhotonTrajectoryX;
  std::vector<float>PhotonTrajectoryY;
  std::vector<float>PhotonTrajectoryZ;
  std::vector<int>PhotonTrajectoryNStep;
  std::vector<float>MomentumX;
  std::vector<float>MomentumY;
  std::vector<float>MomentumZ;
  std::vector<float>BirthLambda;
  std::vector<float>Time;
  std::vector<float>Rayleigh;
  std::vector<float>Total_Reflections;
  std::vector<float>Wrap_Reflections;
  std::vector<float>TotalLength;
  std::vector<float>Angle_creation;
  std::vector<float>Angle_detection;
  std::vector<int>FinalState;

  inline G4int operator ==(const RunTallyOptical& right) const
  {return (this==&right);}
};

struct RunTallyTP {
  G4int ParticuleID;
  float E_start;
  float E_dep;
  float PositionX;
  float PositionY;
  float PositionZ;
  float Time;
  float TotalLength;  


  inline G4int operator ==(const RunTallyTP& right) const
  {return (this==&right);}
};


class TPSimEventAction : public G4UserEventAction
{
public:
  TPSimEventAction(const char*);
  ~TPSimEventAction();

public:
  void BeginOfEventAction(const G4Event*);
  void EndOfEventAction(const G4Event*);


// ░█████╗░██████╗░████████╗██╗░█████╗░░█████╗░██╗░░░░░
// ██╔══██╗██╔══██╗╚══██╔══╝██║██╔══██╗██╔══██╗██║░░░░░
// ██║░░██║██████╔╝░░░██║░░░██║██║░░╚═╝███████║██║░░░░░
// ██║░░██║██╔═══╝░░░░██║░░░██║██║░░██╗██╔══██║██║░░░░░
// ╚█████╔╝██║░░░░░░░░██║░░░██║╚█████╔╝██║░░██║███████╗
// ░╚════╝░╚═╝░░░░░░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚═╝╚══════╝

  //Functions for Optical Tree
  void SetIncidentE(float ince){StatsOptical.IncidentE=ince;}
  void AddEdepSc(float edep){StatsOptical.DepositSc+=edep;}
  float GetEdepSc(){return StatsOptical.DepositSc;}
  void AddEdepZnS(float edep){StatsOptical.DepositZnS+=edep;}
  void CountCerenkovZnS(){StatsOptical.CerenkovZnS++;}
  void CountCerenkovSc(){StatsOptical.CerenkovSc++;}
  void CountScintillationZnS(){StatsOptical.ScintillationZnS++;}
  void CountScintillationSc(){StatsOptical.ScintillationSc++;}
  float GetScintillationSc(){return StatsOptical.ScintillationSc;}
  void CountDetected(){StatsOptical.Detected++;}
  int GetDetected(){return StatsOptical.Detected;}
  //void CountWLS(){StatsOptical.WLS++;}
  void CountAbsorbed(){StatsOptical.Absorbed++;}
  int GetAbsorbed(){return StatsOptical.Absorbed;}
  void CountBulkAbsSc(){StatsOptical.BulkAbsSc++;}
  int GetBulkAbsSc(){return StatsOptical.BulkAbsSc;}
  void CountBulkAbsZnS(){StatsOptical.BulkAbsZnS++;}
  int GetBulkAbsZnS(){return StatsOptical.BulkAbsZnS;}
  void CountEscaped(){StatsOptical.Escaped++;}
  int GetEscaped(){return StatsOptical.Escaped;}
  void CountFailed(){StatsOptical.Failed++;}
  int GetFailed(){return StatsOptical.Failed;}
  void FillPhotonExitLightPositionX(float e){StatsOptical.ExitLightPositionX.push_back(e);}
  void FillPhotonExitLightPositionY(float e){StatsOptical.ExitLightPositionY.push_back(e);}
  void FillPhotonLensPositionX(float e){StatsOptical.LensPositionX.push_back(e);}
  void FillPhotonLensPositionY(float e){StatsOptical.LensPositionY.push_back(e);}
  void FillPhotonDetectorPositionX(float e){StatsOptical.DetectorPositionX.push_back(e);}
  void FillPhotonDetectorPositionY(float e){StatsOptical.DetectorPositionY.push_back(e);}
  void FillPhotonDetectorPositionZ(float e){StatsOptical.DetectorPositionZ.push_back(e);}
  void FillPhotonTrajectoryX(float e){StatsOptical.PhotonTrajectoryX.push_back(e);}
  void FillPhotonTrajectoryY(float e){StatsOptical.PhotonTrajectoryY.push_back(e);}
  void FillPhotonTrajectoryZ(float e){StatsOptical.PhotonTrajectoryZ.push_back(e);}
  void FillPhotonTrajectoryNStep(G4int e){StatsOptical.PhotonTrajectoryNStep.push_back(e);}
  void FillPhotonFinalState(G4int e){StatsOptical.FinalState.push_back(e);}
  void FillPhotonMomentumX(float e){StatsOptical.MomentumX.push_back(e);}
  void FillPhotonMomentumY(float e){StatsOptical.MomentumY.push_back(e);}
  void FillPhotonMomentumZ(float e){StatsOptical.MomentumZ.push_back(e);}
  void FillBirthLambda(float e){StatsOptical.BirthLambda.push_back(e);}
  void FillPhotonTime(float e){StatsOptical.Time.push_back(e);}
  void FillRayleigh(float e){StatsOptical.Rayleigh.push_back(e);}
  void FillTotalReflections(float e){StatsOptical.Total_Reflections.push_back(e);}
  void FillWrapReflecions(float e){StatsOptical.Wrap_Reflections.push_back(e);}
  void FillPhotonTotalLength(float e){StatsOptical.TotalLength.push_back(e);}
  void FillFiberAngleCreation(float e){StatsOptical.Angle_creation.push_back(e);}
  void SetPhotonCreationAngle(float e){Photon_creation_angle=e;}
  float GetPhotonCreationAngle(){return Photon_creation_angle;}
  void SetPhotonCreationLambda(float e){Photon_creation_lambda=e;}
  float GetPhotonCreationLambda(){return Photon_creation_lambda;}
  void FillFiberAngleDetection(float e){StatsOptical.Angle_detection.push_back(e);}
  void SetTrackLengthFastSimulated(float a){TrackLengthFastSimulated=a;}
  float GetTrackLengthFastSimulated(){return TrackLengthFastSimulated;}
  void AddPhotonTrajectoryNStep(){PhotonTrajectoryNStep++;}
  void ClearPhotonTrajectoryNStep(){PhotonTrajectoryNStep=0;}
  int GetPhotonTrajectoryNStep(){return PhotonTrajectoryNStep;}
  int GetSizePhotonTrajectoryNStep(){return StatsOptical.PhotonTrajectoryNStep.size();}
  int GetSizePhotonTrajectoryX(){return StatsOptical.PhotonTrajectoryX.size();}
  void SetAirIndex(float a){Air_Index = a;}
  float GetAirIndex(){return Air_Index;}



// ███████╗███╗░░░███╗░░░░░░████████╗██████╗░
// ██╔════╝████╗░████║░░░░░░╚══██╔══╝██╔══██╗
// █████╗░░██╔████╔██║█████╗░░░██║░░░██████╔╝
// ██╔══╝░░██║╚██╔╝██║╚════╝░░░██║░░░██╔═══╝░
// ███████╗██║░╚═╝░██║░░░░░░░░░██║░░░██║░░░░░
// ╚══════╝╚═╝░░░░░╚═╝░░░░░░░░░╚═╝░░░╚═╝░░░░░

  //Functions for TP Tree
  void SetParticuleID(float a){StatsTP.ParticuleID =a;}
  float GetParticuleID(){return StatsTP.ParticuleID;}
  void SetEstartTP(float d){StatsTP.E_start+=d;}
  float GetEstartTP(){return StatsTP.E_start;}
  void AddEdepTP(float d){StatsTP.E_dep+=d;}
  float GetEdepTP(){return StatsTP.E_dep;}
  void SetTPPositionX(float d){StatsTP.PositionX=d;}
  float GetTPPositionX(){return StatsTP.PositionX;}
  void SetTPPositionY(float d){StatsTP.PositionY=d;}
  float GetTPPositionY(){return StatsTP.PositionY;}
  void SetTPPositionZ(float d){StatsTP.PositionZ=d;}
  float GetTPPositionZ(){return StatsTP.PositionZ;}
  void SetTPTime(float d){StatsTP.Time=d;}
  float GetTPTime(){return StatsTP.Time;}
  void AddTrackLength(float d){StatsTP.TotalLength+=d;}
  float GetTotalTrackLength(){return StatsTP.TotalLength;}


private:

  G4GenericMessenger* eMessenger;
  TTree *EventTree;
  TBranch *EventBranch;
  RunTallyOptical StatsOptical;
  RunTallyTP StatsTP;
  G4String suffixe;
  float TrackLengthFastSimulated=0.0;
  G4int PhotonTrajectoryNStep=0;
  float Photon_creation_angle=0.0;
  float Photon_creation_lambda=0.0;
  float Air_Index=0.0;

  float Absfrac=0.0;
  float BulkfracZnS=0.0;
  float BulkfracSc=0.0;
  float Escfrac=0.0;
  float Failfrac=0.0;
  float efficiency=0.0;
  G4int GeneratedSc=0;
  G4int GeneratedZnS=0;
  G4int Generated=0;
  G4int Scintillation=0;   
  G4int Cerenkov=0;
  float Deposit=0.0;
  G4bool VerbosityResults=false;




};


#endif
