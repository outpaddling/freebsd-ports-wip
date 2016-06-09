--- src/plugins/task/affinity/affinity.c.orig	2016-06-08 21:20:12.050179170 -0500
+++ src/plugins/task/affinity/affinity.c	2016-06-08 21:50:16.291053863 -0500
@@ -336,7 +336,11 @@ void reset_cpuset(cpu_set_t *new_mask, c
 	if (slurm_getaffinity(1, sizeof(full_mask), &full_mask)) {
 		/* Try to get full CPU mask from process init */
 		CPU_ZERO(&full_mask);
+#ifdef __FreeBSD__
+		CPU_OR(&full_mask, cur_mask);
+#else
 		CPU_OR(&full_mask, &full_mask, cur_mask);
+#endif
 	}
 	CPU_ZERO(&newer_mask);
 	for (cur_offset = 0; cur_offset < CPU_SETSIZE; cur_offset++) {
@@ -361,7 +365,10 @@ int slurm_setaffinity(pid_t pid, size_t 
 	int rval;
 	char mstr[1 + CPU_SETSIZE / 4];
 
-#ifdef SCHED_GETAFFINITY_THREE_ARGS
+#ifdef __FreeBSD__
+        rval = cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID,
+				pid, size, mask);
+#elif SCHED_GETAFFINITY_THREE_ARGS
 	rval = sched_setaffinity(pid, size, mask);
 #else
 	rval = sched_setaffinity(pid, mask);
@@ -379,7 +386,10 @@ int slurm_getaffinity(pid_t pid, size_t 
 	char mstr[1 + CPU_SETSIZE / 4];
 
 	CPU_ZERO(mask);
-#ifdef SCHED_GETAFFINITY_THREE_ARGS
+#ifdef __FreeBSD__
+        rval = cpuset_getaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID,
+				pid, size, mask);
+#elif SCHED_GETAFFINITY_THREE_ARGS
 	rval = sched_getaffinity(pid, size, mask);
 #else
 	rval = sched_getaffinity(pid, mask);
