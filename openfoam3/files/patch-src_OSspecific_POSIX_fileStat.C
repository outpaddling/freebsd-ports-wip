--- src/OSspecific/POSIX/fileStat.C.orig	2015-11-03 10:30:23 UTC
+++ src/OSspecific/POSIX/fileStat.C
@@ -29,7 +29,7 @@ License
 
 #include <signal.h>
 #include <unistd.h>
-#include <sys/sysmacros.h>
+// #include <sys/sysmacros.h>
 
 // * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //
 
