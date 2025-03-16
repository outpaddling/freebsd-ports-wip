--- repeat_kmer.h.orig	2025-03-16 19:51:32 UTC
+++ repeat_kmer.h
@@ -206,17 +206,17 @@ class RB_KmerTable { (public)
     {
         RB_Minimizer<TStr>::get_minimizer(query, w_, k_, minimizers);
 
-        size_t est_count = 0;
+        // size_t est_count = 0;
         uint64_t prev_minimizer = 0;
         bool prev_in = false;
         for(size_t j = 0; j < minimizers.size(); j++) {
             bool curr_in = false;
             if(minimizers[j].first == prev_minimizer) {
-                if(prev_in) est_count++;
+                // if(prev_in) est_count++;
                 curr_in = prev_in;
             } else if(isIn(minimizers[j].first)) {
                 curr_in = true;
-                est_count++;
+                // est_count++;
                 
 #if 1
                 return true;
