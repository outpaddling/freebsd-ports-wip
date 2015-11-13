--- etc/config/settings.sh.orig	2015-11-03 04:30:23.000000000 -0600
+++ etc/config/settings.sh	2015-11-12 20:54:19.000000000 -0600
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
 
