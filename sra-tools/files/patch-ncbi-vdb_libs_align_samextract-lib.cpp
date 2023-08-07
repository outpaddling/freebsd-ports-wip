--- ncbi-vdb/libs/align/samextract-lib.cpp.orig	2023-08-07 19:47:55 UTC
+++ ncbi-vdb/libs/align/samextract-lib.cpp
@@ -48,7 +48,7 @@
 #include <stdlib.h>
 #include <string.h>
 
-#if LINUX
+#if LINUX || FREEBSD || NETBSD
 #include <unistd.h>
 #define DFL_THREAD_COUNT ((int)sysconf( _SC_NPROCESSORS_ONLN ) - 1)
 #else
