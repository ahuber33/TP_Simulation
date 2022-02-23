/// GM.hh
//// Auteur: Arnaud HUBER for ENL group <huber@cenbg.in2p3.fr> 
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

// This class is used to create a plastic scintillator.

#ifndef GM_h
#define GM_h

#include "G4LogicalVolume.hh"
#include "G4MaterialPropertiesTable.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "CLHEP/Units/SystemOfUnits.h"

class TPSimMaterials;
class GM

{
public:

  //constructor, builds from keys specified in buildfile
  GM(G4String buildfile);
  ~GM();
  //  void Construct();
  
public:

  // Functions to call this geometry in x_blockGeometry.cc

  G4LogicalVolume *GetGM_LND();
  G4LogicalVolume *GetGM_Filtre1();
  G4LogicalVolume *GetGM_Filtre3();
  G4LogicalVolume *GetGM_Rondelle();
  G4LogicalVolume *GetGM_Isolant();
  G4LogicalVolume *GetGM_Gaine();
  G4LogicalVolume *GetGM_Gaz();
  G4LogicalVolume *GetGM_Plastique();

  G4LogicalVolume *GetSIGAM_MF_GM();
  G4LogicalVolume *GetSIGAM_MF_GM_Anode();
  G4LogicalVolume *GetSIGAM_MF_Gaz();
  G4LogicalVolume *GetSIGAM_MF_GM_Filtre1();
  G4LogicalVolume *GetSIGAM_MF_GM_Filtre2();
  G4LogicalVolume *GetSIGAM_MF_GM_Rondelle();
  G4LogicalVolume *GetSIGAM_MF_GM_Isolant();
  G4LogicalVolume *GetSIGAM_MF_GM_Gaine();
  G4LogicalVolume *GetSIGAM_MF_Gaine();
  G4LogicalVolume *GetSIGAM_MF_Corps_Cylindrique();
  G4LogicalVolume *GetSIGAM_MF_Bouchon_Cable();
  G4LogicalVolume *GetSIGAM_MF_Carte_Fille();
  G4LogicalVolume *GetSIGAM_MF_Connecteur();
  G4LogicalVolume *GetSIGAM_MF_Hexnut();
  G4LogicalVolume *GetSIGAM_MF_Joint1();
  G4LogicalVolume *GetSIGAM_MF_Joint2();
  G4LogicalVolume *GetSIGAM_MF_PCB();
  G4LogicalVolume *GetSIGAM_MF_Transfo();
  G4LogicalVolume *GetSIGAM_MF_Pile();
  G4LogicalVolume *GetSIGAM_MF_Mousse1();
  G4LogicalVolume *GetSIGAM_MF_Mousse2();
  G4LogicalVolume *GetSIGAM_MF_Socket1();
  G4LogicalVolume *GetSIGAM_MF_Socket2();
  G4LogicalVolume *GetSIGAM_MF_Socket3();
  G4LogicalVolume *GetSIGAM_MF_Vis();


  G4LogicalVolume *GetSIGAM_HF_Carmelec_GM();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Filtre1();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Filtre2();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Rondelle();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Gaz();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Manchon();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Anode();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Calque();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Bouchon_Cable();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Connecteur();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Corps_Cylindrique();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_PCB();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Transfo();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Socket1();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Socket2();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Socket3();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Hexnut();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Joint1();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Joint2();
  G4LogicalVolume *GetSIGAM_HF_Carmelec_Vis();


  G4LogicalVolume *GetSIGAM_HF_GM();
  G4LogicalVolume *GetSIGAM_HF_Gaz();
  G4LogicalVolume *GetSIGAM_HF_Compensation();
  G4LogicalVolume *GetSIGAM_HF_Rondelle();
  G4LogicalVolume *GetSIGAM_HF_Manchon();
  G4LogicalVolume *GetSIGAM_HF_Anode();
  G4LogicalVolume *GetSIGAM_HF_Corps_Cylindrique();
  G4LogicalVolume *GetSIGAM_HF_Bouchon_Cable();
  G4LogicalVolume *GetSIGAM_HF_Joint1();
  G4LogicalVolume *GetSIGAM_HF_Joint2();
  G4LogicalVolume *GetSIGAM_HF_Connecteur();
  G4LogicalVolume *GetSIGAM_HF_Vis();
  G4LogicalVolume *GetSIGAM_HF_PCB();
  G4LogicalVolume *GetSIGAM_HF_Hexnut();
  G4LogicalVolume *GetSIGAM_HF_Socket1();
  G4LogicalVolume *GetSIGAM_HF_Socket2();
  G4LogicalVolume *GetSIGAM_HF_Socket3();
  G4LogicalVolume *GetSIGAM_HF_Transfo();


