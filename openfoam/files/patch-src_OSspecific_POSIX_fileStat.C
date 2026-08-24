--- src/OSspecific/POSIX/fileStat.C.orig	2026-08-24 15:00:15 UTC
+++ src/OSspecific/POSIX/fileStat.C
@@ -29,7 +29,11 @@ License
 
 #include <signal.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#else
 #include <sys/sysmacros.h>
+#endif
 
 // * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //
 
