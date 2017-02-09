--- etc/config/settings.sh.orig	2015-11-03 04:30:23.000000000 -0600
+++ etc/config/settings.sh	2015-12-02 08:12:49.248331029 -0600
@@ -65,6 +65,27 @@ _foamAddMan()
 export WM_ARCH=`uname -s`
 
 case "$WM_ARCH" in
+FreeBSD)
+    export WM_CC='gcc48'
+    export WM_CXX='g++48'
+    export WM_CFLAGS='-fPIC'
+    export WM_CXXFLAGS='-fPIC'
+    export WM_LDFLAGS='-L${LOCALBASE}/mpi/openmpi/lib'
+
+    case `uname -m` in
+    i386|powerpc|sparc)
+        export WM_ARCH_OPTION=32
+        export WM_COMPILER_ARCH=32
+        ;;
+
+    amd64|powerpc64|sparc64)
+        export WM_ARCH_OPTION=64
+        export WM_COMPILER_ARCH=64
+        ;;
+
+    esac
+    ;;
+
 Linux)
     WM_ARCH=linux
 
@@ -391,6 +412,7 @@ case "$WM_MPLIB" in
 SYSTEMOPENMPI)
     # Use the system installed openmpi, get library directory via mpicc
     export FOAM_MPI=openmpi-system
+    export PATH=${PATH}:/usr/local/mpi/openmpi/bin
 
     libDir=`mpicc --showme:link | sed -e 's/.*-L\([^ ]*\).*/\1/'`
 
