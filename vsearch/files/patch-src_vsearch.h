--- src/vsearch.h.orig	2018-02-16 17:08:01 UTC
+++ src/vsearch.h
@@ -123,29 +123,29 @@
 #include <windows.h>
 #include <psapi.h>
 
-#else
-
-#ifdef __APPLE__
+#elif defined __APPLE__
 
 #define PROG_OS "macos"
 #include <sys/sysctl.h>
+#include <sys/resource.h>
 
-#else
+#elif defined __linux__
 
-#ifdef __linux__
 #define PROG_OS "linux"
-#else
-#define PROG_OS "unknown"
-#endif
-
 #include <sys/sysinfo.h>
+#include <sys/resource.h>
 
-#endif
+#elif defined __FreeBSD__
 
+#define PROG_OS "freebsd"
+#include <sys/sysinfo.h>
 #include <sys/resource.h>
 
-#endif
+#else
 
+#define PROG_OS "unknown"
+
+#endif
 
 #define PROG_ARCH PROG_OS "_" PROG_CPU
 
