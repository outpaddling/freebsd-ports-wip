--- src/srun/libsrun/srun_job.c.orig	2018-12-02 13:33:29 UTC
+++ src/srun/libsrun/srun_job.c
@@ -108,6 +108,10 @@ typedef struct pack_resp_struct {
 	uint32_t node_cnt;
 } pack_resp_struct_t;
 
+#ifdef __FreeBSD__
+#define	__environ environ
+extern char **environ;
+#endif
 
 static int shepherd_fd = -1;
 static pthread_t signal_thread = (pthread_t) 0;
