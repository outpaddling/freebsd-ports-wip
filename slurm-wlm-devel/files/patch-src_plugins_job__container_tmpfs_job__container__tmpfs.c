--- src/plugins/job_container/tmpfs/job_container_tmpfs.c.orig	2021-05-12 20:23:16 UTC
+++ src/plugins/job_container/tmpfs/job_container_tmpfs.c
@@ -38,6 +38,8 @@
  *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 \*****************************************************************************/
 
+#ifndef __FreeBSD__
+
 #define _GNU_SOURCE
 #define _XOPEN_SOURCE 500 /* For ftw.h */
 #include <errno.h>
@@ -824,3 +826,5 @@ extern int container_p_delete(uint32_t job_id)
 {
 	return _delete_ns(job_id);
 }
+
+#endif // #ifndef __FreeBSD__
