--- awka/fin.h.orig	2020-12-20 21:57:58 UTC
+++ awka/fin.h
@@ -52,5 +52,7 @@ unsigned PROTO ( fillbuff, (int, char *, unsigned) ) ;
 extern  FIN  *main_fin ;  /* for the main input stream */
 void   PROTO( open_main, (void) ) ;
 
+#if MSDOS
 void  PROTO(setmode, (int,int)) ;
+#endif
 #endif  /* FIN_H */
