--- src/common/xcgroup.h.orig	2013-03-08 13:37:58.000000000 -0600
+++ src/common/xcgroup.h	2013-03-27 18:32:27.000000000 -0500
@@ -48,6 +48,15 @@
 #define XCGROUP_ERROR    1
 #define XCGROUP_SUCCESS  0
 
+// http://lists.debian.org/debian-boot/2012/04/msg00047.html
+#if defined(__FreeBSD__)
+#define	MS_NOSUID	MNT_NOSUID
+#define	MS_NOEXEC	MNT_NOEXEC
+#define	MS_NODEV	0
+
+#define	umount(d)	unmount(d, 0)
+#endif
+
 typedef struct xcgroup_ns {
 
 	char* mnt_point;  /* mount point to use for the associated cgroup */
