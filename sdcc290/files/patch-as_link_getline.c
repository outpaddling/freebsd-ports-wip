--- as/link/getline.c.orig	2019-03-06 03:59:55 UTC
+++ as/link/getline.c
@@ -41,6 +41,7 @@ while no characters have been read.
 
 *******************************************************************************/
 
+#if 0
 char *
 getline (char *s, int size, FILE * stream)
 {
@@ -91,3 +92,4 @@ getline (char *s, int size, FILE * stream)
 
   return s_o;
 }
+#endif
