#include "/home/local1/Simulations/TP_Simulation/Resultats/Plot.hh"
#include <iostream>
#include <fstream>

using namespace std;

void Plot_proton()
{
  float c=0;
  float d=0;
  
  ifstream file_Alu("Alu_proton.txt");
  float density_Alu = 2.70;
  std::vector<float> vEnergy_Alu;
  std::vector<float> vCSDA_Alu;
  vEnergy_Alu.clear();
  vCSDA_Alu.clear();
  for (int i =0; i<132; i++){
    file_Alu >> c >> d;
    vEnergy_Alu.push_back(c);
    vCSDA_Alu.push_back(d/density_Alu);
    cout << "Energy = " << vEnergy_Alu.at(i) << " & CSDA = " << vCSDA_Alu.at(i) << endl;
  }
  file_Alu.close();

  ifstream file_Sc("Scintillateur_proton.txt");
  float density_Sc = 1.032;
  std::vector<float> vEnergy_Sc;
  std::vector<float> vCSDA_Sc;
  vEnergy_Sc.clear();
  vCSDA_Sc.clear();
  for (int i =0; i<132; i++){
    file_Sc >> c >> d;
    vEnergy_Sc.push_back(c);
    vCSDA_Sc.push_back(d/density_Sc);
  }
  file_Sc.close();


  ifstream file_Cu("Cuivre_proton.txt");
  float density_Cu = 8.96;
  std::vector<float> vEnergy_Cu;
  std::vector<float> vCSDA_Cu;
  vEnergy_Cu.clear();
  vCSDA_Cu.clear();
  for (int i =0; i<132; i++){
    file_Cu >> c >> d;
    vEnergy_Cu.push_back(c);
    vCSDA_Cu.push_back(d/density_Cu);
  }
  file_Cu.close();


  // ifstream file_C("Carbon_electron.txt");
  // float density_C = 2.0;
  // std::vector<float> vEnergy_C;
  // std::vector<float> vCSDA_C;
  // vEnergy_C.clear();
  // vCSDA_C.clear();
  // for (int i =0; i<81; i++){
  //   file_C >> c >> d;
  //   vEnergy_C.push_back(c);
  //   vCSDA_C.push_back(d/density_C);
  // }
  // file_C.close();

  
  TGraph *gCSDA_Alu = new TGraph(vEnergy_Alu.size(), &vEnergy_Alu[0], &vCSDA_Alu[0]);
  TGraph *gCSDA_Sc = new TGraph(vEnergy_Sc.size(), &vEnergy_Sc[0], &vCSDA_Sc[0]);
  TGraph *gCSDA_Cu = new TGraph(vEnergy_Cu.size(), &vEnergy_Cu[0], &vCSDA_Cu[0]);
  //TGraph *gCSDA_C = new TGraph(vEnergy_C.size(), &vEnergy_C[0], &vCSDA_C[0]);

  TCanvas* c1 = new TCanvas;
  c1->SetLogy();
  c1->SetLogx();
  gCSDA_Alu->SetLineColor(kGray);
  gCSDA_Sc->SetLineColor(kCyan);
  gCSDA_Sc->SetMarkerColor(kCyan);
  gCSDA_Cu->SetLineColor(kOrange);
  //gCSDA_C->SetLineColor(kBlack);
  gCSDA_Sc->Draw("");
  gCSDA_Alu->Draw("same");
  gCSDA_Cu->Draw("same");
  //gCSDA_C->Draw("same");


  const int nfiles=14;
  const char* filenames_Sc[nfiles]=
    {
     "Scintillateur_proton_10keV.root",
     "Scintillateur_proton_100keV.root",
     "Scintillateur_proton_250keV.root",
     "Scintillateur_proton_500keV.root",
     "Scintillateur_proton_750keV.root",
     "Scintillateur_proton_1000keV.root",
     "Scintillateur_proton_1500keV.root",
     "Scintillateur_proton_2000keV.root",
     "Scintillateur_proton_3000keV.root",
     "Scintillateur_proton_4000keV.root",
     "Scintillateur_proton_5000keV.root",
     "Scintillateur_proton_10000keV.root",
     "Scintillateur_proton_50000keV.root",
     "Scintillateur_proton_500000keV.root"
    };

  const char* filenames_Alu[nfiles]=
    {
     "Alu_proton_10keV.root",
     "Alu_proton_100keV.root",
     "Alu_proton_250keV.root",
     "Alu_proton_500keV.root",
     "Alu_proton_750keV.root",
     "Alu_proton_1000keV.root",
     "Alu_proton_1500keV.root",
     "Alu_proton_2000keV.root",
     "Alu_proton_3000keV.root",
     "Alu_proton_4000keV.root",
     "Alu_proton_5000keV.root",
     "Alu_proton_10000keV.root",
     "Alu_proton_50000keV.root",
     "Alu_proton_500000keV.root"
    };


  const char* filenames_Cu[nfiles]=
    {
     "Cuivre_proton_10keV.root",
     "Cuivre_proton_100keV.root",
     "Cuivre_proton_250keV.root",
     "Cuivre_proton_500keV.root",
     "Cuivre_proton_750keV.root",
     "Cuivre_proton_1000keV.root",
     "Cuivre_proton_1500keV.root",
     "Cuivre_proton_2000keV.root",
     "Cuivre_proton_3000keV.root",
     "Cuivre_proton_4000keV.root",
     "Cuivre_proton_5000keV.root",
     "Cuivre_proton_10000keV.root",
     "Cuivre_proton_50000keV.root",
     "Cuivre_proton_500000keV.root"
    };
   

  // const char* filenames_C[nfiles]=
  // {
  //  "Carbon_10keV.root",
  //  "Carbon_100keV.root",
  //  "Carbon_250keV.root",
  //  "Carbon_500keV.root",
  //  "Carbon_750keV.root",
  //  "Carbon_1000keV.root",
  //  "Carbon_1500keV.root",
  //  "Carbon_2000keV.root",
  //  "Carbon_3000keV.root",
  //  "Carbon_4000keV.root",
  //  "Carbon_5000keV.root",
  //  "Carbon_10000keV.root",
  //  "Carbon_50000keV.root"
  // };

    
  //TGraphErrors* test = ge(filenames, "Tree_electron", "E_start", nfiles);
  TGraphErrors* f_Alu = ge(filenames_Alu, "Tree_electron", "E_start", "TotalLength", nfiles);
  TGraphErrors* f_Sc = ge(filenames_Sc, "Tree_electron", "E_start", "TotalLength", nfiles);
  TGraphErrors* f_Cu = ge(filenames_Cu, "Tree_electron", "E_start", "TotalLength", nfiles);
  //TGraphErrors* f_C = ge(filenames_C, "Tree_electron", "E_start", "TotalLength", nfiles);
    
  //new TCanvas;
  f_Alu->Draw("PE3Same");
  f_Alu->SetMarkerStyle(8);
  f_Alu->SetMarkerSize(0.7);
  f_Alu->SetMarkerColor(kGray);
  f_Alu->SetFillColor(kGray);
  f_Alu->SetFillStyle(3002);
  f_Sc->Draw("PE3Same");
  f_Sc->SetMarkerStyle(8);
  f_Sc->SetMarkerSize(0.7);
  f_Sc->SetMarkerColor(kCyan);
  f_Sc->SetFillColor(kCyan);
  f_Sc->SetFillStyle(3002);
  f_Cu->Draw("PE3Same");
  f_Cu->SetMarkerStyle(8);
  f_Cu->SetMarkerSize(0.7);
  f_Cu->SetMarkerColor(kOrange);
  f_Cu->SetFillColor(kOrange);
  f_Cu->SetFillStyle(3002);
  // f_C->Draw("PE3Same");
  // f_C->SetMarkerStyle(8);
  // f_C->SetMarkerColor(kBlack);
  // f_C->SetFillColor(kBlack);
  // f_C->SetFillStyle(3005);
  
  
}
