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
@@ -193,6 +204,51 @@ proctrack_p_get_pids(uint64_t cont_id, pid_t **pids, i
 	pid_t *pid_array = NULL;
 	int pid_count = 0;
 
+	// error("INFO: proctrack_p_get_pids() called.");
+
+#ifdef __FreeBSD__
+	struct procstat		*proc_info; 
+	struct kinfo_proc	*proc_list;
+	size_t			c;
+	FILE			*procstat_err;
+
+	proc_info = procstat_open_sysctl();
+
+	/* procstat_getprocs() prints an innocuous but annoying warning
+	   to stderr by default when no matching processes are found:
+
+		kinfo_proc structure size mismatch (len = 0)
+
+	   Silence by redirecting to /dev/null.
+	*/
+	if ( (procstat_err = fopen("/dev/null", "w+")) != NULL )
+		err_set_file(procstat_err);
+	proc_list = procstat_getprocs(proc_info, KERN_PROC_PGRP, cont_id,
+					(unsigned *)&pid_count);
+	if ( procstat_err != NULL )
+		fclose(procstat_err);
+
+	if ( pid_count > 0 )
+	{
+		xrealloc(pid_array, sizeof(pid_t) * pid_count);
+		// FIXME: Do we need to filter zombies like the Linux code?
+		// proc_list[c].ki_paddr->p_state == PRS_ZOMBIE
+		for (c = 0; c < pid_count; ++c)
+		{
+			/* error("INFO: command=%s pid=%ld ppid=%ld pgid=%ld",
+				proc_list[c].ki_comm,
+				// srun hangs trying to access this
+				//proc_list[c].ki_paddr->p_state,
+				proc_list[c].ki_pid, proc_list[c].ki_ppid,
+				proc_list[c].ki_pgid); */
+			pid_array[c] = proc_list[c].ki_pid;
+		}
+	}
+
+	procstat_freeprocs(proc_info, proc_list);
+	procstat_close(proc_info);
+#else
+	// Is parsing files in /proc the only way to collect PIDs on Linux?
 	if ((dir = opendir("/proc")) == NULL) {
 		error("opendir(/proc): %m");
 		rc = SLURM_ERROR;
@@ -201,32 +257,56 @@ proctrack_p_get_pids(uint64_t cont_id, pid_t **pids, i
 	rbuf = xmalloc(4096);
 	while ((de = readdir(dir)) != NULL) {
 		num = de->d_name;
+
+		// Is this sufficient to identify a PID directory?
+		// Should verify that *endptr == '\0'.
 		if ((num[0] < '0') || (num[0] > '9'))
 			continue;
 		ret_l = strtol(num, &endptr, 10);
+
+		// Is this useful?  Existence of /proc/%s/stat
+		// is what really matters.
 		if ((ret_l == LONG_MIN) || (ret_l == LONG_MAX)) {
 			error("couldn't do a strtol on str %s(%ld): %m",
 			      num, ret_l);
 			continue;
 		}
+
+		// Use snprintf() here to protect against buffer overflow?
 		sprintf(path, "/proc/%s/stat", num);
 		if ((fd = open(path, O_RDONLY)) < 0) {
 			continue;
 		}
+
+		// Why not read straight from stream with fscanf()?
 		buf_used = read(fd, rbuf, 4096);
+
+		// Just ignore failures to read process info?
+		// No error reporting?
 		if ((buf_used <= 0) || (buf_used >= 4096)) {
 			close(fd);
 			continue;
 		}
 		close(fd);
+
+		// Just ignore failures to read process info?
+		// No error reporting?  If this fails after a successful
+		// fopen(), something is very wrong and it should probably
+		// be flagged to facilate debugging
 		if (sscanf(rbuf, "%ld %s %c %ld %ld",
 			   &pid, cmd, &state, &ppid, &pgid) != 5) {
 			continue;
 		}
+		
 		if (pgid != (long) cont_id)
 			continue;
+
+		/* error("INFO: command=%s state=%c "
+		       "pid=%ld ppid=%ld pgid=%ld",
+		       cmd, state, pid, ppid, pgid); */
+
 		if (state == 'Z') {
-			debug3("Defunct process skipped: command=%s state=%c "
+			error("Defunct process skipped: command=%s state=%c "
 			       "pid=%ld ppid=%ld pgid=%ld",
 			       cmd, state, pid, ppid, pgid);
 			continue;	/* Defunct, don't try to kill */
@@ -236,6 +316,7 @@ proctrack_p_get_pids(uint64_t cont_id, pid_t **pids, i
 	}
 	xfree(rbuf);
 	closedir(dir);
+#endif
 
 fini:	*pids  = pid_array;
 	*npids = pid_count;
