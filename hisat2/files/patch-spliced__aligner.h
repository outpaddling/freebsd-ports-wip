--- spliced_aligner.h.orig	2025-03-17 23:42:52 UTC
+++ spliced_aligner.h
@@ -405,7 +405,7 @@ int64_t SplicedAligner<index_t, local_index_t>::hybrid
     // if this is a full alignment, report it
     if(hitoff == 0 && hitlen == rdlen) {
         if(!this->redundant(sink, rdi, hit)) {
-            bool another_spliced = false;
+            // bool another_spliced = false;
             if(!ssdb.empty()) {
                 int64_t best_score = hit.score();
                 this->_local_genomeHits[dep].clear();
@@ -521,7 +521,7 @@ int64_t SplicedAligner<index_t, local_index_t>::hybrid
                            nedits <= leftAnchorLen / 4) { // prevent (short) anchors from having many mismatches
                             if(this->isSearched(tempHit, rdi)) continue;
                             if(!this->redundant(sink, rdi, tempHit)) {
-                                another_spliced = true;
+                                // another_spliced = true;
                                 if(tempHit.score() > best_score)
                                     best_score = tempHit.score();
                                 this->_local_genomeHits[dep].expand();
@@ -638,7 +638,7 @@ int64_t SplicedAligner<index_t, local_index_t>::hybrid
                                nedits <= rightAnchorLen / 4) { // prevent (short) anchors from having many mismatches
                                 if(this->isSearched(combinedHit, rdi)) continue;
                                 if(!this->redundant(sink, rdi, combinedHit)) {
-                                    another_spliced = true;
+                                    // another_spliced = true;
                                     if(combinedHit.score() > best_score)
                                         best_score = tempHit.score();
                                     this->_local_genomeHits[dep].expand();
