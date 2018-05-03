--- plink_common.h.orig	2017-08-27 17:35:52 UTC
+++ plink_common.h
@@ -116,8 +116,8 @@
     // (may break on gcc <3.0?  but that shouldn't matter anymore)
     // tried defining GCC_VERSION, but that didn't always work
     #if (__GNUC__ <= 4) && (__GNUC_MINOR__ < 8)
-      #define uint64_t unsigned long long
-      #define int64_t long long
+      //#define uint64_t unsigned long long
+      //#define int64_t long long
     #endif
   #endif
 #endif
