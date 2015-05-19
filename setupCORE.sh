#!/bin/bash

if [ "$USER" == "cgeorge" ]
then 
  ln -s /home/users/cgeorge/CORE . 
else 
  git clone git@github.com:cmstas/CORE.git
  cd CORE
  make -j 8
  cd ..
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
fi
