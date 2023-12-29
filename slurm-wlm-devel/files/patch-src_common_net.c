--- src/common/net.c.orig	2023-12-29 19:19:05 UTC
+++ src/common/net.c
@@ -90,11 +90,12 @@ strong_alias(net_stream_listen,		slurm_net_stream_list
 int net_stream_listen(int *fd, uint16_t *port)
 {
 	slurm_addr_t sin;
-	socklen_t len = sizeof(sin);
+	socklen_t len;
 	int val = 1;
 
 	/* bind ephemeral port */
 	slurm_setup_addr(&sin, 0);
+	len = sin.ss_len;
 
 	if ((*fd = socket(sin.ss_family, SOCK_STREAM, IPPROTO_TCP)) < 0)
 		return -1;
@@ -219,7 +220,7 @@ static bool _is_port_ok(int s, uint16_t port, bool loc
 		return false;
 	}
 
-	if (bind(s, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
+	if (bind(s, (struct sockaddr *) &addr, addr.ss_len) < 0) {
 		log_flag(NET, "%s: bind() failed on port:%d fd:%d: %m",
 			 __func__, port, s);
 		return false;
