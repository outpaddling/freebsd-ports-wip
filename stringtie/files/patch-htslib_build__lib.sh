--- htslib/build_lib.sh.orig	2025-01-06 23:19:34 UTC
+++ htslib/build_lib.sh
@@ -1,8 +1,10 @@
 #!/usr/bin/env bash
 ## 
 
+set -x
+
 if [[ "$1" == "clean" ]]; then
-  make clean
+  ${MAKE} clean
   /bin/rm -f config.h
   /bin/rm -rf xlibs
   /bin/rm -rf lzma bzip2 libdeflate
@@ -38,7 +40,7 @@ if [[ ! -f $libdir/libdeflate.a ]]; then
    MINGW=1
    libdeflate=libdeflatestatic.lib
   fi
-  make -f ../Makefile.libdeflate -j 4 $libdeflate || exit 1
+  ${MAKE} -f ../Makefile.libdeflate -j 4 $libdeflate || exit 1
   cp $libdeflate $libdir/libdeflate.a
   cp libdeflate.h $incdir/
   cd ..
@@ -54,7 +56,7 @@ if [[ ! -f $libdir/libbz2.a ]]; then 
 fi
 if [[ ! -f $libdir/libbz2.a ]]; then 
   cd bzip2
-  make -j 4 libbz2.a
+  ${MAKE} -j 4 libbz2.a
   cp bzlib.h $incdir/
   cp libbz2.a $libdir/
   cd ..
@@ -74,9 +76,9 @@ if [[ ! -f $libdir/liblzma.a ]]; then
   cd lzma
   ./configure --disable-shared -disable-xz -disable-xzdec --disable-lzmadec \
    --disable-lzmainfo --disable-nls --prefix=$prefix
-  make -j 4
-  make install
+  ${MAKE} -j 4
+  ${MAKE} install
   cd ..
 fi
 
-make -j 4 lib-static
+${MAKE} -j 4 lib-static
