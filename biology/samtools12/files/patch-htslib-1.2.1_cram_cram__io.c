--- htslib-1.2.1/cram/cram_io.c.orig	2015-02-25 15:21:40.060299935 -0600
+++ htslib-1.2.1/cram/cram_io.c	2015-02-25 15:21:58.790300666 -0600
@@ -53,6 +53,7 @@
 #include <assert.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #include <zlib.h>
 #ifdef HAVE_LIBBZ2
 #include <bzlib.h>
