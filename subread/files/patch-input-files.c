--- input-files.c.orig	2018-11-08 14:50:33 UTC
+++ input-files.c
@@ -44,7 +44,7 @@ int is_R_warnned = 0;
 FILE * f_subr_open(const char * fname, const char * mode)
 {
 
-#if defined(__LP64__) || defined(_LP64) || defined(MACOS)
+#if defined(__LP64__) || defined(_LP64) || defined(__APPLE__)
 		return fopen(fname, mode);
 #else
 		return fopen64(fname, mode);
