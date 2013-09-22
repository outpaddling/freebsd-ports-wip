--- src/slurmctld/reservation.c.orig	2013-03-27 19:27:00.000000000 -0500
+++ src/slurmctld/reservation.c	2013-03-27 19:27:19.000000000 -0500
@@ -44,6 +44,10 @@
 #  include <pthread.h>
 #endif				/* WITH_PTHREADS */
 
+#if defined(__FreeBSD__)
+#include <signal.h>
+#endif
+
 #include <fcntl.h>
 #include <string.h>
 #include <stdlib.h>
