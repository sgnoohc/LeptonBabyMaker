#include "Riostream.h"
#include "TFile.h"

int checkForZombies(string fileName){

  TFile *file = new TFile(fileName.c_str(), "read");
  bool isZombie = (bool)file->IsZombie();

  ofstream zombieFiles;
  zombieFiles.open("listOfZombies.txt");
  if(isZombie){
    zombieFiles << fileName << endl;
  }
  
  zombieFiles.close();
  file->Close();

  return isZombie;
}
  
