//// TPSimMagneticfield.cc
//// Auteur: Arnaud HUBER for ENL group <huber@lp2ib.in2p3.fr>
//// Copyright: 2024 (C) Projet PALLAS

#include "TPSimMagneticField.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

TPSimMagneticField::TPSimMagneticField()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

TPSimMagneticField::~TPSimMagneticField()
{
}


void TPSimMagneticField::GetFieldValue(const G4double point[4], double *bField) const
{

  double x = point[0];
  double y = point[1];
  double z = point[2];

  if (StatusMapBField == true)
  {
    
  }

  else
  {  
    bField[0] = 0.0;
    bField[1] = ConstantDipoleBField;
    bField[2] = 0.0;
  }

  // G4cout << "\n\n\nBField value = " << ConstantBField << G4endl;
  // G4cout << "y = " << y << G4endl;
  // G4cout << "z = " << z << G4endl;
  // G4cout << "B= " << bField[0] << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void TPSimMagneticField::SetDipoleField(G4double fieldValue)
{
  ConstantDipoleBField = fieldValue;
  // G4cout << "SETFIELD FONCTION : " << ConstantDipoleBField << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void TPSimMagneticField::SetMapBFieldStatus(G4bool status)
{
  StatusMapBField = status;
  // G4cout << "SETSTATUS MAP BFIELD : " << StatusMapBField << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
