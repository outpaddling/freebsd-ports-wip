--- lumina-desktop/LPanel.cpp.orig	2022-02-23 23:50:42 UTC
+++ lumina-desktop/LPanel.cpp
@@ -74,7 +74,9 @@ LPanel::LPanel(QSettings *file, QString scr, int num, 
     //panelArea->setWindowOpacity(1.0); //fully opaque for the widget on top (apply stylesheet transparencies)
   }
   QTimer::singleShot(1,this, SLOT(UpdatePanel()) );
-  //connect(screen, SIGNAL(resized(int)), this, SLOT(UpdatePanel()) ); //in case the screen resolution changes
+  // Why was this commented out?
+  // Without it, the panel does not redraw reliably when resizing the screen
+  connect(screen, SIGNAL(resized(int)), this, SLOT(UpdatePanel()) ); //in case the screen resolution changes
 }
 
 LPanel::~LPanel(){
