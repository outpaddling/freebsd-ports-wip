--- ncbi-vdb/libs/kns/manager.c.orig	2023-08-07 20:01:06 UTC
+++ ncbi-vdb/libs/kns/manager.c
@@ -58,7 +58,7 @@
 #if HAVE_GNU_LIBC_VERSION_H
 #include <gnu/libc-version.h>
 #endif
-#if LINUX
+#if LINUX || FREEBSD
 #include <arpa/inet.h>
 #include <netinet/in.h>
 #endif
