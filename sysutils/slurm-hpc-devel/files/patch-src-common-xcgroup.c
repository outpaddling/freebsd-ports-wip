--- src/common/xcgroup.c.orig	2013-03-27 09:28:23.000000000 -0500
+++ src/common/xcgroup.c	2013-03-27 09:29:08.000000000 -0500
@@ -217,8 +217,13 @@
 		options = opt_combined;
 	}
 
+#if defined(__FreeBSD__)
+	if (mount("cgroup", cgns->mnt_point,
+		  MS_NOSUID|MS_NOEXEC|MS_NODEV, options))
+#else
 	if (mount("cgroup", cgns->mnt_point, "cgroup",
 		  MS_NOSUID|MS_NOEXEC|MS_NODEV, options))
+#endif
 		return XCGROUP_ERROR;
 	else {
 		/* FIXME: this only gets set when we aren't mounted at
