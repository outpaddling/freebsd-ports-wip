--- SFMT.h.orig	2026-08-17 12:19:05 UTC
+++ SFMT.h
@@ -129,7 +129,9 @@ extern "C" {
   128-bit SIMD like data type for standard C
   ------------------------------------------*/
 #ifdef __LP64__
-  #include <emmintrin.h>
+  // #include <emmintrin.h>
+  #define SIMDE_ENABLE_NATIVE_ALIASES
+  #include <simde/x86/sse2.h>
 
 /** 128-bit data structure */
 union W128_T {
