--- pysam/tabix_util.c.orig	2015-04-29 09:32:28 UTC
+++ pysam/tabix_util.c
@@ -1,6 +1,9 @@
 // Definition of pysamerr
 #include "stdio.h"
 #include "unistd.h"
+#include <stdlib.h>
+#include <string.h>
+
 FILE * pysamerr = NULL;
 
 #if !(_POSIX_C_SOURCE >= 200809L || _XOPEN_SOURCE >= 700)
