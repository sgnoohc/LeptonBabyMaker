#Condor for Babymaker

This will submit the babymaker in the parent directory on Condor

Instructions (no quotes):
  1.  Follow instructions in parent directory; this should work locally.  Make sure your CORE is up to date.
  2.  ". copy.sh" to copy stuff from the parent directory to the batch directory.  Many of the files are modified as well.
  3.  Open doBatch.sh and modify the two fields at the top to specify which baby should be produced
  4.  ". doBatch.sh" to submit

Next Steps (Alex will do on 4/21 or 4/22)
  -  These jobs seem to always fail at certain sites, must be resubmitted.  Have e-mailed T2Support. (this is also a problem for the SS babymaker)
  -  Need a script that will submit every single job, not one at a time
  -  Need to support "smart" resubmissions (ie don't resubmit jobs that exist or are done)
  -  Need one script that will make every baby
  -  Need a merge script to merge the output into a single file
