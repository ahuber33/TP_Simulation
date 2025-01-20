/// TPSimSteppingAction.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#ifndef TPSimSteppingAction_h
#define TPSimSteppingAction_h

#include "G4UserSteppingAction.hh"
#include "CLHEP/Units/SystemOfUnits.h"
#include "G4OpBoundaryProcess.hh"
#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "G4ProcessManager.hh"
#include "G4Track.hh"
#include "TPSimEventAction.hh"
#include "TPSimGeometry.hh"
#include "TRandom3.h"

class G4Step;
class G4SteppingManager;
class PMT;

class TPSimSteppingAction : public G4UserSteppingAction
{
public:
  TPSimSteppingAction();
  ~TPSimSteppingAction();
public:
  void UserSteppingAction(const G4Step*);
  int Boundary;
  void Count(){Boundary++;}
  void PrintOpticalProperties(const G4Step*);
  void CheckAndPrintSurface(const G4Step*);
  void CheckBoundaryStatus(const G4Step*, TPSimEventAction*);
  void CountScintillation(const G4Step*, TPSimEventAction*);
  void CountCerenkov(const G4Step*, TPSimEventAction*);
  void SetPhotonBirthInformation(const G4Step*, TPSimEventAction*);
  void KillPhotonAngleCondition(const G4Step*,  TPSimEventAction*);
  void KillPhotonStuckCondition(const G4Step*,  TPSimEventAction*);
  void FillLensPosition(TPSimEventAction*);
  void FillExitFiberPosition(TPSimEventAction*);
  void SetInitialInformations(const G4Step*, TPSimEventAction*);
  void SetTPInformations(const G4Step*, TPSimEventAction*);


  void SetTheta (double e) { NRJ1 = e;};
  double GetTheta() {return NRJ1;}


private:
  G4Track* theTrack=nullptr;
  G4String partname;
  G4int partID=0;
  G4String endproc;
  G4int Parent_ID=0;
  G4int StepNo=0;
  float x=0.0;
  float xpre=0.0;
  float y=0.0;
  float z=0.0;
  float zpre=0.0;
  float px=0.0;
  float py=0.0;
  float pz=0.0;
  float r=0.0;
  float angle=0.0;
  G4String VolumeNamePreStep;
  G4String VolumeNamePostStep;
  float time=0.0;
  G4ThreeVector polarisation;

  G4GenericMessenger* sMessenger;
  static const G4String path;
  G4int PreviousTrack;
  float NRJ1;
  
  float Length_Track;
  float Total_Length_Track;
  float angle_azimutale;
  G4int VerbosityLevel=0;
  G4bool PhotonTrackStatus=true;

};
#endif
