//// TPSimGeometry.cc
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimGeometry.hh"

using namespace CLHEP;

const G4String TPSimGeometry::path_bin = "../bin/";
const G4String TPSimGeometry::path = "../simulation_input_files/";
G4Mutex fieldManagerMutex = G4MUTEX_INITIALIZER;
std::mutex geometryMutex;
std::mutex fileAccessMutex;
// thread_local pour garantir que chaque thread dispose de sa propre copie des propriétés

G4ThreadLocal TPSimMagneticField *TPSimGeometry::fMagneticField = nullptr;
G4ThreadLocal G4FieldManager *TPSimGeometry::magneticFieldMgr = nullptr;
G4ThreadLocal G4FieldManager *TPSimGeometry::electricFieldMgr = nullptr;

// Constructor
TPSimGeometry::TPSimGeometry()
{
  // scintProp = std::make_unique<TPSimMaterials>(path_bin + "Materials.cfg");
  Geom = std::make_unique<Geometry>(path_bin + "TPSim.cfg");
}

// Destructor
TPSimGeometry::~TPSimGeometry()
{
  CleanFields();
}

void TPSimGeometry::CleanFields()
{
  if (fMagneticField)
  {
    delete fMagneticField;
    fMagneticField = nullptr;
  }
  if (magneticFieldMgr)
  {
    delete magneticFieldMgr;
    magneticFieldMgr = nullptr;
  }

  if (electricFieldMgr)
  {
    delete electricFieldMgr;
    electricFieldMgr = nullptr;
  }
}

void TPSimGeometry::SetLogicalVolumeColor(G4LogicalVolume *LogicalVolume, G4String Color)
{
  // ***********************
  // Visualization Colors
  // ***********************
  // Create some colors for visualizations
  invis = new G4VisAttributes(G4Colour(255 / 255., 255 / 255., 255 / 255.));
  invis->SetVisibility(false);

  white = new G4VisAttributes(G4Colour(1, 1, 1, 1.)); // Sets the color (can be looked up online)
  // white->SetForceWireframe(true); // Sets to wire frame mode for coloring the volume
  white->SetForceSolid(true); // Sets to solid mode for coloring the volume
  white->SetVisibility(true); // Makes color visible in visualization

  gray = new G4VisAttributes(G4Colour(0.5, 0.5, 0.5, 0.5));
  //  gray->SetForceWireframe(true);
  gray->SetForceSolid(true);
  gray->SetVisibility(true);

  gray_bis = new G4VisAttributes(G4Colour(0.5, 0.5, 0.5, 0.05));
  //  gray->SetForceWireframe(true);
  gray_bis->SetForceSolid(true);
  gray_bis->SetVisibility(true);

  black = new G4VisAttributes(G4Colour(0, 0, 0, 0.7));
  //  black->SetForceWireframe(true);
  black->SetForceSolid(true);
  black->SetVisibility(true);

  black_bis = new G4VisAttributes(G4Colour(0, 0, 0, 0.4));
  //  black->SetForceWireframe(true);
  black_bis->SetForceSolid(true);
  black_bis->SetVisibility(true);

  red = new G4VisAttributes(G4Colour(1, 0, 0, 0.5));
  //  red->SetForceWireframe(true);
  red->SetForceSolid(true);
  red->SetVisibility(true);

  red_hot = new G4VisAttributes(G4Colour(1, 0, 0, 1));
  //  red->SetForceWireframe(true);
  red_hot->SetForceSolid(true);
  red_hot->SetVisibility(true);

  orange = new G4VisAttributes(G4Colour(1, 0.5, 0, 0.4));
  //  orange->SetForceWireframe(true);
  orange->SetForceSolid(true);
  orange->SetVisibility(true);

  yellow = new G4VisAttributes(G4Colour(1, 1, 0, 0.1));
  //  yellow->SetForceWireframe(true);
  yellow->SetForceSolid(true);
  yellow->SetVisibility(true);

  green = new G4VisAttributes(G4Colour(0, 1, 0, 0.35));
  //  green->SetForceWireframe(true);
  green->SetForceSolid(true);
  green->SetVisibility(true);

  green_hot = new G4VisAttributes(G4Colour(0, 1, 0, 1));
  //  green_hot->SetForceWireframe(true);
  green_hot->SetForceSolid(true);
  green_hot->SetVisibility(true);

  cyan = new G4VisAttributes(G4Colour(0, 1, 1, 0.1));
  //  cyan->SetForceWireframe(true);
  cyan->SetForceSolid(true);
  cyan->SetVisibility(true);

  blue = new G4VisAttributes(G4Colour(0, 0, 1, 0.5));
  //  blue->SetForceWireframe(true);
  blue->SetForceSolid(true);
  blue->SetVisibility(true);

  magenta = new G4VisAttributes(G4Colour(1, 0, 1, 0.85));
  //  magenta->SetForceWireframe(true);
  // magenta->SetForceSolid(true);
  magenta->SetVisibility(true);

  if (Color == "invis")
  {
    LogicalVolume->SetVisAttributes(invis);
  }
  else if (Color == "black")
  {
    LogicalVolume->SetVisAttributes(black);
  }
  else if (Color == "white")
  {
    LogicalVolume->SetVisAttributes(white);
  }
  else if (Color == "gray")
  {
    LogicalVolume->SetVisAttributes(gray);
  }
  else if (Color == "red")
  {
    LogicalVolume->SetVisAttributes(red);
  }
  else if (Color == "orange")
  {
    LogicalVolume->SetVisAttributes(orange);
  }
  else if (Color == "yellow")
  {
    LogicalVolume->SetVisAttributes(yellow);
  }
  else if (Color == "green")
  {
    LogicalVolume->SetVisAttributes(green);
  }
  else if (Color == "cyan")
  {
    LogicalVolume->SetVisAttributes(cyan);
  }
  else if (Color == "blue")
  {
    LogicalVolume->SetVisAttributes(blue);
  }
  else if (Color == "magenta")
  {
    LogicalVolume->SetVisAttributes(magenta);
  }
}

