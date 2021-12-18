--- utility/src/parasail/cpuid.c.orig	2021-08-04 00:23:37 UTC
+++ utility/src/parasail/cpuid.c
@@ -13,6 +13,9 @@
 
 #include "parasail/cpuid.h"
 
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde/x86/sse4.2.h>
+
 #include <stdint.h>
 #if defined(_MSC_VER)
 # include <intrin.h>
