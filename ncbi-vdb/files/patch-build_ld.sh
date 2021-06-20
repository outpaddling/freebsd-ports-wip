--- build/ld.sh.orig	2021-06-20 14:49:57 UTC
+++ build/ld.sh
@@ -297,8 +297,8 @@ do
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
@@ -310,8 +310,8 @@ do
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
