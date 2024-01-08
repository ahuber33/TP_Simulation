TGraphErrors* GetGraph(const char* filename)
{
  TFile* file = new TFile(filename);
  TGraphErrors* g = (TGraphErrors*)file->Get("Graph");

  return g;
}
  



void Plot()
{

  //TGraphErrors* g_Res_0 = GetGraph("Graph_Resolution_proton_ZnS_0.2mm_0.025mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  //TGraphErrors* g_Nph_0 = GetGraph("Graph_Nph_proton_ZnS_0.2mm_0.025mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");

  TGraphErrors* g_Res_1 = GetGraph("Graph_Resolution_proton_ZnS_0.2mm_0.1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_1 = GetGraph("Graph_Nph_proton_ZnS_0.2mm_0.1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");

  TGraphErrors* g_Res_2 = GetGraph("Graph_Resolution_proton_ZnS_0.2mm_0.5mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_2 = GetGraph("Graph_Nph_proton_ZnS_0.2mm_0.5mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");

  TGraphErrors* g_Res_3 = GetGraph("Graph_Resolution_proton_ZnS_0.2mm_1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_3 = GetGraph("Graph_Nph_proton_ZnS_0.2mm_1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");

  TGraphErrors* g_Res_4 = GetGraph("Graph_Resolution_proton_ZnS_0.2mm_2mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_4 = GetGraph("Graph_Nph_proton_ZnS_0.2mm_2mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");

  TGraphErrors* g_Res_5 = GetGraph("Graph_Resolution_proton_ZnS_0.2mm_5mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_5 = GetGraph("Graph_Nph_proton_ZnS_0.2mm_5mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");


  new TCanvas;
  g_Res_1->Draw("APE2");
  g_Res_2->Draw("samePE2");
  g_Res_3->Draw("samePE2");
  g_Res_4->Draw("samePE2");
  g_Res_5->Draw("samePE2");
  //g_Res_0->Draw("samePE2");

  g_Res_1->SetMarkerColor(kBlack);
  g_Res_2->SetMarkerColor(kRed);
  g_Res_3->SetMarkerColor(kCyan);
  g_Res_4->SetMarkerColor(kBlue);
  g_Res_5->SetMarkerColor(kGreen);
  //g_Res_0->SetMarkerColor(kOrange);

  g_Res_1->SetFillColor(kBlack);
  g_Res_2->SetFillColor(kRed);
  g_Res_3->SetFillColor(kCyan);
  g_Res_4->SetFillColor(kBlue);
  g_Res_5->SetFillColor(kGreen);
  //g_Res_0->SetFillColor(kOrange);

  g_Res_1->SetLineColor(kBlack);
  g_Res_2->SetLineColor(kRed);
  g_Res_3->SetLineColor(kCyan);
  g_Res_4->SetLineColor(kBlue);
  g_Res_5->SetLineColor(kGreen);
  //g_Res_0->SetLineColor(kOrange);

  g_Res_1->SetMarkerStyle(6);
  g_Res_2->SetMarkerStyle(7);
  g_Res_3->SetMarkerStyle(7);
  g_Res_4->SetMarkerStyle(7);
  g_Res_5->SetMarkerStyle(6);
  //g_Res_0->SetMarkerStyle(6);


  
  TLegend* legend = new TLegend(0.1, 0.5, 0.3, 0.9);
  legend->SetHeader("ZnS 0.2mm + EJ-212");
  //legend->AddEntry(g_Res_0, "thickness = 0.025 mm", "PF");
  legend->AddEntry(g_Res_1, "thickness = 0.1 mm", "PF");
  legend->AddEntry(g_Res_2, "thickness = 0.5 mm", "PF");
  legend->AddEntry(g_Res_3, "thickness = 1 mm", "PF");
  legend->AddEntry(g_Res_4, "thickness = 2 mm", "PF");
  legend->AddEntry(g_Res_5, "thickness = 5 mm", "PF");
  legend->Draw();



  new TCanvas;
  g_Nph_1->Draw("APE2");
  g_Nph_2->Draw("samePE2");
  g_Nph_3->Draw("samePE2");
  g_Nph_4->Draw("samePE2");
  g_Nph_5->Draw("samePE2");
  //g_Nph_0->Draw("samePE2");

  g_Nph_1->SetMarkerColor(kBlack);
  g_Nph_2->SetMarkerColor(kRed);
  g_Nph_3->SetMarkerColor(kCyan);
  g_Nph_4->SetMarkerColor(kBlue);
  g_Nph_5->SetMarkerColor(kGreen);
  //g_Nph_0->SetMarkerColor(kOrange);

  g_Nph_1->SetFillColor(kBlack);
  g_Nph_2->SetFillColor(kRed);
  g_Nph_3->SetFillColor(kCyan);
  g_Nph_4->SetFillColor(kBlue);
  g_Nph_5->SetFillColor(kGreen);
  //g_Nph_0->SetFillColor(kOrange);

  g_Nph_1->SetLineColor(kBlack);
  g_Nph_2->SetLineColor(kRed);
  g_Nph_3->SetLineColor(kCyan);
  g_Nph_4->SetLineColor(kBlue);
  g_Nph_5->SetLineColor(kGreen);
  //g_Nph_0->SetLineColor(kOrange);

  g_Nph_1->SetMarkerStyle(6);
  g_Nph_2->SetMarkerStyle(7);
  g_Nph_3->SetMarkerStyle(7);
  g_Nph_4->SetMarkerStyle(7);
  g_Nph_5->SetMarkerStyle(6);
  //g_Nph_0->SetMarkerStyle(6);


  
  TLegend* legend1 = new TLegend(0.1, 0.5, 0.3, 0.9);
  legend1->SetHeader("ZnS 0.2mm + EJ-212");
  //legend1->AddEntry(g_Nph_0, "thickness = 0.025 mm", "PF");
  legend1->AddEntry(g_Nph_1, "thickness = 0.1 mm", "PF");
  legend1->AddEntry(g_Nph_2, "thickness = 0.5 mm", "PF");
  legend1->AddEntry(g_Nph_3, "thickness = 1 mm", "PF");
  legend1->AddEntry(g_Nph_4, "thickness = 2 mm", "PF");
  legend1->AddEntry(g_Nph_5, "thickness = 5 mm", "PF");
  legend1->Draw();


  TGraphErrors* g_Res_ZnS_1 = GetGraph("Graph_Resolution_proton_ZnS_0.1mm_0.1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_ZnS_1 = GetGraph("Graph_Nph_proton_ZnS_0.1mm_0.1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Res_ZnS_2 = GetGraph("Graph_Resolution_proton_ZnS_0.1mm_0.5mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_ZnS_2 = GetGraph("Graph_Nph_proton_ZnS_0.1mm_0.5mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Res_ZnS_3 = GetGraph("Graph_Resolution_proton_ZnS_0.1mm_1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_ZnS_3 = GetGraph("Graph_Nph_proton_ZnS_0.1mm_1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");

  TGraphErrors* g_Res_EJ262_1 = GetGraph("Graph_Resolution_proton_EJ262_0.1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_EJ262_1 = GetGraph("Graph_Nph_proton_EJ262_0.1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Res_EJ262_2 = GetGraph("Graph_Resolution_proton_EJ262_0.5mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_EJ262_2 = GetGraph("Graph_Nph_proton_EJ262_0.5mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Res_EJ262_3 = GetGraph("Graph_Resolution_proton_EJ262_1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_EJ262_3 = GetGraph("Graph_Nph_proton_EJ262_1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");

  TGraphErrors* g_Res_YAG_1 = GetGraph("Graph_Resolution_proton_YAG_0.1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_YAG_1 = GetGraph("Graph_Nph_proton_YAG_0.1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Res_YAG_2 = GetGraph("Graph_Resolution_proton_YAG_0.5mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_YAG_2 = GetGraph("Graph_Nph_proton_YAG_0.5mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Res_YAG_3 = GetGraph("Graph_Resolution_proton_YAG_1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");
  TGraphErrors* g_Nph_YAG_3 = GetGraph("Graph_Nph_proton_YAG_1mm_lens_75mm_300mm_CMOS_Exp_30MeV.root");


  g_Nph_ZnS_1->SetLineColor(kBlack);
  g_Nph_ZnS_1->SetMarkerColor(kBlack);
  g_Nph_ZnS_1->SetFillColor(kBlack);
  g_Nph_ZnS_2->SetLineColor(kBlack);
  g_Nph_ZnS_2->SetMarkerColor(kBlack);
  g_Nph_ZnS_2->SetFillColor(kBlack);
  g_Nph_ZnS_3->SetLineColor(kBlack);
  g_Nph_ZnS_3->SetMarkerColor(kBlack);
  g_Nph_ZnS_3->SetFillColor(kBlack);

  g_Nph_YAG_1->SetLineColor(kRed);
  g_Nph_YAG_1->SetMarkerColor(kRed);
  g_Nph_YAG_1->SetFillColor(kRed);
  g_Nph_YAG_2->SetLineColor(kRed);
  g_Nph_YAG_2->SetMarkerColor(kRed);
  g_Nph_YAG_2->SetFillColor(kRed);
  g_Nph_YAG_3->SetLineColor(kRed);
  g_Nph_YAG_3->SetMarkerColor(kRed);
  g_Nph_YAG_3->SetFillColor(kRed);

  g_Nph_EJ262_1->SetLineColor(kBlue);
  g_Nph_EJ262_1->SetMarkerColor(kBlue);
  g_Nph_EJ262_1->SetFillColor(kBlue);
  g_Nph_EJ262_2->SetLineColor(kBlue);
  g_Nph_EJ262_2->SetMarkerColor(kBlue);
  g_Nph_EJ262_2->SetFillColor(kBlue);
  g_Nph_EJ262_3->SetLineColor(kBlue);
  g_Nph_EJ262_3->SetMarkerColor(kBlue);
  g_Nph_EJ262_3->SetFillColor(kBlue);


  new TCanvas;
  g_Nph_ZnS_1->Draw("APE2");
  g_Nph_EJ262_1->Draw("samePE2");
  g_Nph_YAG_1->Draw("samePE2");

  TLegend* legend2 = new TLegend(0.1, 0.5, 0.3, 0.9);
  legend2->SetHeader("Thickness  = 0.1 mm");
  legend2->AddEntry(g_Nph_YAG_1, "YAG", "PF");
  legend2->AddEntry(g_Nph_EJ262_1, "EJ262", "PF");
  legend2->AddEntry(g_Nph_ZnS_1, "ZnS", "PF");
  legend2->Draw();


  new TCanvas;
  g_Nph_ZnS_2->Draw("APE2");
  g_Nph_EJ262_2->Draw("samePE2");
  g_Nph_YAG_2->Draw("samePE2");

  TLegend* legend3 = new TLegend(0.1, 0.5, 0.3, 0.9);
  legend3->SetHeader("Thickness  = 0.5 mm");
  legend3->AddEntry(g_Nph_YAG_2, "YAG", "PF");
  legend3->AddEntry(g_Nph_EJ262_2, "EJ262", "PF");
  legend3->AddEntry(g_Nph_ZnS_2, "ZnS", "PF");
  legend3->Draw();


  new TCanvas;
  g_Nph_ZnS_3->Draw("APE2");
  g_Nph_EJ262_3->Draw("samePE2");
  g_Nph_YAG_3->Draw("samePE2");

  TLegend* legend4 = new TLegend(0.1, 0.5, 0.3, 0.9);
  legend4->SetHeader("Thickness  = 1 mm");
  legend4->AddEntry(g_Nph_YAG_3, "YAG", "PF");
  legend4->AddEntry(g_Nph_EJ262_3, "EJ262", "PF");
  legend4->AddEntry(g_Nph_ZnS_3, "ZnS", "PF");
  legend4->Draw();



  g_Res_ZnS_1->SetLineColor(kBlack);
  g_Res_ZnS_1->SetMarkerColor(kBlack);
  g_Res_ZnS_1->SetFillColor(kBlack);
  g_Res_ZnS_2->SetLineColor(kBlack);
  g_Res_ZnS_2->SetMarkerColor(kBlack);
  g_Res_ZnS_2->SetFillColor(kBlack);
  g_Res_ZnS_3->SetLineColor(kBlack);
  g_Res_ZnS_3->SetMarkerColor(kBlack);
  g_Res_ZnS_3->SetFillColor(kBlack);

  g_Res_YAG_1->SetLineColor(kRed);
  g_Res_YAG_1->SetMarkerColor(kRed);
  g_Res_YAG_1->SetFillColor(kRed);
  g_Res_YAG_2->SetLineColor(kRed);
  g_Res_YAG_2->SetMarkerColor(kRed);
  g_Res_YAG_2->SetFillColor(kRed);
  g_Res_YAG_3->SetLineColor(kRed);
  g_Res_YAG_3->SetMarkerColor(kRed);
  g_Res_YAG_3->SetFillColor(kRed);

  g_Res_EJ262_1->SetLineColor(kBlue);
  g_Res_EJ262_1->SetMarkerColor(kBlue);
  g_Res_EJ262_1->SetFillColor(kBlue);
  g_Res_EJ262_2->SetLineColor(kBlue);
  g_Res_EJ262_2->SetMarkerColor(kBlue);
  g_Res_EJ262_2->SetFillColor(kBlue);
  g_Res_EJ262_3->SetLineColor(kBlue);
  g_Res_EJ262_3->SetMarkerColor(kBlue);
  g_Res_EJ262_3->SetFillColor(kBlue);


  new TCanvas;
  g_Res_ZnS_1->Draw("APE2");
  g_Res_EJ262_1->Draw("samePE2");
  g_Res_YAG_1->Draw("samePE2");

  TLegend* legend5 = new TLegend(0.1, 0.5, 0.3, 0.9);
  legend5->SetHeader("Thickness  = 0.1 mm");
  legend5->AddEntry(g_Res_YAG_1, "YAG", "PF");
  legend5->AddEntry(g_Res_EJ262_1, "EJ262", "PF");
  legend5->AddEntry(g_Res_ZnS_1, "ZnS", "PF");
  legend5->Draw();


  new TCanvas;
  g_Res_ZnS_2->Draw("APE2");
  g_Res_EJ262_2->Draw("samePE2");
  g_Res_YAG_2->Draw("samePE2");

  TLegend* legend6 = new TLegend(0.1, 0.5, 0.3, 0.9);
  legend6->SetHeader("Thickness  = 0.5 mm");
  legend6->AddEntry(g_Res_YAG_2, "YAG", "PF");
  legend6->AddEntry(g_Res_EJ262_2, "EJ262", "PF");
  legend6->AddEntry(g_Res_ZnS_2, "ZnS", "PF");
  legend6->Draw();


  new TCanvas;
  g_Res_ZnS_3->Draw("APE2");
  g_Res_EJ262_3->Draw("samePE2");
  g_Res_YAG_3->Draw("samePE2");

  TLegend* legend7 = new TLegend(0.1, 0.5, 0.3, 0.9);
  legend7->SetHeader("Thickness  = 1 mm");
  legend7->AddEntry(g_Res_YAG_3, "YAG", "PF");
  legend7->AddEntry(g_Res_EJ262_3, "EJ262", "PF");
  legend7->AddEntry(g_Res_ZnS_3, "ZnS", "PF");
  legend7->Draw();

  
  
}
