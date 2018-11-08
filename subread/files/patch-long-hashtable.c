--- long-hashtable.c.orig	2018-11-08 03:34:19 UTC
+++ long-hashtable.c
@@ -21,11 +21,9 @@
 #include <stdlib.h>
 #include <string.h>
 
-#ifndef MACOS
-#ifndef FREEBSD
+#if !defined(__FreeBSD__) && !defined(__APPLE__)
 #include <malloc.h>
 #endif
-#endif
 
 #include<math.h>
 #include"core.h"
