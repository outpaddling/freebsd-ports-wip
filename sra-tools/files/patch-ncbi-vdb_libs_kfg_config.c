--- ncbi-vdb/libs/kfg/config.c.orig	2023-07-10 16:13:36 UTC
+++ ncbi-vdb/libs/kfg/config.c
@@ -2839,7 +2839,9 @@ void add_predefined_nodes ( KConfig * self, const char
     update_node ( self, "kfg/arch/bits", buf, true );
 
     /* *OS */
-#if LINUX
+#if BSD
+    #define OS "bsd"
+#elif LINUX
     #define OS "linux"
 #elif MAC
     #define OS "mac"
