--- src/tomtom.c.orig	2016-02-24 16:56:16 UTC
+++ src/tomtom.c
@@ -18,7 +18,7 @@
 #include <time.h>
 #include <unistd.h>
 #ifndef WIFEXITED
-#include <wait.h>
+#include <sys/wait.h>
 #endif
 
 #include "array-list.h"
