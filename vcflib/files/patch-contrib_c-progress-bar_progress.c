--- contrib/c-progress-bar/progress.c.orig	2026-03-20 08:48:48 UTC
+++ contrib/c-progress-bar/progress.c
@@ -10,6 +10,7 @@
 #include <stdint.h>
 #include <sys/time.h>
 #include <progress.h>
+#include <inttypes.h>
 
 /* Specify how wide the progress bar should be. */
 #define PROGRESS_BAR_WIDTH 50
@@ -76,13 +77,13 @@ static void print_timedelta(uint64_t delta) {
     uint64_t mseconds = (delta / 100000) % 10;
 
     if (hours) {
-        fprintf(stderr,"%lluh %llum %llus    ", hours, minutes, seconds);
+        fprintf(stderr,"%" PRIu64 "h %" PRIu64 "m %" PRIu64 "s    ", hours, minutes, seconds);
     }
     else if (minutes) {
-        fprintf(stderr,"%llum %02llus        ", minutes, seconds);
+        fprintf(stderr,"%" PRIu64 "m %02" PRIu64 "s        ", minutes, seconds);
     }
     else {
-        fprintf(stderr,"%llu.%llus           ", seconds, mseconds);
+        fprintf(stderr,"%" PRIu64 ".%" PRIu64 "s           ", seconds, mseconds);
     }
 }
 
