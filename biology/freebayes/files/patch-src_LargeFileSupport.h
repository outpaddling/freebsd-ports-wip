--- src/LargeFileSupport.h.orig	2015-11-19 19:47:11.000000000 -0600
+++ src/LargeFileSupport.h	2015-11-19 19:47:19.000000000 -0600
@@ -4,7 +4,7 @@
 #define ftell64(a)     _ftelli64(a)
 #define fseek64(a,b,c) _fseeki64(a,b,c)
 typedef __int64 off_type;
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 #define ftell64(a)     ftello(a)
 #define fseek64(a,b,c) fseeko(a,b,c)
 typedef off_t off_type;
