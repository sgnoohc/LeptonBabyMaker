#!/bin/bash

for (( i = 1 ; i <= 239; i++))
do
 
  #see if already there
  COPYDIR=/hadoop/cms/store/user/cgeorge/condor/singleLeptonBabies/
  OUTPUT=DY_amcnlo_$FILENO.root
  if [ -e $COPYDIR/$OUTPUT ]; then continue; fi; 

  #make condor file
  cp condorFileTemplate condorFile

  #Fun with proxies
  voms-proxy-info --all &> voms_status.txt
  if grep "Couldn't find a valid proxy." voms_status.txt &>/dev/null
  then 
    echo "Error: couldn't find a valid proxy!  Aborting.  Create a proxy with voms-proxy-init."
    rm voms_status.txt
    return 1
  fi
  lineWithPath=`sed -n /path/= voms_status.txt`
  pathToProxy=`awk -v var="$lineWithPath" 'NR==var {print $3}' voms_status.txt`
  sed -i "s,USER_PROXY,$pathToProxy,g" condorFile
 
  #Arguments
  sed -i "s/ARG1/$i/" condorFile

  #run it
  condor_submit condorFile
done
