/// Scintillator.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

// This class is used to create a plastic scintillator.

#ifndef Scintillator_h
#define Scintillator_h

#include "G4LogicalVolume.hh"
#include "G4MaterialPropertiesTable.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "CLHEP/Units/SystemOfUnits.h"

class TPSimMaterials;
class Scintillator

{
public:

  //constructor, builds from keys specified in buildfile
  Scintillator(G4String buildfile);
  ~Scintillator();
  //  void Construct();

public:

  // Functions to call this geometry in x_blockGeometry.cc

  G4LogicalVolume *GetScTest();
  G4LogicalVolume *GetEFPlates();
  G4LogicalVolume *GetVolumeEFPlates();
  G4LogicalVolume *GetMFPlates();
  G4LogicalVolume *GetVolumeMFPlates();
  G4LogicalVolume *GetPinhole();
  G4LogicalVolume *GetLaBr3();
  G4LogicalVolume *GetZnS();
  G4LogicalVolume *GetLaBr3PMMA();
  G4LogicalVolume *GetBoitierAluHPD();
  G4LogicalVolume *GetBoitierAluPM();
  G4LogicalVolume *GetGM_LND();
  G4LogicalVolume *GetGM_Plastique();
  G4LogicalVolume *GetSNMW_8InchesScint();
  G4LogicalVolume *GetSNMW_Teflon();
  G4LogicalVolume *GetSNMW_8InchesMylar();


  // Functions that can be called to return various scint dimensions

  //****************COMMON********************
  // wrapping
  G4double GetTeflonThickness(){return TeflonThickness;}
  G4double GetAirGapTeflon(){return AirGapTeflon;}
  G4double GetMylarThickness(){return MylarThickness;}
  G4double GetAirGapMylar(){return AirGapMylar;}
  // glue
  G4double GetGlueThickness(){return GlueThickness;}
  // *******SuperNEMO Main Wall*********
  // scint
  G4double GetSNMW_ScintStepWidth(){return SNMW_ScintStepWidth;}
  G4double GetSNMW_ScintStepHeight(){return SNMW_ScintStepHeight;}
  G4double GetSNMW_ScintBodyWidth(){return SNMW_ScintBodyWidth;}
  G4double GetSNMW_ScintBodyHeight(){return SNMW_ScintBodyHeight;}
  G4double GetSNMW_CouplingRadius(){return SNMW_CouplingSphereRadius;}
  G4double GetSNMW_CouplingDepth(){return SNMW_CouplingSphereDepth;}
  G4double GetSNMW_FullScintHeight(){return SNMW_ScintStepHeight+SNMW_ScintBodyHeight;}
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
  G4double GetTranslationPinhole(){return translation_pinhole;}
  // Position of Detector
  G4double GetScintillatorThickness(){return ScintillatorThickness;}
  G4double GetZnSThickness(){return ZnSThickness;}


private:


  Scintillator *theScint;
  TPSimMaterials* scintProp;

  static const G4String path_bin;


  // Materials
  G4Material *Material;

  // Logical Volumes
  G4LogicalVolume *LogicalVolume;

  G4double ScintillatorLength;
  G4double ScintillatorThickness;
  G4double ZnSThickness;
  // Physical Dimensions
  // scint SuperNEMO
  G4double SNMW_ScintStepWidth;
  G4double SNMW_ScintStepHeight;
  G4double SNMW_ScintBodyWidth;
  G4double SNMW_ScintBodyHeight;
  G4double SNMW_CouplingSphereRadius;
  G4double SNMW_CouplingSphereDepth;
  // wrapping
  G4double AirGapTeflon;
  G4double TeflonThickness;
  G4double AirGapMylar;
  G4double MylarThickness;
  // glue
  G4double GlueThickness;
  // PMT
  G4double PMTGlassRadius;
  G4double PMTGlassThickness;
  G4double PMTRearGlassRadius;
  G4double PMTPhotocathodeThickness;
  G4double PMTGlassTubeRadius;
  G4double PMTGlassTubeHeight;

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

  // Translations for unions/subtractions
  G4double Step_BodyUnion;
  G4double Block_SphereSubtraction;
  G4double TeflonStep_BodyUnion;
  G4double Teflon_ScintSubtraction;
  G4double MylarStep_BodyUnion;
  G4double Mylar_TeflonSubtraction;
  G4double Mylar_SphereSubtraction;





  // Other
  G4VisAttributes *clear;

};
#endif
