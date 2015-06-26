#!/bin/bash

if [ "$USER" == "cgeorge" ]
then 
  ln -s /home/users/cgeorge/CORE . 
else 
  git clone git@github.com:cmstas/CORE.git
  git checkout cmssw74x
  cd CORE
  make -j 8
  cd ..
fi
