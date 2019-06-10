--- src/plugins/proctrack/pgid/proctrack_pgid.c.orig	2019-06-10 02:34:48 UTC
+++ src/plugins/proctrack/pgid/proctrack_pgid.c
@@ -194,7 +194,7 @@ proctrack_p_get_pids(uint64_t cont_id, p
 	int pid_count = 0;
 
 	if ((dir = opendir("/proc")) == NULL) {
-		error("opendir(/proc): %m");
+		error("proctrack_p_get_pids: opendir(/proc): %m");
 		rc = SLURM_ERROR;
 		goto fini;
 	}
