// Geometry.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimMaterials.hh"
#include "Geometry.hh"
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
const G4String Geometry::path_bin = "../bin/";


Geometry::Geometry(G4String buildfile){

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
      else if(variable == "ZnSThickness"){
        config >> value >> unit;
        ZnSThickness = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "ZnSLGThickness"){
        config >> value >> unit;
        ZnSLGThickness = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "DetectorLength"){
        config >> value >> unit;
        DetectorLength = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "DetectorWidth"){
        config >> value >> unit;
        DetectorWidth = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "DetectorThickness"){
        config >> value >> unit;
        DetectorThickness = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "LensThickness"){
        config >> value >> unit;
        LensThickness = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "LensTranslation"){
        config >> value >> unit;
        LensTranslation = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "DetectorTranslation"){
        config >> value >> unit;
        DetectorTranslation = value*G4UnitDefinition::GetValueOf(unit);
      }
      if(variable == "TeflonThickness"){
        config >> value >> unit;
        TeflonThickness = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "AirGapTeflon"){
        config >> value >> unit;
        AirGapTeflon = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "MylarThickness"){
        config >> value >> unit;
        MylarThickness = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "AirGapMylar"){
        config >> value >> unit;
        AirGapMylar = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "MylarThickness"){
        config >> value >> unit;
        MylarThickness = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "AirGapMylar"){
        config >> value >> unit;
        AirGapMylar = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "GlueThickness"){
        config >> value >> unit;
        GlueThickness = value*G4UnitDefinition::GetValueOf(unit);
      }
      // ElectricField Plates dimensions
      else if(variable == "EF_Value"){
        config >> value >> unit;
        EF_Value = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "EF_Dist_between_plates"){
        config >> value >> unit;
        EF_Dist_between_plates = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "EF_Thickness_plates"){
        config >> value >> unit;
        EF_Thickness_plates = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "EF_Length_plates"){
        config >> value >> unit;
        EF_Length_plates = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "EF_Width_plates"){
        config >> value >> unit;
        EF_Width_plates = value*G4UnitDefinition::GetValueOf(unit);
      }
      // MagneticField Plates dimensions
      else if(variable == "MF_Value"){
        config >> value >> unit;
        MF_Value = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "MF_Dist_between_plates"){
        config >> value >> unit;
        MF_Dist_between_plates = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "MF_Thickness_plates"){
        config >> value >> unit;
        MF_Thickness_plates = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "MF_Length_plates"){
        config >> value >> unit;
        MF_Length_plates = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "MF_Width_plates"){
        config >> value >> unit;
        MF_Width_plates = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "Pinhole_radius_ext"){
        config >> value >> unit;
        Pinhole_radius_ext = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "Pinhole_radius_int"){
        config >> value >> unit;
        Pinhole_radius_int = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "Pinhole_thickness"){
        config >> value >> unit;
        Pinhole_thickness = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "Dist_between_plates"){
        config >> value >> unit;
        Dist_between_plates = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "Dist_EFPlates_Detector"){
        config >> value >> unit;
        Dist_EFPlates_Detector = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "Dist_pinhole_MFPlates"){
        config >> value >> unit;
        Dist_pinhole_MFPlates = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "translation_pinhole"){
        config >> value >> unit;
        translation_pinhole = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "Fiber_geometry"){
        config >> value;
        Fiber_geometry = value;
      }
      else if(variable == "Fiber_multi_cladding"){
        config >> value;
        Fiber_multi_cladding = value;
      }
      else if(variable == "Fiber_number_per_line"){
        config >> value;
        Fiber_number_per_line = value;
      }
      else if(variable == "Fiber_space"){
        config >> value >> unit;
        Fiber_space = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "Fiber_width"){
        config >> value >> unit;
        Fiber_width = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "Fiber_cladding_ratio"){
        config >> value;
        Fiber_cladding_ratio = value;
      }
      else if(variable == "Fiber_length"){
        config >> value >> unit;
        Fiber_length = value*G4UnitDefinition::GetValueOf(unit);
      }
      else if(variable == "G4FAST"){
        config >> value;
        Activation_G4FAST = value;
      }
    }
  }
  config.close();



  G4cout << "\n The Variables that we read in are: "
  << "\n ScintillatorLength = " << ScintillatorLength
  << "\n ScintillatorThickness = " << ScintillatorThickness
  << "\n ZnSThickness = " << ZnSThickness
  << "\n DetectorLength = " << DetectorLength
  << "\n DetectorWidth = " << DetectorWidth
  << "\n DetectorThickness = " << DetectorThickness
  << "\n LensThickness = " << LensThickness
  << "\n DetectorTranslation = " << DetectorTranslation
  << "\n LensTranslation = " << LensTranslation
  << "\n Teflon thickness = " << TeflonThickness
  << "\n Air gap Teflon = " << AirGapTeflon
  << "\n Mylar thickness = " << MylarThickness
  << "\n Air gap Mylar = " << AirGapMylar
  << "\n Glue Thickness = " << GlueThickness
  << "\n EF Value = " << EF_Value
  << "\n EF Distance between plates = " << EF_Dist_between_plates
  << "\n EF Plates thickness = " << EF_Thickness_plates
  << "\n EF Plates length = " << EF_Length_plates
  << "\n EF Plates width = " << EF_Width_plates
  << "\n MF Value = " << MF_Value
  << "\n MF Distance between plates = " << MF_Dist_between_plates
  << "\n MF Plates thickness = " << MF_Thickness_plates
  << "\n MF Plates length = " << MF_Length_plates
  << "\n MF Plates width = " << MF_Width_plates
  << "\n Pinhole external radius = " << Pinhole_radius_ext
  << "\n Pinhole internal radius = " << Pinhole_radius_int
  << "\n Pinhole thickness = " << Pinhole_thickness
  << "\n Distance between plates = " << Dist_between_plates
  << "\n Distance EF Plates / Detector = " << Dist_EFPlates_Detector
  << "\n Distance pinhole / MF Plates = " << Dist_pinhole_MFPlates
  << "\n translation pinhole = " << translation_pinhole
  << "\n Fiber Geometry ? (0=round/1=square) = " << Fiber_geometry
  << "\n Fiber multi cladding activate ? = " << Fiber_multi_cladding
  << "\n Fiber number per line = " << Fiber_number_per_line
  << "\n Fiber space = " << Fiber_space
  << "\n Fiber width (diameter or length) = " << Fiber_width
  << "\n Fiber cladding ratio = " << Fiber_cladding_ratio
  << "\n Fiber length = " << Fiber_length
  << "\n Activation G4FAST = " << Activation_G4FAST
  << "\n " << G4endl;

}
// ***********************
// Destructor
// ***********************
Geometry::~Geometry(){
  if(scintProp) { delete scintProp; scintProp = 0; }
  if(clear) { delete clear; clear = 0; }
}

