--- as/link/getline.h.orig	2019-03-06 03:59:14 UTC
+++ as/link/getline.h
@@ -35,7 +35,7 @@ extern "C"
 {
 #endif
 
-  char *getline (char *s, int size, FILE * stream);
+  // char *getline (char *s, int size, FILE * stream);
 
 #ifdef __cplusplus
 }
