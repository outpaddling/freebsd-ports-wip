--- src/3rdParty/salomesmesh/src/SMDS/SMDS_Mesh.cpp.orig	2023-11-14 12:23:41 UTC
+++ src/3rdParty/salomesmesh/src/SMDS/SMDS_Mesh.cpp
@@ -62,7 +62,7 @@
 using namespace std;
 
 #ifndef WIN32
-#if !(defined(__MACH__) && defined(__APPLE__))
+#ifdef __linux__
 #include <sys/sysinfo.h>
 #endif
 #include <sys/wait.h>
