/// TPSimMaterials.cc
/// Auteur: Arnaud HUBER <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimMaterials.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4MaterialPropertiesTable.hh"
#include "G4MaterialPropertyVector.hh"
#include "G4NistManager.hh"
#include <fstream>
#include <iostream>
#include "G4UnitsTable.hh"
#include "G4ThreeVector.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4Scintillation.hh"

using namespace CLHEP;

const G4String TPSimMaterials::path = "../simulation_input_files/";

// Used to set up all material properties.  Some materials
// are left over from previous simulations and may not be
// needed.  Code to read in material properties from file
// is poorly done.  Can improve using vectors.  Careful of
// memory leaks.  Careful of files and how they are read in.

TPSimMaterials::TPSimMaterials(G4String prop_buildfile):bs_glass(0),
							      polysty(0),
							      Ti02(0),
							      coating(0),
							      scintillator(0),
							      Vacuum(0),
							      plastic(0),
							      mylar(0),
							      grease(0),
							      cargille(0),
							      PMMA(0)


{


  //G4cout << "Test" << G4endl;

  std::ifstream config_prop;
  config_prop.open(prop_buildfile);
  if (!config_prop.is_open())
    G4cout << "Error opening file " << prop_buildfile << G4endl;
  else{
          //G4cout << "Accessing the properties file. " << G4endl;

    while(!config_prop.eof()){
      G4String variable,unit;
      G4double value;

      config_prop >> variable;
      if(!config_prop.good()) break;
      if(variable == "scintIndexconst")
	{
	  config_prop>>scintIndexconst;
	}
      if(variable == "scalingfactor_low")
	{
	  config_prop>>scalingfactor_low;
	}
      if(variable == "scalingfactor_high")
	{
	  config_prop>>scalingfactor_high;
	}
      if(variable == "pop_scalingfactor_low")
	{
	  config_prop>>pop_scalingfactor_low;
	}
      if(variable == "pop_scalingfactor_high")
	{
	  config_prop>>pop_scalingfactor_high;
	}
      if(variable == "lightyield")
	{
	  config_prop>>lightyield;
	}
      if(variable == "paint_ref_coeff")
	{
	  config_prop>>paint_ref_coeff;
	}
      if(variable == "mylar_ref_coeff")
	{
	  config_prop>>mylar_ref_coeff;
	}
      else if(variable == "scintAbsorbconst")
	{
	  config_prop >> value >> unit;
	  scintAbsorbconst = value*G4UnitDefinition::GetValueOf(unit);
	}

    }
  }

  config_prop.close();
  Construct();


}

TPSimMaterials::~TPSimMaterials()
{
  if(scintillator) { delete scintillator; scintillator = 0; }
  if (Vacuum){ delete Vacuum; Vacuum = 0; }
  if (polysty){ delete polysty; polysty = 0; }
  if (coating){ delete coating; coating = 0; }
  if (Ti02){ delete Ti02; Ti02 = 0; }
  if (plastic){ delete plastic; plastic = 0; }
  if (mylar){ delete mylar; mylar = 0; }
  if (grease){ delete grease; grease = 0; }
  if (bs_glass){ delete bs_glass; bs_glass = 0; }
  if (PMMA){ delete PMMA; PMMA = 0;}
}


