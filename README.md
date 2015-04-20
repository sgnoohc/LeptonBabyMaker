# LeptonBabyMaker
one lepton babymaker for common SS+OS effort

To use the baby maker, first make sure you have root sourced. Then check out this repo: 
git clone git@github.com:cmstas/LeptonBabyMaker.git

Then checkout and compile CORE
. setupCORE.sh 

At the top of runLooper.C, specify the user-controlled options (see the comment).

Then run the looper
root -b -q runLooper.C

Important things to note:
  1. Moved declaration of output directory to runLooper.C. Make sure you update the output path before running over a large sample!
  2. You need to set the samples and running options in runLooper.C. The previous samples run to make the fake rate can be used as an example of how this is done.
