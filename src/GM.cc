// GM.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimMaterials.hh"
#include "GM.hh"
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
const G4String GM::path_bin = "../bin/";


GM::GM(G4String buildfile){

  // Read keys and values from file buildfile defined in x_blockGeometry.cc
  // Some of these variables may not be needed.
  // std::ifstream config;
  // config.open(buildfile);
  // if ( !config.is_open() )
  //   G4cout << "Error opening file " << buildfile << G4endl;
  // else{
  //   while( config.is_open() ){
  //     G4String variable;
  //     G4String unit;
  //     G4double value;

  //     config >> variable;
  //     if(!config.good()) break;
  //     //####################### COMMON variables ###########################
  //     if(variable == "TeflonThickness"){
  // 	config >> value >> unit;
  // 	TeflonThickness = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "AirGapTeflon"){
  // 	config >> value >> unit;
  // 	AirGapTeflon = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "MylarThickness"){
  // 	config >> value >> unit;
  // 	MylarThickness = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "AirGapMylar"){
  // 	config >> value >> unit;
  // 	AirGapMylar = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "GlueThickness"){
  // 	config >> value >> unit;
  // 	GlueThickness = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     // PMT 5 inches Dimensions
  //     else if(variable == "PMTGlassRadius"){
  // 	config >> value >> unit;
  // 	PMTGlassRadius = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "PMTGlassThickness"){
  // 	config >> value >> unit;
  // 	PMTGlassThickness = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "PMTRearGlassRadius"){
  // 	config >> value >> unit;
  // 	PMTRearGlassRadius = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "PMTPhotocathodeThickness"){
  // 	config >> value >> unit;
  // 	PMTPhotocathodeThickness = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "PMTGlassTubeRadius"){
  // 	config >> value >> unit;
  // 	PMTGlassTubeRadius = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "PMTGlassTubeHeight"){
  // 	config >> value >> unit;
  // 	PMTGlassTubeHeight = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     //####################### SuperNEMO Main Wall variables ###########################
  //     // Scint Block Dimensions
  //     else if (variable == "SNMW_ScintStepWidth"){
  // 	config >> value >> unit;
  // 	SNMW_ScintStepWidth = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "SNMW_ScintStepHeight"){
  // 	config >> value >> unit;
  // 	SNMW_ScintStepHeight = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "SNMW_ScintBodyWidth"){
  // 	config >> value >> unit;
  // 	SNMW_ScintBodyWidth = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "SNMW_ScintBodyHeight"){
  // 	config >> value >> unit;
  // 	SNMW_ScintBodyHeight = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "SNMW_CouplingSphereRadius"){
  // 	config >> value >> unit;
  // 	SNMW_CouplingSphereRadius = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "SNMW_CouplingSphereDepth"){
  // 	config >> value >> unit;
  // 	SNMW_CouplingSphereDepth = value*G4UnitDefinition::GetValueOf(unit);
  //     }

  //     //####################### NEMO 3 EC  variables ###########################
  //     // GM Dimensions
  //     else if(variable == "N3EC_ScintWidth"){
  // 	config >> value >> unit;
  // 	N3EC_ScintWidth = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "N3EC_ScintHeight"){
  // 	config >> value >> unit;
  // 	N3EC_ScintHeight = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     // Light Guide Dimensions
  //     else if(variable == "N3EC_LightGuideRadius"){
  // 	config >> value >> unit;
  // 	N3EC_LightGuideRadius = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "N3EC_LightGuideHeight"){
  // 	config >> value >> unit;
  // 	N3EC_LightGuideHeight = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "N3EC_LightGuideCouplingRadius"){
  // 	config >> value >> unit;
  // 	N3EC_LightGuideCouplingRadius = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "N3EC_LightGuideCouplingHeight"){
  // 	config >> value >> unit;
  // 	N3EC_LightGuideCouplingHeight = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "N3EC_CouplingSphereDepth"){
  // 	config >> value >> unit;
  // 	N3EC_CouplingSphereDepth = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "N3EC_InterfaceLightGuideHeight"){
  // 	config >> value >> unit;
  // 	N3EC_InterfaceLightGuideHeight = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "N3EC_LightGuideStepHeight"){
  // 	config >> value >> unit;
  // 	N3EC_LightGuideStepHeight = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "N3EC_CouplingSphereRadius"){
  // 	config >> value >> unit;
  // 	N3EC_CouplingSphereRadius = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     //####################### SuperNEMO XWALL  variables ###########################
  //     // GM Dimensions
  //     else if(variable == "SNXW_ScintWidth"){
  // 	config >> value >> unit;
  // 	SNXW_ScintWidth = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "SNXW_ScintHeight"){
  // 	config >> value >> unit;
  // 	SNXW_ScintHeight = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     // Light Guide Dimensions
  //     else if(variable == "SNXW_LightGuideRadius"){
  // 	config >> value >> unit;
  // 	SNXW_LightGuideRadius = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "SNXW_LightGuideHeight"){
  // 	config >> value >> unit;
  // 	SNXW_LightGuideHeight = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "SNXW_LightGuideCouplingHeight"){
  // 	config >> value >> unit;
  // 	SNXW_LightGuideCouplingHeight = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "SNXW_CouplingSphereDepth"){
  // 	config >> value >> unit;
  // 	SNXW_CouplingSphereDepth = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "SNXW_CouplingSphereRadius"){
  // 	config >> value >> unit;
  // 	SNXW_CouplingSphereRadius = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     //########################### N3MO3 L4  variables ###########################
  //     // GM Dimensions
  //     else if(variable == "N3L4_ScintLength"){
  // 	config >> value >> unit;
  // 	N3L4_ScintLength = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "N3L4_ScintWidth"){
  // 	config >> value >> unit;
  // 	N3L4_ScintWidth = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //     else if(variable == "N3L4_ScintHeight"){
  // 	config >> value >> unit;
  // 	N3L4_ScintHeight = value*G4UnitDefinition::GetValueOf(unit);
  //     }
  //   }
  // }
  // config.close();


  /*
    G4cout << "The Variables that we read in are: "
    << "\n SNMW_ScintStepWidth = " << SNMW_ScintStepWidth
    << "\n SNMW_ScintStepHeight = " << SNMW_ScintStepHeight
    << "\n SNMW_cintBodyWidth = " << SNMW_ScintBodyWidth
    << "\n SNMW_ScintBodyHeight = " << SNMW_ScintBodyHeight
    << "\n SNMW_CouplingSphereRadius = " << SNMW_CouplingSphereRadius
    << "\n SNMW_CouplingSphereDepth = " << SNMW_CouplingSphereDepth
    << "\n TeflonThickness = " << TeflonThickness
    << "\n AirGapTeflon = " << AirGapTeflon
    << "\n MylarThickness = " << MylarThickness
    << "\n AirGapMylar = " << AirGapMylar
    << "\n GlueThickness = " << GlueThickness
    << "\n PMTGlassRadius = " << PMTGlassRadius
    << "\n PMTRearGlassRadius = " << PMTRearGlassRadius
    << "\n PMTGlassThickness = " << PMTGlassThickness
    << "\n PMTPhotocathodeThickness = " << PMTPhotocathodeThickness
    << "\n PMTGlassTubeRadius = " << PMTGlassTubeRadius
    << "\n PMTGlassTubeHeight = " << PMTGlassTubeHeight
    << "\n N3EC_ScintWidth = " << N3EC_ScintWidth
    << "\n N3EC_ScintHeight = " << N3EC_ScintHeight
    << "\n N3EC_LightGuideRadius = " << N3EC_LightGuideRadius
    << "\n N3EC_LightGuideHeight = " << N3EC_LightGuideHeight
    << "\n N3EC_LightGuideCouplingRadius = " << N3EC_LightGuideCouplingRadius
    << "\n N3EC_LightGuideCouplingHeight = " << N3EC_LightGuideCouplingHeight
    << "\n N3EC_CouplingSphereDepth = " << N3EC_CouplingSphereDepth
    << "\n N3EC_InterfaceLightGuideHeight = " << N3EC_InterfaceLightGuideHeight
    << "\n N3EC_LightGuideStepHeight = " << N3EC_LightGuideStepHeight
    << "\n N3EC_CouplingSphereRadius = " << N3EC_CouplingSphereRadius
    << "\n SNXW_ScintWidth = " << SNXW_ScintWidth
    << "\n SNXW_ScintHeight = " << SNXW_ScintHeight
    << "\n SNXW_LightGuideRadius = " << SNXW_LightGuideRadius
    << "\n SNXW_LightGuideHeight = " << SNXW_LightGuideHeight
    << "\n SNXW_LightGuideCouplingHeight = " << SNXW_LightGuideCouplingHeight
    << "\n SNXW_CouplingSphereDepth = " << SNXW_CouplingSphereDepth
    << "\n SNXW_CouplingSphereRadius = " << SNXW_CouplingSphereRadius
    << "\n N3L4_ScintLength = " << N3L4_ScintLength
    << "\n N3L4_ScintWidth = " << N3L4_ScintWidth
    << "\n N3L4_ScintHeight = " << N3L4_ScintHeight << G4endl;
  */
}
// ***********************
// Destructor
// ***********************
GM::~GM(){
  if(scintProp) { delete scintProp; scintProp = 0; }
  if(Polystyrene) { delete Polystyrene; Polystyrene = 0; }
  if(coating) { delete coating; coating = 0; }
  if(Vacuum) { delete Vacuum; Vacuum = 0; }
  if(clear) { delete clear; clear = 0; }
}




