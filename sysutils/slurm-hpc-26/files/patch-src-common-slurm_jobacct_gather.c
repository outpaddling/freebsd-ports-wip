--- src/common/slurm_jobacct_gather.c.orig	2013-03-08 13:37:58.000000000 -0600
+++ src/common/slurm_jobacct_gather.c	2013-03-27 18:32:27.000000000 -0500
@@ -47,6 +47,9 @@
  *  	 Morris Jette, et al.
 \*****************************************************************************/
 
+#if defined(__FreeBSD__)
+#include <signal.h>
+#endif
 #include <pthread.h>
 #include <stdlib.h>
 #include <string.h>
