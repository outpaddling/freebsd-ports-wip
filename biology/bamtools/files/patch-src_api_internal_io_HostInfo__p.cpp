--- src/api/internal/io/HostInfo_p.cpp.orig	2015-11-10 12:27:36.000000000 -0600
+++ src/api/internal/io/HostInfo_p.cpp	2015-11-10 12:42:10.000000000 -0600
@@ -11,6 +11,8 @@
 using namespace BamTools;
 using namespace BamTools::Internal;
 
+#include <netinet/in.h>
+
 // platorm-specifics
 #ifdef _WIN32
 #  include "api/internal/io/NetWin_p.h"
