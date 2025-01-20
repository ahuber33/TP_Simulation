/// TPSimRunAction.cc
//// Auteur: Arnaud HUBER for ENL group <huber@lp2ib.in2p3.fr>
//// Copyright: 2024 (C) Projet PALLAS

#include "TPSimActionInitialization.hh"
#include "TPSimPrimaryGeneratorAction.hh"
#include "TPSimRunAction.hh"
#include "TPSimEventAction.hh"
#include "TPSimSteppingAction.hh"
#include "TPSimGeometry.hh"
#include "G4MTRunManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

TPSimActionInitialization::TPSimActionInitialization(const char *suff, G4bool pMT)
    : G4VUserActionInitialization(), 
      suffixe(suff),
      flag_MT(pMT)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

TPSimActionInitialization::~TPSimActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void TPSimActionInitialization::BuildForMaster() const
{
    // Action pour le processus maître (uniquement utile en mode multithreading)
    SetUserAction(new TPSimRunAction(suffixe, flag_MT));
    G4cout << "Build Master" << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void TPSimActionInitialization::Build() const
{
    // Création et affectation des actions pour la simulation
    auto *runAction = new TPSimRunAction(suffixe, flag_MT);
    auto *eventAction = new TPSimEventAction(suffixe);
    
    // Assigner les actions utilisateur
    SetUserAction(new TPSimPrimaryGeneratorAction());
    SetUserAction(runAction);
    SetUserAction(eventAction);
    SetUserAction(new TPSimSteppingAction());
    //SetUserAction(new TPSimTrackingAction());
}