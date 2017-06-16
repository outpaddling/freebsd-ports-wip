--- src/vsearch.h.orig	2017-03-10 16:26:54 UTC
+++ src/vsearch.h
@@ -116,6 +116,11 @@
 
 #endif
 
+#ifdef __FreeBSD__
+#define PROG_OS "freebsd"
+#include <sys/resource.h>
+#endif
+
 #ifdef __APPLE__
 #define PROG_OS "osx"
 #include <sys/resource.h>
