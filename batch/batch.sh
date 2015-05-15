#!/bin/bash

#samples are: QCD_Test, QCD_Mu_Enriched, QCD_EM_Enriched, QCD_non_Enriched, QCD_HT, TTBAR, DY, WJets, ALL
#Choose the sample(s) you want here, separated by commmas
sampleList_in=ALL
#Choose the number of events (per file): 
nEvents=1000
#Decide if you want lots of printouts telling you the status
verbose="true"

#------HERE THERE BE DRAGONS---------

#Parse sampleList
sampleList=`echo $sampleList_in | tr ',' ' ' `
nSamples=`echo "$sampleList" | wc -w`
echo "$sampleList" | grep "ALL" &>/dev/null
isAll="$?" #note this is opposite
if [ "$isAll" == "0" ] && [ "$nSamples" -gt "1" ]; then echo "Aborting! You can't have ALL as well as other sampleLists, dumbass!"; return 1; fi  
if [ "$isAll" == "0" ]
then 
  sampleList="QCD_Test QCD_Mu_Enriched QCD_EM_Enriched QCD_non_Enriched QCD_HT TTBAR DY WJets"
  sampleList_in="QCD_Mu_Enriched,QCD_EM_Enriched,QCD_non_Enriched,QCD_HT,TTBAR,DY,WJets"
fi

#nSubmitted (so you know when to quit)
nSubmitted=0

#Start by checking proxy, get path to proxy file
voms-proxy-info --all &> voms_status.txt
if grep "Couldn't find a valid proxy." voms_status.txt &>/dev/null
then 
  echo "Error: couldn't find a valid proxy!  Aborting.  Create a proxy with voms-proxy-init."
  rm voms_status.txt
  return 1
fi
lineWithPath=`sed -n /path/= voms_status.txt`
pathToProxy=`awk -v var="$lineWithPath" 'NR==var {print $3}' voms_status.txt`

#Do all this stuff once per sample
for sample in $sampleList
do
  #Make a list of all the files on hadoop you want to run on
  root -b -q makeList.C\($sample,\ $nEvents\)
  
  #Submit each file separately
  nLines=`wc -l < fileNames.txt`
  title=`awk "NR==1" fileNames.txt`
  for (( i = 3; i <= $nLines; i++ ))
  do
    name=`awk "NR==$i" fileNames.txt`
    number=$(( $i - 2 ))
    
    #Except they've finished
    if [ -e /hadoop/cms/store/user/cgeorge/condor/frbabies/${title}_${number}.root ] 
    then 
      if [ "$verbose" == "true" ]; then echo "-------------"; echo "${title}_${number} already exists on hadoop, will not resubmit"; fi
      continue
    fi  

    #Status message
    if [ "$verbose" == "true" ]; then echo "-------------"; echo "Working on ${title}_$number"; fi
    
    #Or if they're still running
    if [ -e logs/condorLog_${title}_${number}.log ] 
    then
      while read line
      do
        if [ `echo $line | awk '{ print $1 }'` == "Cluster" ] 
        then
          cluster=`echo $line | awk '{ print $3 }'`
        elif [ `echo $line | awk '{ print $1 }'` == "Proc" ] 
        then
          process=`echo $line | awk '{ print $3 }'`
        fi  
      done < logs/condorLog_${title}_${number}.log
      jobid="$cluster.$process"
      condor_q $jobid > temp.txt
      result=`more temp.txt | awk 'END{print $1}'`
      if [ "$result" == "$jobid" ] 
      then
        if [ "$verbose" == "true" ]; then echo "already submitted!"; fi
        let "nSubmitted=$nSubmitted+1"
        continue
      fi  
    fi  
    if [ "$verbose" == "true" ]; then echo "submitting..."; fi
    let "nSubmitted=$nSubmitted+1"
  
    #Then submit
    cp condorFileTemplate condorFile
    sed -i "s,ARG1,$name,g" condorFile
    sed -i "s,ARG2,$title,g" condorFile
    sed -i "s,ARG3,$nEvents,g" condorFile
    sed -i "s,ARG4,$number,g" condorFile
    sed -i "s,USER_PROXY,$pathToProxy,g" condorFile
    condor_submit condorFile
  done
done

#Clean up
rm voms_status.txt &>/dev/null
rm temp.txt &>/dev/null
rm fileNames.txt &>/dev/null

#Merge
if [ "$nSubmitted" == "0" ] 
then
  . mergeAll.sh $sampleList_in
fi

#Return exit code
if [ "$nSubmitted" == "0" ]
then 
  return 1
else 
  return 0
fi
