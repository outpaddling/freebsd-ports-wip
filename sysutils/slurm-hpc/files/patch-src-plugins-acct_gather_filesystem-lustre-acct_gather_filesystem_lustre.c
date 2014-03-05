--- src/plugins/acct_gather_filesystem/lustre/acct_gather_filesystem_lustre.c.orig	2013-11-04 15:19:15.000000000 -0600
+++ src/plugins/acct_gather_filesystem/lustre/acct_gather_filesystem_lustre.c	2014-02-26 20:19:23.000000000 -0600
@@ -49,6 +49,8 @@
 #include <getopt.h>
 #include <netinet/in.h>
 
+#include <limits.h>
+
 
 #include "src/common/slurm_xlator.h"
 #include "src/common/slurm_acct_gather_filesystem.h"
