/// Geometry.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

// This class is used to create a plastic Geometry.

#ifndef Geometry_h
#define Geometry_h

#include "G4LogicalVolume.hh"
#include "G4Tubs.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Polyhedra.hh"
#include <G4Polycone.hh>
#include "G4Sphere.hh"
#include "G4Trap.hh"
#include "G4Trd.hh"
#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"
#include "G4UnitsTable.hh"

//#ifndef disable_gdml
#include "G4GDMLParser.hh"
//#endif

//class TPSimMaterials;
class Geometry

{
public:

  //constructor, builds from keys specified in buildfile
  Geometry(G4String buildfile);
  ~Geometry();
  //  void Construct();

public:

  // Functions to call this geometry in x_blockGeometry.cc
  G4LogicalVolume *GetGDMLVolume(const char*, const char*, G4Material*);
  G4LogicalVolume *GetCoreRoundFiber(G4Material*);
  G4LogicalVolume *GetInnerCladdingRoundFiber(G4Material*);
  G4LogicalVolume *GetOuterCladdingRoundFiber(G4Material*);
  G4LogicalVolume *GetCoreSquareFiber(G4Material*);
  G4LogicalVolume *GetCladdingSquareFiber(G4Material*);
  G4LogicalVolume *GetScintillator(G4Material*);
  G4LogicalVolume *GetEFPlates(G4Material*);
  G4LogicalVolume *GetVolumeEFPlates(G4Material*);
  G4LogicalVolume *GetMFPlates(G4Material*);
  G4LogicalVolume *GetVolumeMFPlates(G4Material*);
  G4LogicalVolume *GetPinhole(G4Material*);
  G4LogicalVolume *GetZnS(G4Material*);
  G4LogicalVolume *GetZnSLG(G4Material*);
  G4LogicalVolume *GetPhotocathode(G4Material*);
  G4LogicalVolume *GetRoundPhotocathode(G4Material*);
  G4LogicalVolume *GetLens(G4Material*);
  G4LogicalVolume *GetRoundObjective(G4Material*);


  // Functions that can be called to return various scint dimensions

  //****************COMMON********************
  // ElectricField Plates
  G4double GetEFValue(){return EF_Value;}
  G4double GetEFDistBetweenPlates(){return EF_Dist_between_plates;}
  G4double GetEFPlatesThickness(){return EF_Thickness_plates;}
  G4double GetEFPlatesLength(){return EF_Length_plates;}
  G4double GetEFPlatesWidth(){return EF_Width_plates;}
  // MagneticField Plates
  G4double GetMFValue(){return MF_Value;}
  G4double GetMFDistBetweenPlates(){return MF_Dist_between_plates;}
  G4double GetMFPlatesThickness(){return MF_Thickness_plates;}
  G4double GetMFPlatesLength(){return MF_Length_plates;}
  G4double GetMFPlatesWidth(){return MF_Width_plates;}
  // Position of Plates
  G4double GetDistBetweenPlates(){return Dist_between_plates;}
  G4double GetEFPlatesDetector(){return Dist_EFPlates_Detector;}
  G4double GetPinholeMFPlates(){return Dist_pinhole_MFPlates;}
  G4double GetPinholeThickness(){return Pinhole_thickness;}
  G4double GetTranslationPinhole(){return translation_pinhole;}
  // Position of Detector
  G4double GetScintillatorThickness(){return ScintillatorThickness;}
  G4double GetZnSThickness(){return ZnSThickness;}
  G4double GetZnSLGThickness(){return ZnSLGThickness;}
  G4double GetDetectorThickness(){return DetectorThickness;}
  G4double GetDetectorTranslation(){return DetectorTranslation;}
  G4double GetLensTranslation(){return LensTranslation;}
  G4double GetLensThickness(){return LensThickness;}
  G4double GetFiberLength(){return Fiber_length;}
  G4double GetFiberWidth(){return Fiber_width;}
  G4double GetFiberSpace(){return Fiber_space;}
  G4double GetFiberCladdingRatio(){return Fiber_cladding_ratio;}
  G4double GetFiberNumberPerLine(){return Fiber_number_per_line;}
  G4int GetFiberMultiCladdingOption(){return Fiber_multi_cladding;}
  G4int GetFiberGeometry(){return Fiber_geometry;}
  G4int GetActivationG4FAST(){return Activation_G4FAST;}
  G4double GetLightyield(){return lightyield;}
  G4double GetLightyieldZnS(){return lightyieldZnS;}

private:


  Geometry *theScint;
  static const G4String path_bin;

  // Materials
  G4Material *Material;

  // Logical Volumes
  G4LogicalVolume *LogicalVolume;

  G4double ScintillatorLength=0.0;
  G4double ScintillatorWidth=0.0;
  G4double ScintillatorThickness=0.0;
  G4double ZnSThickness=0.0;
  G4double ZnSLGThickness=0.0;
  G4double DetectorLength=0.0;
  G4double DetectorWidth=0.0;
  G4double DetectorThickness=0.0;
  G4double DetectorTranslation=0.0;
  G4double LensTranslation=0.0;
  G4double LensThickness=0.0;
  
  //ElectricField Plates
  G4double EF_Value=0.0;
  G4double EF_Dist_between_plates=0.0;
  G4double EF_Thickness_plates=0.0;
  G4double EF_Length_plates=0.0;
  G4double EF_Width_plates=0.0;

  //MagneticField Plates
  G4double MF_Value=0.0;
  G4double MF_Dist_between_plates=0.0;
  G4double MF_Thickness_plates=0.0;
  G4double MF_Length_plates;
  G4double MF_Width_plates=0.0;

  //Pinhole
  G4double Pinhole_radius_ext=0.0;
  G4double Pinhole_radius_int=0.0;
  G4double Pinhole_thickness=0.0;

  //Position of Plates
  G4double Dist_between_plates=0.0;
  G4double Dist_EFPlates_Detector=0.0;
  G4double Dist_pinhole_MFPlates=0.0;
  G4double translation_pinhole=0.0;

  //Fibers
  G4int Fiber_geometry=0;
  G4int Fiber_multi_cladding=0;
  G4double Fiber_number_per_line=0.0;
  G4double Fiber_cladding_ratio=0.0;
  G4double Fiber_length=0.0;
  G4double Fiber_width=0.0;
  G4double Fiber_space=0.0;

  //G4FastTrack
  G4int Activation_G4FAST=0;

  // Optical Parameters
  G4double lightyield=0.0;
  G4double lightyieldZnS=0.0;

};
#endif
