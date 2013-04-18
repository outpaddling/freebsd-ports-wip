--- src/slurmctld/job_scheduler.c.orig	2013-03-08 13:29:51.000000000 -0600
+++ src/slurmctld/job_scheduler.c	2013-03-27 09:23:59.000000000 -0500
@@ -46,6 +46,9 @@
 #include <sys/types.h> /* for pid_t */
 #include <sys/signal.h> /* for SIGKILL */
 #endif
+#if defined(__FreeBSD__)
+#include <signal.h> /* for SIGKILL */
+#endif
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
