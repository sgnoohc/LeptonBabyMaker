#!/bin/bash

function run () {
    echo root -b -q mergeHadoopFiles.C\(\"${HADOOPDIR}/$1\",\"${OUTPUTDIR}/$1.root\"\)
    nohup nice -n 19 root -b -q mergeHadoopFiles.C\(\"${HADOOPDIR}/$1\",\"${OUTPUTDIR}/$1.root\"\) >& log_merge_$1.txt &
}

#TAG=V00-01-09_25ns_fastsim

HADOOPDIR=/hadoop/cms/store/user/${USER}/condor/forCommissioning/
#HADOOPDIR=/hadoop/cms/store/user/${USER}/condor/forSoftLeptons74X_1May16/
OUTPUTDIR=/nfs-7/userdata/leptonTree/v1.13FR/

mkdir -p $OUTPUTDIR
chmod -R a+wrx $OUTPUTDIR


#run 2015DSingleEl76X
#run DY_76X_HCALdebug
# run 2015DSingleElV4
# run 2015DSingleMuonV4
# run DY_madgraph
run 2016DoubleEG
run 2016DoubleMuon
run DY_madgraph
run WJets
