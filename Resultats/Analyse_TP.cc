#include "Analyse_TP.hh"


void Analyse_TP()
{
  gStyle->SetOptStat("");
gROOT->ProcessLine("#include <vector>");

  float mp = 1.6726e-27; //kg
  float mHe = 4.0026*1.66054e-27;
  float qp = 1.6e-19; //C

  string file_proton = "proton_pinhole.root";
  string file_He1 = "He1+_pinhole.root";
  string file_He2 = "He2+_pinhole.root";
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

  //Analyse("proton_pinhole_200um.root", "He1+_pinhole_200um.root", "He2+_pinhole_200um.root", "pinhole 200 um", 0.2, B, E, 150, 155, 5, 50, 310, 100, 1, 0.1, Optique_No);
  //Analyse("proton_pinhole_150um.root", "He1+_pinhole_150um.root", "He2+_pinhole_150um.root", "pinhole 150 um", 0.15, B, E, 150, 155, 5, 50, 310, 100, 1, 0.1, Optique_No);
  Analyse(file_proton.c_str(), file_He1.c_str(), file_He2.c_str(), "TP", "pinhole 100 um", pinhole, B, E, 150, 155, 5, 50, 310, 100, 1, 0.1, false);
  //Analyse("proton_pinhole_75um.root", "He1+_pinhole_75um.root", "He2+_pinhole_75um.root", "TP", "pinhole 75 um", 0.075, B, E, 150, 155, 5, 50, 310, 100, 1, 0.1, false);
  //Analyse("proton_pinhole_50um.root", "He1+_pinhole_50um.root", "He2+_pinhole_50um.root", "pinhole 50 um", 0.05, B, E, 150, 155, 5, 50, 310, 100, 1, 0.1, Optique_No);
  Analyse("proton_pinhole_100um_B_0.6T.root", "He1+_pinhole_100um_B_0.6T.root", "He2+_pinhole_100um_B_0.6T.root", "TP", "pinhole 100 um - B 0.6T", 0.1, 0.6, E, 150, 155, 5, 50, 310, 100, 1, 0.1, false);
  Analyse("proton_pinhole_100um_B_0.9T.root", "He1+_pinhole_100um_B_0.9T.root", "He2+_pinhole_100um_B_0.9T.root", "TP", "pinhole 100 um - B 0.9T", 0.1, 0.9, E, 150, 155, 5, 50, 310, 100, 1, 0.1, false);
  Analyse("proton_pinhole_100um_B_0.1T.root", "He1+_pinhole_100um_B_0.1T.root", "He2+_pinhole_100um_B_0.1T.root", "TP", "pinhole 100 um - B 0.1T", 0.1, 0.1, E, 150, 155, 5, 50, 310, 100, 1, 0.1, false);
  //Analyse("proton_ligne_Optique_div10_0.1_0.1.root", "He1+_ligne_Optique_div10_0.1_0.1.root", "He2+_ligne_Optique_div10_0.1_0.1.root", "Optical", "Optical ligne", 0, B, E, 150, 155, 5, 50, 310, 100, 0.1, 0.1, true);
  //Analyse("proton_ligne_Optique_div10_0.1_1.root", "He1+_ligne_Optique_div10_0.1_1.root", "He2+_ligne_Optique_div10_0.1_1.root", "Optical", "Optical ligne", 0, B, E, 150, 155, 5, 50, 310, 100, 0.1, 0.1, true);
  //Analyse("proton_pinhole_Optique_div10_0.1_1.root", "He1+_pinhole_Optique_div10_0.1_1.root", "He2+_pinhole_Optique_div10_0.1_1.root", "Optical", "Optical ligne", 0, B, E, 150, 155, 5, 50, 310, 100, 0.1, 0.1, true);
  
  

  // float param_proton = Param_Parabole(mp, qp, Le1, Le2, E, Lb1, Lb2, B);
  // TF1 *proton_calcul = new TF1("proton_calcul","[0]*x*x", -50, 0);
  // proton_calcul->SetParameter(0, param_proton);

  // float param_He1 = Param_Parabole(mHe, qp, Le1, Le2, E, Lb1, Lb2, B);
  // TF1 *He1_calcul = new TF1("He1_calcul","[0]*x*x", -50, 0);
  // He1_calcul->SetParameter(0, param_He1);

  // float param_He2 = Param_Parabole(mHe, 2*qp, Le1, Le2, E, Lb1, Lb2, B);
  // TF1 *He2_calcul = new TF1("He2_calcul","[0]*x*x", -50, 0);
  // He2_calcul->SetParameter(0, param_He2);

  // TGraph* g_proton_ligne = Graph_Parabole("proton_pinhole.root", "TP");
  // TGraph* g_He1_ligne = Graph_Parabole("He1+_pinhole.root", "TP");
  // TGraph* g_He2_ligne = Graph_Parabole("He2+_pinhole.root", "TP");

  // TAxis* xaxis = g_proton_ligne->GetXaxis();
  // TAxis* yaxis = g_proton_ligne->GetYaxis();

  // TCanvas* c1 = new TCanvas();
  // c1->cd();
  // g_proton_ligne->Draw("AP");
  // yaxis->SetLimits(0., 70.);
  // g_proton_ligne->SetMarkerStyle(4);
  // g_proton_ligne->SetMarkerSize(0.4);
  // g_proton_ligne->SetMarkerColor(kRed);
  // proton_calcul->Draw("same");
  // proton_calcul->SetLineStyle(1);
  // proton_calcul->SetLineColor(kOrange);
  
  // g_He1_ligne->Draw("Psame");
  // g_He1_ligne->SetMarkerStyle(4);
  // g_He1_ligne->SetMarkerSize(0.4);
  // g_He1_ligne->SetMarkerColor(kBlue);
  // He1_calcul->Draw("same");
  // He1_calcul->SetLineStyle(1);
  // He1_calcul->SetLineColor(kCyan);

  // g_He2_ligne->Draw("Psame");
  // g_He2_ligne->SetMarkerStyle(4);
  // g_He2_ligne->SetMarkerSize(0.4);
  // g_He2_ligne->SetMarkerColor(kGreen+3);
  // He2_calcul->Draw("same");
  // He2_calcul->SetLineStyle(1);
  // He2_calcul->SetLineColor(kGreen);

  // auto legend = new TLegend(0.1,0.7,0.48,0.9);
  // legend->AddEntry(g_proton_ligne,"Protons simulated parabola","p");
  // legend->AddEntry(proton_calcul,"Protons calculated parabola","l");
  // legend->AddEntry(g_He1_ligne,"He1+ simulated parabola","p");
  // legend->AddEntry(He1_calcul,"He1+ calculated parabola","l");
  // legend->AddEntry(g_He2_ligne,"He2+ simulated parabola","p");
  // legend->AddEntry(He2_calcul,"He2+ calculated parabola","l");
  // legend->Draw();

  
}
