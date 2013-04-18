--- src/slurmd/slurmd/get_mach_stat.c.orig	2013-03-08 13:37:58.000000000 -0600
+++ src/slurmd/slurmd/get_mach_stat.c	2013-03-27 18:32:27.000000000 -0500
@@ -55,6 +55,9 @@
 #endif
 
 #ifdef HAVE_SYS_SYSCTL_H
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#endif
 # include <sys/sysctl.h>
 #endif
 
