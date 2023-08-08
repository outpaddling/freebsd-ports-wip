--- ncbi-vdb/libs/kfs/unix/sysfile.c.orig	2023-07-10 16:13:36 UTC
+++ ncbi-vdb/libs/kfs/unix/sysfile.c
@@ -72,7 +72,7 @@ struct KSysFile_v1;
 #define USE_NO_TIMEOUT_TTY 0
 #endif
 
-#if ! LINUX
+#if ! BSD && ! LINUX
 #define POLLRDHUP 0
 #endif
 
