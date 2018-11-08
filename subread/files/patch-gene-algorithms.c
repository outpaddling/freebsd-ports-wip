--- gene-algorithms.c.orig	2018-11-08 03:36:48 UTC
+++ gene-algorithms.c
@@ -27,10 +27,7 @@
 #include <unistd.h>
 #include <sys/stat.h>
 #include <sys/types.h>
-
-#ifndef FREEBSD
 #include <sys/timeb.h>
-#endif
 
 #include "subread.h"
 #include "input-files.h"
