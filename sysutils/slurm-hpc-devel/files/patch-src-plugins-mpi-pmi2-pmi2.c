--- src/plugins/mpi/pmi2/pmi2.c.orig	2013-03-27 10:54:51.000000000 -0500
+++ src/plugins/mpi/pmi2/pmi2.c	2013-03-27 10:54:59.000000000 -0500
@@ -39,6 +39,11 @@
 #  include "config.h"
 #endif
 
+#if defined(__FreeBSD__)
+#include <roken.h>
+#include <sys/socket.h> /* AF_INET */
+#endif
+
 #include <fcntl.h>
 #include <signal.h>
 #include <sys/types.h>
