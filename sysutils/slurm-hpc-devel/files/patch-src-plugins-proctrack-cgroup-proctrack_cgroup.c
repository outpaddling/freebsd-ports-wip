--- src/plugins/proctrack/cgroup/proctrack_cgroup.c.orig	2013-03-27 10:57:45.000000000 -0500
+++ src/plugins/proctrack/cgroup/proctrack_cgroup.c	2013-03-27 10:58:04.000000000 -0500
@@ -50,6 +50,10 @@
 #include <sys/signal.h> /* for SIGKILL */
 #endif
 
+#if defined(__FreeBSD__)
+#include <signal.h>
+#endif
+
 #include "slurm/slurm.h"
 #include "slurm/slurm_errno.h"
 #include "src/common/log.h"
