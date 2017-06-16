--- serial_posix.c.orig	2016-03-04 18:53:07.860316000 -0600
+++ serial_posix.c	2016-03-04 18:53:36.554064000 -0600
@@ -188,6 +188,7 @@ static port_err_t serial_setup(serial_t 
 	if (settings.c_iflag != h->newtio.c_iflag ||
 	    settings.c_oflag != h->newtio.c_oflag ||
 	    settings.c_cflag != h->newtio.c_cflag ||
+            (settings.c_cflag & 0xffffff00) != (h->newtio.c_cflag & 0xffffff00) ||
 	    settings.c_lflag != h->newtio.c_lflag)
 		return PORT_ERR_UNKNOWN;
 
