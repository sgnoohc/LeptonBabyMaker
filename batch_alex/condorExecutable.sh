#!/bin/bash

#arguments
FILENO=$1

#set up root sys
export CMS_PATH=/cvmfs/cms.cern.ch
export SCRAM_ARCH=slc6_amd64_gcc491
source /cvmfs/cms.cern.ch/cmsset_default.sh
cd /cvmfs/cms.cern.ch/slc6_amd64_gcc491/cms/cmssw-patch/CMSSW_7_4_1_patch1/external/slc6_amd64_gcc491/
eval `scramv1 runtime -sh`
cd - 

#untar
tar -xzvf CORE.tar.gz
tar -xzvf goodRunList.tar.gz

#run the fucking executable
./main.exe DY_amcnlo -1 $FILENO 

#copy back the output
COPYDIR=/hadoop/cms/store/user/cgeorge/condor/singleLeptonBabies/
OUTPUT=DY_amcnlo_$FILENO.root
lcg-cp -b -D srmv2 --vo cms --connect-timeout 2400 --verbose file://`pwd`/${OUTPUT}.root srm://bsrm-3.t2.ucsd.edu:8443/srm/v2/server?SFN=${COPYDIR}/${OUTPUT}.root
