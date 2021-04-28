--- build/ld.bsd.gcc.sh.orig	2017-10-27 02:08:53 UTC
+++ build/ld.bsd.gcc.sh
@@ -33,13 +33,8 @@ LD_REF_SYMBOLS="-Wl,-no-whole-archive"
 
 # build command
 DLIB_CMD="$LD -shared"
-
-#EXE_CMD="$LD -static-libstdc++ -static-libgcc"
-source "${0%exe.sh}exe_cmd.sh" # EXE_CMD is defined in build/ld.linux.exe_cmd.sh
-
-EXE_STATIC_CMD="$EXE_CMD"
-#EXE_CMD="$LD"
-#EXE_STATIC_CMD="$LD -static"
+EXE_CMD="$LD"
+EXE_STATIC_CMD="$LD -static"
 
 # versioned output
 if [ "$VERS" = "" ]
