--- src/vsearch.h.orig	2018-02-16 17:08:01 UTC
+++ src/vsearch.h
@@ -119,30 +119,40 @@
 
 #ifdef _WIN32
 
-#define PROG_OS "win"
-#include <windows.h>
-#include <psapi.h>
+# define PROG_OS "win"
+# include <windows.h>
+# include <psapi.h>
 
-#else
+#else	// Any Unix
 
-#ifdef __APPLE__
+# ifdef __APPLE__
 
-#define PROG_OS "macos"
-#include <sys/sysctl.h>
+#  define PROG_OS "macos"
+#  include <sys/sysctl.h>
 
-#else
+# else	// Not Apple
 
-#ifdef __linux__
-#define PROG_OS "linux"
-#else
-#define PROG_OS "unknown"
-#endif
+#  ifdef __linux__
+#   define PROG_OS "linux"
 
-#include <sys/sysinfo.h>
+#  else	// Not Apple or Linux
 
-#endif
+#   ifdef __FreeBSD__
+#    define PROG_OS "freebsd"
 
-#include <sys/resource.h>
+#   else	// None of the above
+
+#    define PROG_OS "unknown"
+
+#   endif
+
+#   include <sys/sysinfo.h>
+ 
+#  endif
+
+# endif
+
+# include <sys/resource.h>
 
 #endif
 
