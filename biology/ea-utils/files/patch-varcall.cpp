--- varcall.cpp.orig	2014-09-04 10:44:33.000000000 -0500
+++ varcall.cpp	2015-02-13 11:22:37.000000000 -0600
@@ -351,7 +351,8 @@
 int repeat_filter=7;
 double artifact_filter=1;
 int min_adepth=2;
-int read_tail_pct=.6;
+// What is this supposed to be? Assuming 6 below. int read_tail_pct=.6;
+int read_tail_pct=6;
 int read_tail_len=4;
 int min_idepth=3;
 int no_baq=0;
@@ -608,7 +609,7 @@
         meminit(vse_dev);
 
         while(read_line(f, l)>0) {
-            if (val=strchr(l.s, '\t')) {
+            if ( (val=strchr(l.s, '\t')) != NULL ) {
                 *val='\0'; ++val;
                 if (!strcasecmp(l.s, "min depth")) {
                     if (umindepth && umindepth > atoi(val)) {
@@ -783,7 +784,7 @@
 void rename_tmp(std::string f) {
     std::string notmp = f;
     size_t pos = notmp.find(".tmp");
-    if (pos >= 0) {
+    if (pos != string::npos ) {
         notmp.replace(notmp.find(".tmp"),4,""); 
         rename(f.c_str(),notmp.c_str());
     }
