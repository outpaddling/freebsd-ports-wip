--- src/wifimgr.c.orig	2013-11-30 15:29:51.000000000 -0600
+++ src/wifimgr.c	2013-11-30 15:30:16.000000000 -0600
@@ -777,7 +777,7 @@
 		err = index(resp, ' ') + 1;
 		sprintf(buf, gettext("Cannot reset interface <b>%s</b> - %s."), wifi_if, err);
 		gui_message(buf, MSG_ERROR);
-		exit(1);
+		//exit(1);
 	}
 
 	/* loop up to 10 seconds for interface to re-associate */
