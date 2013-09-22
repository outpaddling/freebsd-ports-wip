--- src/common/net.c.orig	2013-03-27 18:34:42.000000000 -0500
+++ src/common/net.c	2013-03-27 19:38:21.000000000 -0500
@@ -52,6 +52,10 @@
 #include <errno.h>
 #include <stdint.h>
 
+#if defined(__FreeBSD__)
+#define	SOL_TCP		IPPROTO_TCP
+#endif
+
 #include "src/common/log.h"
 #include "src/common/macros.h"
 #include "src/common/net.h"
@@ -204,11 +208,20 @@
 		error("Unable to set keep alive socket option: %m");
 		return -1;
 	}
+
+/*
+ * TCP_KEEPIDLE used to be defined in FreeBSD, then went away, then came
+ * back in 9.0.
+ * Is it OK to just disable this setsockopt?
+ */
+#if ! defined(__FreeBSD__) || (__FreeBSD_version > 900000)
 	opt_int = keep_alive_time;
 	if (setsockopt(sock, SOL_TCP, TCP_KEEPIDLE, &opt_int, opt_len) < 0) {
 		error("Unable to set keep alive socket time: %m");
 		return -1;
 	}
+#endif
+
 #if 0
 	opt_linger.l_onoff = 0;
 	opt_linger.l_linger = 0;
