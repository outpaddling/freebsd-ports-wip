--- src/common/slurm_protocol_api.c.orig	2021-09-16 21:21:22 UTC
+++ src/common/slurm_protocol_api.c
@@ -2885,6 +2885,7 @@ extern void slurm_setup_addr(slurm_addr_t *sin, uint16
 {
 	static slurm_addr_t s_addr = { 0 };
 
+	// Useless with unconditional memcpy() below
 	memset(sin, 0, sizeof(*sin));
 
 	if (slurm_addr_is_unspec(&s_addr)) {
@@ -2915,6 +2916,7 @@ extern void slurm_setup_addr(slurm_addr_t *sin, uint16
 	memcpy(sin, &s_addr, sizeof(*sin));
 	slurm_set_port(sin, port);
 	log_flag(NET, "%s: update address to %pA", __func__, sin);
+	fprintf(stderr, "slurm_setup_addr(): ss_len = %u\n", sin->ss_len);
 }
 
 /*
