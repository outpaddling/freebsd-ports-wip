--- src/common/slurm_protocol_socket.c.orig	2021-07-01 22:28:38 UTC
+++ src/common/slurm_protocol_socket.c
@@ -120,8 +120,11 @@ static void _sock_bind_wild(int sockfd)
 
 	slurm_setup_addr(&sin, RANDOM_USER_PORT);
 
+	// fprintf(stderr, "sockfd = %d  sin = %p\n", sockfd, sin);
+	// fprintf(stderr, "ss_len = %u  ss_family = %u  __ss_align = %lu\n",
+	// 	sin.ss_len, sin.ss_family, sin.__ss_align);
 	for (retry=0; retry < PORT_RETRIES ; retry++) {
-		rc = bind(sockfd, (struct sockaddr *) &sin, sizeof(sin));
+		rc = bind(sockfd, (struct sockaddr *) &sin, sin.ss_len);
 		if (rc >= 0)
 			break;
 		slurm_set_port(&sin, RANDOM_USER_PORT);
@@ -422,7 +425,16 @@ extern int slurm_init_msg_engine(slurm_addr_t *addr)
 		goto error;
 	}
 
-	rc = bind(fd, (struct sockaddr const *) addr, sizeof(*addr));
+	// fprintf(stderr, "slurm_init_msg_engine()...\n");
+	// fprintf(stderr, "fd = %d  addr = %p\n", fd, addr);
+	// fprintf(stderr, "ss_len = %u  ss_family = %u  __ss_align = %lu\n",
+	// 	addr->ss_len, addr->ss_family, addr->__ss_align);
+	// fprintf(stderr, "sizeof(*addr) = %zu\n", sizeof(*addr));
+	// fprintf(stderr, "port = %u\n", (unsigned short)(addr->__ss_pad1[1] + (addr->__ss_pad1[0] << 8)));
+	// for (int c = 0; c < 14; ++c)
+	//     fprintf(stderr, "%u ", (unsigned char)addr->__ss_pad1[c]);
+	// putc('\n', stderr);
+	rc = bind(fd, (struct sockaddr const *) addr, addr->ss_len);
 	if (rc < 0) {
 		error("Error binding slurm stream socket: %m");
 		goto error;
@@ -669,6 +681,7 @@ extern void slurm_set_addr(slurm_addr_t *addr, uint16_
 	memcpy(addr, ai_ptr->ai_addr, ai_ptr->ai_addrlen);
 	log_flag(NET, "%s: update addr. addr='%pA'", __func__, addr);
 	freeaddrinfo(ai_start);
+	// fprintf(stderr, "slurm_set_addr(): ss_len = %u\n", addr->ss_len);
 }
 
 extern void slurm_pack_slurm_addr(slurm_addr_t *addr, Buf buffer)
