--- src/srun/libsrun/launch.c.orig	2013-03-08 13:37:58.000000000 -0600
+++ src/srun/libsrun/launch.c	2013-03-27 18:32:27.000000000 -0500
@@ -36,6 +36,10 @@
 #include <stdlib.h>
 #include <fcntl.h>
 
+#if defined(__FreeBSD__)
+#include <signal.h>
+#endif
+
 #include "launch.h"
 
 #include "src/common/env.h"
