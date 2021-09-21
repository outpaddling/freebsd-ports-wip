--- src/plugins/cgroup/v1/cgroup_v1.c.orig	2021-09-21 13:47:11 UTC
+++ src/plugins/cgroup/v1/cgroup_v1.c
@@ -34,6 +34,8 @@
  *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 \*****************************************************************************/
 
+#ifdef __linux__
+
 #define _GNU_SOURCE
 
 #include "cgroup_v1.h"
@@ -1557,3 +1559,5 @@ extern cgroup_acct_t *cgroup_p_task_get_acct_data(uint
 
 	return stats;
 }
+
+#endif