void TPSimGeometry::CreateWorldAndHolder()
{
  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0.0 * deg);
  
  // Create World Volume
  // This is just a big box to place all other logical volumes inside
  auto SolidWorld = new G4Box("SolidWorld", 1100 * cm, 1100 * cm, 1100 * cm);
  auto VacuumWorld = TPSimMaterials::getInstance()->getMaterial("VacuumWorld");
  LogicalWorld = new G4LogicalVolume(SolidWorld, VacuumWorld, "LogicalWorld", 0, 0, 0);
  SetLogicalVolumeColor(LogicalWorld, "invis");

  // Create Holder Volume
  // This is just a big box to count the escaped photons
  auto s_holder = new G4Box("s_holder", 1000 * cm, 1000 * cm, 1000 * cm);
  auto Vacuum = TPSimMaterials::getInstance()->getMaterial("Vacuum");
  LogicalHolder = new G4LogicalVolume(s_holder, Vacuum, "logical_holder", 0, 0, 0); // Replace Air with Vacuum (init)

  SetLogicalVolumeColor(LogicalHolder, "invis");

  // Place the world volume: center of world at origin (0,0,0)
  PhysicalWorld = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0, 0, 0)), "World", LogicalWorld, NULL, false, 0);

  auto PhysicalHolder = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0, 0, 0)), LogicalHolder, "Vacuum", LogicalWorld, false, 0);
}

void TPSimGeometry::CreatePinholeGeometry()
{
  G4RotationMatrix Flip;
  Flip.rotateZ(0 * deg);
  Flip.rotateX(0 * deg);
  Flip.rotateY(90 * deg);

  auto Plomb = G4NistManager::Instance()->FindOrBuildMaterial("G4_Pb");
  auto LogicalPinhole = Geom->GetPinhole(Plomb);
  SetLogicalVolumeColor(LogicalPinhole, "black");

  auto PhysicalPinhole = new G4PVPlacement(G4Transform3D(Flip, G4ThreeVector(-45.5 - PinholeThickness / 2, 0 * mm, 22 * mm)), // Set at origin as basis of everything else
                                      LogicalPinhole, "Pinhole",
                                      LogicalHolder, false, 0);
}

