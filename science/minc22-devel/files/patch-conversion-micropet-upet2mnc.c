--- conversion/micropet/upet2mnc.c.orig	2013-10-28 20:55:32.000000000 -0500
+++ conversion/micropet/upet2mnc.c	2013-10-28 20:55:43.000000000 -0500
@@ -8,6 +8,7 @@
 #include <float.h>
 #include <time.h>
 #include <string.h>
+#include <ctype.h>
 #include <minc.h>
 #include <time_stamp.h>
 #include <ParseArgv.h>
