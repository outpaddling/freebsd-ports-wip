--- cprime/filefunc.cpp.orig	2021-07-28 13:04:59 UTC
+++ cprime/filefunc.cpp
@@ -34,7 +34,7 @@
 #include <libgen.h>
 #include <sys/types.h>
 #include <sys/statvfs.h>
-#include <sys/statfs.h>
+// #include <sys/statfs.h>
 #include <unistd.h>
 
 #include "filefunc.h"
