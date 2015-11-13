--- etc/config/settings.sh.orig	2015-11-03 04:30:23.000000000 -0600
+++ etc/config/settings.sh	2015-11-13 14:46:14.000000000 -0600
@@ -65,6 +65,25 @@
 export WM_ARCH=`uname -s`
 
 case "$WM_ARCH" in
+FreeBSD)
+    WM_ARCH=FreeBSD
+    case `uname -m` in
+    i386|powerpc)
+        export WM_ARCH_OPTION=32
+        ;;
+
+    x86_64|powerpc64)
+        export WM_COMPILER_ARCH=64
+        export WM_CC='cc'
+        export WM_CXX='c++'
+        export WM_CFLAGS='-fPIC'
+        export WM_CXXFLAGS='-fPIC'
+        export WM_LDFLAGS=''
+        ;;
+
+    esac
+    ;;
+
 Linux)
     WM_ARCH=linux
 
@@ -392,7 +411,7 @@
     # Use the system installed openmpi, get library directory via mpicc
     export FOAM_MPI=openmpi-system
 
-    libDir=`mpicc --showme:link | sed -e 's/.*-L\([^ ]*\).*/\1/'`
+    libDir=`mpicc --showme:link | gsed -e 's/.*-L\([^ ]*\).*/\1/'`
 
     # Bit of a hack: strip off 'lib' and hope this is the path to openmpi
     # include files and libraries.
