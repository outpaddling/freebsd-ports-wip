--- src/common/slurm_protocol_socket.c.orig	2021-05-12 20:23:16 UTC
+++ src/common/slurm_protocol_socket.c
@@ -422,6 +422,9 @@ extern int slurm_init_msg_engine(slurm_addr_t *addr)
 		goto error;
 	}
 
+	fprintf(stderr, "fd = %d  addr = %p\n", fd, addr);
+	fprintf(stderr, "sockaddr_storage = %u %u %lu\n",
+		addr->ss_len, addr->ss_family, addr->__ss_align);
 	rc = bind(fd, (struct sockaddr const *) addr, sizeof(*addr));
 	if (rc < 0) {
 		error("Error binding slurm stream socket: %m");
