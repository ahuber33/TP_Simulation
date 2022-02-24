/// Scintillator.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

// This class is used to create a plastic scintillator.

#ifndef Scintillator_h
#define Scintillator_h

#include "G4LogicalVolume.hh"
#include "G4MaterialPropertiesTable.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "CLHEP/Units/SystemOfUnits.h"

class TPSimMaterials;
class Scintillator

{
public:

  //constructor, builds from keys specified in buildfile
  Scintillator(G4String buildfile);
  ~Scintillator();
  //  void Construct();

public:

  // Functions to call this geometry in x_blockGeometry.cc

  G4LogicalVolume *GetScTest();
  G4LogicalVolume *GetGM_LND();
  G4LogicalVolume *GetGM_Plastique();



private:


  Scintillator *theScint;
  TPSimMaterials* scintProp;

  static const G4String path_bin;


  // Materials
  G4Material *scintillator;
  G4Material *Plastic;
  G4Material *Mylar;
  G4Material *Fer;
  G4Material *Polystyrene;
  G4Material *coating;
  G4Material *Vacuum;
  G4Material *PMMA;
  G4Material *Acier;
  G4Material *Inox;
  G4Material *N2;
  G4Material *Cuivre;
  G4Material *Kapton;
  G4Material *Air;
  G4Material *Polypropylene;
  G4Material *Papier;
  G4Material *Compensation;
  G4Material *Nylon;
  G4Material *Alu_Coque_Cylindrique;
  G4Material *Alu;
  G4Material *teflon;
  G4Material *mousse;
  G4Material *Neoprene;
  G4Material *Mica;
  G4Material *Plomb_Antimoine;

  // Logical Volumes
  G4LogicalVolume *LogicalScTest;
  G4LogicalVolume *LogicalGM_LND;
  G4LogicalVolume *LogicalGM_Plastique;


  G4double ScintillatorLength;
  G4double ScintillatorThickness;





  // Other
  G4VisAttributes *clear;

};
#endif
