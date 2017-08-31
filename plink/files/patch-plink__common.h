--- plink_common.h.orig	2017-08-30 22:37:30.805919000 -0500
+++ plink_common.h	2017-08-30 22:37:47.253002000 -0500
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
