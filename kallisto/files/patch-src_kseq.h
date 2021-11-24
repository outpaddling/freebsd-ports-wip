--- src/kseq.h.orig	2021-11-24 14:46:33 UTC
+++ src/kseq.h
@@ -32,6 +32,8 @@
 #include <string.h>
 #include <stdlib.h>
 
+#include <htslib/kstring.h>
+
 #define KS_SEP_SPACE 0 // isspace(): \t, \n, \v, \f, \r
 #define KS_SEP_TAB   1 // isspace() && !' '
 #define KS_SEP_LINE  2 // line separator: "\n" (Unix) or "\r\n" (Windows)
