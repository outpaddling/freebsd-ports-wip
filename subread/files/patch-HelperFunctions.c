--- HelperFunctions.c.orig	2021-03-27 07:38:08 UTC
+++ HelperFunctions.c
@@ -846,7 +846,7 @@ int strcmp_number(char * s1, char * s2)
 
 int mac_str(char * str_buff)
 {
-#if defined(FREEBSD) || defined(__MINGW32__)
+#if defined(__FreeBSD__) || defined(__MINGW32__)
 	return 1;
 #else
 #ifdef MACOS
@@ -2704,10 +2704,6 @@ void main(){
 
 
 int get_free_total_mem(size_t * total, size_t * free_mem){
-
-#ifdef FREEBSD
-    return -1;
-#endif
 
 #ifdef __MINGW32__
 	MEMORYSTATUSEX statex;
