// Scintillator.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimMaterials.hh"
#include "Scintillator.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4ThreeVector.hh"
#include "G4VisAttributes.hh"
#include "G4Transform3D.hh"
#include "G4UnionSolid.hh"
#include <fstream>
#include <iostream>
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4Polyhedra.hh"
#include <G4Polycone.hh>
#include "G4Sphere.hh"
#include "G4Trap.hh"
#include "G4Trd.hh"
#include "G4SubtractionSolid.hh"
#include "G4PVPlacement.hh"
#include "G4UnitsTable.hh"
#include <math.h>

//#ifndef disable_gdml
#include "G4GDMLParser.hh"
//#endif


using namespace CLHEP;

// ***********************
// Constructor
// ***********************
const G4String Scintillator::path_bin = "../bin/";


Scintillator::Scintillator(G4String buildfile){

  // Read keys and values from file buildfile defined in x_blockGeometry.cc
  // Some of these variables may not be needed.
  std::ifstream config;
  config.open(buildfile);
  if ( !config.is_open() )
    G4cout << "Error opening file " << buildfile << G4endl;
  else{
    while( config.is_open() ){
      G4String variable;
      G4String unit;
      G4double value;

      config >> variable;
      if(!config.good()) break;
      //####################### COMMON variables ###########################
      if(variable == "ScintillatorLength"){
  	config >> value >> unit;
  	ScintillatorLength = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "ScintillatorThickness"){
  	config >> value >> unit;
  	ScintillatorThickness = value*G4UnitDefinition::GetValueOf(unit);
      }
    //   else if(variable == "MylarThickness"){
  	// config >> value >> unit;
  	// MylarThickness = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "AirGapMylar"){
  	// config >> value >> unit;
  	// AirGapMylar = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "GlueThickness"){
  	// config >> value >> unit;
  	// GlueThickness = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   // PMT 5 inches Dimensions
    //   else if(variable == "PMTGlassRadius"){
  	// config >> value >> unit;
  	// PMTGlassRadius = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "PMTGlassThickness"){
  	// config >> value >> unit;
  	// PMTGlassThickness = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "PMTRearGlassRadius"){
  	// config >> value >> unit;
  	// PMTRearGlassRadius = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "PMTPhotocathodeThickness"){
  	// config >> value >> unit;
  	// PMTPhotocathodeThickness = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "PMTGlassTubeRadius"){
  	// config >> value >> unit;
  	// PMTGlassTubeRadius = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "PMTGlassTubeHeight"){
  	// config >> value >> unit;
  	// PMTGlassTubeHeight = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   //####################### SuperNEMO Main Wall variables ###########################
    //   // Scint Block Dimensions
    //   else if (variable == "SNMW_ScintStepWidth"){
  	// config >> value >> unit;
  	// SNMW_ScintStepWidth = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "SNMW_ScintStepHeight"){
  	// config >> value >> unit;
  	// SNMW_ScintStepHeight = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "SNMW_ScintBodyWidth"){
  	// config >> value >> unit;
  	// SNMW_ScintBodyWidth = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "SNMW_ScintBodyHeight"){
  	// config >> value >> unit;
  	// SNMW_ScintBodyHeight = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "SNMW_CouplingSphereRadius"){
  	// config >> value >> unit;
  	// SNMW_CouplingSphereRadius = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "SNMW_CouplingSphereDepth"){
  	// config >> value >> unit;
  	// SNMW_CouplingSphereDepth = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //
    //   //####################### NEMO 3 EC  variables ###########################
    //   // GM Dimensions
    //   else if(variable == "N3EC_ScintWidth"){
  	// config >> value >> unit;
  	// N3EC_ScintWidth = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "N3EC_ScintHeight"){
  	// config >> value >> unit;
  	// N3EC_ScintHeight = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   // Light Guide Dimensions
    //   else if(variable == "N3EC_LightGuideRadius"){
  	// config >> value >> unit;
  	// N3EC_LightGuideRadius = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "N3EC_LightGuideHeight"){
  	// config >> value >> unit;
  	// N3EC_LightGuideHeight = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "N3EC_LightGuideCouplingRadius"){
  	// config >> value >> unit;
  	// N3EC_LightGuideCouplingRadius = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "N3EC_LightGuideCouplingHeight"){
  	// config >> value >> unit;
  	// N3EC_LightGuideCouplingHeight = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "N3EC_CouplingSphereDepth"){
  	// config >> value >> unit;
  	// N3EC_CouplingSphereDepth = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "N3EC_InterfaceLightGuideHeight"){
  	// config >> value >> unit;
  	// N3EC_InterfaceLightGuideHeight = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "N3EC_LightGuideStepHeight"){
  	// config >> value >> unit;
  	// N3EC_LightGuideStepHeight = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "N3EC_CouplingSphereRadius"){
  	// config >> value >> unit;
  	// N3EC_CouplingSphereRadius = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   //####################### SuperNEMO XWALL  variables ###########################
    //   // GM Dimensions
    //   else if(variable == "SNXW_ScintWidth"){
  	// config >> value >> unit;
  	// SNXW_ScintWidth = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "SNXW_ScintHeight"){
  	// config >> value >> unit;
  	// SNXW_ScintHeight = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   // Light Guide Dimensions
    //   else if(variable == "SNXW_LightGuideRadius"){
  	// config >> value >> unit;
  	// SNXW_LightGuideRadius = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "SNXW_LightGuideHeight"){
  	// config >> value >> unit;
  	// SNXW_LightGuideHeight = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "SNXW_LightGuideCouplingHeight"){
  	// config >> value >> unit;
  	// SNXW_LightGuideCouplingHeight = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "SNXW_CouplingSphereDepth"){
  	// config >> value >> unit;
  	// SNXW_CouplingSphereDepth = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "SNXW_CouplingSphereRadius"){
  	// config >> value >> unit;
  	// SNXW_CouplingSphereRadius = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   //########################### N3MO3 L4  variables ###########################
    //   // GM Dimensions
    //   else if(variable == "N3L4_ScintLength"){
  	// config >> value >> unit;
  	// N3L4_ScintLength = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "N3L4_ScintWidth"){
  	// config >> value >> unit;
  	// N3L4_ScintWidth = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    //   else if(variable == "N3L4_ScintHeight"){
  	// config >> value >> unit;
  	// N3L4_ScintHeight = value*G4UnitDefinition::GetValueOf(unit);
    //   }
    }
  }
  config.close();



    G4cout << "\n The Variables that we read in are: "
    << "\n ScintillatorLength = " << ScintillatorLength
    << "\n ScintillatorThickness = " << ScintillatorThickness
    << "\n " << G4endl;

}
// ***********************
// Destructor
// ***********************
Scintillator::~Scintillator(){
  if(scintProp) { delete scintProp; scintProp = 0; }
  if(Polystyrene) { delete Polystyrene; Polystyrene = 0; }
  if(coating) { delete coating; coating = 0; }
  if(Vacuum) { delete Vacuum; Vacuum = 0; }
  if(clear) { delete clear; clear = 0; }
}


