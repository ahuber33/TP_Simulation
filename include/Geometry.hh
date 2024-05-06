/// Geometry.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

// This class is used to create a plastic Geometry.

#ifndef Geometry_h
#define Geometry_h

#include "G4LogicalVolume.hh"
#include "G4MaterialPropertiesTable.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "CLHEP/Units/SystemOfUnits.h"
#include "G4Tubs.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Polyhedra.hh"
#include <G4Polycone.hh>
#include "G4Sphere.hh"
#include "G4Trap.hh"
#include "G4Trd.hh"
#include "G4SubtractionSolid.hh"

class TPSimMaterials;
class Geometry

{
public:

  //constructor, builds from keys specified in buildfile
  Geometry(G4String buildfile);
  ~Geometry();
  //  void Construct();

public:

  // Functions to call this geometry in x_blockGeometry.cc

  G4LogicalVolume *GetCoreRoundFiber();
  G4LogicalVolume *GetInnerCladdingRoundFiber();
  G4LogicalVolume *GetOuterCladdingRoundFiber();
  G4LogicalVolume *GetCoreSquareFiber();
  G4LogicalVolume *GetCladdingSquareFiber();
  G4LogicalVolume *GetScTest();
  G4LogicalVolume *GetEFPlates();
  G4LogicalVolume *GetVolumeEFPlates();
  G4LogicalVolume *GetMFPlates();
  G4LogicalVolume *GetVolumeMFPlates();
  G4LogicalVolume *GetPinhole();
  G4LogicalVolume *GetLaBr3();
  G4LogicalVolume *GetZnS();
  G4LogicalVolume *GetZnSLG();
  G4LogicalVolume *GetPhotocathode();
  G4LogicalVolume *GetRoundPhotocathode();
  G4LogicalVolume *GetLens();
  G4LogicalVolume *GetRATP_Aimant1();
  G4LogicalVolume *GetRATP_Aimant2();
  G4LogicalVolume *GetRATP_CoteYokeAimant1();
  G4LogicalVolume *GetRATP_CoteYokeAimant2();
  G4LogicalVolume *GetRATP_EntreeYokeAimant1();
  G4LogicalVolume *GetRATP_EntreeYokeAimant2();
  G4LogicalVolume *GetRATP_FondYokeAimant1();
  G4LogicalVolume *GetRATP_FondYokeAimant2();
  G4LogicalVolume *GetRATP_CaleYokeAimant();
  G4LogicalVolume *GetRATP_Electrode1();
  G4LogicalVolume *GetRATP_Electrode2();
  G4LogicalVolume *GetRATP_ColonneElectrode1();
  G4LogicalVolume *GetRATP_ColonneElectrode2();
  G4LogicalVolume *GetRATP_ColonneElectrode3();
  G4LogicalVolume *GetRATP_ColonneElectrode4();
  G4LogicalVolume *GetRATP_BaseElectrode1();
  G4LogicalVolume *GetRATP_BaseElectrode2();
  G4LogicalVolume *GetRATP_BaseElectrode3();
  G4LogicalVolume *GetRATP_BaseElectrode4();
  G4LogicalVolume *GetRATP_BaseBoite();
  G4LogicalVolume *GetRATP_CapotBoite();
  G4LogicalVolume *GetRATP_CoteBoite();
  G4LogicalVolume *GetRATP_EntreeBoite();
  G4LogicalVolume *GetRATP_SHV1();
  G4LogicalVolume *GetRATP_SHV2();
  G4LogicalVolume *GetRATP_SocleConnecteur();
  G4LogicalVolume *GetRATP_BaseBoiteDetecteur();
  G4LogicalVolume *GetRATP_EntreeBoiteDetecteur();
  G4LogicalVolume *GetRATP_SortieBoiteDetecteur();
  G4LogicalVolume *GetRATP_CoteBoiteDetecteur1();
  G4LogicalVolume *GetRATP_CoteBoiteDetecteur2();
  G4LogicalVolume *GetRATP_MontageIP();
  G4LogicalVolume *GetRATP_CouvercleBoiteDetecteur();
  G4LogicalVolume *GetRATP_PlaquePb();
  G4LogicalVolume *GetRoundObjective();


  // Functions that can be called to return various scint dimensions

  //****************COMMON********************
  // wrapping
  G4double GetTeflonThickness(){return TeflonThickness;}
  G4double GetAirGapTeflon(){return AirGapTeflon;}
  G4double GetMylarThickness(){return MylarThickness;}
  G4double GetAirGapMylar(){return AirGapMylar;}
  // glue
  G4double GetGlueThickness(){return GlueThickness;}
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

private:


  Geometry *theScint;
  TPSimMaterials* scintProp;

  static const G4String path_bin;


  // Materials
  G4Material *Material;

  // Logical Volumes
  G4LogicalVolume *LogicalVolume;

  G4double ScintillatorLength;
  G4double ScintillatorThickness;
  G4double ZnSThickness;
  G4double ZnSLGThickness;
  G4double DetectorLength;
  G4double DetectorWidth;
  G4double DetectorThickness;
  G4double DetectorTranslation;
  G4double LensTranslation;
  G4double LensThickness;
  // Physical Dimensions
  // wrapping
  G4double AirGapTeflon;
  G4double TeflonThickness;
  G4double AirGapMylar;
  G4double MylarThickness;
  // glue
  G4double GlueThickness;

  //ElectricField Plates
  G4double EF_Value;
  G4double EF_Dist_between_plates;
  G4double EF_Thickness_plates;
  G4double EF_Length_plates;
  G4double EF_Width_plates;

  //MagneticField Plates
  G4double MF_Value;
  G4double MF_Dist_between_plates;
  G4double MF_Thickness_plates;
  G4double MF_Length_plates;
  G4double MF_Width_plates;

  //Pinhole
  G4double Pinhole_radius_ext;
  G4double Pinhole_radius_int;
  G4double Pinhole_thickness;

  //Position of Plates
  G4double Dist_between_plates;
  G4double Dist_EFPlates_Detector;
  G4double Dist_pinhole_MFPlates;
  G4double translation_pinhole;

  //Fibers
  G4int Fiber_geometry;
  G4int Fiber_multi_cladding;
  G4double Fiber_number_per_line;
  G4double Fiber_cladding_ratio;
  G4double Fiber_length;
  G4double Fiber_width;
  G4double Fiber_space;

  //G4FastTrack
  G4int Activation_G4FAST;


  // Other
  G4VisAttributes *clear;

};
#endif
