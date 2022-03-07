#include "/home/local1/Simulations/TP_Simulation/Resultats/Plot.hh"
#include <iostream>
#include <fstream>


void Study_LaBr3_attenuation()
{
  float c,d =0;
  ifstream file_Cfg("../simulation_input_files/LaBr3_attenuation.cfg");
  std::vector<float> vWavelength;
  std::vector<float> vLabs;
  string filler;
  vWavelength.clear();
  vLabs.clear();
  for (int i =0; i<19; i++){
    file_Cfg >> c >> filler >> d;
    vWavelength.push_back(c);
    vLabs.push_back(d);
    cout << "Wavelength = " << vWavelength.at(i) << " & Labs = " << vLabs.at(i) << endl;
  }
  file_Cfg.close();

  TGraph *gCfg = new TGraph(vWavelength.size(), &vWavelength[0], &vLabs[0]);
  
  //  TCanvas* c1 = new TCanvas;
  //c1->cd();
  //gCfg->Draw();
  gCfg->SetLineColor(kCyan);



  int n=0;
  int start=340;
  int end =430;
  int step =1;
  int n_step= (end-start)/step;
  
    
  TGraphErrors* g = geLabs(start, end, step);
  
  TCanvas* c2 = new TCanvas;
  c2->cd();
  g->Draw("");
  gCfg->Draw("same");
  g->SetMarkerStyle(8);
  g->SetMarkerSize(0.7);
  g->SetMarkerColor(kRed);
  g->SetFillColor(kRed);
  g->SetLineColor(kRed);
  g->SetFillStyle(3002);
  
}
