--- lumina-desktop/LDesktopBackground.cpp.orig	2022-02-24 00:18:31 UTC
+++ lumina-desktop/LDesktopBackground.cpp
@@ -83,6 +83,10 @@ QPixmap LDesktopBackground::setBackground(const QStrin
 LDesktopBackground::LDesktopBackground() : QWidget() {
     bgPixmap = NULL;
     this->setWindowOpacity(0);
+
+    // Copied from LPanel
+    //in case the screen resolution changes
+    //connect(screen, SIGNAL(resized(int)), this, SLOT(UpdateBackground()) );
 }
 
 LDesktopBackground::~LDesktopBackground() {
