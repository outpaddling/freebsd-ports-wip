--- plink_common.h.orig	2019-02-27 08:24:47 UTC
+++ plink_common.h
@@ -128,8 +128,8 @@
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
@@ -141,17 +141,6 @@
 #else
   #define CTZLU __builtin_ctzl
   #define CLZLU __builtin_clzl
-  #ifndef __LP64__
-    // attempt to patch GCC 6 build failure
-    #if (__GNUC__ <= 4) && (__GNUC_MINOR__ < 8)
-      #ifndef uintptr_t
-        #define uintptr_t unsigned long
-      #endif
-      #ifndef intptr_t
-        #define intptr_t long
-      #endif
-    #endif
-  #endif
 #endif
 
 #ifdef __cplusplus
