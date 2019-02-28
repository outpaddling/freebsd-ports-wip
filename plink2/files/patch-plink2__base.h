--- plink2_base.h.orig	2019-02-28 14:49:04 UTC
+++ plink2_base.h
@@ -542,19 +542,6 @@ HEADER_INLINE uint32_t ctzw(unsigned long ulii) {
 HEADER_INLINE uint32_t bsrw(unsigned long ulii) {
   return (8 * sizeof(intptr_t) - 1) - __builtin_clzl(ulii);
 }
-#  ifndef __LP64__
-    // needed to prevent GCC 6 build failure
-#    if (__GNUC__ <= 4) && (__GNUC_MINOR__ < 8)
-#      if (__cplusplus < 201103L) && !defined(__APPLE__)
-#        ifndef uintptr_t
-#          define uintptr_t unsigned long
-#        endif
-#        ifndef intptr_t
-#          define intptr_t long
-#        endif
-#      endif
-#    endif
-#  endif
 #endif
 
 #ifdef __LP64__
