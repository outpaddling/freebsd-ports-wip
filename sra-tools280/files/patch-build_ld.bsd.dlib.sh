--- build/ld.bsd.dlib.sh.orig	2017-10-27 02:08:53 UTC
+++ build/ld.bsd.dlib.sh
@@ -51,8 +51,8 @@ case "$LD" in
 g*)
     source "${0%dlib.sh}gcc.sh"
     ;;
-i*)
-    source "${0%dlib.sh}icc.sh"
+c*)
+    source "${0%dlib.sh}clang.sh"
     ;;
  *)
     echo "$SELF_NAME: unrecognized ld tool - '$LD'"
@@ -100,7 +100,7 @@ then
             # always load libdl as shared library
             load-ref-symbols
             load-dynamic
-            CMD="$CMD -ldl"
+#            CMD="$CMD -ldl"
             ;;
 
         -l*)
@@ -275,7 +275,7 @@ then
 fi
 
 # add in xml
-if grep -q HAVE_XML2 ${BUILD_DIR}/Makefile.config.linux.$ARCH > /dev/null
+if grep -q HAVE_XML2 ${BUILD_DIR}/Makefile.config.bsd.$ARCH > /dev/null
 then
     if [ $HAVE_XML -ne 0 ]
     then
