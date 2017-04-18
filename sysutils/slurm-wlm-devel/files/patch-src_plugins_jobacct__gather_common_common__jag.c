--- src/plugins/jobacct_gather/common/common_jag.c.orig	2017-01-31 13:55:41.000000000 -0600
+++ src/plugins/jobacct_gather/common/common_jag.c	2017-04-18 14:30:59.292164698 -0500
@@ -212,6 +212,13 @@ static int _get_sys_interface_freq_line(
 	} else {
 		/* frequency scaling not enabled */
 		if (!cpunfo_frequency) {
+#if defined(__FreeBSD__)
+			/* Make sure this is the right sysctl variable */
+			sysctlbyname("machdep.tsc_freq", cpunfo_line,
+				sizeof(cpunfo_line), NULL, NULL);
+			/* Sysctl reports in Hz, convert to MHz */
+			cpunfo_frequency = atoi(cpunfo_line) / 1000000;
+#else	/* Assume Linux procfs */
 			snprintf(freq_file, 14, "/proc/cpuinfo");
 			debug2("_get_sys_interface_freq_line: filename = %s ",
 			       freq_file);
@@ -223,6 +230,7 @@ static int _get_sys_interface_freq_line(
 				}
 				fclose(sys_fp);
 			}
+#endif
 		}
 		return 1;
 	}
