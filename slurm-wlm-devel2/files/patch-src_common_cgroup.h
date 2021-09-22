--- src/common/cgroup.h.orig	2021-09-22 13:21:27 UTC
+++ src/common/cgroup.h
@@ -34,6 +34,8 @@
  *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 \*****************************************************************************/
 
+#ifdef __linux__
+
 #ifndef _COMMON_CGROUP_H_
 #define _COMMON_CGROUP_H_
 
@@ -213,3 +215,5 @@ extern int cgroup_g_task_addto(cgroup_ctl_type_t sub, 
 extern cgroup_acct_t *cgroup_g_task_get_acct_data(uint32_t taskid);
 
 #endif
+
+#endif  // __linux__
