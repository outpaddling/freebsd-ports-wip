--- src/tomtom.c.orig	2015-10-26 23:37:43 UTC
+++ src/tomtom.c
@@ -18,7 +18,7 @@
 #include <time.h>
 #include <unistd.h>
 #ifndef WIFEXITED
-#include <wait.h>
+#include <sys/wait.h>
 #endif
 
 #include "array-list.h"
