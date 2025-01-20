/// TPSimMaterials.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

// This class is used to create a plastic scintillator.

#ifndef TPSimMaterials_h
#define TPSimMaterials_h

#include "G4MaterialPropertiesTable.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4OpticalSurface.hh"
#include "CLHEP/Units/SystemOfUnits.h"
#include "G4MaterialTable.hh"
#include "G4MaterialPropertyVector.hh"
#include <fstream>
#include <iostream>

class G4Material;

class TPSimMaterials
{
public:
  static TPSimMaterials *getInstance();
  virtual ~TPSimMaterials();

  G4Material *getMaterial(const char *);
  void printMaterialProperties(const char *);
  void printMaterialProperties(G4Material *material);

protected:
  TPSimMaterials();

private:
  static const G4String path;

  std::vector<G4Material *> fMaterialsList;
  static TPSimMaterials *fgInstance;
  G4double wavelengthNmToEnergy(G4double wavelength);
  G4double energyToWavelangthNm(G4double energy);
  const G4int TAB_COLUMN_1 = 25;
  const G4int TAB_COLUMN = 10;

  G4double var;
  G4double pWavelength;
  G4String filler;
  G4String file;
  std::ifstream Read;
  std::ifstream Readabsorb;
  std::ifstream Readindex;
  std::ifstream Readscatt;
  std::vector<G4double> Emission_Energy;
  std::vector<G4double> Emission_Ratio;
  std::vector<G4double> Absorption_Energy;
  std::vector<G4double> Absorption_Long;
  std::vector<G4double> Index_Energy;
  std::vector<G4double> Index_Value;
  std::vector<G4double> Scatt_Energy;
  std::vector<G4double> Scatt_Long;

  G4double Res = 0.0;
  G4double Fastconst = 0.0;
  G4double Slowconst = 0.0;

  G4double lightyield = 0.0;
  G4double lightyieldZnS = 0.0;
};
#endif
