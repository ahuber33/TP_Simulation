/// TPSimStackingAction.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr> 
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA


#include "LXeStackingAction.hh"

#include "LXeEventAction.hh"

#include "G4OpticalPhoton.hh"
#include "G4Track.hh"
#include "G4VProcess.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

TPSimStackingAction::TPSimStackingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4ClassificationOfNewTrack LXeStackingAction::ClassifyNewTrack(
  const G4Track* aTrack)
{
  // Count what process generated the optical photons
  if(aTrack->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition())
  {
    // particle is optical photon
    if(aTrack->GetParentID() > 0)
    {
      // particle is secondary
      if(aTrack->GetCreatorProcess()->GetProcessName() == "Scintillation")
      {
        G4Track* theTrack=(G4Track*)aTrack;
	    theTrack->SetUserInformation(new TPSimTrackInformation(aTrack));
      }
      else if(aTrack->GetCreatorProcess()->GetProcessName() == "Cerenkov")
      {
        G4Track* theTrack=(G4Track*)aTrack;
	    theTrack->SetUserInformation(new TPSimTrackInformation(aTrack));
      }
    }
  }
  return fUrgent;
}
