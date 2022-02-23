/// Coupling.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr> 
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimMaterials.hh"
#include "Coupling.hh"
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
#include "G4Box.hh"
#include <G4Polycone.hh>
#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"

using namespace CLHEP;

const G4String Coupling::path_bin = "../bin/";

Coupling::Coupling(){}

Coupling::~Coupling(){
    if(scintProp) { delete scintProp; scintProp = 0; }
    if(Cargille) { delete Cargille; Cargille = 0; }
}




G4LogicalVolume *Coupling::GetBADGE_Coupling_Sc(){

  scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Cargille = scintProp->GetMaterial("cargille");
 				      
  // Define some rotations
  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0.0*deg);
  G4RotationMatrix Flip;
  Flip.rotateX(180.0*deg);


  //G4double ep_light_guide   =  1.000;     //en cm 
  G4double larg_scinti      =  12.000;    //en cm
  G4double long_scinti      =  8.500;     //en cm
  //G4double ep_scinti =  0.010;     //en cm [epaisseur scintillateur]
  G4double ep_remove_glue = 0.030;
  G4double ep_glue =  0.050;     //en cm => [epaisseur couplage optique sur coté du scintillateur]


  G4Box *Coupling_Sc = new G4Box   ("Coupling_Sc",                                               //its name
				    ep_glue/2*cm, (larg_scinti+0.2)/2*cm, (long_scinti+0.2)/2*cm);    //its size
  
  G4Box *Coupling_Remove = new G4Box   ("Coupling_Remove",		                                               //its name
					 ep_remove_glue/2*cm, larg_scinti/2*cm, long_scinti/2*cm);    //its size


  G4SubtractionSolid* Final_Coupling_Sc = new G4SubtractionSolid("Final_Coupling_Sc", 
							     Coupling_Sc,
							     Coupling_Remove,
							     G4Transform3D(DontRotate,G4ThreeVector(-0.01*cm, 0, 0)));  


  // Logical volume for FinalScint: material = scintillator
  LogicalBADGE_Coupling_Sc = new G4LogicalVolume(Final_Coupling_Sc, Cargille, "LogicalBADGE_Coupling_Sc",0,0,0);
  

  return LogicalBADGE_Coupling_Sc;  

  
}



G4LogicalVolume *Coupling::GetBADGE_Coupling_PMT(){

  scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Cargille = scintProp->GetMaterial("cargille");
 			      
  // Define some rotations
  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0.0*deg);
  G4RotationMatrix Flip;
  Flip.rotateX(180.0*deg);

  
  G4Box *Coupling_PMT = new G4Box   ("Coupling_PMT",                     //its name
				     (23)/2*mm, (32)/2*mm, 0.25*mm);    //its size


  // Logical volume for FinalScint: material = scintillator
  LogicalBADGE_Coupling_PMT = new G4LogicalVolume(Coupling_PMT, Cargille, "LogicalBADGE_Coupling_PMT",0,0,0);
  

  return LogicalBADGE_Coupling_PMT;  

  
}
