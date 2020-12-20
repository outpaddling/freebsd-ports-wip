--- lib/io.c.orig	2020-12-20 12:06:46 UTC
+++ lib/io.c
@@ -19,6 +19,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
+#include <sys/types.h>
 
 #define _IO_C
 #define _IN_LIBRARY
