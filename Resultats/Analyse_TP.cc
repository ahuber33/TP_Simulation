#include "Analyse_TP.hh"
//#include "Analyse_TP_backup_first_study.hh"


void Analyse_TP()
{
  gStyle->SetOptStat("");
  gROOT->ProcessLine("#include <vector>");

  float mp = 1.6726e-27; //kg
  float mHe = 4.0026*1.66054e-27;
  float qp = 1.6e-19; //C

  string file_He1 = "Pinhole_variation/He1+_pinhole.root";
  string file_He2 = "Pinhole_variation/He2+_pinhole.root";
  float pinhole =0.1;
  float B = 0.3; //T
  float E = 1.5e+6; //V/m
  float Le1 = 0.15; //m
  float Le2 = 0.155; //m
  float D = 5e-3; //m
  float Lb1 = 0.05; //m
  float Lb2 = 0.310; //m
  float Sc_length = 0.1; //m
  float Sc_thickness = 100e-6; //m
  float ZnS_thickness = 100e-6; //m
  string Optique_Yes = "Yes";
  string Optique_No = "No";
  bool Optique = false;


  //Analyse("Borlin333_Files/proton_Config_PAUL_1-12MeV_RoundBunchFibersDoubleCladding_0.2mm_1m_pinhole_100um_FactorLY_0.1_100k.root", "Borlin333_Files/He1+_Config_PAUL_1-12MeV_RoundBunchFibersDoubleCladding_0.2mm_1m_pinhole_100um_FactorLY_0.1_100k.root", "Borlin333_Files/He2+_Config_PAUL_1-12MeV_RoundBunchFibersDoubleCladding_0.2mm_1m_pinhole_100um_FactorLY_0.1_100k.root", "Optical", "Config TP PETAL Exp", 0.5, 0.5, 1400000, 62.5, 20.75, 262.1, 745.9, 400, 0, 0., true, -40, -40, -25, 6);


  
  //Analyse("proton_pinhole_200um.root", "He1+_pinhole_200um.root", "He2+_pinhole_200um.root", "TP", "pinhole 200 um", 0.2, B, E, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -10, -2.9, 2);
  //Analyse("proton_pinhole_150um.root", "He1+_pinhole_150um.root", "He2+_pinhole_150um.root", "TP", "pinhole 150 um", 0.15, B, E, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -10, -3, 1.2);
  //Analyse(file_proton.c_str(), file_He1.c_str(), file_He2.c_str(), "TP", "pinhole 100 um", pinhole, B, E, 150, 5, 50, 310, 100, 1, 0., false, -15, -10, -3.1, 1.5);
  //Analyse("proton_pinhole_75um.root", "He1+_pinhole_75um.root", "He2+_pinhole_75um.root", "TP", "pinhole 75 um", 0.075, B, E, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -8, -3.2, 1.3);
  //Analyse("proton_pinhole_50um.root", "He1+_pinhole_50um.root", "He2+_pinhole_50um.root", "TP", "pinhole 50 um", 0.05, B, E, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -8, -3.2, 2);
  //Analyse("proton_pinhole_100um_B_0.6T.root", "He1+_pinhole_100um_B_0.6T.root", "He2+_pinhole_100um_B_0.6T.root", "TP", "pinhole 100 um - B 0.6T", 0.1, 0.6, E, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -10, -3, 1.6);
  //Analyse("proton_pinhole_100um_B_0.9T.root", "He1+_pinhole_100um_B_0.9T.root", "He2+_pinhole_100um_B_0.9T.root", "TP", "pinhole 100 um - B 0.9T", 0.1, 0.9, E, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -15, -9.9, 1.5);
  //Analyse("proton_Config_TP_existante.root", "He1+_Config_TP_existante.root", "He2+_Config_TP_existante.root", "TP", "Config TP existante pinhole 100um", 0.1, 0.6, E, 50.8, 8.45, 40, 108.85, 100, 1, 0.1, false, -20, -10, -3.5, 1);
  //Analyse("proton_Config_TP_ENL_1MeV_10MeV.root", "He1+_Config_TP_ENL_1MeV_10MeV.root", "He2+_Config_TP_ENL_1MeV_10MeV.root", "TP", "Config TP existante pinhole 100um", 0.1, 0.6, 630000, 50., 0, 40, 175, 200, 0, 0., false, -25, -17, -15.5, 1.1);
  //Analyse("ZnS/proton_Config_TP_ENL_ZnS_0.1_1MeV_10MeV.root", "ZnS/He1+_Config_TP_ENL_ZnS_0.1_1MeV_10MeV.root", "ZnS/He2+_Config_TP_ENL_ZnS_0.1_1MeV_10MeV.root", "TP", "Config TP existante pinhole 100um with ZnS 0.1mm", 0.1, 0.6, 630000, 50., 0, 40, 175, 200, 0., 0.1, false, -25, -17, -15.8, 1.3);
  //Analyse("test1.root", "test2.root", "test3.root", "TP", "Config TP existante pinhole 100um with ZnS 0.1mm", 0.1, 0.6, 630000, 50., 0, 40, 175, 200, 0., 0.1, false, -25, -17, -15.8, 1.3);
  //Analyse("ELFEX/proton_Config_TP_ELFEX_new.root", "ELFEX/He1+_Config_TP_ELFEX_new.root", "ELFEX/He2+_Config_TP_ELFEX_new.root", "TP", "Config TP ELFEX new", 0.3, 0.8, 1200000, 150., 20, 175, 200, 400, 0, 0., false, -100, -70, -52, 3.5);
  //Analyse("PETAL/proton_Config_TP_PETAL.root", "PETAL/He1+_Config_TP_PETAL.root", "PETAL/He2+_Config_TP_PETAL.root", "TP", "Config TP PETAL", 0.5, 0.5, 1400000, 62.5, 20.75, 262.1, 745.9, 400, 0, 0., false, -28, -25, -14.8, 6);
  //Analyse("PETAL/proton_Config_TP_PETAL_Exp.root", "PETAL/He1+_Config_TP_PETAL_Exp.root", "PETAL/He2+_Config_TP_PETAL_Exp.root", "TP", "Config TP PETAL Exp", 0.5, 0.5, 1400000, 62.5, 20.75, 262.1, 745.9, 400, 0, 0., false, -40, -40, -25, 6);
  //Analyse("PETAL/proton_Config_TP_PETAL_Exp_pinhole_1mm.root", "PETAL/He1+_Config_TP_PETAL_Exp_pinhole_1mm.root", "PETAL/He2+_Config_TP_PETAL_Exp_pinhole_1mm.root", "TP", "Config TP PETAL Exp pinhole 1mm", 1, 0.5, 1400000, 62.5, 20.75, 262.1, 745.9, 400, 0, 0., false, -40, -40, -25, 6);
  //Analyse("PETAL/proton_Config_TP_PETAL_pinhole_1mm.root", "PETAL/He1+_Config_TP_PETAL_pinhole_1mm.root", "PETAL/He2+_Config_TP_PETAL_pinhole_1mm.root", "TP", "Config TP PETAL pinhole 1mm", 1, 0.5, 1400000, 62.5, 20.75, 262.1, 745.9, 400, 0, 0., false, -30, -25, -15, 6);
  //Analyse("proton_pinhole_100um_B_0.6T_E_1000kV.root", "He1+_pinhole_100um_B_0.6T_E_1000kV.root", "He2+_pinhole_100um_B_0.6T_E_1000kV.root", "TP", "pinhole 100 um - B 0.6T - E 1000 kV/m", 0.1, 0.6, 1e6, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -9, -6.5, 1.4);
  //Analyse("proton_pinhole_100um_B_0.6T_E_2000kV.root", "He1+_pinhole_100um_B_0.6T_E_2000kV.root", "He2+_pinhole_100um_B_0.6T_E_2000kV.root", "TP", "pinhole 100 um - B 0.6T - E 2000 kV/m", 0.1, 0.6, 2e6, 50, 5, 150, 155, 100, 1, 0.1, false, -15, -10, -3, 1.6);
  //Analyse("proton_pinhole_100um_B_0.6T_E_2000kV_Le1_300.root", "He1+_pinhole_100um_B_0.6T_E_2000kV_Le1_300.root", "He2+_pinhole_100um_B_0.6T_E_2000kV_Le1_300.root", "TP", "pinhole 100 um - B 0.6T - E 2000 kV/m - Le1 300 mm", 0.1, 0.6, 2e6, 50, 5, 300, 150, 100, 1, 0.1, false, -15, -10, -3, 2);
  //Analyse("proton_pinhole_100um_B_0.6T_E_2000kV_Le1_300_Optique.root", "He1+_pinhole_100um_B_0.6T_E_2000kV_Le1_300_Optique.root", "He2+_pinhole_100um_B_0.6T_E_2000kV_Le1_300_Optique.root", "Optical", "pinhole 100 um - B 0.6T - E 2000 kV/m - Le1 300 mm Optical", 0.1, 0.6, 2e6, 50, 5, 150, 300, 100, 1, 0., true, -15, -11, -9.5, 2);
  //Analyse("proton_pinhole_200um_B_0.6T_E_2000kV_Le1_300.root", "He1+_pinhole_200um_B_0.6T_E_2000kV_Le1_300.root", "He2+_pinhole_200um_B_0.6T_E_2000kV_Le1_300.root", "TP", "pinhole 200 um - B 0.6T - E 2000 kV/m - Le1 300 mm", 0.2, 0.6, 2e6, 50, 5, 150, 300, 100, 1, 0.1, false, -15, -10, -3, 2);
  //Analyse("proton_ligne_Optique_div10_0.1_0.1.root", "He1+_ligne_Optique_div10_0.1_0.1.root", "He2+_ligne_Optique_div10_0.1_0.1.root", "Optical", "Optical ligne", 0, B, E, 50, 5, 150, 155, 100, 0.1, 0.1, true, -8, -5, -3.1, 2);
  //Analyse("proton_E_1000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_1000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_1000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 1000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.3, 1e6, 50, 5, 150, 150, 100, 1, 0., false, -10, -8, -3, 1.7);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.3, 1.5e6, 50, 5, 150, 150, 100, 1, 0., false, -10, -7, -3, 1.4);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.3, 2e6, 50, 5, 150, 150, 100, 1, 0., false, -10, -6, -3, 1.4);
  //Analyse("proton_E_1000_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_1000_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_1000_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 1000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.6, 1e6, 50, 5, 150, 150, 100, 1, 0., false, -11.5, -9, -6.5, 1.5);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.6, 1.5e6, 50, 5, 150, 150, 100, 1, 0., false, -11.5, -9, -6.5, 1.2);
  //Analyse("proton_E_2000_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_2000_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_2000_B_0.6_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 2000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.6, 2e6, 50, 5, 150, 150, 100, 1, 0., false, -11.5, -9, -6.5, 1.2);
  //Analyse("proton_E_1000_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_1000_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_1000_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 1000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.9, 1e6, 50, 5, 150, 150, 100, 1, 0., false, -20, -15, -9.9, 1.3);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.9, 1.5e6, 50, 5, 150, 150, 100, 1, 0., false, -20, -15, -9.9, 1.6);
  //Analyse("proton_E_2000_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_2000_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_2000_B_0.9_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 2000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.9, 2e6, 50, 5, 150, 150, 100, 1, 0., false, -20, -11, -9.9, 1.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.3, 1.5e6, 50, 5, 225, 150, 100, 1, 0., false, -10, -7, -3.9, 1.1);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.6, 1.5e6, 50, 5, 225, 150, 100, 1, 0., false, -15, -10, -8, 1.5);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.9, 1.5e6, 50, 5, 225, 150, 100, 1, 0., false, -20, -15, -12.2, 1.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_150.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_150.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 150 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 150, 100, 1, 0., false, -10, -6, -4.7, 2);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_300_Le2_150.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_300_Le2_150.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_300_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 300 mm Le2 150 mm", 0.1, 0.6, 1.5e6, 50, 5, 300, 150, 100, 1, 0., false, -15, -12, -9.4, 2);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_300_Le2_150.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_300_Le2_150.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_300_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 300 mm Le2 150 mm", 0.1, 0.9, 1.5e6, 50, 5, 300, 150, 100, 1, 0., false, -20, -17, -14.5, 2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_150.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_150.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 100 mm Le2 150 mm", 0.1, 0.3, 1.5e6, 50, 5, 100, 150, 100, 1, 0., false, -10, -7, -2.7, 1.8);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_150.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_150.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 100 mm Le2 150 mm", 0.1, 0.6, 1.5e6, 50, 5, 100, 150, 100, 1, 0., false, -10, -5.9, -2.7, 1.8);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_150.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_150.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 100 mm Le2 150 mm", 0.1, 0.9, 1.5e6, 50, 5, 100, 150, 100, 1, 0., false, -17, -9.5, -8.4, 1.7);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_75.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_75.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_75.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 225 mm Le2 75 mm", 0.1, 0.3, 1.5e6, 50, 5, 225, 75, 100, 1, 0., false, -10, -6, -3.2, 1.6);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_75.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_75.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_75.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 225 mm Le2 75 mm", 0.1, 0.6, 1.5e6, 50, 5, 225, 75, 100, 1, 0., false, -10, -8, -6.5, 1.5);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_75.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_75.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_75.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 225 mm Le2 75 mm", 0.1, 0.9, 1.5e6, 50, 5, 225, 75, 100, 1, 0., false, -14, -11, -9.9, 1.5);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_0.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_0.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_0.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 0 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 0, 100, 1, 0., false, -10, -6, -3.2, 1.6);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_300_Le2_0.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_300_Le2_0.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_300_Le2_0.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 300 mm Le2 0 mm", 0.1, 0.6, 1.5e6, 50, 5, 300, 0, 100, 1, 0., false, -14, -11, -6.5, 1.4);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_300_Le2_0.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_300_Le2_0.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_300_Le2_0.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 300 mm Le2 0 mm", 0.1, 0.9, 1.5e6, 50, 5, 300, 0, 100, 1, 0., false, -14, -11, -9.9, 1.4);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_200.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_200.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_200.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 100 mm Le2 200 mm", 0.1, 0.3, 1.5e6, 50, 5, 100, 200, 100, 1, 0., false, -10, -6, -3.2, 1.7);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_200.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_200.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_200.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 100 mm Le2 200 mm", 0.1, 0.6, 1.5e6, 50, 5, 100, 200, 100, 1, 0., false, -14, -11, -6.5, 1.4);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_200.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_200.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_200.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 100 mm Le2 200 mm", 0.1, 0.9, 1.5e6, 50, 5, 100, 200, 100, 1, 0., false, -17, -11, -9.9, 1.8);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_275.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_275.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_100_Le2_275.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 100 mm Le2 275 mm", 0.1, 0.3, 1.5e6, 50, 5, 100, 275, 100, 1, 0., false, -10, -6, -3.2, 1.4);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_275.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_275.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_100_Le2_275.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 100 mm Le2 275 mm", 0.1, 0.6, 1.5e6, 50, 5, 100, 275, 100, 1, 0., false, -14, -11, -6.5, 1.7);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_275.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_275.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_100_Le2_275.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 100 mm Le2 275 mm", 0.1, 0.9, 1.5e6, 50, 5, 100, 275, 100, 1, 0., false, -19, -15, -12, 1.1);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_150_Le2_225.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_150_Le2_225.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_150_Le2_225.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 150 mm Le2 225 mm", 0.1, 0.3, 1.5e6, 50, 5, 150, 225, 100, 1, 0., false, -10, -6, -3.2, 1.3);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_150_Le2_225.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_150_Le2_225.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_150_Le2_225.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 150 mm Le2 225 mm", 0.1, 0.6, 1.5e6, 50, 5, 150, 225, 100, 1, 0., false, -14, -11, -6.5, 1.3);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_150_Le2_225.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_150_Le2_225.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_150_Le2_225.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 150 mm Le2 225 mm", 0.1, 0.9, 1.5e6, 50, 5, 150, 225, 100, 1, 0., false, -19, -15, -9.9, 1.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.3, 1.5e6, 50, 5, 225, 150, 100, 1, 0., false, -10, -6, -3.2, 1.1);
  //Analyse("proton_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_1500_B_0.6_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.6T - E 1500 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.6, 1.5e6, 50, 5, 225, 150, 100, 1, 0., false, -13, -11, -6.5, 1.3);
  //Analyse("proton_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_1500_B_0.9_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.9T - E 1500 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.9, 1.5e6, 50, 5, 225, 150, 100, 1, 0., false, -19, -15, -9.9, 1.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_75.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_75.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_75.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 75 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 75, 100, 1, 0., false, -10, -6, -3.2, 1.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_375_Le2_0.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_375_Le2_0.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_375_Le2_0.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 375 mm Le2 0 mm", 0.1, 0.3, 1.5e6, 50, 5, 375, 0, 100, 1, 0., false, -10, -6, -3.2, 1.2);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_200.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_200.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_200.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 100 mm Le2 200 mm", 0.1, 0.3, 2e6, 50, 5, 100, 200, 100, 1, 0., false, -10, -6, -3.2, 1.4);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 150 mm Le2 150 mm", 0.1, 0.3, 2e6, 50, 5, 150, 150, 100, 1, 0., false, -10, -6, -3.2, 1.4);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_75.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_75.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_75.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 75 mm", 0.1, 0.3, 2e6, 50, 5, 225, 75, 100, 1, 0., false, -5, -4, -3.2, 1);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_0.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_0.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_0.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 300 mm Le2 0 mm", 0.1, 0.3, 2e6, 50, 5, 300, 0, 100, 1, 0., false, -10, -5, -3.2, 1.);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_275.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_275.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_275.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 100 mm Le2 275 mm", 0.1, 0.3, 2e6, 50, 5, 100, 275, 100, 1, 0., false, -10, -5, -3.2, 1.5);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_225.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_225.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_225.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 150 mm Le2 225 mm", 0.1, 0.3, 2e6, 50, 5, 150, 225, 100, 1, 0., false, -10, -5, -3.2, 1.3);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_150.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 150 mm", 0.1, 0.3, 2e6, 50, 5, 225, 150, 100, 1, 0., false, -10, -5, -3.2, 2);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_75.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_75.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_75.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 300 mm Le2 75 mm", 0.1, 0.3, 2e6, 50, 5, 300, 75, 100, 1, 0., false, -10, -5, -3.2, 2);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_245.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_245.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_245.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 100 mm Le2 245 mm", 0.1, 0.3, 2e6, 50, 5, 100, 245, 100, 1, 0., false, -10, -5, -3.2, 1.4);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_195.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_195.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_195.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 150 mm Le2 195 mm", 0.1, 0.3, 2e6, 50, 5, 150, 195, 100, 1, 0., false, -10, -5, -3.2, 1.5);

  //####################################################################################
  //################################# CONFIG 4 #########################################
  //####################################################################################
  //Analyse("Pinhole_variation/proton_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_120.root", "Pinhole_variation/He1+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_120.root", "Pinhole_variation/He2+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_120.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., false, -10, -5, -3.2, 1.5);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.15_Le1_225_Le2_120.root", "He1+_E_2000_B_0.3_pinhole_0.15_Le1_225_Le2_120.root", "He2+_E_2000_B_0.3_pinhole_0.15_Le1_225_Le2_120.root", "TP", "pinhole 150 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm", 0.15, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., false, -10, -5, -3.2, 2.2);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.2_Le1_225_Le2_120.root", "He1+_E_2000_B_0.3_pinhole_0.2_Le1_225_Le2_120.root", "He2+_E_2000_B_0.3_pinhole_0.2_Le1_225_Le2_120.root", "TP", "pinhole 200 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm", 0.2, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., false, -10, -5, -3.2, 2.4);

  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_225.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_225.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_225.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 100 mm Le2 225 mm", 0.1, 0.3, 2e6, 50, 5, 100, 225, 100, 1, 0., false, -10, -5, -3.2, 1.6);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_175.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_175.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_175.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 150 mm Le2 175 mm", 0.1, 0.3, 2e6, 50, 5, 150, 175, 100, 1, 0., false, -10, -5, -3.2, 1.3);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_100.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_100.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_100.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 100 mm", 0.1, 0.3, 2e6, 50, 5, 225, 100, 100, 1, 0., false, -10, -5, -3.2, 1.6);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_25.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_25.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_25.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 300 mm Le2 25 mm", 0.1, 0.3, 2e6, 50, 5, 300, 25, 100, 1, 0., false, -10, -5, -3.2, 1.6);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_235.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_235.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_100_Le2_235.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 100 mm Le2 235 mm", 0.1, 0.3, 2e6, 50, 5, 100, 235, 100, 1, 0., false, -10, -5, -3.2, 1.4);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_185.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_185.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_150_Le2_185.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 150 mm Le2 185 mm", 0.1, 0.3, 2e6, 50, 5, 150, 185, 100, 1, 0., false, -10, -5, -3.2, 1.4);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_110.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_110.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_225_Le2_110.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 110 mm", 0.1, 0.3, 2e6, 50, 5, 225, 110, 100, 1, 0., false, -10, -5, -3.2, 1.7);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_35.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_35.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_300_Le2_35.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 300 mm Le2 35 mm", 0.1, 0.3, 2e6, 50, 5, 300, 35, 100, 1, 0., false, -10, -5, -3.2, 1.8);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_205.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_205.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_205.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 200 mm Le2 205 mm", 0.1, 0.3, 1.5e6, 50, 5, 200, 205, 100, 1, 0., false, -10, -5, -3.2, 1.5);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_155.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_155.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_155.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 250 mm Le2 155 mm", 0.1, 0.3, 1.5e6, 50, 5, 250, 155, 100, 1, 0., false, -10, -5, -3.2, 1.6);

  //####################################################################################
  //################################# CONFIG 2 #########################################
  //####################################################################################
  //Analyse("Pinhole_variation/proton_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_105.root", "Pinhole_variation/He1+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_105.root", "Pinhole_variation/He2+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_105.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 1, 0., false, -10, -5, -3.2, 1.5);
  //Analyse("Config2/proton_E_1500_B_0.3_pinhole_0.15_Le1_300_Le2_105.root", "Config2/He1+_E_1500_B_0.3_pinhole_0.15_Le1_300_Le2_105.root", "Config2/He2+_E_1500_B_0.3_pinhole_0.15_Le1_300_Le2_105.root", "TP", "pinhole 150 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm", 0.15, 0.3, 1.5e6, 50, 5, 300, 105, 100, 1, 0., false, -10, -5, -3.2, 2.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.2_Le1_300_Le2_105.root", "He1+_E_1500_B_0.3_pinhole_0.2_Le1_300_Le2_105.root", "He2+_E_1500_B_0.3_pinhole_0.2_Le1_300_Le2_105.root", "TP", "pinhole 200 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm", 0.2, 0.3, 1.5e6, 50, 5, 300, 105, 100, 1, 0., false, -10, -5, -3.2, 2.2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_350_Le2_25.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_350_Le2_25.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_350_Le2_25.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 350 mm Le2 25 mm", 0.1, 0.3, 1.5e6, 50, 5, 350, 25, 100, 1, 0., false, -10, -5, -3.2, 1.5);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_115.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_115.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_115.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 250 mm Le2 115 mm", 0.1, 0.3, 1.5e6, 50, 5, 250, 115, 100, 1, 0., false, -10, -5, -3.2, 2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_65.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_65.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_65.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 65 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 65, 100, 1, 0., false, -10, -5, -3.2, 1.4);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_350_Le2_15.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_350_Le2_15.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_350_Le2_15.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 350 mm Le2 15 mm", 0.1, 0.3, 1.5e6, 50, 5, 350, 15, 100, 1, 0., false, -10, -5, -3.2, 1.6);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_160.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_160.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_160.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 200 mm Le2 160 mm", 0.1, 0.3, 1.5e6, 50, 5, 200, 160, 100, 1, 0., false, -10, -5, -3.2, 2);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_110.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_110.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_110.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 250 mm Le2 110 mm", 0.1, 0.3, 1.5e6, 50, 5, 250, 110, 100, 1, 0., false, -10, -5, -3.2, 1.8);
  //Analyse("Pinhole_variation/proton_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_145.root", "Pinhole_variation/He1+_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_145.root", "Pinhole_variation/He2+_E_1500_B_0.3_pinhole_0.1_Le1_200_Le2_145.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 200 mm Le2 145 mm", 0.1, 0.3, 1.5e6, 50, 5, 200, 145, 100, 1, 0., false, -10, -5, -3.2, 1.3);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_95.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_95.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_250_Le2_95.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 250 mm Le2 95 mm", 0.1, 0.3, 1.5e6, 50, 5, 250, 95, 100, 1, 0., false, -10, -5, -3.2, 1.4);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_45.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_45.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_300_Le2_45.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 45 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 45, 100, 1, 0., false, -10, -5, -3.2, 1.4);
  //Analyse("proton_E_1500_B_0.3_pinhole_0.1_Le1_345_Le2_0.root", "He1+_E_1500_B_0.3_pinhole_0.1_Le1_345_Le2_0.root", "He2+_E_1500_B_0.3_pinhole_0.1_Le1_345_Le2_0.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 345 mm Le2 0 mm", 0.1, 0.3, 1.5e6, 50, 5, 345, 0, 100, 1, 0., false, -10, -5, -3.2, 1.1);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_200_Le2_115.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_200_Le2_115.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_200_Le2_115.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 200 mm Le2 115 mm", 0.1, 0.3, 2e6, 50, 5, 200, 115, 100, 1, 0., false, -10, -5, -3.2, 1.1);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.1_Le1_250_Le2_65.root", "He1+_E_2000_B_0.3_pinhole_0.1_Le1_250_Le2_65.root", "He2+_E_2000_B_0.3_pinhole_0.1_Le1_250_Le2_65.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 250 mm Le2 65 mm", 0.1, 0.3, 2e6, 50, 5, 250, 65, 100, 1, 0., false, -10, -5, -3.2, 1.5);

  //####################################################################################
  //################################# CONFIG 3 #########################################
  //####################################################################################
  //Analyse("Pinhole_variation/proton_E_2000_B_0.3_pinhole_0.1_Le1_280_Le2_35.root", "Pinhole_variation/He1+_E_2000_B_0.3_pinhole_0.1_Le1_280_Le2_35.root", "Pinhole_variation/He2+_E_2000_B_0.3_pinhole_0.1_Le1_280_Le2_35.root", "TP", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 280 mm Le2 35 mm", 0.1, 0.3, 2e6, 50, 5, 280, 35, 100, 1, 0., false, -8, -5, -3.2, 1.3);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.15_Le1_280_Le2_35.root", "He1+_E_2000_B_0.3_pinhole_0.15_Le1_280_Le2_35.root", "He2+_E_2000_B_0.3_pinhole_0.15_Le1_280_Le2_35.root", "TP", "pinhole 150 um - B 0.3T - E 2000 kV/m - Le1 280 mm Le2 35 mm", 0.15, 0.3, 2e6, 50, 5, 280, 35, 100, 1, 0., false, -8, -4, -3.2, 2);
  //Analyse("proton_E_2000_B_0.3_pinhole_0.2_Le1_280_Le2_35.root", "He1+_E_2000_B_0.3_pinhole_0.2_Le1_280_Le2_35.root", "He2+_E_2000_B_0.3_pinhole_0.2_Le1_280_Le2_35.root", "TP", "pinhole 200 um - B 0.3T - E 2000 kV/m - Le1 280 mm Le2 35 mm", 0.2, 0.3, 2e6, 50, 5, 280, 35, 100, 1, 0., false, -8, -5, -3.2, 2.);

  //####################################################################################
  //################################# CONFIG 1 #########################################
  //####################################################################################
  //Analyse("Pinhole_variation/proton_E_1500_B_0.3_pinhole_0.1_Le1_320_Le2_25.root", "Pinhole_variation/He1+_E_1500_B_0.3_pinhole_0.1_Le1_320_Le2_25.root", "Pinhole_variation/He2+_E_1500_B_0.3_pinhole_0.1_Le1_320_Le2_25.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 320 mm Le2 25 mm", 0.1, 0.3, 1.5e6, 50, 5, 320, 25, 100, 1, 0., false, -8, -5, -3.2, 1.0);

  //Analyse("Pinhole_variation/proton_E_1500_B_0.3_pinhole_0.15_Le1_320_Le2_25.root", "Pinhole_variation/He1+_E_1500_B_0.3_pinhole_0.15_Le1_320_Le2_25.root", "Pinhole_variation/He2+_E_1500_B_0.3_pinhole_0.15_Le1_320_Le2_25.root", "TP", "pinhole 150 um - B 0.3T - E 1500 kV/m - Le1 320 mm Le2 25 mm", 0.15, 0.3, 1.5e6, 50, 5, 320, 25, 100, 1, 0., false, -8, -5, -3.2, 1.4);
  //Analyse("Pinhole_variation/proton_E_1500_B_0.3_pinhole_0.2_Le1_320_Le2_25.root", "Pinhole_variation/He1+_E_1500_B_0.3_pinhole_0.2_Le1_320_Le2_25.root", "Pinhole_variation/He2+_E_1500_B_0.3_pinhole_0.2_Le1_320_Le2_25.root", "TP", "pinhole 200 um - B 0.3T - E 1500 kV/m - Le1 320 mm Le2 25 mm", 0.2, 0.3, 1.5e6, 50, 5, 320, 25, 100, 1, 0., false, -8, -5, -3.2, 2);



  //####################################################################################
  //################################# CONFIG 4 W SC#####################################
  //####################################################################################
  //Analyse("proton_Config4_Sc_0.05.root", "He1+_Config4_Sc_0.05.root", "He2+_Config4_Sc_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -6, -5, -3.7, 1.2);
  //Analyse("proton_Config4_Sc_0.1.root", "He1+_Config4_Sc_0.1.root", "He2+_Config4_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -6, -5, -3.2, 1.5);
  //Analyse("proton_Config4_Sc_0.25.root", "He1+_Config4_Sc_0.25.root", "He2+_Config4_Sc_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -6, -5, -3.2, 1.7);
  //Analyse("proton_Config4_Sc_0.5.root", "He1+_Config4_Sc_0.5.root", "He2+_Config4_Sc_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.5 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -6, -5, -3.8, 1.8);
  //Analyse("proton_Config4_Sc_1.root", "He1+_Config4_Sc_1.root", "He2+_Config4_Sc_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -4.5, -3.8, 2);
  //Analyse("proton_Config4_Sc_1.root", "He1+_Config4_Sc_1.root", "He2+_Config4_Sc_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -4.5, -3.8, 3);
  //Analyse("proton_Config4_ZnS_0.05.root", "He1+_Config4_ZnS_0.05.root", "He2+_Config4_ZnS_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.05 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0, 0.1, true, -6, -4.5, -3.8, 1.1);
  //Analyse("proton_Config4_ZnS_0.1.root", "He1+_Config4_ZnS_0.1.root", "He2+_Config4_ZnS_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0, 0.1, true, -6, -4.5, -3.8, 1.1);
  //Analyse("proton_Config4_ZnS_0.25.root", "He1+_Config4_ZnS_0.25.root", "He2+_Config4_ZnS_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.25 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0, 0.25, true, -6, -4.5, -3.8, 1.4);
  //Analyse("proton_Config4_ZnS_0.5.root", "He1+_Config4_ZnS_0.5.root", "He2+_Config4_ZnS_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0, 0.5, true, -6, -4.5, -3.8, 1.6);
  //Analyse("proton_Config4_ZnS_1.root", "He1+_Config4_ZnS_1.root", "He2+_Config4_ZnS_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0, 1, true, -5, -3.8, -3.7, 1.6);
  //Analyse("proton_Config4_ZnS_2.root", "He1+_Config4_ZnS_2.root", "He2+_Config4_ZnS_2.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 2 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0, 2, true, -5, -4.5, -3.8, 1.5);
  //Analyse("proton_Config4_NoWaSH_0.05.root", "He1+_Config4_NoWaSH_0.05.root", "He2+_Config4_NoWaSH_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.05 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -5, -4.5, -3.8, 1.2);
  //Analyse("proton_Config4_NoWaSH_0.1.root", "He1+_Config4_NoWaSH_0.1.root", "He2+_Config4_NoWaSH_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -6, -4.5, -3.8, 1.6);
  //Analyse("proton_Config4_NoWaSH_0.25.root", "He1+_Config4_NoWaSH_0.25.root", "He2+_Config4_NoWaSH_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.25 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -6, -4.5, -3.8, 1.);
  //Analyse("proton_Config4_NoWaSH_0.5.root", "He1+_Config4_NoWaSH_0.5.root", "He2+_Config4_NoWaSH_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.5 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -6, -4.5, -3.8, 1.4);
  //Analyse("proton_Config4_NoWaSH_1.root", "He1+_Config4_NoWaSH_1.root", "He2+_Config4_NoWaSH_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -4.5, -3.8, 1);
  //Analyse("proton_Config4_NoWaSH_2.root", "He1+_Config4_NoWaSH_2.root", "He2+_Config4_NoWaSH_2.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 2 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 2, 0., true, -5.5, -4.5, -3.8, 1.3);



  //####################################################################################
  //################################# CONFIG 3 W SC#####################################
  //####################################################################################
  //Analyse("proton_Config3_Sc_0.05.root", "He1+_Config3_Sc_0.05.root", "He2+_Config3_Sc_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -6, -5, -3.2, 1);
  //Analyse("proton_Config3_Sc_0.1.root", "He1+_Config3_Sc_0.1.root", "He2+_Config3_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -6, -5, -3.2, 1.8);
  //Analyse("proton_Config3_Sc_0.25.root", "He1+_Config3_Sc_0.25.root", "He2+_Config3_Sc_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -6, -5, -3.2, 1.3);
  //Analyse("proton_Config3_Sc_0.5.root", "He1+_Config3_Sc_0.5.root", "He2+_Config3_Sc_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 0.5 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -6, -5, -3.2, 1.5);
  //Analyse("proton_Config3_Sc_1.root", "He1+_Config3_Sc_1.root", "He2+_Config3_Sc_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - EJ 212 1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -5, -3.2, 1.3);
  //Analyse("proton_Config3_ZnS_0.05.root", "He1+_Config3_ZnS_0.05.root", "He2+_Config3_ZnS_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.05, true, -3.5, -5, -3.2, 0.9);
  //Analyse("proton_Config3_ZnS_0.1.root", "He1+_Config3_ZnS_0.1.root", "He2+_Config3_ZnS_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.1, true, -3.5, -5, -3.2, 1.6);
  //Analyse("proton_Config3_ZnS_0.25.root", "He1+_Config3_ZnS_0.25.root", "He2+_Config3_ZnS_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.25, true, -5, -5, -3.4, 1.2);
  //Analyse("proton_Config3_ZnS_0.5.root", "He1+_Config3_ZnS_0.5.root", "He2+_Config3_ZnS_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.5, true, -5., -5, -3.2, 1.1);
  //Analyse("proton_Config3_ZnS_1.root", "He1+_Config3_ZnS_1.root", "He2+_Config3_ZnS_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 1, true, -5., -5, -3.2, 1.3);
  //Analyse("proton_Config3_NoWaSH_0.05.root", "He1+_Config3_NoWaSH_0.05.root", "He2+_Config3_NoWaSH_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.05 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -6, -4.5, -3.8, 1.6);
  //Analyse("proton_Config3_NoWaSH_0.1.root", "He1+_Config3_NoWaSH_0.1.root", "He2+_Config3_NoWaSH_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -6, -4.5, -3.8, 1.7);
  //Analyse("proton_Config3_NoWaSH_0.25.root", "He1+_Config3_NoWaSH_0.25.root", "He2+_Config3_NoWaSH_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.25 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -6, -4.5, -3.8, 1.5);
  //Analyse("proton_Config3_NoWaSH_0.5.root", "He1+_Config3_NoWaSH_0.5.root", "He2+_Config3_NoWaSH_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.5 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -6, -4.5, -3.8, 1.5);
  //Analyse("proton_Config3_NoWaSH_1.root", "He1+_Config3_NoWaSH_1.root", "He2+_Config3_NoWaSH_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -4.5, -3.8, 1.8);



  //####################################################################################
  //################################# CONFIG 1 W SC#####################################
  //####################################################################################
  //Analyse("proton_Config1_Sc_0.05.root", "He1+_Config1_Sc_0.05.root", "He2+_Config1_Sc_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -5, -5, -3.2, 1.);
  //Analyse("proton_Config1_Sc_0.1.root", "He1+_Config1_Sc_0.1.root", "He2+_Config1_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -5, -5, -3.2, 1.8);
  //Analyse("proton_Config1_Sc_0.25.root", "He1+_Config1_Sc_0.25.root", "He2+_Config1_Sc_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -5, -5, -3.2, 1.3);
  //Analyse("proton_Config1_Sc_0.5.root", "He1+_Config1_Sc_0.5.root", "He2+_Config1_Sc_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.5 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -5, -5, -3.2, 1.5);
  //Analyse("proton_Config1_Sc_1.root", "He1+_Config1_Sc_1.root", "He2+_Config1_Sc_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -5, -5, -3.2, 1.5);
  //Analyse("proton_Config1_ZnS_0.05.root", "He1+_Config1_ZnS_0.05.root", "He2+_Config1_ZnS_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.05, true, -5, -5, -3.2, 1.1);
  //Analyse("proton_Config1_ZnS_0.1.root", "He1+_Config1_ZnS_0.1.root", "He2+_Config1_ZnS_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.1, true, -5, -5, -3.2, 1.3);
  //Analyse("proton_Config1_ZnS_0.25.root", "He1+_Config1_ZnS_0.25.root", "He2+_Config1_ZnS_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.25, true, -5, -5, -3.2, 1.3);
  //Analyse("proton_Config1_ZnS_0.5.root", "He1+_Config1_ZnS_0.5.root", "He2+_Config1_ZnS_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.5, true, -6, -5, -3.2, 1.4);
  //Analyse("proton_Config1_ZnS_1.root", "He1+_Config1_ZnS_1.root", "He2+_Config1_ZnS_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 1, true, -5, -5, -3.2, 1.6);
  //Analyse("proton_Config1_NoWaSH_0.05.root", "He1+_Config1_NoWaSH_0.05.root", "He2+_Config1_NoWaSH_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.05 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -6, -4.5, -3.8, 1.1);
  //Analyse("proton_Config1_NoWaSH_0.1.root", "He1+_Config1_NoWaSH_0.1.root", "He2+_Config1_NoWaSH_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -6, -4.5, -3.8, 1.1);
  //Analyse("proton_Config1_NoWaSH_0.25.root", "He1+_Config1_NoWaSH_0.25.root", "He2+_Config1_NoWaSH_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.25 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -6, -4.5, -3.8, 1.4);
  //Analyse("proton_Config1_NoWaSH_0.5.root", "He1+_Config1_NoWaSH_0.5.root", "He2+_Config1_NoWaSH_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.5 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -6, -4.5, -3.8, 1.4);
  //Analyse("proton_Config1_NoWaSH_1.root", "He1+_Config1_NoWaSH_1.root", "He2+_Config1_NoWaSH_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -4.5, -3.8, 1.4);



  //####################################################################################
  //################################# CONFIG 2 W SC#####################################
  //####################################################################################
  //Analyse("Config2/proton_Config2_Sc_0.05.root", "Config2/He1+_Config2_Sc_0.05.root", "Config2/He2+_Config2_Sc_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -5.5, -5, -4.3, 1.4);
  //Analyse("proton_Config2_Sc_0.1.root", "He1+_Config2_Sc_0.1.root", "He2+_Config2_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -5, -5, -3.2, 1.8);
  //Analyse("proton_Config2_Sc_0.25.root", "He1+_Config2_Sc_0.25.root", "He2+_Config2_Sc_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -7, -5, -3.2, 1.5);
  //Analyse("proton_Config2_Sc_0.5.root", "He1+_Config2_Sc_0.5.root", "He2+_Config2_Sc_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 0.5 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -7, -5, -3.2, 1.5);
  //Analyse("proton_Config2_Sc_1.root", "He1+_Config2_Sc_1.root", "He2+_Config2_Sc_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - Sc 1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -7, -5, -3.2, 1.2);
  //Analyse("proton_Config2_ZnS_0.05.root", "He1+_Config2_ZnS_0.05.root", "He2+_Config2_ZnS_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.05 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.05, true, -5.5, -5, -3.2, 1.5);
  //Analyse("proton_Config2_ZnS_0.1.root", "He1+_Config2_ZnS_0.1.root", "He2+_Config2_ZnS_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.1, true, -7, -5, -3.2, 1.5);
  //Analyse("proton_Config2_ZnS_0.25.root", "He1+_Config2_ZnS_0.25.root", "He2+_Config2_ZnS_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.25 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.25, true, -7, -5, -3.8, 1.8);
  //Analyse("proton_Config2_ZnS_0.5.root", "He1+_Config2_ZnS_0.5.root", "He2+_Config2_ZnS_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 0.5, true, -5, -5, -3.2, 1.5);
  //Analyse("proton_Config2_ZnS_1.root", "He1+_Config2_ZnS_1.root", "He2+_Config2_ZnS_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 1 mm ", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0., 1, true, -6, -5, -4.2, 1.3);
  //Analyse("proton_Config2_NoWaSH_0.05.root", "He1+_Config2_NoWaSH_0.05.root", "He2+_Config2_NoWaSH_0.05.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.05 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.05, 0., true, -6, -4.5, -3.8, 1.5);
  //Analyse("proton_Config2_NoWaSH_0.1.root", "He1+_Config2_NoWaSH_0.1.root", "He2+_Config2_NoWaSH_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.1, 0., true, -6, -4.5, -3.8, 1.);
  //Analyse("proton_Config2_NoWaSH_0.25.root", "He1+_Config2_NoWaSH_0.25.root", "He2+_Config2_NoWaSH_0.25.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.25 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.25, 0., true, -6, -4.5, -3.8, 1.4);
  //Analyse("proton_Config2_NoWaSH_0.5.root", "He1+_Config2_NoWaSH_0.5.root", "He2+_Config2_NoWaSH_0.5.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 0.5 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 0.5, 0., true, -6, -4.5, -3.8, 1.4);
  //Analyse("proton_Config2_NoWaSH_1.root", "He1+_Config2_NoWaSH_1.root", "He2+_Config2_NoWaSH_1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - NoWaSH 1 mm", 0.1, 0.3, 2e6, 50, 5, 225, 120, 100, 1, 0., true, -6, -4.5, -3.8, 1.4);



  //Analyse("proton_Config3_ZnS_0.5_Sc_0.1.root", "He1+_Config3_ZnS_0.5_Sc_0.1.root", "He2+_Config3_ZnS_0.5_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm & EJ-212 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 280, 35, 100, 0.1, 0.5, true, -7, -5, -3.2, 1.7);
  //Analyse("proton_Config4_ZnS_0.5_Sc_0.1.root", "He1+_Config4_ZnS_0.5_Sc_0.1.root", "He2+_Config4_ZnS_0.5_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm & EJ-212 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 280, 35, 100, 0.1, 0.5, true, -5, -5, -3.2, 1.7);
  //Analyse("proton_Config1_ZnS_0.5_Sc_0.1.root", "He1+_Config1_ZnS_0.5_Sc_0.1.root", "He2+_Config1_ZnS_0.5_Sc_0.1.root", "Optical", "pinhole 100 um - B 0.3T - E 2000 kV/m - Le1 225 mm Le2 120 mm - ZnS 0.5 mm & EJ-212 0.1 mm ", 0.1, 0.3, 2e6, 50, 5, 280, 35, 100, 0.1, 0.5, true, -5, -5, -3.2, 1.4);


  //Analyse("proton_Config2_High_Stat.root", "He1+_Config2_High_Stat.root", "He2+_Config2_High_Stat.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_maxtheta_0.3mrad.root", "He1+_Config2_High_Stat_maxtheta_0.3mrad.root", "He2+_Config2_High_Stat_maxtheta_0.3mrad.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm maxtheta 0.3mrad", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_Pinhole_thick_12mm.root", "He1+_Config2_High_Stat_Pinhole_thick_12mm.root", "He2+_Config2_High_Stat_Pinhole_thick_12mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm Pinhole thickness 12 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_dist_bet_plate_Elec_36mm.root", "He1+_Config2_High_Stat_dist_bet_plate_Elec_36mm.root", "He2+_Config2_High_Stat_dist_bet_plate_Elec_36mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm dist between plates elec 36mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_dist_bet_plate_Elec_25mm.root", "He1+_Config2_High_Stat_dist_bet_plate_Elec_25mm.root", "He2+_Config2_High_Stat_dist_bet_plate_Elec_25mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm dist between plates elec 25mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_dist_bet_plate_Elec_50mm.root", "He1+_Config2_High_Stat_dist_bet_plate_Elec_50mm.root", "He2+_Config2_High_Stat_dist_bet_plate_Elec_50mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm dist between plates elec 50mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_dist_detecteur_plaques_200mm.root", "He1+_Config2_High_Stat_dist_detecteur_plaques_200mm.root", "He2+_Config2_High_Stat_dist_detecteur_plaques_200mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 200 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 200, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_dist_detecteur_plaques_0mm.root", "He1+_Config2_High_Stat_dist_detecteur_plaques_0mm.root", "He2+_Config2_High_Stat_dist_detecteur_plaques_0mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 0 mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 0, 100, 0., 0., false, -5, -5, -3.2, 1.4);
  //Analyse("proton_Config2_High_Stat_thick_elec_plate_10mm.root", "He1+_Config2_High_Stat_thick_elec_plate_10mm.root", "He2+_Config2_High_Stat_thick_elec_plate_10mm.root", "TP", "pinhole 100 um - B 0.3T - E 1500 kV/m - Le1 300 mm Le2 105 mm thickness elec plate 10mm", 0.1, 0.3, 1.5e6, 50, 5, 300, 105, 100, 0., 0., false, -5, -5, -3.2, 1.4);


  //void Analyse(const char* file_proton, const char* file_He1, const char* file_He2, const char* TreeName, const char* CanvasName, float pinhole, float B, float E, float Lb1, float D, float Le1, float Le2, float Sc_length, float Sc_thickness, float ZnS_thickness, bool Optique, float xmin_proton, float xmin_He1, float xmax_proton, float sigma)





  //Analyse("proton_test.root", "He1+_test.root", "He2+_test.root", "Optical", "PAUL test", 0.1, 0.6, 670e3, 50.8, 8.45, 40, 108.85, 120, 1, 0., true, 0, 0, 15, 0.001);

  //string file_proton = "test.root";
  //string file_proton = "Timing_proton_EJ214_0.025mm_ORCA_Exp.root";
  string file_proton = "test.root";
  //string file_proton = "He1+_0.1mm.root";


  //######################################################
  //DEBUT CREATION FICHIERS
  //######################################################
  /*
  cout << "Début création fichiers" << endl;
  
  TFile* file1 = new TFile(file_proton.c_str());
  TTree* Tree1 = (TTree*)file1->Get("Optical");
  TTree* Tree2 = (TTree*)file1->Get("TP");
  TH2F* h_proton = Histo_Parabole_Optique(Tree1, file_proton.c_str());
  Create_ROOT_Histo_Parabole_Optique(Tree1, "He1+_EJ262_1mm_CMOS_Exp_30MeV_Optique_2D.root");
  //Create_ROOT_Histo_Parabole(Tree2, "He2+_2D.root");
  //TH2F* h_proton = Histo_Parabole(Tree1, file_proton.c_str());

  cout << "Fin Histo 2D position" << endl;

  TH2F* test = Plot_E_Position_Optique(Tree1, "DetectorPositionX");
  Create_ROOT_Plot_E_Position_Optique(Tree1, "DetectorPositionX", "He1+_EJ262_1mm_CMOS_Exp_30MeV_Optique_Energie.root");
  //Create_ROOT_Plot_E_Position(Tree2, "PositionX", "proton_Energie.root");
  //TH2F* test = Plot_E_Position(Tree1, "PositionX");

  cout << "Fin Histo E vs Position" << endl;

  Create_ROOT_E_start(Tree2, "He1+_EJ262_1mm_CMOS_Exp_30MeV_Optique_Estart.root");

  //Create_ROOT_Timing_Optique(Tree1, "proton_EJ214_0.025mm_ORCA_Exp_30MeV_Optique_TIME.root");

  cout << "Fin Création fichiers" << endl;
  */

  
  //######################################################
  //FIN CREATION FICHIERS
  //######################################################


   
  
  //######################################################
  //DEBUT LECTURE FICHIERS
  //######################################################
 
  
  TFile* file1 = new TFile("Etudes_Scintillateurs/ROOT_files/proton_EJ212_0.1mm_CMOS_Exp_30MeV_Optique_2D.root");
  //TFile* file1 = new TFile("proton_EJ444_0.081mm_0.025mm_CMOS_Exp_30MeV_Optique_2D.root");
  TH2F* h_proton=(TH2F*)file1->Get("2D");

  TFile* file2 = new TFile("Etudes_Scintillateurs/ROOT_files/proton_EJ212_0.1mm_CMOS_Exp_30MeV_Optique_Energie.root");
  //TFile* file2 = new TFile("proton_EJ444_0.081mm_0.025mm_CMOS_Exp_30MeV_Optique_Energie.root");
  TH2F* test=(TH2F*)file2->Get("E_vs_Position");


  TFile* file3 = new TFile("Etudes_Scintillateurs/ROOT_files/proton_EJ212_0.1mm_CMOS_Exp_30MeV_Optique_Estart.root");
  //TFile* file3 = new TFile("proton_EJ444_0.081mm_0.025mm_CMOS_Exp_30MeV_Optique_Estart.root");
  TH1F* Estart=(TH1F*)file3->Get("E_start");


  string filename_resolution = "Graph_Resolution_proton_EJ212_0.1mm_CMOS_Exp_30MeV_Optique.root";
  string filename_Nph = "Graph_Nph_proton_EJ212_0.1mm_CMOS_Exp_30MeV_Optique.root";

  //######################################################
  //FIN LECTURE FICHIERS
  //######################################################
  
  
  
  h_proton->Draw("colz");
  
  float NEvents=0;
  float a = 0;
  float b = 0;
  float c = 0;
  
  
  // new TCanvas;
  // TH1D *Output = new TH1D("Output", "Output", NbinsY, -1, PosY);
  // h_proton->ProjectionY("Output", 994, 994, "");
  // Output->Draw();
  // double par[3000];
  // TF1*fit1a = new TF1("fit1a", "gaus", -1, PosY);
  // Output->Fit(fit1a, "R");
  // TF1*fit1bb = new TF1("fit1bb", "gaus", fit1a->GetParameter(1)-2*fit1a->GetParameter(2), fit1a->GetParameter(1)+2*fit1a->GetParameter(2));
  // Output->Fit(fit1bb, "R");

  // a = fit1bb->GetParameter(0);
  // b = fit1bb->GetParameter(1);
  // c = fit1bb->GetParameter(2);

  // cout << " a = " << a << endl;
  // TF1 *fit2b = new TF1("fit2", "gaus(0)+gaus(3)", fit1a->GetParameter(1)-3*fit1a->GetParameter(2), fit1a->GetParameter(1)+3*fit1a->GetParameter(2));
  // fit2b->SetParameter(0, a);
  // fit2b->SetParameter(1, b);
  // fit2b->SetParameter(2, c);
  // fit2b->SetParameter(3, 0.1*a);
  // fit2b->SetParLimits(3, 0.1*a, 100*a);
  // fit2b->SetParameter(4, b);
  // fit2b->SetParLimits(4, 0, 5);
  // fit2b->SetParameter(5, 3*c);
  // fit2b->SetParLimits(5, 0.01, 10);
  // Output->Fit(fit2b, "R");
  // cout << "Eval1 = " << fit1bb->Eval(fit1a->GetParameter(1)) << endl;
  // cout << "Eval2 = " << fit1bb->Eval(fit1a->GetParameter(1) + 1*fit1bb->GetParameter(2)) << endl;
  


  //new TCanvas;
  // TH1D *proj2 = new TH1D("proj2", "proj2", 1000, 0, 100);
  // test->ProjectionY("proj2", 950, 950, "");
  //TF1* fit_gaus_Energie = new TF1("fit_gaus_Energie", "gaus", 0, 100);
  // proj2->Fit(fit_gaus_Energie, "");

  float x[NbinsX], ex[NbinsX], y[NbinsX], ey[NbinsX];
  float x_new[150], y_new[150], ex_new[150], ey_new[150];
  float xE[NbinsX], exE[NbinsX], yE[NbinsX], eyE[NbinsX];
  float xNph[NbinsX], exNph[NbinsX], yNph[NbinsX], eyNph[NbinsX];
  int n=0;
  int nbis=0;
  TH1D *proj2 = new TH1D("proj2", "proj2", 1000, 0, 100);
  TH1D *proj3 = new TH1D("proj3", "proj3", NbinsX, 0, PosX);
  TF1* fit_gaus_Energie = new TF1("fit_gaus_Energie", "gaus", 0, 100);

  TH1D *Output_resolution = new TH1D("Output_resolution", "Output_resolution", NbinsY, -1, PosY);
  TF1*fit1 = new TF1("fit1", "gaus", -1, PosY);
  TF1*fitX = new TF1("fitX", "gaus", 0, 25);
  TF1*fit1b;
  TF1*fit2;
  TF1*fit4b;
  TF1*fit4;
  float mean, sigma, Chi2, Ndf, Chi2Ndf, Eval1, Eval2, MeanEval, Eval_Energy;

  
  
   for (int i=150; i<1000; i++)
     {
  //     h_proton->ProjectionY("Output_resolution", i, i, "");
  //     Output_resolution->Fit(fit1, "QR");
  //     fit1b = new TF1("fit1b", "gaus", fit1->GetParameter(1)-2*fit1->GetParameter(2), fit1->GetParameter(1)+2*fit1->GetParameter(2));
  //     Output_resolution->Fit(fit1b, "QR");
  //     a = fit1b->GetParameter(0);
  //     b = fit1b->GetParameter(1);
  //     c = fit1b->GetParameter(2);
  //     fit2 = new TF1("fit2", "gaus(0)+gaus(3)", fit1->GetParameter(1)-3*fit1->GetParameter(2), fit1->GetParameter(1)+3*fit1->GetParameter(2));
  //     fit2->SetParameter(0, a);
  //     fit2->SetParameter(1, b);
  //     fit2->SetParameter(2, c);
  //     fit2->SetParameter(3, 0.1*a);
  //     fit2->SetParLimits(3, 0.1*a, 100*a);
  //     fit2->SetParameter(4, b);
  //     fit2->SetParLimits(4, 0, 5);
  //     fit2->SetParameter(5, 3*c);
  //     fit2->SetParLimits(5, 0.01, 10);
  //     Output_resolution->Fit(fit2, "QR");
  //     Eval1 = fit2->Eval(fit2->GetParameter(1));
  //     Eval2 = fit2->Eval(fit2->GetParameter(1) + 1*fit2->GetParameter(2));
  //     //Eval1 = fit2->Eval(fit1b->GetParameter(1));
  //     //Eval2 = fit2->Eval(fit1b->GetParameter(1) + 1*fit1b->GetParameter(2));
  //     //MeanEval = (Eval1+Eval2)/2;
  //     MeanEval = Eval2;
  //     //cout << "i = " << i << endl;
  //     //cout << "Eval = " << MeanEval << endl;
  //     //if(MeanEval >3000)cout << "!!!!" << i << endl;


  //     //cout << "mean = " << fit2->GetParameter(4) << endl;
  //     //cout << "sigma = " << fit2->GetParameter(5) << endl;
      
      
       test->ProjectionY("proj2", i, i, "");
       test->ProjectionX("proj3", i, i, "");
       proj2->Fit(fit_gaus_Energie, "QN");
       mean = fit_gaus_Energie->GetParameter(1);
       sigma = fit_gaus_Energie->GetParameter(2);
       Chi2 = fit_gaus_Energie->GetChisquare();
       Ndf = fit_gaus_Energie->GetNDF();
       Chi2Ndf = Chi2/Ndf;
      
      
       if(Chi2Ndf >0.5 && Chi2Ndf <800 && mean >0 && mean <120 && sigma/mean <1)
   	{
	  // 	  x[n] = proj3->GetBinCenter(i);
	  	  //cout << "x = " << x[n] << endl;
	  // 	  //cout << "Chi2/NdF = " << Chi2Ndf << endl;
  // 	  ex[n]=proj3->GetBinCenter(i+1) - proj3->GetBinCenter(i);
   	  y[n] = fit_gaus_Energie->GetParameter(1);
   	  ey[n] = fit_gaus_Energie->GetParameter(2);
   	  //if(ey[n] <0.1)ey[n]=0.1;
	  
   	  xE[n] = y[n];
   	  exE[n] = fit_gaus_Energie->GetParError(1);
   	  if(exE[n] >100)exE[n]=0;
   	  yE[n] = ey[n]/y[n];
	  //if(yE[n] >0.1)yE[n]=-0.1;
   	  eyE[n] = fit_gaus_Energie->GetParError(2)/ey[n] + fit_gaus_Energie->GetParError(1)/y[n];
   	  if(eyE[n] >0.02)eyE[n]=0;

  // 	  xNph[n] = y[n];
  // 	  exNph[n] = ey[n];
  // 	  NEvents = Estart->Integral((int)1000*(y[n]-ey[n]), (int)1000*(y[n]+ey[n]));

  // 	  // cout << "\ni = " << i << endl;
  // 	  // cout << "n = " << n << endl;
  // 	  // cout << "y = " << y[n] << endl;
  // 	  // cout << "ey = " << ey[n] << endl;
  // 	  // cout << "Eval 1= " << Eval1 << endl;
  // 	  // cout << "Eval 2= " << Eval2 << endl;
  // 	  // cout << "MeanEval = " << MeanEval << endl;
  // 	  // cout << "NEvents = " << NEvents << endl;
	  
  // 	  yNph[n] = MeanEval/(NEvents);
  // 	  if(NEvents==0) yNph[n]=0;
  // 	  //cout << "Nph = " << yNph[n] << endl;
  // 	  //	  eyNph[n] = (Eval1-MeanEval)/(NEvents);
	  
   	  n++;
  // 	  //cout << "n = " << n << endl;
   	}
     }

   // TGraphErrors* g = new TGraphErrors(n, x, y, ex, ey);
   // g->Draw();
   
   new TCanvas;
   TGraphErrors* gg = new TGraphErrors(n, xE, yE, exE, eyE);
   gg->Draw("APE2");
   gg->SetFillColor(kRed);
   gg->SetFillStyle(3002);
   gg->SetLineColor(kRed);
   gg->SetMarkerColor(kRed);
   gg->SetLineWidth(2);

  TFile file_out_resolution(filename_resolution.c_str(), "RECREATE");
  gg->Write();
  file_out_resolution.Close();


  // new TCanvas;
  // TGraphErrors* ggg = new TGraphErrors(n, xNph, yNph, exNph, eyNph);
  // ggg->Draw("APE2");
  // ggg->SetFillColor(kRed);
  // ggg->SetMarkerColor(kRed);
  // ggg->SetFillStyle(3001);
  // ggg->SetLineColor(kRed);
  // ggg->SetLineWidth(3);

  // TFile file_out_Nph(filename_Nph.c_str(), "RECREATE");
  // ggg->Write();
  // file_out_Nph.Close();

  
  test->RebinY(10);
  Estart->Rebin(1000);
  cout << "Bin 1 Estart = " << Estart->GetBinContent(1) << endl;

  new TCanvas;
  Estart->Draw();

  new TCanvas;
  test->Draw("colz");

  new TCanvas;
  TH1D *OutputE = new TH1D("OutputE", "OutputE", 150, 0, 150);
  test->ProjectionX("OutputE", 50, 50, "");
  OutputE->Draw();
  TF1*fit3a = new TF1("fit3a", "gaus", 0, 25);
  OutputE->Fit(fit3a, "R");
  TF1*fit3bb = new TF1("fit3bb", "gaus", fit3a->GetParameter(1)-2*fit3a->GetParameter(2), fit3a->GetParameter(1)+2*fit3a->GetParameter(2));
  OutputE->Fit(fit3bb, "R");
  a = fit3bb->GetParameter(0);
  b = fit3bb->GetParameter(1);
  c = fit3bb->GetParameter(2);
  TF1 *fit3b = new TF1("fit2", "gaus(0)+gaus(3)", fit3a->GetParameter(1)-5*fit3a->GetParameter(2), fit3a->GetParameter(1)+5*fit3a->GetParameter(2));
  fit3b->SetParameter(0, a);
  fit3b->SetParameter(1, b);
  fit3b->SetParameter(2, c);
  fit3b->SetParameter(3, 0.1*a);
  fit3b->SetParLimits(3, 0.01*a, 100*a);
  fit3b->SetParameter(4, b);
  fit3b->SetParLimits(4, 0, 50);
  fit3b->SetParameter(5, 5*c);
  fit3b->SetParLimits(5, 0.01, 10);
  OutputE->Fit(fit3b, "R");


  cout << "Eval = " << fit3b->Eval(fit3b->GetParameter(1) + fit3b->GetParameter(2)) << endl;
  cout << "Eval = " << fit3b->Eval(fit3b->GetParameter(1) - fit3b->GetParameter(2)) << endl;
  cout << "Eval = " << (fit3b->Eval(fit3b->GetParameter(1) + fit3b->GetParameter(2)) + (fit3b->Eval(fit3b->GetParameter(1) - fit3b->GetParameter(2))))/2 << endl;

  TH1D *Output_energy = new TH1D("Output_energy", "Output_energy", 150, 0, 150);
  
  for (int i=3; i<120; i++)
    {
      test->ProjectionX("Output_energy", i, i, "");
      Output_energy->Fit(fitX, "QR");
      fit4b = new TF1("fit4b", "gaus", fitX->GetParameter(1)-2*fitX->GetParameter(2), fitX->GetParameter(1)+2*fitX->GetParameter(2));
      Output_energy->Fit(fit4b, "QR");
      a = fit4b->GetParameter(0);
      b = fit4b->GetParameter(1);
      c = fit4b->GetParameter(2);
      fit4 = new TF1("fit4", "gaus(0)+gaus(3)", fitX->GetParameter(1)-5*fitX->GetParameter(2), fitX->GetParameter(1)+5*fitX->GetParameter(2));
      fit4->SetParameter(0, a);
      fit4->SetParameter(1, b);
      fit4->SetParameter(2, c);
      fit4->SetParameter(3, 0.1*a);
      fit4->SetParLimits(3, 0.1*a, 100*a);
      fit4->SetParameter(4, b);
      fit4->SetParLimits(4, 0, 50);
      fit4->SetParameter(5, 5*c);
      fit4->SetParLimits(5, 0.01, 10);
      Output_energy->Fit(fit4, "QR");
      Eval_Energy = (fit4->Eval(fit4->GetParameter(1) + 1*fit4->GetParameter(2)));
      NEvents = Estart->Integral(i, i);
      x_new[nbis] = i-0.5;
      ex_new[nbis] = 0.5;
      y_new[nbis] = Eval_Energy/NEvents;
      ey_new[nbis] = y_new[nbis] * ((sqrt(Eval_Energy)/Eval_Energy) + (sqrt(NEvents)/NEvents));
      Chi2 = fit4->GetChisquare();
      Ndf = fit4->GetNDF();
      Chi2Ndf = Chi2/Ndf;
      cout << "\ni = " << i << endl;
      cout << "Eval = " << Eval_Energy << endl;
      cout << "Nevents = " << NEvents << endl;
      cout << "Nph = " << Eval_Energy/NEvents << endl;
      cout << "Chi2/NdF = " << Chi2Ndf << endl;
      nbis++;
       
    }

  
  new TCanvas;
  TGraphErrors* Nph = new TGraphErrors(nbis, x_new, y_new, ex_new, ey_new);
  Nph->Draw("APE2");           
  Nph->SetFillColor(kRed);
  Nph->SetMarkerColor(kRed);
  Nph->SetFillStyle(3001);
  Nph->SetLineColor(kRed);
  Nph->SetLineWidth(3);

  TFile file_out_Nph(filename_Nph.c_str(), "RECREATE");
  Nph->Write();
  file_out_Nph.Close();
  
  



  /*
  //DEBUG

   int npeaks =2;
   int bin_start = (-15+40.1)*10;
   int bin_end = (-9+40.1)*10;
   double par[3000];
   int p;
   int n=0;
   int nfound=0;
   double xp;
   int bin;
   double yp;
   TH1D *Output_resolution = new TH1D("Output_resolution", "Output_resolution", 610, -1, 60);
   int number_of_peaks = npeaks;

   TFile* file1 = new TFile("proton_pinhole_100um_B_0.6T_E_2000kV_Le1_300_Optique.root");
   TTree *Tree1 = (TTree*)file1->Get("Optical");
   TFile* file2 = new TFile("He1+_pinhole_100um_B_0.6T_E_2000kV_Le1_300_Optique.root");
   TTree *Tree2 = (TTree*)file2->Get("Optical");
   TFile* file3 = new TFile("He2+_pinhole_100um_B_0.6T_E_2000kV_Le1_300_Optique.root");
   TTree *Tree3 = (TTree*)file3->Get("Optical");

   TH2F* h_proton;
   TH2F* h_ALL;
   TH2F* h_proton_He1;
   TH2F* h_proton_He2;
   TH2F* h_He1;
   TH2F* h_He2;

   h_proton = Histo_Parabole_Optique(Tree1, "proton");
   h_ALL = Histo_Parabole_Optique(Tree1, "ALL");
   h_proton_He1 = Histo_Parabole_Optique(Tree1, "proton_He1");
   h_proton_He2 = Histo_Parabole_Optique(Tree1, "proton_He2");
   h_He1 = Histo_Parabole_Optique(Tree2, "He1");
   h_He2 = Histo_Parabole_Optique(Tree3, "He2");



   h_proton_He2->Add(h_He2, 1);
   h_proton_He2->Draw("colz");

   TCanvas* c1 = new TCanvas();
   c1->cd();

   TH1D *proj = new TH1D("proj", "proj", 610, -1, 60);
   TH1D *proj_clean = new TH1D("proj_clean", "proj_clean", 610, -1, 60);
   TH1D *bg = new TH1D("bg", "bg", 610, -1, 60);

   //for (int i=bin_start; i<bin_end; i++)
   //{
   //cout << "i = " << i << endl;
       TH2F *h_proton_He2_bis = (TH2F*)h_proton_He2->Clone();
       h_proton_He2_bis->ProjectionY("proj", 302, 302, "");
       //h_proton->Draw();
       proj->Draw();
       TSpectrum *s = new TSpectrum(2);
       // Estimate background using TSpectrum::Background
       TH1 *hb = s->Background(proj,20,"same");
       if (hb) c1->Update();

       // for (int j=0; j<proj->GetNbinsX(); j++)
       // 	 {
       // 	   proj_clean->SetBinContent(j, proj->GetBinContent(j)-hb->GetBinContent(j));
       // 	 }


       nfound = s->Search(proj, 2,"",0.2);
       printf("Found %d candidate peaks to fit\n",nfound);


       //estimate linear background using a fitting method
       TF1 *fline = new TF1("fline","pol1",-1,60);
       proj->Fit("fline","same");
       // Loop on all found peaks. Eliminate peaks at the background level
       par[0] = fline->GetParameter(0);
       par[1] = fline->GetParameter(1);
       npeaks = 0;
       Double_t *xpeaks;
       xpeaks = s->GetPositionX();
       for (p=0;p<nfound;p++) {
   	xp = xpeaks[p];
   	bin = proj->GetXaxis()->FindBin(xp);
   	yp = proj->GetBinContent(bin);
   	if (yp-TMath::Sqrt(yp) < fline->Eval(xp)) continue;
   	par[3*npeaks+2] = yp; // "height"
   	par[3*npeaks+3] = xp; // "mean"
   	par[3*npeaks+4] = 0.1; // "sigma"
   	npeaks++;
       }

       TF1*test_fit1 = new TF1("fit1", "gaus", par[3]-0.6, par[3]+0.4);
       test_fit1->SetParameter(1, par[3]);
       TF1*test_fit2 = new TF1("fit2", "gaus", par[6]-0.4, par[6]+0.5);
       test_fit2->SetParameter(1, par[6]);
       TF1*test_fit3 = new TF1("fit3", "gaus(0)+gaus(3)+gaus(6)", -1, par[6]+10);
       TH1F *h2 = (TH1F*)proj->Clone("h2");
       h2->Draw();
       h2->Fit(test_fit1, "R");
       h2->Fit(test_fit2, "R");
       test_fit3->SetParameter(1, test_fit1->GetParameter(1));
       test_fit3->SetParameter(2, test_fit1->GetParameter(2));
       test_fit3->SetParLimits(2, 0.1, 0.5);
       test_fit3->SetParameter(4, test_fit2->GetParameter(1));
       test_fit3->SetParameter(5, test_fit2->GetParameter(2));
       test_fit3->SetParLimits(5, 0.1, 1);
       test_fit3->SetParameter(7, (test_fit2->GetParameter(1)+test_fit2->GetParameter(1))/2);
       test_fit3->SetParLimits(8, 1, 10);
       h2->Fit(test_fit3, "R+");
       cout << "Eval = " << test_fit1->Eval(par[3]-0.5);

       for (int i=0; i<h2->GetNbinsX(); i++)
	 {
	   bg->SetBinContent(i, h2->GetBinContent(i) - test_fit1->Eval(h2->GetBinCenter(i)) - test_fit2->Eval(h2->GetBinCenter(i)));
	 }

       bg->SetLineColor(kGreen);
       bg->Draw("same");

       printf("Found %d useful peaks to fit\n",npeaks);
       printf("Now fitting: Be patient\n");
       TF1 *fit = new TF1("fit",fpeaks,-1,60,2+3*npeaks);
       // We may have more than the default 25 parameters
       TVirtualFitter::Fitter(h2,10+3*npeaks);
       fit->SetParameters(par);
       fit->SetParLimits(2,10, 1000000);
       fit->SetParLimits(3,2, 3);
       fit->SetParLimits(4,0.1, 0.5);
       fit->SetParLimits(5,10, 1000000);
       fit->SetParLimits(6, 4.5, 5.5);
       fit->SetParLimits(7, 0.1, 0.5);
       fit->SetNpx(1000);
       fit->SetLineColor(kRed);
       //h2->Fit("fit", "");

       //proj_clean->Draw("same");
       //proj_clean->SetLineColor(kCyan);;
       //c1->Modified();
       //c1->Update();
       //getchar();

       //}


       */

      // c1->cd(2);
      // TH1F *h2 = (TH1F*)proj_clean->Clone("h2");
      // //h2->Draw();
      // printf("Found %d useful peaks to fit\n",npeaks);
      // printf("Now fitting: Be patient\n");
      // TF1 *fit = new TF1("fit",fpeaks,-1,60,2+3*npeaks);
      // // We may have more than the default 25 parameters
      // TVirtualFitter::Fitter(h2,10+3*npeaks);
      // fit->SetParameters(par);
      // fit->SetParLimits(2,10, 1000000);
      // fit->SetParLimits(3,0, 60);
      // fit->SetParLimits(4,0.1, 0.5);
      // fit->SetParLimits(5,10, 1000000);
      // fit->SetParLimits(6,0, 60);
      // fit->SetParLimits(7, 0.1, 0.5);
      // fit->SetNpx(1000);
      // fit->SetLineColor(kRed);
      // h2->Fit("fit", "");
      // //  proj_clean->Draw("same");
      // c1->Modified();
      // c1->Update();
      // getchar();

      // }





}
