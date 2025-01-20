/// TPSimMaterials.cc
/// Auteur: Arnaud HUBER <huber@cenbg.in2p3.fr>
//// Copyright: 2022 (C) Projet RATP - ENL [LP2IB] - CELIA

#include "TPSimMaterials.hh"

using namespace CLHEP;

const G4String TPSimMaterials::path = "../simulation_input_files/";
std::mutex materialMutex;

TPSimMaterials *TPSimMaterials::fgInstance = nullptr;


TPSimMaterials::TPSimMaterials() : fMaterialsList{}
{

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ██╗░░██╗██████╗░░█████╗░
	// ██║░░██║╚════██╗██╔══██╗
	// ███████║░░███╔═╝██║░░██║
	// ██╔══██║██╔══╝░░██║░░██║
	// ██║░░██║███████╗╚█████╔╝
	// ╚═╝░░╚═╝╚══════╝░╚════╝░

	auto H2O = new G4Material("Eau", 1.000 * g / cm3, 2);
	H2O->AddElement(G4NistManager::Instance()->FindOrBuildElement("H"), 2);
	H2O->AddElement(G4NistManager::Instance()->FindOrBuildElement("O"), 1);
	fMaterialsList.push_back(H2O);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ███╗░░░███╗██╗░░░██╗██╗░░░░░░█████╗░██████╗░
	// ████╗░████║╚██╗░██╔╝██║░░░░░██╔══██╗██╔══██╗
	// ██╔████╔██║░╚████╔╝░██║░░░░░███████║██████╔╝
	// ██║╚██╔╝██║░░╚██╔╝░░██║░░░░░██╔══██║██╔══██╗
	// ██║░╚═╝░██║░░░██║░░░███████╗██║░░██║██║░░██║
	// ╚═╝░░░░░╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝

	auto mylar = G4NistManager::Instance()->FindOrBuildMaterial("G4_MYLAR");
	fMaterialsList.push_back(mylar);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ████████╗███████╗███████╗██╗░░░░░░█████╗░███╗░░██╗
	// ╚══██╔══╝██╔════╝██╔════╝██║░░░░░██╔══██╗████╗░██║
	// ░░░██║░░░█████╗░░█████╗░░██║░░░░░██║░░██║██╔██╗██║
	// ░░░██║░░░██╔══╝░░██╔══╝░░██║░░░░░██║░░██║██║╚████║
	// ░░░██║░░░███████╗██║░░░░░███████╗╚█████╔╝██║░╚███║
	// ░░░╚═╝░░░╚══════╝╚═╝░░░░░╚══════╝░╚════╝░╚═╝░░╚══╝

	auto teflon = G4NistManager::Instance()->FindOrBuildMaterial("G4_TEFLON");
	fMaterialsList.push_back(teflon);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ██████╗░██╗░░░░░░█████╗░███╗░░░███╗██████╗░  ░█████╗░███╗░░██╗████████╗██╗███╗░░░███╗░█████╗░██╗███╗░░██╗███████╗
	// ██╔══██╗██║░░░░░██╔══██╗████╗░████║██╔══██╗  ██╔══██╗████╗░██║╚══██╔══╝██║████╗░████║██╔══██╗██║████╗░██║██╔════╝
	// ██████╔╝██║░░░░░██║░░██║██╔████╔██║██████╦╝  ███████║██╔██╗██║░░░██║░░░██║██╔████╔██║██║░░██║██║██╔██╗██║█████╗░░
	// ██╔═══╝░██║░░░░░██║░░██║██║╚██╔╝██║██╔══██╗  ██╔══██║██║╚████║░░░██║░░░██║██║╚██╔╝██║██║░░██║██║██║╚████║██╔══╝░░
	// ██║░░░░░███████╗╚█████╔╝██║░╚═╝░██║██████╦╝  ██║░░██║██║░╚███║░░░██║░░░██║██║░╚═╝░██║╚█████╔╝██║██║░╚███║███████╗
	// ╚═╝░░░░░╚══════╝░╚════╝░╚═╝░░░░░╚═╝╚═════╝░  ╚═╝░░╚═╝╚═╝░░╚══╝░░░╚═╝░░░╚═╝╚═╝░░░░░╚═╝░╚════╝░╚═╝╚═╝░░╚══╝╚══════╝

	auto Plomb_Antimoine = new G4Material("Plomb_Antimoine", 11.04 * g / cm3, 2);
	Plomb_Antimoine->AddElement(G4NistManager::Instance()->FindOrBuildElement("Pb"), 0.96);
	Plomb_Antimoine->AddElement(G4NistManager::Instance()->FindOrBuildElement("Sb"), 0.04);
	fMaterialsList.push_back(Plomb_Antimoine);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ░█████╗░░█████╗░██╗███████╗██████╗░
	// ██╔══██╗██╔══██╗██║██╔════╝██╔══██╗
	// ███████║██║░░╚═╝██║█████╗░░██████╔╝
	// ██╔══██║██║░░██╗██║██╔══╝░░██╔══██╗
	// ██║░░██║╚█████╔╝██║███████╗██║░░██║
	// ╚═╝░░╚═╝░╚════╝░╚═╝╚══════╝╚═╝░░╚═╝

	auto Acier = new G4Material("Acier", 7.86 * g / cm3, 2);
	Acier->AddElement(G4NistManager::Instance()->FindOrBuildElement("Fe"), 0.99);
	Acier->AddElement(G4NistManager::Instance()->FindOrBuildElement("C"), 0.01);
	fMaterialsList.push_back(Acier);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ██╗███╗░░██╗░█████╗░██╗░░██╗
	// ██║████╗░██║██╔══██╗╚██╗██╔╝
	// ██║██╔██╗██║██║░░██║░╚███╔╝░
	// ██║██║╚████║██║░░██║░██╔██╗░
	// ██║██║░╚███║╚█████╔╝██╔╝╚██╗
	// ╚═╝╚═╝░░╚══╝░╚════╝░╚═╝░░╚═╝

	auto Inox = new G4Material("Inox", 8.06 * g / cm3, 6);
	Inox->AddElement(G4NistManager::Instance()->FindOrBuildElement("Fe"), 0.712);
	Inox->AddElement(G4NistManager::Instance()->FindOrBuildElement("Cr"), 0.18);
	Inox->AddElement(G4NistManager::Instance()->FindOrBuildElement("Ni"), 0.09);
	Inox->AddElement(G4NistManager::Instance()->FindOrBuildElement("Mn"), 0.01);
	Inox->AddElement(G4NistManager::Instance()->FindOrBuildElement("Si"), 0.007);
	Inox->AddElement(G4NistManager::Instance()->FindOrBuildElement("C"), 0.001);
	fMaterialsList.push_back(Inox);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ██╗░░░██╗░█████╗░░█████╗░██╗░░░██╗██╗░░░██╗███╗░░░███╗
	// ██║░░░██║██╔══██╗██╔══██╗██║░░░██║██║░░░██║████╗░████║
	// ╚██╗░██╔╝███████║██║░░╚═╝██║░░░██║██║░░░██║██╔████╔██║
	// ░╚████╔╝░██╔══██║██║░░██╗██║░░░██║██║░░░██║██║╚██╔╝██║
	// ░░╚██╔╝░░██║░░██║╚█████╔╝╚██████╔╝╚██████╔╝██║░╚═╝░██║
	// ░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░░╚═════╝░░╚═════╝░╚═╝░░░░░╚═╝

	// Be careful of this vacuum definition.  This is only used to define
	// a refractive index so that the detector boundaries are defined.

	auto Vacuum = new G4Material("Vacuum", 1., 1. * g / mole, 1.e-20 * g / cm3, kStateGas, 0.1 * kelvin, 1.e-20 * bar);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto vacMPT = new G4MaterialPropertiesTable();

		G4double vacAbsorbconst = 10000 * m;

		file = path + "EJ-212.cfg"; // simply index filler values...not EJ-212 values

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				Absorption_Energy.push_back((1240 / pWavelength) * eV); // convert wavelength to eV
				Absorption_Long.push_back(vacAbsorbconst);
				Index_Energy.push_back((1240 / pWavelength) * eV); // convert wavelength to eV
				Index_Value.push_back(1.0);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readabsorb.close();

		vacMPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		vacMPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long);
		Vacuum->SetMaterialPropertiesTable(vacMPT);
	}

	fMaterialsList.push_back(Vacuum);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ███████╗░█████╗░██╗░░██╗███████╗  ██╗░░░██╗░█████╗░░█████╗░██╗░░░██╗██╗░░░██╗███╗░░░███╗
	// ██╔════╝██╔══██╗██║░██╔╝██╔════╝  ██║░░░██║██╔══██╗██╔══██╗██║░░░██║██║░░░██║████╗░████║
	// █████╗░░███████║█████═╝░█████╗░░  ╚██╗░██╔╝███████║██║░░╚═╝██║░░░██║██║░░░██║██╔████╔██║
	// ██╔══╝░░██╔══██║██╔═██╗░██╔══╝░░  ░╚████╔╝░██╔══██║██║░░██╗██║░░░██║██║░░░██║██║╚██╔╝██║
	// ██║░░░░░██║░░██║██║░╚██╗███████╗  ░░╚██╔╝░░██║░░██║╚█████╔╝╚██████╔╝╚██████╔╝██║░╚═╝░██║
	// ╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝  ░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░░╚═════╝░░╚═════╝░╚═╝░░░░░╚═╝

	// Be careful of this vacuum definition.  This is only used to define
	// a refractive index so that the detector boundaries are defined.

	auto VacuumWorld = new G4Material("VacuumWorld", 1., 1. * g / mole, 1.e-20 * g / cm3, kStateGas, 0.1 * kelvin, 1.e-20 * bar);

	fMaterialsList.push_back(VacuumWorld);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ░█████╗░██╗██████╗░
	// ██╔══██╗██║██╔══██╗
	// ███████║██║██████╔╝
	// ██╔══██║██║██╔══██╗
	// ██║░░██║██║██║░░██║
	// ╚═╝░░╚═╝╚═╝╚═╝░░╚═╝

	auto Air = new G4Material("Air", 1.290 * mg / cm3, 2);
	Air->AddElement(G4NistManager::Instance()->FindOrBuildElement("N"), 0.7);
	Air->AddElement(G4NistManager::Instance()->FindOrBuildElement("O"), 0.3);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto airMPT = new G4MaterialPropertiesTable();

		G4double vacAbsorbconst = 10000 * m;

		file = path + "EJ-212.cfg"; // simply index filler values...not EJ-212 values

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				Absorption_Energy.push_back((1240 / pWavelength) * eV); // convert wavelength to eV
				Absorption_Long.push_back(var);
				Index_Energy.push_back((1240 / pWavelength) * eV); // convert wavelength to eV
				Index_Value.push_back(1.0);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readabsorb.close();

		airMPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		airMPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long);
		Air->SetMaterialPropertiesTable(airMPT);
	}
	fMaterialsList.push_back(Air);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ███████╗░░░░░██╗░░░░░░██████╗░░░███╗░░██████╗░
	// ██╔════╝░░░░░██║░░░░░░╚════██╗░████║░░╚════██╗
	// █████╗░░░░░░░██║█████╗░░███╔═╝██╔██║░░░░███╔═╝
	// ██╔══╝░░██╗░░██║╚════╝██╔══╝░░╚═╝██║░░██╔══╝░░
	// ███████╗╚█████╔╝░░░░░░███████╗███████╗███████╗
	// ╚══════╝░╚════╝░░░░░░░╚══════╝╚══════╝╚══════╝

	auto EJ212 = new G4Material("EJ212",
								1.032 * g / cm3, // 1.053
								2,
								kStateSolid,
								273.15 * kelvin,
								1.0 * atmosphere);

	EJ212->AddElement(G4NistManager::Instance()->FindOrBuildElement("H"), 10);
	EJ212->AddElement(G4NistManager::Instance()->FindOrBuildElement("C"), 9);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto EJ212MPT = new G4MaterialPropertiesTable();

		// Read primary emission spectrum
		file = path + "EJ-212.cfg";

		Read.open(file);
		if (Read.is_open())
		{
			while (!Read.eof())
			{
				Read >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << 1240./pWavelength << " & emission = "<< var << G4endl;
				Emission_Energy.push_back((1240. / pWavelength) * eV); // convert wavelength to eV
				Emission_Ratio.push_back(var);
			}
		}
		else
		{
			G4cout << "Error opening file: " << file << G4endl;
		}
		Read.close();

		// // Read primary bulk absorption

		file = path + "PSTBulkAbsorb_reverse.cfg";

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << pWavelength << " & absorption = "<< varabsorblength << G4endl;
				Absorption_Energy.push_back((1240. / pWavelength) * eV);
				Absorption_Long.push_back(1. * var * m);
			}
		}
		else

			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		// Read WLS absorption
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

		// Read WLS emission
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

		// Read scintillator refractive index

		// G4String ref_index_emit = path+"PST_ref_index.dat";
		file = path + "PS_index_geant_reverse.cfg";

		Readindex.open(file);
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				// ref_index_value[ref_index_Entries]=1.59;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				Index_Value.push_back(var);
				// EJ212_Index_Value.push_back(1.59);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readindex.close();

		// Now apply the properties table

		// scintMPT->AddProperty("WLSCOMPONENT",wlsEnergy,wlsEmit,wlsEmEntries);
		// scintMPT->AddProperty("WLSABSLENGTH",wlsEnergy,wlsAbsorb,wlsAbEntries);   // the WLS absorption spectrum
		// scintMPT->AddConstProperty("WLSTIMECONSTANT",12*ns);
		EJ212MPT->AddProperty("RINDEX", Index_Energy, Index_Value);

		EJ212MPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long); // the bulk absorption spectrum
		EJ212MPT->AddProperty("SCINTILLATIONCOMPONENT1", Emission_Energy, Emission_Ratio);
		// scintMPT->AddProperty("SCINTILLATIONCOMPONENT1",scintEnergy,scintEmit,scintEntries);
		// scintMPT->AddProperty("SCINTILLATIONCOMPONENT2",scintEnergy,scintEmit,scintEntries);  // if slow component

		// G4double efficiency = 1.0;
		// scintMPT->AddConstProperty("EFFICIENCY",efficiency);

		EJ212MPT->AddConstProperty("SCINTILLATIONYIELD", lightyield / MeV);
		// scintMPT->AddConstProperty("ALPHASCINTILLATIONYIELD",0.01*lightyield/MeV);
		Res = 1;
		EJ212MPT->AddConstProperty("RESOLUTIONSCALE", Res);
		Fastconst = 2.1 * ns;
		EJ212MPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", Fastconst);
		Slowconst = 10 * ns;
		EJ212MPT->AddConstProperty("SCINTILLATIONTIMECONSTANT2", Slowconst); // if slow component
		EJ212MPT->AddConstProperty("SCINTILLATIONYIELD1", 1.0);
		EJ212MPT->AddConstProperty("SCINTILLATIONYIELD2", 0.0);

		EJ212->SetMaterialPropertiesTable(EJ212MPT);
		// scintillator->GetIonisation()->SetBirksConstant(0.0872*mm/MeV); //0.126->base; 0.0872->article BiPO
		// scintillator->GetIonisation()->SetBirksConstant(0.25*mm/MeV); // Choisi pour validation modÃ¨le avec LY 11737!!!
		// scintillator->GetIonisation()->SetBirksConstant(0.22*mm/MeV);
		// scintillator->GetIonisation()->SetBirksConstant(0.01*mm/MeV); // TEST ELECTRONS !!! => Maxime
	}

	// printMaterialProperties(EJ212);
	fMaterialsList.push_back(EJ212);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ███████╗░░░░░██╗░░░░░░██████╗░░░███╗░░░░██╗██╗
	// ██╔════╝░░░░░██║░░░░░░╚════██╗░████║░░░██╔╝██║
	// █████╗░░░░░░░██║█████╗░░███╔═╝██╔██║░░██╔╝░██║
	// ██╔══╝░░██╗░░██║╚════╝██╔══╝░░╚═╝██║░░███████║
	// ███████╗╚█████╔╝░░░░░░███████╗███████╗╚════██║
	// ╚══════╝░╚════╝░░░░░░░╚══════╝╚══════╝░░░░░╚═╝

	auto EJ214 = new G4Material("EJ214",
								1.02 * g / cm3, // 1.053
								4,
								kStateSolid,
								273.15 * kelvin,
								1.0 * atmosphere);

	EJ214->AddElement(G4NistManager::Instance()->FindOrBuildElement("H"), 0.2989);
	EJ214->AddElement(G4NistManager::Instance()->FindOrBuildElement("C"), 0.2695);
	EJ214->AddElement(G4NistManager::Instance()->FindOrBuildElement("N"), 0.2821);
	EJ214->AddElement(G4NistManager::Instance()->FindOrBuildElement("O"), 0.1495);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto EJ214MPT = new G4MaterialPropertiesTable();

		// Read primary emission spectrum

		file = path + "EJ-214.cfg";

		Read.open(file);
		if (Read.is_open())
		{
			while (!Read.eof())
			{
				Read >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << 1240./pWavelength << " & emission = "<< ratio << G4endl;
				Emission_Energy.push_back((1240. / pWavelength) * eV); // convert wavelength to eV
				Emission_Ratio.push_back(var);
			}
		}
		else
		{
			G4cout << "Error opening file: " << file << G4endl;
		}
		Read.close();

		// // Read primary bulk absorption
		file = path + "PSTBulkAbsorb_reverse.cfg";

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << pWavelength << " & absorption = "<< varabsorblength << G4endl;
				Absorption_Energy.push_back((1240. / pWavelength) * eV);
				Absorption_Long.push_back(1. * var * m);
			}
		}
		else

			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		// Read scintillator refractive index
		file = path + "PS_index_geant_reverse.cfg";

		Readindex.open(file);
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				// ref_index_value[ref_index_Entries]=1.59;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				Index_Value.push_back(var);
				// EJ214_Index_Value.push_back(1.59);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readindex.close();

		// Now apply the properties table

		EJ214MPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		EJ214MPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long); // the bulk absorption spectrum
		EJ214MPT->AddProperty("SCINTILLATIONCOMPONENT1", Emission_Energy, Emission_Ratio);

		EJ214MPT->AddConstProperty("SCINTILLATIONYIELD", lightyield / MeV);
		// scintMPT->AddConstProperty("ALPHASCINTILLATIONYIELD",0.01*lightyield/MeV);
		Res = 1;
		EJ214MPT->AddConstProperty("RESOLUTIONSCALE", Res);
		Fastconst = 2 * ns;
		EJ214MPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", Fastconst);
		Slowconst = 10 * ns;
		EJ214MPT->AddConstProperty("SCINTILLATIONTIMECONSTANT2", Slowconst); // if slow component
		EJ214MPT->AddConstProperty("SCINTILLATIONYIELD1", 1.0);
		EJ214MPT->AddConstProperty("SCINTILLATIONYIELD2", 0.0);
		// EJ214->GetIonisation()->SetBirksConstant(0.0872*mm/MeV); //0.126->base; 0.0872->article BiPO
		EJ214->SetMaterialPropertiesTable(EJ214MPT);
	}

	fMaterialsList.push_back(EJ214);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ███████╗░░░░░██╗░░░░░░██████╗░░█████╗░░█████╗░
	// ██╔════╝░░░░░██║░░░░░░╚════██╗██╔═══╝░██╔══██╗
	// █████╗░░░░░░░██║█████╗░░███╔═╝██████╗░██║░░██║
	// ██╔══╝░░██╗░░██║╚════╝██╔══╝░░██╔══██╗██║░░██║
	// ███████╗╚█████╔╝░░░░░░███████╗╚█████╔╝╚█████╔╝
	// ╚══════╝░╚════╝░░░░░░░╚══════╝░╚════╝░░╚════╝░

	auto EJ260 = new G4Material("EJ260",
								1.023 * g / cm3, // 1.053
								2,
								kStateSolid,
								273.15 * kelvin,
								1.0 * atmosphere);

	EJ260->AddElement(G4NistManager::Instance()->FindOrBuildElement("H"), 0.5257);
	EJ260->AddElement(G4NistManager::Instance()->FindOrBuildElement("C"), 0.4743);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto EJ260MPT = new G4MaterialPropertiesTable();

		// Read primary emission spectrum

		file = path + "EJ-260.cfg";

		Read.open(file);
		if (Read.is_open())
		{
			while (!Read.eof())
			{
				Read >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << 1240./pWavelength << " & emission = "<< ratio << G4endl;
				Emission_Energy.push_back((1240. / pWavelength) * eV); // convert wavelength to eV
				Emission_Ratio.push_back(var);
			}
		}
		else
		{
			G4cout << "Error opening file: " << file << G4endl;
		}
		Read.close();

		// // Read primary bulk absorption

		file = path + "PSTBulkAbsorb_reverse.cfg";

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << pWavelength << " & absorption = "<< varabsorblength << G4endl;
				Absorption_Energy.push_back((1240. / pWavelength) * eV);
				Absorption_Long.push_back(3.5 * m);
			}
		}
		else

			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		// Read scintillator refractive index

		file = path + "PS_index_geant_reverse.cfg";

		Readindex.open(file);
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				// ref_index_value[ref_index_Entries]=1.59;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				// EJ260_Index_Value.push_back(var);
				Index_Value.push_back(1.58);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readindex.close();

		// Now apply the properties table

		EJ260MPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		EJ260MPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long); // the bulk absorption spectrum
		EJ260MPT->AddProperty("SCINTILLATIONCOMPONENT1", Emission_Energy, Emission_Ratio);

		EJ260MPT->AddConstProperty("SCINTILLATIONYIELD", lightyield / MeV);
		// scintMPT->AddConstProperty("ALPHASCINTILLATIONYIELD",0.01*lightyield/MeV);
		Res = 1;
		EJ260MPT->AddConstProperty("RESOLUTIONSCALE", Res);
		Fastconst = 2 * ns;
		EJ260MPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", Fastconst);
		Slowconst = 10 * ns;
		EJ260MPT->AddConstProperty("SCINTILLATIONTIMECONSTANT2", Slowconst); // if slow component
		EJ260MPT->AddConstProperty("SCINTILLATIONYIELD1", 1.0);
		EJ260MPT->AddConstProperty("SCINTILLATIONYIELD2", 0.0);
		// EJ260->GetIonisation()->SetBirksConstant(0.0872*mm/MeV); //0.126->base; 0.0872->article BiPO
		EJ260->SetMaterialPropertiesTable(EJ260MPT);
	}

	fMaterialsList.push_back(EJ260);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ███████╗░░░░░██╗░░░░░░██████╗░░█████╗░██████╗░
	// ██╔════╝░░░░░██║░░░░░░╚════██╗██╔═══╝░╚════██╗
	// █████╗░░░░░░░██║█████╗░░███╔═╝██████╗░░░███╔═╝
	// ██╔══╝░░██╗░░██║╚════╝██╔══╝░░██╔══██╗██╔══╝░░
	// ███████╗╚█████╔╝░░░░░░███████╗╚█████╔╝███████╗
	// ╚══════╝░╚════╝░░░░░░░╚══════╝░╚════╝░╚══════╝

	auto EJ262 = new G4Material("EJ262",
								1.023 * g / cm3, // 1.053
								2,
								kStateSolid,
								273.15 * kelvin,
								1.0 * atmosphere);

	EJ262->AddElement(G4NistManager::Instance()->FindOrBuildElement("H"), 0.5257);
	EJ262->AddElement(G4NistManager::Instance()->FindOrBuildElement("C"), 0.4743);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto EJ262MPT = new G4MaterialPropertiesTable();

		// Read primary emission spectrum

		file = path + "EJ-262.cfg";

		Read.open(file);
		if (Read.is_open())
		{
			while (!Read.eof())
			{
				Read >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << 1240./pWavelength << " & emission = "<< ratio << G4endl;
				Emission_Energy.push_back((1240. / pWavelength) * eV); // convert wavelength to eV
				Emission_Ratio.push_back(var);
			}
		}
		else
		{
			G4cout << "Error opening file: " << file << G4endl;
		}
		Read.close();

		// // Read primary bulk absorption
		file = path + "PSTBulkAbsorb_reverse.cfg";

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << pWavelength << " & absorption = "<< varabsorblength << G4endl;
				Absorption_Energy.push_back((1240. / pWavelength) * eV);
				Absorption_Long.push_back(2.5 * m);
			}
		}
		else

			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		// Read scintillator refractive index
		file = path + "PS_index_geant_reverse.cfg";

		Readindex.open(file);
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				// ref_index_value[ref_index_Entries]=1.59;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				// EJ260_Index_Value.push_back(var);
				Index_Value.push_back(1.58);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readindex.close();

		// Now apply the properties table

		EJ262MPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		EJ262MPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long); // the bulk absorption spectrum
		EJ262MPT->AddProperty("SCINTILLATIONCOMPONENT1", Emission_Energy, Emission_Ratio);

		EJ262MPT->AddConstProperty("SCINTILLATIONYIELD", lightyield / MeV);
		// scintMPT->AddConstProperty("ALPHASCINTILLATIONYIELD",0.01*lightyield/MeV);
		Res = 1;
		EJ262MPT->AddConstProperty("RESOLUTIONSCALE", Res);
		Fastconst = 2 * ns;
		EJ262MPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", Fastconst);
		Slowconst = 10 * ns;
		EJ262MPT->AddConstProperty("SCINTILLATIONTIMECONSTANT2", Slowconst); // if slow component
		EJ262MPT->AddConstProperty("SCINTILLATIONYIELD1", 1.0);
		EJ262MPT->AddConstProperty("SCINTILLATIONYIELD2", 0.0);
		// EJ262->GetIonisation()->SetBirksConstant(0.0872*mm/MeV); //0.126->base; 0.0872->article BiPO
		EJ262->SetMaterialPropertiesTable(EJ262MPT);
	}

	fMaterialsList.push_back(EJ262);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ██╗░░░░░██╗░░░██╗░██████╗░█████╗░
	// ██║░░░░░╚██╗░██╔╝██╔════╝██╔══██╗
	// ██║░░░░░░╚████╔╝░╚█████╗░██║░░██║
	// ██║░░░░░░░╚██╔╝░░░╚═══██╗██║░░██║
	// ███████╗░░░██║░░░██████╔╝╚█████╔╝
	// ╚══════╝░░░╚═╝░░░╚═════╝░░╚════╝░

	auto LYSO = new G4Material("LYSO",
							   7.1 * g / cm3, // 1.053
							   4,
							   kStateSolid,
							   273.15 * kelvin,
							   1.0 * atmosphere);

	LYSO->AddElement(G4NistManager::Instance()->FindOrBuildElement("Lu"), 0.225);
	LYSO->AddElement(G4NistManager::Instance()->FindOrBuildElement("Y"), 0.025);
	LYSO->AddElement(G4NistManager::Instance()->FindOrBuildElement("Si"), 0.125);
	LYSO->AddElement(G4NistManager::Instance()->FindOrBuildElement("O"), 0.625);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto LYSOMPT = new G4MaterialPropertiesTable();

		// Read primary emission spectrum
		file = path + "LYSO_reverse.cfg";

		Read.open(file);
		if (Read.is_open())
		{
			while (!Read.eof())
			{
				Read >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << 1240./pWavelength << " & emission = "<< ratio << G4endl;
				Emission_Energy.push_back((1240. / pWavelength) * eV); // convert wavelength to eV
				Emission_Ratio.push_back(var);
			}
		}
		else
		{
			G4cout << "Error opening file: " << file << G4endl;
		}
		Read.close();

		// // Read primary bulk absorption
		file = path + "PSTBulkAbsorb_reverse.cfg";

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << pWavelength << " & absorption = "<< varabsorblength << G4endl;
				Absorption_Energy.push_back((1240. / pWavelength) * eV);
				Absorption_Long.push_back(40 * cm);
			}
		}
		else

			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		// Read scintillator refractive index
		file = path + "PS_index_geant_reverse.cfg";

		Readindex.open(file);
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				// Index_Value.push_back(var);
				Index_Value.push_back(1.81);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readindex.close();

		// Now apply the properties table

		LYSOMPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		LYSOMPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long); // the bulk absorption spectrum
		LYSOMPT->AddProperty("SCINTILLATIONCOMPONENT1", Emission_Energy, Emission_Ratio);

		LYSOMPT->AddConstProperty("SCINTILLATIONYIELD", lightyield / MeV);
		// scintMPT->AddConstProperty("ALPHASCINTILLATIONYIELD",0.01*lightyield/MeV);
		Res = 1;
		LYSOMPT->AddConstProperty("RESOLUTIONSCALE", Res);
		Fastconst = 36 * ns;
		LYSOMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", Fastconst);
		Slowconst = 100 * ns;
		LYSOMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT2", Slowconst); // if slow component
		LYSOMPT->AddConstProperty("SCINTILLATIONYIELD1", 1.0);
		LYSOMPT->AddConstProperty("SCINTILLATIONYIELD2", 0.0);
		LYSO->SetMaterialPropertiesTable(LYSOMPT);
	}

	fMaterialsList.push_back(LYSO);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ░█████╗░░██████╗██╗██╗████████╗██╗░░░░░
	// ██╔══██╗██╔════╝██║╚═╝╚══██╔══╝██║░░░░░
	// ██║░░╚═╝╚█████╗░██║░░░░░░██║░░░██║░░░░░
	// ██║░░██╗░╚═══██╗██║░░░░░░██║░░░██║░░░░░
	// ╚█████╔╝██████╔╝██║██╗░░░██║░░░███████╗
	// ░╚════╝░╚═════╝░╚═╝╚═╝░░░╚═╝░░░╚══════╝

	auto CsITl = new G4Material("CsITl",
								4.51 * g / cm3, // 1.053
								2,
								kStateSolid,
								273.15 * kelvin,
								1.0 * atmosphere);

	CsITl->AddElement(G4NistManager::Instance()->FindOrBuildElement("Cs"), 1);
	CsITl->AddElement(G4NistManager::Instance()->FindOrBuildElement("I"), 1);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto CsITlMPT = new G4MaterialPropertiesTable();

		// Read primary emission spectrum

		file = path + "CsITl_reverse.cfg";

		Read.open(file);
		if (Read.is_open())
		{
			while (!Read.eof())
			{
				Read >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << 1240./pWavelength << " & emission = "<< ratio << G4endl;
				Emission_Energy.push_back((1240. / pWavelength) * eV); // convert wavelength to eV
				Emission_Ratio.push_back(var);
			}
		}
		else
		{
			G4cout << "Error opening file: " << file << G4endl;
		}
		Read.close();

		// // Read primary bulk absorption
		file = path + "CsITlAbsorb_reverse.dat";

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << pWavelength << " & absorption = "<< varabsorblength << G4endl;
				Absorption_Energy.push_back((1240. / pWavelength) * eV);
				Absorption_Long.push_back(var * cm);
			}
		}
		else

			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		// Read scintillator refractive index
		file = path + "PS_index_geant_reverse.cfg";

		Readindex.open(file);
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				// ref_index_value[ref_index_Entries]=1.59;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				// EJ260_Index_Value.push_back(var);
				Index_Value.push_back(1.79);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readindex.close();

		// Now apply the properties table

		CsITlMPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		CsITlMPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long); // the bulk absorption spectrum
		CsITlMPT->AddProperty("SCINTILLATIONCOMPONENT1", Emission_Energy, Emission_Ratio);

		CsITlMPT->AddConstProperty("SCINTILLATIONYIELD", lightyield / MeV);
		// scintMPT->AddConstProperty("ALPHASCINTILLATIONYIELD",0.01*lightyield/MeV);
		Res = 1;
		CsITlMPT->AddConstProperty("RESOLUTIONSCALE", Res);
		Fastconst = 1000 * ns;
		CsITlMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", Fastconst);
		Slowconst = 2000 * ns;
		CsITlMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT2", Slowconst); // if slow component
		CsITlMPT->AddConstProperty("SCINTILLATIONYIELD1", 1.0);
		CsITlMPT->AddConstProperty("SCINTILLATIONYIELD2", 0.0);

		CsITl->SetMaterialPropertiesTable(CsITlMPT);
	}

	fMaterialsList.push_back(CsITl);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ██╗░░░░░██╗░░░██╗░█████╗░░██████╗░
	// ██║░░░░░██║░░░██║██╔══██╗██╔════╝░
	// ██║░░░░░██║░░░██║███████║██║░░██╗░
	// ██║░░░░░██║░░░██║██╔══██║██║░░╚██╗
	// ███████╗╚██████╔╝██║░░██║╚██████╔╝
	// ╚══════╝░╚═════╝░╚═╝░░╚═╝░╚═════╝░

	auto LuAG = new G4Material("LuAG",
							   6.73 * g / cm3, // 1.053
							   3,
							   kStateSolid,
							   273.15 * kelvin,
							   1.0 * atmosphere);

	LuAG->AddElement(G4NistManager::Instance()->FindOrBuildElement("Lu"), 1);
	LuAG->AddElement(G4NistManager::Instance()->FindOrBuildElement("Al"), 5);
	LuAG->AddElement(G4NistManager::Instance()->FindOrBuildElement("O"), 12);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto LuAGMPT = new G4MaterialPropertiesTable();

		// Read primary emission spectrum
		file = path + "LuAG_reverse.cfg";

		Read.open(file);
		if (Read.is_open())
		{
			while (!Read.eof())
			{
				Read >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << 1240./pWavelength << " & emission = "<< ratio << G4endl;
				Emission_Energy.push_back((1240. / pWavelength) * eV); // convert wavelength to eV
				Emission_Ratio.push_back(var);
			}
		}
		else
		{
			G4cout << "Error opening file: " << file << G4endl;
		}
		Read.close();

		// // Read primary bulk absorption
		file = path + "LuAGAbsorb_reverse.dat";

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << pWavelength << " & absorption = "<< varabsorblength << G4endl;
				Absorption_Energy.push_back((1240. / pWavelength) * eV);
				Absorption_Long.push_back(var * m);
			}
		}
		else

			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		// Read scintillator refractive index
		file = path + "PS_index_geant_reverse.cfg";

		Readindex.open(file);
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				// ref_index_value[ref_index_Entries]=1.59;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				// EJ260_Index_Value.push_back(var);
				Index_Value.push_back(1.84);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readindex.close();

		// Now apply the properties table

		LuAGMPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		LuAGMPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long); // the bulk absorption spectrum
		LuAGMPT->AddProperty("SCINTILLATIONCOMPONENT1", Emission_Energy, Emission_Ratio);

		LuAGMPT->AddConstProperty("SCINTILLATIONYIELD", lightyield / MeV);
		// scintMPT->AddConstProperty("ALPHASCINTILLATIONYIELD",0.01*lightyield/MeV);
		Res = 1;
		LuAGMPT->AddConstProperty("RESOLUTIONSCALE", Res);
		Fastconst = 70 * ns;
		LuAGMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", Fastconst);
		Slowconst = 100 * ns;
		LuAGMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT2", Slowconst); // if slow component
		LuAGMPT->AddConstProperty("SCINTILLATIONYIELD1", 1.0);
		LuAGMPT->AddConstProperty("SCINTILLATIONYIELD2", 0.0);

		LuAG->SetMaterialPropertiesTable(LuAGMPT);
	}

	fMaterialsList.push_back(LuAG);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ██╗░░░██╗░█████╗░░██████╗░██╗░█████╗░███████╗
	// ╚██╗░██╔╝██╔══██╗██╔════╝░╚═╝██╔══██╗██╔════╝
	// ░╚████╔╝░███████║██║░░██╗░░░░██║░░╚═╝█████╗░░
	// ░░╚██╔╝░░██╔══██║██║░░╚██╗░░░██║░░██╗██╔══╝░░
	// ░░░██║░░░██║░░██║╚██████╔╝██╗╚█████╔╝███████╗
	// ░░░╚═╝░░░╚═╝░░╚═╝░╚═════╝░╚═╝░╚════╝░╚══════╝

	auto YAG = new G4Material("YAG",
							  4.57 * g / cm3, // 1.053
							  3,
							  kStateSolid,
							  273.15 * kelvin,
							  1.0 * atmosphere);

	YAG->AddElement(G4NistManager::Instance()->FindOrBuildElement("Y"), 3);
	YAG->AddElement(G4NistManager::Instance()->FindOrBuildElement("Al"), 5);
	YAG->AddElement(G4NistManager::Instance()->FindOrBuildElement("O"), 12);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto YAGMPT = new G4MaterialPropertiesTable();

		// Read primary emission spectrum
		file = path + "YAG_reverse.cfg";

		Read.open(file);
		if (Read.is_open())
		{
			while (!Read.eof())
			{
				Read >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << 1240./pWavelength << " & emission = "<< ratio << G4endl;
				Emission_Energy.push_back((1240. / pWavelength) * eV); // convert wavelength to eV
				Emission_Ratio.push_back(var);
			}
		}
		else
		{
			G4cout << "Error opening file: " << file << G4endl;
		}
		Read.close();

		// // Read primary bulk absorption
		file = path + "YAGAbsorb_reverse.dat";

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << pWavelength << " & absorption = "<< varabsorblength << G4endl;
				Absorption_Energy.push_back((1240. / pWavelength) * eV);
				Absorption_Long.push_back(var * m);
			}
		}
		else

			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		// Read scintillator refractive index
		file = path + "PS_index_geant_reverse.cfg";

		Readindex.open(file);
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				// ref_index_value[ref_index_Entries]=1.59;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				// EJ260_Index_Value.push_back(var);
				Index_Value.push_back(1.82); // 1.82
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readindex.close();

		// Now apply the properties table

		YAGMPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		YAGMPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long); // the bulk absorption spectrum
		YAGMPT->AddProperty("SCINTILLATIONCOMPONENT1", Emission_Energy, Emission_Ratio);

		YAGMPT->AddConstProperty("SCINTILLATIONYIELD", lightyield / MeV);
		// scintMPT->AddConstProperty("ALPHASCINTILLATIONYIELD",0.01*lightyield/MeV);
		Res = 1;
		YAGMPT->AddConstProperty("RESOLUTIONSCALE", Res);
		Fastconst = 70 * ns;
		YAGMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", Fastconst);
		Slowconst = 100 * ns;
		YAGMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT2", Slowconst); // if slow component
		YAGMPT->AddConstProperty("SCINTILLATIONYIELD1", 1.0);
		YAGMPT->AddConstProperty("SCINTILLATIONYIELD2", 0.0);

		YAG->SetMaterialPropertiesTable(YAGMPT);
	}

	fMaterialsList.push_back(YAG);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ░██████╗░░█████╗░░██████╗░░██████╗░
	// ██╔════╝░██╔══██╗██╔════╝░██╔════╝░
	// ██║░░██╗░███████║██║░░██╗░██║░░██╗░
	// ██║░░╚██╗██╔══██║██║░░╚██╗██║░░╚██╗
	// ╚██████╔╝██║░░██║╚██████╔╝╚██████╔╝
	// ░╚═════╝░╚═╝░░╚═╝░╚═════╝░░╚═════╝░

	auto GAGG = new G4Material("GAGG",
							   6.6 * g / cm3, // 1.053
							   4,
							   kStateSolid,
							   273.15 * kelvin,
							   1.0 * atmosphere);

	GAGG->AddElement(G4NistManager::Instance()->FindOrBuildElement("Gd"), 3);
	GAGG->AddElement(G4NistManager::Instance()->FindOrBuildElement("Ga"), 3);
	GAGG->AddElement(G4NistManager::Instance()->FindOrBuildElement("Al"), 2);
	GAGG->AddElement(G4NistManager::Instance()->FindOrBuildElement("O"), 12);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto GAGGMPT = new G4MaterialPropertiesTable();

		// Read primary emission spectrum
		file = path + "GAGGCe_reverse.cfg";

		Read.open(file);
		if (Read.is_open())
		{
			while (!Read.eof())
			{
				Read >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << 1240./pWavelength << " & emission = "<< ratio << G4endl;
				Emission_Energy.push_back((1240. / pWavelength) * eV); // convert wavelength to eV
				Emission_Ratio.push_back(var);
			}
		}
		else
		{
			G4cout << "Error opening file: " << file << G4endl;
		}
		Read.close();

		// // Read primary bulk absorption
		file = path + "LuAGAbsorb_reverse.dat";

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << pWavelength << " & absorption = "<< varabsorblength << G4endl;
				Absorption_Energy.push_back((1240. / pWavelength) * eV);
				Absorption_Long.push_back(645 * mm);
			}
		}
		else

			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		// Read scintillator refractive index
		file = path + "PS_index_geant_reverse.cfg";

		Readindex.open(file);
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				// ref_index_value[ref_index_Entries]=1.59;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				// EJ260_Index_Value.push_back(var);
				Index_Value.push_back(1.91);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readindex.close();

		// Now apply the properties table

		GAGGMPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		GAGGMPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long); // the bulk absorption spectrum
		GAGGMPT->AddProperty("SCINTILLATIONCOMPONENT1", Emission_Energy, Emission_Ratio);

		GAGGMPT->AddConstProperty("SCINTILLATIONYIELD", lightyield / MeV);
		// scintMPT->AddConstProperty("ALPHASCINTILLATIONYIELD",0.01*lightyield/MeV);
		Res = 1;
		GAGGMPT->AddConstProperty("RESOLUTIONSCALE", Res);
		Fastconst = 100 * ns;
		GAGGMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", Fastconst);
		Slowconst = 100 * ns;
		GAGGMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT2", Slowconst); // if slow component
		GAGGMPT->AddConstProperty("SCINTILLATIONYIELD1", 1.0);
		GAGGMPT->AddConstProperty("SCINTILLATIONYIELD2", 0.0);

		GAGG->SetMaterialPropertiesTable(GAGGMPT);
	}

	fMaterialsList.push_back(GAGG);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ██████╗░░█████╗░██████╗░░█████╗░░██████╗██╗██╗░░░░░██╗░█████╗░░█████╗░████████╗███████╗
	// ██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔════╝██║██║░░░░░██║██╔══██╗██╔══██╗╚══██╔══╝██╔════╝
	// ██████╦╝██║░░██║██████╔╝██║░░██║╚█████╗░██║██║░░░░░██║██║░░╚═╝███████║░░░██║░░░█████╗░░
	// ██╔══██╗██║░░██║██╔══██╗██║░░██║░╚═══██╗██║██║░░░░░██║██║░░██╗██╔══██║░░░██║░░░██╔══╝░░
	// ██████╦╝╚█████╔╝██║░░██║╚█████╔╝██████╔╝██║███████╗██║╚█████╔╝██║░░██║░░░██║░░░███████╗
	// ╚═════╝░░╚════╝░╚═╝░░╚═╝░╚════╝░╚═════╝░╚═╝╚══════╝╚═╝░╚════╝░╚═╝░░╚═╝░░░╚═╝░░░╚══════╝

	// ░██████╗░██╗░░░░░░█████╗░░██████╗░██████╗
	// ██╔════╝░██║░░░░░██╔══██╗██╔════╝██╔════╝
	// ██║░░██╗░██║░░░░░███████║╚█████╗░╚█████╗░
	// ██║░░╚██╗██║░░░░░██╔══██║░╚═══██╗░╚═══██╗
	// ╚██████╔╝███████╗██║░░██║██████╔╝██████╔╝
	// ░╚═════╝░╚══════╝╚═╝░░╚═╝╚═════╝░╚═════╝░

	// GLASS PMT
	//  Silicon Dioxide
	auto SiO2 = G4NistManager::Instance()->FindOrBuildMaterial("G4_SILICON_DIOXIDE");

	// DiBoron TriOxide
	auto B2O3 = G4NistManager::Instance()->FindOrBuildMaterial("G4_BORON_OXIDE");

	auto bs_glass = new G4Material("bs_glass",
								   2.23 * g / cm3,
								   2,
								   kStateSolid,
								   273.15 * kelvin,
								   1.0 * atmosphere);

	bs_glass->AddMaterial(SiO2, 0.9);
	bs_glass->AddMaterial(B2O3, 0.1);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto bs_glassMPT = new G4MaterialPropertiesTable();

		file = path + "Borosilicate_GlassBulkAbsorb_reverse.cfg";

		Readabsorb.open(file);

		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				Absorption_Energy.push_back((1240 / pWavelength) * eV);
				Absorption_Long.push_back(var * m);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		file = path + "BSG_ref_index_reverse.dat";

		Readindex.open(file);
		Readindex.clear();
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				Index_Value.push_back(var);
				//      G4cout << " Energy = " << bsgindexEnergy[bsgindexEntries] << "    Index = " << bsgindexvalue[bsgindexEntries] << G4endl;
			}
		}

		else
			G4cout << "Error opening file: " << file << G4endl;

		Readindex.close();

		bs_glassMPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long);
		bs_glassMPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		bs_glass->SetMaterialPropertiesTable(bs_glassMPT);
	}

	fMaterialsList.push_back(bs_glass);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ░█████╗░░█████╗░██████╗░░██████╗░██╗██╗░░░░░██╗░░░░░███████╗
	// ██╔══██╗██╔══██╗██╔══██╗██╔════╝░██║██║░░░░░██║░░░░░██╔════╝
	// ██║░░╚═╝███████║██████╔╝██║░░██╗░██║██║░░░░░██║░░░░░█████╗░░
	// ██║░░██╗██╔══██║██╔══██╗██║░░╚██╗██║██║░░░░░██║░░░░░██╔══╝░░
	// ╚█████╔╝██║░░██║██║░░██║╚██████╔╝██║███████╗███████╗███████╗
	// ░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝░╚═════╝░╚═╝╚══════╝╚══════╝╚══════╝

	auto cargille = new G4Material("cargille",
								   0.99 * g / cm3,
								   4,
								   kStateSolid,
								   273.15 * kelvin,
								   1.0 * atmosphere);

	cargille->AddElement(G4NistManager::Instance()->FindOrBuildElement("H"), 6);
	cargille->AddElement(G4NistManager::Instance()->FindOrBuildElement("C"), 2);
	cargille->AddElement(G4NistManager::Instance()->FindOrBuildElement("O"), 1);
	cargille->AddElement(G4NistManager::Instance()->FindOrBuildElement("Si"), 1);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();
		G4double cargille_absorblength;
		G4double cargilleIndexconst = 1.406; // 1.49 1.406 RTV

		auto cargilleMPT = new G4MaterialPropertiesTable();

		file = path + "CargilleBulkAbsorb_reverse.cfg";

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				Absorption_Energy.push_back((1240. / pWavelength) * eV);
				Absorption_Long.push_back(var * m);
				Index_Energy.push_back((1240. / pWavelength) * eV);
				Index_Value.push_back(cargilleIndexconst);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readabsorb.close();

		cargilleMPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		cargilleMPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long);
		cargille->SetMaterialPropertiesTable(cargilleMPT);
	}

	fMaterialsList.push_back(cargille);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ██╗░░░░░░█████╗░██████╗░██████╗░██████╗░
	// ██║░░░░░██╔══██╗██╔══██╗██╔══██╗╚════██╗
	// ██║░░░░░███████║██████╦╝██████╔╝░█████╔╝
	// ██║░░░░░██╔══██║██╔══██╗██╔══██╗░╚═══██╗
	// ███████╗██║░░██║██████╦╝██║░░██║██████╔╝
	// ╚══════╝╚═╝░░╚═╝╚═════╝░╚═╝░░╚═╝╚═════╝░

	auto LaBr3 = new G4Material("LaBr3", 5.08 * g / cm3, 2);
	LaBr3->AddElement(G4NistManager::Instance()->FindOrBuildElement("La"), 1);
	LaBr3->AddElement(G4NistManager::Instance()->FindOrBuildElement("Br"), 3);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();
		auto LaBr3MPT = new G4MaterialPropertiesTable();

		// Read primary emission spectrum
		file = path + "LaBr3_emission_spectrum_reverse.cfg";

		Read.open(file);
		if (Read.is_open())
		{
			while (!Read.eof())
			{
				Read >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << 1240./pWavelength << " & emission = "<< ratio << G4endl;
				Emission_Energy.push_back((1240. / pWavelength) * eV); // convert wavelength to eV
				Emission_Ratio.push_back(var);
			}
		}
		else
		{
			G4cout << "Error opening file: " << file << G4endl;
		}
		Read.close();

		// Read primary bulk absorption
		file = path + "LaBr3_absorption_reverse.cfg";

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << pWavelength << " & absorption = "<< varabsorblength << G4endl;
				Absorption_Energy.push_back((1240. / pWavelength) * eV);
				Absorption_Long.push_back(1. * var * mm);
			}
		}
		else

			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		// Read primary Rayleigh scattering
		file = path + "LaBr3_scattering_reverse.cfg";

		Readscatt.open(file);
		if (Readscatt.is_open())
		{
			while (!Readscatt.eof())
			{
				Readscatt >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << pWavelength << " & absorption = "<< varabsorblength << G4endl;
				Scatt_Energy.push_back((1240. / pWavelength) * eV);
				Scatt_Long.push_back(1. * var * mm);
			}
		}
		else

			G4cout << "Error opening file: " << file << G4endl;

		Readscatt.close();

		file = path + "LaBr3_index_reverse.cfg";

		Readindex.open(file);
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				// ref_index_value[ref_index_Entries]=1.59;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				// LaBr3_Index_Value.push_back(var);
				Index_Value.push_back(1.9);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readindex.close();

		// Now apply the properties table
		LaBr3MPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		LaBr3MPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long); // the bulk absorption spectrum
		LaBr3MPT->AddProperty("RAYLEIGH", Scatt_Energy, Scatt_Long);			// the bulk absorption spectrum
		LaBr3MPT->AddProperty("SCINTILLATIONCOMPONENT1", Emission_Energy, Emission_Ratio);
		// scintMPT->AddProperty("SCINTILLATIONCOMPONENT2",scintEnergy,scintEmit,scintEntries);  // if slow component

		LaBr3MPT->AddConstProperty("SCINTILLATIONYIELD", lightyield / MeV);
		// LaBr3MPT->AddConstProperty("ALPHASCINTILLATIONYIELD",0.01*lightyield/MeV);
		Res = 1;
		LaBr3MPT->AddConstProperty("RESOLUTIONSCALE", Res);
		Fastconst = 16 * ns;
		LaBr3MPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", Fastconst);
		Slowconst = 66 * ns;
		LaBr3MPT->AddConstProperty("SCINTILLATIONTIMECONSTANT2", Slowconst); // if slow component
		LaBr3MPT->AddConstProperty("SCINTILLATIONYIELD1", 1.0);
		LaBr3MPT->AddConstProperty("SCINTILLATIONYIELD2", 0.0);

		LaBr3->SetMaterialPropertiesTable(LaBr3MPT);
		LaBr3->GetIonisation()->SetBirksConstant(0.03 * mm / MeV); // 0.126->base; 0.0872->article BiPO
	}

	fMaterialsList.push_back(LaBr3);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ██████╗░███╗░░░███╗███╗░░░███╗░█████╗░
	// ██╔══██╗████╗░████║████╗░████║██╔══██╗
	// ██████╔╝██╔████╔██║██╔████╔██║███████║
	// ██╔═══╝░██║╚██╔╝██║██║╚██╔╝██║██╔══██║
	// ██║░░░░░██║░╚═╝░██║██║░╚═╝░██║██║░░██║
	// ╚═╝░░░░░╚═╝░░░░░╚═╝╚═╝░░░░░╚═╝╚═╝░░╚═╝

	// PMMA
	auto PMMA = new G4Material("PMMA", 1.19 * g / cm3, 3, kStateSolid, 273.15 * kelvin, 1.0 * atmosphere);
	PMMA->AddElement(G4NistManager::Instance()->FindOrBuildElement("H"), 0.532);
	PMMA->AddElement(G4NistManager::Instance()->FindOrBuildElement("C"), 0.336);
	PMMA->AddElement(G4NistManager::Instance()->FindOrBuildElement("H"), 0.132);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto PMMAMPT = new G4MaterialPropertiesTable();

		file = path + "PMMA_ref_index_geant_reverse.dat";

		Readindex.open(file);
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				// Index_Value.push_back(var);
				Index_Value.push_back(1.49);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readindex.close();

		file = path + "PMMABulkAbsorb_reverse.dat";

		//  Read_pmma_Bulk.open(pmma_Bulk);
		Readabsorb.open(file);

		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				Absorption_Energy.push_back((1240 / pWavelength) * eV);
				Absorption_Long.push_back(var * m);
			}
		}
		else
			//    G4cout << "Error opening file: " << Bulk << G4endl;
			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		PMMAMPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long);
		PMMAMPT->AddProperty("RINDEX", Index_Energy, Index_Value);

		PMMA->SetMaterialPropertiesTable(PMMAMPT);
	}

	fMaterialsList.push_back(PMMA);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ███████╗██████╗░
	// ██╔════╝██╔══██╗
	// █████╗░░██████╔╝
	// ██╔══╝░░██╔═══╝░
	// ██║░░░░░██║░░░░░
	// ╚═╝░░░░░╚═╝░░░░░

	// Fulorinated polymer
	auto FP = new G4Material("FP", 1.43 * g / cm3, 3, kStateSolid, 273.15 * kelvin, 1.0 * atmosphere);
	FP->AddElement(G4NistManager::Instance()->FindOrBuildElement("H"), 4);
	FP->AddElement(G4NistManager::Instance()->FindOrBuildElement("C"), 4);
	FP->AddElement(G4NistManager::Instance()->FindOrBuildElement("F"), 4);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto FPMPT = new G4MaterialPropertiesTable();

		file = path + "PMMA_ref_index_geant_reverse.dat";

		Readindex.open(file);
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				// Index_Value.push_back(var);
				Index_Value.push_back(1.42);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readindex.close();

		file = path + "PMMABulkAbsorb_reverse.dat";

		//  Read_pmma_Bulk.open(pmma_Bulk);
		Readabsorb.open(file);

		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				Absorption_Energy.push_back((1240 / pWavelength) * eV);
				Absorption_Long.push_back(var * m);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		FPMPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long);
		FPMPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		FP->SetMaterialPropertiesTable(FPMPT);
	}

	fMaterialsList.push_back(FP);

	// #######################################################################################################################################
	// #######################################################################################################################################

	// ███████╗███╗░░██╗░██████╗██╗░█████╗░░██████╗░
	// ╚════██║████╗░██║██╔════╝╚═╝██╔══██╗██╔════╝░
	// ░░███╔═╝██╔██╗██║╚█████╗░░░░███████║██║░░██╗░
	// ██╔══╝░░██║╚████║░╚═══██╗░░░██╔══██║██║░░╚██╗
	// ███████╗██║░╚███║██████╔╝██╗██║░░██║╚██████╔╝
	// ╚══════╝╚═╝░░╚══╝╚═════╝░╚═╝╚═╝░░╚═╝░╚═════╝░

	auto ZnS = new G4Material("ZnS", 4.1 * g / cm3, 2);
	ZnS->AddElement(G4NistManager::Instance()->FindOrBuildElement("Zn"), 1);
	ZnS->AddElement(G4NistManager::Instance()->FindOrBuildElement("S"), 1);

	{
		Read.clear();
		Readabsorb.clear();
		Readindex.clear();
		Emission_Energy.clear();
		Emission_Ratio.clear();
		Absorption_Energy.clear();
		Absorption_Long.clear();
		Index_Energy.clear();
		Index_Value.clear();

		auto ZnSMPT = new G4MaterialPropertiesTable();

		// Read primary emission spectrum

		file = path + "ZnS_spectrum.dat";

		Read.open(file);
		if (Read.is_open())
		{
			while (!Read.eof())
			{
				Read >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << 1240./pWavelength << " & emission = "<< ratio << G4endl;
				Emission_Energy.push_back((1240. / pWavelength) * eV); // convert wavelength to eV
				Emission_Ratio.push_back(var);
			}
		}
		else
		{
			G4cout << "Error opening file: " << file << G4endl;
		}
		Read.close();

		// Read primary bulk absorption

		file = path + "LaBr3_absorption_reverse.cfg";

		Readabsorb.open(file);
		if (Readabsorb.is_open())
		{
			while (!Readabsorb.eof())
			{
				Readabsorb >> pWavelength >> filler >> var;
				// G4cout << "Wavelength = " << pWavelength << " & absorption = "<< varabsorblength << G4endl;
				Absorption_Energy.push_back((1240. / pWavelength) * eV);
				Absorption_Long.push_back(0.15 * mm);
			}
		}
		else

			G4cout << "Error opening file: " << file << G4endl;

		Readabsorb.close();

		file = path + "ZnS_index_reverse.cfg";

		Readindex.open(file);
		if (Readindex.is_open())
		{
			while (!Readindex.eof())
			{
				Readindex >> pWavelength >> filler >> var;
				Index_Energy.push_back((1240 / pWavelength) * eV);
				Index_Value.push_back(var);
			}
		}
		else
			G4cout << "Error opening file: " << file << G4endl;
		Readindex.close();

		// Now apply the properties table
		ZnSMPT->AddProperty("RINDEX", Index_Energy, Index_Value);
		ZnSMPT->AddProperty("ABSLENGTH", Absorption_Energy, Absorption_Long); // the bulk absorption spectrum
		ZnSMPT->AddProperty("SCINTILLATIONCOMPONENT1", Emission_Energy, Emission_Ratio);
		// scintMPT->AddProperty("SCINTILLATIONCOMPONENT2",scintEnergy,scintEmit,scintEntries);  // if slow component

		ZnSMPT->AddConstProperty("SCINTILLATIONYIELD", lightyieldZnS / MeV);
		Res = 1;
		ZnSMPT->AddConstProperty("RESOLUTIONSCALE", Res);
		Fastconst = 200 * ns;
		ZnSMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT1", Fastconst);
		Slowconst = 1000 * ns;
		ZnSMPT->AddConstProperty("SCINTILLATIONTIMECONSTANT2", Slowconst); // if slow component
		ZnSMPT->AddConstProperty("SCINTILLATIONYIELD1", 1.0);
		ZnSMPT->AddConstProperty("SCINTILLATIONYIELD2", 0.0);

		ZnS->SetMaterialPropertiesTable(ZnSMPT);
	}

	fMaterialsList.push_back(ZnS);
	// #######################################################################################################################################
	// #######################################################################################################################################
}

