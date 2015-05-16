#Condor for Babymaker

This will submit the babymaker in the parent directory on Condor

Instructions (no quotes):
  1.  Follow instructions in parent directory; this should work locally.  Make sure your CORE is up to date.
  2.  ". copy.sh" to copy stuff from the parent directory to the batch directory.  Many of the files are modified as well.
  3.  Open batch.sh and modify the fields at the top to specify which bab(ies) should be produced.  nEventsPerJob will run N events per job and skip the rest -- set this to -1 unless you are just running a quick test (I recommend 1000 for testing).  
  4.  ". makeBabies.sh" to submit.  Just let it run, it will quit when all babies exist.  It will also merge them for you at the end.
