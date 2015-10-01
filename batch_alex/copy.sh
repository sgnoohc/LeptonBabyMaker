#!/bin/bash

#Make Directories
if [ ! -d CORE/Tools/jetcorr ]; then mkdir -p CORE/Tools/jetcorr; fi
if [ ! -d goodRunList ]; then mkdir goodRunList; fi

#Do the copying
cp ../main.exe . 
cp  /home/users/cgeorge/CORE/*.h CORE/
cp  /home/users/cgeorge/CORE/*.so CORE/
cp  /home/users/cgeorge/CORE/Tools/*.h CORE/Tools/
cp  /home/users/cgeorge/CORE/Tools/jetcorr/*.h CORE/Tools/jetcorr/
cp ../sample.dat .
cp ../liblooper.so . 
cp -r ../goodRunList/*.txt goodRunList/
