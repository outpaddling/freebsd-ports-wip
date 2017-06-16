--- ./src/cpp/core/system/PosixChildProcess.cpp.orig	2013-12-13 11:18:24.000000000 -0500
+++ ./src/cpp/core/system/PosixChildProcess.cpp	2013-12-13 11:19:09.000000000 -0500
@@ -23,6 +23,11 @@
 #include <util.h>
 #include <sys/ttycom.h>
 #include <sys/ioctl.h>
+#elif defined __FreeBSD__
+#include <libutil.h>
+#include <sys/ttycom.h>
+#include <sys/ioctl.h>
+#include <termios.h>
 #else
 #include <pty.h>
 #include <asm/ioctls.h>