void TPSimGeometry::CreateRATPGeometry()
{
  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0.0 * deg);
  
  auto Neodyme = G4NistManager::Instance()->FindOrBuildMaterial("G4_Nd");
  auto Alu = G4NistManager::Instance()->FindOrBuildMaterial("G4_Al");
  auto Fer = G4NistManager::Instance()->FindOrBuildMaterial("G4_Fe");
  auto Plomb = G4NistManager::Instance()->FindOrBuildMaterial("G4_Pb");

  auto LogicalRATP_Aimant1 = Geom->GetGDMLVolume("../gdml_models/RATP/aimant_1.gdml", "aimant_1", Neodyme);
  auto LogicalRATP_Aimant2 = Geom->GetGDMLVolume("../gdml_models/RATP/aimant_2.gdml", "aimant_2", Neodyme);
  auto LogicalRATP_CoteYokeAimant1 = Geom->GetGDMLVolume("../gdml_models/RATP/cote_YOKE_aimant_RATP.gdml", "cote_YOKE_Aimant_RATP", Alu);
  auto LogicalRATP_CoteYokeAimant2 = Geom->GetGDMLVolume("../gdml_models/RATP/cote_YOKE_aimant_RATP_bis.gdml", "cote_YOKE_Aimant_RATP_bis", Alu);
  auto LogicalRATP_EntreeYokeAimant1 = Geom->GetGDMLVolume("../gdml_models/RATP/entree_YOKE_aimant_RATP.gdml", "entree_YOKE_aimant_RATP", Alu);
  auto LogicalRATP_EntreeYokeAimant2 = Geom->GetGDMLVolume("../gdml_models/RATP/entree_YOKE_aimant_RATP_bis.gdml", "entree_YOKE_aimant_RATP_bis", Alu);
  auto LogicalRATP_FondYokeAimant1 = Geom->GetGDMLVolume("../gdml_models/RATP/fond_YOKE_aimant_RATP.gdml", "Fond_YOKE_Aimant", Alu);
  auto LogicalRATP_FondYokeAimant2 = Geom->GetGDMLVolume("../gdml_models/RATP/fond_YOKE_aimant_RATP_bis.gdml", "Fond_YOKE_Aimant_bis", Alu);
  auto LogicalRATP_CaleYokeAimant = Geom->GetGDMLVolume("../gdml_models/RATP/cale_YOKE_aimant_RATP.gdml", "Cale_YOKE_Aimant", Alu);
  auto LogicalRATP_Electrode1 = Geom->GetGDMLVolume("../gdml_models/RATP/electrode_RATP_1.gdml", "Electrode1", Fer);
  auto LogicalRATP_Electrode2 = Geom->GetGDMLVolume("../gdml_models/RATP/electrode_RATP_2.gdml", "Electrode2", Fer);
  auto LogicalRATP_ColonneElectrode1 = Geom->GetGDMLVolume("../gdml_models/RATP/colonne_electrode_RATP_1.gdml", "Colonne_electrode1", Alu);
  auto LogicalRATP_ColonneElectrode2 = Geom->GetGDMLVolume("../gdml_models/RATP/colonne_electrode_RATP_2.gdml", "Colonne_electrode2", Alu);
  auto LogicalRATP_ColonneElectrode3 = Geom->GetGDMLVolume("../gdml_models/RATP/colonne_electrode_RATP_3.gdml", "Colonne_electrode3", Alu);
  auto LogicalRATP_ColonneElectrode4 = Geom->GetGDMLVolume("../gdml_models/RATP/colonne_electrode_RATP_4.gdml", "Colonne_electrode4", Alu);
  auto LogicalRATP_BaseElectrode1 = Geom->GetGDMLVolume("../gdml_models/RATP/base_electrode_RATP_1.gdml", "Base_electrode1", Alu);
  auto LogicalRATP_BaseElectrode2 = Geom->GetGDMLVolume("../gdml_models/RATP/base_electrode_RATP_2.gdml", "Base_electrode2", Alu);
  auto LogicalRATP_BaseElectrode3 = Geom->GetGDMLVolume("../gdml_models/RATP/base_electrode_RATP_3.gdml", "Base_electrode3", Alu);
  auto LogicalRATP_BaseElectrode4 = Geom->GetGDMLVolume("../gdml_models/RATP/base_electrode_RATP_4.gdml", "Base_electrode4", Alu);
  auto LogicalRATP_BaseBoite = Geom->GetGDMLVolume("../gdml_models/RATP/base_boite_RATP.gdml", "Base_boite", Alu);
  auto LogicalRATP_CapotBoite = Geom->GetGDMLVolume("../gdml_models/RATP/capot_boite_RATP.gdml", "Capot_boite", Alu);
  auto LogicalRATP_CoteBoite = Geom->GetGDMLVolume("../gdml_models/RATP/cote_boite_RATP.gdml", "Cote_boite", Alu);
  auto LogicalRATP_EntreeBoite = Geom->GetGDMLVolume("../gdml_models/RATP/entree_boite_RATP.gdml", "Entree_boite", Alu);
  auto LogicalRATP_SHV1 = Geom->GetGDMLVolume("../gdml_models/RATP/SHV_1.gdml", "SHV1", Alu);
  auto LogicalRATP_SHV2 = Geom->GetGDMLVolume("../gdml_models/RATP/SHV_2.gdml", "SHV2", Alu);
  auto LogicalRATP_SocleConnecteur = Geom->GetGDMLVolume("../gdml_models/RATP/socle_connecteur_RATP.gdml", "Socle_connecteur", Alu);
  auto LogicalRATP_BaseBoiteDetecteur = Geom->GetGDMLVolume("../gdml_models/RATP/base_boite_detecteur_RATP.gdml", "Base_boite_detecteur", Alu);
  auto LogicalRATP_EntreeBoiteDetecteur = Geom->GetGDMLVolume("../gdml_models/RATP/entree_boite_detecteur_RATP.gdml", "Entree_boite_detecteur", Alu);
  auto LogicalRATP_SortieBoiteDetecteur = Geom->GetGDMLVolume("../gdml_models/RATP/sortie_boite_detecteur_RATP.gdml", "Sortie_boite_detecteur", Alu);
  auto LogicalRATP_CoteBoiteDetecteur1 = Geom->GetGDMLVolume("../gdml_models/RATP/cote_boite_detecteur_RATP.gdml", "Cote_boite_detecteur1", Alu);
  auto LogicalRATP_CoteBoiteDetecteur2 = Geom->GetGDMLVolume("../gdml_models/RATP/cote_boite_detecteur_RATP_bis.gdml", "Cote_boite_detecteur2", Alu);
  auto LogicalRATP_MontageIP = Geom->GetGDMLVolume("../gdml_models/RATP/montage_IP_RATP.gdml", "Montage_IP", Alu);
  auto LogicalRATP_CouvercleBoiteDetecteur = Geom->GetGDMLVolume("../gdml_models/RATP/couvercle_boite_detecteur_RATP.gdml", "Couvercle_boite_detecteur", Alu);
  auto LogicalRATP_PlaquePb = Geom->GetGDMLVolume("../gdml_models/RATP/Pb_Plate.gdml", "Pb_Plate", Plomb);

  SetLogicalVolumeColor(LogicalRATP_Aimant1, "black");
  SetLogicalVolumeColor(LogicalRATP_Aimant2, "black");
  SetLogicalVolumeColor(LogicalRATP_CoteYokeAimant1, "blue");
  SetLogicalVolumeColor(LogicalRATP_CoteYokeAimant2, "blue");
  SetLogicalVolumeColor(LogicalRATP_EntreeYokeAimant1, "blue");
  SetLogicalVolumeColor(LogicalRATP_EntreeYokeAimant2, "blue");
  SetLogicalVolumeColor(LogicalRATP_FondYokeAimant1, "blue");
  SetLogicalVolumeColor(LogicalRATP_FondYokeAimant2, "blue");
  SetLogicalVolumeColor(LogicalRATP_CaleYokeAimant, "gray");
  SetLogicalVolumeColor(LogicalRATP_Electrode1, "red");
  SetLogicalVolumeColor(LogicalRATP_Electrode2, "red");
  SetLogicalVolumeColor(LogicalRATP_ColonneElectrode1, "red");
  SetLogicalVolumeColor(LogicalRATP_ColonneElectrode2, "red");
  SetLogicalVolumeColor(LogicalRATP_ColonneElectrode3, "red");
  SetLogicalVolumeColor(LogicalRATP_ColonneElectrode4, "red");
  SetLogicalVolumeColor(LogicalRATP_BaseElectrode1, "red");
  SetLogicalVolumeColor(LogicalRATP_BaseElectrode2, "red");
  SetLogicalVolumeColor(LogicalRATP_BaseElectrode3, "red");
  SetLogicalVolumeColor(LogicalRATP_BaseElectrode4, "red");
  SetLogicalVolumeColor(LogicalRATP_BaseBoite, "cyan");
  SetLogicalVolumeColor(LogicalRATP_CapotBoite, "cyan");
  SetLogicalVolumeColor(LogicalRATP_CoteBoite, "cyan");
  SetLogicalVolumeColor(LogicalRATP_EntreeBoite, "cyan");
  SetLogicalVolumeColor(LogicalRATP_SHV1, "cyan");
  SetLogicalVolumeColor(LogicalRATP_SHV2, "cyan");
  SetLogicalVolumeColor(LogicalRATP_SocleConnecteur, "cyan");
  SetLogicalVolumeColor(LogicalRATP_BaseBoiteDetecteur, "green");
  SetLogicalVolumeColor(LogicalRATP_EntreeBoiteDetecteur, "green");
  SetLogicalVolumeColor(LogicalRATP_SortieBoiteDetecteur, "green");
  SetLogicalVolumeColor(LogicalRATP_CoteBoiteDetecteur1, "green");
  SetLogicalVolumeColor(LogicalRATP_CoteBoiteDetecteur2, "green");
  SetLogicalVolumeColor(LogicalRATP_CouvercleBoiteDetecteur, "green");
  SetLogicalVolumeColor(LogicalRATP_MontageIP, "red_hot");
  SetLogicalVolumeColor(LogicalRATP_PlaquePb, "black");

  auto PhysicalRATP_PlaquePb = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                            LogicalRATP_PlaquePb, "PlaquePb",
                                            LogicalHolder, false, 0);

  auto PhysicalRATP_Aimant1 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                           LogicalRATP_Aimant1, "Aimant1",
                                           LogicalHolder, false, 0);

  auto PhysicalRATP_Aimant2 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                           LogicalRATP_Aimant2, "Aimant2",
                                           LogicalHolder, false, 0);

  auto PhysicalRATP_CoteYokeAimant1 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                   LogicalRATP_CoteYokeAimant1, "CoteYokeAimant1",
                                                   LogicalHolder, false, 0);

  auto PhysicalRATP_CoteYokeAimant2 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                   LogicalRATP_CoteYokeAimant2, "CoteYokeAimant2",
                                                   LogicalHolder, false, 0);

  auto PhysicalRATP_EntreeYokeAimant1 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                     LogicalRATP_EntreeYokeAimant1, "EntreeYokeAimant1",
                                                     LogicalHolder, false, 0);

  auto PhysicalRATP_EntreeYokeAimant2 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                     LogicalRATP_EntreeYokeAimant2, "EntreeYokeAimant2",
                                                     LogicalHolder, false, 0);

  auto PhysicalRATP_FondYokeAimant1 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                   LogicalRATP_FondYokeAimant1, "FondYokeAimant1",
                                                   LogicalHolder, false, 0);

  auto PhysicalRATP_FondYokeAimant2 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                   LogicalRATP_FondYokeAimant2, "FondYokeAimant2",
                                                   LogicalHolder, false, 0);

  auto PhysicalRATP_CaleYokeAimant = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                  LogicalRATP_CaleYokeAimant, "CaleYokeAimant",
                                                  LogicalHolder, false, 0);

  auto PhysicalRATP_Electrode1 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                              LogicalRATP_Electrode1, "Electrode1",
                                              LogicalHolder, false, 0);

  auto PhysicalRATP_Electrode2 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                              LogicalRATP_Electrode2, "Electrode2",
                                              LogicalHolder, false, 0);

  auto PhysicalRATP_ColonneElectrode1 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                     LogicalRATP_ColonneElectrode1, "ColonneElectrode1",
                                                     LogicalHolder, false, 0);

  auto PhysicalRATP_ColonneElectrode2 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                     LogicalRATP_ColonneElectrode2, "ColonneElectrode2",
                                                     LogicalHolder, false, 0);

  auto PhysicalRATP_ColonneElectrode3 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                     LogicalRATP_ColonneElectrode3, "ColonneElectrode3",
                                                     LogicalHolder, false, 0);

  auto PhysicalRATP_ColonneElectrode4 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                     LogicalRATP_ColonneElectrode4, "ColonneElectrode4",
                                                     LogicalHolder, false, 0);

  auto PhysicalRATP_BaseElectrode1 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                  LogicalRATP_BaseElectrode1, "BaseElectrode1",
                                                  LogicalHolder, false, 0);

  auto PhysicalRATP_BaseElectrode2 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                  LogicalRATP_BaseElectrode2, "BaseElectrode2",
                                                  LogicalHolder, false, 0);

  auto PhysicalRATP_BaseElectrode3 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                  LogicalRATP_BaseElectrode3, "BaseElectrode3",
                                                  LogicalHolder, false, 0);

  auto PhysicalRATP_BaseElectrode4 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                  LogicalRATP_BaseElectrode4, "BaseElectrode4",
                                                  LogicalHolder, false, 0);

  auto PhysicalRATP_BaseBoite = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                             LogicalRATP_BaseBoite, "BaseBoite",
                                             LogicalHolder, false, 0);

  auto PhysicalRATP_CapotBoite = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                              LogicalRATP_CapotBoite, "CapotBoite",
                                              LogicalHolder, false, 0);

  auto PhysicalRATP_CoteBoite = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                             LogicalRATP_CoteBoite, "CoteBoite",
                                             LogicalHolder, false, 0);

  auto PhysicalRATP_EntreeBoite = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                               LogicalRATP_EntreeBoite, "EntreeBoite",
                                               LogicalHolder, false, 0);

  auto PhysicalRATP_SocleConnecteur = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                   LogicalRATP_SocleConnecteur, "SocleConnecteur",
                                                   LogicalHolder, false, 0);

  auto PhysicalRATP_SHV1 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                        LogicalRATP_SHV1, "SHV1",
                                        LogicalHolder, false, 0);

  auto PhysicalRATP_SHV2 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                        LogicalRATP_SHV2, "SHV2",
                                        LogicalHolder, false, 0);

  auto PhysicalRATP_BaseBoiteDetecteur = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                      LogicalRATP_BaseBoiteDetecteur, "BaseBoiteDetecteur",
                                                      LogicalHolder, false, 0);

  auto PhysicalRATP_EntreeBoiteDetecteur = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                        LogicalRATP_EntreeBoiteDetecteur, "EntreeBoiteDetecteur",
                                                        LogicalHolder, false, 0);

  auto PhysicalRATP_SortieBoiteDetecteur = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                        LogicalRATP_SortieBoiteDetecteur, "SortieBoiteDetecteur",
                                                        LogicalHolder, false, 0);

  auto PhysicalRATP_CoteBoiteDetecteur1 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                       LogicalRATP_CoteBoiteDetecteur1, "CoteBoiteDetecteur1",
                                                       LogicalHolder, false, 0);

  auto PhysicalRATP_CoteBoiteDetecteur2 = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                       LogicalRATP_CoteBoiteDetecteur2, "CoteBoiteDetecteur2",
                                                       LogicalHolder, false, 0);

  auto PhysicalRATP_CouvercleBoiteDetecteur = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(0 * mm, 0, 0)), // Set at origin as basis of everything else
                                                           LogicalRATP_CouvercleBoiteDetecteur, "CouvercleBoiteDetecteur",
                                                           LogicalHolder, false, 0);

  // auto PhysicalRATP_MontageIP = new G4PVPlacement(G4Transform3D
  // (DontRotate,G4ThreeVector(0*mm, 0, 0)), // Set at origin as basis of everything else
  // LogicalRATP_MontageIP,"MontageIP",
  // LogicalHolder,false,0);
}

