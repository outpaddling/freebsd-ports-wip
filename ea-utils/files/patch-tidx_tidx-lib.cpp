--- tidx/tidx-lib.cpp.orig	2015-02-13 11:11:24.000000000 -0600
+++ tidx/tidx-lib.cpp	2015-02-13 11:11:44.000000000 -0600
@@ -393,10 +393,12 @@
         for (i=0;i<van.size();++i) {
             // overlap next
             if (van[i].pos.size() != 0 && van[i].beg <= van[i].end)
+            {
                 if (i != j) 
                     van[j++]=van[i];
                 else
                     ++j;
+            }
         }
         if (j != van.size()) {
             if (debug) fprintf(stderr, "(rm %ld) ", van.size()-j);
