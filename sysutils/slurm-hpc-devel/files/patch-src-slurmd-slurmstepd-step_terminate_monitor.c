--- src/slurmd/slurmstepd/step_terminate_monitor.c.orig	2013-03-27 09:59:59.000000000 -0500
+++ src/slurmd/slurmstepd/step_terminate_monitor.c	2013-03-27 10:00:32.000000000 -0500
@@ -39,6 +39,9 @@
 #include <sys/types.h> /* for pid_t */
 #include <sys/signal.h> /* for SIGKILL */
 #endif
+#if defined(__FreeBSD__)
+#include <signal.h>
+#endif
 #include <stdlib.h>
 #include <sys/wait.h>
 #include <sys/errno.h>
