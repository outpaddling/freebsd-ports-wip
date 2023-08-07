--- ncbi-vdb/test/vdb/test-dependencies_dflt.cpp.orig	2023-08-07 20:04:05 UTC
+++ ncbi-vdb/test/vdb/test-dependencies_dflt.cpp
@@ -139,6 +139,8 @@ class EmptyFixture : public DepFixture { (public)
 
 class RefseqFixture : public DepFixture {
 
+  #if FREEBSD
+    #define PATH "kfg/freebsd"
   #if LINUX
     #define PATH "kfg/linux"
   #elif MAC
