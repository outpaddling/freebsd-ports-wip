--- build/ld.sh.orig	2017-10-27 07:23:08 UTC
+++ build/ld.sh
@@ -68,6 +68,8 @@ HAVE_M=0
 NEED_M=1
 HAVE_XML=0
 NEED_XML=0
+HAVE_MBEDTLS=0
+NEED_MBEDTLS=0
 HAVE_KFC=0
 HAVE_KAPP=0
 HAVE_NCBI_VDB=0
@@ -297,18 +299,19 @@ do
     -[lds]ncbi-vdb)
         HAVE_NCBI_VDB=1
         KPROC=4
-        HAVE_GZIP=1
-        HAVE_BZIP=1
+        NEED_GZIP=1
+        NEED_BZIP=1
         HAVE_KFC=1
         NEED_M=1
         NEED_XML=1
+        NEED_MBEDTLS=1
         LIBS="$LIBS $1"
         ;;
     -[lds]ncbi-ngs-c++)
         HAVE_NCBI_VDB=1
         KPROC=4
-        HAVE_GZIP=1
-        HAVE_BZIP=1
+        NEED_GZIP=1
+        NEED_BZIP=1
         HAVE_KFC=1
         NEED_M=1
         NEED_XML=1
@@ -317,11 +320,12 @@ do
     -[lds]ncbi-wvdb)
         HAVE_NCBI_WVDB=1
         KPROC=4
-        HAVE_GZIP=1
-        HAVE_BZIP=1
+        NEED_GZIP=1
+        NEED_BZIP=1
         HAVE_KFC=1
         NEED_M=16
         NEED_XML=1
+        NEED_MBEDTLS=1
         LIBS="$LIBS $1"
         ;;
 
@@ -512,6 +516,7 @@ fi
 # supply missing libraries
 [ $HAVE_GZIP -eq 0 ] && [ $NEED_GZIP -ne 0 ] && LIBS="$LIBS -lz"
 [ $HAVE_BZIP -eq 0 ] && [ $NEED_BZIP -ne 0 ] && LIBS="$LIBS -lbz2"
+[ $HAVE_MBEDTLS -eq 0 ] && [ $NEED_MBEDTLS -ne 0 ] && LIBS="$LIBS -lmbedtls -lmbedcrypto -lmbedx509"
 [ $HAVE_DL -eq 0 ] && [ $NEED_DL -ne 0 ] && LIBS="$LIBS -ldl"
 [ $HAVE_M -eq 0 ] && [ $NEED_M -ne 0 ] && HAVE_M=16
 [ $HAVE_XML -eq 0 ] && [ $NEED_XML -ne 0 ] && HAVE_XML=32
