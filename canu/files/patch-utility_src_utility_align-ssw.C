--- utility/src/utility/align-ssw.C.orig	2021-12-17 23:37:21 UTC
+++ utility/src/utility/align-ssw.C
@@ -33,7 +33,8 @@
  */
 
 //#include <nmmintrin.h>
-#include <emmintrin.h>
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde/x86/sse2.h>
 #include <stdint.h>
 #include <stdlib.h>
 #include <stdio.h>
