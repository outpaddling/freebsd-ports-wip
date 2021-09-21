--- src/plugins/cgroup/v1/xcgroup.c.orig	2021-09-21 13:46:04 UTC
+++ src/plugins/cgroup/v1/xcgroup.c
@@ -35,6 +35,8 @@
  *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 \*****************************************************************************/
 
+#ifdef __linux__
+
 #include "cgroup_v1.h"
 
 extern int xcgroup_ns_create(xcgroup_ns_t *cgns, char *mnt_args,
@@ -616,3 +618,5 @@ endit:
 
 	return rc;
 }
+
+#endif // __linux__
