--- csys/info_manager.h.orig	2021-08-07 13:50:11 UTC
+++ csys/info_manager.h
@@ -76,7 +76,6 @@ class LIBCSYSSHARED_EXPORT InfoManager { (private)
     MemoryInfo *mi = nullptr;
     NetworkInfo *ni = nullptr;
     SystemInfo *si = nullptr;
-    ProcessInfo *pi = nullptr;
 
     static InfoManager *instance;
 
