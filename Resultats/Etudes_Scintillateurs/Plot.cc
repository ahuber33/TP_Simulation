void Plot()
{

  /*
  TFile* file1 = new TFile("Graph_files/Graph_Nph_proton_ZnS_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file2 = new TFile("Graph_files/Graph_Nph_proton_ZnS_0.5mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file3 = new TFile("Graph_files/Graph_Nph_proton_ZnS_1mm_CMOS_Exp_30MeV_Optique.root");

  TGraph* g1 = (TGraph*)file1->Get("Graph");
  TGraph* g2 = (TGraph*)file2->Get("Graph");
  TGraph* g3 = (TGraph*)file3->Get("Graph");

  TCanvas* c1 = new TCanvas("Nph", "Nph", 2500, 1800);
  c1->cd();
  c1->SetGridx();
  c1->SetGridy();
  //c1->SetLogx();
  c1->SetLogy();

  g1->Draw("APE2");
  g1->GetXaxis()->SetLimits(1, 100);
  g1->SetMarkerStyle(7);
  g2->Draw("samePE2");
  g2->SetMarkerStyle(7);
  g2->SetMarkerColor(kBlue);
  g2->SetLineColor(kBlue);
  g2->SetFillColor(kBlue);
  g3->Draw("samePE2");
  g3->SetMarkerStyle(7);
  g3->SetMarkerColor(kCyan);
  g3->SetFillColor(kCyan);
  g3->SetLineColor(kCyan);

  g1->GetXaxis()->SetTitle("proton energy [MeV]");
  g1->GetXaxis()->SetTitleSize(0.03);
  g1->GetXaxis()->SetTitleOffset(1.3);
  g1->GetYaxis()->SetTitle("Nph [photons/pixel/particules_{detected}]");

  TLegend* leg1 = new TLegend(0.6, 0.7, 0.9, 0.9);
  leg1->SetHeader("ZnS :", "");
  leg1->AddEntry(g1, "thickness = 0.1 mm", "pf");
  leg1->AddEntry(g2, "thickness = 0.5 mm", "pf");
  leg1->AddEntry(g3, "thickness = 1 mm", "pf");
  leg1->Draw();



  TFile* file4 = new TFile("Graph_files/Graph_Resolution_proton_ZnS_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file5 = new TFile("Graph_files/Graph_Resolution_proton_ZnS_0.5mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file6 = new TFile("Graph_files/Graph_Resolution_proton_ZnS_1mm_CMOS_Exp_30MeV_Optique.root");

  TGraph* g4 = (TGraph*)file4->Get("Graph");
  TGraph* g5 = (TGraph*)file5->Get("Graph");
  TGraph* g6 = (TGraph*)file6->Get("Graph");

  TCanvas* c2 = new TCanvas("Resolution", "Resolution", 2500, 1800);
  c2->cd();
  c2->SetGridx();
  c2->SetGridy();
  //c2->SetLogx();
  //c2->SetLogy();

  g4->Draw("APE2");
  g4->GetXaxis()->SetLimits(1, 100);
  g4->GetYaxis()->SetLimits(0.01, 1);
  g4->SetMarkerStyle(7);
  g5->Draw("samePE2");
  g5->SetMarkerStyle(7);
  g5->SetMarkerColor(kBlue);
  g5->SetLineColor(kBlue);
  g5->SetFillColor(kBlue);
  g6->Draw("samePE2");
  g6->SetMarkerStyle(7);
  g6->SetMarkerColor(kCyan);
  g6->SetFillColor(kCyan);
  g6->SetLineColor(kCyan);

  g4->GetXaxis()->SetTitle("proton energy [MeV]");
  g4->GetXaxis()->SetTitleSize(0.03);
  g4->GetXaxis()->SetTitleOffset(1.3);
  g4->GetYaxis()->SetTitle("Energy Resolution");

  TLegend* leg2 = new TLegend(0.1, 0.7, 0.38, 0.9);
  leg2->SetHeader("ZnS :", "");
  leg2->AddEntry(g4, "thickness = 0.1 mm", "pf");
  leg2->AddEntry(g5, "thickness = 0.5 mm", "pf");
  leg2->AddEntry(g6, "thickness = 1 mm", "pf");
  leg2->Draw();
  
  */





  
  TFile* file2 = new TFile("Graph_files/Graph_Nph_proton_EJ212_1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file1 = new TFile("Graph_files/Graph_Nph_proton_YAG_1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file3 = new TFile("Graph_files/Graph_Nph_proton_EJ262_1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file4 = new TFile("Graph_files/Graph_Nph_proton_ZnS_1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file5 = new TFile("Graph_files/Graph_Nph_proton_CsITl_1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file6 = new TFile("Graph_files/Graph_Nph_proton_LYSO_1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file7 = new TFile("Graph_files/Graph_Nph_proton_LuAG_1mm_CMOS_Exp_30MeV_Optique.root");

  TGraph* g1 = (TGraph*)file1->Get("Graph");
  TGraph* g2 = (TGraph*)file2->Get("Graph");
  TGraph* g3 = (TGraph*)file3->Get("Graph");
  TGraph* g4 = (TGraph*)file4->Get("Graph");
  TGraph* g5 = (TGraph*)file5->Get("Graph");
  TGraph* g6 = (TGraph*)file6->Get("Graph");
  TGraph* g7 = (TGraph*)file7->Get("Graph");

  TCanvas* c1 = new TCanvas("Nph", "Nph", 2500, 1800);
  c1->cd();
  c1->SetGridx();
  c1->SetGridy();
  //c1->SetLogx();
  c1->SetLogy();

  g1->Draw("APE2");
  g1->GetXaxis()->SetLimits(1, 100);
  g1->SetMarkerStyle(7);
  //g2->Draw("samePE2");
  //g2->SetMarkerStyle(7);
  //g2->SetMarkerColor(kBlue);
  //g2->SetLineColor(kBlue);
  //g2->SetFillColor(kBlue);
  g3->Draw("samePE2");
  g3->SetMarkerStyle(7);
  g3->SetMarkerColor(kCyan);
  g3->SetFillColor(kCyan);
  g3->SetLineColor(kCyan);
  g4->Draw("samePE2");
  g4->SetMarkerStyle(7);
  g4->SetMarkerColor(kBlack);
  g4->SetFillColor(kBlack);
  g4->SetLineColor(kBlack);
  //g5->Draw("samePE2");
  //g5->SetMarkerStyle(7);
  //g5->SetMarkerColor(kOrange);
  //g5->SetFillColor(kOrange);
  //g5->SetLineColor(kOrange);
  //g6->Draw("samePE2");
  //g6->SetMarkerStyle(7);
  //g6->SetMarkerColor(kGreen);
  //g6->SetFillColor(kGreen);
  //g6->SetLineColor(kGreen);
  //g7->Draw("samePE2");
  //g7->SetMarkerStyle(7);
  //g7->SetMarkerColor(kGreen+2);
  //g7->SetFillColor(kGreen+2);
  //g7->SetLineColor(kGreen+2);

  g1->GetXaxis()->SetTitle("proton energy [MeV]");
  g1->GetXaxis()->SetTitleSize(0.03);
  g1->GetXaxis()->SetTitleOffset(1.3);
  g1->GetYaxis()->SetTitle("Nph [photons/pixel/particules_{detected}]");

  TLegend* leg1 = new TLegend(0.6, 0.7, 0.9, 0.9);
  leg1->SetHeader("Thickness = 1 mm :", "");
  //leg1->AddEntry(g1, "EJ214 (0.025 mm thickness)", "pf");
  leg1->AddEntry(g1, "YAG", "pf");
  leg1->AddEntry(g3, "EJ262", "pf");
  //leg1->AddEntry(g4, "YAG", "pf");
  leg1->AddEntry(g4, "ZnS", "pf");
  //leg1->AddEntry(g5, "CsITl", "pf");
  //leg1->AddEntry(g6, "LYSO", "pf");
  //leg1->AddEntry(g7, "LuAG", "pf");
  leg1->Draw();





  TFile* file9 = new TFile("Graph_files/Graph_Resolution_proton_EJ212_1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file8 = new TFile("Graph_files/Graph_Resolution_proton_YAG_1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file10 = new TFile("Graph_files/Graph_Resolution_proton_EJ260_1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file11 = new TFile("Graph_files/Graph_Resolution_proton_ZnS_1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file12 = new TFile("Graph_files/Graph_Resolution_proton_CsITl_1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file13 = new TFile("Graph_files/Graph_Resolution_proton_LYSO_1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file14 = new TFile("Graph_files/Graph_Resolution_proton_LuAG_1mm_CMOS_Exp_30MeV_Optique.root");

  TGraph* g8 = (TGraph*)file8->Get("Graph");
  TGraph* g9 = (TGraph*)file9->Get("Graph");
  TGraph* g10 = (TGraph*)file10->Get("Graph");
  TGraph* g11 = (TGraph*)file11->Get("Graph");
  TGraph* g12 = (TGraph*)file12->Get("Graph");
  TGraph* g13 = (TGraph*)file13->Get("Graph");
  TGraph* g14 = (TGraph*)file14->Get("Graph");

  TCanvas* c2 = new TCanvas("Resolution", "Resolution", 2500, 1800);
  c2->cd();
  c2->SetGridx();
  c2->SetGridy();
  //c1->SetLogx();
  //c2->SetLogy();

  g8->Draw("APE2");
  g8->GetXaxis()->SetLimits(1, 100);
  g8->SetMarkerStyle(7);
  // g9->Draw("samePE2");
  // g9->SetMarkerStyle(7);
  // g9->SetMarkerColor(kBlue);
  // g9->SetLineColor(kBlue);
  // g9->SetFillColor(kBlue);
  g10->Draw("samePE2");
  g10->SetMarkerStyle(7);
  g10->SetMarkerColor(kCyan);
  g10->SetFillColor(kCyan);
  g10->SetLineColor(kCyan);
  g11->Draw("samePE2");
  g11->SetMarkerStyle(7);
  g11->SetMarkerColor(kBlack);
  g11->SetFillColor(kBlack);
  g11->SetLineColor(kBlack);
  // g12->Draw("samePE2");
  // g12->SetMarkerStyle(7);
  // g12->SetMarkerColor(kOrange);
  // g12->SetFillColor(kOrange);
  // g12->SetLineColor(kOrange);
  // g13->Draw("samePE2");
  // g13->SetMarkerStyle(7);
  // g13->SetMarkerColor(kGreen);
  // g13->SetFillColor(kGreen);
  // g13->SetLineColor(kGreen);
  // g14->Draw("samePE2");
  // g14->SetMarkerStyle(7);
  // g14->SetMarkerColor(kGreen+2);
  // g14->SetFillColor(kGreen+2);
  // g14->SetLineColor(kGreen+2);

  g8->GetXaxis()->SetTitle("proton energy [MeV]");
  g8->GetXaxis()->SetTitleSize(0.03);
  g8->GetXaxis()->SetTitleOffset(1.3);
  g8->GetYaxis()->SetTitle("Energy resolution");

  TLegend* leg2 = new TLegend(0.1, 0.7, 0.4, 0.9);
  leg2->SetHeader("Thickness = 1 mm :", "");
  //leg2->AddEntry(g8, "EJ214 (0.025 mm thickness)", "pf");
  leg2->AddEntry(g8, "YAG", "pf");
  leg2->AddEntry(g10, "EJ262", "pf");
  //leg2->AddEntry(g9, "YAG", "pf");
  leg2->AddEntry(g11, "ZnS", "pf");
  //leg2->AddEntry(g12, "CsITl", "pf");
  //leg2->AddEntry(g13, "LYSO", "pf");
  //leg2->AddEntry(g14, "LuAG", "pf");
  leg2->Draw();




  /*
  
  TFile* file1 = new TFile("Graph_files/Graph_Nph_proton_EJ214_0.025mm_ORCA_Exp_30MeV_Optique.root");
  TFile* file2 = new TFile("Graph_files/Graph_Nph_proton_EJ262_0.1mm_ORCA_Exp_30MeV_Optique.root");
  TFile* file3 = new TFile("Graph_files/Graph_Nph_proton_ZnS_0.1mm_ORCA_Exp_30MeV_Optique.root");
  TFile* file4 = new TFile("Graph_files/Graph_Nph_proton_LYSO_0.1mm_ORCA_Exp_30MeV_Optique.root");
  TFile* file5 = new TFile("Graph_files/Graph_Nph_proton_EJ214_0.025mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file6 = new TFile("Graph_files/Graph_Nph_proton_EJ262_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file7 = new TFile("Graph_files/Graph_Nph_proton_ZnS_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file8 = new TFile("Graph_files/Graph_Nph_proton_LYSO_0.1mm_CMOS_Exp_30MeV_Optique.root");


  TGraph* g1 = (TGraph*)file1->Get("Graph");
  TGraph* g2 = (TGraph*)file2->Get("Graph");
  TGraph* g3 = (TGraph*)file3->Get("Graph");
  TGraph* g4 = (TGraph*)file4->Get("Graph");
  TGraph* g5 = (TGraph*)file5->Get("Graph");
  TGraph* g6 = (TGraph*)file6->Get("Graph");
  TGraph* g7 = (TGraph*)file7->Get("Graph");
  TGraph* g8 = (TGraph*)file8->Get("Graph");

  TCanvas* c1 = new TCanvas("Nph", "Nph", 2500, 1800);
  c1->cd();
  c1->SetGridx();
  c1->SetGridy();
  //c1->SetLogx();
  c1->SetLogy();

  g1->Draw("APE2");
  g1->GetXaxis()->SetLimits(1, 100);
  g1->SetMarkerStyle(7);
  g2->Draw("samePE2");
  g2->SetMarkerStyle(7);
  g2->SetMarkerColor(kBlue);
  g2->SetLineColor(kBlue);
  g2->SetFillColor(kBlue);
  g3->Draw("samePE2");
  g3->SetMarkerStyle(7);
  g3->SetMarkerColor(kCyan);
  g3->SetFillColor(kCyan);
  g3->SetLineColor(kCyan);
  g4->Draw("samePE2");
  g4->SetMarkerStyle(7);
  g4->SetMarkerColor(kBlack);
  g4->SetFillColor(kBlack);
  g4->SetLineColor(kBlack);
  g5->Draw("samePE2");
  g5->SetMarkerStyle(7);
  g5->SetMarkerColor(kOrange);
  g5->SetFillColor(kOrange);
  g5->SetLineColor(kOrange);
  g6->Draw("samePE2");
  g6->SetMarkerStyle(7);
  g6->SetMarkerColor(kGreen);
  g6->SetFillColor(kGreen);
  g6->SetLineColor(kGreen);
  g7->Draw("samePE2");
  g7->SetMarkerStyle(7);
  g7->SetMarkerColor(kGreen+2);
  g7->SetFillColor(kGreen+2);
  g7->SetLineColor(kGreen+2);
  g8->Draw("samePE2");
  g8->SetMarkerStyle(7);
  g8->SetMarkerColor(kMagenta);
  g8->SetFillColor(kMagenta);
  g8->SetLineColor(kMagenta);

  g1->GetXaxis()->SetTitle("proton energy [MeV]");
  g1->GetXaxis()->SetTitleSize(0.03);
  g1->GetXaxis()->SetTitleOffset(1.3);
  g1->GetYaxis()->SetTitle("Nph [photons/pixel/particules_{detected}]");

  TLegend* leg1 = new TLegend(0.6, 0.7, 0.9, 0.9);
  leg1->AddEntry(g1, "EJ214 (0.025 mm thickness) + ORCA", "pf");
  leg1->AddEntry(g2, "EJ262 (0.1 mm thickness) + ORCA", "pf");
  leg1->AddEntry(g3, "ZnS (0.1 mm thickness) + ORCA", "pf");
  leg1->AddEntry(g4, "LYSO (0.1 mm thickness) + ORCA", "pf");
  leg1->AddEntry(g5, "EJ214 (0.025 mm thickness) + CMOS", "pf");
  leg1->AddEntry(g6, "EJ262 (0.1 mm thickness) + CMOS", "pf");
  leg1->AddEntry(g7, "ZnS (0.1 mm thickness) + CMOS", "pf");
  leg1->AddEntry(g8, "LYSO (0.1 mm thickness) + CMOS", "pf");
  leg1->Draw();




  TFile* file9 = new TFile("Graph_files/ORCA/Graph_Resolution_proton_EJ214_0.025mm_ORCA_Exp_30MeV_Optique.root");
  TFile* file10 = new TFile("Graph_files/ORCA/Graph_Resolution_proton_EJ262_0.1mm_ORCA_Exp_30MeV_Optique.root");
  TFile* file11 = new TFile("Graph_files/ORCA/Graph_Resolution_proton_ZnS_0.1mm_ORCA_Exp_30MeV_Optique.root");
  TFile* file12 = new TFile("Graph_files/ORCA/Graph_Resolution_proton_LYSO_0.1mm_ORCA_Exp_30MeV_Optique.root");
  TFile* file13 = new TFile("Graph_files/Graph_Resolution_proton_EJ214_0.025mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file14 = new TFile("Graph_files/Graph_Resolution_proton_EJ262_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file15 = new TFile("Graph_files/Graph_Resolution_proton_ZnS_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file16 = new TFile("Graph_files/Graph_Resolution_proton_LYSO_0.1mm_CMOS_Exp_30MeV_Optique.root");


  TGraph* g9 = (TGraph*)file9->Get("Graph");
  TGraph* g10 = (TGraph*)file10->Get("Graph");
  TGraph* g11 = (TGraph*)file11->Get("Graph");
  TGraph* g12 = (TGraph*)file12->Get("Graph");
  TGraph* g13 = (TGraph*)file13->Get("Graph");
  TGraph* g14 = (TGraph*)file14->Get("Graph");
  TGraph* g15 = (TGraph*)file15->Get("Graph");
  TGraph* g16 = (TGraph*)file16->Get("Graph");

  TCanvas* c2 = new TCanvas("Resolution", "Resolution", 2500, 1800);
  c2->cd();
  c2->SetGridx();
  c2->SetGridy();
  //c1->SetLogx();
  //c2->SetLogy();

  g9->Draw("APE2");
  g9->GetXaxis()->SetLimits(1, 100);
  g9->SetMarkerStyle(7);
  g10->Draw("samePE2");
  g10->SetMarkerStyle(7);
  g10->SetMarkerColor(kBlue);
  g10->SetLineColor(kBlue);
  g10->SetFillColor(kBlue);
  g11->Draw("samePE2");
  g11->SetMarkerStyle(7);
  g11->SetMarkerColor(kCyan);
  g11->SetFillColor(kCyan);
  g11->SetLineColor(kCyan);
  g12->Draw("samePE2");
  g12->SetMarkerStyle(7);
  g12->SetMarkerColor(kBlack);
  g12->SetFillColor(kBlack);
  g12->SetLineColor(kBlack);
  g13->Draw("samePE2");
  g13->SetMarkerStyle(7);
  g13->SetMarkerColor(kOrange);
  g13->SetFillColor(kOrange);
  g13->SetLineColor(kOrange);
  g14->Draw("samePE2");
  g14->SetMarkerStyle(7);
  g14->SetMarkerColor(kGreen);
  g14->SetFillColor(kGreen);
  g14->SetLineColor(kGreen);
  g15->Draw("samePE2");
  g15->SetMarkerStyle(7);
  g15->SetMarkerColor(kGreen+2);
  g15->SetFillColor(kGreen+2);
  g15->SetLineColor(kGreen+2);
  g16->Draw("samePE2");
  g16->SetMarkerStyle(7);
  g16->SetMarkerColor(kMagenta);
  g16->SetFillColor(kMagenta);
  g16->SetLineColor(kMagenta);

  g9->GetXaxis()->SetTitle("proton energy [MeV]");
  g9->GetXaxis()->SetTitleSize(0.03);
  g9->GetXaxis()->SetTitleOffset(1.3);
  g9->GetYaxis()->SetTitle("Energy resolution");

  TLegend* leg2 = new TLegend(0.1, 0.7, 0.4, 0.9);
  leg2->AddEntry(g9, "EJ214 (0.025 mm thickness) + ORCA", "pf");
  leg2->AddEntry(g10, "EJ262 (0.1 mm thickness) + ORCA", "pf");
  leg2->AddEntry(g11, "ZnS (0.1 mm thickness) + ORCA", "pf");
  leg2->AddEntry(g12, "LYSO (0.1 mm thickness) + ORCA", "pf");
  leg2->AddEntry(g13, "EJ214 (0.025 mm thickness) + CMOS", "pf");
  leg2->AddEntry(g14, "EJ262 (0.1 mm thickness) + CMOS", "pf");
  leg2->AddEntry(g15, "ZnS (0.1 mm thickness) + CMOS", "pf");
  leg2->AddEntry(g16, "LYSO (0.1 mm thickness) + CMOS", "pf");

  leg2->Draw();
*/



  /*

  TFile* file1 = new TFile("Graph_files/Graph_Nph_proton_ZnS_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file2 = new TFile("Graph_files/Graph_Nph_proton_EJ444_0.048mm_0.025mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file3 = new TFile("Graph_files/Graph_Nph_proton_EJ444_0.081mm_0.025mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file4 = new TFile("Graph_files/Graph_Nph_proton_EJ444_0.048mm_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file5 = new TFile("Graph_files/Graph_Nph_proton_EJ444_0.081mm_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file6 = new TFile("Graph_files/Graph_Nph_proton_EJ440_0.081mm_0.25mm_CMOS_Exp_30MeV_Optique.root");



  TGraph* g1 = (TGraph*)file1->Get("Graph");
  TGraph* g2 = (TGraph*)file2->Get("Graph");
  TGraph* g3 = (TGraph*)file3->Get("Graph");
  TGraph* g4 = (TGraph*)file4->Get("Graph");
  TGraph* g5 = (TGraph*)file5->Get("Graph");
  TGraph* g6 = (TGraph*)file6->Get("Graph");
  //TGraph* g7 = (TGraph*)file7->Get("Graph");
  //TGraph* g8 = (TGraph*)file8->Get("Graph");

  TCanvas* c1 = new TCanvas("Nph", "Nph", 2500, 1800);
  c1->cd();
  c1->SetGridx();
  c1->SetGridy();
  //c1->SetLogx();
  c1->SetLogy();

  g1->Draw("APE2");
  g1->GetXaxis()->SetLimits(1, 100);
  g1->SetMarkerStyle(7);
  g2->Draw("samePE2");
  g2->SetMarkerStyle(7);
  g2->SetMarkerColor(kBlue);
  g2->SetLineColor(kBlue);
  g2->SetFillColor(kBlue);
  g3->Draw("samePE2");
  g3->SetMarkerStyle(7);
  g3->SetMarkerColor(kCyan);
  g3->SetFillColor(kCyan);
  g3->SetLineColor(kCyan);
  g4->Draw("samePE2");
  g4->SetMarkerStyle(7);
  g4->SetMarkerColor(kBlack);
  g4->SetFillColor(kBlack);
  g4->SetLineColor(kBlack);
  g5->Draw("samePE2");
  g5->SetMarkerStyle(7);
  g5->SetMarkerColor(kOrange);
  g5->SetFillColor(kOrange);
  g5->SetLineColor(kOrange);
  g6->Draw("samePE2");
  g6->SetMarkerStyle(7);
  g6->SetMarkerColor(kGreen);
  g6->SetFillColor(kGreen);
  g6->SetLineColor(kGreen);
  // g7->Draw("samePE2");
  // g7->SetMarkerStyle(7);
  // g7->SetMarkerColor(kGreen+2);
  // g7->SetFillColor(kGreen+2);
  // g7->SetLineColor(kGreen+2);
  // g8->Draw("samePE2");
  // g8->SetMarkerStyle(7);
  // g8->SetMarkerColor(kMagenta);
  // g8->SetFillColor(kMagenta);
  // g8->SetLineColor(kMagenta);

  g1->GetXaxis()->SetTitle("proton energy [MeV]");
  g1->GetXaxis()->SetTitleSize(0.03);
  g1->GetXaxis()->SetTitleOffset(1.3);
  g1->GetYaxis()->SetTitle("Nph [photons/pixel/particules_{detected}]");

  TLegend* leg1 = new TLegend(0.6, 0.7, 0.9, 0.9);
  leg1->AddEntry(g1, "ZnS 0.1mm", "pf");
  leg1->AddEntry(g2, "EJ444 48um + 25um", "pf");
  leg1->AddEntry(g3, "EJ444 81um + 25um", "pf");
  leg1->AddEntry(g4, "EJ444 48um + 100um", "pf");
  leg1->AddEntry(g5, "EJ444 81um + 100um", "pf");
  leg1->AddEntry(g6, "EJ440 81um + 250um", "pf");
  leg1->Draw();




  TFile* file7 = new TFile("Graph_files/Graph_Resolution_proton_ZnS_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file8 = new TFile("Graph_files/Graph_Resolution_proton_EJ444_0.048mm_0.025mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file9= new TFile("Graph_files/Graph_Resolution_proton_EJ444_0.081mm_0.025mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file10 = new TFile("Graph_files/Graph_Resolution_proton_EJ444_0.048mm_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file11 = new TFile("Graph_files/Graph_Resolution_proton_EJ444_0.081mm_0.1mm_CMOS_Exp_30MeV_Optique.root");
  TFile* file12 = new TFile("Graph_files/Graph_Resolution_proton_EJ440_0.081mm_0.25mm_CMOS_Exp_30MeV_Optique.root");



  TGraph* g7 = (TGraph*)file7->Get("Graph");
  TGraph* g8 = (TGraph*)file8->Get("Graph");
  TGraph* g9 = (TGraph*)file9->Get("Graph");
  TGraph* g10 = (TGraph*)file10->Get("Graph");
  TGraph* g11 = (TGraph*)file11->Get("Graph");
  TGraph* g12 = (TGraph*)file12->Get("Graph");
  //TGraph* g7 = (TGraph*)file7->Get("Graph");
  //TGraph* g8 = (TGraph*)file8->Get("Graph");

  TCanvas* c2 = new TCanvas("Resolution", "Resolution", 2500, 1800);
  c2->cd();
  c2->SetGridx();
  c2->SetGridy();
  //c1->SetLogx();
  c2->SetLogy();

  g7->Draw("APE2");
  g7->GetXaxis()->SetLimits(1, 100);
  g7->SetMarkerStyle(7);
  g8->Draw("samePE2");
  g8->SetMarkerStyle(7);
  g8->SetMarkerColor(kBlue);
  g8->SetLineColor(kBlue);
  g8->SetFillColor(kBlue);
  g9->Draw("samePE2");
  g9->SetMarkerStyle(7);
  g9->SetMarkerColor(kCyan);
  g9->SetFillColor(kCyan);
  g9->SetLineColor(kCyan);
  g10->Draw("samePE2");
  g10->SetMarkerStyle(7);
  g10->SetMarkerColor(kBlack);
  g10->SetFillColor(kBlack);
  g10->SetLineColor(kBlack);
  g11->Draw("samePE2");
  g11->SetMarkerStyle(7);
  g11->SetMarkerColor(kOrange);
  g11->SetFillColor(kOrange);
  g11->SetLineColor(kOrange);
  g12->Draw("samePE2");
  g12->SetMarkerStyle(7);
  g12->SetMarkerColor(kGreen);
  g12->SetFillColor(kGreen);
  g12->SetLineColor(kGreen);

  g7->GetXaxis()->SetTitle("proton energy [MeV]");
  g7->GetXaxis()->SetTitleSize(0.03);
  g7->GetXaxis()->SetTitleOffset(1.3);
  g7->GetYaxis()->SetTitle("Energy resolution");

  TLegend* leg2 = new TLegend(0.6, 0.7, 0.9, 0.9);
  leg2->AddEntry(g7, "ZnS 0.1mm", "pf");
  leg2->AddEntry(g8, "EJ444 48um + 25um", "pf");
  leg2->AddEntry(g9, "EJ444 81um + 25um", "pf");
  leg2->AddEntry(g10, "EJ444 48um + 100um", "pf");
  leg2->AddEntry(g11, "EJ444 81um + 100um", "pf");
  leg2->AddEntry(g12, "EJ440 81um + 250um", "pf");
  leg2->Draw();

  */

  
}
