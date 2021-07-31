--- coreterminal.cpp.orig	2021-07-31 03:36:34 UTC
+++ coreterminal.cpp
@@ -27,6 +27,7 @@
     *
 */
 
+#include <iostream>
 #include <QWidget>
 #include <QCloseEvent>
 #include <QHBoxLayout>
@@ -34,6 +35,7 @@
 #include <QDir>
 #include <QFileInfo>
 #include <QMessageBox>
+#include <QTabBar>
 
 #include <cprime/appopenfunc.h>
 #include <cprime/variables.h>
@@ -267,7 +269,25 @@ void CoreTerminal::setWindowProperties()
         setStyleSheet( "#base { background-color: palette(Window); }" );
     }
 
-    resize( 800, 500 );
+    // FIXME: Compute window size based on font
+    // resize( 816, 607 );	// 80x30 with 12pt mono
+    // resize( 951, 705 );	// 85x30 with 14pt mono
+    // resize( 896, 728 );	// 80x30 with 14pt mono
+    QFontMetrics fm( terminalFont );
+    std::cerr << "Font em width = " << fm.boundingRect( "M" ).width() 
+		<< "\nFont em height = " << fm.boundingRect("M").height() 
+		<< "\nFont avg width = " << fm.averageCharWidth()
+		<< "\nFont height = " << fm.height()
+		<< "\nTab bar width = " << TabWidget->tabBar()->width()
+		<< "\nTab bar height = " << TabWidget->tabBar()->height()
+		<< '\n';
+    // FIXME: Replace 16 with actual width of scroll bar
+    // int width = fm.boundingRect( "M" ).width() * 80 + 16;
+    int width = fm.averageCharWidth() * 80 + 16;
+    // int height = fm.boundingRect( "M" ).height() * 30
+    int height = fm.height() * 30
+		 + TabWidget->tabBar()->height() + 8;
+    resize(width, height);
 
     if (uiMode != 0) {
         setWindowFlags( windowFlags() );
