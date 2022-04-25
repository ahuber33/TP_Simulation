void Plot_Reunion_2mai()
{
  float Le1_1[4] = {100, 150, 225, 300};
  float Le1_2[5] = {100, 150, 225, 300, 350};
  float Le1_3[3] = {200, 250, 300};
  float Le1_4[5] = {200, 250, 300, 320, 345};

  float Ecut_1[4] = {52, 63, 69, 71};
  float Ecut_2[5] = {48, 69, 89, 100, 100};
  float Ecut_3[3] = {83, 96, 100};
  float Ecut_4[5] = {74, 85, 88, 100, 100};

  TGraph* g_1 = new TGraph(4, Le1_1, Ecut_1);
  TGraph* g_2 = new TGraph(5, Le1_2, Ecut_2);
  TGraph* g_3 = new TGraph(3, Le1_3, Ecut_3);
  TGraph* g_4 = new TGraph(5, Le1_4, Ecut_4);

  g_2->Draw("");
  g_1->Draw("same");
  g_3->Draw("same");
  g_4->Draw("same");

  auto legend = new TLegend(0.1,0.7,0.48,0.9);
  legend->AddEntry(g_1,"E = 1500 kV/m & L_{tot} = 355 mm","l");
  legend->AddEntry(g_4,"E = 1500 kV/m & L_{tot} = 400 mm","l");
  legend->AddEntry(g_2,"E = 1500 kV/m & L_{tot} = 430 mm","l");
  legend->AddEntry(g_3,"E = 1500 kV/m & L_{tot} = 460 mm","l");
  legend->Draw();


  float Le1_5[4] = {100, 150, 225, 300};
  float Le1_6[4] = {100, 150, 225, 300};
  float Le1_7[4] = {100, 150, 225, 300};
  float Le1_8[4] = {200, 250, 280, 320};

  float Ecut_5[4] = {52, 69, 95, 96};
  float Ecut_6[4] = {58, 80, 100, 100};
  float Ecut_7[4] = {59, 80, 95, 100};
  float Ecut_8[4] = {92, 95, 100, 100};

  TGraph* g_5 = new TGraph(4, Le1_5, Ecut_5);
  TGraph* g_6 = new TGraph(4, Le1_6, Ecut_6);
  TGraph* g_7 = new TGraph(4, Le1_7, Ecut_7);
  TGraph* g_8 = new TGraph(4, Le1_8, Ecut_8);

  g_5->Draw("");
  g_6->Draw("same");
  g_7->Draw("same");
  g_8->Draw("same");

  auto legend1 = new TLegend(0.1,0.7,0.48,0.9);
  legend1->AddEntry(g_5,"E = 2000 kV/m & L_{tot} = 355 mm","l");
  legend1->AddEntry(g_8,"E = 2000 kV/m & L_{tot} = 370 mm","l");
  legend1->AddEntry(g_7,"E = 2000 kV/m & L_{tot} = 390 mm","l");
  legend1->AddEntry(g_6,"E = 2000 kV/m & L_{tot} = 400 mm","l");
  legend1->Draw();



  float Pinhole[3] = {0.1, 0.15, 0.2};

  float Ecut_9[3] = {100, 65, 48};
  float Ecut_10[3] = {100, 74, 58};
  float Ecut_11[3] = {100, 66, 54};
  float Ecut_12[3] = {100, 70, 54};
  float Ecut_Mean[3] = {100, 68.75, 53.25};
  float E_Pinhole[3] = {0, 0, 0};
  float E_Ecut[3] = {0, 4.11, 4.11};

  TGraph* g_9 = new TGraph(3, Pinhole, Ecut_9);
  TGraph* g_10 = new TGraph(3, Pinhole, Ecut_10);
  TGraph* g_11 = new TGraph(3, Pinhole, Ecut_11);
  TGraph* g_12 = new TGraph(3, Pinhole, Ecut_12);
  TGraphErrors* g_err1 = new TGraphErrors(3, Pinhole, Ecut_12, E_Pinhole, E_Ecut);

  g_9->Draw("");
  g_10->Draw("same");
  g_11->Draw("same");
  g_12->Draw("same");

  auto legend2 = new TLegend(0.1,0.7,0.48,0.9);
  legend2->AddEntry(g_9,"Config 1","l");
  legend2->AddEntry(g_10,"Config 2","l");
  legend2->AddEntry(g_11,"Config 3","l");
  legend2->AddEntry(g_12,"Config 4","l");
  legend2->Draw();



  new TCanvas;
  g_err1->Draw("A3");
  g_err1->SetFillColor(kRed);
  g_err1->SetFillStyle(3010);



  float B[3] = {0.3, 0.6, 0.9};

  float Ecut_13[3] = {31, 37, 35};
  float Ecut_14[3] = {52, 58, 54};
  float Ecut_15[3] = {69, 75, 70};

  TGraph* g_13 = new TGraph(3, B, Ecut_13);
  TGraph* g_14 = new TGraph(3, B, Ecut_14);
  TGraph* g_15 = new TGraph(3, B, Ecut_15);


  g_13->Draw("");
  g_14->Draw("same");
  g_15->Draw("same");

  auto legend3 = new TLegend(0.1,0.7,0.48,0.9);
  legend3->AddEntry(g_13,"Config 1","l");
  legend3->AddEntry(g_14,"Config 2","l");
  legend3->AddEntry(g_15,"Config 3","l");
  legend3->Draw();



  float Ecut_16[3] = {29, 33, 31};
  float Ecut_17[3] = {52, 58, 54};
  float Ecut_18[3] = {89, 86, 89};
  float Ecut_19[3] = {100, 100, 100};

  TGraph* g_16 = new TGraph(3, B, Ecut_16);
  TGraph* g_17 = new TGraph(3, B, Ecut_17);
  TGraph* g_18 = new TGraph(3, B, Ecut_18);
  TGraph* g_19 = new TGraph(3, B, Ecut_19);


  g_16->Draw("");
  g_17->Draw("same");
  g_18->Draw("same");
  g_19->Draw("same");

  auto legend4 = new TLegend(0.1,0.7,0.48,0.9);
  legend4->AddEntry(g_16,"Config 1","l");
  legend4->AddEntry(g_17,"Config 2","l");
  legend4->AddEntry(g_18,"Config 3","l");
  legend4->AddEntry(g_19,"Config 4","l");
  legend4->Draw();




  float Ecut_20[3] = {37, 44, 37};
  float Ecut_21[3] = {52, 58, 54};
  float Ecut_22[3] = {63, 66, 65};
  float Ecut_23[3] = {69, 71, 71};

  TGraph* g_20 = new TGraph(3, B, Ecut_20);
  TGraph* g_21 = new TGraph(3, B, Ecut_21);
  TGraph* g_22 = new TGraph(3, B, Ecut_22);
  TGraph* g_23 = new TGraph(3, B, Ecut_23);


  g_20->Draw("");
  g_21->Draw("same");
  g_22->Draw("same");
  g_23->Draw("same");

  auto legend5 = new TLegend(0.1,0.7,0.48,0.9);
  legend5->AddEntry(g_20,"Config 1","l");
  legend5->AddEntry(g_21,"Config 2","l");
  legend5->AddEntry(g_22,"Config 3","l");
  legend5->AddEntry(g_23,"Config 4","l");
  legend5->Draw();



  float Le1_var1[4] = {100, 150, 225, 300};
  float Le1_var2[5] = {100, 150, 225, 300, 375};
  float Ecut_24[4] = {37, 52, 63, 69};
  float Ecut_25[5] = {48, 69, 89, 100, 100};

  TGraph* g_24 = new TGraph(4, Le1_var1, Ecut_24);
  TGraph* g_25 = new TGraph(5, Le1_var2, Ecut_25);



  g_25->Draw("");
  g_24->Draw("same");

  auto legend6 = new TLegend(0.1,0.7,0.48,0.9);
  legend6->AddEntry(g_24,"Config 1","l");
  legend6->AddEntry(g_25,"Config 2","l");
  legend6->Draw();


  
  
}
