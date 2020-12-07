--- src/plugins/select/cons_tres/job_test.c.orig	2020-12-07 22:40:47 UTC
+++ src/plugins/select/cons_tres/job_test.c
@@ -52,10 +52,10 @@ extern bitstr_t *idle_node_bitmap __attribute__((weak_
 extern node_record_t *node_record_table_ptr __attribute__((weak_import));
 extern List job_list __attribute__((weak_import));
 #else
-slurmctld_config_t slurmctld_config;
-bitstr_t *idle_node_bitmap;
-node_record_t *node_record_table_ptr;
-List job_list;
+extern slurmctld_config_t slurmctld_config;
+extern bitstr_t *idle_node_bitmap;
+extern node_record_t *node_record_table_ptr;
+extern List job_list;
 #endif
 
 typedef struct node_weight_struct {
