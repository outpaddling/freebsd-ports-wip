--- tools/fastq-loader/common-writer.c.orig	2017-08-03 16:17:04 UTC
+++ tools/fastq-loader/common-writer.c
@@ -58,6 +58,7 @@
 
 #include <unistd.h>
 #include <fcntl.h>
+#include <sys/stat.h>
 #include <sys/mman.h>
 
 #define USE_READER_THREAD (1)
