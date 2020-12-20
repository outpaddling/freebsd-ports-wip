--- lib/builtin.c.orig	2020-12-20 21:30:08 UTC
+++ lib/builtin.c
@@ -21,6 +21,7 @@
 #include <limits.h>
 #include <ctype.h>
 #include <errno.h>
+#include <unistd.h>
 
 #ifndef NO_TIME_H
 #  include <time.h>
