/// TPSimActionInitialization.hh
//// Auteur: Arnaud HUBER for ENL group <huber@lp2ib.in2p3.fr>
//// Copyright: 2024 (C) Projet PALLAS

#ifndef TPSimActionInitialization_h
#define TPSimActionInitialization_h 1

#include "G4VUserActionInitialization.hh"
#include "globals.hh"
#include "TPSimPrimaryGeneratorAction.hh"
#include "TPSimRunAction.hh"
#include "TPSimEventAction.hh"
#include "TPSimSteppingAction.hh"
#include "TPSimGeometry.hh"
#include "G4MTRunManager.hh"
#include "TPSimTrackingAction.hh"


class TPSimGeometryConstruction;
class TPSimPrimaryGeneratorAction;

class TPSimActionInitialization : public G4VUserActionInitialization
{
public:
  TPSimActionInitialization(const char*, G4bool pMT);
  virtual ~TPSimActionInitialization();
  size_t charToSizeT(G4String str);

  virtual void BuildForMaster() const;
  virtual void Build() const;
  char* NEvents;
  G4String suffixe;
  G4bool flag_MT=false;
  
};

#endif