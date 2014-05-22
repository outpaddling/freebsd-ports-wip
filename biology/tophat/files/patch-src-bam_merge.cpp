--- src/bam_merge.cpp.orig	2014-05-21 19:31:17.000000000 -0500
+++ src/bam_merge.cpp	2014-05-21 19:37:10.000000000 -0500
@@ -1,3 +1,4 @@
+#include <getopt.h>
 #include "bam_merge.h"
 
 #define USAGE "Usage: bam_merge [-Q] <out.bam> <in1.bam> <in2.bam> [...]\n"
