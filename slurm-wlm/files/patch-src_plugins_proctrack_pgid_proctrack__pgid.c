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
@@ -193,32 +204,66 @@ proctrack_p_get_pids(uint64_t cont_id, pid_t **pids, i
 	pid_t *pid_array = NULL;
 	int pid_count = 0;
 
-	if ((dir = opendir("/proc")) == NULL) {
-		error("opendir(/proc): %m");
+#ifdef __FreeBSD__
+	struct procstat		*proc_info; 
+	struct kinfo_proc	*proc_list;
+	size_t			c;
+
+	proc_info = procstat_open_sysctl();
+	proc_list = procstat_getprocs(proc_info, KERN_PROC_PGRP, cont_id,
+					(unsigned *)&pid_count);
+
+	if ( pid_count > 0 )
+	{
+		xrealloc(pid_array, sizeof(pid_t) * pid_count);
+		for (c = 0; c < pid_count; ++c)
+		{
+			error("pid=%ld ppid=%ld pgid=%ld",
+				proc_list[c].ki_pid, proc_list[c].ki_ppid,
+				proc_list[c].ki_pgid);
+			pid_array[c] = proc_list[c].ki_pid;
+		}
+	}
+	else
+		error("No PIDs found in group %lu.", cont_id);
+
+	procstat_freeprocs(proc_info, proc_list);
+	procstat_close(proc_info);
+#else
+	// Is parsing files in /proc really the only way to get PIDs in Linux?
+	if ((dir = opendir("/compat/linux/proc")) == NULL) {
+		error("opendir(/compat/linux/proc): %m");
 		rc = SLURM_ERROR;
 		goto fini;
 	}
 	rbuf = xmalloc(4096);
 	while ((de = readdir(dir)) != NULL) {
 		num = de->d_name;
+		// Is this really sufficient to identify a procid directory?
 		if ((num[0] < '0') || (num[0] > '9'))
 			continue;
 		ret_l = strtol(num, &endptr, 10);
+		// Should check *endptr.  Should be '\0'.
+		// Just ignore failures to read process info??
 		if ((ret_l == LONG_MIN) || (ret_l == LONG_MAX)) {
 			error("couldn't do a strtol on str %s(%ld): %m",
 			      num, ret_l);
 			continue;
 		}
-		sprintf(path, "/proc/%s/stat", num);
+		// Use snprintf() here to protect against buffer overflow?
+		sprintf(path, "/compat/linux/proc/%s/stat", num);
 		if ((fd = open(path, O_RDONLY)) < 0) {
 			continue;
 		}
 		buf_used = read(fd, rbuf, 4096);
+		// Why not just read straight from stream with fscanf()?
+		// Just ignore failures to read process info??
 		if ((buf_used <= 0) || (buf_used >= 4096)) {
 			close(fd);
 			continue;
 		}
 		close(fd);
+		// Just ignore failures to read process info??
 		if (sscanf(rbuf, "%ld %s %c %ld %ld",
 			   &pid, cmd, &state, &ppid, &pgid) != 5) {
 			continue;
@@ -236,6 +281,7 @@ proctrack_p_get_pids(uint64_t cont_id, pid_t **pids, i
 	}
 	xfree(rbuf);
 	closedir(dir);
+#endif
 
 fini:	*pids  = pid_array;
 	*npids = pid_count;
