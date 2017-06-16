--- src/plugins/task/affinity/affinity.h.orig	2016-05-03 17:41:59.000000000 -0500
+++ src/plugins/task/affinity/affinity.h	2016-06-09 19:55:26.233573140 -0500
@@ -33,6 +33,18 @@
  *  with SLURM; if not, write to the Free Software Foundation, Inc.,
  *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 \*****************************************************************************/
+
+/*
+ * FreeBSD and Linux affinity functions have a slightly different interface
+ * and are defined in different headers.  See platform-dependencies in
+ * affinity.c.
+ */
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/cpuset.h>
+typedef cpuset_t cpu_set_t;
+#endif
+
 #ifdef HAVE_CONFIG_H
 #  include "config.h"
 #endif