void TPSimGeometry::CreateFibersGeometry()
{
  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0.0 * deg);
  G4RotationMatrix Flip;
  Flip.rotateZ(0 * deg);
  Flip.rotateX(0 * deg);
  Flip.rotateY(90 * deg);

  auto Vacuum = TPSimMaterials::getInstance()->getMaterial("Vacuum");
  auto EJ212 = TPSimMaterials::getInstance()->getMaterial("EJ212");
  auto PMMA = TPSimMaterials::getInstance()->getMaterial("PMMA");
  auto FP = TPSimMaterials::getInstance()->getMaterial("FP");

  auto s_fibersholder = new G4Box("s_fibersholder", (WidthBunchFibers / 2) * mm, (WidthBunchFibers / 2) * mm, FiberLength / 2);
  // G4Tubs *s_fibersholder = new G4Tubs("s_fibersholder", 0.0, 0.6*mm, 50*mm, 0, 360*deg);

  auto LogicalFibersHolder = new G4LogicalVolume(s_fibersholder, Vacuum, "logical_fibersholder", 0, 0, 0); // Replace Air with Vacuum (init)

  SetLogicalVolumeColor(LogicalFibersHolder, "orange");

  auto PhysicalFibersHolder = new G4PVPlacement(G4Transform3D(Flip, G4ThreeVector(280.5 + ZnSThickness + ScintillatorThickness + FiberLength / 2, 15, -3.1)), LogicalFibersHolder, "Holder_Fiber", LogicalHolder, false, 0); // USE THAT FOR TP
  // PhysicalFibersHolder = new G4PVPlacement(G4Transform3D(DontRotate,G4ThreeVector(0, 0, Z_Position_Fiber)),LogicalFibersHolder, "Holder_Fiber",LogicalHolder,false,0);//USE THAT FOR DEBUG



  if (FiberGeometry == 0)
  {
    LogicalCoreFiber = Geom->GetCoreRoundFiber(EJ212);
    LogicalInnerCladdingFiber = Geom->GetInnerCladdingRoundFiber(PMMA);
    LogicalOuterCladdingFiber = Geom->GetOuterCladdingRoundFiber(FP);
  }

  else if (FiberGeometry == 1)
  {
    LogicalCoreFiber = Geom->GetCoreSquareFiber(EJ212);
    LogicalInnerCladdingFiber = Geom->GetCladdingSquareFiber(PMMA);
  }

  else
    G4Exception("TPSim.cfg",
                "InvalidSetup", FatalException,
                "Fiber Geometry !=0 or 1");

  SetLogicalVolumeColor(LogicalCoreFiber, "cyan");
  SetLogicalVolumeColor(LogicalInnerCladdingFiber, "yellow");
  SetLogicalVolumeColor(LogicalOuterCladdingFiber, "red");

  auto FiberRegion = new G4Region("Fiber_Region");
  FiberRegion->AddRootLogicalVolume(LogicalFibersHolder);

  auto regionStore = G4RegionStore::GetInstance();
  if (ActivationG4FAST == 1)
    new FastSimModelOpFiber("FastSimModelOpFiber", FiberRegion, FiberMultiCladding);

  G4int n = 0;
  G4float translation_x = 0;
  G4float translation_y = 0;

  for (int i = 0; i < FiberNumberPerLine; i++)
  {
    for (int j = 0; j < FiberNumberPerLine; j++)
    {
      translation_x = (FiberSpace + FiberWidth / 2 - WidthBunchFibers / 2) + j * (FiberWidth + FiberSpace);
      translation_y = (FiberSpace + FiberWidth / 2 - WidthBunchFibers / 2) + i * (FiberWidth + FiberSpace);

      PhysicalCoreFiberBunch[n] = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(translation_x, translation_y, 0)), // Set at origin as basis of everything else
                                                    LogicalCoreFiber, "Core_Fiber",
                                                    LogicalFibersHolder, false, 0);

      PhysicalInnerCladdingFiberBunch[n] = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(translation_x, translation_y, 0)), // Set at origin as basis of everything else
                                                             LogicalInnerCladdingFiber, "Inner_Cladding_Fiber",
                                                             LogicalFibersHolder, false, 0);

      if (FiberMultiCladding == 1)
      {
        PhysicalOuterCladdingFiberBunch[n] = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(translation_x, translation_y, 0)), // Set at origin as basis of everything else
                                                               LogicalOuterCladdingFiber, "Outer_Cladding_Fiber",
                                                               LogicalFibersHolder, false, 0);
      }

      n++;
    }
  }
}

