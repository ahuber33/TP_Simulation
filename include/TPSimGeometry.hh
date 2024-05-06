/// TPSimGeometry.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#ifndef TPSimGeometry_h
#define TPSimGeometry_h  1

#include "G4MaterialPropertiesTable.hh"

class Geometry;
class TPSimMaterials;
class G4VPhysicalVolume;

#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "CLHEP/Units/SystemOfUnits.h"

class  TPSimGeometry:  public G4VUserDetectorConstruction
{
public:
  TPSimGeometry();
  ~TPSimGeometry();

public:
  G4VPhysicalVolume* Construct();
  G4LogicalVolume* GetLWorld() {return LogicalWorld;}

private:
  static const G4String path_bin;
  static const G4String path;
  // Classes for building various components
  //     LogicalHolder *holder;
  TPSimMaterials *scintProp;
  Geometry *theScint;
  G4Material *Vacuum;
  G4Material *VacuumWorld;
  G4Material *Air;
  G4Material *Alu;

  // Colors for visualizations
  G4VisAttributes *invis;
  G4VisAttributes *white;
  G4VisAttributes *gray;
  G4VisAttributes *gray_bis;
  G4VisAttributes *black;
  G4VisAttributes *black_bis;
  G4VisAttributes *red;
  G4VisAttributes *red_hot;
  G4VisAttributes *orange;
  G4VisAttributes *yellow;
  G4VisAttributes *green;
  G4VisAttributes *green_hot;
  G4VisAttributes *cyan;
  G4VisAttributes *blue;
  G4VisAttributes *magenta;

  // Logical Volumes
  G4LogicalVolume *LogicalWorld;
  G4LogicalVolume *LogicalHolder;
  G4LogicalVolume *LogicalFibersHolder;
  G4LogicalVolume *LogicalGM_LND;
  G4LogicalVolume *LogicalSc;
  G4LogicalVolume *LogicalZnS;
  G4LogicalVolume *LogicalZnSLG;
  G4LogicalVolume *LogicalTeflon;
  G4LogicalVolume *LogicalMylar;
  G4LogicalVolume *LogicalGlue;
  G4LogicalVolume *LogicalPM;
  G4LogicalVolume *LogicalPhotocathode;
  G4LogicalVolume *LogicalLaBr3;
  G4LogicalVolume *LogicalPMMA;
  G4LogicalVolume *LogicalBoitierAlu;
  G4LogicalVolume *LogicalEFPlates;
  G4LogicalVolume *LogicalVolumeEFPlates;
  G4LogicalVolume *LogicalMFPlates;
  G4LogicalVolume *LogicalVolumeMFPlates;
  G4LogicalVolume *LogicalPinhole;
  G4LogicalVolume *LogicalCoreFiber;
  G4LogicalVolume *LogicalInnerCladdingFiber;
  G4LogicalVolume *LogicalOuterCladdingFiber;
  G4LogicalVolume *LogicalFiber;
  G4LogicalVolume *LogicalLens;
  G4LogicalVolume *LogicalLens2;
  G4LogicalVolume *LogicalRATP_Aimant1;
  G4LogicalVolume *LogicalRATP_Aimant2;
  G4LogicalVolume *LogicalRATP_CoteYokeAimant1;
  G4LogicalVolume *LogicalRATP_CoteYokeAimant2;
  G4LogicalVolume *LogicalRATP_EntreeYokeAimant1;
  G4LogicalVolume *LogicalRATP_EntreeYokeAimant2;
  G4LogicalVolume *LogicalRATP_FondYokeAimant1;
  G4LogicalVolume *LogicalRATP_FondYokeAimant2;
  G4LogicalVolume *LogicalRATP_CaleYokeAimant;
  G4LogicalVolume *LogicalRATP_Electrode1;
  G4LogicalVolume *LogicalRATP_Electrode2;
  G4LogicalVolume *LogicalRATP_ColonneElectrode1;
  G4LogicalVolume *LogicalRATP_ColonneElectrode2;
  G4LogicalVolume *LogicalRATP_ColonneElectrode3;
  G4LogicalVolume *LogicalRATP_ColonneElectrode4;
  G4LogicalVolume *LogicalRATP_BaseElectrode1;
  G4LogicalVolume *LogicalRATP_BaseElectrode2;
  G4LogicalVolume *LogicalRATP_BaseElectrode3;
  G4LogicalVolume *LogicalRATP_BaseElectrode4;
  G4LogicalVolume *LogicalRATP_BaseBoite;
  G4LogicalVolume *LogicalRATP_CoteBoite;
  G4LogicalVolume *LogicalRATP_CapotBoite;
  G4LogicalVolume *LogicalRATP_EntreeBoite;
  G4LogicalVolume *LogicalRATP_SHV1;
  G4LogicalVolume *LogicalRATP_SHV2;
  G4LogicalVolume *LogicalRATP_SocleConnecteur;
  G4LogicalVolume *LogicalRATP_BaseBoiteDetecteur;
  G4LogicalVolume *LogicalRATP_EntreeBoiteDetecteur;
  G4LogicalVolume *LogicalRATP_SortieBoiteDetecteur;
  G4LogicalVolume *LogicalRATP_CoteBoiteDetecteur1;
  G4LogicalVolume *LogicalRATP_CoteBoiteDetecteur2;
  G4LogicalVolume *LogicalRATP_CouvercleBoiteDetecteur;
  G4LogicalVolume *LogicalRATP_MontageIP;
  G4LogicalVolume *LogicalRATP_PlaquePb;
  G4LogicalVolume *LogicalRoundObjective;


