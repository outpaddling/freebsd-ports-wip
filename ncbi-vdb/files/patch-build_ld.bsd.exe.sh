--- build/ld.bsd.exe.sh.orig	2021-06-20 22:48:01 UTC
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
@@ -108,7 +108,7 @@ then
             # always load libdl as shared library
             load-ref-symbols
             load-dynamic
-            CMD="$CMD -ldl"
+#            CMD="$CMD -ldl"
             ;;
 
         -l*)
@@ -289,10 +289,14 @@ then
 fi
 
 # add in xml
+# Doesn't work since ld.sh uses HAVE_XML=32, passed here as part of MODE
 if [ "$HAVE_XML2" == "1" ]
 then
     CMD="$CMD -lxml2"
 fi
+
+# For sra-tools tools/*
+CMD="$CMD -lepoll-shim -lxml2 -lbz2 -lz"
 
 # add in math library
 if [ $HAVE_M -ne 0 ]
