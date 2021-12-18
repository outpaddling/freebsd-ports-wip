--- utility/src/utility/align-ssw.H.orig	2021-12-17 23:38:08 UTC
+++ utility/src/utility/align-ssw.H
@@ -33,8 +33,8 @@
 #include <stdio.h>
 #include <stdint.h>
 #include <string.h>
-#include <emmintrin.h>
-
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde/x86/sse2.h>
 
 #define MAPSTR "MIDNSHP=X"
 #ifndef BAM_CIGAR_SHIFT
