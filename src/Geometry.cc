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
    }
  }
  config.close();



  G4cout << "\n The Variables that we read in are: "
  << "\n ScintillatorLength = " << ScintillatorLength
  << "\n ScintillatorThickness = " << ScintillatorThickness
  << "\n ZnSThickness = " << ZnSThickness
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
  << "\n " << G4endl;

}
// ***********************
// Destructor
// ***********************
Geometry::~Geometry(){
  if(scintProp) { delete scintProp; scintProp = 0; }
  if(clear) { delete clear; clear = 0; }
}


G4LogicalVolume *Geometry::GetScTest(){

  Material = scintProp->GetMaterial("scintillator");
  //Material = scintProp->GetMaterial("ZnS");

  //scintillator = scintProp->GetMaterial("Alu");

  G4Box *Box = new G4Box   ("Box",             //its name
  ScintillatorLength/2, ScintillatorLength/2, ScintillatorThickness/2);    //its size

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
  EF_Width_plates/2, L/2, EF_Length_plates/2);    //its size

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
  MF_Width_plates/2, L/2, MF_Length_plates/2);    //its size

  //G4Box *Box2 = new G4Box   ("Box2",             //its name
  //            (Width_plates+1)/2, Dist_between_plates/2, (Length_plates+1)/2);    //its size


  LogicalVolume = new G4LogicalVolume(Box1, Material, "VolumeEMPlates",0,0,0);

  return LogicalVolume;
}



G4LogicalVolume *Geometry::GetPinhole(){

  //Material = scintProp->GetMaterial("Carbon");
  Material = scintProp->GetMaterial("Plomb_Antimoine");

  G4Tubs *Tubs = new G4Tubs   ("Tubs",             //its name
  //0., (38.1/2)*mm, (38.1/2)*mm, 0, 360*deg);    //its size
  Pinhole_radius_int, Pinhole_radius_ext, Pinhole_thickness, 0, 360*deg);    //its size
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
  ScintillatorLength/2, ScintillatorLength/2, ZnSThickness/2);    //its size
  LogicalVolume = new G4LogicalVolume(Box, Material, "ZnS",0,0,0);

  return LogicalVolume;
}


G4LogicalVolume *Geometry::GetPhotocathode(){
  // Materials properties for PMT
  Material = scintProp->GetMaterial("Vacuum");

  G4Box *Box = new G4Box   ("Box",             //its name
  ScintillatorLength/2, ScintillatorLength/2, 0.1/2);    //its size
  LogicalVolume = new G4LogicalVolume(Box, Material, "Photocathode",0,0,0);

  return LogicalVolume;
}
