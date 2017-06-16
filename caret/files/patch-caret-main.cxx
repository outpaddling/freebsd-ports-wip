--- caret/main.cxx.orig	2008-11-23 16:46:04.000000000 -0600
+++ caret/main.cxx	2008-11-23 16:46:23.000000000 -0600
@@ -518,9 +518,9 @@
    //
    // needed for static linking to have JPEG support
    //
-   Q_IMPORT_PLUGIN(qjpeg) //QJpegPlugin)
-   Q_IMPORT_PLUGIN(qgif)  //QGifPlugin)
-   Q_IMPORT_PLUGIN(qtiff) //QTiffPlugin)
+   //Q_IMPORT_PLUGIN(qjpeg) //QJpegPlugin)
+   //Q_IMPORT_PLUGIN(qgif)  //QGifPlugin)
+   //Q_IMPORT_PLUGIN(qtiff) //QTiffPlugin)
 
 #ifdef Q_OS_MACX
    GuiMacOSXApplication app(argc, argv);
