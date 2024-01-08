TGraphErrors* GetGraph(const char* filename)
{
  TFile* file = new TFile(filename);
  TGraphErrors* g = (TGraphErrors*)file->Get("Graph");

  return g;
}
  



void Plot_general()
{


  TGraphErrors* g_Res_EJ_contact = GetGraph("/mnt/hgfs/shared/Simulations/TP_Simulation/Resultats/Etudes_Scintillateurs/Graph_files/Graph_Resolution_proton_EJ262_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TGraphErrors* g_Nph_EJ_contact = GetGraph("/mnt/hgfs/shared/Simulations/TP_Simulation/Resultats/Etudes_Scintillateurs/Graph_files/Graph_Nph_proton_EJ262_0.1mm_CMOS_Exp_30MeV_Optique.root");

  TGraphErrors* g_Res_YAG_contact = GetGraph("/mnt/hgfs/shared/Simulations/TP_Simulation/Resultats/Etudes_Scintillateurs/Graph_files/Graph_Resolution_proton_YAG_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TGraphErrors* g_Nph_YAG_contact = GetGraph("/mnt/hgfs/shared/Simulations/TP_Simulation/Resultats/Etudes_Scintillateurs/Graph_files/Graph_Nph_proton_YAG_0.1mm_CMOS_Exp_30MeV_Optique.root");

  TGraphErrors* g_Res_EJ_lens = GetGraph("Graph_Resolution_proton_EJ262_0.1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_EJ_lens = GetGraph("Graph_Nph_proton_EJ262_0.1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  
  TGraphErrors* g_Res_YAG_lens = GetGraph("Graph_Resolution_proton_YAG_0.1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_YAG_lens = GetGraph("Graph_Nph_proton_YAG_0.1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");

  TGraphErrors* g_Res_EJ_fiber = GetGraph("/mnt/hgfs/shared/Simulations/TP_FIBERS_Simulation/Resultats/Graph_Resolution_proton_EJ262_0.1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_EJ_fiber = GetGraph("/mnt/hgfs/shared/Simulations/TP_FIBERS_Simulation/Resultats/Graph_Nph_proton_EJ262_0.1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");
  
  TGraphErrors* g_Res_YAG_fiber = GetGraph("/mnt/hgfs/shared/Simulations/TP_FIBERS_Simulation/Resultats/Graph_Resolution_proton_YAG_0.1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_YAG_fiber = GetGraph("/mnt/hgfs/shared/Simulations/TP_FIBERS_Simulation/Resultats/Graph_Nph_proton_YAG_0.1mm_round_fiber_multicladding_0.2mm_1m_CMOS_Exp_30MeV.root");



  g_Nph_YAG_contact->SetLineColor(kRed);
  g_Nph_YAG_contact->SetMarkerColor(kRed);
  g_Nph_YAG_contact->SetFillColor(kRed);

  g_Nph_EJ_contact->SetLineColor(kBlue);
  g_Nph_EJ_contact->SetMarkerColor(kBlue);
  g_Nph_EJ_contact->SetFillColor(kBlue);

  g_Nph_YAG_lens->SetLineColor(kOrange);
  g_Nph_YAG_lens->SetMarkerColor(kOrange);
  g_Nph_YAG_lens->SetFillColor(kOrange);

  g_Nph_EJ_lens->SetLineColor(kCyan);
  g_Nph_EJ_lens->SetMarkerColor(kCyan);
  g_Nph_EJ_lens->SetFillColor(kCyan);

  g_Nph_YAG_fiber->SetLineColor(kMagenta);
  g_Nph_YAG_fiber->SetMarkerColor(kMagenta);
  g_Nph_YAG_fiber->SetFillColor(kMagenta);

  g_Nph_EJ_fiber->SetLineColor(kBlack);
  g_Nph_EJ_fiber->SetMarkerColor(kBlack);
  g_Nph_EJ_fiber->SetFillColor(kBlack);



  new TCanvas;
  g_Nph_YAG_lens->Draw("APE2");
  g_Nph_EJ_contact->Draw("samePE2");
  g_Nph_YAG_contact->Draw("samePE2");
  g_Nph_EJ_lens->Draw("samePE2");
  g_Nph_YAG_fiber->Draw("sameC");
  g_Nph_EJ_fiber->Draw("samePE2");


  TLegend* leg = new TLegend(0.1, 0.5, 0.3, 0.9);
  leg->AddEntry(g_Nph_YAG_contact, "YAG 0.1mm direct contact", "PF");
  leg->AddEntry(g_Nph_EJ_contact, "EJ-262 0.1mm direct contact", "PF");
  leg->AddEntry(g_Nph_YAG_lens, "YAG 1mm with lens [solid angle = 0.049 sr (75mm/300mm)]", "PF");
  leg->AddEntry(g_Nph_EJ_lens, "EJ-262 1mm with lens [solid angle = 0.049 sr (75mm/300mm)]", "PF");
  leg->AddEntry(g_Nph_YAG_fiber, "YAG 0.1mm with fibers", "PF");
  leg->AddEntry(g_Nph_EJ_fiber, "EJ-262 0.1mm with fibers", "PF");
  leg->Draw();



  g_Res_YAG_contact->SetLineColor(kRed);
  g_Res_YAG_contact->SetMarkerColor(kRed);
  g_Res_YAG_contact->SetFillColor(kRed);

  g_Res_EJ_contact->SetLineColor(kBlue);
  g_Res_EJ_contact->SetMarkerColor(kBlue);
  g_Res_EJ_contact->SetFillColor(kBlue);

  g_Res_YAG_lens->SetLineColor(kOrange);
  g_Res_YAG_lens->SetMarkerColor(kOrange);
  g_Res_YAG_lens->SetFillColor(kOrange);

  g_Res_EJ_lens->SetLineColor(kCyan);
  g_Res_EJ_lens->SetMarkerColor(kCyan);
  g_Res_EJ_lens->SetFillColor(kCyan);

  g_Res_YAG_fiber->SetLineColor(kMagenta);
  g_Res_YAG_fiber->SetMarkerColor(kMagenta);
  g_Res_YAG_fiber->SetFillColor(kMagenta);

  g_Res_EJ_fiber->SetLineColor(kBlack);
  g_Res_EJ_fiber->SetMarkerColor(kBlack);
  g_Res_EJ_fiber->SetFillColor(kBlack);



  new TCanvas;
  g_Res_YAG_lens->Draw("APE2");
  g_Res_EJ_contact->Draw("samePE2");
  g_Res_YAG_contact->Draw("samePE2");
  g_Res_EJ_lens->Draw("samePE2");
  g_Res_YAG_fiber->Draw("samePE2");
  g_Res_EJ_fiber->Draw("samePE2");


  TLegend* leg1 = new TLegend(0.1, 0.5, 0.3, 0.9);
  leg1->AddEntry(g_Res_YAG_contact, "YAG 0.1mm direct contact", "PF");
  leg1->AddEntry(g_Res_EJ_contact, "EJ-262 0.1mm direct contact", "PF");
  leg1->AddEntry(g_Res_YAG_lens, "YAG 1mm with lens [solid angle = 0.049 sr (75mm/300mm)]", "PF");
  leg1->AddEntry(g_Res_EJ_lens, "EJ-262 1mm with lens [solid angle = 0.049 sr (75mm/300mm)]", "PF");
  leg1->AddEntry(g_Res_YAG_fiber, "YAG 0.1mm with fibers", "PF");
  leg1->AddEntry(g_Res_EJ_fiber, "EJ-262 0.1mm with fibers", "PF");
  leg1->Draw();

  
  
}
