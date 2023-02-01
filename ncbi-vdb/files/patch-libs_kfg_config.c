--- libs/kfg/config.c.orig	2023-02-01 13:39:27 UTC
+++ libs/kfg/config.c
@@ -2841,6 +2841,8 @@ void add_predefined_nodes ( KConfig * self, const char
     /* *OS */
 #if LINUX
     #define OS "linux"
+#elif FREEBSD
+    #define OS "freebsd"
 #elif MAC
     #define OS "mac"
 #elif WINDOWS
