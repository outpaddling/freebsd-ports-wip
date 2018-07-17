--- lib/dmask.h.orig	2018-07-17 00:39:02 UTC
+++ lib/dmask.h
@@ -4,6 +4,7 @@
 #define DMASK
 
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <resolv.h>
 #include <arpa/inet.h>
 #include <unistd.h>
