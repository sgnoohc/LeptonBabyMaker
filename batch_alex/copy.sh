#!/bin/bash

#Make Directories
if [ ! -d CORE/Tools/jetcorr/data/run2_25ns/ ]; then mkdir -p CORE/Tools/jetcorr/data/run2_25ns ; fi
if [ ! -d CORE/Tools/jetcorr/data/run2_50ns/ ]; then mkdir -p CORE/Tools/jetcorr/data/run2_50ns ; fi
if [ ! -d CORE/data          ]; then mkdir -p CORE/data; fi
if [ ! -d goodRunList        ]; then mkdir goodRunList; fi

#Do the copying
cp ../main.exe . 
cp  /home/users/cgeorge/CORE/*.h CORE/
cp  /home/users/cgeorge/CORE/*.so CORE/
cp  /home/users/cgeorge/CORE/Tools/*.h CORE/Tools/
cp  /home/users/cgeorge/CORE/Tools/jetcorr/*.h CORE/Tools/jetcorr/
cp  /home/users/cgeorge/CORE/data/*.xml CORE/data/
cp  /home/users/cgeorge/CORE/Tools/jetcorr/data/run2_25ns/*.txt CORE/Tools/jetcorr/data/run2_25ns/
cp  /home/users/cgeorge/CORE/Tools/jetcorr/data/run2_50ns/*.txt CORE/Tools/jetcorr/data/run2_50ns/
cp ../sample.dat .
cp ../liblooper.so . 
cp -r ../goodRunList/*.txt goodRunList/

#Do the tarring
tar czf CORE.tar.gz CORE
tar czf goodRunList.tar.gz goodRunList
