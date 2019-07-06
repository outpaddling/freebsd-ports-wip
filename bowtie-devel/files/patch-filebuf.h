--- filebuf.h.orig	2019-07-06 13:06:52 UTC
+++ filebuf.h
@@ -14,6 +14,7 @@
 #include <stdint.h>
 #include <stdexcept>
 #include <fcntl.h>
+#include <unistd.h>
 #include <zlib.h>
 #include "assert_helpers.h"
 
