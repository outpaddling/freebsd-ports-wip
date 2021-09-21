--- src/common/cgroup.c.orig	2021-09-21 13:38:15 UTC
+++ src/common/cgroup.c
@@ -34,6 +34,8 @@
  *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 \*****************************************************************************/
 
+#ifndef __FreeBSD__
+
 #include "src/common/cgroup.h"
 
 /* Define slurm-specific aliases for use by plugins, see slurm_xlator.h. */
@@ -990,3 +992,5 @@ extern cgroup_acct_t *cgroup_g_task_get_acct_data(uint
 
 	return (*(ops.task_get_acct_data))(taskid);
 }
+
+#endif // __FreeBSD__
