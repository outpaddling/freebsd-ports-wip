--- processor_support.h.orig	2021-11-27 23:24:40 UTC
+++ processor_support.h
@@ -12,7 +12,7 @@
 
 #if defined(__INTEL_COMPILER)
 #   define USING_INTEL_COMPILER
-#elif defined(__GNUC__)
+#elif defined(__GNUC__) && defined(__x86_64__) || defined(__i386__)
 #   define USING_GCC_COMPILER
 #   include <cpuid.h>
 #elif defined(_MSC_VER)
@@ -54,6 +54,7 @@ class ProcessorSupport { (public)
 #else
         std::cerr << "ERROR: please define __cpuid() for this build.\n"; 
         assert(0);
+	return false;
 #endif
         if( !( (regs.ECX & BIT(20)) && (regs.ECX & BIT(23)) ) ) return false;
     }
