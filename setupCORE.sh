#!/bin/bash

if [ "$USER" == "cgeorge" ]
then 
  ln -s /home/users/cgeorge/CORE . 
else 
  git clone git@github.com:cmstas/CORE.git
  cd CORE
  git checkout cmssw74x
  make -j 10
  cd ..
#  git clone git@github.com:cmstas/Tools.git
fi
