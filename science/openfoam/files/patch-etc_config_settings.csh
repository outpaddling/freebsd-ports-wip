--- etc/config/settings.csh.orig	2015-12-05 07:26:43.975667214 -0600
+++ etc/config/settings.csh	2015-12-05 07:55:57.759573718 -0600
@@ -45,6 +45,31 @@ setenv WM_ARCH `uname -s`
 setenv WM_COMPILER_LIB_ARCH
 
 switch ($WM_ARCH)
+case FreeBSD:
+    setenv WM_CC 'gcc48'
+    setenv WM_CXX 'g++48'
+    setenv WM_CFLAGS '-fPIC'
+    setenv WM_CXXFLAGS '-fPIC'
+    setenv WM_LDFLAGS '-L${LOCALBASE}/mpi/openmpi/lib'
+
+    switch(`uname -m`)
+    case i386:
+    case powerpc:
+    case sparc:
+        setenv WM_ARCH_OPTION 32
+        setenv WM_COMPILER_ARCH 32
+        breaksw
+
+    case amd64:
+    case powerpc64:
+    case sparc64:
+        setenv WM_ARCH_OPTION 64
+        setenv WM_COMPILER_ARCH 64
+        breaksw
+
+    endsw
+    breaksw
+
 case Linux:
     setenv WM_ARCH linux
 
@@ -367,6 +392,7 @@ switch ("$WM_MPLIB")
 case SYSTEMOPENMPI:
     # Use the system installed openmpi, get library directory via mpicc
     setenv FOAM_MPI openmpi-system
+    setenv PATH ${PATH}:/usr/local/mpi/openmpi/bin
 
     set libDir=`mpicc --showme:link | sed -e 's/.*-L\([^ ]*\).*/\1/'`
 