  // Physical volumes
  G4VPhysicalVolume *PhysicalWorld;
  G4VPhysicalVolume *PhysicalHolder;
  G4VPhysicalVolume *PhysicalFibersHolder;
  G4VPhysicalVolume *PhysicalGM_LND;
  G4VPhysicalVolume *PhysicalSc;
  G4VPhysicalVolume *PhysicalZnS;
  G4VPhysicalVolume *PhysicalZnSLG;
  G4VPhysicalVolume *PhysicalTeflon;
  G4VPhysicalVolume *PhysicalMylar;
  G4VPhysicalVolume *PhysicalGlue;
  G4VPhysicalVolume *PhysicalPM;
  G4VPhysicalVolume *PhysicalPhotocathode;
  G4VPhysicalVolume *PhysicalPMMA;
  G4VPhysicalVolume *PhysicalBoitierAlu;
  G4VPhysicalVolume *PhysicalEFPlates;
  G4VPhysicalVolume *PhysicalVolumeEFPlates;
  G4VPhysicalVolume *PhysicalMFPlates;
  G4VPhysicalVolume *PhysicalVolumeMFPlates;
  G4VPhysicalVolume *PhysicalPinhole;
  G4VPhysicalVolume *PhysicalCoreFiber;
  G4VPhysicalVolume *PhysicalInnerCladdingFiber;
  G4VPhysicalVolume *PhysicalOuterCladdingFiber;
  G4VPhysicalVolume *PhysicalCoreFiberBunch[1000000];
  G4VPhysicalVolume *PhysicalInnerCladdingFiberBunch[1000000];
  G4VPhysicalVolume *PhysicalOuterCladdingFiberBunch[1000000];
  G4VPhysicalVolume *PhysicalLens;
  G4VPhysicalVolume *PhysicalLens2;
  G4VPhysicalVolume *PhysicalRATP_Aimant1;
  G4VPhysicalVolume *PhysicalRATP_Aimant2;
  G4VPhysicalVolume *PhysicalRATP_CoteYokeAimant1;
  G4VPhysicalVolume *PhysicalRATP_CoteYokeAimant2;
  G4VPhysicalVolume *PhysicalRATP_EntreeYokeAimant1;
  G4VPhysicalVolume *PhysicalRATP_EntreeYokeAimant2;
  G4VPhysicalVolume *PhysicalRATP_FondYokeAimant1;
  G4VPhysicalVolume *PhysicalRATP_FondYokeAimant2;
  G4VPhysicalVolume *PhysicalRATP_CaleYokeAimant;
  G4VPhysicalVolume *PhysicalRATP_Electrode1;
  G4VPhysicalVolume *PhysicalRATP_Electrode2;
  G4VPhysicalVolume *PhysicalRATP_ColonneElectrode1;
  G4VPhysicalVolume *PhysicalRATP_ColonneElectrode2;
  G4VPhysicalVolume *PhysicalRATP_ColonneElectrode3;
  G4VPhysicalVolume *PhysicalRATP_ColonneElectrode4;
  G4VPhysicalVolume *PhysicalRATP_BaseElectrode1;
  G4VPhysicalVolume *PhysicalRATP_BaseElectrode2;
  G4VPhysicalVolume *PhysicalRATP_BaseElectrode3;
  G4VPhysicalVolume *PhysicalRATP_BaseElectrode4;
  G4VPhysicalVolume *PhysicalRATP_BaseBoite;
  G4VPhysicalVolume *PhysicalRATP_CapotBoite;
  G4VPhysicalVolume *PhysicalRATP_CoteBoite;
  G4VPhysicalVolume *PhysicalRATP_EntreeBoite;
  G4VPhysicalVolume *PhysicalRATP_SHV1;
  G4VPhysicalVolume *PhysicalRATP_SHV2;
  G4VPhysicalVolume *PhysicalRATP_SocleConnecteur;
  G4VPhysicalVolume *PhysicalRATP_BaseBoiteDetecteur;
  G4VPhysicalVolume *PhysicalRATP_EntreeBoiteDetecteur;
  G4VPhysicalVolume *PhysicalRATP_SortieBoiteDetecteur;
  G4VPhysicalVolume *PhysicalRATP_CoteBoiteDetecteur1;
  G4VPhysicalVolume *PhysicalRATP_CoteBoiteDetecteur2;
  G4VPhysicalVolume *PhysicalRATP_CouvercleBoiteDetecteur;
  G4VPhysicalVolume *PhysicalRATP_MontageIP;
  G4VPhysicalVolume *PhysicalRATP_PlaquePb;
  G4VPhysicalVolume *PhysicalRoundObjective;