void TPSimGeometry::CreateBFieldVolume()
{
  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0.0 * deg);
  
  auto Vacuum = TPSimMaterials::getInstance()->getMaterial("Vacuum");
  // LogicalMFPlates = Geom->GetMFPlates(); //Activate if non GDML-RATP Geometry
  LogicalVolumeMFPlates = Geom->GetVolumeMFPlates(Vacuum);

  // SetLogicalVolumeColor(LogicalMFPlates, "blue"); //Activate if non GDML-RATP Geometry
  SetLogicalVolumeColor(LogicalVolumeMFPlates, "gray");

  auto PhysicalVolumeMFPlates = new G4PVPlacement(G4Transform3D
                                             //(DontRotate,G4ThreeVector(MF_Width_plates/2-2, 0*mm, Z_Position_MFPlates)), // Without GDML
                                             (DontRotate, G4ThreeVector(0, 0, 7)), // GDML !!!!
                                             LogicalVolumeMFPlates, "Volume_MF_Plates",
                                             LogicalHolder, false, 0);

  //     PhysicalMFPlates = new G4PVPlacement(G4Transform3D   //Activate if non GDML-RATP Geometry
  //       (DontRotate,G4ThreeVector(0*mm, 0*mm, 0)), // Set at origin as basis of everything else
  //       LogicalMFPlates,"MF_Plates",
  //       LogicalVolumeMFPlates,false,0);
}

void TPSimGeometry::CreateEFieldVolume()
{
  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0.0 * deg);

  auto Vacuum = TPSimMaterials::getInstance()->getMaterial("Vacuum");
  // LogicalEFPlates = Geom->GetEFPlates(); //Activate if non GDML-RATP Geometry
  LogicalVolumeEFPlates = Geom->GetVolumeEFPlates(Vacuum);

  // SetLogicalVolumeColor(LogicalEFPlates, "red"); //Activate if non GDML-RATP Geometry
  SetLogicalVolumeColor(LogicalVolumeEFPlates, "gray");

  auto PhysicalVolumeEFPlates = new G4PVPlacement(G4Transform3D
                                             //(DontRotate,G4ThreeVector(EF_Width_plates/2 - 2*mm, 4*mm, Z_Position_EFPlates)), // Without GDML
                                             (DontRotate, G4ThreeVector(135.5, 4, -3.5)), // GDML
                                             LogicalVolumeEFPlates, "Volume_EF_Plates",
                                             LogicalHolder, false, 0);

  //         PhysicalEFPlates = new G4PVPlacement(G4Transform3D
  //           (DontRotate,G4ThreeVector(0*mm, 0, 0)), // Set at origin as basis of everything else
  //           LogicalEFPlates,"EF_Plates",
  //           LogicalVolumeEFPlates,false,0);
}

