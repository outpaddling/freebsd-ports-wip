--- src/common/slurm_protocol_socket.c.orig	2023-12-29 19:26:12 UTC
+++ src/common/slurm_protocol_socket.c
@@ -116,7 +116,7 @@ static void _sock_bind_wild(int sockfd)
 	slurm_setup_addr(&sin, RANDOM_USER_PORT);
 
 	for (retry=0; retry < PORT_RETRIES ; retry++) {
-		rc = bind(sockfd, (struct sockaddr *) &sin, sizeof(sin));
+		rc = bind(sockfd, (struct sockaddr *) &sin, sin.ss_len);
 		if (rc >= 0)
 			break;
 		slurm_set_port(&sin, RANDOM_USER_PORT);
@@ -511,7 +511,7 @@ extern int slurm_init_msg_engine(slurm_addr_t *addr, b
 		goto error;
 	}
 
-	rc = bind(fd, (struct sockaddr const *) addr, sizeof(*addr));
+	rc = bind(fd, (struct sockaddr const *) addr, addr->ss_len);
 	if (rc < 0) {
 		format_print(log_lvl, "Error binding slurm stream socket: %m");
 		goto error;
