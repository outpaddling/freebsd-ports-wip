--- build/ld.bsd.exe.sh.orig	2017-10-27 02:08:53 UTC
+++ build/ld.bsd.exe.sh
@@ -51,8 +51,8 @@ case "$LD" in
 g*)
     source "${0%exe.sh}gcc.sh"
     ;;
-i*)
-    source "${0%exe.sh}icc.sh"
+c*)
+    source "${0%exe.sh}clang.sh"
     ;;
 *)
     echo "$SELF_NAME: unrecognized ld tool - '$LD'"
@@ -113,7 +113,7 @@ then
             # always load libdl as shared library
             load-ref-symbols
             load-dynamic
-            CMD="$CMD -ldl"
+#            CMD="$CMD -ldl"
             ;;
 
         -l*)
@@ -294,18 +294,11 @@ then
 fi
 
 # add in xml
-if grep -q HAVE_XML2 ${BUILD_DIR}/Makefile.config.linux.$ARCH > /dev/null
+if grep -q HAVE_XML2 ${BUILD_DIR}/Makefile.config.bsd.$ARCH > /dev/null
 then
-    if grep -q XML2_LIBDIR ${BUILD_DIR}/Makefile.config.linux.$ARCH > /dev/null
+    if grep -q XML2_LIBDIR ${BUILD_DIR}/Makefile.config.bsd.$ARCH > /dev/null
     then
-        if grep -q 'OS_DISTRIBUTOR = Ubuntu' ${BUILD_DIR}/Makefile.config.linux.$ARCH > /dev/null
-        then
-            ##### Do not link libxml2 statically on Ubuntu: it does not compile
-            XMLLIBDIR="-L$(grep XML2_LIBDIR ${BUILD_DIR}/Makefile.config.linux.$ARCH | perl -e'while(<>){if(/XML2_LIBDIR = (.+)/){print $1}}')"
-        else
-            ##### Link libxml2 statically on all linux-es except Ubuntu
-            XMLLIBDIR="-Wl,-Bstatic -L$(grep XML2_LIBDIR ${BUILD_DIR}/Makefile.config.linux.$ARCH | perl -e'while(<>){if(/XML2_LIBDIR = (.+)/){print $1}}')"
-        fi
+        XMLLIBDIR="-L$(grep XML2_LIBDIR ${BUILD_DIR}/Makefile.config.bsd.$ARCH | perl -e'while(<>){if(/XML2_LIBDIR = (.+)/){print $1}}')"
     fi
     if [ $HAVE_XML -ne 0 ]
     then
