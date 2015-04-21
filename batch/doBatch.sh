#!/bin/bash

#samples are: QCD_Test, QCD_Mu_Enriched, QCD_EM_Enriched, QCD_non_Enriched, QCD_HT, TTBAR, DY
#Choose the sample you want here:
sample=QCD_Test
#Choose the number of events:
nEvents=1000

#------HERE THERE BE DRAGONS---------

root -b -q makeList.C\($sample,\ $nEvents\)

nLines=`wc -l < fileNames.txt`
title=`awk "NR==1" fileNames.txt`
for (( i = 3; i <= $nLines; i++ ))
do
  name=`awk "NR==$i" fileNames.txt`
  number=$(( $i - 2 ))
  cp condorFileTemplate condorFile
  sed -i "s,ARG1,$name,g" condorFile
  sed -i "s,ARG2,$title,g" condorFile
  sed -i "s,ARG3,$nEvents,g" condorFile
  sed -i "s,ARG4,$number,g" condorFile
done
