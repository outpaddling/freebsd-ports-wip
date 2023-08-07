--- ncbi-vdb/test/kfg/kfgtest.cpp.orig	2023-08-07 20:02:56 UTC
+++ ncbi-vdb/test/kfg/kfgtest.cpp
@@ -282,6 +282,8 @@ FIXTURE_TEST_CASE(predef_ARCHBITS, KfgFixture)
 FIXTURE_TEST_CASE(predef_OS, KfgFixture)
 {
     CreateAndLoad(GetName(), "var=$(OS)\n");
+    #if FREEBSD
+        #define OS "freebsd"
     #if LINUX
         #define OS "linux"
     #elif SUN
