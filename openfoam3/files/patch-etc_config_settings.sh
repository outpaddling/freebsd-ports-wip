--- etc/config/settings.sh.orig	2015-11-03 10:30:23 UTC
+++ etc/config/settings.sh
@@ -65,6 +65,27 @@ _foamAddMan()
 export WM_ARCH=`uname -s`
 
 case "$WM_ARCH" in
+FreeBSD)
+    export WM_CC='gcc'
+    export WM_CXX='g++'
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
 
