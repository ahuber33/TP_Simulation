#include "TPSimTrackingAction.hh"
#include "G4Track.hh"
#include "TPSimTrackInformation.hh"
#include "G4TrackingManager.hh"
#include "G4EventManager.hh"

TPSimTrackingAction::TPSimTrackingAction() {}
TPSimTrackingAction::~TPSimTrackingAction() {}

void TPSimTrackingAction::PreUserTrackingAction(const G4Track* aTrack) {
    G4String partname = aTrack->GetDefinition()->GetParticleName();

    // Si c'est un photon optique et qu'il n'a pas d'information utilisateur attachée
    if (partname == "opticalphoton" && aTrack->GetUserInformation() == nullptr) {
        const G4VProcess* creatorProcess = aTrack->GetCreatorProcess();
        if (creatorProcess) {
            G4String processName = creatorProcess->GetProcessName();
            if (processName == "Scintillation" || processName == "Cerenkov") {
                // Assurez-vous que l'objet est bien attaché
                G4Track* theTrack = const_cast<G4Track*>(aTrack);
                if (theTrack->GetUserInformation() == nullptr) {
                    // Attacher une nouvelle information utilisateur
                    // TPSimTrackInformation::threadSpecificTrackInfo = new TPSimTrackInformation(aTrack);
                    // theTrack->SetUserInformation(TPSimTrackInformation::threadSpecificTrackInfo);
                }
            }
        }
    }
}

void TPSimTrackingAction::PostUserTrackingAction(const G4Track* aTrack) {
    G4String partname = aTrack->GetDefinition()->GetParticleName();

    if (partname == "opticalphoton") {
        G4TrackVector* secondaries = fpTrackingManager->GimmeSecondaries();
        if (secondaries) {
            size_t nSeco = secondaries->size();
            for (size_t i = 0; i < nSeco; i++) {
                if ((*secondaries)[i]->GetUserInformation() == nullptr) {
                    // Attacher la nouvelle information utilisateur spécifique au thread
                    //(*secondaries)[i]->SetUserInformation(TPSimTrackInformation::threadSpecificTrackInfo);
                }
            }
        }
    }
}