void TPSimGeometry::CreateTeflonOpticalProperties()
{
  auto TeflonMPT = new G4MaterialPropertiesTable();
  // Define Teflon properties
  // Properties are read in from data file
  std::ifstream Read_teflon;
  G4String teflon_file = path + "teflon.dat";
  std::vector<G4double> Teflon_Energy;
  std::vector<G4double> Teflon_Reflectivity;
  std::vector<G4double> Teflon_Zero;
  G4double wavelength;       // x values
  G4double teflon_ref_coeff; // y values
                             // Read_teflon.open(teflon_file);
  if (Read_teflon.is_open())
  {
    while (!Read_teflon.eof())
    {
      G4String filler; // This just skips the coma and space in data files
      Read_teflon >> wavelength >> filler >> teflon_ref_coeff;
      Teflon_Energy.push_back((1240 / wavelength) * eV);
      Teflon_Reflectivity.push_back(1. * teflon_ref_coeff);
      Teflon_Zero.push_back(1e-6);
    }
  }
  else
    G4cout << "Error opening file: " << teflon_file << G4endl; // throw an error if file is not found
  Read_teflon.close();

  // Define Teflon optical boundary surface properties
  auto OpticalTeflon = new G4OpticalSurface("OpticalTeflon");
  OpticalTeflon->SetModel(unified);             // Either glisur (GEANT3 model) or unified surface model: set references online
  OpticalTeflon->SetPolish(0);                  // Set level of polish
  OpticalTeflon->SetFinish(groundfrontpainted); // Sets finish to one of 6 options: see references online - based off polished or grounded
  OpticalTeflon->SetType(dielectric_metal);     // Sets boundary type: dielectric-dielectric or dielectric-metal
  // Define Teflon material properties
  TeflonMPT->AddProperty("REFLECTIVITY", Teflon_Energy, Teflon_Reflectivity);
  TeflonMPT->AddProperty("SPECULARLOBECONSTANT", Teflon_Energy, Teflon_Zero);
  TeflonMPT->AddProperty("SPECULARSPIKECONSTANT", Teflon_Energy, Teflon_Zero);
  TeflonMPT->AddProperty("BACKSCATTERCONSTANT", Teflon_Energy, Teflon_Zero);
  // Geometrical implementation of boundary surface
  OpticalTeflon->SetMaterialPropertiesTable(TeflonMPT);
  // auto SSTeflon = new G4LogicalSkinSurface("b_Teflon",LogicalTeflon,OpticalTeflon); // Applies optical Teflon properties to ogical Teflon surface
}

void TPSimGeometry::CreateMylarOpticalProperties()
{
  auto MylarMPT = new G4MaterialPropertiesTable();
  // Define Mylar properties
  std::ifstream Read_mylar;
  G4double wavelength; // x values
  G4String mylar_file = path + "mylar.dat";
  std::vector<G4double> Mylar_Energy;
  std::vector<G4double> Mylar_Reflectivity;
  std::vector<G4double> Mylar_Zero;
  std::vector<G4double> Mylar_Un;
  G4double mylar_ref_coeff;
  Read_mylar.open(mylar_file);
  if (Read_mylar.is_open())
  {
    while (!Read_mylar.eof())
    {
      G4String filler;
      Read_mylar >> wavelength >> filler >> mylar_ref_coeff;
      Mylar_Energy.push_back((1240 / wavelength) * eV);
      Mylar_Reflectivity.push_back(1. * mylar_ref_coeff);
      Mylar_Zero.push_back(0.0);
      Mylar_Un.push_back(1.0);
    }
  }
  else
    G4cout << "Error opening file: " << mylar_file << G4endl;
  Read_mylar.close();

  // Define Mylar optical boundary surface properties
  auto OpticalMylar = new G4OpticalSurface("OpticalMylar");
  OpticalMylar->SetModel(glisur);
  OpticalMylar->SetFinish(polished);
  OpticalMylar->SetType(dielectric_metal);

  // Define Mylar material properties
  MylarMPT->AddProperty("REFLECTIVITY", Mylar_Energy, Mylar_Reflectivity);
  MylarMPT->AddProperty("SPECULARLOBECONSTANT", Mylar_Energy, Mylar_Un);
  MylarMPT->AddProperty("SPECULARSPIKECONSTANT", Mylar_Energy, Mylar_Un);
  // MylarMPT->AddProperty("DIFFUSELOBECONSTANT",mylar_energy,realzero,mylar_entries);
  MylarMPT->AddProperty("BACKSCATTERCONSTANT", Mylar_Energy, Mylar_Zero);

  // Geometrical implementation of boundary surface
  OpticalMylar->SetMaterialPropertiesTable(MylarMPT);

  // SSMylar = new G4LogicalSkinSurface("SSMylar", LogicalMylar,OpticalMylar); // Applies Mylar properties to logical mylar surface
  //auto SSAlu = new G4LogicalSkinSurface("SSAlu", LogicalBoitierAlu, OpticalMylar); // Applies Mylar properties to logical Alu surface
}

void TPSimGeometry::CreateDetectionOpticalProperties()
{
  G4RotationMatrix Flip;
  Flip.rotateZ(0 * deg);
  Flip.rotateX(0 * deg);
  Flip.rotateY(90 * deg);
  auto Silicium = G4NistManager::Instance()->FindOrBuildMaterial("G4_SILICON_DIOXIDE");
  // LogicalPhotocathode = Geom->GetPhotocathode(); // Call function for PMT glass
  auto LogicalPhotocathode = Geom->GetRoundObjective(Silicium); // Call function for PMT glass
  LogicalPhotocathode->SetVisAttributes(blue);             // Set photocathode color to orange

  // Define PMT properties
  G4double wavelength;        // x values
  G4double indexconst = 1.49; // Index currently set to constant for PMT glass
  G4double reflectconst = 0.;
  std::ifstream ReadPMT;
  // G4String PMTfile = path+"QE_ham_GA0124.txt";
  // G4String PMTfile = path+"9102B_ET_reverse.txt";
  G4String PMTfile = path + "ORCA_ENL_reverse.cfg";
  // G4String PMTfile = path+"CMOS_S11684_reverse.cfg";
  std::vector<G4double> Photocathode_Energy;
  std::vector<G4double> Photocathode_Value;
  std::vector<G4double> Photocathode_Index;
  std::vector<G4double> Photocathode_Reflectivity;
  G4double quant_eff;
  ReadPMT.open(PMTfile);
  if (ReadPMT.is_open())
  {
    while (!ReadPMT.eof())
    {
      G4String filler;
      ReadPMT >> wavelength >> filler >> quant_eff;
      // PMTdetect[PMTentries] = 0.79*quant_eff*.65;  //0.79 = correction factor to adjust QE to lower value of 34% for R6594 and 0.59 = 25%
      // PMTdetect1[PMTentries] = 1; // Use only if you want %100 QE
      Photocathode_Energy.push_back((1240 / wavelength) * eV);
      // Photocathode_Value.push_back(1);  //For the GAxxxx file with good QE and 0.65 for collection efficiency
      Photocathode_Value.push_back(quant_eff * 1); // Change 1 if you know ou want to apply a collection efficiency factor !!!
      Photocathode_Index.push_back(indexconst);
      Photocathode_Reflectivity.push_back(reflectconst);
    }
  }
  else
    G4cout << "Error opening file: " << PMTfile << G4endl;
  ReadPMT.close();

  // Define PMT optical boundary surface properties
  auto OpticalPMT = new G4OpticalSurface("OpticalPMT");
  OpticalPMT->SetModel(glisur);
  OpticalPMT->SetFinish(polished);
  OpticalPMT->SetType(dielectric_metal);

  // Define PMT material properties
  auto PMT_MPT = new G4MaterialPropertiesTable();
  PMT_MPT->AddProperty("EFFICIENCY", Photocathode_Energy, Photocathode_Value);
  PMT_MPT->AddProperty("REFLECTIVITY", Photocathode_Energy, Photocathode_Reflectivity);
  PMT_MPT->AddProperty("RINDEX", Photocathode_Energy, Photocathode_Index);

  // Geometrical implementation of boundary surface
  OpticalPMT->SetMaterialPropertiesTable(PMT_MPT);
  auto SSPhotocathode = new G4LogicalSkinSurface("SSVikuiti", LogicalPhotocathode, OpticalPMT);

  // PMT photocathode placement
  auto PhysicalPhotocathode = new G4PVPlacement(G4Transform3D
                                           //(DontRotate,G4ThreeVector(FiberWidth/2 + FiberSpace - WidthBunchFibers/2, 0, Z_Position_Photocathode)), //USE THAT FOR TP
                                           //(DontRotate,G4ThreeVector((60-10)*mm, (30-12.1)*mm, Z_Position_Photocathode+300)), //USE THAT FOR DEBUG
                                           //(Flip,G4ThreeVector((280.5 + ZnSThickness + ScintillatorThickness + DetectorThickness/2)*mm, 7*mm, -5*mm)), //7.44mm for AIFIRA lens
                                           (Flip, G4ThreeVector((280.5 + ZnSThickness + ScintillatorThickness + 300 + DetectorThickness / 2) * mm, 7 * mm, -5 * mm)), // 7.44mm for AIFIRA lens
                                           //(Flip,G4ThreeVector((280.5 + ZnSThickness + ScintillatorThickness + FiberLength + DetectorThickness/2)*mm, 15*mm, 0)), //7.44mm for AIFIRA lens
                                           LogicalPhotocathode, "Objectif",
                                           LogicalHolder, true, 0);
}

