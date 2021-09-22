--- src/common/slurm_protocol_api.c.orig	2021-07-01 22:28:38 UTC
+++ src/common/slurm_protocol_api.c
@@ -858,6 +858,7 @@ extern int slurm_open_controller_conn(slurm_addr_t *ad
 	}
 	addr = NULL;
 	_slurm_api_free_comm_config(proto_conf);
+	fprintf(stderr, "slurm_open_controller_conn()...\n");
 	slurm_seterrno_ret(SLURMCTLD_COMMUNICATIONS_CONNECTION_ERROR);
 
 end_it:
@@ -2866,6 +2867,7 @@ extern void slurm_setup_addr(slurm_addr_t *sin, uint16
 {
 	static slurm_addr_t s_addr = { 0 };
 
+	// Useless with unconditional memcpy() below
 	memset(sin, 0, sizeof(*sin));
 
 	if (slurm_addr_is_unspec(&s_addr)) {
@@ -2880,7 +2882,7 @@ extern void slurm_setup_addr(slurm_addr_t *sin, uint16
 		else
 			var = "NoInAddrAny";
 
-		if (xstrcasestr(slurm_conf.comm_params, var)) {
+		if ( 1 ) { // xstrcasestr(slurm_conf.comm_params, var)) {
 			char host[MAXHOSTNAMELEN];
 
 			if (!gethostname(host, MAXHOSTNAMELEN)) {
@@ -2889,13 +2891,20 @@ extern void slurm_setup_addr(slurm_addr_t *sin, uint16
 				fatal("%s: Can't get hostname or addr: %m",
 				      __func__);
 		} else {
+			// fprintf(stderr, "Using NULL host for slurm_set_addr().\n");
 			slurm_set_addr(&s_addr, port, NULL);
 		}
 	}
 
+	// fprintf(stderr, "Back from slurm_set_addr\n");
+	// for (int c = 0; c < 14; ++c)
+	//     fprintf(stderr, "%u ",
+	// 	(unsigned char)s_addr.__ss_pad1[c]);
+	// putc('\n', stderr);
 	memcpy(sin, &s_addr, sizeof(*sin));
 	slurm_set_port(sin, port);
 	log_flag(NET, "%s: update address to %pA", __func__, sin);
+	// fprintf(stderr, "slurm_setup_addr(): ss_len = %u\n", sin->ss_len);
 }
 
 /*
@@ -2966,7 +2975,7 @@ static bool _is_port_ok(int s, uint16_t port, bool loc
 		return false;
 	}
 
-	if (bind(s, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
+	if (bind(s, (struct sockaddr *) &addr, addr.ss_len) < 0) {
 		log_flag(NET, "%s: bind() failed on port:%d fd:%d: %m",
 			 __func__, port, s);
 		return false;
