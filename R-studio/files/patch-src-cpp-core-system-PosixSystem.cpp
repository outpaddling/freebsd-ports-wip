--- src/cpp/core/system/PosixSystem.cpp.orig	2012-03-05 13:29:44.000000000 -0600
+++ src/cpp/core/system/PosixSystem.cpp	2012-03-05 13:29:54.000000000 -0600
@@ -25,7 +25,7 @@
 #include <sys/wait.h>
 #include <unistd.h>
 
-#include <uuid/uuid.h>
+#include <uuid.h>
 
 #ifdef __APPLE__
 #include <mach-o/dyld.h>
