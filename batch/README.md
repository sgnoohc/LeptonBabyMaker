#Condor for Babymaker

This will submit the babymaker in the parent directory on Condor

Instructions (no quotes):
  1.  Follow instructions in parent directory; this should work locally.  Make sure your CORE is up to date.
  2.  ". copy.sh" to copy stuff from the parent directory to the batch directory.  Many of the files are modified as well.
  3.  Open batch.sh and modify the fields at the top to specify which bab(ies) should be produced.  nEvents(PerJob) will run N events per job and skip the rest -- set this to -1 unless you are just running a quick test (I recommend 1000 for testing). Also modify the copy_dir where you want your babies to be stored.
  4.  ". makeBabies.sh" to submit.  Just let it run, it will quit when all babies exist.  It will NOT merge them for you at the end.
  [Alternatively, just comment out the ZOMBIE section in batch.sh and just do ". batch.sh", if you do not care about having 100% of jobs. This will submit jobs only once, with no automated resubmission, so you will not need screen.]
  5.  Modify the HADOOPDIR and OUTPUTDIR directories and the list of samples to merge in mergeHadoop.sh, then do ". mergeHadoop.sh"

