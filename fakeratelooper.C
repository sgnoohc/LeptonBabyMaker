#include "fakeratelooper.h" 
#include "CORE/Tools/goodrun.h"

//Switches
bool verbose = 0;
unsigned int evt_cut = 74994186;
bool doFast = true;

//Main functions
void babyMaker::MakeBabyNtuple(const char* output_name){

  //Create Baby
  BabyFile = new TFile(Form("%s/%s", path.c_str(), output_name), "RECREATE");
  BabyFile->cd();
  BabyTree = new TTree("t", "Lepton Baby Ntuple");

  //General
  BabyTree->Branch("evt_pfmet"         , &evt_pfmet);
  BabyTree->Branch("evt_pfmetPhi"      , &evt_pfmetPhi);
  BabyTree->Branch("evt_trackmet"      , &evt_trackmet);
  BabyTree->Branch("evt_trackmetPhi"   , &evt_trackmetPhi);
  BabyTree->Branch("evt_met3p0"        , &evt_met3p0);
  BabyTree->Branch("evt_met3p0Phi"     , &evt_met3p0Phi);
  BabyTree->Branch("evt_pfsumet"       , &evt_pfsumet);
  BabyTree->Branch("evt_pfmetSig"      , &evt_pfmetSig);
  BabyTree->Branch("evt_event"         , &evt_event);
  BabyTree->Branch("evt_lumiBlock"     , &evt_lumiBlock);
  BabyTree->Branch("evt_run"           , &evt_run);
  BabyTree->Branch("filt_csc"          , &filt_csc);
  BabyTree->Branch("filt_hbhe"         , &filt_hbhe);
  BabyTree->Branch("passes_met_filters", &passes_met_filters); 
  BabyTree->Branch("filt_hcallaser"    , &filt_hcallaser);
  BabyTree->Branch("filt_ecaltp"       , &filt_ecaltp);
  BabyTree->Branch("filt_trkfail"      , &filt_trkfail);
  BabyTree->Branch("filt_eebadsc"      , &filt_eebadsc);
  BabyTree->Branch("evt_isRealData"    , &evt_isRealData);
  BabyTree->Branch("scale1fb"          , &scale1fb);
  BabyTree->Branch("evt_xsec_incl"     , &evt_xsec_incl);
  BabyTree->Branch("evt_kfactor"       , &evt_kfactor);
  BabyTree->Branch("gen_met"           , &gen_met);
  BabyTree->Branch("gen_metPhi"        , &gen_metPhi);
  BabyTree->Branch("njets"             , &njets);
  BabyTree->Branch("ht"                , &ht);
  BabyTree->Branch("jets"              , &jets);
  BabyTree->Branch("jets_disc"         , &jets_disc);
  BabyTree->Branch("sample"            , &sample);
  BabyTree->Branch("nFOs_SS"           , &nFOs_SS);
  BabyTree->Branch("nvtx"              , &nvtx);

  //All leptons
  BabyTree->Branch("p4"                            , &p4);
  BabyTree->Branch("tag_p4"                        , &tag_p4);
  BabyTree->Branch("dilep_p4"                      , &dilep_p4);
  BabyTree->Branch("mc_p4"                         , &mc_p4);
  BabyTree->Branch("mc_motherp4"                   , &mc_motherp4);
  BabyTree->Branch("mc_motherid"                   , &mc_motherid);
  BabyTree->Branch("id"                            , &id);
  BabyTree->Branch("isPF"                          , &isPF);
  BabyTree->Branch("idx"                           , &idx);
  BabyTree->Branch("dxyPV"                         , &dxyPV);
  BabyTree->Branch("dZ"                            , &dZ);
  BabyTree->Branch("dxyPV_err"                     , &dxyPV_err);
  BabyTree->Branch("motherID"                      , &motherID);
  BabyTree->Branch("mc_id"                         , &mc_id);
  BabyTree->Branch("RelIso03"                      , &RelIso03);
  BabyTree->Branch("RelIso03EA"                    , &RelIso03EA);
  BabyTree->Branch("RelIso03DB"                    , &RelIso03DB);
  BabyTree->Branch("pfChargedHadronIso"            , &pfChargedHadronIso);
  BabyTree->Branch("pfPhotonIso"                   , &pfPhotonIso);
  BabyTree->Branch("pfNeutralHadronIso"            , &pfNeutralHadronIso);
  BabyTree->Branch("tkIso"                         , &tkIso);
  BabyTree->Branch("sumPUPt"                       , &sumPUPt);
  BabyTree->Branch("passes_SS_tight_v3"            , &passes_SS_tight_v3);
  BabyTree->Branch("passes_SS_tight_noiso_v3"      , &passes_SS_tight_noiso_v3);
  BabyTree->Branch("passes_SS_fo_v3"               , &passes_SS_fo_v3);
  BabyTree->Branch("passes_SS_fo_noiso_v3"         , &passes_SS_fo_noiso_v3);
  BabyTree->Branch("passes_SS_fo_looseMVA_v3"      , &passes_SS_fo_looseMVA_v3);
  BabyTree->Branch("passes_SS_fo_looseMVA_noiso_v3", &passes_SS_fo_looseMVA_noiso_v3);
  BabyTree->Branch("passes_WW_medium_v1"           , &passes_WW_medium_v1);
  BabyTree->Branch("passes_WW_medium_noiso_v1"     , &passes_WW_medium_noiso_v1);
  BabyTree->Branch("passes_WW_fo_v1"               , &passes_WW_fo_v1);
  BabyTree->Branch("passes_WW_fo_noiso_v1"         , &passes_WW_fo_noiso_v1);
  BabyTree->Branch("passes_WW_fo_looseMVA_v1"      , &passes_WW_fo_looseMVA_v1);
  BabyTree->Branch("passes_WW_fo_looseMVA_noiso_v1", &passes_WW_fo_looseMVA_noiso_v1);
  BabyTree->Branch("passes_WW_veto_v1"             , &passes_WW_veto_v1);
  BabyTree->Branch("passes_WW_veto_noiso_v1"       , &passes_WW_veto_noiso_v1);
  BabyTree->Branch("passes_HAD_veto_v3"            , &passes_HAD_veto_v3);
  BabyTree->Branch("passes_HAD_veto_noiso_v3"      , &passes_HAD_veto_noiso_v3);
  BabyTree->Branch("passes_HAD_loose_v3"           , &passes_HAD_loose_v3);
  BabyTree->Branch("passes_HAD_loose_noiso_v3"     , &passes_HAD_loose_noiso_v3);
  BabyTree->Branch("passes_POG_vetoID"             , &passes_POG_vetoID);
  BabyTree->Branch("passes_POG_looseID"            , &passes_POG_looseID);
  BabyTree->Branch("passes_POG_mediumID"           , &passes_POG_mediumID);
  BabyTree->Branch("passes_POG_tightID"            , &passes_POG_tightID);
  BabyTree->Branch("ip3d"                          , &ip3d);
  BabyTree->Branch("ip3derr"                       , &ip3derr);
  BabyTree->Branch("type"                          , &type);
  BabyTree->Branch("mt"                            , &mt);
  BabyTree->Branch("ptrelv0"                       , &ptrelv0);
  BabyTree->Branch("ptrelv1"                       , &ptrelv1);
  BabyTree->Branch("miniiso"                       , &miniiso);
  BabyTree->Branch("miniisoDB"                     , &miniisoDB);
  BabyTree->Branch("reliso04"                      , &reliso04);
  BabyTree->Branch("annulus04"                     , &annulus04);
  BabyTree->Branch("iso03sumPt"                    , &iso03sumPt);
  BabyTree->Branch("iso03emEt"                     , &iso03emEt);
  BabyTree->Branch("iso03hadEt"                    , &iso03hadEt);
  BabyTree->Branch("jet_close_lep"                 , &jet_close_lep);
  BabyTree->Branch("ptratio"                       , &ptratio);
  BabyTree->Branch("tag_charge"                    , &tag_charge);
  BabyTree->Branch("tag_eSeed"                     , &tag_eSeed);
  BabyTree->Branch("tag_eSCraw"                    , &tag_eSCraw);
  BabyTree->Branch("tag_HLTLeadingLeg"             , &tag_HLTLeadingLeg);

  //Tag triggers
  BabyTree->Branch("tag_HLT_Ele25WP60_Ele8_Mass55_LeadingLeg"                , &tag_HLT_Ele25WP60_Ele8_Mass55_LeadingLeg);
  BabyTree->Branch("tag_HLT_Ele25WP60_SC4_Mass55_LeadingLeg"                 , &tag_HLT_Ele25WP60_SC4_Mass55_LeadingLeg);
  BabyTree->Branch("tag_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg", &tag_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg);
  BabyTree->Branch("tag_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg", &tag_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg);
  BabyTree->Branch("tag_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg", &tag_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg);
  BabyTree->Branch("tag_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg", &tag_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg);
  BabyTree->Branch("tag_HLT_Ele33_CaloIdM_TrackIdM_PFJet30_ElectronLeg"      , &tag_HLT_Ele33_CaloIdM_TrackIdM_PFJet30_ElectronLeg);
  BabyTree->Branch("tag_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_ElectronLeg"      , &tag_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_ElectronLeg);
  BabyTree->Branch("tag_HLT_Ele18_CaloIdM_TrackIdM_PFJet30_ElectronLeg"      , &tag_HLT_Ele18_CaloIdM_TrackIdM_PFJet30_ElectronLeg);
  BabyTree->Branch("tag_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_ElectronLeg"      , &tag_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_ElectronLeg);
  BabyTree->Branch("tag_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_ElectronLeg"       , &tag_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_ElectronLeg);
  BabyTree->Branch("tag_HLT_Ele27_eta2p1_WP75_Gsf"                           , &tag_HLT_Ele27_eta2p1_WP75_Gsf);
  BabyTree->Branch("tag_HLT_Ele27_WP85_Gsf"                                  , &tag_HLT_Ele27_WP85_Gsf);
  BabyTree->Branch("tag_HLT_Ele27_eta2p1_WPLoose_Gsf"                        , &tag_HLT_Ele27_eta2p1_WPLoose_Gsf);
  BabyTree->Branch("tag_HLT_Ele27_eta2p1_WPTight_Gsf"                        , &tag_HLT_Ele27_eta2p1_WPTight_Gsf);
  BabyTree->Branch("tag_HLT_Ele32_eta2p1_WP75_Gsf"                           , &tag_HLT_Ele32_eta2p1_WP75_Gsf);
  BabyTree->Branch("tag_HLT_Ele32_eta2p1_WPLoose_Gsf"                        , &tag_HLT_Ele32_eta2p1_WPLoose_Gsf);
  BabyTree->Branch("tag_HLT_Ele32_eta2p1_WPTight_Gsf"                        , &tag_HLT_Ele32_eta2p1_WPTight_Gsf);
  BabyTree->Branch("tag_HLT_Ele22_eta2p1_WPLoose_Gsf"                        , &tag_HLT_Ele22_eta2p1_WPLoose_Gsf);
  BabyTree->Branch("tag_HLT_Ele22_eta2p1_WPTight_Gsf"                        , &tag_HLT_Ele22_eta2p1_WPTight_Gsf);
  BabyTree->Branch("tag_HLT_Ele23_WPLoose_Gsf"                               , &tag_HLT_Ele23_WPLoose_Gsf);
  BabyTree->Branch("tag_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_LeadingLeg", &tag_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_LeadingLeg);
  BabyTree->Branch("tag_HLT_Ele23_CaloIdL_TrackIdL_IsoVL"                    , &tag_HLT_Ele23_CaloIdL_TrackIdL_IsoVL);
  BabyTree->Branch("tag_HLT_Ele12_CaloIdL_TrackIdL_IsoVL"                    , &tag_HLT_Ele12_CaloIdL_TrackIdL_IsoVL);
  BabyTree->Branch("probe_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg" , &probe_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg);
  BabyTree->Branch("probe_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg", &probe_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg);
  BabyTree->Branch("tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg"   , &tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg);
  BabyTree->Branch("tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg"    , &tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg);
  BabyTree->Branch("tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg"     , &tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg);
  BabyTree->Branch("tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg"      , &tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg);
  BabyTree->Branch("tag_HLT_IsoMu20"                                         , &tag_HLT_IsoMu20);
  BabyTree->Branch("tag_HLT_IsoTkMu20"                                       , &tag_HLT_IsoTkMu20);
  BabyTree->Branch("tag_HLT_IsoMu24_eta2p1"                                  , &tag_HLT_IsoMu24_eta2p1);
  BabyTree->Branch("tag_HLT_IsoTkMu24_eta2p1"                                , &tag_HLT_IsoTkMu24_eta2p1);
  BabyTree->Branch("tag_HLT_IsoMu27"                                         , &tag_HLT_IsoMu27);
  BabyTree->Branch("tag_HLT_IsoTkMu27"                                       , &tag_HLT_IsoTkMu27);
  BabyTree->Branch("probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg" , &probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg);
  BabyTree->Branch("probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg"  , &probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg);
  BabyTree->Branch("probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg"   , &probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg);
  BabyTree->Branch("probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg"    , &probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg);
  BabyTree->Branch("dilep_mass"                                              , &dilep_mass);
  BabyTree->Branch("isRandom"                                                , &isRandom);

  //Electrons
  BabyTree->Branch("sigmaIEtaIEta_full5x5", &sigmaIEtaIEta_full5x5   );
  BabyTree->Branch("sigmaIEtaIEta"        , &sigmaIEtaIEta           );
  BabyTree->Branch("etaSC"                , &etaSC                   );
  BabyTree->Branch("dEtaIn"               , &dEtaIn                  );
  BabyTree->Branch("dPhiIn"               , &dPhiIn                  );
  BabyTree->Branch("hOverE"               , &hOverE                  );
  BabyTree->Branch("eSeed"                , &eSeed                   );
  BabyTree->Branch("ecalEnergy"           , &ecalEnergy              );
  BabyTree->Branch("eOverPIn"             , &eOverPIn                );
  BabyTree->Branch("conv_vtx_flag"        , &conv_vtx_flag           );
  BabyTree->Branch("exp_innerlayers"      , &exp_innerlayers         );
  BabyTree->Branch("charge"               , &charge                  );
  BabyTree->Branch("sccharge"             , &sccharge                );
  BabyTree->Branch("ckf_charge"           , &ckf_charge              );
  BabyTree->Branch("threeChargeAgree"     , &threeChargeAgree_branch );
  BabyTree->Branch("mva"                  , &mva                     );
  BabyTree->Branch("ecalIso"              , &ecalIso                 );
  BabyTree->Branch("hcalIso"              , &hcalIso                 );
  BabyTree->Branch("ecalPFClusterIso"     , &ecalPFClusterIso        );
  BabyTree->Branch("hcalPFClusterIso"     , &hcalPFClusterIso        );
  BabyTree->Branch("ckf_laywithmeas"      , &ckf_laywithmeas         );
  BabyTree->Branch("sigmaIPhiIPhi_full5x5", &sigmaIPhiIPhi_full5x5   );
  BabyTree->Branch("e1x5_full5x5"         , &e1x5_full5x5            );
  BabyTree->Branch("e5x5_full5x5"         , &e5x5_full5x5            );
  BabyTree->Branch("r9_full5x5"           , &r9_full5x5              );
  BabyTree->Branch("etaSCwidth"           , &etaSCwidth              );
  BabyTree->Branch("phiSCwidth"           , &phiSCwidth              );
  BabyTree->Branch("eSCRaw"               , &eSCRaw                  );
  BabyTree->Branch("eSCPresh"             , &eSCPresh                );
  BabyTree->Branch("ckf_chi2"             , &ckf_chi2                );
  BabyTree->Branch("ckf_ndof"             , &ckf_ndof                );
  BabyTree->Branch("chi2"                 , &chi2                    );
  BabyTree->Branch("ndof"                 , &ndof                    );
  BabyTree->Branch("fbrem"                , &fbrem                   );
  BabyTree->Branch("eOverPOut"            , &eOverPOut               );
  BabyTree->Branch("dEtaOut"              , &dEtaOut                 );    
  BabyTree->Branch("dPhiOut"              , &dPhiOut                 );                

  //Muons
  BabyTree->Branch("pid_PFMuon"             , &pid_PFMuon);
  BabyTree->Branch("gfit_chi2"              , &gfit_chi2);
  BabyTree->Branch("gfit_ndof"              , &gfit_ndof);
  BabyTree->Branch("gfit_validSTAHits"      , &gfit_validSTAHits);
  BabyTree->Branch("numberOfMatchedStations", &numberOfMatchedStations);
  BabyTree->Branch("validPixelHits"         , &validPixelHits);
  BabyTree->Branch("nlayers"                , &nlayers);
  BabyTree->Branch("chi2LocalPosition"      , &chi2LocalPosition);
  BabyTree->Branch("trkKink"                , &trkKink);
  BabyTree->Branch("validHits"              , &validHits);
  BabyTree->Branch("lostHits"               , &lostHits);
  BabyTree->Branch("exp_outerlayers"        , &exp_outerlayers);
  BabyTree->Branch("segmCompatibility"      , &segmCompatibility);

  //Singel Muon Triggers
  BabyTree->Branch("HLT_Mu8_TrkIsoVVL"                    , &HLT_Mu8_TrkIsoVVL);
  BabyTree->Branch("HLT_Mu17_TrkIsoVVL"                   , &HLT_Mu17_TrkIsoVVL);
  BabyTree->Branch("HLT_Mu24_TrkIsoVVL"                   , &HLT_Mu24_TrkIsoVVL);
  BabyTree->Branch("HLT_Mu34_TrkIsoVVL"                   , &HLT_Mu34_TrkIsoVVL);
  BabyTree->Branch("HLT_Mu8"                              , &HLT_Mu8);
  BabyTree->Branch("HLT_Mu17"                             , &HLT_Mu17);
  BabyTree->Branch("HLT_Mu24"                             , &HLT_Mu24);
  BabyTree->Branch("HLT_Mu34"                             , &HLT_Mu34);
  BabyTree->Branch("HLT_Mu10_CentralPFJet30_BTagCSV0p5PF" , &HLT_Mu10_CentralPFJet30_BTagCSV0p5PF);
  BabyTree->Branch("HLT_IsoMu20"                          , &HLT_IsoMu20);
  BabyTree->Branch("HLT_IsoTkMu20"                        , &HLT_IsoTkMu20);
  BabyTree->Branch("HLT_Mu10_CentralPFJet30_BTagCSV0p54PF", &HLT_Mu10_CentralPFJet30_BTagCSV0p54PF);
  BabyTree->Branch("HLT_IsoMu24_eta2p1"                   , &HLT_IsoMu24_eta2p1);
  BabyTree->Branch("HLT_IsoTkMu24_eta2p1"                 , &HLT_IsoTkMu24_eta2p1);
  BabyTree->Branch("HLT_IsoMu27"                          , &HLT_IsoMu27);
  BabyTree->Branch("HLT_IsoTkMu27"                        , &HLT_IsoTkMu27);
  BabyTree->Branch("HLT_Mu45_eta2p1"                      , &HLT_Mu45_eta2p1);
  BabyTree->Branch("HLT_Mu50"                             , &HLT_Mu50);

  //Single Electron Triggers
  BabyTree->Branch("HLT_Ele8_CaloIdM_TrackIdM_PFJet30"                      , &HLT_Ele8_CaloIdM_TrackIdM_PFJet30);
  BabyTree->Branch("HLT_Ele12_CaloIdM_TrackIdM_PFJet30"                     , &HLT_Ele12_CaloIdM_TrackIdM_PFJet30);
  BabyTree->Branch("HLT_Ele18_CaloIdM_TrackIdM_PFJet30"                     , &HLT_Ele18_CaloIdM_TrackIdM_PFJet30);
  BabyTree->Branch("HLT_Ele23_CaloIdM_TrackIdM_PFJet30"                     , &HLT_Ele23_CaloIdM_TrackIdM_PFJet30);
  BabyTree->Branch("HLT_Ele33_CaloIdM_TrackIdM_PFJet30"                     , &HLT_Ele33_CaloIdM_TrackIdM_PFJet30);
  BabyTree->Branch("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30"               , &HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30);
  BabyTree->Branch("HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30"               , &HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30);
  BabyTree->Branch("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30"               , &HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30);
  BabyTree->Branch("HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30"               , &HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30);
  BabyTree->Branch("HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p5PF" , &HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p5PF);
  BabyTree->Branch("HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF", &HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF);
  BabyTree->Branch("HLT_Ele27_eta2p1_WP75_Gsf"                              , &HLT_Ele27_eta2p1_WP75_Gsf);
  BabyTree->Branch("HLT_Ele27_WP85_Gsf"                                     , &HLT_Ele27_WP85_Gsf);
  BabyTree->Branch("HLT_Ele27_eta2p1_WPLoose_Gsf"                           , &HLT_Ele27_eta2p1_WPLoose_Gsf);
  BabyTree->Branch("HLT_Ele27_eta2p1_WPTight_Gsf"                           , &HLT_Ele27_eta2p1_WPTight_Gsf);
  BabyTree->Branch("HLT_Ele32_eta2p1_WP75_Gsf"                              , &HLT_Ele32_eta2p1_WP75_Gsf);
  BabyTree->Branch("HLT_Ele32_eta2p1_WPLoose_Gsf"                           , &HLT_Ele32_eta2p1_WPLoose_Gsf);
  BabyTree->Branch("HLT_Ele32_eta2p1_WPTight_Gsf"                           , &HLT_Ele32_eta2p1_WPTight_Gsf);
  BabyTree->Branch("HLT_Ele22_eta2p1_WPLoose_Gsf"                           , &HLT_Ele22_eta2p1_WPLoose_Gsf);
  BabyTree->Branch("HLT_Ele22_eta2p1_WPTight_Gsf"                           , &HLT_Ele22_eta2p1_WPTight_Gsf);
  BabyTree->Branch("HLT_Ele23_WPLoose_Gsf"                                  , &HLT_Ele23_WPLoose_Gsf);
  BabyTree->Branch("HLT_Ele23_CaloIdL_TrackIdL_IsoVL"                       , &HLT_Ele23_CaloIdL_TrackIdL_IsoVL);
  BabyTree->Branch("HLT_Ele12_CaloIdL_TrackIdL_IsoVL"                       , &HLT_Ele12_CaloIdL_TrackIdL_IsoVL);

  //MuElectron Triggers
  BabyTree->Branch("HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300"            , &HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300);
  BabyTree->Branch("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL"        , &HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL);
  BabyTree->Branch("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL"         , &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);

  //Double Muon Triggers
  BabyTree->Branch("HLT_DoubleMu8_Mass8_PFHT300"                            , &HLT_DoubleMu8_Mass8_PFHT300);
  BabyTree->Branch("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL"                       , &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL);
  BabyTree->Branch("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL"                     , &HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL);
  BabyTree->Branch("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ"                    , &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ);
  BabyTree->Branch("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ"                  , &HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ);

  //Double Electron Triggers
  BabyTree->Branch("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300"          , &HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300);
  BabyTree->Branch("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ"              , &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
  BabyTree->Branch("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL"                 , &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL);

}

void babyMaker::InitBabyNtuple(){

  //General
  evt_pfmet = -1;
  evt_pfmetPhi = -99.;
  evt_trackmet = -1;
  evt_trackmetPhi = -99;
  evt_met3p0 = -1;
  evt_met3p0Phi = -99.;
  evt_pfsumet = -1;
  evt_pfmetSig = -1;
  evt_event = -1;
  evt_lumiBlock = -1;
  evt_run = -1;
  filt_csc = 0;
  filt_hbhe = 0;
  passes_met_filters = 0;
  filt_hcallaser = 0;
  filt_ecaltp = 0;
  filt_trkfail = 0;
  filt_eebadsc = 0;
  evt_isRealData = 0;
  scale1fb = -1;
  evt_xsec_incl = -1;
  evt_kfactor = -1;
  gen_met = -1;
  gen_metPhi = -99;
  njets = -1;
  ht = -1;
  jets.clear();
  jets_disc.clear();
  sample = "";
  nFOs_SS = -1;
  nvtx = -1;

  InitLeptonBranches();

} 

void babyMaker::InitLeptonBranches(){

  //Leptons
  p4 = LorentzVector(0,0,0,0); 
  tag_p4 = LorentzVector(0,0,0,0); 
  dilep_p4 = LorentzVector(0,0,0,0); 
  mc_p4 = LorentzVector(0,0,0,0);
  mc_motherp4 = LorentzVector(0,0,0,0);
  mc_motherid = -1;
  id = -1; 
  isPF = false; 
  idx = -1;
  dxyPV = -1;
  dZ = -1;
  dxyPV_err = -1;
  motherID = -1;
  mc_id = -1;
  RelIso03 = -1;
  RelIso03EA = -1;
  RelIso03DB = -1;
  pfChargedHadronIso = -1;
  pfPhotonIso = -1;
  pfNeutralHadronIso = -1;
  tkIso = -1;
  sumPUPt = -1;
  passes_SS_tight_v3 = 0;
  passes_SS_tight_noiso_v3 = 0;
  passes_SS_fo_v3 = 0;
  passes_SS_fo_noiso_v3 = 0;
  passes_SS_fo_looseMVA_v3 = 0;
  passes_SS_fo_looseMVA_noiso_v3 = 0;
  passes_WW_medium_v1 = 0;
  passes_WW_medium_noiso_v1 = 0;
  passes_WW_fo_v1 = 0;
  passes_WW_fo_noiso_v1 = 0;
  passes_WW_fo_looseMVA_v1 = 0;
  passes_WW_fo_looseMVA_noiso_v1 = 0;
  passes_WW_veto_v1 = 0;
  passes_WW_veto_noiso_v1 = 0;
  passes_HAD_veto_v3 = 0;
  passes_HAD_veto_noiso_v3 = 0;
  passes_HAD_loose_v3 = 0;
  passes_HAD_loose_noiso_v3 = 0;
  passes_POG_vetoID = 0;
  passes_POG_looseID = 0;
  passes_POG_mediumID = 0;
  passes_POG_tightID = 0;
  type = -1;
  ip3d = -1;
  ip3derr = -1;
  mt = -1;
  ptrelv0 = -1;
  ptrelv1 = -1;
  miniiso = -1;
  miniisoDB = -1;
  reliso04 = -1;
  annulus04 = -1;
  iso03sumPt = -1;
  iso03emEt = -1;
  iso03hadEt = -1;
  jet_close_lep = LorentzVector(0,0,0,0);
  ptratio = -1;
  dilep_mass = -1.;
  isRandom = false;

  //Tag variables
  tag_charge = 0.;
  tag_eSeed = -1;
  tag_eSCraw = -1;
  tag_HLTLeadingLeg = false;
  tag_HLT_Ele25WP60_Ele8_Mass55_LeadingLeg = 0;
  tag_HLT_Ele25WP60_SC4_Mass55_LeadingLeg = 0;
  tag_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg = 0;
  tag_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg = 0;
  tag_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg = 0;
  tag_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg = 0;
  tag_HLT_Ele33_CaloIdM_TrackIdM_PFJet30_ElectronLeg = 0;
  tag_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_ElectronLeg = 0;
  tag_HLT_Ele18_CaloIdM_TrackIdM_PFJet30_ElectronLeg = 0;
  tag_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_ElectronLeg = 0;
  tag_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_ElectronLeg = 0;
  tag_HLT_Ele27_eta2p1_WP75_Gsf = 0;
  tag_HLT_Ele27_WP85_Gsf = 0;
  tag_HLT_Ele27_eta2p1_WPLoose_Gsf = 0;
  tag_HLT_Ele27_eta2p1_WPTight_Gsf = 0;
  tag_HLT_Ele32_eta2p1_WP75_Gsf = 0;
  tag_HLT_Ele32_eta2p1_WPLoose_Gsf = 0;
  tag_HLT_Ele32_eta2p1_WPTight_Gsf = 0;
  tag_HLT_Ele22_eta2p1_WPLoose_Gsf = 0;
  tag_HLT_Ele22_eta2p1_WPTight_Gsf = 0;
  tag_HLT_Ele23_WPLoose_Gsf = 0;
  tag_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_LeadingLeg = 0;
  tag_HLT_Ele23_CaloIdL_TrackIdL_IsoVL = 0;
  tag_HLT_Ele12_CaloIdL_TrackIdL_IsoVL = 0;
  tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg = 0;
  tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg = 0;
  tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg = 0;
  tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg = 0;
  tag_HLT_IsoMu20 = 0;
  tag_HLT_IsoTkMu20 = 0;
  tag_HLT_IsoMu24_eta2p1 = 0;
  tag_HLT_IsoTkMu24_eta2p1 = 0;
  tag_HLT_IsoMu27 = 0;
  tag_HLT_IsoTkMu27 = 0;

  //Probe variables
  probe_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg = 0;
  probe_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg = 0;
  probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg = 0;
  probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg = 0;
  probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg = 0;
  probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg = 0;

  //Muons
  pid_PFMuon = -1;
  gfit_chi2 = -1;
  gfit_ndof = -1;
  gfit_validSTAHits = -1;
  numberOfMatchedStations = -1;
  validPixelHits = -1;
  nlayers = -1;
  chi2LocalPosition = -99;
  trkKink = -99;
  validHits = -99;
  lostHits = -99;
  exp_outerlayers = -99;
  segmCompatibility = -99;

  //Electrons
  sigmaIEtaIEta_full5x5 = -1;
  sigmaIEtaIEta = -1;
  etaSC = -1;
  dEtaIn = -1;
  dPhiIn = -99;
  hOverE = -1;
  eSeed = -1;
  ecalEnergy = -1;
  eOverPIn = -1;
  conv_vtx_flag = 0;
  exp_innerlayers = -1;
  charge = -1;
  sccharge = -1;
  ckf_charge = -1;
  trk_charge = -1;
  threeChargeAgree_branch = 0;
  mva = -999.;
  ecalIso = -1;
  hcalIso = -1;
  ecalPFClusterIso = -1;
  hcalPFClusterIso = -1;
  ckf_laywithmeas       = -1;
  sigmaIPhiIPhi_full5x5 = -1;
  e1x5_full5x5          = -1;
  e5x5_full5x5          = -1;
  r9_full5x5            = -1;
  etaSCwidth            = -1;
  phiSCwidth            = -1;
  eSCRaw                = -1;
  eSCPresh              = -1;
  ckf_chi2              = -1;
  ckf_ndof              = -1;
  chi2                  = -1;
  ndof                  = -1;
  fbrem                 = -1;
  eOverPOut             = -1;
  dEtaOut               = -1;
  dPhiOut               = -1;

  //Single Muon Trigger
  HLT_Mu8_TrkIsoVVL = 0;
  HLT_Mu17_TrkIsoVVL = 0;
  HLT_Mu24_TrkIsoVVL = 0;
  HLT_Mu34_TrkIsoVVL = 0;
  HLT_Mu8 = 0;
  HLT_Mu17 = 0;
  HLT_Mu24 = 0;
  HLT_Mu34 = 0;
  HLT_Mu10_CentralPFJet30_BTagCSV0p5PF = 0;
  HLT_Mu10_CentralPFJet30_BTagCSV0p54PF = 0;
  HLT_IsoMu20 = 0;
  HLT_IsoTkMu20 = 0;
  HLT_IsoMu24_eta2p1 = 0;
  HLT_IsoTkMu24_eta2p1 = 0;
  HLT_IsoMu27 = 0;
  HLT_IsoTkMu27 = 0;
  HLT_Mu45_eta2p1 = 0;
  HLT_Mu50 = 0;

  //Single Electron Trigger
  HLT_Ele8_CaloIdM_TrackIdM_PFJet30 = 0;
  HLT_Ele12_CaloIdM_TrackIdM_PFJet30 = 0;
  HLT_Ele18_CaloIdM_TrackIdM_PFJet30 = 0;
  HLT_Ele23_CaloIdM_TrackIdM_PFJet30 = 0;
  HLT_Ele33_CaloIdM_TrackIdM_PFJet30 = 0;
  HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 = 0;
  HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30 = 0;
  HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 = 0;
  HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30 = 0;
  HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p5PF = 0;
  HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF = 0;
  HLT_Ele27_eta2p1_WP75_Gsf = 0;
  HLT_Ele27_WP85_Gsf = 0;
  HLT_Ele27_eta2p1_WPLoose_Gsf = 0;
  HLT_Ele27_eta2p1_WPTight_Gsf = 0;
  HLT_Ele32_eta2p1_WP75_Gsf = 0;
  HLT_Ele32_eta2p1_WPLoose_Gsf = 0;
  HLT_Ele32_eta2p1_WPTight_Gsf = 0;
  HLT_Ele22_eta2p1_WPLoose_Gsf = 0;
  HLT_Ele22_eta2p1_WPTight_Gsf = 0;
  HLT_Ele23_WPLoose_Gsf = 0;
  HLT_Ele23_CaloIdL_TrackIdL_IsoVL = 0;
  HLT_Ele12_CaloIdL_TrackIdL_IsoVL = 0;

  //MuEl Trigger
  HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300 = 0;
  HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL = 0;
  HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL = 0;

  //Double Muon Trigger
  HLT_DoubleMu8_Mass8_PFHT300 = 0;
  HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL = 0;
  HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL = 0;
  HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ = 0;
  HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ = 0;

  //Double Electron Trigger
  HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300 = 0;
  HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = 0;
  HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL = 0;
}

bool babyMaker::checkMuonTag(unsigned int i){
  for (unsigned int j = 0; j < tas::mus_p4().size(); j++){
    if (i == j) continue;
    if (tas::mus_p4().at(j).pt() < 20.0) continue;
    if (fabs(tas::mus_p4().at(j).eta()) > 2.4) continue;
    if (fabs(tas::mus_dxyPV().at(j)) > 0.05) continue;
    if (fabs(tas::mus_dzPV().at(j)) > 0.1) continue;
    if (!isTightMuonPOG(j)) continue; 
    tag_p4 = tas::mus_p4().at(j);
    tag_charge = tas::mus_charge().at(j);
    tag_HLTLeadingLeg = false;
    if (tas::evt_isRealData()){
      tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg = tas::mus_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg().at(j);
      tag_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg  = tas::mus_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg().at(j);
      tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg   = tas::mus_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg().at(j);
      tag_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg    = tas::mus_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg().at(j);
      setHLTBranch("HLT_IsoMu20_v"         ,  tag_p4, tag_HLT_IsoMu20         );
      setHLTBranch("HLT_IsoTkMu20_v"       ,  tag_p4, tag_HLT_IsoTkMu20       );
      setHLTBranch("HLT_IsoMu24_eta2p1_v"  ,  tag_p4, tag_HLT_IsoMu24_eta2p1  );
      setHLTBranch("HLT_IsoTkMu24_eta2p1_v",  tag_p4, tag_HLT_IsoTkMu24_eta2p1);
      setHLTBranch("HLT_IsoMu27_v"         ,  tag_p4, tag_HLT_IsoMu27         );
      setHLTBranch("HLT_IsoTkMu27_v"       ,  tag_p4, tag_HLT_IsoTkMu27       );

      //Randomize if needed
      if (usedMu == false && ((rndm < 0.5 && tag_charge < 0) || (rndm >= 0.5 && tag_charge > 0))){
        isRandom = true;
        usedMu = true;
      }
      else isRandom = false;
      return true; 
    }
  }
  return false;
}

bool babyMaker::checkElectronTag(unsigned int i){
  for(unsigned int j = 0; j < tas::els_p4().size(); j++){
    if (i == j) continue;
    if (tas::els_p4().at(j).pt() < 20.0) continue;
    if (fabs(tas::els_etaSC().at(j)) > 2.5) continue;
    if (!tas::els_passTightId().at(j)) continue;
    tag_p4 = tas::els_p4().at(j);
    tag_charge = tas::els_charge().at(j); 
    tag_eSeed = tas::els_eSeed().at(j); 
    tag_eSCraw = tas::els_eSCRaw().at(j);      
    tag_HLTLeadingLeg = (tas::els_HLT_Ele17_Ele8_Mass50_LeadingLeg().at(j) > 0 || tas::els_HLT_Ele20_SC4_Mass50_LeadingLeg().at(j) > 0);

    //both data and MC triggers
    tag_HLT_Ele25WP60_Ele8_Mass55_LeadingLeg = tas::els_HLT_Ele25WP60_Ele8_Mass55_LeadingLeg().at(j);
    tag_HLT_Ele25WP60_SC4_Mass55_LeadingLeg  = tas::els_HLT_Ele25WP60_SC4_Mass55_LeadingLeg().at(j);
    setHLTBranch("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v",  tag_p4, tag_HLT_Ele23_CaloIdL_TrackIdL_IsoVL);
    setHLTBranch("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v",  tag_p4, tag_HLT_Ele12_CaloIdL_TrackIdL_IsoVL);

    //only data triggers
    if (tas::evt_isRealData()){
      tag_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_LeadingLeg = tas::els_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg().at(j);
      tag_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg = tas::els_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg().at(j);      
      tag_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg = tas::els_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg().at(j);
      tag_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg = tas::els_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg().at(j);
      tag_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg = tas::els_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg().at(j);
      tag_HLT_Ele33_CaloIdM_TrackIdM_PFJet30_ElectronLeg = tas::els_HLT_Ele33_CaloIdM_TrackIdM_PFJet30_ElectronLeg().at(j);
      tag_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_ElectronLeg = tas::els_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_ElectronLeg().at(j);
      tag_HLT_Ele18_CaloIdM_TrackIdM_PFJet30_ElectronLeg = tas::els_HLT_Ele18_CaloIdM_TrackIdM_PFJet30_ElectronLeg().at(j);
      tag_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_ElectronLeg = tas::els_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_ElectronLeg().at(j);
      tag_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_ElectronLeg = tas::els_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_ElectronLeg().at(j);
      setHLTBranch("HLT_Ele27_eta2p1_WPLoose_Gsf_v",  tag_p4, tag_HLT_Ele27_eta2p1_WPLoose_Gsf);
      setHLTBranch("HLT_Ele27_eta2p1_WPTight_Gsf_v",  tag_p4, tag_HLT_Ele27_eta2p1_WPTight_Gsf);
      setHLTBranch("HLT_Ele32_eta2p1_WPLoose_Gsf_v",  tag_p4, tag_HLT_Ele32_eta2p1_WPLoose_Gsf);
      setHLTBranch("HLT_Ele32_eta2p1_WPTight_Gsf_v",  tag_p4, tag_HLT_Ele32_eta2p1_WPTight_Gsf);
      setHLTBranch("HLT_Ele22_eta2p1_WPLoose_Gsf_v",  tag_p4, tag_HLT_Ele22_eta2p1_WPLoose_Gsf);
      setHLTBranch("HLT_Ele22_eta2p1_WPTight_Gsf_v",  tag_p4, tag_HLT_Ele22_eta2p1_WPTight_Gsf);
      setHLTBranch("HLT_Ele23_WPLoose_Gsf_v",  tag_p4, tag_HLT_Ele23_WPLoose_Gsf);	
    }    

    //only MC triggers
    if(!(tas::evt_isRealData())){
      setHLTBranch("HLT_Ele27_eta2p1_WP75_Gsf_v",  tag_p4, tag_HLT_Ele27_eta2p1_WP75_Gsf);
      setHLTBranch("HLT_Ele27_WP85_Gsf_v"       ,  tag_p4, tag_HLT_Ele27_WP85_Gsf       );
      setHLTBranch("HLT_Ele32_eta2p1_WP75_Gsf_v",  tag_p4, tag_HLT_Ele32_eta2p1_WP75_Gsf);
    }

    // Randomize if needed
    if (usedEl == false && ((rndm < 0.5 && tag_charge < 0) || (rndm >= 0.5 && tag_charge > 0))){
      isRandom = true;
      usedEl = true;
    }
    else isRandom = false;
    return true;
  }
  return false;
}

bool isPFmuon(vector<LorentzVector> &pfP4, vector<bool> &pfmuIsReco, int idx){
  for(size_t i = 0; i < pfP4.size(); i++) {
    float dR2 = ROOT::Math::VectorUtil::DeltaR2(pfP4[i], tas::mus_p4().at(idx));
    if (dR2 < 0.0025) {
      pfmuIsReco[i] = true;
      return true;
    }
  }
  return false;
}

bool isPFelectron(vector<LorentzVector> &pfP4, vector<bool> &pfelIsReco, int idx){
  for(size_t i = 0; i < pfP4.size(); i++){
    float dR2 = ROOT::Math::VectorUtil::DeltaR2(pfP4[i], tas::els_p4().at(idx));
    if (dR2 < 0.0025){
      pfelIsReco[i] = true;
      return true;
    }
  }
  return false;
}

void babyMaker::fillElectronTriggerBranches(LorentzVector &p4, int idx){

  //Single Electron Trigger
  setHLTBranch("HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v" ,  (idx>=0 ? tas::els_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_ElectronLeg().at(idx)  : 0), HLT_Ele8_CaloIdM_TrackIdM_PFJet30 );
  setHLTBranch("HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v",  (idx>=0 ? tas::els_HLT_Ele12_CaloIdM_TrackIdM_PFJet30_ElectronLeg().at(idx) : 0), HLT_Ele12_CaloIdM_TrackIdM_PFJet30);
  setHLTBranch("HLT_Ele18_CaloIdM_TrackIdM_PFJet30_v",  (idx>=0 ? tas::els_HLT_Ele18_CaloIdM_TrackIdM_PFJet30_ElectronLeg().at(idx) : 0), HLT_Ele18_CaloIdM_TrackIdM_PFJet30);
  setHLTBranch("HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v",  (idx>=0 ? tas::els_HLT_Ele23_CaloIdM_TrackIdM_PFJet30_ElectronLeg().at(idx) : 0), HLT_Ele23_CaloIdM_TrackIdM_PFJet30);
  setHLTBranch("HLT_Ele33_CaloIdM_TrackIdM_PFJet30_v",  (idx>=0 ? tas::els_HLT_Ele33_CaloIdM_TrackIdM_PFJet30_ElectronLeg().at(idx) : 0), HLT_Ele33_CaloIdM_TrackIdM_PFJet30);
  setHLTBranch("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v",  (idx>=0 ? tas::els_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg().at(idx) : 0), HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30);
  setHLTBranch("HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v",  (idx>=0 ? tas::els_HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg().at(idx) : 0), HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30);
  setHLTBranch("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v",  (idx>=0 ? tas::els_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg().at(idx) : 0), HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30);
  setHLTBranch("HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v",  (idx>=0 ? tas::els_HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg().at(idx) : 0), HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30);
  if (tas::evt_isRealData()) setHLTBranch("HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_v",  (idx>=0 ? tas::els_HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF_ElectronLeg().at(idx) : 0), HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p54PF);
  else setHLTBranch("HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p5PF_v",  (idx>=0 ? tas::els_HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p5PF_ElectronLeg().at(idx) : 0), HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV0p5PF);
  if (!(tas::evt_isRealData())) setHLTBranch("HLT_Ele27_eta2p1_WP75_Gsf_v",  p4, HLT_Ele27_eta2p1_WP75_Gsf);
  if (!(tas::evt_isRealData())) setHLTBranch("HLT_Ele27_WP85_Gsf_v",  p4, HLT_Ele27_WP85_Gsf);
  if (tas::evt_isRealData()) setHLTBranch("HLT_Ele27_eta2p1_WPLoose_Gsf_v",  p4, HLT_Ele27_eta2p1_WPLoose_Gsf);
  if (tas::evt_isRealData()) setHLTBranch("HLT_Ele27_eta2p1_WPTight_Gsf_v",  p4, HLT_Ele27_eta2p1_WPTight_Gsf);
  if (!(tas::evt_isRealData())) setHLTBranch("HLT_Ele32_eta2p1_WP75_Gsf_v",  p4, HLT_Ele32_eta2p1_WP75_Gsf);
  if (tas::evt_isRealData()) setHLTBranch("HLT_Ele32_eta2p1_WPLoose_Gsf_v",  p4, HLT_Ele32_eta2p1_WPLoose_Gsf);
  if (tas::evt_isRealData()) setHLTBranch("HLT_Ele32_eta2p1_WPTight_Gsf_v",  p4, HLT_Ele32_eta2p1_WPTight_Gsf);
  if (tas::evt_isRealData()) setHLTBranch("HLT_Ele22_eta2p1_WPLoose_Gsf_v",  p4, HLT_Ele22_eta2p1_WPLoose_Gsf);
  if (tas::evt_isRealData()) setHLTBranch("HLT_Ele22_eta2p1_WPTight_Gsf_v",  p4, HLT_Ele22_eta2p1_WPTight_Gsf);
  if (tas::evt_isRealData()) setHLTBranch("HLT_Ele23_WPLoose_Gsf_v",  p4, HLT_Ele23_WPLoose_Gsf);
  setHLTBranch("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v",  p4, HLT_Ele23_CaloIdL_TrackIdL_IsoVL);
  setHLTBranch("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v",  p4, HLT_Ele12_CaloIdL_TrackIdL_IsoVL);
  probe_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg =  (idx>=0 ? tas::els_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg().at(idx) : 0);
  probe_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg =  (idx>=0 ? tas::els_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg().at(idx) : 0);

  //MuElectron Triggers
  setHLTBranch("HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v",     (idx>=0 ? tas::els_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_ElectronLeg().at(idx) : 0)    , HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300);
  setHLTBranch("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v", (idx>=0 ? tas::els_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_ElectronLeg().at(idx) : 0), HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL);
  setHLTBranch("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v",  (idx>=0 ? tas::els_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_ElectronLeg().at(idx) : 0) , HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);

  //Double Electron Trigger
  setHLTBranch("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v",  (idx>=0 ? tas::els_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_ElectronLeg().at(idx) : 0), HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300);
  setHLTBranch("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v",  p4, HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
  setHLTBranch("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v",  p4, HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL);

}

void babyMaker::fillMuonTriggerBranches(LorentzVector &p4, int idx) {

  //temporary until we run on mc with the new tag
  if (tas::evt_isRealData()==0) idx = -1;

  //Single Muon Triggers
  setHLTBranch("HLT_Mu8_v"             , p4, HLT_Mu8             );
  setHLTBranch("HLT_Mu17_v"            , p4, HLT_Mu17            );
  setHLTBranch("HLT_Mu24_v"            , p4, HLT_Mu24            );
  setHLTBranch("HLT_Mu34_v"            , p4, HLT_Mu34            );
  setHLTBranch("HLT_Mu8_TrkIsoVVL_v"   , p4, HLT_Mu8_TrkIsoVVL   );
  setHLTBranch("HLT_Mu17_TrkIsoVVL_v"  , p4, HLT_Mu17_TrkIsoVVL  );
  setHLTBranch("HLT_Mu24_TrkIsoVVL_v"  , p4, HLT_Mu24_TrkIsoVVL  );
  setHLTBranch("HLT_Mu34_TrkIsoVVL_v"  , p4, HLT_Mu34_TrkIsoVVL  );
  setHLTBranch("HLT_IsoMu20_v"         , p4, HLT_IsoMu20         );
  setHLTBranch("HLT_IsoTkMu20_v"       , p4, HLT_IsoTkMu20       );
  setHLTBranch("HLT_IsoMu24_eta2p1_v"  , p4, HLT_IsoMu24_eta2p1  );
  setHLTBranch("HLT_IsoTkMu24_eta2p1_v", p4, HLT_IsoTkMu24_eta2p1);
  setHLTBranch("HLT_IsoMu27_v"         , p4, HLT_IsoMu27         );
  setHLTBranch("HLT_IsoTkMu27_v"       , p4, HLT_IsoTkMu27       );
  setHLTBranch("HLT_Mu45_eta2p1_v"     , p4, HLT_Mu45_eta2p1     );
  setHLTBranch("HLT_Mu50_v"            , p4, HLT_Mu50            );
  if (tas::evt_isRealData()) setHLTBranch("HLT_Mu10_CentralPFJet30_BTagCSV0p54PF_v", (idx>=0 ? tas::mus_HLT_Mu10_CentralPFJet30_BTagCSV0p54PF_MuonLeg().at(idx) : 0), HLT_Mu10_CentralPFJet30_BTagCSV0p54PF);
  else setHLTBranch("HLT_Mu10_CentralPFJet30_BTagCSV0p5PF_v", (idx>=0 ? tas::mus_HLT_Mu10_CentralPFJet30_BTagCSV0p5PF_MuonLeg().at(idx) : 0), HLT_Mu10_CentralPFJet30_BTagCSV0p5PF);

  //MuElectron Trigger
  setHLTBranch("HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_v"    , (idx>=0 ? tas::mus_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300_MuonLeg().at(idx)     : 0), HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300);
  setHLTBranch("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v", (idx>=0 ? tas::mus_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_MuonLeg().at(idx) : 0), HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL);
  setHLTBranch("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v" , (idx>=0 ? tas::mus_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_MuonLeg().at(idx)  : 0), HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);

  //Double Muon Trigger
  setHLTBranch("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v"     , p4, HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL     );
  setHLTBranch("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v"   , p4, HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL   );
  setHLTBranch("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v"  , p4, HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ  );
  setHLTBranch("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v", p4, HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ);
  setHLTBranch("HLT_DoubleMu8_Mass8_PFHT300_v",  (idx>=0 ? tas::mus_HLT_DoubleMu8_Mass8_PFHT300_MuonLeg().at(idx) : 0), HLT_DoubleMu8_Mass8_PFHT300);

}

//Main function
int babyMaker::looper(TChain* chain, char* output_name, int nEvents){

  //Print warning!
  cout << "Careful!! Path is " << path << endl;

  //Create and init MVA
  createAndInitMVA("CORE");

  //Add good run list
  set_goodrun_file("goodRunList/json_Golden_246908-251883_snt.txt");

  //Make Baby Ntuple  
  MakeBabyNtuple( Form("%s.root", output_name) );

  //Initialize Baby Ntuple
  InitBabyNtuple();

  //Set up loop over chain
  unsigned int nEventsDone = 0;
  unsigned int nEventsToDo = chain->GetEntries();
  if(nEvents >= 0) nEventsToDo = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) { 

    // Get File Content
    if(nEventsDone >= nEventsToDo) continue;
    TFile *file = new TFile( currentFile->GetTitle() );
    TTree *tree = (TTree*)file->Get("Events");
    cms3.Init(tree);

    // Loop over Events in current file
    unsigned int nEventsTree = tree->GetEntriesFast();
    for(unsigned int evt = 0; evt < nEventsTree; evt++){

      // Get Event Content
      if(nEventsDone >= nEventsToDo) continue;   
      cms3.GetEntry(evt);
      nEventsDone++;

      //If data, check good run list
      if (tas::evt_isRealData() && !goodrun(tas::evt_run(), tas::evt_lumiBlock())) continue; 

      //Initialize variables
      InitBabyNtuple();

      // Progress
      CMS3::progress(nEventsDone, nEventsToDo);

      //Debug mode
      if (verbose && tas::evt_event() != evt_cut) continue;
      if (verbose) cout << "file name is " << file->GetName() << endl;

      //Preliminary stuff
      if (tas::mus_dxyPV().size() != tas::mus_dzPV().size()) continue;  

      //MET variables
      metStruct trackMetStruct =  trackerMET(0.2);
      pair<float,float> met3p0Pair = MET3p0();

      //Fill Easy Variables
      evt_pfmet      = cms3.evt_pfmet();
      evt_pfmetPhi   = cms3.evt_pfmetPhi();
      evt_trackmet   = trackMetStruct.met;
      evt_trackmetPhi= trackMetStruct.metphi;
      evt_met3p0     = met3p0Pair.first;
      evt_met3p0Phi  = met3p0Pair.second;
      evt_pfsumet    = cms3.evt_pfsumet();
      evt_pfmetSig   = cms3.evt_pfmetSig();
      evt_event      = tas::evt_event();
      evt_lumiBlock  = tas::evt_lumiBlock();
      evt_run        = tas::evt_run();
      evt_isRealData = tas::evt_isRealData();
      sample         = Form("%s", file->GetName());
      if (!evt_isRealData){
        evt_xsec_incl = tas::evt_xsec_incl();
        evt_kfactor   = tas::evt_kfactor();
        gen_met       = tas::gen_met();
        gen_metPhi    = tas::gen_metPhi();
      }

      // Vertex selection:
      nvtx = 0;
      for(unsigned int ivtx=0; ivtx < tas::evt_nvtxs(); ivtx++){
        if (!isGoodVertex(ivtx)) continue;
        nvtx++;
      }

      //Fill data vs. mc variables
      passes_met_filters = evt_isRealData ? passesMETfilter()           : 1;
      filt_hbhe          = evt_isRealData ? hbheNoiseFilter()           : 1;
      filt_csc           = evt_isRealData ? tas::evt_cscTightHaloId()   : 1;
      filt_hcallaser     = evt_isRealData ? tas::filt_hcalLaser()       : 1;
      filt_ecaltp        = evt_isRealData ? tas::filt_ecalTP()          : 1;
      filt_trkfail       = evt_isRealData ? tas::filt_trackingFailure() : 1;
      filt_eebadsc       = evt_isRealData ? tas::filt_eeBadSc()         : 1;
      scale1fb           = evt_isRealData ? 1                           : tas::evt_scale1fb();

      //Determine and save jet variables
      ht = 0;
      for (unsigned int i = 0; i < tas::pfjets_p4().size(); i++){
        LorentzVector jet = tas::pfjets_p4().at(i);

        //Require loose jet ID
        if (!isLoosePFJet(i)) continue;

        //Kinematic jet cuts
        if (jet.pt() < 25) continue;

        //Verbose
        if (verbose) cout << "Possible jet with pT: " << jet.pt() << endl;

        //Save jets that make it this far
        jets.push_back(jet);

        //HT is sum of jets with pT > 40
        if(jet.pt() > 40) ht += jet.pt();

        //Save b-tags
        float disc = tas::pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag().at(i);  
        jets_disc.push_back(disc);

      }

      //Calculate number of fakeable objects
      nFOs_SS = 0; 
      for(size_t j = 0; j < tas::mus_p4().size(); j++){
        if(muonID(j, SS_fo_v3) && tas::mus_p4().at(j).pt() > 10) nFOs_SS++;
      }
      for(size_t j = 0; j < tas::els_p4().size(); j++){
        if( electronID(j, SS_fo_looseMVA_v3) && tas::els_p4().at(j).pt() > 10) nFOs_SS++;
      }

      //These variables are persistent through the event, used for PFlepton saving
      bool foundMuTag = false;
      bool foundElTag = false;

      // Variables to keep track of PFElectrons and PFMuons
      // We would like to save PFleptons if they don't overlap with something we've already saved.
      // If they do overlap, we want to save the fact that they overlap
      // Load the pflepton p4s in memory, we'll have to check them on each lepton
      vector<LorentzVector> savedMuP4s; savedMuP4s.clear();
      vector<LorentzVector> savedElP4s; savedElP4s.clear();
      vector<int> pfelidx; pfelidx.clear();
      vector<int> pfmuidx; pfmuidx.clear();
      vector<bool> pfelIsReco; pfelIsReco.clear();
      vector<bool> pfmuIsReco; pfmuIsReco.clear();
      vector<LorentzVector> pfelP4; pfelP4.clear();
      vector<LorentzVector> pfmuP4; pfmuP4.clear();
      for(unsigned int i=0; i<tas::isotracks_p4().size(); i++){
        if (fabs(tas::isotracks_particleId().at(i)) != 11 && fabs(tas::isotracks_particleId().at(i)) != 13 ) continue;
        if (fabs(tas::isotracks_particleId().at(i)) == 11){
          pfelidx.push_back(i);
          pfelP4.push_back(tas::isotracks_p4().at(i));
          pfelIsReco.push_back(false); 
        }
        else if (fabs(tas::isotracks_particleId().at(i)) == 13){
          pfmuidx.push_back(i);
          pfmuP4.push_back(tas::isotracks_p4().at(i));
          pfmuIsReco.push_back(false); 
        }
        continue;
      }

      usedMu = false;
      usedEl = false;
      TRandom r;
      rndm = r.Rndm();
      //Muon Loop -- we loop over the probes
      for(unsigned int i=0; i<tas::mus_p4().size(); i++){
        InitLeptonBranches(); 

        //Check for a tag
        bool foundTag = checkMuonTag(i);
        if (foundTag) foundMuTag = true; 

        // Require pT > 10 GeV
        if (tas::mus_p4().at(i).pt()<=10.) continue; 

        //Save the muon if we have a tag OR if it passes loose ID 
        if(muonID(i, SS_veto_noiso_v3)==0 && muonID(i, HAD_loose_v3)==0 && foundTag==false) continue; 

        //check to which leg a match has been found
        if (tas::evt_isRealData()){
          probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg       = tas::mus_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg().at(i);
          probe_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg        = tas::mus_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg().at(i);
          probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg         = tas::mus_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg().at(i);
          probe_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg          = tas::mus_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg().at(i);
        }

        //ID & Index for muons
        id = -13.0*tas::mus_charge().at(i);
        idx = i;  

        //p4 for muon
        p4 = tas::mus_p4().at(i); 
        savedMuP4s.push_back(p4);

        //Dilepton stuff
        if (foundTag) {
          dilep_p4 = p4 + tag_p4;
          dilep_mass = dilep_p4.M();
        }

        //MC stuff
        if (!evt_isRealData){
          motherID = lepMotherID(Lep(id, idx));
          mc_motherp4 = tas::mus_mc_motherp4().at(i);
          mc_p4 = tas::mus_mc_p4().at(i);
          mc_motherid = tas::mus_mc_motherid().at(i);
          mc_id = tas::mus_mc_id().at(i);
        }

        //Impact parameter
        dxyPV = abs(id) == 11 ? tas::els_dxyPV().at(i) : tas::mus_dxyPV().at(i); 
        dxyPV_err = abs(id) == 11 ? tas::els_d0Err().at(i) : tas::mus_d0Err().at(i); 
        dZ = abs(id) == 11 ? tas::els_dzPV().at(i) : tas::mus_dzPV().at(i);
        ip3d = tas::mus_ip3d().at(i);
        ip3derr = tas::mus_ip3derr().at(i);

        //Isolation et al
        RelIso03 = (tas::mus_isoR03_pf_ChargedHadronPt().at(i)+tas::mus_isoR03_pf_NeutralHadronEt().at(i)+tas::mus_isoR03_pf_PhotonEt().at(i))/tas::mus_p4().at(i).pt();
        RelIso03EA = muRelIso03EA(i);
        RelIso03DB = muRelIso03DB(i);
        pfChargedHadronIso = tas::mus_isoR03_pf_ChargedHadronPt().at(i);
        pfPhotonIso = tas::mus_isoR03_pf_PhotonEt().at(i);
        pfNeutralHadronIso = tas::mus_isoR03_pf_NeutralHadronEt().at(i);
        tkIso = tas::mus_iso03_sumPt().at(i);
        sumPUPt = tas::mus_isoR03_pf_PUPt().at(i);
        iso03sumPt = tas::mus_iso03_sumPt().at(i);
        iso03emEt  = tas::mus_iso03_emEt().at(i);
        iso03hadEt = tas::mus_iso03_hadEt().at(i);
        ptrelv0 = getPtRel(id, idx, false);
        ptrelv1 = getPtRel(id, idx, true);
        miniiso = muMiniRelIsoCMS3_EA(idx);
        miniisoDB = muMiniRelIsoCMS3_DB(idx);
        jet_close_lep = closestJet(p4,0.4,2.4);
        ptratio = jet_close_lep.pt() > 0 ? p4.pt()/jet_close_lep.pt() : 1; 

        //MT
        mt = MT(p4.pt(), p4.phi(), evt_pfmet, evt_pfmetPhi);

        //Other muon Id
        pid_PFMuon = tas::mus_pid_PFMuon().at(i);
        gfit_chi2 = tas::mus_gfit_chi2().at(i);
        gfit_ndof = tas::mus_gfit_ndof().at(i);
        gfit_validSTAHits = tas::mus_gfit_validSTAHits().at(i);
        numberOfMatchedStations = tas::mus_numberOfMatchedStations().at(i);
        validPixelHits = tas::mus_validPixelHits().at(i);
        nlayers = tas::mus_nlayers().at(i);
        type = tas::mus_type().at(i);
        chi2LocalPosition = tas::mus_chi2LocalPosition().at(i);
        trkKink = tas::mus_trkKink().at(i);
        validHits = tas::mus_validHits().at(i);
        lostHits = tas::mus_lostHits().at(i);
        exp_innerlayers = tas::mus_exp_innerlayers().at(i);
        exp_outerlayers = tas::mus_exp_outerlayers().at(i);
        segmCompatibility = tas::mus_segmCompatibility().at(i);
        if (!doFast){
          reliso04 = muRelIsoCustomCone(idx, 0.4, true, 0.5, false, true);
          annulus04 = reliso04 - miniiso;
          isPF = isPFmuon(pfmuP4, pfmuIsReco, i);
        }

        muID::setCache(idx,miniiso,ptratio,ptrelv1);

        //Save SS ID bools
        if(muonID(i, SS_tight_v3))              passes_SS_tight_v3 = true;
        if(muonID(i, SS_tight_noiso_v3))        passes_SS_tight_noiso_v3 = true;
        if(muonID(i, SS_fo_v3))                 passes_SS_fo_v3 = true;
        if(muonID(i, SS_fo_noiso_v3))           passes_SS_fo_noiso_v3 = true;

        //Save WW ID bools
        if(muonID(i, WW_medium_v1))             passes_WW_medium_v1 = true;
        if(muonID(i, WW_medium_noiso_v1))       passes_WW_medium_noiso_v1 = true;
        if(muonID(i, WW_fo_v1))                 passes_WW_fo_v1 = true;
        if(muonID(i, WW_fo_noiso_v1))           passes_WW_fo_noiso_v1 = true;
        if(muonID(i, WW_veto_v1))               passes_WW_veto_v1 = true;
        if(muonID(i, WW_veto_noiso_v1))         passes_WW_veto_noiso_v1 = true;

        //Save HAD ID bools
        if(muonID(i, HAD_loose_v3))              passes_HAD_loose_v3 = true;
        if(muonID(i, HAD_loose_noiso_v3))        passes_HAD_loose_noiso_v3 = true;

        //Save POG ID bools
        if( isLooseMuonPOG(i) )                  passes_POG_looseID = true;
        if( isMediumMuonPOG(i) )                 passes_POG_mediumID = true;
        if( isTightMuonPOG(i) )                  passes_POG_tightID = true;

        muID::unsetCache();

        //Fill trigger branches
        fillMuonTriggerBranches(p4,idx);

        //Fill baby once per probe
        BabyTree->Fill(); 

      } //close muon loop

      //Electron Loop
      for(unsigned int i=0; i<tas::els_p4().size(); i++){

        InitLeptonBranches(); 

        //Check for a tag
        bool foundTag = checkElectronTag(i);
        if (foundTag) foundElTag = true; 

        // Require pT > 10 GeV
        if (tas::els_p4().at(i).pt() <= 10) continue; 

        //Save the muon if we have a tag OR if it passes loose ID 
        if(electronID(i, SS_veto_noiso_v3)==0 && electronID(i, HAD_veto_v3)==0 && foundTag==false) continue; 

        //p4
        p4 = tas::els_p4().at(i);    
        savedElP4s.push_back(p4);

        //Dilepton stuff
        if (foundTag){
          dilep_p4 = p4 + tag_p4;
          dilep_mass = dilep_p4.M();
        }

        //ID & idx stuff
        id = -11.0*tas::els_charge().at(i); 
        idx = i;
  
        //MC Stuff
        if (!evt_isRealData){
          mc_p4 = tas::els_mc_p4().at(i);  
          mc_id = tas::els_mc_id().at(i);  
        }

        //Impact Parameter
        dxyPV = abs(id) == 11 ? tas::els_dxyPV().at(i) : tas::mus_dxyPV().at(i); 
        dxyPV_err = abs(id) == 11 ? tas::els_d0Err().at(i) : tas::mus_d0Err().at(i); 
        dZ = abs(id) == 11 ? tas::els_dzPV().at(i) : tas::mus_dzPV().at(i);
        ip3d = tas::els_ip3d().at(i);
        ip3derr = tas::els_ip3derr().at(i);

        //Isolation et al
        RelIso03 = (tas::els_pfChargedHadronIso().at(i)+tas::els_pfNeutralHadronIso().at(i)+tas::els_pfPhotonIso().at(i))/tas::els_p4().at(i).pt();
        RelIso03EA = eleRelIso03EA(i);
        RelIso03DB = eleRelIso03DB(i);
        pfChargedHadronIso = tas::els_pfChargedHadronIso().at(i);
        pfPhotonIso = tas::els_pfPhotonIso().at(i);
        pfNeutralHadronIso = tas::els_pfNeutralHadronIso().at(i);
        tkIso = tas::els_tkIso().at(i);
        ptrelv0 = getPtRel(id, idx, false);
        ptrelv1 = getPtRel(id, idx, true);
        jet_close_lep = closestJet(p4,0.4,2.4);
        ptratio = ( jet_close_lep.pt()>0. ? p4.pt()/jet_close_lep.pt() : 1. ); 
        miniiso = elMiniRelIsoCMS3_EA(idx);
        miniisoDB = elMiniRelIsoCMS3_DB(idx);

        //MT
        mt = MT(p4.pt(), p4.phi(), evt_pfmet, evt_pfmetPhi); 

        //Other Electron ID stuff
        sumPUPt = tas::els_pfPUIso().at(i);
        sigmaIEtaIEta_full5x5 = tas::els_sigmaIEtaIEta_full5x5().at(i);
        etaSC = tas::els_etaSC().at(i);
        dEtaIn = tas::els_dEtaIn().at(i);
        dPhiIn = tas::els_dPhiIn().at(i);
        hOverE = tas::els_hOverE().at(i);
        ecalEnergy = tas::els_ecalEnergy().at(i);
        eOverPIn = tas::els_eOverPIn().at(i);
        conv_vtx_flag = tas::els_conv_vtx_flag().at(i);
        exp_innerlayers = tas::els_exp_innerlayers().at(i);
        exp_outerlayers = tas::els_exp_outerlayers().at(i);
        charge = tas::els_charge().at(i);    
        sccharge = tas::els_sccharge().at(i);
        ckf_charge = tas::els_ckf_charge().at(i);
        trk_charge = tas::els_trk_charge().at(i);
        threeChargeAgree_branch = threeChargeAgree(i);
        mva = getMVAoutput(i); 
        type = tas::els_type().at(i);
        ecalIso = tas::els_ecalIso().at(i);
        hcalIso = tas::els_hcalIso().at(i);
        sigmaIEtaIEta = tas::els_sigmaIEtaIEta().at(i);
        ecalPFClusterIso = tas::els_ecalPFClusterIso().at(i);
        hcalPFClusterIso = tas::els_hcalPFClusterIso().at(i);
        ckf_laywithmeas        = tas::els_ckf_laywithmeas().at(i);
        sigmaIPhiIPhi_full5x5  = tas::els_sigmaIPhiIPhi_full5x5().at(i);
        e1x5_full5x5           = tas::els_e1x5_full5x5().at(i);
        e5x5_full5x5           = tas::els_e5x5_full5x5().at(i);
        r9_full5x5             = tas::els_r9_full5x5().at(i);
        etaSCwidth             = tas::els_etaSCwidth().at(i);
        phiSCwidth             = tas::els_phiSCwidth().at(i);
        eSeed                  = tas::els_eSeed().at(i);
        eSCRaw                 = tas::els_eSCRaw().at(i);
        eSCPresh               = tas::els_eSCPresh().at(i);
        ckf_chi2               = tas::els_ckf_chi2().at(i);
        ckf_ndof               = tas::els_ckf_ndof().at(i);
        chi2                   = tas::els_chi2().at(i);
        ndof                   = tas::els_ndof().at(i);
        fbrem                  = tas::els_fbrem().at(i);
        eOverPOut              = tas::els_eOverPOut().at(i);
        dEtaOut                = tas::els_dEtaOut().at(i);
        dPhiOut                = tas::els_dPhiOut().at(i);

        if (!doFast){
          reliso04 = elRelIsoCustomCone(idx, 0.4, true, 0.0, false, true);
          isPF = isPFelectron(pfelP4, pfelIsReco, i);		  
          annulus04 = reliso04 - miniiso;
        }

        elID::setCache(idx,mva,miniiso,ptratio,ptrelv1);

        //Save SS ID bools
        if(electronID(i, SS_medium_v3))             passes_SS_tight_v3 = true;
        if(electronID(i, SS_medium_noiso_v3))       passes_SS_tight_noiso_v3 = true;
        if(electronID(i, SS_fo_v3))                 passes_SS_fo_v3 = true;
        if(electronID(i, SS_fo_noiso_v3))           passes_SS_fo_noiso_v3 = true;
        if(electronID(i, SS_fo_looseMVA_v3))        passes_SS_fo_looseMVA_v3 = true;
        if(electronID(i, SS_fo_looseMVA_noiso_v3))  passes_SS_fo_looseMVA_noiso_v3 = true;

        //Save WW ID bools
        if(electronID(i, WW_medium_v1))             passes_WW_medium_v1 = true;
        if(electronID(i, WW_medium_noiso_v1))       passes_WW_medium_noiso_v1 = true;
        if(electronID(i, WW_fo_v1))                 passes_WW_fo_v1 = true;
        if(electronID(i, WW_fo_noiso_v1))           passes_WW_fo_noiso_v1 = true;
        if(electronID(i, WW_fo_looseMVA_v1))        passes_WW_fo_looseMVA_v1 = true;
        if(electronID(i, WW_fo_looseMVA_noiso_v1))  passes_WW_fo_looseMVA_noiso_v1 = true;
        if(electronID(i, WW_veto_v1))               passes_WW_veto_v1 = true;
        if(electronID(i, WW_veto_noiso_v1))         passes_WW_veto_noiso_v1 = true;
    
        //Save HAD ID bools
        if(electronID(i, HAD_veto_v3))              passes_HAD_veto_v3 = true;
        if(electronID(i, HAD_veto_noiso_v3))        passes_HAD_veto_noiso_v3 = true;

        //Save POG ID bools
        if( tas::els_passVetoId().at(i) )           passes_POG_vetoID = true;
        if( tas::els_passLooseId().at(i) )          passes_POG_looseID = true;
        if( tas::els_passMediumId().at(i) )         passes_POG_mediumID = true;
        if( tas::els_passTightId().at(i) )          passes_POG_tightID = true;

        elID::unsetCache();

        if (!evt_isRealData ) {
          motherID = lepMotherID(Lep(id, idx));
          mc_motherp4 = tas::els_mc_motherp4().at(i); 
          mc_motherid = tas::els_mc_motherid().at(i); 
        }
  
        //Triggers
        fillElectronTriggerBranches(p4, idx);
    
        //Fill tree once per tag
        BabyTree->Fill(); 

      }

      ////////// Addition of PF LEPTONS that were not included before //////////////////
      // check if anything needs to be done: 
      //    - compare size of pfelp4 with probeelp4, and same for muons
      //    - check whether there is a muon/electron tag
      // if something to be done, then we need to save the pflepton as well as tag properties and triggers...

      bool addPFel = false;
      bool addPFmu = false;
      if ( foundElTag && savedElP4s.size() != pfelP4.size() ) addPFel = true;
      if ( foundMuTag && savedMuP4s.size() != pfmuP4.size() ) addPFmu = true;

      if ( addPFel && !doFast ) {
        for (unsigned int i=0; i<pfelP4.size(); i++) {
          if (pfelIsReco[i]) continue;
          InitLeptonBranches(); 
          // set the tag branches (-1 means we are happy if any reco electron is a tag)
          checkElectronTag( -1 );
          // now let's look at our electron
          int pfidx = pfelidx[i];
          p4 = pfelP4[i];
          id = tas::isotracks_particleId().at(pfidx);
          isPF = true; // that's why we're here!
          if (id > 0) id = 1011; 
          else id = -1011;
          dZ = abs(id) == 11 ? tas::els_dzPV().at(i) : tas::mus_dzPV().at(i);
          charge = tas::isotracks_charge().at(pfidx);
          RelIso03 = tas::isotracks_relIso().at(pfidx);

          dilep_p4 = p4 + tag_p4;
          dilep_mass = dilep_p4.M();

          fillElectronTriggerBranches(p4,-1);

          BabyTree->Fill(); 
        }
      } // addPFel

      if (addPFmu && !doFast){
        for (unsigned int i=0; i<pfmuP4.size(); i++) {
          if (pfmuIsReco[i]) continue;
          InitLeptonBranches(); 
          // set the tag branches (-1 means we are happy if any reco electron is a tag)
          checkMuonTag( -1 );
          // now let's look at our electron
          int pfidx = pfmuidx[i];
          p4 = pfmuP4[i];
          id = tas::isotracks_particleId().at(pfidx);
          isPF = true; // that's why we're here!
          if (id > 0) id = 1013; 
          else id = -1013;
          dZ = tas::isotracks_dz().at(pfidx); 
          charge = tas::isotracks_charge().at(pfidx);
          RelIso03 = tas::isotracks_relIso().at(pfidx);

          dilep_p4 = p4 + tag_p4;
          dilep_mass = dilep_p4.M();

          fillMuonTriggerBranches(p4,-1);

          BabyTree->Fill(); 		  
        }	    
      } // addPFmu

    }//close event loop

    file->Close();
    delete file;

    cout << "\nFile done" <<endl;
  }//close file loop

  cout<<"\nWriting file"<<endl;

  BabyFile->cd();
  BabyTree->Write();
  BabyFile->Close();

  return 0;  

}

void babyMaker::SetOutputPath(std::string outputpath){
  path = outputpath;
}
