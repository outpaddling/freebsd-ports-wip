--- ncbi-vdb/libs/kfs/unix/sysfile.c.orig	2023-08-07 19:55:11 UTC
+++ ncbi-vdb/libs/kfs/unix/sysfile.c
@@ -72,7 +72,7 @@ struct KSysFile_v1;
 #define USE_NO_TIMEOUT_TTY 0
 #endif
 
-#if ! LINUX
+#if ! LINUX && ! FREEBSD
 #define POLLRDHUP 0
 #endif
 
