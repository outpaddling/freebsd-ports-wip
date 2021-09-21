--- src/slurmd/slurmstepd/req.c.orig	2021-09-21 19:39:55 UTC
+++ src/slurmd/slurmstepd/req.c
@@ -177,7 +177,7 @@ _create_socket(const char *name)
 	len = strlen(addr.sun_path)+1 + sizeof(addr.sun_family);
 
 	/* bind the name to the descriptor */
-	if (bind(fd, (struct sockaddr *) &addr, len) < 0) {
+	if (bind(fd, (struct sockaddr *) &addr, addr.sun_len) < 0) {
 		(void) close(fd);
 		return -2;
 	}
