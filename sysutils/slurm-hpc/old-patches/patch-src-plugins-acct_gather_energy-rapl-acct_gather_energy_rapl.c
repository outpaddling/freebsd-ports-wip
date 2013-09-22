--- src/plugins/acct_gather_energy/rapl/acct_gather_energy_rapl.c.orig	2013-03-08 13:37:58.000000000 -0600
+++ src/plugins/acct_gather_energy/rapl/acct_gather_energy_rapl.c	2013-03-27 18:32:27.000000000 -0500
@@ -67,6 +67,11 @@
 #include <math.h>
 #include "acct_gather_energy_rapl.h"
 
+/* From Linux sys/types.h */
+#if defined(__FreeBSD__)
+typedef unsigned long int	ulong;
+#endif
+
 union {
 	uint64_t val;
 	struct {