  // Optical surfaces
  G4OpticalSurface *OpticalTeflon;
  G4OpticalSurface *OpticalMylar;
  G4OpticalSurface *OpticalPMT;
  G4OpticalSurface *OpticalAlu;

  // Material Properties Table
  G4MaterialPropertiesTable *TeflonMPT;
  G4MaterialPropertiesTable *MylarMPT;
  G4MaterialPropertiesTable *AluMPT;
  G4MaterialPropertiesTable *PMT_MPT;

  // // Skin surfaces
  G4LogicalSkinSurface *SSTeflon;
  G4LogicalSkinSurface *SSMylar;
  G4LogicalSkinSurface *SSAlu;
  G4LogicalSkinSurface *SSPhotocathode;
  // G4LogicalSkinSurface *SSScintillateur;

  // Dimension values
  G4double EF_Value;
  G4double EF_Dist_between_plates;
  G4double EF_Thickness_plates;
  G4double EF_Length_plates;
  G4double EF_Width_plates;
  G4double MF_Value;
  G4double MF_Dist_between_plates;
  G4double MF_Thickness_plates;
  G4double MF_Length_plates;
  G4double MF_Width_plates;
  G4double Dist_between_plates;
  G4double Dist_EFPlates_Detector;
  G4double Dist_pinhole_MFPlates;
  G4double translation_pinhole;
  G4double ScintillatorThickness;
  G4double ZnSThickness;
  G4double ZnSLGThickness;
  G4double DetectorThickness;
  G4double DetectorTranslation;
  G4double LensTranslation;
  G4double LensThickness;
  G4double PinholeThickness;
  G4double FiberLength;
  G4double FiberWidth;
  G4double FiberSpace;
  G4double FiberCladdingRatio;
  G4double FiberNumberPerLine;
  G4double InnerCladdingFiberRadius;
  G4double OuterCladdingFiberRadius;
  G4double InnerCladdingFiberWidth;
  G4int NbOfFibers;
  G4double FiberSpacing;
  G4double FiberWidthCore;
  G4double FiberWidthCladding;
  G4double FiberMultiCladding;
  G4double FiberGeometry;
  G4double WidthBunchFibers;
  G4int ActivationG4FAST;

  // Dimensions PLACEMENTS
  G4double Z_Position_MFPlates;
  G4double Z_Position_EFPlates;
  G4double Z_Position_ZnS;
  G4double Z_Position_Sc;
  G4double Z_Position_ZnSLG;
  G4double Z_Position_Photocathode;
  G4double Z_Position_Fiber;
  G4double Z_Position_Lens;
  // wrapping
  G4double TeflonGap;
  G4double TeflonThickness;
  G4double MylarGap;
  G4double MylarThickness;
  // glue
  G4double GlueThickness;


};
#endif
