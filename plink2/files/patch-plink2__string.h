--- plink2_string.h.orig	2019-01-09 02:07:17 UTC
+++ plink2_string.h
@@ -341,7 +341,7 @@ HEADER_INLINE char* strcpya_k(char* __restrict dst, co
 }
 #endif
 
-#if defined(__cplusplus) && !defined(__APPLE__)
+#if defined(__cplusplus) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #  if __cplusplus >= 201103L
 #    define isfinite std::isfinite
 #  else