G4LogicalVolume *Geometry::GetRATP_Aimant1(){

  Material = scintProp->GetMaterial("Neodyme");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/aimant_1.gdml", false);
  LogicalVolume = parser->GetVolume("aimant_1");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}

G4LogicalVolume *Geometry::GetRATP_Aimant2(){

  Material = scintProp->GetMaterial("Neodyme");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/aimant_2.gdml", false);
  LogicalVolume = parser->GetVolume("aimant_2");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_CoteYokeAimant1(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/cote_YOKE_aimant_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("cote_YOKE_Aimant_RATP");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_CoteYokeAimant2(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/cote_YOKE_aimant_RATP_bis.gdml", false);
  LogicalVolume = parser->GetVolume("cote_YOKE_Aimant_RATP_bis");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_EntreeYokeAimant1(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/entree_YOKE_aimant_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("entree_YOKE_aimant_RATP");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}

G4LogicalVolume *Geometry::GetRATP_EntreeYokeAimant2(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/entree_YOKE_aimant_RATP_bis.gdml", false);
  LogicalVolume = parser->GetVolume("entree_YOKE_aimant_RATP_bis");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_FondYokeAimant1(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/fond_YOKE_aimant_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("Fond_YOKE_Aimant");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}

G4LogicalVolume *Geometry::GetRATP_FondYokeAimant2(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/fond_YOKE_aimant_RATP_bis.gdml", false);
  LogicalVolume = parser->GetVolume("Fond_YOKE_Aimant_bis");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}

G4LogicalVolume *Geometry::GetRATP_CaleYokeAimant(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/cale_YOKE_aimant_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("Cale_YOKE_Aimant");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_Electrode1(){

  Material = scintProp->GetMaterial("Fer");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/electrode_RATP_1.gdml", false);
  LogicalVolume = parser->GetVolume("Electrode1");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_Electrode2(){

  Material = scintProp->GetMaterial("Fer");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/electrode_RATP_2.gdml", false);
  LogicalVolume = parser->GetVolume("Electrode2");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_ColonneElectrode1(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/colonne_electrode_RATP_1.gdml", false);
  LogicalVolume = parser->GetVolume("Colonne_electrode1");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}

G4LogicalVolume *Geometry::GetRATP_ColonneElectrode2(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/colonne_electrode_RATP_2.gdml", false);
  LogicalVolume = parser->GetVolume("Colonne_electrode2");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}

G4LogicalVolume *Geometry::GetRATP_ColonneElectrode3(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/colonne_electrode_RATP_3.gdml", false);
  LogicalVolume = parser->GetVolume("Colonne_electrode3");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}

G4LogicalVolume *Geometry::GetRATP_ColonneElectrode4(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/colonne_electrode_RATP_4.gdml", false);
  LogicalVolume = parser->GetVolume("Colonne_electrode4");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_BaseElectrode1(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/base_electrode_RATP_1.gdml", false);
  LogicalVolume = parser->GetVolume("Base_electrode1");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}

G4LogicalVolume *Geometry::GetRATP_BaseElectrode2(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/base_electrode_RATP_2.gdml", false);
  LogicalVolume = parser->GetVolume("Base_electrode2");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}

G4LogicalVolume *Geometry::GetRATP_BaseElectrode3(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/base_electrode_RATP_3.gdml", false);
  LogicalVolume = parser->GetVolume("Base_electrode3");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}

G4LogicalVolume *Geometry::GetRATP_BaseElectrode4(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/base_electrode_RATP_4.gdml", false);
  LogicalVolume = parser->GetVolume("Base_electrode4");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_BaseBoite(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/base_boite_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("Base_boite");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_CapotBoite(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/capot_boite_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("Capot_boite");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_CoteBoite(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/cote_boite_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("Cote_boite");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_EntreeBoite(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/entree_boite_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("Entree_boite");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_SHV1(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/SHV_1.gdml", false);
  LogicalVolume = parser->GetVolume("SHV1");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_SHV2(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/SHV_2.gdml", false);
  LogicalVolume = parser->GetVolume("SHV2");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_SocleConnecteur(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/socle_connecteur_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("Socle_connecteur");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_BaseBoiteDetecteur(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/base_boite_detecteur_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("Base_boite_detecteur");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_EntreeBoiteDetecteur(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/entree_boite_detecteur_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("Entree_boite_detecteur");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_SortieBoiteDetecteur(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/sortie_boite_detecteur_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("Sortie_boite_detecteur");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_MontageIP(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/montage_IP_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("Montage_IP");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_CoteBoiteDetecteur1(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/cote_boite_detecteur_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("Cote_boite_detecteur1");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_CoteBoiteDetecteur2(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/cote_boite_detecteur_RATP_bis.gdml", false);
  LogicalVolume = parser->GetVolume("Cote_boite_detecteur2");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_CouvercleBoiteDetecteur(){

  Material = scintProp->GetMaterial("Alu");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/couvercle_boite_detecteur_RATP.gdml", false);
  LogicalVolume = parser->GetVolume("Couvercle_boite_detecteur");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRATP_PlaquePb(){

  Material = scintProp->GetMaterial("Plomb");

  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/RATP/Pb_Plate.gdml", false);
  LogicalVolume = parser->GetVolume("Pb_Plate");
  LogicalVolume->SetMaterial(Material);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRoundObjective(){

  Material = scintProp->GetMaterial("Silicium");

  G4Tubs *Tubs = new G4Tubs   ("Tubs",             //its name
  0., (40/2)*mm, (DetectorThickness/2)*mm, 0, 360*deg);    //its size

  LogicalVolume = new G4LogicalVolume(Tubs, Material, "Photocathode",0,0,0);

  return LogicalVolume;
}



G4LogicalVolume *Geometry::GetCoreRoundFiber(){

  Material = scintProp->GetMaterial("EJ212");

  G4Tubs *Tubs= NULL;

  if(Fiber_multi_cladding==0)
  {
    Tubs = new G4Tubs   ("Tubs",             //its name
    0, (Fiber_width-2*Fiber_cladding_ratio*Fiber_width)/2, Fiber_length/2, 0, 360*deg);    //its size
  }


  if(Fiber_multi_cladding==1)
  {
    Tubs = new G4Tubs   ("Tubs",             //its name
    0, (Fiber_width-4*Fiber_cladding_ratio*Fiber_width)/2, Fiber_length/2, 0, 360*deg);    //its size
  }

  LogicalVolume = new G4LogicalVolume(Tubs, Material, "Core_Round_Fiber",0,0,0);

  return LogicalVolume;
}

G4LogicalVolume *Geometry::GetInnerCladdingRoundFiber(){

  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0*deg);

  Material = scintProp->GetMaterial("PMMA");

  G4Tubs *Tubs= NULL;

  if(Fiber_multi_cladding==0)
  {
    Tubs = new G4Tubs   ("Tubs",             //its name
    (Fiber_width-2*Fiber_cladding_ratio*Fiber_width)/2, Fiber_width/2, Fiber_length/2, 0, 360*deg);    //its size
  }


  if(Fiber_multi_cladding==1)
  {
    Tubs = new G4Tubs   ("Tubs",             //its name
    (Fiber_width-4*Fiber_cladding_ratio*Fiber_width)/2, (Fiber_width-2*Fiber_cladding_ratio*Fiber_width)/2, Fiber_length/2, 0, 360*deg);    //its size
    //0, (Fiber_width-2*Fiber_cladding_ratio*Fiber_width)/2, Fiber_length/2, 0, 360*deg);    //its size
  }

  LogicalVolume = new G4LogicalVolume(Tubs, Material, "Inner_Cladding_Round_Fiber",0,0,0);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetOuterCladdingRoundFiber(){

  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0*deg);

  Material = scintProp->GetMaterial("FP");


  G4Tubs* Tubs = new G4Tubs   ("Tubs",             //its name
  //(Fiber_width-2*Fiber_cladding_ratio*Fiber_width)/2, (Fiber_width)/2, Fiber_length/2, 0, 360*deg);    //its size
  (Fiber_width-2*Fiber_cladding_ratio*Fiber_width)/2, (Fiber_width)/2, Fiber_length/2, 0, 360*deg);    //its size


  LogicalVolume = new G4LogicalVolume(Tubs, Material, "Outer_Cladding_Round_Fiber",0,0,0);

  return LogicalVolume;
}



G4LogicalVolume *Geometry::GetCoreSquareFiber(){

  Material = scintProp->GetMaterial("EJ212");

  G4Box *Box = new G4Box   ("Box",             //its name
  (Fiber_width-2*Fiber_cladding_ratio*Fiber_width)/2, (Fiber_width-2*Fiber_cladding_ratio*Fiber_width)/2, Fiber_length/2);    //its size

  LogicalVolume = new G4LogicalVolume(Box, Material, "Core_Square_Fiber",0,0,0);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetCladdingSquareFiber(){

  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0*deg);

  Material = scintProp->GetMaterial("PMMA");

  G4Box *Box1 = new G4Box   ("Box1",             //its name
  Fiber_width/2, Fiber_width/2, Fiber_length/2);    //its size

  G4Box *Box2 = new G4Box   ("Box2",             //its name
  (Fiber_width-2*Fiber_cladding_ratio*Fiber_width)/2, (Fiber_width-2*Fiber_cladding_ratio*Fiber_width)/2, Fiber_length/2);    //its size

  G4SubtractionSolid* Box = new G4SubtractionSolid("Box", Box1, Box2, G4Transform3D(DontRotate,G4ThreeVector(0,0,0.0)));

  LogicalVolume = new G4LogicalVolume(Box, Material, "Cladding_Square_Fiber",0,0,0);

  return LogicalVolume;
}

G4LogicalVolume *Geometry::GetScTest(){

  Material = scintProp->GetMaterial("EJ212");
  //  Material = scintProp->GetMaterial("YAG");
  //Material = scintProp->GetMaterial("ZnS");

  //scintillator = scintProp->GetMaterial("Alu");

  G4Box *Box = new G4Box   ("Box",             //its name
  //ScintillatorLength/2, 100./2, ScintillatorThickness/2);    //its size
  ScintillatorThickness/2, 58/2*mm, ScintillatorLength/2);

  LogicalVolume = new G4LogicalVolume(Box, Material, "Sc_Test",0,0,0);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetEFPlates(){

  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0*deg);

  Material = scintProp->GetMaterial("Alu");

  float L = EF_Dist_between_plates +2*EF_Thickness_plates;

  G4Box *Box1 = new G4Box   ("Box1",             //its name
  EF_Width_plates/2, L/2, EF_Length_plates/2);    //its size

  G4Box *Box2 = new G4Box   ("Box2",             //its name
  (EF_Width_plates+1)/2, EF_Dist_between_plates/2, (EF_Length_plates+1)/2);    //its size

  G4SubtractionSolid* Box = new G4SubtractionSolid("Box", Box1, Box2, G4Transform3D(DontRotate,G4ThreeVector(0,0,0.0)));

  LogicalVolume = new G4LogicalVolume(Box, Material, "EMPlates",0,0,0);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetVolumeEFPlates(){

  Material = scintProp->GetMaterial("Vacuum");

  float L = EF_Dist_between_plates +2*EF_Thickness_plates;

  G4Box *Box1 = new G4Box   ("Box1",             //its name
  EF_Length_plates/2, EF_Dist_between_plates/2, EF_Width_plates/2);
  //EF_Width_plates/2, L/2, EF_Length_plates/2);    //its size

  //G4Box *Box2 = new G4Box   ("Box2",             //its name
  //            (Width_plates+1)/2, Dist_between_plates/2, (Length_plates+1)/2);    //its size


  LogicalVolume = new G4LogicalVolume(Box1, Material, "VolumeEMPlates",0,0,0);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetMFPlates(){

  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0*deg);

  Material = scintProp->GetMaterial("Alu");

  float L = MF_Dist_between_plates +2*MF_Thickness_plates;

  G4Box *Box1 = new G4Box   ("Box1",             //its name
  MF_Width_plates/2, L/2, MF_Length_plates/2);    //its size

  G4Box *Box2 = new G4Box   ("Box2",             //its name
  (MF_Width_plates+1)/2, MF_Dist_between_plates/2, (MF_Length_plates+1)/2);    //its size

  G4SubtractionSolid* Box = new G4SubtractionSolid("Box", Box1, Box2, G4Transform3D(DontRotate,G4ThreeVector(0,0,0.0)));

  LogicalVolume = new G4LogicalVolume(Box, Material, "EMPlates",0,0,0);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetVolumeMFPlates(){

  Material = scintProp->GetMaterial("Vacuum");

  float L = MF_Dist_between_plates +2*MF_Thickness_plates;

  G4Box *Box1 = new G4Box   ("Box1",             //its name
  MF_Length_plates/2, MF_Dist_between_plates/2, MF_Width_plates/2);
  //MF_Width_plates/2, L/2, MF_Length_plates/2);    //its size

  //G4Box *Box2 = new G4Box   ("Box2",             //its name
  //            (Width_plates+1)/2, Dist_between_plates/2, (Length_plates+1)/2);    //its size


  LogicalVolume = new G4LogicalVolume(Box1, Material, "VolumeEMPlates",0,0,0);

  return LogicalVolume;
}



G4LogicalVolume *Geometry::GetPinhole(){

  //Material = scintProp->GetMaterial("Carbon");
  Material = scintProp->GetMaterial("Plomb");

  G4Tubs *Tubs = new G4Tubs   ("Tubs",             //its name
  //0., (38.1/2)*mm, (38.1/2)*mm, 0, 360*deg);    //its size
  Pinhole_radius_int, Pinhole_radius_ext, Pinhole_thickness/2, 0, 360*deg);    //its size
  LogicalVolume = new G4LogicalVolume(Tubs, Material, "Pinhole",0,0,0);

  return LogicalVolume;
}




G4LogicalVolume *Geometry::GetLaBr3(){

  Material = scintProp->GetMaterial("LaBr3");

  G4Tubs *Tubs = new G4Tubs   ("Tubs",             //its name
  //0., (38.1/2)*mm, (38.1/2)*mm, 0, 360*deg);    //its size
  0., (38.1/2)*mm, (38.1/2)*mm, 0, 360*deg);    //its size
  LogicalVolume = new G4LogicalVolume(Tubs, Material, "LaBr3",0,0,0);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetZnS(){

  Material = scintProp->GetMaterial("ZnS");

  G4Box *Box = new G4Box   ("Box",             //its name
  ZnSThickness/2, 60/2, ScintillatorLength/2);    //its size
  LogicalVolume = new G4LogicalVolume(Box, Material, "ZnS",0,0,0);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetZnSLG(){

  Material = scintProp->GetMaterial("PMMA");

  G4Box *Box = new G4Box   ("Box",             //its name
  ScintillatorLength/2, 60/2, ZnSLGThickness/2);    //its size
  LogicalVolume = new G4LogicalVolume(Box, Material, "PMMA",0,0,0);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetPhotocathode(){
  // Materials properties for PMT
  //Material = scintProp->GetMaterial("Vacuum");
  Material = scintProp->GetMaterial("Silicium");

  G4Box *Box = new G4Box   ("Box",             //its name
  ScintillatorLength/2, 60/2, DetectorThickness/2);    //its size
  //(Fiber_number_per_line*Fiber_width + (Fiber_number_per_line+1)*Fiber_space)/2, (Fiber_number_per_line*Fiber_width + (Fiber_number_per_line+1)*Fiber_space)/2, DetectorThickness/2);    //its size
  //DetectorLength/2, DetectorWidth/2, DetectorThickness/2);    //its size

  LogicalVolume = new G4LogicalVolume(Box, Material, "Photocathode",0,0,0);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetRoundPhotocathode(){

  Material = scintProp->GetMaterial("Silicium");

  G4Tubs *Tubs = new G4Tubs   ("Tubs",             //its name
  0., (75/2)*mm, (0.1/2)*mm, 0, 360*deg);    //its size

  LogicalVolume = new G4LogicalVolume(Tubs, Material, "Photocathode",0,0,0);

  return LogicalVolume;
}

G4LogicalVolume *Geometry::GetLens(){

  Material = scintProp->GetMaterial("lens_glass");

#ifndef disable_gdm
  //G4NistManager* nist = G4NistManager::Instance();
  G4GDMLParser* parser = new G4GDMLParser();
  //Create Tesselated volume of "Bouchon"
  parser->Clear();
  parser->Read("../gdml_models/LA1002-Step.gdml", false);
  LogicalVolume = parser->GetVolume("LA1002-Step");
  LogicalVolume->SetMaterial(Material);
#else
  //
#endif

  return LogicalVolume;
}
