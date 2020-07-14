--- cram/open_trace_file.c.orig	2020-07-08 12:52:24 UTC
+++ cram/open_trace_file.c
@@ -205,8 +205,9 @@ mFILE *find_file_url(const char *file, char *url) {
             goto fail;
         }
     }
-    if (hclose(hf) < 0 || len < 0) {
-        hts_log_warning("Failed to read reference \"%s\": %s", path, strerror(errno));
+    int close_status = hclose(hf);
+    if (close_status < 0 || len < 0) {
+        hts_log_warning("Failed to read reference \"%s\": %s  close_status = %d len = %ld", path, strerror(errno));
         goto fail;
     }
 
