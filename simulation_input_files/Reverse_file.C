#include <iostream>
#include <fstream>

using namespace std;

void Reverse_file()
{
  ifstream file("CargilleBulkAbsorb.cfg");
  const int nlines =400;
  
  float c,d;
  std::vector<float> vx;
  std::vector<float> vy;
  vx.clear();
  vy.clear();
  string filler;
  
  for (int i =0; i<nlines; i++){
    file >> c >> filler >> d;
    vx.push_back(c);
    vy.push_back(d);
    cout << "x = " << vx.at(i) << " y = " << vy.at(i) << endl;
  }
  file.close();


  ofstream ofile("CargilleBulkAbsorb_reverse.cfg");

  for(int i =0; i<nlines; i++)
    {
      ofile <<vx.at(nlines-1-i) << ", " << vy.at(nlines-1-i) << endl;
    }

}
