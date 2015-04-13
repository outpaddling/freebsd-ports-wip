--- src/nco++/ncoLexer.hpp.orig	2015-04-13 15:21:02.000000000 -0500
+++ src/nco++/ncoLexer.hpp	2015-04-13 15:21:19.000000000 -0500
@@ -1,6 +1,9 @@
 #ifndef INC_ncoLexer_hpp_
 #define INC_ncoLexer_hpp_
 
+#include <cstdio>
+#include <cstring>
+
 #include <antlr/config.hpp>
 /* $ANTLR 2.7.7 (2006-11-01): "ncoGrammer.g" -> "ncoLexer.hpp"$ */
 #include <antlr/CommonToken.hpp>