  G4LogicalVolume *GetSIGAM_BF_GM();
  G4LogicalVolume *GetSIGAM_BF_Compensation();
  G4LogicalVolume *GetSIGAM_BF_Bague();
  G4LogicalVolume *GetSIGAM_BF_Anode();
  G4LogicalVolume *GetSIGAM_BF_Gaz();
  G4LogicalVolume *GetSIGAM_BF_Manchon();
  G4LogicalVolume *GetSIGAM_BF_Gaine();
  G4LogicalVolume *GetSIGAM_BF_Mousse();
  G4LogicalVolume *GetSIGAM_BF_Corps_Cylindrique();
  G4LogicalVolume *GetSIGAM_BF_Bouchon_Cable();
  G4LogicalVolume *GetSIGAM_BF_Connecteur();
  G4LogicalVolume *GetSIGAM_BF_Carte_Fille();
  G4LogicalVolume *GetSIGAM_BF_Transfo();
  G4LogicalVolume *GetSIGAM_BF_Joint1();
  G4LogicalVolume *GetSIGAM_BF_Joint2();
  G4LogicalVolume *GetSIGAM_BF_Socket1();
  G4LogicalVolume *GetSIGAM_BF_Socket2();
  G4LogicalVolume *GetSIGAM_BF_Socket3();
  G4LogicalVolume *GetSIGAM_BF_Hexnut();
  G4LogicalVolume *GetSIGAM_BF_PCB();
  G4LogicalVolume *GetSIGAM_BF_Pile();
  G4LogicalVolume *GetSIGAM_BF_Vis();

  G4LogicalVolume *GetDolphy_GM();
  G4LogicalVolume *GetDolphy_Anode();
  G4LogicalVolume *GetDolphy_Membrane();
  G4LogicalVolume *GetDolphy_Gaz();
  G4LogicalVolume *GetDolphy_Bague();
  G4LogicalVolume *GetDolphy_Ampoule();
  G4LogicalVolume *GetDolphy_Circuit_Imprime();
  G4LogicalVolume *GetDolphy_Bouton_Poussoir();
  G4LogicalVolume *GetDolphy_Buzzer();
  G4LogicalVolume *GetDolphy_CI();
  G4LogicalVolume *GetDolphy_Connecteur();
  G4LogicalVolume *GetDolphy_Ecran();
  G4LogicalVolume *GetDolphy_Ecrou();
  G4LogicalVolume *GetDolphy_Transfo();
  G4LogicalVolume *GetDolphy_Couvercle_Pile();
  G4LogicalVolume *GetDolphy_Pile();
  G4LogicalVolume *GetDolphy_Dessous();
  G4LogicalVolume *GetDolphy_Dessus();
  G4LogicalVolume *GetDolphy_Fenetre();
  G4LogicalVolume *GetDolphy_Grille();
  G4LogicalVolume *GetDolphy_Insert1();
  G4LogicalVolume *GetDolphy_Insert2();
  G4LogicalVolume *GetDolphy_Insert3();
  G4LogicalVolume *GetDolphy_Protection_Grille();
  G4LogicalVolume *GetDolphy_Protection_Grille_Test();
  G4LogicalVolume *GetDolphy_Rondelle_Protection();
  G4LogicalVolume *GetDolphy_Filtre_H10();
  G4LogicalVolume *GetDolphy_Mousse_GM();
  G4LogicalVolume *GetDolphy_Rondelle();
  G4LogicalVolume *GetDolphy_Support_Ressort1();
  G4LogicalVolume *GetDolphy_Support_Ressort2();
  G4LogicalVolume *GetDolphy_Vis1();
  G4LogicalVolume *GetDolphy_Vis2();
  G4LogicalVolume *GetDolphy_Vis3();
  G4LogicalVolume *GetDolphy_Vis4();
  G4LogicalVolume *GetDolphy_Vis5();
  G4LogicalVolume *GetDolphy_Vis6();
  G4LogicalVolume *GetDolphy_Vis7();
  G4LogicalVolume *GetDolphy_Vis8();
  G4LogicalVolume *GetDolphy_Vis9();
  G4LogicalVolume *GetDolphy_Vis10();
  G4LogicalVolume *GetDolphy_Vis11();
  G4LogicalVolume *GetDolphy_Vis12();



private:

 
  GM *theScint;
  TPSimMaterials* scintProp;

  static const G4String path_bin;


  // Materials
  G4Material *scintillator;
  G4Material *Plastic;
  G4Material *Mylar;
  G4Material *Fer;
  G4Material *Polystyrene;
  G4Material *coating;
  G4Material *Vacuum;
  G4Material *PMMA;
  G4Material *Acier;
  G4Material *Inox;
  G4Material *N2;
  G4Material *Cuivre;
  G4Material *Kapton;
  G4Material *Air;
  G4Material *Polypropylene;
  G4Material *Papier;
  G4Material *Compensation;
  G4Material *Nylon;
  G4Material *Alu_Coque_Cylindrique;
  G4Material *Alu;
  G4Material *teflon;
  G4Material *mousse;
  G4Material *Neoprene;
  G4Material *Mica;
  G4Material *Plomb_Antimoine;

  // Logical Volumes
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
  G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Gaz;
  G4LogicalVolume *LogicalSIGAM_HF_Carmelec_Manchon;
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
  G4LogicalVolume *LogicalSIGAM_HF_Gaz;
  G4LogicalVolume *LogicalSIGAM_HF_Compensation;
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
  G4LogicalVolume *LogicalDolphy_Membrane;
  G4LogicalVolume *LogicalDolphy_Gaz;
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




  // Other
  G4VisAttributes *clear;

};
#endif