G4LogicalVolume *GM::GetGM_LND(){
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


G4LogicalVolume *GM::GetGM_Filtre1(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Compensation = scintProp->GetMaterial("Compensation");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/GM_Dolphy_complet_Filtre_GM-1.gdml", false);
  LogicalGM_Filtre1 = parser->GetVolume("GM Dolphy complet - Filtre GM-1");
  LogicalGM_Filtre1->SetMaterial(Compensation);
#else
  //
#endif

  return LogicalGM_Filtre1;
}


G4LogicalVolume *GM::GetGM_Filtre3(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Compensation = scintProp->GetMaterial("Compensation");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/GM_Dolphy_complet_Filtre_GM-3.gdml", false);
  LogicalGM_Filtre3 = parser->GetVolume("GM Dolphy complet - Filtre GM-3");
  LogicalGM_Filtre3->SetMaterial(Compensation);
#else
  //
#endif

  return LogicalGM_Filtre3;
}



G4LogicalVolume *GM::GetGM_Rondelle(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  //Plastic = scintProp->GetMaterial("plastic");
  Nylon = scintProp->GetMaterial("Nylon");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/GM_Dolphy_complet_Rondelle_plastique-1.gdml", false);
  LogicalGM_Rondelle = parser->GetVolume("GM Dolphy complet - Rondelle plastique-1");
  LogicalGM_Rondelle->SetMaterial(Nylon);
#else
  //
#endif

  return LogicalGM_Rondelle;
}


G4LogicalVolume *GM::GetGM_Isolant(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Papier = scintProp->GetMaterial("Papier");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/GM_Dolphy_complet_Isolant_GM-2.gdml", false);
  LogicalGM_Isolant = parser->GetVolume("GM Dolphy complet - Isolant GM-2");
  LogicalGM_Isolant->SetMaterial(Papier);
#else
  //
#endif

  return LogicalGM_Isolant;
}



G4LogicalVolume *GM::GetGM_Gaine(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Polypropylene = scintProp->GetMaterial("Polypropylene");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/GM_Dolphy_complet_Gaine_de_l'ensemble.gdml", false);
  LogicalGM_Gaine = parser->GetVolume("GM Dolphy complet - Gaine de l'ensemble-1");
  LogicalGM_Gaine->SetMaterial(Polypropylene);
#else
  //
#endif

  return LogicalGM_Gaine;
}


G4LogicalVolume *GM::GetGM_Gaz(){
  // Material Properties for scint
  Air = scintProp->GetMaterial("Air");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/GM_Dolphy_complet_Volume_air_interne_GM-1.gdml", false);
  LogicalGM_Gaz = parser->GetVolume("GM Dolphy complet - Volume air interne GM-1");
  LogicalGM_Gaz->SetMaterial(Air);
#else
  //
  // G4Tubs *Tubs = new G4Tubs   ("Tubs",		                           //its name
  // 			    0*cm, 7.77/2.*mm, 26.5/2.*mm, 0*deg, 360*deg);    //its size


  // LogicalGM_Gaz = new G4LogicalVolume(Tubs, Air, "GM_Gaz",0,0,0);

#endif

  return LogicalGM_Gaz;
}



// G4LogicalVolume *GM::GetGM_Gaz(){
//   // Material Properties for scint
//   //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");

//   G4Tubs *Tubs = new G4Tubs   ("Tubs",		                           //its name
// 			    0*cm, 7.77/2.*mm, 26.5/2.*mm, 0*deg, 360*deg);    //its size


//   LogicalGM_Gaz = new G4LogicalVolume(Tubs, Air, "GM_Gaz",0,0,0);


//   return LogicalGM_Gaz;
// }



G4LogicalVolume *GM::GetGM_Plastique(){
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



G4LogicalVolume *GM::GetSIGAM_MF_GM(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Inox = scintProp->GetMaterial("Inox");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-GM_71-324.gdml", false);
  LogicalSIGAM_MF_GM = parser->GetVolume("SI-GAM MF - GM Moyen flux - Rev 08-2 GM LND 71-324-2");
  LogicalSIGAM_MF_GM->SetMaterial(Inox);
#else
  //
#endif

  return LogicalSIGAM_MF_GM;
}



G4LogicalVolume *GM::GetSIGAM_MF_GM_Anode(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-GM_cosse_anode.gdml", false);
  LogicalSIGAM_MF_GM_Anode = parser->GetVolume("SI-GAM MF - GM Moyen flux - Rev 08-2 cosse anode-4");
  LogicalSIGAM_MF_GM_Anode->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_MF_GM_Anode;
}



G4LogicalVolume *GM::GetSIGAM_MF_Gaz(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Air = scintProp->GetMaterial("Air");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-GAZ.gdml", false);
  LogicalSIGAM_MF_Gaz = parser->GetVolume("SI-GAM MF - GM Moyen flux - Rev 08-2 GAZ - GM LND 71-324-2");
  LogicalSIGAM_MF_Gaz->SetMaterial(Air);
#else
  //
#endif

  return LogicalSIGAM_MF_Gaz;
}



G4LogicalVolume *GM::GetSIGAM_MF_GM_Filtre1(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Compensation = scintProp->GetMaterial("Compensation");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Filtre1.gdml", false);
  LogicalSIGAM_MF_GM_Filtre1 = parser->GetVolume("SI-GAM MF - Filtre  GM  Moyen flux - Rev 08-1 Filtre GM-1");
  LogicalSIGAM_MF_GM_Filtre1->SetMaterial(Compensation);
#else
  //
#endif

  return LogicalSIGAM_MF_GM_Filtre1;
}


G4LogicalVolume *GM::GetSIGAM_MF_GM_Filtre2(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Compensation = scintProp->GetMaterial("Compensation");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Filtre2.gdml", false);
  LogicalSIGAM_MF_GM_Filtre2 = parser->GetVolume("SI-GAM MF - Filtre  GM  Moyen flux - Rev 08-1 Filtre GM-2");
  LogicalSIGAM_MF_GM_Filtre2->SetMaterial(Compensation);
#else
  //
#endif

  return LogicalSIGAM_MF_GM_Filtre2;
}



G4LogicalVolume *GM::GetSIGAM_MF_GM_Rondelle(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  //Plastic = scintProp->GetMaterial("plastic");
  Nylon = scintProp->GetMaterial("Nylon");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Filtre_Rondelle_plastique-1.gdml", false);
  LogicalSIGAM_MF_GM_Rondelle = parser->GetVolume("SI-GAM MF - Filtre  GM  Moyen flux - Rev 08-1 Rondelle plastique-1");
  LogicalSIGAM_MF_GM_Rondelle->SetMaterial(Nylon);
#else
  //
#endif

  return LogicalSIGAM_MF_GM_Rondelle;
}




G4LogicalVolume *GM::GetSIGAM_MF_GM_Isolant(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Papier = scintProp->GetMaterial("Papier");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Isolant_GM.gdml", false);
  LogicalSIGAM_MF_GM_Isolant = parser->GetVolume("SI-GAM MF - Filtre  GM  Moyen flux - Rev 08-1 Isolant GM-1");
  LogicalSIGAM_MF_GM_Isolant->SetMaterial(Papier);
#else
  //
#endif

  return LogicalSIGAM_MF_GM_Isolant;
}


G4LogicalVolume *GM::GetSIGAM_MF_Gaine(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Polypropylene = scintProp->GetMaterial("Polypropylene");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Gaine_ensemble.gdml", false);
  LogicalSIGAM_MF_Gaine = parser->GetVolume("SI-GAM MF - Filtre  GM  Moyen flux - Rev 08-1 Gaine de l'ensemble-1");
  LogicalSIGAM_MF_Gaine->SetMaterial(Polypropylene);
#else
  //
#endif

  return LogicalSIGAM_MF_Gaine;
}



G4LogicalVolume *GM::GetSIGAM_MF_GM_Gaine(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Polypropylene = scintProp->GetMaterial("Polypropylene");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Gaine_GM.gdml", false);
  LogicalSIGAM_MF_GM_Gaine = parser->GetVolume("SI-GAM MF - Gaine de maintient GM 713 - Rev 08-1");
  LogicalSIGAM_MF_GM_Gaine->SetMaterial(Polypropylene);
#else
  //
#endif

  return LogicalSIGAM_MF_GM_Gaine;
}


G4LogicalVolume *GM::GetSIGAM_MF_Corps_Cylindrique(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-corps_cylindrique.gdml", false);
  LogicalSIGAM_MF_Corps_Cylindrique = parser->GetVolume("SI-GAM MF - Sonde Moyen Flux corps cylindrique - Rev 08-2");
  LogicalSIGAM_MF_Corps_Cylindrique->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_MF_Corps_Cylindrique;
}


G4LogicalVolume *GM::GetSIGAM_MF_Bouchon_Cable(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Bouchon_Cable.gdml", false);
  LogicalSIGAM_MF_Bouchon_Cable = parser->GetVolume("SI-GAM MF - Bouchon coté Cable rev 08-1");
  LogicalSIGAM_MF_Bouchon_Cable->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_MF_Bouchon_Cable;
}



G4LogicalVolume *GM::GetSIGAM_MF_Carte_Fille(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Plastic = scintProp->GetMaterial("plastic");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Carte_Fille.gdml", false);
  LogicalSIGAM_MF_Carte_Fille = parser->GetVolume("SI-GAM MF - Carte Fille sans composants-1");
  LogicalSIGAM_MF_Carte_Fille->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalSIGAM_MF_Carte_Fille;
}


G4LogicalVolume *GM::GetSIGAM_MF_Connecteur(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Connecteur_4_broches_BINDER.gdml", false);
  LogicalSIGAM_MF_Connecteur = parser->GetVolume("SI-GAM MF - Connecteur 4 broches BINDER - Rev 08-1");
  LogicalSIGAM_MF_Connecteur->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_MF_Connecteur;
}



G4LogicalVolume *GM::GetSIGAM_MF_Hexnut(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-hex_nut_style.gdml", false);
  LogicalSIGAM_MF_Hexnut = parser->GetVolume("SI-GAM MF - hex nut style 1 gradeab_iso-1");
  LogicalSIGAM_MF_Hexnut->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_MF_Hexnut;
}


G4LogicalVolume *GM::GetSIGAM_MF_Joint1(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  teflon = scintProp->GetMaterial("teflon");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Joint1.gdml", false);
  LogicalSIGAM_MF_Joint1 = parser->GetVolume("SI-GAM MF - Joint JT4 25,12 x 1,78 ref 01_0600_0037 nbr- Rev 08-1");
  LogicalSIGAM_MF_Joint1->SetMaterial(teflon);
#else
  //
#endif

  return LogicalSIGAM_MF_Joint1;
}


G4LogicalVolume *GM::GetSIGAM_MF_Joint2(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  teflon = scintProp->GetMaterial("teflon");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Joint2.gdml", false);
  LogicalSIGAM_MF_Joint2 = parser->GetVolume("SI-GAM MF - Joint JT4 25,12 x 1,78 ref 01_0600_0037 nbr- Rev 08-2");
  LogicalSIGAM_MF_Joint2->SetMaterial(teflon);
#else
  //
#endif

  return LogicalSIGAM_MF_Joint2;
}



G4LogicalVolume *GM::GetSIGAM_MF_PCB(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Plastic = scintProp->GetMaterial("plastic");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-PCB.gdml", false);
  LogicalSIGAM_MF_PCB = parser->GetVolume("SI-GAM MF - PCB sans implantation - Rev 08-1");
  LogicalSIGAM_MF_PCB->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalSIGAM_MF_PCB;
}


G4LogicalVolume *GM::GetSIGAM_MF_Transfo(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Plastic = scintProp->GetMaterial("plastic");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Transfo.gdml", false);
  LogicalSIGAM_MF_Transfo = parser->GetVolume("SI-GAM MF - Transfo (corps)-2");
  LogicalSIGAM_MF_Transfo->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalSIGAM_MF_Transfo;
}



G4LogicalVolume *GM::GetSIGAM_MF_Pile(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Compensation = scintProp->GetMaterial("Compensation");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Pile_Bouton.gdml", false);
  LogicalSIGAM_MF_Pile = parser->GetVolume("SI-GAM MF - Pile Bouton CR1220-1");
  LogicalSIGAM_MF_Pile->SetMaterial(Compensation);
#else
  //
#endif

  return LogicalSIGAM_MF_Pile;
}



G4LogicalVolume *GM::GetSIGAM_MF_Mousse1(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  mousse = scintProp->GetMaterial("mousse");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Mousse1.gdml", false);
  LogicalSIGAM_MF_Mousse1 = parser->GetVolume("SI-GAM MF - Mousse de maintient - pièce 01-1");
  LogicalSIGAM_MF_Mousse1->SetMaterial(mousse);
#else
  //
#endif

  return LogicalSIGAM_MF_Mousse1;
}


G4LogicalVolume *GM::GetSIGAM_MF_Mousse2(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  mousse = scintProp->GetMaterial("mousse");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Mousse2.gdml", false);
  LogicalSIGAM_MF_Mousse2 = parser->GetVolume("SI-GAM MF - Mousse de maintient - pièce 02-1");
  LogicalSIGAM_MF_Mousse2->SetMaterial(mousse);
#else
  //
#endif

  return LogicalSIGAM_MF_Mousse2;
}


G4LogicalVolume *GM::GetSIGAM_MF_Socket1(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-socket1.gdml", false);
  LogicalSIGAM_MF_Socket1 = parser->GetVolume("SI-GAM MF - socket button head screw_iso-1");
  LogicalSIGAM_MF_Socket1->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_MF_Socket1;
}


G4LogicalVolume *GM::GetSIGAM_MF_Socket2(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-socket2.gdml", false);
  LogicalSIGAM_MF_Socket2 = parser->GetVolume("SI-GAM MF - socket head cap screw_din-2");
  LogicalSIGAM_MF_Socket2->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_MF_Socket2;
}


G4LogicalVolume *GM::GetSIGAM_MF_Socket3(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-socket3.gdml", false);
  LogicalSIGAM_MF_Socket3 = parser->GetVolume("SI-GAM MF - socket head cap screw_din-3");
  LogicalSIGAM_MF_Socket3->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_MF_Socket3;
}



G4LogicalVolume *GM::GetSIGAM_MF_Vis(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_MF/SI-GAM_MF-Vis.gdml", false);
  LogicalSIGAM_MF_Vis = parser->GetVolume("SI-GAM MF - Vis Tête Fraisée Din 7991 M1,6 x 3 - Rev 08-1");
  LogicalSIGAM_MF_Vis->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_MF_Vis;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_GM(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Inox = scintProp->GetMaterial("Inox");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-GM.gdml", false);
  LogicalSIGAM_HF_Carmelec_GM = parser->GetVolume("SI GAM HF -  - Montage GM LND 714-1 GM LND 714-2");
  LogicalSIGAM_HF_Carmelec_GM->SetMaterial(Inox);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_GM;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Filtre1(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Compensation = scintProp->GetMaterial("Compensation");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF_Filtre1.gdml", false);
  LogicalSIGAM_HF_Carmelec_Filtre1 = parser->GetVolume("SI GAM HF -  - Montage GM LND 714-1 Filtre GM LND 714-3");
  LogicalSIGAM_HF_Carmelec_Filtre1->SetMaterial(Compensation);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Filtre1;
}


 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Filtre2(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Compensation = scintProp->GetMaterial("Compensation");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Filtre2.gdml", false);
  LogicalSIGAM_HF_Carmelec_Filtre2 = parser->GetVolume("SI GAM HF -  - Montage GM LND 714-1 Filtre GM LND 714-4");
  LogicalSIGAM_HF_Carmelec_Filtre2->SetMaterial(Compensation);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Filtre2;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Rondelle(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Nylon = scintProp->GetMaterial("Nylon");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Rondelle.gdml", false);
  LogicalSIGAM_HF_Carmelec_Rondelle = parser->GetVolume("SI GAM HF -  - Montage GM LND 714-1 Bague PVC GM LND 714-2");
  LogicalSIGAM_HF_Carmelec_Rondelle->SetMaterial(Inox);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Rondelle;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Manchon(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Neoprene = scintProp->GetMaterial("Neoprene");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Manchon.gdml", false);
  LogicalSIGAM_HF_Carmelec_Manchon = parser->GetVolume("SI GAM HF -  - Montage GM LND 714-1 Manchon GM LND 714-2");
  LogicalSIGAM_HF_Carmelec_Manchon->SetMaterial(Neoprene);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Manchon;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Gaz(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Air = scintProp->GetMaterial("Air");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Gaz.gdml", false);
  LogicalSIGAM_HF_Carmelec_Gaz = parser->GetVolume("SI GAM HF -  - Montage GM LND 714-1 Volume Air GM LND 714-1");
  LogicalSIGAM_HF_Carmelec_Gaz->SetMaterial(Air);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Gaz;
}

 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Anode(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Anode.gdml", false);
  LogicalSIGAM_HF_Carmelec_Anode = parser->GetVolume("SI GAM HF -  - Montage GM LND 714-1 Cosse anode-1");
  LogicalSIGAM_HF_Carmelec_Anode->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Anode;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Calque(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Papier = scintProp->GetMaterial("Papier");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Calque.gdml", false);
  LogicalSIGAM_HF_Carmelec_Calque = parser->GetVolume("SI GAM HF -  - Montage GM LND 714-1 Calque GM LND 714-2");
  LogicalSIGAM_HF_Carmelec_Calque->SetMaterial(Papier);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Calque;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Bouchon_Cable(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Bouchon_Cable.gdml", false);
  LogicalSIGAM_HF_Carmelec_Bouchon_Cable = parser->GetVolume("SI GAM HF -  - Bouchon coté Cable rev 08-1");
  LogicalSIGAM_HF_Carmelec_Bouchon_Cable->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Bouchon_Cable;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Connecteur(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Connecteur.gdml", false);
  LogicalSIGAM_HF_Carmelec_Connecteur = parser->GetVolume("SI GAM HF -  - Connecteur 4 broches BINDER - Rev 08-1");
  LogicalSIGAM_HF_Carmelec_Connecteur->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Connecteur;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Corps_Cylindrique(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Corps_Cylindrique.gdml", false);
  LogicalSIGAM_HF_Carmelec_Corps_Cylindrique = parser->GetVolume("SI GAM HF -  - Sonde Sam Haut Flux corps cylindrique - Rev 08-1");
  LogicalSIGAM_HF_Carmelec_Corps_Cylindrique->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Corps_Cylindrique;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_PCB(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Plastic = scintProp->GetMaterial("plastic");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-PCB.gdml", false);
  LogicalSIGAM_HF_Carmelec_PCB = parser->GetVolume("SI GAM HF -  - PCB sans implantation - Rev 08-1");
  LogicalSIGAM_HF_Carmelec_PCB->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_PCB;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Transfo(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Plastic = scintProp->GetMaterial("plastic");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Transfo.gdml", false);
  LogicalSIGAM_HF_Carmelec_Transfo = parser->GetVolume("SI GAM HF -  - Transfo (corps)-1");
  LogicalSIGAM_HF_Carmelec_Transfo->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Transfo;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Socket1(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Socket1.gdml", false);
  LogicalSIGAM_HF_Carmelec_Socket1 = parser->GetVolume("SI GAM HF -  - socket button head screw_iso-1");
  LogicalSIGAM_HF_Carmelec_Socket1->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Socket1;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Socket2(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Socket2.gdml", false);
  LogicalSIGAM_HF_Carmelec_Socket2 = parser->GetVolume("SI GAM HF -  - socket head cap screw_din-1");
  LogicalSIGAM_HF_Carmelec_Socket2->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Socket2;
}


 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Socket3(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Socket3.gdml", false);
  LogicalSIGAM_HF_Carmelec_Socket3 = parser->GetVolume("SI GAM HF -  - socket head cap screw_din-2");
  LogicalSIGAM_HF_Carmelec_Socket3->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Socket3;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Hexnut(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Hexnut.gdml", false);
  LogicalSIGAM_HF_Carmelec_Hexnut = parser->GetVolume("SI GAM HF -  - hex nut style 1 gradeab_iso-3");
  LogicalSIGAM_HF_Carmelec_Hexnut->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Hexnut;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Joint1(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   teflon = scintProp->GetMaterial("teflon");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Joint1.gdml", false);
  LogicalSIGAM_HF_Carmelec_Joint1 = parser->GetVolume("SI GAM HF -  - Joint JT4 25,12 x 1,78 ref 01_0600_0037 nbr- Rev 08-1");
  LogicalSIGAM_HF_Carmelec_Joint1->SetMaterial(teflon);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Joint1;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Joint2(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   teflon = scintProp->GetMaterial("teflon");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Joint2.gdml", false);
  LogicalSIGAM_HF_Carmelec_Joint2 = parser->GetVolume("SI GAM HF -  - Joint JT4 25,12 x 1,78 ref 01_0600_0037 nbr- Rev 08-2");
  LogicalSIGAM_HF_Carmelec_Joint2->SetMaterial(teflon);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Joint2;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Carmelec_Vis(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF_Carmelec/SI GAM_HF-Vis.gdml", false);
  LogicalSIGAM_HF_Carmelec_Vis = parser->GetVolume("SI GAM HF -  - Vis Tête Fraisée Din 7991 M1,6 x 3 - Rev 08-1");
  LogicalSIGAM_HF_Carmelec_Vis->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_HF_Carmelec_Vis;
}



 G4LogicalVolume *GM::GetSIGAM_HF_GM(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Inox = scintProp->GetMaterial("Inox");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAM_GM_HF-GM.gdml", false);
  LogicalSIGAM_HF_GM = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - Assemblage GM LND 7149-2 GM LND 7149-2");
  LogicalSIGAM_HF_GM->SetMaterial(Inox);
#else
  //
#endif

  return LogicalSIGAM_HF_GM;
}


 G4LogicalVolume *GM::GetSIGAM_HF_Gaz(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Air = scintProp->GetMaterial("Air");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAM_GM_HF-Gaz.gdml", false);
  LogicalSIGAM_HF_Gaz = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - Assemblage GM LND 7149-2 Volume Air GM LND 7149-1");
  LogicalSIGAM_HF_Gaz->SetMaterial(Air);
#else
  //
#endif

  return LogicalSIGAM_HF_Gaz;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Compensation(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Compensation = scintProp->GetMaterial("Compensation");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAM_GM_HF-Compensation.gdml", false);
  LogicalSIGAM_HF_Compensation = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - Assemblage GM LND 7149-2 Compensation GM LND 7149-2");
  LogicalSIGAM_HF_Compensation->SetMaterial(Compensation);
#else
  //
#endif

  return LogicalSIGAM_HF_Compensation;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Rondelle(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Nylon = scintProp->GetMaterial("Nylon");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAM_GM_HF-Rondelle.gdml", false);
  LogicalSIGAM_HF_Rondelle = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - Assemblage GM LND 7149-2 Rondelle GM LND 7149-1");
  LogicalSIGAM_HF_Rondelle->SetMaterial(Nylon);
#else
  //
#endif

  return LogicalSIGAM_HF_Rondelle;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Manchon(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Neoprene = scintProp->GetMaterial("Neoprene");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAM_GM_HF-Manchon.gdml", false);
  LogicalSIGAM_HF_Manchon = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - Assemblage GM LND 7149-2 Manchon pour GM LND 7149-2");
  LogicalSIGAM_HF_Manchon->SetMaterial(Neoprene);
#else
  //
#endif

  return LogicalSIGAM_HF_Manchon;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Anode(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAMGM_HF- Anode.gdml", false);
  LogicalSIGAM_HF_Anode = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - Assemblage GM LND 7149-2 Cosse anode-1");
  LogicalSIGAM_HF_Anode->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_HF_Anode;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Corps_Cylindrique(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAM_GM_HF-Corps_Cylindrique.gdml", false);
  LogicalSIGAM_HF_Corps_Cylindrique = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - Sonde Sam Haut Flux corps cylindrique - Rev 08-1");
  LogicalSIGAM_HF_Corps_Cylindrique->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_HF_Corps_Cylindrique;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Bouchon_Cable(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAMGM_HF- Bouchon_Cable.gdml", false);
  LogicalSIGAM_HF_Bouchon_Cable = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - Bouchon coté Cable rev 08-1");
  LogicalSIGAM_HF_Bouchon_Cable->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_HF_Bouchon_Cable;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Joint1(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   teflon = scintProp->GetMaterial("teflon");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/SI_GAM_HF-Joint1.gdml", false);
  LogicalSIGAM_HF_Joint1 = parser->GetVolume("SI GAM HF - Joint JT4 25,12 x 1,78 ref 01_0600_0037 nbr- Rev 08-1");
  LogicalSIGAM_HF_Joint1->SetMaterial(teflon);
#else
  //
#endif

  return LogicalSIGAM_HF_Joint1;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Joint2(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   teflon = scintProp->GetMaterial("teflon");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/SI_GAM_HF-Joint2.gdml", false);
  LogicalSIGAM_HF_Joint2 = parser->GetVolume("SI GAM HF - Joint JT4 25,12 x 1,78 ref 01_0600_0037 nbr- Rev 08-2");
  LogicalSIGAM_HF_Joint2->SetMaterial(teflon);
#else
  //
#endif

  return LogicalSIGAM_HF_Joint2;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Connecteur(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAM_GM_HF-Connecteur.gdml", false);
  LogicalSIGAM_HF_Connecteur = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - Connecteur 4 broches BINDER - Rev 08-1");
  LogicalSIGAM_HF_Connecteur->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_HF_Connecteur;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Vis(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/SI_GAM_HF-Vis.gdml", false);
  LogicalSIGAM_HF_Vis = parser->GetVolume("SI GAM HF - Vis Tête Fraisée Din 7991 M1,6 x 3 - Rev 08-1");
  LogicalSIGAM_HF_Vis->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_HF_Vis;
}



 G4LogicalVolume *GM::GetSIGAM_HF_PCB(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Plastic = scintProp->GetMaterial("plastic");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAM_GM_HF-PCB.gdml", false);
  LogicalSIGAM_HF_PCB = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - PCB sans implantation - Rev 08-1");
  LogicalSIGAM_HF_PCB->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalSIGAM_HF_PCB;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Hexnut(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAM_GM_HF-Hexnut.gdml", false);
  LogicalSIGAM_HF_Hexnut = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - hex nut style 1 gradeab_iso-3");
  LogicalSIGAM_HF_Hexnut->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_HF_Hexnut;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Socket1(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAM_GM_HF-Socket1.gdml", false);
  LogicalSIGAM_HF_Socket1 = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - socket button head screw_iso-1");
  LogicalSIGAM_HF_Socket1->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_HF_Socket1;
}


 G4LogicalVolume *GM::GetSIGAM_HF_Socket2(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAM_GM_HF-Socket2.gdml", false);
  LogicalSIGAM_HF_Socket2 = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - socket head cap screw_din-1");
  LogicalSIGAM_HF_Socket2->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_HF_Socket2;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Socket3(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAM_GM_HF-Socket3.gdml", false);
  LogicalSIGAM_HF_Socket3 = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - socket head cap screw_din-2");
  LogicalSIGAM_HF_Socket3->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_HF_Socket3;
}



 G4LogicalVolume *GM::GetSIGAM_HF_Transfo(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Plastic = scintProp->GetMaterial("plastic");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_HF/Sonde_SAM_GM_HF-Transfo.gdml", false);
  LogicalSIGAM_HF_Transfo = parser->GetVolume("Sonde SAM GM HF GM 7149 - Rev 08 - Transfo (corps)-1");
  LogicalSIGAM_HF_Transfo->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalSIGAM_HF_Transfo;
}



 G4LogicalVolume *GM::GetSIGAM_BF_GM(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Inox = scintProp->GetMaterial("Inox");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-GM.gdml", false);
  LogicalSIGAM_BF_GM = parser->GetVolume("Sonde SAM BF - Rev 08 - - Assemblage GM LND 7128 - Rev 06-1 GM LND 7128 - Rev 06-1");
  LogicalSIGAM_BF_GM->SetMaterial(Inox);
#else
  //
#endif

  return LogicalSIGAM_BF_GM;
}


 G4LogicalVolume *GM::GetSIGAM_BF_Bague(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Nylon = scintProp->GetMaterial("Nylon");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Bague.gdml", false);
  LogicalSIGAM_BF_Bague = parser->GetVolume("Sonde SAM BF - Rev 08 - Assemblage GM LND 7128 - Rev 06-1 Bague - GM LND 7128 - Rev 06-1");
  LogicalSIGAM_BF_Bague->SetMaterial(Nylon);
#else
  //
#endif

  return LogicalSIGAM_BF_Bague;
}



 G4LogicalVolume *GM::GetSIGAM_BF_Compensation(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Compensation = scintProp->GetMaterial("Compensation");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Compensation.gdml", false);
  LogicalSIGAM_BF_Compensation = parser->GetVolume("Sonde SAM BF - Rev 08 - Assemblage GM LND 7128 - Rev 06-1 Compensation - GM LND 7128 - Rev 06-1");
  LogicalSIGAM_BF_Compensation->SetMaterial(Compensation);
#else
  //
#endif

  return LogicalSIGAM_BF_Compensation;
}



 G4LogicalVolume *GM::GetSIGAM_BF_Anode(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Anode.gdml", false);
  LogicalSIGAM_BF_Anode = parser->GetVolume("Sonde SAM BF - Rev 08 - Assemblage GM LND 7128 - Rev 06-1 Cosse anode - Rev 06-2");
  LogicalSIGAM_BF_Anode->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_BF_Anode;
}



 G4LogicalVolume *GM::GetSIGAM_BF_Gaz(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Air = scintProp->GetMaterial("Air");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Gaz.gdml", false);
  LogicalSIGAM_BF_Gaz = parser->GetVolume("Sonde SAM BF - Rev 08 - Assemblage GM LND 7128 - Rev 06-1 GAZ - GM LND 7128-1");
  LogicalSIGAM_BF_Gaz->SetMaterial(Air);
#else
  //
#endif

  return LogicalSIGAM_BF_Gaz;
}



 G4LogicalVolume *GM::GetSIGAM_BF_Manchon(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Neoprene = scintProp->GetMaterial("Neoprene");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Manchon.gdml", false);
  LogicalSIGAM_BF_Manchon = parser->GetVolume("Sonde SAM BF - Rev 08 - Assemblage GM LND 7128 - Rev 06-1 Manchon GM-1");
  LogicalSIGAM_BF_Manchon->SetMaterial(Neoprene);
#else
  //
#endif

  return LogicalSIGAM_BF_Manchon;
}



G4LogicalVolume *GM::GetSIGAM_BF_Gaine(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Polypropylene = scintProp->GetMaterial("Polypropylene");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Gaine.gdml", false);
  LogicalSIGAM_BF_Gaine = parser->GetVolume("Sonde SAM BF - Rev 08 - Gaine de maintient du GM - Rev 08-1");
  LogicalSIGAM_BF_Gaine->SetMaterial(Polypropylene);
#else
  //
#endif

  return LogicalSIGAM_BF_Gaine;
}



G4LogicalVolume *GM::GetSIGAM_BF_Mousse(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  mousse = scintProp->GetMaterial("mousse");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Mousse.gdml", false);
  LogicalSIGAM_BF_Mousse = parser->GetVolume("Sonde SAM BF - Rev 08 - Mousse de maintient du GM - Rev 08-1");
  LogicalSIGAM_BF_Mousse->SetMaterial(mousse);
#else
  //
#endif

  return LogicalSIGAM_BF_Mousse;
}



 G4LogicalVolume *GM::GetSIGAM_BF_Corps_Cylindrique(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Corps_Cylindrique.gdml", false);
  LogicalSIGAM_BF_Corps_Cylindrique = parser->GetVolume("Sonde SAM BF - Rev 08 - Sonde Sam Nano corps cylindrique - Rev 08-1");
  LogicalSIGAM_BF_Corps_Cylindrique->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_BF_Corps_Cylindrique;
}



 G4LogicalVolume *GM::GetSIGAM_BF_Bouchon_Cable(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Bouchon.gdml", false);
  LogicalSIGAM_BF_Bouchon_Cable = parser->GetVolume("Sonde SAM BF - Rev 08 - Bouchon coté Cable rev 08-1");
  LogicalSIGAM_BF_Bouchon_Cable->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_BF_Bouchon_Cable;
}



 G4LogicalVolume *GM::GetSIGAM_BF_Connecteur(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Connecteur.gdml", false);
  LogicalSIGAM_BF_Connecteur = parser->GetVolume("Sonde SAM BF - Rev 08 - Connecteur 4 broches BINDER - Rev 08-1");
  LogicalSIGAM_BF_Connecteur->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_BF_Connecteur;
}


G4LogicalVolume *GM::GetSIGAM_BF_Carte_Fille(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Plastic = scintProp->GetMaterial("plastic");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Carte_Fille.gdml", false);
  LogicalSIGAM_BF_Carte_Fille = parser->GetVolume("Sonde SAM BF - Rev 08 - Carte Fille sans composants-1");
  LogicalSIGAM_BF_Carte_Fille->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalSIGAM_BF_Carte_Fille;
}



 G4LogicalVolume *GM::GetSIGAM_BF_Transfo(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Plastic = scintProp->GetMaterial("plastic");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Transfo.gdml", false);
  LogicalSIGAM_BF_Transfo = parser->GetVolume("Sonde SAM BF - Rev 08 - Transfo (corps)-1");
  LogicalSIGAM_BF_Transfo->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalSIGAM_BF_Transfo;
}



 G4LogicalVolume *GM::GetSIGAM_BF_Joint1(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   teflon = scintProp->GetMaterial("teflon");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Joint1.gdml", false);
  LogicalSIGAM_BF_Joint1 = parser->GetVolume("Sonde SAM BF - Rev 08 - Joint JT4 25,12 x 1,78 ref 01_0600_0037 nbr- Rev 08-1");
  LogicalSIGAM_BF_Joint1->SetMaterial(teflon);
#else
  //
#endif

  return LogicalSIGAM_BF_Joint1;
}



 G4LogicalVolume *GM::GetSIGAM_BF_Joint2(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   teflon = scintProp->GetMaterial("teflon");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Joint2.gdml", false);
  LogicalSIGAM_BF_Joint2 = parser->GetVolume("Sonde SAM BF - Rev 08 - Joint JT4 25,12 x 1,78 ref 01_0600_0037 nbr- Rev 08-2");
  LogicalSIGAM_BF_Joint2->SetMaterial(teflon);
#else
  //
#endif

  return LogicalSIGAM_BF_Joint2;
}



 G4LogicalVolume *GM::GetSIGAM_BF_Socket1(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Socket1.gdml", false);
  LogicalSIGAM_BF_Socket1 = parser->GetVolume("Sonde SAM BF - Rev 08 - socket button head screw_iso-1");
  LogicalSIGAM_BF_Socket1->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_BF_Socket1;
}


 G4LogicalVolume *GM::GetSIGAM_BF_Socket2(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Socket2.gdml", false);
  LogicalSIGAM_BF_Socket2 = parser->GetVolume("Sonde SAM BF - Rev 08 - socket head cap screw_din-1");
  LogicalSIGAM_BF_Socket2->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_BF_Socket2;
}


 G4LogicalVolume *GM::GetSIGAM_BF_Socket3(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Socket3.gdml", false);
  LogicalSIGAM_BF_Socket3 = parser->GetVolume("Sonde SAM BF - Rev 08 - socket head cap screw_din-2");
  LogicalSIGAM_BF_Socket3->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_BF_Socket3;
}



 G4LogicalVolume *GM::GetSIGAM_BF_Hexnut(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Hexnut.gdml", false);
  LogicalSIGAM_BF_Hexnut = parser->GetVolume("Sonde SAM BF - Rev 08 - hex nut style 1 gradeab_iso-1");
  LogicalSIGAM_BF_Hexnut->SetMaterial(Alu_Coque_Cylindrique);
#else
  //
#endif

  return LogicalSIGAM_BF_Hexnut;
}



 G4LogicalVolume *GM::GetSIGAM_BF_PCB(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Plastic = scintProp->GetMaterial("plastic");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-PCB.gdml", false);
  LogicalSIGAM_BF_PCB = parser->GetVolume("Sonde SAM BF - Rev 08 - PCB sans implantation - Rev 08-1");
  LogicalSIGAM_BF_PCB->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalSIGAM_BF_PCB;
}



G4LogicalVolume *GM::GetSIGAM_BF_Pile(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Compensation = scintProp->GetMaterial("Compensation");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Pile.gdml", false);
  LogicalSIGAM_BF_Pile = parser->GetVolume("Sonde SAM BF - Rev 08 - Pile Bouton CR1220-2");
  LogicalSIGAM_BF_Pile->SetMaterial(Compensation);
#else
  //
#endif

  return LogicalSIGAM_BF_Pile;
}



 G4LogicalVolume *GM::GetSIGAM_BF_Vis(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_SI-GAM_BF/Sonde_SAM_BF-Vis.gdml", false);
  LogicalSIGAM_BF_Vis = parser->GetVolume("Sonde SAM BF - Rev 08 - Vis Tête Fraisée Din 7991 M1,6 x 3 - Rev 08-1");
  LogicalSIGAM_BF_Vis->SetMaterial(Alu);
#else
  //
#endif

  return LogicalSIGAM_BF_Vis;
}




 G4LogicalVolume *GM::GetDolphy_Anode(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Inox = scintProp->GetMaterial("Inox");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Anode.gdml", false);
  LogicalDolphy_Anode = parser->GetVolume("Dolphy Béta - Assemblage GM LND 7312-1 Anode GM LND 7312-1");
  LogicalDolphy_Anode->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Anode;
}




 G4LogicalVolume *GM::GetDolphy_GM(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Inox = scintProp->GetMaterial("Inox");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-GM.gdml", false);
  LogicalDolphy_GM = parser->GetVolume("Dolphy Béta - Assemblage GM LND 7312-1 GM LND 7312-1");
  LogicalDolphy_GM->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_GM;
}




 G4LogicalVolume *GM::GetDolphy_Membrane(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
  Mica = scintProp->GetMaterial("Mica");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Membrane.gdml", false);
  LogicalDolphy_Membrane = parser->GetVolume("Dolphy Béta - Assemblage GM LND 7312-1 Menbrane GM LND 7312-1");
  LogicalDolphy_Membrane->SetMaterial(Mica);
#else
  //
#endif

  return LogicalDolphy_Membrane;
}



 G4LogicalVolume *GM::GetDolphy_Gaz(){
  // Material Properties for scint
  //scintProp = new TPSimMaterials(path_bin+"Materials.cfg");
   Air = scintProp->GetMaterial("Air");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Gaz.gdml", false);
  LogicalDolphy_Gaz = parser->GetVolume("Dolphy Béta - Assemblage GM LND 7312-1 Gaz GM LND 7312-1");
  LogicalDolphy_Gaz->SetMaterial(Air);
#else
  //
#endif

  return LogicalDolphy_Gaz;
}



 G4LogicalVolume *GM::GetDolphy_Bague(){
  // Material Properties for scint
  Inox = scintProp->GetMaterial("Inox");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Bague.gdml", false);
  LogicalDolphy_Bague = parser->GetVolume("Dolphy Béta - Assemblage GM LND 7312-1 Bague Plastic GM LND 7312-1");
  LogicalDolphy_Bague->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Bague;
}




 G4LogicalVolume *GM::GetDolphy_Ampoule(){
  // Material Properties for scint
  Alu = scintProp->GetMaterial("Alu");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Ampoule.gdml", false);
  LogicalDolphy_Ampoule = parser->GetVolume("Dolphy Béta - Assemblage GM LND 7312-1 Vis Ampoule GM LND 7312-1");
  LogicalDolphy_Ampoule->SetMaterial(Alu);
#else
  //
#endif

  return LogicalDolphy_Ampoule;
}



 G4LogicalVolume *GM::GetDolphy_Circuit_Imprime(){
  // Material Properties for scint
  Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Circuit_imprime.gdml", false);
  LogicalDolphy_Circuit_Imprime = parser->GetVolume("Dolphy Béta - Circuit imprimé-1 BackLight-1");
  LogicalDolphy_Circuit_Imprime->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_Circuit_Imprime;
}



 G4LogicalVolume *GM::GetDolphy_Bouton_Poussoir(){
  // Material Properties for scint
  Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Bouton_poussoir.gdml", false);
  LogicalDolphy_Bouton_Poussoir = parser->GetVolume("Dolphy Béta - Circuit imprimé-1 Bouton poussoir-1");
  LogicalDolphy_Bouton_Poussoir->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_Bouton_Poussoir;
}



 G4LogicalVolume *GM::GetDolphy_Buzzer(){
  // Material Properties for scint
  Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Buzzer.gdml", false);
  LogicalDolphy_Buzzer = parser->GetVolume("Dolphy Béta - Circuit imprimé-1 Buzzer KPE-006-1");
  LogicalDolphy_Buzzer->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_Buzzer;
}



 G4LogicalVolume *GM::GetDolphy_CI(){
  // Material Properties for scint
  Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-CI.gdml", false);
  LogicalDolphy_CI = parser->GetVolume("Dolphy Béta - Circuit imprimé-1 CI-1");
  LogicalDolphy_CI->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_CI;
}



 G4LogicalVolume *GM::GetDolphy_Connecteur(){
  // Material Properties for scint
  Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Connecteur.gdml", false);
  LogicalDolphy_Connecteur = parser->GetVolume("Dolphy Béta - Circuit imprimé-1 Connecteur 6 broches-1");
  LogicalDolphy_Connecteur->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_Connecteur;
}



 G4LogicalVolume *GM::GetDolphy_Ecran(){
  // Material Properties for scint
  Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Ecran.gdml", false);
  LogicalDolphy_Ecran = parser->GetVolume("Dolphy Béta - Circuit imprimé-1 Ecran VI-502-DP-1");
  LogicalDolphy_Ecran->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_Ecran;
}



 G4LogicalVolume *GM::GetDolphy_Ecrou(){
  // Material Properties for scint
   Inox = scintProp->GetMaterial("Inox");
   Alu = scintProp->GetMaterial("Alu");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Ecrou.gdml", false);
  LogicalDolphy_Ecrou = parser->GetVolume("Dolphy Béta - Circuit imprimé-1 Ecrou 2mm-1");
  LogicalDolphy_Ecrou->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Ecrou;
 }



 G4LogicalVolume *GM::GetDolphy_Transfo(){
  // Material Properties for scint
  Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Transfo.gdml", false);
  LogicalDolphy_Transfo = parser->GetVolume("Dolphy Béta - Circuit imprimé-1 Transfo (corps)-1");
  LogicalDolphy_Transfo->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_Transfo;
 }



 G4LogicalVolume *GM::GetDolphy_Couvercle_Pile(){
  // Material Properties for scint
  Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Couvercle_pile.gdml", false);
  LogicalDolphy_Couvercle_Pile = parser->GetVolume("Dolphy Béta - Couvercle pile-1");
  LogicalDolphy_Couvercle_Pile->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_Couvercle_Pile;
 }



 G4LogicalVolume *GM::GetDolphy_Pile(){
  // Material Properties for scint
  Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Pile.gdml", false);
  LogicalDolphy_Pile = parser->GetVolume("Dolphy Béta - Pile 9V dimensions maximum selon norme-1");
  LogicalDolphy_Pile->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_Pile;
 }



 G4LogicalVolume *GM::GetDolphy_Dessous(){
  // Material Properties for scint
  Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Dessous.gdml", false);
  LogicalDolphy_Dessous = parser->GetVolume("Dolphy Béta - Dessous-1");
  LogicalDolphy_Dessous->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_Dessous;
 }



 G4LogicalVolume *GM::GetDolphy_Dessus(){
  // Material Properties for scint
  Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Dessus.gdml", false);
  LogicalDolphy_Dessus = parser->GetVolume("Dolphy Béta - Dessus-1");
  LogicalDolphy_Dessus->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_Dessus;
 }



 G4LogicalVolume *GM::GetDolphy_Fenetre(){
  // Material Properties for scint
  Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Fenetre.gdml", false);
  LogicalDolphy_Fenetre = parser->GetVolume("Dolphy Béta - Fenêtre-1");
  LogicalDolphy_Fenetre->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_Fenetre;
 }



 G4LogicalVolume *GM::GetDolphy_Grille(){
  // Material Properties for scint
   Inox = scintProp->GetMaterial("Inox");
   Alu = scintProp->GetMaterial("Alu");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Grille.gdml", false);
  LogicalDolphy_Grille = parser->GetVolume("Dolphy Béta - Grille-1");
  LogicalDolphy_Grille->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Grille;
 }



 G4LogicalVolume *GM::GetDolphy_Insert1(){
  // Material Properties for scint
   Inox = scintProp->GetMaterial("Inox");
   Alu = scintProp->GetMaterial("Alu");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Insert-1.gdml", false);
  LogicalDolphy_Insert1 = parser->GetVolume("Dolphy Béta - Insert-1");
  LogicalDolphy_Insert1->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Insert1;
 }



 G4LogicalVolume *GM::GetDolphy_Insert2(){
  // Material Properties for scint
   Inox = scintProp->GetMaterial("Inox");
   Alu = scintProp->GetMaterial("Alu");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Insert-2.gdml", false);
  LogicalDolphy_Insert2 = parser->GetVolume("Dolphy Béta - Insert-2");
  LogicalDolphy_Insert2->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Insert2;
 }



 G4LogicalVolume *GM::GetDolphy_Insert3(){
  // Material Properties for scint
   Inox = scintProp->GetMaterial("Inox");
   Alu = scintProp->GetMaterial("Alu");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Insert-3.gdml", false);
  LogicalDolphy_Insert3 = parser->GetVolume("Dolphy Béta - Insert-3");
  LogicalDolphy_Insert3->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Insert3;
 }



 G4LogicalVolume *GM::GetDolphy_Protection_Grille(){
  // Material Properties for scint
  Inox = scintProp->GetMaterial("Inox");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");
  Compensation = scintProp->GetMaterial("Compensation");
  Cuivre = scintProp->GetMaterial("Cuivre");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Protection_Grille.gdml", false);
  LogicalDolphy_Protection_Grille = parser->GetVolume("Dolphy Béta - Protection de grille-1");
  LogicalDolphy_Protection_Grille->SetMaterial(Inox);
  //LogicalDolphy_Protection_Grille->SetMaterial(Alu_Coque_Cylindrique);
  //LogicalDolphy_Protection_Grille->SetMaterial(Compensation);
  //LogicalDolphy_Protection_Grille->SetMaterial(Cuivre);
#else
  //
#endif

  return LogicalDolphy_Protection_Grille;
 }



 G4LogicalVolume *GM::GetDolphy_Filtre_H10(){
  // Material Properties for scint
  Inox = scintProp->GetMaterial("Inox");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");
  Compensation = scintProp->GetMaterial("Compensation");
  Cuivre = scintProp->GetMaterial("Cuivre");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Compensation_Inox.gdml", false);
  LogicalDolphy_Filtre_H10 = parser->GetVolume("Dolphy Béta - Compensation Inox - Rev 01-3");
  LogicalDolphy_Filtre_H10->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Filtre_H10;
 }




 G4LogicalVolume *GM::GetDolphy_Protection_Grille_Test(){
  // Material Properties for scint
  Inox = scintProp->GetMaterial("Inox");
  Alu_Coque_Cylindrique = scintProp->GetMaterial("Alu_Coque_SIGAM");
  Compensation = scintProp->GetMaterial("Compensation");
  Cuivre = scintProp->GetMaterial("Cuivre");
  Plomb_Antimoine = scintProp->GetMaterial("Plomb_Antimoine");

  G4Tubs *Grille = new G4Tubs   ("Grille",
				  0*cm, 3*cm, 0.5*mm, 0*deg, 360*deg);


  G4Tubs *Sub = new G4Tubs   ("Sub",
				  0*cm, 1.6*cm, 0.5*mm, 0*deg, 360*deg);


  G4ThreeVector Trans_NULL(0*mm, 0*mm, 0*mm);//
  G4RotationMatrix* noRot = new G4RotationMatrix(0.*deg,0.*deg,0.*deg);//

  G4SubtractionSolid* Grille_True = new G4SubtractionSolid("Grille_True",
  							  Grille,
  							  Sub,
  							  noRot,
  							  Trans_NULL);



  //LogicalDolphy_Protection_Grille = new G4LogicalVolume(Grille, Inox, "LogicalSc",0,0,0);
  //LogicalDolphy_Protection_Grille = new G4LogicalVolume(Grille_True, Inox, "LogicalSc",0,0,0);
  //LogicalDolphy_Protection_Grille = new G4LogicalVolume(Grille_True, Compensation, "LogicalSc",0,0,0);
  LogicalDolphy_Protection_Grille = new G4LogicalVolume(Grille_True, Plomb_Antimoine, "LogicalSc",0,0,0);


  return LogicalDolphy_Protection_Grille;
 }




 G4LogicalVolume *GM::GetDolphy_Rondelle_Protection(){
  // Material Properties for scint
  Nylon = scintProp->GetMaterial("Nylon");

  G4Tubs *Rondelle = new G4Tubs   ("Rondelle",
				  0*cm, 1.6*cm, 0.5*mm, 0*deg, 360*deg);



  LogicalDolphy_Rondelle_Protection = new G4LogicalVolume(Rondelle, Nylon, "LogicalSc",0,0,0);


  return LogicalDolphy_Rondelle_Protection;
 }



 G4LogicalVolume *GM::GetDolphy_Mousse_GM(){
  // Material Properties for scint
  mousse = scintProp->GetMaterial("mousse");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Mousse_GM.gdml", false);
  LogicalDolphy_Mousse_GM= parser->GetVolume("Dolphy Béta - Mousse GM-1");
  LogicalDolphy_Mousse_GM->SetMaterial(mousse);
#else
  //
#endif

  return LogicalDolphy_Mousse_GM;
 }



 G4LogicalVolume *GM::GetDolphy_Rondelle(){
  // Material Properties for scint
   Nylon = scintProp->GetMaterial("Nylon");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Rondelle.gdml", false);
  LogicalDolphy_Rondelle = parser->GetVolume("Dolphy Béta - Rondelle cuvette-2");
  LogicalDolphy_Rondelle->SetMaterial(Nylon);
#else
  //
#endif

  return LogicalDolphy_Rondelle;
 }



 G4LogicalVolume *GM::GetDolphy_Support_Ressort1 (){
  // Material Properties for scint
   Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Support_Ressort1.gdml", false);
  LogicalDolphy_Support_Ressort1 = parser->GetVolume("Dolphy Béta - Support de ressort  - 2018-3");
  LogicalDolphy_Support_Ressort1->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_Support_Ressort1;
 }



 G4LogicalVolume *GM::GetDolphy_Support_Ressort2(){
  // Material Properties for scint
   Plastic = scintProp->GetMaterial("plastic");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Support_Ressort2.gdml", false);
  LogicalDolphy_Support_Ressort2 = parser->GetVolume("Dolphy Béta - Support de ressort plat - 2018-3");
  LogicalDolphy_Support_Ressort2->SetMaterial(Plastic);
#else
  //
#endif

  return LogicalDolphy_Support_Ressort2;
 }


 G4LogicalVolume *GM::GetDolphy_Vis1(){
  // Material Properties for scint
   Alu = scintProp->GetMaterial("Alu");
   Inox = scintProp->GetMaterial("Inox");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Vis1.gdml", false);
  LogicalDolphy_Vis_1 = parser->GetVolume("Dolphy Béta - Circuit imprimé-1 Vis 12mm-1");
  LogicalDolphy_Vis_1->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Vis_1;
 }



 G4LogicalVolume *GM::GetDolphy_Vis2(){
  // Material Properties for scint
  Inox = scintProp->GetMaterial("Inox");
   Alu = scintProp->GetMaterial("Alu");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Vis2.gdml", false);
  LogicalDolphy_Vis_2 = parser->GetVolume("Dolphy Béta - Vis à tête fraisée-1");
  LogicalDolphy_Vis_2->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Vis_2;
 }



 G4LogicalVolume *GM::GetDolphy_Vis3(){
  // Material Properties for scint
   Alu = scintProp->GetMaterial("Alu");
   Inox = scintProp->GetMaterial("Inox");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Vis3.gdml", false);
  LogicalDolphy_Vis_3 = parser->GetVolume("Dolphy Béta - Vis à tête fraisée-2");
  LogicalDolphy_Vis_3->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Vis_3;
 }



 G4LogicalVolume *GM::GetDolphy_Vis4(){
  // Material Properties for scint
   Alu = scintProp->GetMaterial("Alu");
   Inox = scintProp->GetMaterial("Inox");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Vis4.gdml", false);
  LogicalDolphy_Vis_4 = parser->GetVolume("Dolphy Béta - Vis à tête fraisée-3");
  LogicalDolphy_Vis_4->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Vis_4;
 }



 G4LogicalVolume *GM::GetDolphy_Vis5(){
  // Material Properties for scint
   Alu = scintProp->GetMaterial("Alu");
   Inox = scintProp->GetMaterial("Inox");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Vis5.gdml", false);
  LogicalDolphy_Vis_5 = parser->GetVolume("Dolphy Béta - Vis à tête fraisée-4");
  LogicalDolphy_Vis_5->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Vis_5;
 }



 G4LogicalVolume *GM::GetDolphy_Vis6(){
  // Material Properties for scint
   Inox = scintProp->GetMaterial("Inox");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Vis6.gdml", false);
  LogicalDolphy_Vis_6 = parser->GetVolume("Dolphy Béta - Vis à tête plate-1");
  LogicalDolphy_Vis_6->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Vis_6;
 }



 G4LogicalVolume *GM::GetDolphy_Vis7(){
  // Material Properties for scint
   Inox = scintProp->GetMaterial("Inox");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Vis7.gdml", false);
  LogicalDolphy_Vis_7 = parser->GetVolume("Dolphy Béta - Vis à tête plate-2");
  LogicalDolphy_Vis_7->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Vis_7;
 }



 G4LogicalVolume *GM::GetDolphy_Vis8(){
  // Material Properties for scint
   Inox = scintProp->GetMaterial("Inox");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Vis8.gdml", false);
  LogicalDolphy_Vis_8 = parser->GetVolume("Dolphy Béta - Vis à tête plate-3");
  LogicalDolphy_Vis_8->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Vis_8;
 }



 G4LogicalVolume *GM::GetDolphy_Vis9(){
  // Material Properties for scint
   Inox = scintProp->GetMaterial("Inox");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Vis9.gdml", false);
  LogicalDolphy_Vis_9 = parser->GetVolume("Dolphy Béta - Vis à tole-1");
  LogicalDolphy_Vis_9->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Vis_9;
 }



 G4LogicalVolume *GM::GetDolphy_Vis10(){
  // Material Properties for scint
   Inox = scintProp->GetMaterial("Inox");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Vis10.gdml", false);
  LogicalDolphy_Vis_10 = parser->GetVolume("Dolphy Béta - Vis à tole-2");
  LogicalDolphy_Vis_10->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Vis_10;
 }



 G4LogicalVolume *GM::GetDolphy_Vis11(){
  // Material Properties for scint
   Inox = scintProp->GetMaterial("Inox");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Vis11.gdml", false);
  LogicalDolphy_Vis_11 = parser->GetVolume("Dolphy Béta - Vis à tole-3");
  LogicalDolphy_Vis_11->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Vis_11;
 }




 G4LogicalVolume *GM::GetDolphy_Vis12(){
  // Material Properties for scint
   Inox = scintProp->GetMaterial("Inox");


#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../GDML_Dolphy_béta/Dolphy_Beta-Vis12.gdml", false);
  LogicalDolphy_Vis_12 = parser->GetVolume("Dolphy Béta - Vis à tole-4");
  LogicalDolphy_Vis_12->SetMaterial(Inox);
#else
  //
#endif

  return LogicalDolphy_Vis_12;
 }
