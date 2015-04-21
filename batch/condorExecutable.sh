#!/bin/bash

NAME=$1
TITLE=$2
NEVENTS=$3
NUMBER=$4

#Show where you are
hostname

#Environment
export CMS_PATH=/cvmfs/cms.cern.ch
export SCRAM_ARCH=slc6_amd64_gcc481
source /cvmfs/cms.cern.ch/cmsset_default.sh

#Set CMSSW environment
pushd /cvmfs/cms.cern.ch/slc6_amd64_gcc481/cms/cmssw/CMSSW_7_2_0/src/
eval `scramv1 runtime -sh`
popd

#Show g++ version
echo " " 
echo "G++ INFORMATION" 
g++ --version
which g++

#This stuff to get output back
export COPYDIR=/hadoop/cms/store/user/cgeorge/condor/frbabies

#Untar the zip dir
tar xzvf CORE.tar.gz

root -b -q runLooper.C\(\"$NAME\",\"$TITLE\",$NEVENTS,$NUMBER\)
ls -l `pwd`/${OUTPUT}.root

echo "copying.  LS is: "
ls -l ${TITLE}_${NUMBER}.root

lcg-cp -b -D srmv2 --vo cms --connect-timeout 2400 --verbose file://`pwd`/${TITLE}_$NUMBER.root srm://bsrm-3.t2.ucsd.edu:8443/srm/v2/server?SFN=${COPYDIR}/${TITLE}_$NUMBER.root
