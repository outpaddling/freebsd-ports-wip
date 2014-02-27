--- src/slurmctld/groups.c.orig	2014-02-10 16:16:55.000000000 -0600
+++ src/slurmctld/groups.c	2014-02-27 08:10:17.000000000 -0600
@@ -208,6 +208,9 @@
 	while (!getpwent_r(&pw, pw_buffer, PW_BUF_SIZE, &pwd_result)) {
 #endif
 #endif
+		/* David Bigagli groups seg fault fix */
+		if (pwd_result == NULL)
+			break; 
  		if (pwd_result->pw_gid != my_gid)
 			continue;
 		if (j+1 >= uid_cnt) {
