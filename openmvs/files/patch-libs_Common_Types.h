--- libs/Common/Types.h.orig	2016-04-06 15:59:29.000000000 -0500
+++ libs/Common/Types.h	2016-09-16 00:16:19.182458812 -0500
@@ -180,6 +180,21 @@ namespace cv { namespace gpu = cuda; }
 #  define __THREAD__ ((unsigned)GetCurrentThreadId())
 # else
 #  include <sys/syscall.h>
+// https://www.percona.com/forums/questions-discussions/percona-xtradb-cluster/24029-compilation-errors-sys_gettid-undeclared-expected-before-sigev_value
+#ifndef SYS_gettid
+    // i386: 224, ia64: 1105, amd64: 186, sparc 143
+    #ifdef __ia64__
+        #define SYS_gettid 1105
+    #elif __i386__
+        #define SYS_gettid 224
+    #elif __amd64__
+        #define SYS_gettid 186
+    #elif __sparc__
+        #define SYS_gettid 143
+    #else
+        #error define gettid for the arch
+    #endif
+#endif
 #  define __THREAD__ ((unsigned)((pid_t)syscall(SYS_gettid)))
 # endif
 #endif
@@ -331,7 +346,7 @@ FORCEINLINE T RANDOM() { return (T(1)/RA
 # define __BIG_ENDIAN 1
 # define __PDP_ENDIAN 2
 # define __BYTE_ORDER __LITTLE_ENDIAN
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 # include <machine/endian.h>
 #elif defined(__GNUC__)
 # include <endian.h>
