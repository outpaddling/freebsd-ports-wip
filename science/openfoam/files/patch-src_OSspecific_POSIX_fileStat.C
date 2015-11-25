--- src/OSspecific/POSIX/fileStat.C.orig	2015-11-25 13:37:21.874672229 -0600
+++ src/OSspecific/POSIX/fileStat.C	2015-11-25 13:37:30.586686944 -0600
@@ -29,7 +29,7 @@
 
 #include <signal.h>
 #include <unistd.h>
-#include <sys/sysmacros.h>
+// #include <sys/sysmacros.h>
 
 // * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //
 
