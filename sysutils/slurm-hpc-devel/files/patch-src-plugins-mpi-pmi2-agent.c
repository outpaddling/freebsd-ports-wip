--- src/plugins/mpi/pmi2/agent.c.orig	2013-03-27 10:07:23.000000000 -0500
+++ src/plugins/mpi/pmi2/agent.c	2013-03-27 10:52:44.000000000 -0500
@@ -39,6 +39,11 @@
 #  include "config.h"
 #endif
 
+#if defined(__FreeBSD__)
+#include <roken.h>
+#include <sys/socket.h>	/* AF_INET */
+#endif
+
 #include <fcntl.h>
 #include <signal.h>
 #include <sys/types.h>
