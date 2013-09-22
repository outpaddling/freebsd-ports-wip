--- src/plugins/proctrack/linuxproc/proctrack_linuxproc.c.orig	2013-03-08 13:37:58.000000000 -0600
+++ src/plugins/proctrack/linuxproc/proctrack_linuxproc.c	2013-03-27 18:32:27.000000000 -0500
@@ -51,6 +51,9 @@
 #include <sys/types.h> /* for pid_t */
 #include <sys/signal.h> /* for SIGKILL */
 #endif
+#if defined(__FreeBSD__)
+#include <signal.h>	/* SIGKILL */
+#endif
 #include <sys/types.h>
 
 #include "slurm/slurm.h"
