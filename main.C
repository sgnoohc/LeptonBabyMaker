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
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-20toInf_MuEnrichedPt15_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v3/V07-02-08/merged_ntuple_1.root");
      }
      //QCD_MuEnriched
      else if (sample == "QCD_Mu_Enriched"){
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-20toInf_MuEnrichedPt15_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v3/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-30to50_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-AVE20BX25_tsg_PHYS14_25_V3-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-50to80_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-AVE20BX25_tsg_PHYS14_25_V3-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-80to120_MuEnrichedPt5_PionKaonDecay_Tune4C_13TeV_pythia8_Phys14DR-AVE20BX25_tsg_PHYS14_25_V3-v1/V07-02-08/merged_ntuple_*.root");
      }
      //QCD_EM_Enriched
      else if (sample == "QCD_EM_Enriched"){
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt_20to30_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
	//result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt_30to80_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");  //bad sample. Doesn't exist
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt_80to170_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt_170toInf_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-5to10_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-10to20_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-20to30_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-30to80_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-80to170_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
      }
      //QCD non-Enriched
      else if (sample == "QCD_non_Enriched"){
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-15to30_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-30to50_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-50to80_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-80to120_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-120to170_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-170to300_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-06/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-300to470_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-470to600_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-600to800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-800to1000_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-1000to1400_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-1400to1800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-1800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-1800to2400_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v2/V07-02-06/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-2400to3200_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-3200_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_Pt-15to3000_Tune4C_Flat_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
      }
      //QCD HT
      else if (sample == "QCD_HT"){
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_HT-100To250_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_HT-500To1000_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_HT_1000ToInf_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1/V07-02-08/merged_ntuple_*.root");
	result->Add("/hadoop/cms/store/group/snt/phys14/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/V07-02-08/merged_ntuple_*.root");
      }
      //ttbar
      else if (sample == "TTBAR"){
	result->Add("/hadoop/cms/store/group/snt/phys14/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
      }
      //DY
      else if (sample == "DY"){
	result->Add("/hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_13TeV-madgraph-pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
      }
      //WJets
      else if (sample == "WJets"){
	result->Add("/hadoop/cms/store/group/snt/phys14/WJetsToLNu_13TeV-madgraph-pythia8-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_*.root");
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


