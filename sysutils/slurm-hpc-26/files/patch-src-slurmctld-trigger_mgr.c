--- src/slurmctld/trigger_mgr.c.orig	2013-03-08 13:37:58.000000000 -0600
+++ src/slurmctld/trigger_mgr.c	2013-03-27 18:32:27.000000000 -0500
@@ -49,6 +49,9 @@
 #include <sys/types.h> /* for pid_t */
 #include <sys/signal.h> /* for SIGKILL */
 #endif
+#if defined(__FreeBSD__)
+#include <signal.h>
+#endif
 #include <errno.h>
 #include <fcntl.h>
 #include <grp.h>
