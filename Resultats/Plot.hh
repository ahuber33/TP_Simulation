int Compteur(string file)
{
  TFile* f = new TFile(file.c_str());

  float a=0;
  //float Compteur=0;

  TTree *Tree = (TTree*)f->Get("Tree_electron");
  Tree->SetBranchAddress("TotalLength", &a);

  int Entries = Tree->GetEntries();
  //cout << "Entries = " << Entries << endl;

  cout << "Compteur[" << file<< "] = " << Entries << endl;

  return Entries;

}


float Mean(const char* filename, const char* TreeName, const char* VariableName)
{
  TFile* file = new TFile(filename);
  float a;
  TTree *Tree = (TTree*)file->Get(TreeName);
  Tree->SetBranchAddress(VariableName, &a);
  float Entries = Tree->GetEntries();
  float Mean=0;
  float Sum=0;

  for(int i=0; i<Entries; i++)
  {
    Tree->GetEntry(i);
    Sum+=a;
  }

  Mean= Sum/Entries;
  
  cout << "Mean[" << filename << "/" << VariableName << "] = " << Mean << endl;

  file->Close();

  return Mean;
}

float Sigma(const char* filename, const char* TreeName, const char* VariableName, float Mean)
{
  TFile* file = new TFile(filename);
  float a;
  TTree *Tree = (TTree*)file->Get(TreeName);
  Tree->SetBranchAddress(VariableName, &a);
  int Entries = Tree->GetEntries();
  float Sum=0;
  float Sigma=0;

  for(int i=0; i<Entries; i++)
  {
    Tree->GetEntry(i);
    Sigma+=pow(a-Mean, 2);
  }

  Sigma= sqrt(Sigma/Entries);

  cout << "Sigma[" << filename << "] = " << Sigma << endl;

  file->Close();

  return Sigma;
}


TGraphErrors* ge(const char* filenames[], const char* TreeName, const char* VariableName1, const char* VariableName2, const int nfiles)
{
  float x[nfiles];
  float y[nfiles];
  float e_x[nfiles];
  float e_y[nfiles];

  
  for(int i=0; i<nfiles; i++)
    {
      x[i] = Mean(filenames[i], TreeName, VariableName1); //conv keV to MeV
      y[i] = Mean(filenames[i], TreeName, VariableName2); //conv mm to cm
      e_x[i]=0;
      e_y[i] = Sigma(filenames[i], TreeName, VariableName2, y[i]); //conv mm to cm
      x[i] = x[i]/1000;
      y[i] = y[i]/10;
      e_y[i] = e_y[i]/10;
      cout << "x[" << i << "] = " << x[i] << endl;
      cout << "y[" << i << "] = " << y[i] << endl;
      cout << "ey[" << i << "] = " << e_y[i] << endl;
    }
  

  TGraphErrors* graph = new TGraphErrors(nfiles, x, y, e_x, e_y);
      
      
  
  //cout << "test = " << filenames[5] << endl;
  //const char* test = filenames[3];
  
  return graph;
}

