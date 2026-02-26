--- ext/bifrost/src/kseq.h.orig	2026-02-26 17:21:28 UTC
+++ ext/bifrost/src/kseq.h
@@ -32,6 +32,9 @@
 #include <string.h>
 #include <stdlib.h>
 
+// Prevent redefinition of kstring_t below
+#include <htslib/kstring.h>
+
 #define KS_SEP_SPACE 0 // isspace(): \t, \n, \v, \f, \r
 #define KS_SEP_TAB   1 // isspace() && !' '
 #define KS_SEP_LINE  2 // line separator: "\n" (Unix) or "\r\n" (Windows)
@@ -74,14 +77,6 @@
 		}													\
 		return (int)ks->buf[ks->begin++];					\
 	}
-
-#ifndef KSTRING_T
-#define KSTRING_T kstring_t
-typedef struct __kstring_t {
-  size_t l, m;
-  char *s;
-} kstring_t;
-#endif
 
 #ifndef kroundup32
 #define kroundup32(x) (--(x), (x)|=(x)>>1, (x)|=(x)>>2, (x)|=(x)>>4, (x)|=(x)>>8, (x)|=(x)>>16, ++(x))
