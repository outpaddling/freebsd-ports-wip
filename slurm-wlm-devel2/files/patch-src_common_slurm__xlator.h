--- src/common/slurm_xlator.h.orig	2021-09-21 13:43:42 UTC
+++ src/common/slurm_xlator.h
@@ -474,7 +474,9 @@
 /* Include the function definitions after redefining their names. */
 #include "src/common/bitstring.h"
 #include "src/common/callerid.h"
+#ifdef __linux__
 #include "src/common/cgroup.h"
+#endif
 #include "src/common/eio.h"
 #include "src/common/env.h"
 #include "src/common/hostlist.h"
