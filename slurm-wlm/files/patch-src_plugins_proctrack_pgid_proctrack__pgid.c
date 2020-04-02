--- src/plugins/proctrack/pgid/proctrack_pgid.c.orig	2020-03-26 21:44:05 UTC
+++ src/plugins/proctrack/pgid/proctrack_pgid.c
@@ -49,6 +49,13 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <libprocstat.h>
+#endif
+
 #include "slurm/slurm.h"
 #include "slurm/slurm_errno.h"
 #include "src/common/log.h"
@@ -179,6 +186,10 @@ proctrack_p_wait(uint64_t cont_id)
 	return SLURM_SUCCESS;
 }
 
+
+/*
+ * Get list of all PIDs belonging to process group cont_id
+ */
 extern int
 proctrack_p_get_pids(uint64_t cont_id, pid_t **pids, int *npids)
 {
@@ -193,8 +204,22 @@ proctrack_p_get_pids(uint64_t cont_id, pid_t **pids, i
 	pid_t *pid_array = NULL;
 	int pid_count = 0;
 
-	if ((dir = opendir("/proc")) == NULL) {
-		error("opendir(/proc): %m");
+#ifdef __FreeBSD__
+	struct procstat		*procs; 
+	struct kinfo_proc	*proc_list;
+	size_t			c;
+
+	procs = procstat_open_sysctl();
+	proc_list = procstat_getprocs(procs, KERN_PROC_PGRP, cont_id,
+					(unsigned *)&pid_count);
+	procstat_close(procs);
+
+	xrealloc(pid_array, sizeof(pid_t) * pid_count);
+	for (c = 0; c < pid_count; ++c)
+		pid_array[c] = proc_list[c].ki_pid;
+#else
+	if ((dir = opendir("/compat/linux/proc")) == NULL) {
+		error("opendir(/compat/linux/proc): %m");
 		rc = SLURM_ERROR;
 		goto fini;
 	}
@@ -209,11 +234,12 @@ proctrack_p_get_pids(uint64_t cont_id, pid_t **pids, i
 			      num, ret_l);
 			continue;
 		}
-		sprintf(path, "/proc/%s/stat", num);
+		sprintf(path, "/compat/linux/proc/%s/stat", num);
 		if ((fd = open(path, O_RDONLY)) < 0) {
 			continue;
 		}
 		buf_used = read(fd, rbuf, 4096);
+		// Just ignore failures to read process info??
 		if ((buf_used <= 0) || (buf_used >= 4096)) {
 			close(fd);
 			continue;
@@ -236,6 +262,7 @@ proctrack_p_get_pids(uint64_t cont_id, pid_t **pids, i
 	}
 	xfree(rbuf);
 	closedir(dir);
+#endif
 
 fini:	*pids  = pid_array;
 	*npids = pid_count;
