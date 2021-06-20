--- test/vdb/test-dependencies.cpp.orig	2017-07-14 21:55:36 UTC
+++ test/vdb/test-dependencies.cpp
@@ -115,7 +115,7 @@ public:
 
 class RefseqFixture : public DepFixture {
 
-  #if LINUX
+  #if LINUX || BSD
     #define PATH "kfg/linux"
   #elif MAC
     #define PATH "kfg/mac"
