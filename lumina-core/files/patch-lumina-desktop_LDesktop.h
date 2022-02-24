--- lumina-desktop/LDesktop.h.orig	2022-02-24 14:42:08 UTC
+++ lumina-desktop/LDesktop.h
@@ -62,7 +62,7 @@ public slots:
 private:
 	QSettings *settings;
 	QTimer *bgtimer;
-	//QDesktopWidget *desktop;
+	QDesktopWidget *screen;
 	QString DPREFIX, screenID;
 	//int desktopnumber;
 	QRegion availDPArea;
