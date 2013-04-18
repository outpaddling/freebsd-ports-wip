--- src/slurmd/common/setproctitle.c.orig	2013-03-27 09:43:43.000000000 -0500
+++ src/slurmd/common/setproctitle.c	2013-03-27 09:53:07.000000000 -0500
@@ -89,6 +89,9 @@
 #include <stdlib.h>
 #include <string.h>
 #endif
+#if defined(__FreeBSD__)
+#include <stdio.h>
+#endif
 #ifndef HAVE_SETPROCTITLE
 #include <stdlib.h>
 #include <stdio.h>
@@ -264,7 +267,7 @@
 	save_argc = argc;
 	save_argv = argv;
 
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 	setprogname (argv[0]);
 #else
 	_init__progname (argv[0]);