G4LogicalVolume *Scintillator::GetScTest(){

  scintillator = scintProp->GetMaterial("scintillator");
  //scintillator = scintProp->GetMaterial("Alu");

  G4Box *Box = new G4Box   ("Box",             //its name
  			    ScintillatorLength/2, ScintillatorLength/2, ScintillatorThickness/2);    //its size

  LogicalScTest = new G4LogicalVolume(Box, scintillator, "Sc_Test",0,0,0);

  return LogicalScTest;
}




G4LogicalVolume *Scintillator::GetGM_LND(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Inox = scintProp->GetMaterial("Inox");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/GM_Dolphy_complet_GM_LND_71-324.gdml", false);
  LogicalGM_LND = parser->GetVolume("GM Dolphy complet - GM LND 71-324-1");
  LogicalGM_LND->SetMaterial(Inox);
#else
  //
#endif

  return LogicalGM_LND;
}



// G4LogicalVolume *GM::GetGM_Gaz(){
//   // Material Properties for scint
//   //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");

//   G4Tubs *Tubs = new G4Tubs   ("Tubs",		                           //its name
// 			    0*cm, 7.77/2.*mm, 26.5/2.*mm, 0*deg, 360*deg);    //its size


//   LogicalGM_Gaz = new G4LogicalVolume(Tubs, Air, "GM_Gaz",0,0,0);


//   return LogicalGM_Gaz;
// }



G4LogicalVolume *Scintillator::GetGM_Plastique(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Plastic = scintProp->GetMaterial("plastic");

  // G4Box *Box = new G4Box   ("Box",             //its name
  // 			    2.25/2.*cm, 6.5/2.*cm, 0.3/2.*cm);    //its size


  G4Box *Box_FULL = new G4Box   ("Box_FULL",             //its name
  			    2.25/2.*cm, 6.5/2.*cm, 11.8/2.*cm);    //its size

  G4Box *Box_SUB = new G4Box   ("Box_SUB",             //its name
  			    (2.25-0.6)/2.*cm, (6.5-0.6)/2.*cm, (11.8-0.6)/2.*cm);    //its size

  G4ThreeVector Trans_NULL(0*mm, 0*mm, 0*mm);//
  G4RotationMatrix* noRot = new G4RotationMatrix(0.*deg,0.*deg,0.*deg);//

  G4SubtractionSolid* Box = new G4SubtractionSolid("Box",
  							  Box_FULL,
  							  Box_SUB,
  							  noRot,
  							  Trans_NULL);



  LogicalGM_Plastique = new G4LogicalVolume(Box, Plastic, "GM_Plastique",0,0,0);

  return LogicalGM_Plastique;
}
