/// TPSimGeometry.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#ifndef TPSimGeometry_h
#define TPSimGeometry_h  1

#include "G4MaterialPropertiesTable.hh"

class GM;
class Coupling;
class PMT;
class GdL;
class TPSimMaterials;
class G4VPhysicalVolume;

#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4OpticalSurface.hh"
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
     GM *theScint;
     G4Material *Vacuum;
     G4Material *VacuumWorld;
     G4Material *Air;

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
     G4LogicalVolume *LogicalGM_LND;
     G4LogicalVolume *LogicalGM_Filtre1;
     G4LogicalVolume *LogicalGM_Filtre3;
     G4LogicalVolume *LogicalGM_Rondelle;
     G4LogicalVolume *LogicalGM_Isolant;
     G4LogicalVolume *LogicalGM_Gaine;
     G4LogicalVolume *LogicalGM_Gaz;
     G4LogicalVolume *LogicalGM_Plastique;

     G4LogicalVolume *LogicalSIGAM_MF_GM;
     G4LogicalVolume *LogicalSIGAM_MF_GM_Anode;
     G4LogicalVolume *LogicalSIGAM_MF_Gaz;
     G4LogicalVolume *LogicalSIGAM_MF_GM_Filtre1;
     G4LogicalVolume *LogicalSIGAM_MF_GM_Filtre2;
     G4LogicalVolume *LogicalSIGAM_MF_GM_Rondelle;
     G4LogicalVolume *LogicalSIGAM_MF_GM_Isolant;
     G4LogicalVolume *LogicalSIGAM_MF_GM_Gaine;
     G4LogicalVolume *LogicalSIGAM_MF_Gaine;
     G4LogicalVolume *LogicalSIGAM_MF_Corps_Cylindrique;
     G4LogicalVolume *LogicalSIGAM_MF_Bouchon_Cable;
     G4LogicalVolume *LogicalSIGAM_MF_Carte_Fille;
     G4LogicalVolume *LogicalSIGAM_MF_Connecteur;
     G4LogicalVolume *LogicalSIGAM_MF_Hexnut;
     G4LogicalVolume *LogicalSIGAM_MF_Joint1;
     G4LogicalVolume *LogicalSIGAM_MF_Joint2;
     G4LogicalVolume *LogicalSIGAM_MF_PCB;
     G4LogicalVolume *LogicalSIGAM_MF_Transfo;
     G4LogicalVolume *LogicalSIGAM_MF_Pile;
     G4LogicalVolume *LogicalSIGAM_MF_Mousse1;
     G4LogicalVolume *LogicalSIGAM_MF_Mousse2;
     G4LogicalVolume *LogicalSIGAM_MF_Socket1;
     G4LogicalVolume *LogicalSIGAM_MF_Socket2;
     G4LogicalVolume *LogicalSIGAM_MF_Socket3;
     G4LogicalVolume *LogicalSIGAM_MF_Vis;


     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_GM;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Filtre1;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Filtre2;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Rondelle;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Manchon;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Gaz;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Anode;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Calque;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Bouchon_Cable;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Connecteur;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Corps_Cylindrique;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_PCB;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Transfo;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Socket1;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Socket2;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Socket3;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Hexnut;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Joint1;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Joint2;
     G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Vis;


     G4LogicalVolume *LogicalSIGAM_HF_GM;
     G4LogicalVolume *LogicalSIGAM_HF_Compensation;
     G4LogicalVolume *LogicalSIGAM_HF_Gaz;
     G4LogicalVolume *LogicalSIGAM_HF_Rondelle;
     G4LogicalVolume *LogicalSIGAM_HF_Manchon;
     G4LogicalVolume *LogicalSIGAM_HF_Anode;
     G4LogicalVolume *LogicalSIGAM_HF_Corps_Cylindrique;
     G4LogicalVolume *LogicalSIGAM_HF_Bouchon_Cable;
     G4LogicalVolume *LogicalSIGAM_HF_Joint1;
     G4LogicalVolume *LogicalSIGAM_HF_Joint2;
     G4LogicalVolume *LogicalSIGAM_HF_Connecteur;
     G4LogicalVolume *LogicalSIGAM_HF_Vis;
     G4LogicalVolume *LogicalSIGAM_HF_PCB;
     G4LogicalVolume *LogicalSIGAM_HF_Hexnut;
     G4LogicalVolume *LogicalSIGAM_HF_Socket1;
     G4LogicalVolume *LogicalSIGAM_HF_Socket2;
     G4LogicalVolume *LogicalSIGAM_HF_Socket3;
     G4LogicalVolume *LogicalSIGAM_HF_Transfo;


     G4LogicalVolume *LogicalSIGAM_BF_GM;
     G4LogicalVolume *LogicalSIGAM_BF_Bague;
     G4LogicalVolume *LogicalSIGAM_BF_Compensation;
     G4LogicalVolume *LogicalSIGAM_BF_Anode;
     G4LogicalVolume *LogicalSIGAM_BF_Gaz;
     G4LogicalVolume *LogicalSIGAM_BF_Manchon;
     G4LogicalVolume *LogicalSIGAM_BF_Gaine;
     G4LogicalVolume *LogicalSIGAM_BF_Mousse;
     G4LogicalVolume *LogicalSIGAM_BF_Corps_Cylindrique;
     G4LogicalVolume *LogicalSIGAM_BF_Bouchon_Cable;
     G4LogicalVolume *LogicalSIGAM_BF_Connecteur;
     G4LogicalVolume *LogicalSIGAM_BF_Carte_Fille;
     G4LogicalVolume *LogicalSIGAM_BF_Transfo;
     G4LogicalVolume *LogicalSIGAM_BF_Joint1;
     G4LogicalVolume *LogicalSIGAM_BF_Joint2;
     G4LogicalVolume *LogicalSIGAM_BF_Socket1;
     G4LogicalVolume *LogicalSIGAM_BF_Socket2;
     G4LogicalVolume *LogicalSIGAM_BF_Socket3;
     G4LogicalVolume *LogicalSIGAM_BF_Hexnut;
     G4LogicalVolume *LogicalSIGAM_BF_PCB;
     G4LogicalVolume *LogicalSIGAM_BF_Pile;
     G4LogicalVolume *LogicalSIGAM_BF_Vis;


     G4LogicalVolume *LogicalDolphy_GM;
     G4LogicalVolume *LogicalDolphy_Anode;
     G4LogicalVolume *LogicalDolphy_Gaz;
     G4LogicalVolume *LogicalDolphy_Membrane;
     G4LogicalVolume *LogicalDolphy_Bague;
     G4LogicalVolume *LogicalDolphy_Ampoule;
     G4LogicalVolume *LogicalDolphy_Circuit_Imprime;
     G4LogicalVolume *LogicalDolphy_Bouton_Poussoir;
     G4LogicalVolume *LogicalDolphy_Buzzer;
     G4LogicalVolume *LogicalDolphy_CI;
     G4LogicalVolume *LogicalDolphy_Connecteur;
     G4LogicalVolume *LogicalDolphy_Ecran;
     G4LogicalVolume *LogicalDolphy_Ecrou;
     G4LogicalVolume *LogicalDolphy_Transfo;
     G4LogicalVolume *LogicalDolphy_Couvercle_Pile;
     G4LogicalVolume *LogicalDolphy_Pile;
     G4LogicalVolume *LogicalDolphy_Dessous;
     G4LogicalVolume *LogicalDolphy_Dessus;
     G4LogicalVolume *LogicalDolphy_Fenetre;
     G4LogicalVolume *LogicalDolphy_Grille;
     G4LogicalVolume *LogicalDolphy_Insert1;
     G4LogicalVolume *LogicalDolphy_Insert2;
     G4LogicalVolume *LogicalDolphy_Insert3;
     G4LogicalVolume *LogicalDolphy_Protection_Grille;
     G4LogicalVolume *LogicalDolphy_Protection_Grille_Test;
     G4LogicalVolume *LogicalDolphy_Rondelle_Protection;
     G4LogicalVolume *LogicalDolphy_Filtre_H10;
     G4LogicalVolume *LogicalDolphy_Mousse_GM;
     G4LogicalVolume *LogicalDolphy_Rondelle;
     G4LogicalVolume *LogicalDolphy_Support_Ressort1;
     G4LogicalVolume *LogicalDolphy_Support_Ressort2;
     G4LogicalVolume *LogicalDolphy_Vis_1;
     G4LogicalVolume *LogicalDolphy_Vis_2;
     G4LogicalVolume *LogicalDolphy_Vis_3;
     G4LogicalVolume *LogicalDolphy_Vis_4;
     G4LogicalVolume *LogicalDolphy_Vis_5;
     G4LogicalVolume *LogicalDolphy_Vis_6;
     G4LogicalVolume *LogicalDolphy_Vis_7;
     G4LogicalVolume *LogicalDolphy_Vis_8;
     G4LogicalVolume *LogicalDolphy_Vis_9;
     G4LogicalVolume *LogicalDolphy_Vis_10;
     G4LogicalVolume *LogicalDolphy_Vis_11;
     G4LogicalVolume *LogicalDolphy_Vis_12;


     // Physical volumes
     G4VPhysicalVolume *PhysicalWorld;
     G4VPhysicalVolume *PhysicalHolder;
     G4VPhysicalVolume *PhysicalGM_LND;
     G4VPhysicalVolume *PhysicalGM_Filtre1;
     G4VPhysicalVolume *PhysicalGM_Filtre3;
     G4VPhysicalVolume *PhysicalGM_Rondelle;
     G4VPhysicalVolume *PhysicalGM_Isolant;
     G4VPhysicalVolume *PhysicalGM_Gaine;
     G4VPhysicalVolume *PhysicalGM_Gaz;
     G4VPhysicalVolume *PhysicalGM_Plastique;

     G4VPhysicalVolume *PhysicalSIGAM_MF_GM;
     G4VPhysicalVolume *PhysicalSIGAM_MF_GM_Anode;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Gaz;
     G4VPhysicalVolume *PhysicalSIGAM_MF_GM_Filtre1;
     G4VPhysicalVolume *PhysicalSIGAM_MF_GM_Filtre2;
     G4VPhysicalVolume *PhysicalSIGAM_MF_GM_Rondelle;
     G4VPhysicalVolume *PhysicalSIGAM_MF_GM_Isolant;
     G4VPhysicalVolume *PhysicalSIGAM_MF_GM_Gaine;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Gaine;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Corps_Cylindrique;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Bouchon_Cable;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Carte_Fille;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Connecteur;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Hexnut;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Joint1;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Joint2;
     G4VPhysicalVolume *PhysicalSIGAM_MF_PCB;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Transfo;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Pile;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Mousse1;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Mousse2;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Socket1;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Socket2;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Socket3;
     G4VPhysicalVolume *PhysicalSIGAM_MF_Vis;


     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_GM;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Filtre1;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Filtre2;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Rondelle;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Gaz;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Manchon;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Anode;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Calque;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Bouchon_Cable;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Connecteur;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Corps_Cylindrique;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_PCB;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Transfo;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Socket1;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Socket2;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Socket3;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Hexnut;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Joint1;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Joint2;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Carmelec_Vis;


     G4VPhysicalVolume *PhysicalSIGAM_HF_GM;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Gaz;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Compensation;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Rondelle;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Manchon;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Anode;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Corps_Cylindrique;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Bouchon_Cable;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Joint1;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Joint2;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Connecteur;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Vis;
     G4VPhysicalVolume *PhysicalSIGAM_HF_PCB;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Hexnut;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Socket1;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Socket2;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Socket3;
     G4VPhysicalVolume *PhysicalSIGAM_HF_Transfo;


     G4VPhysicalVolume *PhysicalSIGAM_BF_GM;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Bague;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Compensation;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Anode;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Gaz;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Manchon;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Gaine;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Mousse;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Corps_Cylindrique;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Bouchon_Cable;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Connecteur;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Carte_Fille;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Transfo;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Joint1;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Joint2;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Socket1;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Socket2;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Socket3;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Hexnut;
     G4VPhysicalVolume *PhysicalSIGAM_BF_PCB;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Pile;
     G4VPhysicalVolume *PhysicalSIGAM_BF_Vis;


     G4VPhysicalVolume *PhysicalDolphy_GM;
     G4VPhysicalVolume *PhysicalDolphy_Anode;
     G4VPhysicalVolume *PhysicalDolphy_Gaz;
     G4VPhysicalVolume *PhysicalDolphy_Membrane;
     G4VPhysicalVolume *PhysicalDolphy_Bague;
     G4VPhysicalVolume *PhysicalDolphy_Ampoule;
     G4VPhysicalVolume *PhysicalDolphy_Circuit_Imprime;
     G4VPhysicalVolume *PhysicalDolphy_Bouton_Poussoir;
     G4VPhysicalVolume *PhysicalDolphy_Buzzer;
     G4VPhysicalVolume *PhysicalDolphy_CI;
     G4VPhysicalVolume *PhysicalDolphy_Connecteur;
     G4VPhysicalVolume *PhysicalDolphy_Ecran;
     G4VPhysicalVolume *PhysicalDolphy_Ecrou;
     G4VPhysicalVolume *PhysicalDolphy_Transfo;
     G4VPhysicalVolume *PhysicalDolphy_Couvercle_Pile;
     G4VPhysicalVolume *PhysicalDolphy_Pile;
     G4VPhysicalVolume *PhysicalDolphy_Dessous;
     G4VPhysicalVolume *PhysicalDolphy_Dessus;
     G4VPhysicalVolume *PhysicalDolphy_Fenetre;
     G4VPhysicalVolume *PhysicalDolphy_Grille;
     G4VPhysicalVolume *PhysicalDolphy_Insert1;
     G4VPhysicalVolume *PhysicalDolphy_Insert2;
     G4VPhysicalVolume *PhysicalDolphy_Insert3;
     G4VPhysicalVolume *PhysicalDolphy_Protection_Grille;
     G4VPhysicalVolume *PhysicalDolphy_Protection_Grille_Test;
     G4VPhysicalVolume *PhysicalDolphy_Rondelle_Protection;
     G4VPhysicalVolume *PhysicalDolphy_Filtre_H10;
     G4VPhysicalVolume *PhysicalDolphy_Mousse_GM;
     G4VPhysicalVolume *PhysicalDolphy_Rondelle;
     G4VPhysicalVolume *PhysicalDolphy_Support_Ressort1;
     G4VPhysicalVolume *PhysicalDolphy_Support_Ressort2;
     G4VPhysicalVolume *PhysicalDolphy_Vis_1;
     G4VPhysicalVolume *PhysicalDolphy_Vis_2;
     G4VPhysicalVolume *PhysicalDolphy_Vis_3;
     G4VPhysicalVolume *PhysicalDolphy_Vis_4;
     G4VPhysicalVolume *PhysicalDolphy_Vis_5;
     G4VPhysicalVolume *PhysicalDolphy_Vis_6;
     G4VPhysicalVolume *PhysicalDolphy_Vis_7;
     G4VPhysicalVolume *PhysicalDolphy_Vis_8;
     G4VPhysicalVolume *PhysicalDolphy_Vis_9;
     G4VPhysicalVolume *PhysicalDolphy_Vis_10;
     G4VPhysicalVolume *PhysicalDolphy_Vis_11;
     G4VPhysicalVolume *PhysicalDolphy_Vis_12;


     // // Optical surfaces
     // G4OpticalSurface *OpticalTeflon;
     // G4OpticalSurface *OpticalSc;
     // G4OpticalSurface *OpticalMylar;
     // G4OpticalSurface *OpticalVikuiti;
     // G4OpticalSurface *OpticalPMT;

     // // Skin surfaces
     // G4LogicalSkinSurface *SSTeflon;
     // G4LogicalSkinSurface *SSMylar;
     // G4LogicalSkinSurface *SSWrapLightGuide;
     // G4LogicalSkinSurface *SSWrapInterfaceLightGuide;
     // G4LogicalSkinSurface *SSPhotocathode;
     // G4LogicalSkinSurface *SSScintillateur;


     // // Material properties tables
     // G4MaterialPropertiesTable *TeflonMPT;
     // G4MaterialPropertiesTable *MylarMPT;
     // G4MaterialPropertiesTable *VikuitiMPT;
     // G4MaterialPropertiesTable *PMT_MPT;

  };
#endif
