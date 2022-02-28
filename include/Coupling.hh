/// Coupling.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

/*This class is used to create a Coupling with some glue.
GetModule() returns the logical volume containing all the components
*/

#ifndef Coupling_h
#define Coupling_h

#include "G4LogicalVolume.hh"
#include "G4MaterialPropertiesTable.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "CLHEP/Units/SystemOfUnits.h"

class TPSimMaterials;
class Scintillator;

class Coupling
{
public:


  Coupling();
  ~Coupling();
  void Construct();

public:


  G4LogicalVolume *GetBADGE_Coupling_Sc();
  G4LogicalVolume *GetBADGE_Coupling_PMT();
  G4LogicalVolume *GetSNMW_8InchesSphericalCoupling();

private:
  TPSimMaterials* scintProp;
  Scintillator *theScint;
  static const G4String path_bin;
  G4Material* Cargille;
  G4Material* grease;

  G4LogicalVolume *LogicalBADGE_Coupling_Sc;
  G4LogicalVolume *LogicalBADGE_Coupling_PMT;
  G4LogicalVolume *LogicalSNMW_8InchesCouplingSphere;

  G4double AirGapMylar;
  G4double GlueThickness;
  G4double PMTGlassRadius;
  G4double MylarThickness;
  G4double SNMW_CouplingSphereRadius;
  G4double SNMW_CouplingSphereDepth;



};
#endif
