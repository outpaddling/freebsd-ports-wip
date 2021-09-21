--- src/slurmrestd/conmgr.c.orig	2021-09-21 19:41:32 UTC
+++ src/slurmrestd/conmgr.c
@@ -1802,7 +1802,7 @@ static int _create_socket(void *x, void *arg)
 		/* set value of socket path */
 		strlcpy(addr.sun_path, unixsock, sizeof(addr.sun_path));
 		if ((rc = bind(fd, (const struct sockaddr *) &addr,
-			       sizeof(addr))))
+			       addr.sun_len)))
 			fatal("%s: [%s] Unable to bind UNIX socket: %m",
 			      __func__, hostport);
 
