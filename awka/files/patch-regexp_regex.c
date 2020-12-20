--- regexp/regex.c.orig	2020-12-20 12:06:46 UTC
+++ regexp/regex.c
@@ -600,6 +600,8 @@ extract_number_and_incr (destination, source)
 /* It is useful to test things that ``must'' be true when debugging.  */
 # include <assert.h>
 
+#include "dfa.h"
+
 static int debug;
 
 # define DEBUG_STATEMENT(e) e
@@ -5781,7 +5783,7 @@ _re_gsub_fixslashes(char *pattern)
 awka_regexp *
 awka_regcomp (patt, gsub)
     char *patt;
-    char gsub;
+    int gsub;
 {
   awka_regexp *preg;
   reg_errcode_t ret;
