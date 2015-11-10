--- src/api/internal/io/TcpSocketEngine_unix_p.cpp.orig	2015-11-10 12:40:19.000000000 -0600
+++ src/api/internal/io/TcpSocketEngine_unix_p.cpp	2015-11-10 12:40:33.000000000 -0600
@@ -12,6 +12,8 @@
 using namespace BamTools;
 using namespace BamTools::Internal;
 
+#include <netinet/in.h>
+
 #ifdef SUN_OS
 #include <sys/filio.h> 
 #endif
