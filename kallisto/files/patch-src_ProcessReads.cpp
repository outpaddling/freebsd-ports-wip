--- src/ProcessReads.cpp.orig	2020-02-16 22:27:33 UTC
+++ src/ProcessReads.cpp
@@ -1408,6 +1408,13 @@ void BUSProcessor::processBuffer() {
   std::vector<int> l(jmax,0);
 
   bool singleSeq = busopt.seq.size() ==1 ;
+
+  if (mp.opt.busOptions.seq.empty()) {
+    std::cerr << "No seq technology specified.\n";
+    std::cerr << "If you believe this is a bug, please report using reportbug.";
+    std::cerr.flush();
+    exit(1);
+  }
   const BUSOptionSubstr seqopt = busopt.seq.front();
 
 
@@ -2145,7 +2152,7 @@ void AlnProcessor::processBufferGenome() {
       rlen2 = seqs[si2].second;
     }
     
-    if (mp.opt.busOptions.seq.front().fileno == 1) {
+    if (!mp.opt.busOptions.seq.empty() && mp.opt.busOptions.seq.front().fileno == 1) {
       std::swap(si1,si2);
       std::swap(rlen1,rlen2);
     }
