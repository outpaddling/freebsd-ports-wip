--- src/srun/libsrun/srun_job.c.orig	2018-09-30 05:41:23 UTC
+++ src/srun/libsrun/srun_job.c
@@ -105,6 +105,11 @@ static int shepherd_fd = -1;
 static pthread_t signal_thread = (pthread_t) 0;
 static int pty_sigarray[] = { SIGWINCH, 0 };
 
+#ifdef __FreeBSD__
+#define __environ environ
+extern char **environ;
+#endif
+
 /*
  * Prototypes:
  */
