--- src/slurmd/common/setproctitle.c.orig	2013-03-08 13:37:58.000000000 -0600
+++ src/slurmd/common/setproctitle.c	2013-03-27 18:32:27.000000000 -0500
@@ -90,6 +90,9 @@
 #include <stdlib.h>
 #include <string.h>
 #endif
+#if defined(__FreeBSD__)
+#include <stdio.h>
+#endif
 #ifndef HAVE_SETPROCTITLE
 #include <stdlib.h>
 #include <stdio.h>
@@ -265,7 +268,7 @@
 	save_argc = argc;
 	save_argv = argv;
 
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 	setprogname (argv[0]);
 #else
 	_init__progname (argv[0]);
