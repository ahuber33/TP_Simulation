/// PMT.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr> 
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimMaterials.hh"
#include "PMT.hh"
#include "Scintillator.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4ThreeVector.hh"
#include "G4VisAttributes.hh"
#include "G4Transform3D.hh"
#include <fstream>
#include <iostream>
#include "G4Tubs.hh"
#include "G4UnitsTable.hh"
#include "G4Sphere.hh"
#include <G4Polycone.hh>
#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"

using namespace CLHEP;

const G4String PMT::path_bin = "../bin/";

// ***********************
// Constructor
// ***********************
PMT::PMT(){}
// ***********************
// Destructor
// ***********************
PMT::~PMT(){
  if(scintProp) { delete scintProp; scintProp = 0; }
  if(Vacuum) { delete Vacuum; Vacuum = 0; }
  if(Borosilicate_Glass) { delete Borosilicate_Glass; Borosilicate_Glass = 0; }
  if(theScint) { delete theScint; theScint = 0; }
}


G4LogicalVolume *PMT::GetBADGE_PMTGlass(){
  // Materials properties for PMT
  Borosilicate_Glass = scintProp->GetMaterial("bs_glass");

  // Define some rotations
  G4RotationMatrix Rotate;
  Rotate.rotateX(180.0*deg);
  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0.0*deg);


  // ####################### PMT GLASS TUBE SOLID #######################
  // Solid PMT photocathode sphere
  G4int N_z_plane = 7;
  G4double Phi_start = 0.*deg;
  G4double Phi_end = 2*180*deg;
  
  
  const G4double z_plane[] = {0*mm, 0.5*mm, 1.*mm, 71*mm, 74*mm, 84*mm, 85*mm};
  
  const G4double r_inner[]= {0/2*mm, 0/2*mm, 37.7/2*mm, 37.7/2*mm, 32/2*mm, 31/2*mm, 0/2*mm};

  const G4double r_outer[]= {38/2*mm, 38.7/2*mm, 38.7/2*mm, 38.7/2*mm, 33/2*mm, 32/2*mm, 30/2*mm};

  G4Polycone *PMTGlass = new G4Polycone("PMTGlass",
  			Phi_start,
  			Phi_end,
  			N_z_plane,
  			z_plane,
  			r_inner,
  			r_outer);  


  // Logical PMT tube:  material borosilicate glass
  LogicalPMTGlass = new G4LogicalVolume(PMTGlass, Borosilicate_Glass,"LogicalPMTGlass",0,0,0);
  
  
  return LogicalPMTGlass;
}




G4LogicalVolume *PMT::GetBADGE_Photocathode(){
  // Materials properties for PMT
  Vacuum = scintProp->GetMaterial("Vacuum");

  // Define some rotations
  G4RotationMatrix Rotate;
  Rotate.rotateX(180.0*deg);
  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0.0*deg);


  // ####################### PMT GLASS TUBE SOLID #######################
  // Solid PMT photocathode sphere
  G4int N_z_plane = 3;
  G4double Phi_start = 0.*deg;
  G4double Phi_end = 2*180*deg;
  
  
  const G4double z_plane[] = {0*mm, 0.5*mm, 1.*mm};
  
  const G4double r_inner[]= {0/2*mm, 0/2*mm, 37.7/2*mm};

  const G4double r_outer[]= {38/2*mm, 38.7/2*mm, 38.7/2*mm};

  G4Polycone *Photocathode = new G4Polycone("Photocathode",
					Phi_start,
					Phi_end,
					N_z_plane,
					z_plane,
					r_inner,
					r_outer);  


  LogicalPhotocathode = new G4LogicalVolume(Photocathode, Vacuum,"LogicalPhotocathode",0,0,0);
  
  
  return LogicalPhotocathode;
}
