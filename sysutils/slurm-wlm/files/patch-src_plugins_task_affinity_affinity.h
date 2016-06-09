--- src/plugins/task/affinity/affinity.h.orig	2016-06-08 21:15:07.540204151 -0500
+++ src/plugins/task/affinity/affinity.h	2016-06-08 21:18:48.221192796 -0500
@@ -33,6 +33,13 @@
  *  with SLURM; if not, write to the Free Software Foundation, Inc.,
  *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 \*****************************************************************************/
+
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/cpuset.h>
+typedef cpuset_t cpu_set_t;
+#endif
+
 #ifdef HAVE_CONFIG_H
 #  include "config.h"
 #endif