void TPSimGeometry::ConstructSDandField()
{
  // magnetic field ----------------------------------------------------------
  fMagneticField = new TPSimMagneticField();
  fMagneticField->SetDipoleField(-MF_Value);
  fMagneticField->SetMapBFieldStatus(false);
  magneticFieldMgr = new G4FieldManager();
  magneticFieldMgr->SetDetectorField(fMagneticField);
  // Création du Chord Finder pour le champ magnétique
  G4Mag_UsualEqRhs *magEquation = new G4Mag_UsualEqRhs(fMagneticField);
  G4MagIntegratorStepper *magStepper = new G4ClassicalRK4(magEquation);
  G4ChordFinder *magChordFinder = new G4ChordFinder(fMagneticField, 1e-2 * CLHEP::mm, magStepper);
  magneticFieldMgr->SetChordFinder(magChordFinder);
  G4bool forceToAllDaughters = true;
  LogicalVolumeMFPlates->SetFieldManager(magneticFieldMgr, forceToAllDaughters);

  // Electric field ---------------------------------------------------------
  G4ElectricField *LocalfEMfield = new G4UniformElectricField(G4ThreeVector(0.0, EF_Value, 0.0));
  G4EqMagElectricField *LocalfEquation = new G4EqMagElectricField(LocalfEMfield);
  G4FieldManager *LocalFieldManager = new G4FieldManager(LocalfEMfield);
  G4ClassicalRK4 *localfStepper = new G4ClassicalRK4(LocalfEquation);
  G4IntegrationDriver<G4ClassicalRK4> *elIntegrationDriver = new G4IntegrationDriver<G4ClassicalRK4>(1e-2 * CLHEP::mm, localfStepper, localfStepper->GetNumberOfVariables());
  G4ChordFinder *fChordFinder = new G4ChordFinder(elIntegrationDriver);
  LocalFieldManager->SetChordFinder(fChordFinder);
  LogicalVolumeEFPlates->SetFieldManager(LocalFieldManager, forceToAllDaughters);
}

void TPSimGeometry::GetConfigValue()
{
  EF_Value = Geom->GetEFValue();
  EF_Dist_between_plates = Geom->GetDistBetweenPlates();
  EF_Thickness_plates = Geom->GetEFPlatesThickness();
  EF_Length_plates = Geom->GetEFPlatesLength();
  EF_Width_plates = Geom->GetEFPlatesWidth();
  MF_Value = Geom->GetMFValue();
  MF_Dist_between_plates = Geom->GetMFDistBetweenPlates();
  MF_Thickness_plates = Geom->GetMFPlatesThickness();
  MF_Length_plates = Geom->GetMFPlatesLength();
  MF_Width_plates = Geom->GetMFPlatesWidth();
  Dist_between_plates = Geom->GetDistBetweenPlates();
  Dist_EFPlates_Detector = Geom->GetEFPlatesDetector();
  Dist_pinhole_MFPlates = Geom->GetPinholeMFPlates();
  translation_pinhole = Geom->GetTranslationPinhole();
  ScintillatorThickness = Geom->GetScintillatorThickness();
  ZnSThickness = Geom->GetZnSThickness();
  ZnSLGThickness = Geom->GetZnSLGThickness();
  DetectorThickness = Geom->GetDetectorThickness();
  DetectorTranslation = Geom->GetDetectorTranslation();
  LensThickness = Geom->GetLensThickness();
  LensTranslation = Geom->GetLensTranslation();
  PinholeThickness = Geom->GetPinholeThickness();
  FiberLength = Geom->GetFiberLength();
  FiberWidth = Geom->GetFiberWidth();
  FiberCladdingRatio = Geom->GetFiberCladdingRatio();
  FiberNumberPerLine = Geom->GetFiberNumberPerLine();
  FiberSpace = Geom->GetFiberSpace();
  NbOfFibers = FiberNumberPerLine * FiberNumberPerLine;
  FiberSpacing = FiberWidth + FiberSpace;
  FiberGeometry = Geom->GetFiberGeometry();
  FiberMultiCladding = Geom->GetFiberMultiCladdingOption();
  FiberWidthCore = 0;
  if (FiberMultiCladding == 0)
    FiberWidthCore = FiberWidth - 2 * FiberCladdingRatio * FiberWidth;
  else if (FiberMultiCladding == 1)
  {
    FiberWidthCore = FiberWidth - 4 * FiberCladdingRatio * FiberWidth;
    FiberWidthCladding = FiberWidth - 2 * FiberCladdingRatio * FiberWidth;
  }
  else
    G4Exception("TPSim.cfg",
                "InvalidSetup", FatalException,
                "Fiber multi cladding option not well defined");
  WidthBunchFibers = FiberNumberPerLine * (FiberWidth) + (FiberNumberPerLine + 1) * FiberSpace;
  ActivationG4FAST = Geom->GetActivationG4FAST();
  lightyield = Geom->GetLightyield();
  lightyieldZnS = Geom->GetLightyieldZnS();
}

