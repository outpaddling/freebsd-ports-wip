--- src/plugins/mpi/pmi2/setup.c.orig	2013-03-08 13:37:58.000000000 -0600
+++ src/plugins/mpi/pmi2/setup.c	2013-03-27 18:32:27.000000000 -0500
@@ -39,6 +39,10 @@
 #  include "config.h"
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/socket.h>	/* AF_INET */
+#endif
+
 #include <fcntl.h>
 #include <signal.h>
 #include <sys/types.h>
