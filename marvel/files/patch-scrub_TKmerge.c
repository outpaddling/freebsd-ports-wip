--- scrub/TKmerge.c.orig	2018-07-17 00:22:17 UTC
+++ scrub/TKmerge.c
@@ -14,11 +14,7 @@
 #include <assert.h>
 #include <unistd.h>
 
-#if defined(__APPLE__)
-    #include <sys/syslimits.h>
-#else
-    #include <linux/limits.h>
-#endif
+#include <limits.h>
 
 #include "db/DB.h"
 #include "lib/tracks.h"
