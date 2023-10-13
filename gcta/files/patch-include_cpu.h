--- include/cpu.h.orig	2023-10-13 13:09:13 UTC
+++ include/cpu.h
@@ -13,7 +13,7 @@
   #define GCTA_ARCH_i386 0
 #endif
 
-#if GCTA_ARCH_x86_64 || GCTA_ARCH_i386
+#if !defined(__FreeBSD__) && (GCTA_ARCH_x86_64 || GCTA_ARCH_i386)
   #define GCTA_CPU_x86 1
 #else
   #define GCTA_CPU_x86 0
@@ -50,4 +50,4 @@
   #include <lapack.h>
 #endif
 
-#endif  //END GCTA_CPU_H
\ No newline at end of file
+#endif  //END GCTA_CPU_H
