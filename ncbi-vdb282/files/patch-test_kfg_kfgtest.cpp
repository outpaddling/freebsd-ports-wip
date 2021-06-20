--- test/kfg/kfgtest.cpp.orig	2017-07-14 21:55:36 UTC
+++ test/kfg/kfgtest.cpp
@@ -443,6 +443,8 @@ FIXTURE_TEST_CASE(predef_OS, KfgFixture)
     CreateAndLoad(GetName(), "var=$(OS)\n");
     #if LINUX
         #define OS "linux"
+    #elif BSD
+        #define OS "bsd"    
     #elif SUN
         #define OS "sun"    
     #elif MAC 
