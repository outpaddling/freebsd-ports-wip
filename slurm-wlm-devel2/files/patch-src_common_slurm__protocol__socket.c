--- src/common/slurm_protocol_socket.c.orig	2021-07-01 22:28:38 UTC
+++ src/common/slurm_protocol_socket.c
@@ -120,6 +120,12 @@ static void _sock_bind_wild(int sockfd)
 
 	slurm_setup_addr(&sin, RANDOM_USER_PORT);
 
+	fprintf(stderr, "sockfd = %d  sin = %p\n", sockfd, sin);
+	memset(sin.__ss_pad1, 0, _SS_PAD1SIZE);
+	memset(sin.__ss_pad2, 0, _SS_PAD2SIZE);
+	sin.__ss_align = 0;
+	fprintf(stderr, "ss_len = %u  ss_family = %u  __ss_align = %lu\n",
+		sin.ss_len, sin.ss_family, sin.__ss_align);
 	for (retry=0; retry < PORT_RETRIES ; retry++) {
 		rc = bind(sockfd, (struct sockaddr *) &sin, sizeof(sin));
 		if (rc >= 0)
@@ -422,6 +428,13 @@ extern int slurm_init_msg_engine(slurm_addr_t *addr)
 		goto error;
 	}
 
+	fprintf(stderr, "fd = %d  addr = %p\n", fd, addr);
+	memset(addr->__ss_pad1, 0, _SS_PAD1SIZE);
+	memset(addr->__ss_pad2, 0, _SS_PAD2SIZE);
+	addr->__ss_align = 0;
+	fprintf(stderr, "ss_len = %u  ss_family = %u  __ss_align = %lu\n",
+		addr->ss_len, addr->ss_family, addr->__ss_align);
+	fprintf(stderr, "sizeof(*addr) = %zu\n", sizeof(*addr));
 	rc = bind(fd, (struct sockaddr const *) addr, sizeof(*addr));
 	if (rc < 0) {
 		error("Error binding slurm stream socket: %m");
@@ -669,6 +682,7 @@ extern void slurm_set_addr(slurm_addr_t *addr, uint16_
 	memcpy(addr, ai_ptr->ai_addr, ai_ptr->ai_addrlen);
 	log_flag(NET, "%s: update addr. addr='%pA'", __func__, addr);
 	freeaddrinfo(ai_start);
+	fprintf(stderr, "slurm_set_addr(): ss_len = %u\n", addr->ss_len);
 }
 
 extern void slurm_pack_slurm_addr(slurm_addr_t *addr, Buf buffer)
