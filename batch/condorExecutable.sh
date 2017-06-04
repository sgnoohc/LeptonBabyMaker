#!/bin/bash

NAME=$1
NEVENTS=$2
NUMBER=$3

#Show where you are
hostname

#Environment
export CMS_PATH=/cvmfs/cms.cern.ch
export SCRAM_ARCH=slc6_amd64_gcc491
source /cvmfs/cms.cern.ch/cmsset_default.sh

#Set CMSSW environment
pushd /cvmfs/cms.cern.ch/slc6_amd64_gcc491/cms/cmssw/CMSSW_7_4_1/src/
eval `scramv1 runtime -sh`
popd

#	#Show g++ version
#	echo " " 
#	echo "G++ INFORMATION" 
#	g++ --version
#	which g++

#This stuff to get output back
export COPYDIR=$4

#Untar the zip dir
echo "This this the current dir: "
THISDIR=`pwd`
echo `pwd`
echo "LS to check that all files were transferred: "
ls
tar xzfv forCondor_Commissioning.tar.gz
echo "LS to check that tarball was unpacked: "
ls
cd forCondor_Commissioning
echo "LS to check contents of unpacked directory: "
ls

#	make clean
#	make

echo "./main.exe $NAME $NEVENTS $NUMBER ./"
./main.exe "$NAME" $NEVENTS $NUMBER "./"

echo "copying.  LS is: "
ls -l ${NAME}_${NUMBER}.root
echo `ls -l`

gfal-copy -p -f -t 4200 file://`pwd`/${NAME}_${NUMBER}.root srm://bsrm-3.t2.ucsd.edu:8443/srm/v2/server?SFN=${COPYDIR}/${NAME}_${NUMBER}.root --checksum ADLER32