TPSimMaterials::~TPSimMaterials()
{
}

G4Material *TPSimMaterials::getMaterial(const char *materialId)
{
	for (int i = 0; i < (int)fMaterialsList.size(); i++)
	{
		if (fMaterialsList[i]->GetName() == materialId)
		{
			G4cout << "Material : " << materialId << " found" << G4endl;
			return fMaterialsList[i];
		}
	}
	G4cout << "ERROR: Materials::getMaterial material " << materialId << " not found." << G4endl;
	return NULL;
}

void TPSimMaterials::printMaterialProperties(G4Material *material)
{
	std::cout << "\nMaterial name: " << material->GetName() << std::endl;
	G4MaterialPropertiesTable *mpt = material->GetMaterialPropertiesTable();
	if (!mpt)
		return;

	std::vector<G4double> fOpticalPhotonWavelength = {360, 400., 440., 480., 520., 560., 600., 640., 680., 720., 760};

	// Print photon wavelengths
	std::cout << std::left << std::setw(TAB_COLUMN_1) << "PHOTON_WAVELEGTH, nm";
	for (G4int i = 0; i < (G4int)fOpticalPhotonWavelength.size(); i++)
	{
		std::cout << std::left << std::setw(TAB_COLUMN) << fOpticalPhotonWavelength[i];
	}

	std::cout << std::endl;

	// Print photon energy
	std::cout << std::left << std::setw(TAB_COLUMN_1) << "PHOTON_ENERGY, eV";
	for (G4int i = 0; i < (G4int)fOpticalPhotonWavelength.size(); i++)
	{
		std::cout << std::left << std::setw(TAB_COLUMN) << wavelengthNmToEnergy(fOpticalPhotonWavelength[i]) / eV;
	}
	std::cout << std::endl;

	// Print material properties
	std::vector<G4String> propertyNames = mpt->GetMaterialPropertyNames();

	// Replaced in Geant4 v.11 with const std::vector<G4MaterialPropertyVector*>& GetProperties() const
	// const std::map<G4int, G4MaterialPropertyVector*, std::less<G4int> >* pMapNew = mpt->GetPropertyMap();
	std::vector<G4String> materialPropertiesNames = mpt->GetMaterialPropertyNames();

	for (G4String propertyName : materialPropertiesNames)
	{
		G4MaterialPropertyVector *property = mpt->GetProperty(propertyName);
		if (!property)
			continue;

		// Print property name
		std::cout << std::left << std::setw(TAB_COLUMN_1) << propertyName;
		// Print property values
		for (G4int i = 0; i < (G4int)fOpticalPhotonWavelength.size(); i++)
		{
			G4bool b;
			G4double value = property->GetValue(wavelengthNmToEnergy(fOpticalPhotonWavelength[i]), b);
			std::cout << std::left << std::setw(TAB_COLUMN) << value;
		}

		std::cout << std::endl;
	}

	// Print material constant properties
	std::vector<G4String> constPropertyNames = mpt->GetMaterialConstPropertyNames();
	for (G4String constPropertyName : constPropertyNames)
	{
		if (!mpt->ConstPropertyExists(constPropertyName))
			continue;
		// Print property name and value
		G4double constPropertyValue = mpt->GetConstProperty(constPropertyName);
		std::cout << std::left << std::setw(TAB_COLUMN_1) << constPropertyName << constPropertyValue << std::endl;
	}
}

void TPSimMaterials::printMaterialProperties(const char *materialId)
{
	G4Material *material = getMaterial(materialId);
	if (material == NULL)
		return;
	printMaterialProperties(material);
}

TPSimMaterials *TPSimMaterials::getInstance()
{
	static TPSimMaterials materials;
	if (fgInstance == nullptr)
	{
		fgInstance = &materials;
	}
	return fgInstance;
}

G4double TPSimMaterials::wavelengthNmToEnergy(G4double wavelength)
{
	G4double hc = 1239.84193;
	return hc / wavelength * eV; // E (eV) = 1239.8 / l (nm)
}