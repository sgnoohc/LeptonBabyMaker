#include "fakeratelooper.h"
#include "TString.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

//usage: ./main.exe QCD_Test 1000 1 ./

vector<TString> load(const char *type, char *input){

  vector<TString> output;
  char buffer[200];
  char StringValue[1000];
  ifstream IN(input);
  while( IN.getline(buffer, 200, '\n') ){
    // ok = false;
    if (buffer[0] == '#') {
      continue; // Skip lines commented with '#'
    }
    if( !strcmp(buffer, "SAMPLE")){
      bool add = false;
      IN.getline(buffer, 200, '\n');
      sscanf(buffer, "Name\t%s", StringValue);
      if((string)StringValue==(string)type) add=true;
      IN.getline(buffer, 200, '\n');
      sscanf(buffer, "Path\t%s", StringValue);
      if(add){
	std::ostringstream addStream;
	addStream << StringValue;
	TString addString = addStream.str().c_str();
	output.push_back(addString);
      }
    }
  }
  return output;
}

int main(int argc, char **argv)
  try{
    TString sample = "";
    babyMaker *mylooper = new babyMaker();
    TChain *result = new TChain("Events");
    char *input = "sample.dat";

    if (argc < 2) {
      sample = "default";
      cout<<"Using default file. "<<endl;
    }
    else {
      sample = (TString) argv[1];
      cout<<"Using files corresponding to sample "<<sample<<endl;
    }

    int nevents = -1;
    if (argc < 3) {
      cout<<"Number of events not specified. Running over "<<nevents<<" events"<<endl;
    }
    else {
      TString n = (TString) argv[2];
      nevents = n.Atoi();
      cout<<"Running over "<<nevents<<" events"<<endl;
    }
    
    int file=0;
    if (argc < 4) {
      cout<<"Number of events not specified. Running over "<<nevents<<" events"<<endl;
    }
    else {
      file = atoi(argv[3]);
    }
    const char* filename = (file == 0 ? "merged_ntuple_*.root" : Form("merged_ntuple_%i.root", file));
    cout<<"Running over files with names "<<filename<<endl;
    const char* suffix = file == 0 ? "" : Form("_%i", file);

    string dirpath = "./";  
    if (argc < 5) {
      cout<<"No directory specified, default ./" <<endl;
    } else {
      dirpath = argv[4];
      cout<<"Output directory is" << dirpath <<endl;
    }
    
    vector<TString> samplelist = load(sample.Data(), input);//new
    if(samplelist.size()==0) cout<<"Could not find files corresponding to sample "<<sample<<endl;
    for(unsigned int i = 0; i<samplelist.size(); ++i){
      std::ifstream infile(samplelist[i].Data());
      if (infile.good()) {
	if(!(samplelist[i].Contains(".root"))) samplelist[i] = samplelist[i] + filename;
	cout << "Add sample " << samplelist[i] << " to files to be processed." << endl;
	result->Add(samplelist[i].Data());
      } else {
	cout << "Warning! File: " << samplelist[i] << " does not exist ab exist. Not added to files to be processed." << endl;
      }
    }

    mylooper->SetOutputPath(dirpath);
    mylooper->looper(result, Form("%s%s", (char*) sample.Data(),suffix), nevents);
    return 0;

  }
  catch (std::exception& e)
    {
      std::cerr << "[LeptonBabyMaker] Error: failed..." << std::endl;
      std::cerr << e.what() << std::endl;
      return 1;
    }