void TPSimGeometry::UpdateLightyield(G4Material *material, G4double lightyield)
{
  G4MaterialPropertiesTable *mpt = material->GetMaterialPropertiesTable();
  if (!mpt)
    return;

  mpt->AddConstProperty("SCINTILLATIONYIELD", lightyield / MeV);

  // Vous pouvez aussi mettre à jour d'autres propriétés comme l'absorption, la diffusion, etc.
  G4cout << "Mise à jour de la propriété optique : lightyield = " << lightyield << G4endl;
}

void TPSimGeometry::CreateScGeometry(G4double lightyield)
{
  G4RotationMatrix DontRotate;
  DontRotate.rotateX(0.0 * deg);

  // █▀ █▀▀   █▀█ ▄▀█ █▀█ ▀█▀
  // ▄█ █▄▄   █▀▀ █▀█ █▀▄ ░█░

  auto material = TPSimMaterials::getInstance()->getMaterial("EJ212");
  TPSimMaterials::getInstance()->printMaterialProperties(material);
  UpdateLightyield(material, lightyield);
  auto LogicalSc = Geom->GetScintillator(material);

  SetLogicalVolumeColor(LogicalSc, "orange");

  auto PhysicalSc = new G4PVPlacement(G4Transform3D
                                      //(DontRotate,G4ThreeVector((60-10)*mm, (30-12.1)*mm, Z_Position_Sc)), // Without GDML
                                      (DontRotate, G4ThreeVector(280.5 + ZnSThickness + ScintillatorThickness / 2, 15, -3.1)), // GDML
                                      LogicalSc, "Scintillator",
                                      LogicalHolder, false, 0);

  // ▀█ █▄░█ █▀   █▀█ ▄▀█ █▀█ ▀█▀
  // █▄ █░▀█ ▄█   █▀▀ █▀█ █▀▄ ░█░

  material = TPSimMaterials::getInstance()->getMaterial("ZnS");
  TPSimMaterials::getInstance()->printMaterialProperties(material);
  UpdateLightyield(material, lightyieldZnS);
  auto LogicalZnS = Geom->GetScintillator(material);

  // SetLogicalVolumeColor(LogicalZnS, "green");

  // PhysicalZnS = new G4PVPlacement(G4Transform3D(DontRotate, G4ThreeVector(280.5 + ZnSThickness / 2, 15 * mm, -3.1)), // Set at origin as basis of everything else
  //                                 LogicalZnS, "ZnS",
  //                                 LogicalHolder, false, 0);

  // PhysicalZnSLG = new G4PVPlacement(G4Transform3D
  //   (DontRotate,G4ThreeVector((60-10)*mm, (30-12.1)*mm, Z_Position_ZnSLG)), // Set at origin as basis of everything else
  //   LogicalZnSLG,"PMMA",
  //   LogicalHolder,false,0);
}

void TPSimGeometry::PrintMaterialProperties(G4MaterialPropertiesTable *mpt, const G4String &materialName)
{
  if (!mpt)
  {
    G4cout << "No properties found for material: " << materialName << G4endl;
    return;
  }

  G4cout << "Properties for material: " << materialName << G4endl;

  // mpt->DumpTable();

  // Ajoutez ici d'autres propriétés comme 'EFFICIENCY', 'REFLECTIVITY', etc.
}

// Main Function: Builds Full block, coupling, and PMT geometries
G4VPhysicalVolume *TPSimGeometry::Construct()
{
  G4GeometryManager::GetInstance()->OpenGeometry();
  G4PhysicalVolumeStore::GetInstance()->Clean();
  G4LogicalVolumeStore::GetInstance()->Clean();
  G4SolidStore::GetInstance()->Clean();

  std::lock_guard<std::mutex> lock(geometryMutex);
  // ConstructMaterials();
  //  Define common rotations

  // ***********************
  // Various dimensions
  // ***********************
  GetConfigValue();

  Z_Position_MFPlates = Dist_pinhole_MFPlates + MF_Length_plates / 2;
  Z_Position_EFPlates = Dist_pinhole_MFPlates + MF_Length_plates + Dist_between_plates + EF_Length_plates / 2;
  Z_Position_ZnS = Dist_pinhole_MFPlates + MF_Length_plates + Dist_between_plates + EF_Length_plates + Dist_EFPlates_Detector + ZnSThickness / 2;
  Z_Position_ZnSLG = Dist_pinhole_MFPlates + MF_Length_plates + Dist_between_plates + EF_Length_plates + Dist_EFPlates_Detector + ZnSThickness + ZnSLGThickness / 2;
  Z_Position_Sc = Dist_pinhole_MFPlates + MF_Length_plates + Dist_between_plates + EF_Length_plates + Dist_EFPlates_Detector + ZnSThickness + ScintillatorThickness / 2;
  // Z_Position_ZnSLG = Dist_pinhole_MFPlates + MF_Length_plates + Dist_between_plates + EF_Length_plates + Dist_EFPlates_Detector + ZnSThickness + ScintillatorThickness +ZnSLGThickness/2;
  // Z_Position_Fiber = Dist_pinhole_MFPlates + MF_Length_plates + Dist_between_plates + EF_Length_plates + Dist_EFPlates_Detector + FiberLength / 2;
  // Z_Position_Photocathode = PinholeThickness/2 + Dist_pinhole_MFPlates + MF_Length_plates + Dist_between_plates + EF_Length_plates + Dist_EFPlates_Detector + FiberLength + DetectorThickness/2;
  Z_Position_Photocathode = Dist_pinhole_MFPlates + MF_Length_plates + Dist_between_plates + EF_Length_plates + Dist_EFPlates_Detector + ZnSThickness + ScintillatorThickness + ZnSLGThickness + DetectorThickness / 2;
  // Z_Position_Photocathode = FiberLength/2 + LensTranslation + DetectorTranslation + DetectorThickness/2 ;

  // ############################
  //  DEFINE GEOMETRY PLACEMENTS#
  // ############################
  CreateWorldAndHolder();
  CreatePinholeGeometry();
  // CreateFibersGeometry();
  CreateRATPGeometry();
  CreateBFieldVolume();
  CreateEFieldVolume();
  CreateScGeometry(lightyield);

  //********************************************
  // Build optical properties and skin surfaces*
  //*********************** ********************
  // CreateMylarOpticalProperties();
  // CreateTeflonOpticalProperties();
  CreateDetectionOpticalProperties();

  // Returns world with everything in it and all properties set
  return PhysicalWorld;
}
