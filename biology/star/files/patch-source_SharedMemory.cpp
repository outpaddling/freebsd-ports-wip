--- source/SharedMemory.cpp.orig	2016-06-10 11:54:47.702667727 -0500
+++ source/SharedMemory.cpp	2016-06-10 11:56:08.108657804 -0500
@@ -11,7 +11,7 @@
 #include <semaphore.h>
 #include <errno.h>
 
-#ifdef COMPILE_FOR_MAC
+#if defined(COMPILE_FOR_MAC) || defined(__FreeBSD__)
   //some Mac's idiosyncrasies: standard SHM libraries are very old and missing some definitions
   #define SHM_NORESERVE 0
 #endif
