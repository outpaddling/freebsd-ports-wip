--- src/plugins/task/cgroup/task_cgroup_cpuset.c.orig	2014-02-27 08:10:21.000000000 -0600
+++ src/plugins/task/cgroup/task_cgroup_cpuset.c	2014-02-27 08:12:29.000000000 -0600
@@ -60,7 +60,14 @@
 
 #ifdef HAVE_HWLOC
 #include <hwloc.h>
+
+#if !defined(__FreeBSD__)
 #include <hwloc/glibc-sched.h>
+#else
+// For cpuset
+#include <pthread_np.h>
+#define cpu_set_t cpuset_t
+#endif
 
 # if HWLOC_API_VERSION <= 0x00010000
 /* After this version the cpuset structure and all it's functions
