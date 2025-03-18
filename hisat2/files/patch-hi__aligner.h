--- hi_aligner.h.orig	2025-03-17 23:37:37 UTC
+++ hi_aligner.h
@@ -3727,7 +3727,7 @@ int64_t GenomeHit<index_t>::calculateScore(
     const BTDnaString& seq = _fw ? rd.patFw : rd.patRc;
     const BTString& qual = _fw ? rd.qual : rd.qualRev;
     index_t rdlen = (index_t)seq.length();
-    int64_t toff_base = _toff;
+    // int64_t toff_base = _toff;
     bool conflict_splicesites = false;
     uint8_t whichsense = SPL_UNKNOWN;
     for(index_t i = 0; i < _edits->size(); i++) {
@@ -3835,7 +3835,7 @@ int64_t GenomeHit<index_t>::calculateScore(
                 }
             }
             
-            toff_base += edit.splLen;
+            // toff_base += edit.splLen;
         } else if(edit.type == EDIT_TYPE_READ_GAP) {
             bool open = true;
             if(i > 0 &&
@@ -3847,7 +3847,7 @@ int64_t GenomeHit<index_t>::calculateScore(
                 if(open)    score -= sc.readGapOpen();
                 else        score -= sc.readGapExtend();
             }
-            toff_base++;
+            // toff_base++;
         } else if(edit.type == EDIT_TYPE_REF_GAP) {
             bool open = true;
             if(i > 0 &&
@@ -3859,7 +3859,7 @@ int64_t GenomeHit<index_t>::calculateScore(
                 if(open)    score -= sc.refGapOpen();
                 else        score -= sc.refGapExtend();
             }
-            toff_base--;
+            // toff_base--;
         }
 #ifndef NDEBUG
         else {
