--- src/progress.h.orig	2018-07-24 16:57:56 UTC
+++ src/progress.h
@@ -6,7 +6,7 @@
 
 #pragma once
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 
 #if defined(__INTEL_COMPILER_BUILD_DATE) || \
     (defined(__GNUC__) && (__GNUC__ > 4 || \
