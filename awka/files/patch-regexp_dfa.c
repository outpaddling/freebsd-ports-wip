--- regexp/dfa.c.orig	2020-12-20 22:01:14 UTC
+++ regexp/dfa.c
@@ -39,6 +39,9 @@ extern char *calloc(), *malloc(), *realloc();
 extern void free();
 #endif
 
+// Failing to pick this up on FreeBSD
+#include <string.h>
+
 #if defined(HAVE_STRING_H) || defined(STDC_HEADERS)
 #include <string.h>
 #undef index
