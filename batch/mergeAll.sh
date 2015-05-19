#!/bin/bash

path0="/hadoop/cms/store/user/"
path1="/condor/frbabies"
#path2="/hadoop/cms/store/user/iandyckes/condor/frbabies"
path2=$path0$USER$path1

samples=$1
samples=`echo $samples | tr ',' ' '`

for sname in $samples
do

  root -b -q makeList.C\($sname,1\)
  numberOfFiles=`wc -l < fileNames.txt`
  numberOfFiles=$(( $numberOfFiles - 2 ))
  title=`awk "NR==1" fileNames.txt`

  if [ "$numberOfFiles" == "1" ]
  then
    cp $path2/${title}_1.root $title.root & 
    echo "Copying $title.root in background, may be delay even after this program finishes...."
    continue
  fi

  for (( counter=0; counter<=500; counter++ )); do file1[$counter]=""; done

  #Write array with file names
  for (( counter=1; counter<=$numberOfFiles; counter++ ))
  do
    file1[$(( $counter - 1 )) ]="$path2/${title}_${counter}.root"
  done

  hadd $sname.root ${file1[*]}

 done 

#clean up
rm fileNames.txt &>/dev/null
rm null &>/dev/null
