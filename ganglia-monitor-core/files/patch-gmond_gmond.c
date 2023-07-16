--- gmond/gmond.c.orig	2023-07-16 09:53:01 UTC
+++ gmond/gmond.c
@@ -2060,7 +2060,7 @@ process_tcp_accept_channel(const apr_pollfd_t *desc, a
 	  debug_msg("failed to allocate gzip stream");
 	  goto close_accept_socket;
 	}
-      apr_status_t r = apr_socket_data_set(client, strm, GZIP_KEY, &zstream_destroy);
+      apr_status_t r = apr_socket_data_set(client, strm, GZIP_KEY, (apr_status_t (*)(void *))zstream_destroy);
       if (r != APR_SUCCESS)
 	{
 	  debug_msg("failed to set socket user data");
