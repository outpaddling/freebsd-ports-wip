--- src/condor_includes/condor_sys_bsd.h.orig	2014-11-10 22:15:16.000000000 -0600
+++ src/condor_includes/condor_sys_bsd.h	2014-11-10 22:16:24.000000000 -0600
@@ -41,11 +41,12 @@
 #include <stdarg.h>
 
 /* BSD also declares a dprintf, wonder of wonders */
-#   define dprintf _hide_dprintf
-#   define getline _hide_getline
+/* Actually, dprintf is a common extension, also present in CentOS stdio.h */
+//#   define dprintf _hide_dprintf
+//#   define getline _hide_getline
 #include <stdio.h>
-#   undef dprintf
-#   undef getline
+//#   undef dprintf
+//#   undef getline
 
 
 /* There is no <sys/select.h> on HPUX, select() and friends are 
