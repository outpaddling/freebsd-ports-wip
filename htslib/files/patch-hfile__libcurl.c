--- hfile_libcurl.c.orig	2020-07-08 12:52:24 UTC
+++ hfile_libcurl.c
@@ -74,6 +74,10 @@ typedef struct {
     unsigned int size;
 } hdrlist;
 
+#ifndef ENOTRECOVERABLE
+#define ENOTRECOVERABLE EIO
+#endif
+
 typedef struct {
     hdrlist fixed;                   // List of headers supplied at hopen()
     hdrlist extra;                   // List of headers from callback
@@ -126,6 +130,8 @@ static int restart_from_position(hFILE_libcurl *fp, of
 
 static int http_status_errno(int status)
 {
+    fprintf(stderr, "http_status_errno: status = %d\n", status);
+
     if (status >= 500)
         switch (status) {
         case 501: return ENOSYS;
@@ -151,6 +157,8 @@ static int easy_errno(CURL *easy, CURLcode err)
 {
     long lval;
 
+    fprintf(stderr, "easy_errno: err = %d\n", err);
+
     switch (err) {
     case CURLE_OK:
         return 0;
@@ -227,6 +235,8 @@ static int easy_errno(CURL *easy, CURLcode err)
 
 static int multi_errno(CURLMcode errm)
 {
+    fprintf(stderr, "multi_errno: errm = %d\n", errm);
+
     switch (errm) {
     case CURLM_CALL_MULTI_PERFORM:
     case CURLM_OK:
