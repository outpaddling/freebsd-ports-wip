--- src/slurmctld/gang.c.orig	2013-03-08 13:37:58.000000000 -0600
+++ src/slurmctld/gang.c	2013-03-27 18:32:27.000000000 -0500
@@ -44,6 +44,9 @@
 #include <sys/types.h> /* for pid_t */
 #include <sys/signal.h> /* for SIGKILL */
 #endif
+#if defined(__FreeBSD__)
+#include <signal.h>
+#endif
 #include <pthread.h>
 #include <unistd.h>
 
