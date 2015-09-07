# LeptonBabyMaker
one lepton babymaker for common SS+OS effort

Instructions for 74X

Setup CMSSW74X (if not already setup):
```
cmsrel CMSSW_7_4_1_patch1
cd CMSSW_7_4_1_patch1/src
cmsenv
```

Then 

```
git clone git@github.com:cmstas/LeptonBabyMaker.git
cd LeptonBabyMaker
git checkout cmssw74x
source setupCORE.sh
make
./main.exe
```

Currently running main.C, while runLooper.C is kept for reference.

main.C can have 4 inputs
```
./main.exe SampleName NumberOfEvents FileNumber OutputDirectory
```
The default values are
   * SampleName = default.
   * NumberOfEvents = -1 (meaning all)
   * FileNumber = 0 (meaning merged_ntuple_*.root)
   * OutputDirectory = ./

Also note, that the samples are stored in sample.dat in format
```
SAMPLE
Name SampleName
Path CMSntuplePath
```

Batch mode is now implemented to work for root6.

