/// TPSimGeometry.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#ifndef TPSimGeometry_h
#define TPSimGeometry_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4MaterialPropertiesTable.hh"
#include "G4VisAttributes.hh"
#include "G4Material.hh"
#include "G4VPhysicalVolume.hh"
#include "CLHEP/Units/SystemOfUnits.h"
#include "TPSimMagneticField.hh"
#include "TPSimRunAction.hh"
#include "TPSimMaterials.hh"
#include "TPSimSteppingAction.hh"
#include "Geometry.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4UnitsTable.hh"
#include "G4MaterialTable.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4PVPlacement.hh"
#include "G4UImanager.hh"
#include "G4MaterialTable.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4RunManager.hh"
#include "G4Transform3D.hh"
#include "G4SurfaceProperty.hh"

#include "G4ElectroMagneticField.hh"
#include "G4MagneticField.hh"
#include "G4UniformMagField.hh"
#include "G4FieldManager.hh"
#include "G4TransportationManager.hh"
#include "G4EquationOfMotion.hh"
#include "G4Mag_UsualEqRhs.hh"
#include "G4MagIntegratorStepper.hh"
#include "G4ChordFinder.hh"
#include "G4UniformElectricField.hh"
#include "G4EqMagElectricField.hh"
#include "G4MagIntegratorStepper.hh"
#include "G4MagIntegratorDriver.hh"

#include "G4ClassicalRK4.hh"

#include "G4RegionStore.hh"
#include "FastSimModelOpFiber.hh"
#include "G4MaterialPropertiesTable.hh"

#include "G4GenericMessenger.hh"

#include <memory>

class Geometry;
// class TPSimMaterials;
class G4FieldManager;
class TPSimMagneticField;

class TPSimGeometry : public G4VUserDetectorConstruction
{
public:
  TPSimGeometry();
  ~TPSimGeometry();

  G4VPhysicalVolume *Construct();
  void SetLogicalVolumeColor(G4LogicalVolume *, G4String);
  void GetConfigValue();
  void UpdateLightyield(G4Material *, G4double);
  void CreateWorldAndHolder();
  void CreatePinholeGeometry();
  void CreateFibersGeometry();
  void CreateRATPGeometry();
  void CreateScGeometry(G4double);
  void ConstructMaterials();
  void CreateBFieldVolume();
  void CreateEFieldVolume();
  void CreateTeflonOpticalProperties();
  void CreateMylarOpticalProperties();
  void CreateDetectionOpticalProperties();
  static void InitializeEJ212Properties(const G4String &, G4Material *);
  static void InitializeVacuumProperties(const G4String &, G4Material *);
  void ConstructSDandField() override;
  void CleanFields();
  static void PrintMaterialProperties(G4MaterialPropertiesTable *, const G4String &);
  G4LogicalVolume *GetLWorld() { return LogicalWorld; }

private:
  // Paths
  static const G4String path_bin;
  static const G4String path;

  // Classes for building various components
  std::unique_ptr<Geometry> Geom;

  // Visualization attributes
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
  G4LogicalVolume *LogicalWorld = nullptr;
  G4LogicalVolume *LogicalHolder = nullptr;
  G4LogicalVolume *LogicalVolumeEFPlates = nullptr;
  G4LogicalVolume *LogicalVolumeMFPlates = nullptr;
  G4LogicalVolume *LogicalCoreFiber = nullptr;
  G4LogicalVolume *LogicalInnerCladdingFiber = nullptr;
  G4LogicalVolume *LogicalOuterCladdingFiber = nullptr;

  // Physical volumes
  G4VPhysicalVolume *PhysicalWorld = nullptr;
  G4VPhysicalVolume *PhysicalCoreFiberBunch[1000000] = {nullptr};
  G4VPhysicalVolume *PhysicalInnerCladdingFiberBunch[1000000] = {nullptr};
  G4VPhysicalVolume *PhysicalOuterCladdingFiberBunch[1000000] = {nullptr};

  // Dimension values
  G4double EF_Value = 0.0;
  G4double EF_Dist_between_plates = 0.0;
  G4double EF_Thickness_plates = 0.0;
  G4double EF_Length_plates = 0.0;
  G4double EF_Width_plates = 0.0;
  G4double MF_Value = 0.0;
  G4double MF_Dist_between_plates = 0.0;
  G4double MF_Thickness_plates = 0.0;
  G4double MF_Length_plates = 0.0;
  G4double MF_Width_plates = 0.0;
  G4double Dist_between_plates = 0.0;
  G4double Dist_EFPlates_Detector = 0.0;
  G4double Dist_pinhole_MFPlates = 0.0;
  G4double translation_pinhole = 0.0;
  G4double ScintillatorLength = 0.0;
  G4double ScintillatorThickness = 0.0;
  G4double ZnSThickness = 0.0;
  G4double ZnSLGThickness = 0.0;
  G4double DetectorThickness = 0.0;
  G4double DetectorTranslation = 0.0;
  G4double LensTranslation = 0.0;
  G4double LensThickness = 0.0;
  G4double PinholeThickness = 0.0;
  G4double FiberLength = 0.0;
  G4double FiberWidth = 0.0;
  G4double FiberSpace = 0.0;
  G4double FiberCladdingRatio = 0.0;
  G4double FiberNumberPerLine = 0.0;
  G4double InnerCladdingFiberRadius = 0.0;
  G4double OuterCladdingFiberRadius = 0.0;
  G4double InnerCladdingFiberWidth = 0.0;
  G4int NbOfFibers = 0;
  G4double FiberSpacing = 0.0;
  G4double FiberWidthCore = 0.0;
  G4double FiberWidthCladding = 0.0;
  G4double FiberMultiCladding = 0.0;
  G4double FiberGeometry = 0.0;
  G4double WidthBunchFibers = 0.0;
  G4int ActivationG4FAST = 0;

  // Dimensions PLACEMENTS
  G4double Z_Position_MFPlates = 0.0;
  G4double Z_Position_EFPlates = 0.0;
  G4double Z_Position_ZnS = 0.0;
  G4double Z_Position_Sc = 0.0;
  G4double Z_Position_ZnSLG = 0.0;
  G4double Z_Position_Photocathode = 0.0;
  G4double Z_Position_Fiber = 0.0;
  G4double Z_Position_Lens = 0.0;
  G4double TeflonGap = 0.0;
  G4double TeflonThickness = 0.0;
  G4double MylarGap = 0.0;
  G4double MylarThickness = 0.0;
  G4double GlueThickness = 0.0;

  // Optical Parameters
  G4double lightyield;
  G4double lightyieldZnS;

  static G4ThreadLocal TPSimMagneticField *fMagneticField;
  static G4ThreadLocal G4FieldManager *magneticFieldMgr;
  static G4ThreadLocal G4FieldManager *electricFieldMgr;
  
};

#endif
