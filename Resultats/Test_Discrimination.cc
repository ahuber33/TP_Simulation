void Test_Discrimination()
{

  //float pitch = 6.5e-3; //ORCA
  //float pitch = 20e-3; //CMOS
  //float pitch = 50e-3; //IP
  float PosX = 50;
  float PosY = 5;
  int NbinsX=PosX/pitch;
  int NbinsY=(PosY+1)/pitch;

 
  //TFile *file1 = new TFile("Proton_YAG_0.1mm_CMOS_Exp_30MeV_Optique_2D.root");
  //TFile *file2 = new TFile("He2+_YAG_0.1mm_CMOS_Exp_30MeV_Optique_2D.root");
  //TFile *file3 = new TFile("Proton_YAG_0.1mm_CMOS_Exp_30MeV_Optique_Energie.root");

  TFile *file1 = new TFile("proton_2D.root");
  TFile *file2 = new TFile("He2+_2D.root");
  TFile *file3 = new TFile("proton_Energie.root");

  TH2F *f = (TH2F*)file1->Get("2D");
  TH2F *g = (TH2F*)file2->Get("2D");
  TH2F *h = (TH2F*)file3->Get("E_vs_Position");

  //f->Draw("colz");

  //new TCanvas;
  //  g->Draw("colz");
  //g->SetMarkerColor(kRed);

  int j=2000;

  TF1* gaus = new TF1("gaus", "gaus", 0, 5);
  TF1* gaus1 = new TF1("gaus1", "gaus(0)+gaus(3)", 0, 5);
  TF1* gaus2 = new TF1("gaus2", "gaus(0)+gaus(3)", 0, 5);

  new TCanvas;
  TH1D *Proj1 = new TH1D("Proj1", "Proj1", NbinsY, -1, PosY);
  f->ProjectionY("Proj1", j, j, "");
  Proj1->Draw();
  Proj1->Fit(gaus, "0");
  gaus1->SetParameter(0, gaus->GetParameter(0));
  gaus1->SetParameter(1, gaus->GetParameter(1));
  gaus1->SetParameter(2, gaus->GetParameter(2));
  gaus1->SetParameter(4, gaus->GetParameter(1));
  gaus1->SetParameter(3, 0.1*gaus->GetParameter(0));
  gaus1->SetParameter(5, 5*gaus->GetParameter(2));
  Proj1->Fit(gaus1, "0");
  gaus1->Draw("same");
  gaus1->SetLineColor(kBlue);
  Proj1->SetLineColor(kCyan);

  TH1D *Proj2 = new TH1D("Proj2", "Proj2", NbinsY, -1, PosY);
  g->ProjectionY("Proj2", j, j, "");
  Proj2->Draw("same");
  Proj2->Fit(gaus, "0");
  gaus2->SetParameter(0, gaus->GetParameter(0));
  gaus2->SetParameter(1, gaus->GetParameter(1));
  gaus2->SetParameter(2, gaus->GetParameter(2));
  gaus2->SetParameter(4, gaus->GetParameter(1));
  gaus2->SetParameter(3, 0.1*gaus->GetParameter(0));
  gaus2->SetParameter(5, 5*gaus->GetParameter(2));
  Proj2->Fit(gaus2, "0");
  gaus2->Draw("same");
  gaus2->SetLineColor(kCyan);
  Proj2->SetLineColor(kBlue);

  float Mean1 = gaus1->GetParameter(1);
  float Mean2 = gaus2->GetParameter(1);
  float Sigma1 = gaus1->GetParameter(2);
  float Sigma2 = gaus2->GetParameter(2);

  cout << "Mean 1 = " << Mean1 << endl;
  cout << "Mean 2 = " << Mean2 << endl;
  cout << "Sigma 1 = " << Sigma1 << endl;
  cout << "Sigma 2 = " << Sigma2 << endl;

  int out=0;
  
  if(Mean1 + 3*Sigma1 < Mean2)out++;
  if(Mean2 - 3*Sigma2 > Mean1)out++;

  cout << "Out = " << out << endl;

  float X[NbinsX], Y[NbinsX];
  int n=0;

  
  for (int i = 0; i<NbinsX ; i++)
    {
      out =0;
      f->ProjectionY("Proj1", i, i, "");
      Proj1->Fit(gaus, "Q0");
      gaus1->SetParameter(0, gaus->GetParameter(0));
      gaus1->SetParameter(1, gaus->GetParameter(1));
      gaus1->SetParameter(2, gaus->GetParameter(2));
      gaus1->SetParameter(4, gaus->GetParameter(1));
      gaus1->SetParameter(3, 0.1*gaus->GetParameter(0));
      gaus1->SetParameter(5, 5*gaus->GetParameter(2));
      Proj1->Fit(gaus1, "Q0");

      g->ProjectionY("Proj2", i, i, "");
      Proj2->Fit(gaus, "Q0");
      gaus2->SetParameter(0, gaus->GetParameter(0));
      gaus2->SetParameter(1, gaus->GetParameter(1));
      gaus2->SetParameter(2, gaus->GetParameter(2));
      gaus2->SetParameter(4, gaus->GetParameter(1));
      gaus2->SetParameter(3, 0.1*gaus->GetParameter(0));
      gaus2->SetParameter(5, 5*gaus->GetParameter(2));
      Proj2->Fit(gaus2, "Q0");
      
      Mean1 = gaus1->GetParameter(1);
      Mean2 = gaus2->GetParameter(1);
      Sigma1 = gaus1->GetParameter(2);
      Sigma2 = gaus2->GetParameter(2);

      if(Mean1 + 3*Sigma1 < Mean2)out++;
      if(Mean2 - 3*Sigma2 > Mean1)out++;

      //X[i] = f->GetXaxis()->GetBinCenter(i);
      X[n] =i;
      Y[n] = out;
      n++;

      //cout << " i =" << i << endl;
      //cout << "out = " << out << endl;
    }

  TGraph* gg = new TGraph(n, X, Y);

  new TCanvas;
  gg->Draw("");

  new TCanvas;
  h->Draw("colz");

}
