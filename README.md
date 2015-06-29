# LeptonBabyMaker
one lepton babymaker for common SS+OS effort

Instructions for 74X

Setup CMSSW74X (if not already setup):

cmsrel CMSSW_7_4_1_patch1

cd CMSSW_7_4_1_patch1/src

cmsenv


Then 

git clone git@github.com:cmstas/LeptonBabyMaker.git

git checkout cmssw74x

source setupCORE.sh

make

./main.exe


Currently running main.C, while runLooper.C is kept for reference.

Batch mode not yet working in 74X (still based on the root5 setup)

