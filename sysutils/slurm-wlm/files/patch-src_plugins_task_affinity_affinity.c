--- src/plugins/task/affinity/affinity.c.orig	2016-05-31 16:35:09.000000000 -0500
+++ src/plugins/task/affinity/affinity.c	2016-06-10 13:59:48.753204000 -0500
@@ -291,12 +291,34 @@ int get_cpuset(cpu_set_t *mask, stepd_st
 	return false;
 }
 
+/* For sysctl() functions */
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
+#define	BUFFLEN	127
+
 /* Return true if Power7 processor */
 static bool _is_power_cpu(void)
 {
 	if (is_power == -1) {
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+
+		char    buffer[BUFFLEN+1];
+		size_t  len = BUFFLEN;
+    
+		if ( sysctlbyname("hw.model", buffer, &len, NULL, 0) == 0 )
+		    is_power = ( strstr(buffer, "POWER7") != NULL );
+		else {
+		    error("_get_is_power: sysctl could not retrieve hw.model");
+		    return false;
+		}
+
+#elif defined(__linux__)
+
 		FILE *cpu_info_file;
-		char buffer[128];
+		char buffer[BUFFLEN+1];
 		char* _cpuinfo_path = "/proc/cpuinfo";
 		cpu_info_file = fopen(_cpuinfo_path, "r");
 		if (cpu_info_file == NULL) {
@@ -313,6 +335,14 @@ static bool _is_power_cpu(void)
 			}
 		}
 		fclose(cpu_info_file);
+
+#else
+
+/* Assuming other platforms don't support sysctlbyname() or /proc/cpuinfo */
+#warning	"Power7 check not implemented for this platform."
+	is_power = 0;
+
+#endif
 	}
 
 	if (is_power == 1)
@@ -336,7 +366,11 @@ void reset_cpuset(cpu_set_t *new_mask, c
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
@@ -361,7 +395,10 @@ int slurm_setaffinity(pid_t pid, size_t 
 	int rval;
 	char mstr[1 + CPU_SETSIZE / 4];
 
-#ifdef SCHED_GETAFFINITY_THREE_ARGS
+#ifdef __FreeBSD__
+        rval = cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID,
+				pid, size, mask);
+#elif defined(SCHED_GETAFFINITY_THREE_ARGS)
 	rval = sched_setaffinity(pid, size, mask);
 #else
 	rval = sched_setaffinity(pid, mask);
@@ -379,7 +416,19 @@ int slurm_getaffinity(pid_t pid, size_t 
 	char mstr[1 + CPU_SETSIZE / 4];
 
 	CPU_ZERO(mask);
-#ifdef SCHED_GETAFFINITY_THREE_ARGS
+
+	/*
+	 * The FreeBSD cpuset API is a superset of the Linux API.
+	 * In addition to PIDs, it supports threads, interrupts,
+	 * jails, and potentially other objects.  The first two arguments
+	 * to cpuset_*etaffinity() below indicate that the third argument
+	 * is a PID.  -1 indicates the PID of the calling process.
+	 * Linux sched_*etaffinity() uses 0 for this.
+	 */
+#ifdef __FreeBSD__
+        rval = cpuset_getaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID,
+				pid, size, mask);
+#elif defined(SCHED_GETAFFINITY_THREE_ARGS)
 	rval = sched_getaffinity(pid, size, mask);
 #else
 	rval = sched_getaffinity(pid, mask);
