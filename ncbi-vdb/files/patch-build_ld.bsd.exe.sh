--- build/ld.bsd.exe.sh.orig	2021-06-20 16:49:54 UTC
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
@@ -293,6 +293,9 @@ if [ "$HAVE_XML2" == "1" ]
 then
     CMD="$CMD -lxml2"
 fi
+
+# For sra-tools tools/*
+CMD="$CMD -lepoll-shim -lbz2 -lz"
 
 # add in math library
 if [ $HAVE_M -ne 0 ]
