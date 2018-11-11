--- tools/bam-loader/loader-imp.c.orig	2017-08-03 16:17:04 UTC
+++ tools/bam-loader/loader-imp.c
@@ -73,6 +73,7 @@
 
 #include <unistd.h>
 #include <fcntl.h>
+#include <sys/stat.h>
 #include <sys/mman.h>
 #include <stdlib.h>
 #include <stdio.h>
