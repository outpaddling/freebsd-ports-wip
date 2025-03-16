--- gfm.h.orig	2025-03-16 20:02:10 UTC
+++ gfm.h
@@ -6932,13 +6932,13 @@ void GFM<index_t>::checkOrigs(
     }
     while(i < os.size()) {
         size_t olen = os[i].length();
-        int lastorig = -1;
+        // int lastorig = -1;
         for(; j < olen; j++) {
             size_t joff = j;
             if(mirror) joff = olen - j - 1;
             if((int)os[i][joff] == 4) {
                 // Skip over Ns
-                lastorig = -1;
+                // lastorig = -1;
                 if(!mirror) {
                     while(j < olen && (int)os[i][j] == 4) j++;
                 } else {
@@ -6948,7 +6948,7 @@ void GFM<index_t>::checkOrigs(
                 continue;
             }
             assert_eq(os[i][joff], rest[restOff]);
-            lastorig = (int)os[i][joff];
+            // lastorig = (int)os[i][joff];
             restOff++;
         }
         if(j == os[i].length()) {
