--- src/plugins/select/cons_res/job_test.c.orig	2020-12-07 22:53:41 UTC
+++ src/plugins/select/cons_res/job_test.c
@@ -106,7 +106,7 @@
 #if defined (__APPLE__)
 extern bitstr_t *idle_node_bitmap __attribute__((weak_import));
 #else
-bitstr_t *idle_node_bitmap;
+extern bitstr_t *idle_node_bitmap;
 #endif
 
 /* Enables module specific debugging */
