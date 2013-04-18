--- src/plugins/mpi/pmi2/setup.c.orig	2013-03-27 10:55:35.000000000 -0500
+++ src/plugins/mpi/pmi2/setup.c	2013-03-27 10:56:04.000000000 -0500
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
