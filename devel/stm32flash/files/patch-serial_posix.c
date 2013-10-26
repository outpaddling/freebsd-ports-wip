--- serial_posix.c.orig	2011-05-31 18:43:53.000000000 -0500
+++ serial_posix.c	2013-10-25 21:56:43.000000000 -0500
@@ -176,7 +176,7 @@
 	if (
 		settings.c_iflag != h->newtio.c_iflag ||
 		settings.c_oflag != h->newtio.c_oflag ||
-		settings.c_cflag != h->newtio.c_cflag ||
+		(settings.c_cflag & 0xffffff00) != (h->newtio.c_cflag & 0xffffff00) ||
 		settings.c_lflag != h->newtio.c_lflag
 	)       return SERIAL_ERR_UNKNOWN;
 
