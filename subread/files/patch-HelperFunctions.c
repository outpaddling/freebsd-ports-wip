--- HelperFunctions.c.orig	2020-05-04 08:14:22 UTC
+++ HelperFunctions.c
@@ -25,7 +25,7 @@
 #include <unistd.h>
 
 
-#ifdef MACOS
+#ifdef __APPLE__
 
 #include <sys/types.h>
 #include <sys/socket.h>
@@ -845,10 +845,10 @@ int strcmp_number(char * s1, char * s2)
 
 int mac_str(char * str_buff)
 {
-#if defined(FREEBSD) || defined(__MINGW32__)
+#if defined(__FreeBSD__) || defined(__MINGW32__)
 	return 1;
 #else
-#ifdef MACOS
+#ifdef __APPLE__
     int         mib[6], x1, ret = 1;
 	size_t		len;
     char            *buf;
@@ -2703,7 +2703,7 @@ void main(){
 
 int get_free_total_mem(size_t * total, size_t * free_mem){
 
-#ifdef FREEBSD
+#ifdef __FREEBSD__
     return -1;
 #endif
 
