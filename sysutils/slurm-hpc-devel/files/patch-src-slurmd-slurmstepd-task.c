--- src/slurmd/slurmstepd/task.c.orig	2013-03-27 09:54:00.000000000 -0500
+++ src/slurmd/slurmstepd/task.c	2013-03-27 09:59:07.000000000 -0500
@@ -500,6 +500,11 @@
 		 * has been around for a while.  So to make sure we
 		 * still work with older systems we include this check.
 		 */
+
+#if defined(__FreeBSD__)
+#define	__GLIBC__ 		(1)
+#define __GLIBC_PREREQ(a,b)	(1)
+#endif
 #if defined __GLIBC__ && __GLIBC_PREREQ(2, 4)
 		else if (eaccess(tmpdir, X_OK|W_OK)) /* check permissions */
 #else
