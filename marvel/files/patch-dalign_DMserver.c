--- dalign/DMserver.c.orig	2018-07-17 00:40:00 UTC
+++ dalign/DMserver.c
@@ -47,11 +47,7 @@
 #include <sys/socket.h>
 #include <unistd.h>
 
-#if defined( __APPLE__ )
-#include <sys/syslimits.h>
-#else
-#include <linux/limits.h>
-#endif
+#include <limits.h>
 
 #include "lib/dmask.h"
 #include "lib/dmask_proto.h"
