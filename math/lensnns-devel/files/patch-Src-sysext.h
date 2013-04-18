--- Src/sysext.h.orig	2003-12-09 13:13:53.000000000 -0600
+++ Src/sysext.h	2012-12-14 09:05:09.000000000 -0600
@@ -3,10 +3,8 @@
 #ifndef SYSEXT_H
 #define SYSEXT_H
 
-/*
-#ifdef MACHINE_YOURMACHINE
-  include headers or define macros as necessary
-#endif
-*/
+#if BYTE_ORDER == LITTLE_ENDIAN
+#    define LITTLE_END
+#endif /* LITTLE_END */
 
 #endif /* SYSEXT_H */