void TPSimMaterials::Construct()
{

  G4double R = 8.3144621; //(en J/K/mole => Constante gaz parfait)
  G4double T = 273.15; //en K

  //Define the Elements

  elementH = new G4Element( "Hydrogen", "H", 1, 1.00794*g/mole );
  elementC = new G4Element( "Carbon", "C", 6, 12.011*g/mole );
  elementCl = new G4Element( "Chlore", "Cl", 6, 35.453*g/mole );
  elementO = new G4Element( "Oxygen", "O", 8, 15.9994*g/mole );
  elementTi = new G4Element( "Titanium","Ti", 22, 47.88*g/mole);
  elementSi = new G4Element("Silicon","Si",14,28.0855*g/mole);
  elementB = new G4Element("Boron","B",5,10.811*g/mole);
  elementNa = new G4Element("Sodium","Na",11,22.989770*g/mole);
  elementAl = new G4Element("Aluminum","Al",13,26.981538*g/mole);
  elementFe = new G4Element ("Fer", "Fe", 26., 55.845*g/mole);
  elementNi = new G4Element ("Nickel", "Nickel", 28., 58.6939*g/mole);
  elementCr = new G4Element ("Chrome", "Chrome", 24., 51.9961*g/mole);
  elementMn = new G4Element ("Manganese", "Manganese", 25., 54.938044*g/mole);
  elementCu = new G4Element ("Cuivre", "Cuivre", 29., 63.546*g/mole);
  elementSn = new G4Element ("Etain", "Etain", 50., 118.71*g/mole);
  elementSb = new G4Element ("Antimoine", "Antimoine", 51., 121.760*g/mole);
  elementMg = new G4Element ("Magnesium", "Magnesium", 12., 24.305*g/mole);
  elementZn = new G4Element ("Zinc", "Zinc", 30., 65.38*g/mole);
  elementK = new G4Element ("Potassium", "Potassium", 19., 39.0983*g/mole);
  elementN = new G4Element ("Nitrogen", "N", 7., 14.01*g/mole);
  elementPb = new G4Element ("Plomb", "Plomb", 82., 207.2*g/mole);
  // G4Isotope* N14 = new G4Isotope("N14", 7, 14);
  // elementN = new G4Element("Azote", "Azote", 1);
  // elementN->AddIsotope(N14, 100.*perCent);

  // DiAzote
  G4double M_mole_N2 = 2*14; //en g/mole
  G4double Pression = 100000; //(en Pa => 1 bar = 100 000 Pa)
  N2 = new G4Material("Diazote", ((Pression * M_mole_N2)/(R*T))*g/m3, 1, kStateGas, T, (Pression*0.00000986923*atmosphere));
  N2->AddElement(elementN,2);


  H2O = new G4Material("Eau", 1.000*g/cm3, 2);
  H2O->AddElement(elementH, 2);
  H2O->AddElement(elementO, 1);

  Polypropylene = new G4Material("Polypropylene", 0.900*g/cm3, 2);
  Polypropylene->AddElement(elementC, 3);
  Polypropylene->AddElement(elementH, 6);

  Neoprene = new G4Material("Neoprene", 1.23*g/cm3, 3);
  Neoprene->AddElement(elementC, 4);
  Neoprene->AddElement(elementH, 5);
  Neoprene->AddElement(elementCl, 1);

  Papier = new G4Material("Papier", 1.2*g/cm3, 3);
  Papier->AddElement(elementC, 6);
  Papier->AddElement(elementH, 10);
  Papier->AddElement(elementO, 5);

  // Plomb Antimoine
  Plomb_Antimoine = new G4Material("Plomb_Antimoine"  , 11.04*g/cm3, 2);
  Plomb_Antimoine->AddElement(elementPb, 0.96);
  Plomb_Antimoine->AddElement(elementSb, 0.04);


  plastic = new G4Material("plastic",
			   1.3*g/cm3,
			   2,
			   kStateSolid,
			   273.15*kelvin,
			   1.0*atmosphere );

  plastic->AddElement( elementH, 0.498 );
  plastic->AddElement( elementC, 0.502 );


  Nylon = new G4Material("Nylon",
			   1.4*g/cm3,
			 4);

  Nylon->AddElement( elementH, 22 );
  Nylon->AddElement( elementC, 12 );
  Nylon->AddElement( elementN, 2 );
  Nylon->AddElement( elementO, 2 );



  Compensation = new G4Material("Compensation", 7.25*g/cm3, 2);
  Compensation->AddElement(elementSn,0.95);
  Compensation->AddElement(elementSb,0.05);


  // Kapton = new G4Material("Kapton", 1.39*g/cm3, 3);
  // Kapton->AddElement(elementO,2);
  // Kapton->AddElement(elementC,5);
  // Kapton->AddElement(elementH,4);

  Kapton = new G4Material("Kapton", 1.413*g/cm3, 4);
  Kapton->AddElement(elementO,5);
  Kapton->AddElement(elementC,22);
  Kapton->AddElement(elementN,2);
  Kapton->AddElement(elementH,10);



  Acier = new G4Material("Acier", 7.86*g/cm3, 2);
  Acier->AddElement(elementFe, 0.99);
  Acier->AddElement(elementC, 0.01);

  Inox = new G4Material("Inox",8.06*g/cm3, 6);
  Inox->AddElement(elementC, 0.001);
  Inox->AddElement(elementSi, 0.007);
  Inox->AddElement(elementCr, 0.18);
  Inox->AddElement(elementMn, 0.01);
  Inox->AddElement(elementFe, 0.712);
  Inox->AddElement(elementNi, 0.09);

  // AIR
  Air = new G4Material("Air"  , 1.290*mg/cm3, 2);
  Air->AddElement(elementN, 0.7);
  Air->AddElement(elementO, 0.3);

  // FER
  Fer = new G4Material("Fer"  , 7.87*g/cm3, 1);
  Fer->AddElement(elementFe, 1);

	// Carbon
  Carbon = new G4Material("Carbon"  , 2.0*g/cm3, 1);
  Carbon->AddElement(elementC, 1);

  // FER
  Cuivre = new G4Material("Cuivre"  , 8.96*g/cm3, 1);
  Cuivre->AddElement(elementCu, 1);


  // ALU COQUE SIGAM
  Alu_Coque_SIGAM = new G4Material("Alu_Coque_SIGAM", 2.8*g/cm3, 8);
  Alu_Coque_SIGAM->AddElement(elementAl, 0.9325);
  Alu_Coque_SIGAM->AddElement(elementCu, 0.04);
  Alu_Coque_SIGAM->AddElement(elementMn, 0.007);
  Alu_Coque_SIGAM->AddElement(elementMg, 0.007);
  Alu_Coque_SIGAM->AddElement(elementSi, 0.005);
  Alu_Coque_SIGAM->AddElement(elementFe, 0.005);
  Alu_Coque_SIGAM->AddElement(elementZn, 0.0025);
  Alu_Coque_SIGAM->AddElement(elementCr, 0.001);




  //Aluminium plates
  Alu = new G4Material("Alu", 2.6989*g/cm3, 1, kStateSolid);
  Alu->AddElement(elementAl, 1);

  //Mylar
  mylar = new G4Material("mylar", 1.40*g/cm3, 3);
  mylar->AddElement(elementH, 4);
  mylar->AddElement(elementC, 5);
  mylar->AddElement(elementO, 2);


  //Teflon
  teflon = new G4Material("teflon", 0.40*g/cm3, 4);
  teflon->AddElement(elementH, 6);
  teflon->AddElement(elementC, 2);
  teflon->AddElement(elementO, 1);
  teflon->AddElement(elementSi, 1);


  //Mousse
  mousse = new G4Material("mousse", 40*kg/m3, 4);
  mousse->AddElement(elementH, 6);
  mousse->AddElement(elementC, 2);
  mousse->AddElement(elementO, 1);
  mousse->AddElement(elementSi, 1);



  Mica = new G4Material("Mica", 1.75*g/cm3, 7);
  Mica->AddElement(elementO, 24);
  Mica->AddElement(elementH, 4);
  Mica->AddElement(elementAl, 2);
  Mica->AddElement(elementSi, 6);
  Mica->AddElement(elementMg, 6);
  Mica->AddElement(elementFe, 6);
  Mica->AddElement(elementK, 2);



	//Scintillator *******************************************************

 scintillator = new G4Material("scintillator",
			 1.032*g/cm3, //1.053
			 2,
			 kStateSolid,
			 273.15*kelvin,
			 1.0*atmosphere );

 scintMPT = new G4MaterialPropertiesTable();

 scintillator->AddElement( elementH, 10);
 //scintillator->AddElement( elementH, 0.5 );
 scintillator->AddElement( elementC, 9);
 //scintillator->AddElement( elementC, 0.5 );


 // G4int absorbEntries = 0;
 // G4int wlsAbEntries  = 0;
 // G4int wlsEmEntries  = 0;
 // G4double varabsorblength;
 // G4double absorbEnergy[500];
 // G4double Absorb[500];
 // G4double wlsEnergy[500];
 // G4double wlsEmit[500];
 // G4double wlsAbsorb[500];
 // G4double scintEnergy[500];
 // G4double scintEmit[500];
 // G4double scintAbsorb[500];
 // G4double scintSlow[500];
 // G4double ref_index_Energy[500];
 // G4double ref_index_value[500];
 // G4double wlsabsorblength;
 //
 // for (int i = 0; i < 500; i++){
	//  wlsEnergy[i] = 0;
	//  wlsEmit[i] = 0;
	//  wlsAbsorb[i] = 0;
	//  scintEnergy[i] = 0;
	//  scintEmit[i] = 0;
	//  scintAbsorb[i] = 0;
	//  scintSlow[i] = 0;
	//  ref_index_Energy[i]  =  0;
	//  ref_index_value[i] = 0;
 // }
 //
 // // Read primary emission spectrum
 //
 // G4int scintEntries = 0;
 // std::ifstream ReadScint;
 //
 // G4String Scint_file = path+"pTP_emission.dat";
 //
 //
 // ReadScint.open(Scint_file);
 // if(ReadScint.is_open()){
	//  while(!ReadScint.eof()){
	// 	 G4String filler;
	// 	 ReadScint >> pWavelength >> filler >> scintEmit[scintEntries];
	// 	 scintEnergy[scintEntries] = (1240/pWavelength)*eV;         //convert wavelength to eV
	// 	 // scintIndex[scintEntries] = scintIndexconst;                //read from Scintillator.cfg if you want constant.
	// 	 // scintAbsorb[scintEntries] = scintAbsorbconst;              //read from Scintillator.cfg or check bulk absorb below
	// 	 scintSlow[scintEntries] = 0.0;
	// 	 scintEntries++;
	//  }
 // }
 // else
	//  {
	// 	 G4cout << "Error opening file: " << Scint_file << G4endl;
	//  }
 // ReadScint.close();
 //
 // // Read primary bulk absorption
 //
 // absorbEntries = 0;
 // std::ifstream Readabsorb;
	//  G4String Readabsorblength = path+"PSTBulkAbsorb.cfg";
 //
 //
 // Readabsorb.open(Readabsorblength);
 // if (Readabsorb.is_open()){
	//  while(!Readabsorb.eof()){
	// 	 G4String filler;
	// 	 Readabsorb >> pWavelength >> filler >> varabsorblength;
	// 	 absorbEnergy[absorbEntries] = (1240/pWavelength)*eV;
	// 	 Absorb[absorbEntries] = 1*1.3*varabsorblength*m; //MW
	// 	 //Absorb[absorbEntries] = 0.31*varabsorblength*m; //XW 0.31
 //
 //
	// 	 absorbEntries++;
	//  }
 // }
 // else
 //
	// 	 G4cout << "Error opening file: "<< Readabsorblength << G4endl;
 //
 // Readabsorb.close();
 //
 // // Read WLS absorption
 //
 // wlsAbEntries = 0;
 // std::ifstream ReadWLSa;
 // G4String WLSabsorb = path+"UPS923.cfg";
 //
 // ReadWLSa.open(WLSabsorb);
 // if (ReadWLSa.is_open()){
	//  while(!ReadWLSa.eof()){
	// 	 G4String filler;
	// 	 ReadWLSa>>pWavelength>>filler>>wlsabsorblength;
	// 	 wlsEnergy[wlsAbEntries] = (1240/pWavelength)*eV;
 //
 //
	// 	 if (wlsAbEntries < 200){
 // wlsAbsorb[wlsAbEntries] = wlsabsorblength*m;
	// 	 }
	// 	 else{
 // wlsAbsorb[wlsAbEntries] = wlsabsorblength*m;
	// 	 }
 //
	// 	 wlsAbEntries++;
	//  }
 // }
 // else
	//  {
	// 	 G4cout << "Error opening file: " << WLSabsorb << G4endl;
	//  }
 //
 // ReadWLSa.close();
 //
 // // Read WLS emission
 //
 // wlsEmEntries = 0;
 // std::ifstream ReadWLSe;
 // G4String WLSemit = path+"full_popop_emission.cfg";
 // ReadWLSe.open(WLSemit);
 // if(ReadWLSe.is_open()){
	//  while(!ReadWLSe.eof()){
	// 	 G4String filler;
	// 	 ReadWLSe >> pWavelength >> filler >> wlsEmit[wlsEmEntries];
	// 	 wlsEnergy[wlsEmEntries] = (1240/pWavelength)*eV;
	// 	 wlsEmEntries++;
	//  }
 // }
 // else
	//  G4cout << "Error opening file: " << WLSemit << G4endl;
 // ReadWLSe.close();
 //
 // // Read scintillator refractive index
 //
 // G4int ref_index_Entries = 0;
 //
 // std::ifstream Read_ref_index;
 // //G4String ref_index_emit = path+"PST_ref_index.dat";
 // G4String ref_index_emit = path+"PS_index_geant.dat";
 // Read_ref_index.open(ref_index_emit);
 // if(Read_ref_index.is_open()){
	//  while(!Read_ref_index.eof()){
	// 	 G4String filler;
	// 	 Read_ref_index >> pWavelength >> filler >> ref_index_value[ref_index_Entries];
	// 	 //ref_index_value[ref_index_Entries]=1.59;
	// 	 ref_index_Energy[ref_index_Entries] = (1240/pWavelength)*eV;
	// 	 ref_index_Entries++;
	//  }
 // }
 // else
	//  G4cout << "Error opening file: " << ref_index_emit << G4endl;
 // Read_ref_index.close();
 //
 //
 // // Now apply the properties table
 //
 // scintMPT->AddProperty("WLSCOMPONENT",wlsEnergy,wlsEmit,wlsEmEntries);
 // scintMPT->AddProperty("WLSABSLENGTH",wlsEnergy,wlsAbsorb,wlsAbEntries);   // the WLS absorption spectrum
 // scintMPT->AddConstProperty("WLSTIMECONSTANT",12*ns);
 // scintMPT->AddProperty("RINDEX",ref_index_Energy,ref_index_value,ref_index_Entries);
 //
 // scintMPT->AddProperty("ABSLENGTH",absorbEnergy,Absorb,absorbEntries);    // the bulk absorption spectrum
 // scintMPT->AddProperty("FASTCOMPONENT",scintEnergy,scintEmit,scintEntries);  // not needed in sim
 // scintMPT->AddProperty("SLOWCOMPONENT",scintEnergy,scintSlow,scintEntries);  // not needed in sim
 //
 // G4double efficiency = 1.0;
 // scintMPT->AddConstProperty("EFFICIENCY",efficiency);
 //
 // scintMPT->AddConstProperty("SCINTILLATIONYIELD",lightyield/MeV);
 // //scintMPT->AddConstProperty("ALPHASCINTILLATIONYIELD",0.01*lightyield/MeV);
 // G4double scintRes = 1;
 // scintMPT->AddConstProperty("RESOLUTIONSCALE",scintRes);
 // G4double scintFastconst = 2.1*ns;
 // scintMPT->AddConstProperty("FASTTIMECONSTANT",scintFastconst);
 // G4double scintSlowconst = 10*ns;
 // scintMPT->AddConstProperty("SLOWTIMECONSTANT",scintSlowconst);
 // scintMPT->AddConstProperty("YIELDRATIO",1.0);
 //
 // scintillator->SetMaterialPropertiesTable(scintMPT);
 // //scintillator->GetIonisation()->SetBirksConstant(0.0872*mm/MeV); //0.126->base; 0.0872->article BiPO
 // scintillator->GetIonisation()->SetBirksConstant(0.25*mm/MeV); // Choisi pour validation modÃ¨le avec LY 11737!!!
 // //scintillator->GetIonisation()->SetBirksConstant(0.22*mm/MeV);
 // //scintillator->GetIonisation()->SetBirksConstant(0.01*mm/MeV); // TEST ELECTRONS !!! => Maxime

  //Vacuum *************************************************************

  // Be careful of this vacuum definition.  This is only used to define
  // a refractive index so that the detector boundaries are defined.

  Vacuum = new G4Material ("Vacuum", //"Vacuum"   => SIMU OPTIQUE BASE
			   1.0,  //1.0
			   1.01*g/mole,  //1.01*g/mole
			   universe_mean_density,   //universe_mean_density
			   kStateGas,   //kStateGas
			   3.e-18*pascal, //3.e-18*pascal
			   2.73*kelvin);  //2.73*kelvin

  G4int vacEntries = 0;
  G4double vacEmit[500];
  G4double vacIndex[500];
  G4double vacAbsorb[500];
  G4double vacEnergy[500];
  G4double vacAbsorbconst = 100*m;

  std::ifstream ReadVac;
  G4String Vac = path+"pTP_emission.dat";  // simply index filler values...not pTP values
  ReadVac.open(Vac);
  if(ReadVac.is_open()){
    while(!ReadVac.eof()){
      G4String filler;
      ReadVac >> pWavelength >> filler >> vacEmit[vacEntries];
      vacEnergy[vacEntries] = (1240/pWavelength)*eV; //convert wavelength to eV
      vacIndex[vacEntries] = 1.0;
      vacAbsorb[vacEntries] = vacAbsorbconst;
      //    G4cout<<vacEntries<<" "<<vacEnergy[vacEntries]<<" "<<vacIndex[vacEntries]<<G4endl;
      vacEntries++;
    }
  }
  else
  G4cout << "Error opening file: " << Vac << G4endl;
  ReadVac.close();

  vacMPT = new G4MaterialPropertiesTable();
  vacMPT->AddProperty("RINDEX",vacEnergy,vacIndex,vacEntries);
  vacMPT->AddProperty("ABSLENGTH",vacEnergy,vacAbsorb,vacEntries);
  //Air->SetMaterialPropertiesTable(vacMPT);
  Vacuum->SetMaterialPropertiesTable(vacMPT);

  //Fake Vacuum *************************************************************

  // Be careful of this vacuum definition.  This is only used to define
  // a refractive index so that the detector boundaries are defined.

  VacuumWorld = new G4Material ("VacuumWorld",
			   1.0,
			   1.01*g/mole,
			   universe_mean_density,
			   kStateGas,
			   3.e-18*pascal,
			   2.73*kelvin);


  //G4cout << *(G4Material::GetMaterialTable()) << G4endl;



}
  G4Material* TPSimMaterials::GetMaterial(G4String material)
    {
      G4Material* pttoMaterial = G4Material::GetMaterial(material);
      return pttoMaterial;


    }
