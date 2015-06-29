#include "fakeratelooper.h"
#include "TString.h"

//usage: ./main.exe QCD_Test 1000

int main(int argc, char **argv)
  try{
    TString sample = "";
    babyMaker *mylooper = new babyMaker();
    TChain *result = new TChain("Events");

    if (argc < 2) {
      sample = "default";
      cout<<"Using default file. "<<endl;
      result->Add("/hadoop/cms/store/group/snt/run2_50ns/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-03/merged_ntuple_1.root");
    }
    else {
      sample = (TString) argv[1];
      cout<<"Using files corresponding to sample "<<sample<<endl;
      //QCD_test (test with just one file)
      if (sample == "QCD_Test"){
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_80to120_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-02-08/merged_ntuple_1.root");
      }
      //QCD_MuEnriched
      else if (sample == "QCD_Mu_Enriched"){
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-15to20_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-02-08/merged_ntuple_*.root");
	//missing samples!
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-80to120_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-120to170_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-300to470_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-470to600_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-600to800_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-800to1000_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-1000toInf_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
      }
      //QCD_EM_Enriched
      else if (sample == "QCD_EM_Enriched"){
	//bcToE
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_15to20_bcToE_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_20to30_bcToE_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_30to80_bcToE_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-04-03/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_80to170_bcToE_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-04-03/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_170to250_bcToE_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/merged_ntuple_*.root");
	//EMEnriched
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-15to20_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-20to30_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-30to50_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-50to80_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-80to120_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v3/V07-04-03/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-120to170_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt-170to300_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/merged_ntuple_*.root");
      }
      //QCD non-Enriched
      else if (sample == "QCD_non_Enriched"){
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_5to10_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
	//misssing sample
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_15to30_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_50to80_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_80to120_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_120to170_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_470to600_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
	//misssing sample
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_800to1000_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_1400to1800_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_1800to2400_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_2400to3200_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_3200toInf_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-02-08/merged_ntuple_*.root");
      }
      //QCD HT
      else if (sample == "QCD_HT"){
      }
      //ttbar
      else if (sample == "TTBAR"){
	result->Add("/hadoop/cms/store/group/snt/run2_25ns/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-04-03/merged_ntuple_*.root");
      }
      //DY
      else if (sample == "DY"){
      }
      //WJets
      else if (sample == "WJets"){
      }
      //2012DoubleEle
      else if (sample == "2012DoubleEle"){
	result->Add("/hadoop/cms/store/user/gzevi/DoubleElectron/crab_DoubleElectron_CMSSW_7_4_0_pre9_ROOT6-GR_R_74_V8_1Apr_RelVal_zEl2012D-v1/CMS3_V07-04-01/merged/merged_ntuple_1.root");
      }
      else {
	cout<<"Could not find files corresponding to sample "<<sample<<endl;
      }
    }
   
    int nevents = 100;
    if (argc < 3) {
      cout<<"Number of events not specified. Running over "<<nevents<<" events"<<endl;
    }
    else {
      TString n = (TString) argv[2];
      nevents = n.Atoi();
      cout<<"Running over "<<nevents<<" events"<<endl;
    }

    mylooper->looper(result, (char*) sample.Data(), nevents);
    return 0;

  }
  catch (std::exception& e)
    {
      std::cerr << "[LeptonBabyMaker] Error: failed..." << std::endl;
      std::cerr << e.what() << std::endl;
      return 1;
    }


