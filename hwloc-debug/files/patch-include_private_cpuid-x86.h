--- include/private/cpuid-x86.h.orig	2015-10-06 17:06:45 UTC
+++ include/private/cpuid-x86.h
@@ -60,23 +60,8 @@ static __hwloc_inline void hwloc_x86_cpuid(unsigned *e
   *ecx = regs[2];
   *edx = regs[3];
 #else /* HWLOC_HAVE_MSVC_CPUIDEX */
-  /* Note: gcc might want to use bx or the stack for %1 addressing, so we can't
-   * use them :/ */
-#ifdef HWLOC_X86_64_ARCH
-  hwloc_uint64_t sav_rbx;
-  __asm__(
-  "mov %%rbx,%2\n\t"
-  "cpuid\n\t"
-  "xchg %2,%%rbx\n\t"
-  "movl %k2,%1\n\t"
-  : "+a" (*eax), "=m" (*ebx), "=&r"(sav_rbx),
-    "+c" (*ecx), "=&d" (*edx));
-#elif defined(HWLOC_X86_32_ARCH)
-  __asm__(
-  "mov %%ebx,%1\n\t"
-  "cpuid\n\t"
-  "xchg %%ebx,%1\n\t"
-  : "+a" (*eax), "=SD" (*ebx), "+c" (*ecx), "=d" (*edx));
+#if defined(HWLOC_X86_32_ARCH) || defined(HWLOC_X86_64_ARCH)
+  __asm__("cpuid" : "+a" (*eax), "=b" (*ebx), "+c" (*ecx), "=d" (*edx));
 #else
 #error unknown architecture
 #endif
