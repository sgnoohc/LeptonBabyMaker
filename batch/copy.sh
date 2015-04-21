#!/bin/bash

#Copy files
cp ../fakeratelooper.C .
cp ../runLooper.C makeList.C
cp ../runLooper.C .
cp ../fakeratelooper.h .

#Copy CORE directory
if [ ! -d CORE ] 
then
  mkdir CORE
fi
cp ../CORE/CMS3_CORE.so CORE/
cp ../CORE/*.h CORE/

#And data directory inside CORE
if [ ! -d CORE/data ] 
then
  mkdir CORE/data
fi
cp /home/users/cgeorge/CORE/data/*.xml CORE/data/

#Modifications to makeList.C
sed -i '/mylooper->looper/d' makeList.C
lineno=`grep -n "char\* title = " makeList.C | tr ':' ' ' | awk '{print $1}'`
lineno=$(( $lineno + 1 ));
sed -i "${lineno}i \\  TObjArray *listOfFiles = chain->GetListOfFiles();\n  TIter fileIter(listOfFiles);\n  TFile *currentFile = 0;\n  \n  //Write the list of files\n  ofstream myfile;\n  myfile.open(\"fileNames.txt\");\n  myfile << title << endl;\n  myfile << nEvents << endl;\n  while ((currentFile = (TFile*)fileIter.Next())){ \n    myfile << currentFile->GetTitle() << endl;\n  }\n  myfile.close();" makeList.C
sed -i "s/void\ runLooper()/void makeList()/g" makeList.C
lineno=`grep -n "sample_t\ sample\ =\ " makeList.C | tr ':' ' ' | awk '{print $1}'`
lineno=$(( $lineno - 2 ));
sed -i "${lineno}d" makeList.C
sed -i "${lineno}d" makeList.C
sed -i "${lineno}d" makeList.C
sed -i "${lineno}d" makeList.C
sed -i 's/makeList()/makeList(sample_t sample, int nEvents)/' makeList.C

#Modification to runLooper.C
sed -i 's/runLooper()/runLooper(char* name, char* title, int nEvents, int number)/' runLooper.C
lineno=`grep -n "getTitle(sample_t sample){" runLooper.C | tr ':' ' ' | awk  '{print $1}'`
lineno=$(( $lineno - 1 ))
sed -i "${lineno},100000d" runLooper.C
lineno=`grep -n "sample_t\ sample\ =\ " runLooper.C | tr ':' ' ' | awk '{print $1}'`
lineno=$(( $lineno - 2 ));
sed -i "${lineno}d" runLooper.C
sed -i "${lineno}d" runLooper.C
sed -i "${lineno}d" runLooper.C
sed -i "${lineno}d" runLooper.C
sed -i "s/TChain\ \*chain\ =\ (TChain\*)getChain(sample);/TChain *chain = new TChain(\"Events\");/"  runLooper.C
sed -i "s/char\*\ title\ =\ (char\*)getTitle(sample);/chain->Add(name);/g" runLooper.C
lineno=`grep -n "int file = 0" runLooper.C | tr ':' ' ' | awk '{print $1}'`
sed -i "${lineno}d" runLooper.C
sed -i "${lineno}d" runLooper.C
sed -i "s/->looper(chain, title/->looper(chain, Form(\"%s_%i\", title, number)/" runLooper.C

#Zip CORE
tar czf CORE.tar.gz CORE

#Make dir for logs
if [ ! -d logs ] 
then
  mkdir logs
fi

#Shit for Lorentz Vectors, etc.
sed -i "/struct val_err_t { float value; float error; };/i #include\ \"Math/Vector4D.h\" \n#include\ \"Math/LorentzVector.h\" \n\n\#ifdef\ __MAKECINT__\n\#pragma\ link\ C++\ class\ ROOT::Math::PxPyPzE4D<float>+;\n\#pragma\ link\ C++\ class\ ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>\ >+;\n\#pragma\ link\ C++\ typedef ROOT::Math::XYZTVectorF;\n\#endif" fakeratelooper.h

#Fix name in condor executable
sed -i "s,export\ COPYDIR=/hadoop/cms/store/user/.*/condor/frbabies,export COPYDIR=/hadoop/cms/store/user/$USER/condor/frbabies," condorExecutable.sh
