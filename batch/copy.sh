#!/bin/bash

echo "CONDOR FILES ASSEEEEEEEMMMMMMBBBBLLLLEEEE"

START_DIR=`pwd`
cd $START_DIR
cd ..
PREV_DIR=`pwd`

CONDOR_DIR_NAME=forCondor_Commissioning
# Check that CMSSW base is set
if [ -z $CMSSW_BASE ]; then
    echo "CMSSW_BASE var not set, run cmsenv, exiting..."
    return 1;
fi

echo ""
echo "  Creating tarball to transfer to condor node..."
cd $HOME
if [ -d $CONDOR_DIR_NAME ]; then
    rm -rf $CONDOR_DIR_NAME
fi
mkdir $CONDOR_DIR_NAME

cp -r $PREV_DIR $CONDOR_DIR_NAME
tar czf $CONDOR_DIR_NAME.tar.gz $CONDOR_DIR_NAME

cd $START_DIR

#Make dir for logs
if [ ! -d logs ] 
then
  mkdir logs
fi

#Shit for Lorentz Vectors, etc.
sed -i "/struct val_err_t { float value; float error; };/i #include\ \"Math/Vector4D.h\" \n#include\ \"Math/LorentzVector.h\" \n\n\#ifdef\ __MAKECINT__\n\#pragma\ link\ C++\ class\ ROOT::Math::PxPyPzE4D<float>+;\n\#pragma\ link\ C++\ class\ ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>\ >+;\n\#pragma\ link\ C++\ typedef ROOT::Math::XYZTVectorF;\n\#endif" $PREV_DIR/fakeratelooper.h

#Fix name in condor executable
sed -i "s,export\ COPYDIR=/hadoop/cms/store/user/.*/condor/forCommissioning,export COPYDIR=/hadoop/cms/store/user/$USER/condor/forCommissioning," condorExecutable.sh
