--- reference.cpp.orig	2025-03-16 20:08:47 UTC
+++ reference.cpp
@@ -130,14 +130,18 @@ BitPairReference::BitPairReference(
     
     EList<TIndexOffU> seq_poss;
     TIndexOffU seq_cumpos = 0;
+    #ifndef NDEBUG
     TIndexOffU skips = 0;
+    #endif
 	// For each unambiguous stretch...
 	for(TIndexOffU i = 0; i < sz; i++) {
 		recs_.push_back(RefRecord(f3, swap));
         if(included != NULL && !(*included)[i]) {
             seq_cumpos += recs_.back().len;
             recs_.pop_back();
+	    #ifndef NDEBUG
             skips++;
+	    #endif
             continue;
         }
         seq_poss.push_back(seq_cumpos);
@@ -180,7 +184,9 @@ BitPairReference::BitPairReference(
 	cumRefOff_.push_back(cumlen);
 	bufSz_ = cumsz;
 	assert_eq(nrefs_, refLens_.size());
+	#ifndef DEGBUG
 	assert_eq(sz, recs_.size() + skips);
+	#endif
 	if (f3 != NULL) fclose(f3); // done with .3.gfm_ext file
     
 	// Round cumsz up to nearest byte boundary
