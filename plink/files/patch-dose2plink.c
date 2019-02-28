--- dose2plink.c.orig	2019-02-28 14:18:50 UTC
+++ dose2plink.c
@@ -56,15 +56,6 @@
 
 #ifdef _WIN64
   #define __LP64__
-#else
-  #ifndef __LP64__
-    #ifndef uintptr_t
-      #define uintptr_t unsigned long
-    #endif
-    #ifndef intptr_t
-      #define intptr_t long
-    #endif
-  #endif
 #endif
 
 #ifdef __LP64__
