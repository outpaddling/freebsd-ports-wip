--- plink_common.h.orig	2020-04-28 17:18:08 UTC
+++ plink_common.h
@@ -122,7 +122,7 @@
   #define EOLN_STR "\n"
   #define FOPEN_RB "r"
   #define FOPEN_WB "w"
-  #ifndef __APPLE__
+  #if !defined(__APPLE__) && !defined(__FreeBSD__)
     // argh
     // not sure what the right threshold actually is, but this works for now
     // (may break on gcc <3.0?  but that shouldn't matter anymore)
@@ -143,7 +143,7 @@
   #define CLZLU __builtin_clzl
   #ifndef __LP64__
     // attempt to patch GCC 6 build failure
-    #if (__GNUC__ <= 4) && (__GNUC_MINOR__ < 8)
+    #if !defined(__FreeBSD__) && (__GNUC__ <= 4) && (__GNUC_MINOR__ < 8)
       #ifndef uintptr_t
         #define uintptr_t unsigned long
       #endif
@@ -187,14 +187,16 @@
 // http://esr.ibiblio.org/?p=5095 ).
 
 #ifdef __LP64__
-  #ifndef __SSE2__
+  // #ifndef __SSE2__
     // It's obviously possible to support this by writing 64-bit non-SSE2 code
     // shadowing each SSE2 intrinsic, but this almost certainly isn't worth the
     // development/testing effort until regular PLINK 2.0 development is
     // complete.  No researcher has ever asked me for this feature.
-    #error "64-bit builds currently require SSE2.  Try producing a 32-bit build instead."
-  #endif
-  #include <emmintrin.h>
+    // #error "64-bit builds currently require SSE2.  Try producing a 32-bit build instead."
+  // #endif
+  // #include <emmintrin.h>
+  #define SIMDE_ENABLE_NATIVE_ALIASES
+  #include <simde/x86/sse2.h>
 
   #define VECFTYPE __m128
   #define VECITYPE __m128i
