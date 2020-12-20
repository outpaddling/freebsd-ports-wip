--- awka/scan.c.orig	2020-12-20 21:59:14 UTC
+++ awka/scan.c
@@ -37,6 +37,8 @@
 #include  "repl.h"
 #include  "code.h"
 
+#include <unistd.h>
+
 #ifndef          NO_FCNTL_H
 #include  <fcntl.h>
 #endif
