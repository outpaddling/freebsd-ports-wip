--- src/common/net.c.orig	2021-09-21 19:38:03 UTC
+++ src/common/net.c
@@ -87,7 +87,6 @@ strong_alias(net_stream_listen,		slurm_net_stream_list
 int net_stream_listen(int *fd, uint16_t *port)
 {
 	slurm_addr_t sin;
-	socklen_t len = sizeof(sin);
 	int val = 1;
 
 	/* bind ephemeral port */
@@ -98,9 +97,9 @@ int net_stream_listen(int *fd, uint16_t *port)
 
 	if (setsockopt(*fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) < 0)
 		goto cleanup;
-	if (bind(*fd, (struct sockaddr *) &sin, len) < 0)
+	if (bind(*fd, (struct sockaddr *) &sin, sin.ss_len) < 0)
 		goto cleanup;
-	if (getsockname(*fd, (struct sockaddr *) &sin, &len) < 0)
+	if (getsockname(*fd, (struct sockaddr *) &sin, sin.ss_len) < 0)
 		goto cleanup;
 
 	*port = slurm_get_port(&sin);
