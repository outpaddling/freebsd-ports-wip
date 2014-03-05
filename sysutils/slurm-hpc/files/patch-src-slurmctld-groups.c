--- src/slurmctld/groups.c.orig	2013-11-04 15:19:15.000000000 -0600
+++ src/slurmctld/groups.c	2014-02-26 20:19:23.000000000 -0600
@@ -169,6 +169,9 @@
 	while (!getpwent_r(&pw, pw_buffer, PW_BUF_SIZE, &pwd_result)) {
 #endif
 #endif
+		/* David Bigagli groups seg fault fix */
+		if (pwd_result == NULL)
+			break; 
  		if (pwd_result->pw_gid != my_gid)
 			continue;
 		if (j+1 >= uid_cnt) {
