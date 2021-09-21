--- src/plugins/openapi/v0.0.35/jobs.c.orig	2021-09-21 13:53:49 UTC
+++ src/plugins/openapi/v0.0.35/jobs.c
@@ -41,6 +41,7 @@
 #include <search.h>
 #include <stdint.h>
 #include <unistd.h>
+#include <signal.h>
 
 #include "slurm/slurm.h"
 
