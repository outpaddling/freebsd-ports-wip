--- src/plugins/acct_gather_filesystem/lustre/acct_gather_filesystem_lustre.c.orig	2013-09-21 22:24:22.000000000 -0500
+++ src/plugins/acct_gather_filesystem/lustre/acct_gather_filesystem_lustre.c	2013-09-21 22:24:44.000000000 -0500
@@ -49,6 +49,8 @@
 #include <getopt.h>
 #include <netinet/in.h>
 
+#include <limits.h>
+
 
 #include "src/common/slurm_xlator.h"
 #include "src/common/slurm_acct_gather_filesystem.h"
