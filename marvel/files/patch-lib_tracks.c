--- lib/tracks.c.orig	2018-03-08 10:04:51 UTC
+++ lib/tracks.c
@@ -10,12 +10,7 @@
 #include <unistd.h>
 #include <assert.h>
 
-#if defined(__APPLE__)
-#include <sys/syslimits.h>
-#else
-#include <linux/limits.h>
-#endif
-
+#include <limits.h>
 
 HITS_TRACK* track_load(HITS_DB *db, char* track)
 {
