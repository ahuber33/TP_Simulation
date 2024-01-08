#include "Analyse_Config_TP.hh"

void Analyse_Config_TP()
{
  //gStyle->SetOptStat(0);

  float x[NbinsX], ex[NbinsX], y[NbinsX], ey[NbinsX];
  float x_new[1500], y_new[1500], ex_new[1500], ey_new[1500];
  float xE[NbinsX], exE[NbinsX], yE[NbinsX], eyE[NbinsX];
  float xNph[NbinsX], exNph[NbinsX], yNph[NbinsX], eyNph[NbinsX];

  float distance = 300;
  string filename = "Config33_proton.root";
  string filename_He2 = "Config33_He2+.root";
  //string filename = "proton_EJ262_5mm_lens_75mm_300mm_CMOS_Exp_30MeV.root";
  //string filename_out_Nph = "Etudes_lentilles/Graph_Nph_proton_ZnS_0.2mm_5mm_lens_75mm_300mm_CMOS_Exp_30MeV.root";
  //string filename_out_Resolution = "Etudes_lentilles/Graph_Resolution_proton_ZnS_0.2mm_5mm_lens_75mm_300mm_CMOS_Exp_30MeV.root";
  //string filename_out = "../../../Images/TPSim/Analyses_Scintillateurs/Lentille/Results_proton_ZnS_0.2mm_5mm_lens_75mm_300mm_CMOS_Exp_30MeV.png";

  cout << "\nStart of 2D proton Histogram reconstruction !!!" << endl;
  TH2F* Pos = Histo_Reconstruction_2D(filename.c_str(), "2D", distance);
  cout << "\nStart of 2D He2+ Histogram reconstruction !!!" << endl;
  TH2F* Pos_He = Histo_Reconstruction_2D(filename_He2.c_str(), "2D_He", distance);
  TH2F* Pos_ALL = (TH2F*)Pos->Clone();
  Pos_ALL->Add(Pos_He, 1);
  cout << "End of 2D Histogram reconstruction !!!" << endl;
  cout << "\nStart of EPos Histogram reconstruction !!!" << endl;
  TH2F* EPos = Histo_Reconstruction_Energie_Position(filename.c_str(), "Energie Position", distance);
  cout << "End of EPos Histogram reconstruction !!!" << endl;
  TH1F* Estart = Histo_Reconstruction_Estart(filename.c_str());


  cout << "\nStart of Resolution part !!! " << endl;

  // RESOLUTION PART
  TH1D *ProjY = new TH1D("ProjY", "ProjY", 1000, 0, 100);
  Draw_ProjY_Test(EPos, ProjY, 300);
  int n=0;

  for (int i=200; i<2000; i++)
    {

      EPos->ProjectionY("ProjY", i, i, "");
      ProjY->Fit(fit_gaus_Energie, "QN");
      mean = fit_gaus_Energie->GetParameter(1);
      sigma = fit_gaus_Energie->GetParameter(2);
      Resolution = sigma/mean;
      Chi2 = fit_gaus_Energie->GetChisquare();
      Ndf = fit_gaus_Energie->GetNDF();
      Chi2Ndf = Chi2/Ndf;

      // cout << "Mean = " << mean << endl;
      // cout << "Sigma = " << sigma << endl;
      // cout << "Resolution = " << Resolution << endl;
      // cout << "Chi2/Ndf = " << Chi2Ndf << endl;

       if(Chi2Ndf >0.5 && Chi2Ndf <60 && mean >0 && mean <120 && sigma/mean <1)
   	{
	  y[n] = fit_gaus_Energie->GetParameter(1);
	  ey[n] = fit_gaus_Energie->GetParameter(2);
	  if(ey[n] <0.1)ey[n]=0.1;
	  
	  xE[n] = y[n];
	  exE[n] = fit_gaus_Energie->GetParError(1);
	  if(exE[n] >20)exE[n]=0;
	  yE[n] = Resolution;
	  //if(yE[n] >0.1)yE[n]=-0.1;
	  eyE[n] = fit_gaus_Energie->GetParError(2)/ey[n] + fit_gaus_Energie->GetParError(1)/y[n];
	  if(eyE[n] >0.1)eyE[n]=0;
	  //cout << "\nResolution[" << i << "] = " << yE[n] << endl;
	  //cout << "Chi2/Ndf[" << i << "] = " << Chi2Ndf << endl;
	  n++;
	}
    }

  cout << " n = " << n << endl;

  gResolution = new TGraphErrors(n, xE, yE, exE, eyE);

  cout << "End of Resolution part !!! " << endl;

  cout << "\nStart of Nph part !!! " << endl;

  // NPH PART
  TH1D *ProjX = new TH1D("ProjX", "ProjX", 1500, 0, 150);
  Draw_ProjX_Test(EPos, ProjX, Estart, 1062);
  int nbis=0;

  for (int i=10; i<1200; i++)
    {
      EPos->ProjectionX("ProjX", i, i, "");
      fitX = new TF1("fitX", "gaus", 0, ProjX->GetMean(1) + 2*ProjX->GetRMS(1));
      fitX->SetParameter(1, ProjX->GetMean(1));
      fitX->SetParameter(2, ProjX->GetRMS(1));
      ProjX->Fit(fitX, "QR");
      fitX1 = new TF1("fitX1", "gaus", fitX->GetParameter(1)-4*fitX->GetParameter(2), fitX->GetParameter(1)+0.5*fitX->GetParameter(2));
      ProjX->Fit(fitX1, "QR");
      
      Eval_Energy = fitX1->Eval(fitX1->GetParameter(1))/2;
      if (Eval_Energy != Eval_Energy) continue; //test NaN condition !!!
      NEvents = Estart->Integral(i, i);
      x_new[nbis] = (i-0.5)/10;
      ex_new[nbis] = 0.5;
      y_new[nbis] = Eval_Energy/NEvents;
      ey_new[nbis] = y_new[nbis] * ((sqrt(Eval_Energy)/Eval_Energy) + (sqrt(NEvents)/NEvents));
      Chi2 = fitX1->GetChisquare();
      Ndf = fitX1->GetNDF();
      Chi2Ndf = Chi2/Ndf;
      // cout << "\ni = " << i << endl;
      // cout << "Eval = " << Eval_Energy << endl;
      // cout << "Nevents = " << NEvents << endl;
      // cout << "Nph = " << Eval_Energy/NEvents << endl;
      // cout << "Chi2/NdF = " << Chi2Ndf << endl;
      nbis++;
      
    }
  
  Nph = new TGraphErrors(nbis, x_new, y_new, ex_new, ey_new);

  cout << "End of Nph part !!! " << endl;
  

  // DRAW AND SAVE
  Draw_Results(Estart, Pos_ALL, EPos, gResolution, Nph);
  //Save_Results(filename_out, filename_out_Resolution, filename_out_Nph);


  new TCanvas;
  Pos->Draw("colz");


  int j=400;
  int Rebin = 10;

  TF1* gaus1 = new TF1("gaus1", "gaus", -1, 10);
  TF1* gaus2 = new TF1("gaus2", "gaus", -1, 10);
  TH1D* Proj1 = new TH1D("Proj1", "Proj1", NbinsY, -1, PosY);
  TH1D* Proj2 = new TH1D("Proj2", "Proj2", NbinsY, -1, PosY);

  float Mean1;
  float Mean2;
  float Sigma1;
  float Sigma2;

  Pos->RebinX(Rebin);
  Pos_He->RebinX(Rebin);

  /*
  new TCanvas;
  Proj1 = new TH1D("Proj1", "Proj1", NbinsY, -1, PosY);
  Pos->ProjectionY("Proj1", j, j, "");
  Proj1->Draw();
  Proj1->Fit(gaus1, "0");
  gaus1->Draw("same");
  gaus1->SetLineColor(kBlue);
  Proj1->SetLineColor(kCyan);

  Proj2 = new TH1D("Proj2", "Proj2", NbinsY, -1, PosY);
  Pos_He->ProjectionY("Proj2", j, j, "");
  Proj2->Draw("same");
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
  */

  int out=0;
  
  if(Mean1 + 3*Sigma1 < Mean2)out++;
  if(Mean2 - 3*Sigma2 > Mean1)out++;

  cout << "Out = " << out << endl;

  float X[NbinsX/Rebin], Y[NbinsX/Rebin];
  int m=0;


  
  for (int i = 0; i<NbinsX/Rebin ; i++)
    {
      out =0;
      Pos->ProjectionY("Proj1", i, i, "");
      Proj1->Fit(gaus1, "Q0");

      Pos_He->ProjectionY("Proj2", i, i, "");
      Proj2->Fit(gaus2, "Q0");
      
      Mean1 = gaus1->GetParameter(1);
      Mean2 = gaus2->GetParameter(1);
      Sigma1 = gaus1->GetParameter(2);
      Sigma2 = gaus2->GetParameter(2);

      if(Mean1 + 3*Sigma1 < Mean2)out++;
      if(Mean2 - 3*Sigma2 > Mean1)out++;

      //X[i] = f->GetXaxis()->GetBinCenter(i);
      X[m] =i;
      Y[m] = out;
      m++;

      //cout << " i =" << i << endl;
      //cout << "out = " << out << endl;
    }

  TGraph* gg = new TGraph(m, X, Y);

  new TCanvas;
  gg->Draw("");
  


}
