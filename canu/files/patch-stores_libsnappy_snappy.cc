--- stores/libsnappy/snappy.cc.orig	2021-12-17 23:40:42 UTC
+++ stores/libsnappy/snappy.cc
@@ -40,7 +40,8 @@
 #endif
 
 #if SNAPPY_HAVE_SSE2
-#include <emmintrin.h>
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde/x86/sse2.h>
 #endif
 #include <stdio.h>
 
