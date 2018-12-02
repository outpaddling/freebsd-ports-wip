--- src/plugins/switch/cray/switch_cray.c.orig	2018-10-24 20:21:46 UTC
+++ src/plugins/switch/cray/switch_cray.c
@@ -35,7 +35,6 @@
  *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 \*****************************************************************************/
 
-#if !(defined(__FreeBSD__) || defined(__NetBSD__))
 #include "config.h"
 
 #define _GNU_SOURCE
@@ -44,7 +43,9 @@
 #include <fcntl.h>
 #include <inttypes.h>
 #include <limits.h>
+#ifdef __linux__
 #include <linux/limits.h>
+#endif
 #include <math.h>
 #include <sched.h>
 #include <signal.h>
@@ -1056,4 +1057,3 @@ extern int switch_p_job_step_post_resume
 #endif
 	return SLURM_SUCCESS;
 }
-#endif /* !defined(__FreeBSD__) */
