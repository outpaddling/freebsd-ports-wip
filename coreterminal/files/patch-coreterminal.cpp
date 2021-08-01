--- coreterminal.cpp.orig	2021-07-31 03:36:34 UTC
+++ coreterminal.cpp
@@ -27,6 +27,7 @@
     *
 */
 
+#include <iostream>
 #include <QWidget>
 #include <QCloseEvent>
 #include <QHBoxLayout>
@@ -34,6 +35,8 @@
 #include <QDir>
 #include <QFileInfo>
 #include <QMessageBox>
+#include <QTabBar>
+#include <QStyle>
 
 #include <cprime/appopenfunc.h>
 #include <cprime/variables.h>
@@ -267,7 +270,28 @@ void CoreTerminal::setWindowProperties()
         setStyleSheet( "#base { background-color: palette(Window); }" );
     }
 
-    resize( 800, 500 );
+    QFontMetrics fm( terminalFont );
+    std::cerr << "Font em width = " << fm.boundingRect( "M" ).width() 
+		<< "\nFont em height = " << fm.boundingRect("M").height() 
+		<< "\nFont avg width = " << fm.averageCharWidth()
+		<< "\nFont height = " << fm.height()
+		<< "\nTab bar width = " << TabWidget->tabBar()->width()
+		<< "\nTab bar height = " << TabWidget->tabBar()->height()
+		<< "\nScroll bar width = " << qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent) 
+		//<< "\nframeGeom = " << frameGeometry().height()
+		//<< "\ngeom = " << geometry().height()
+		<< "\nTabBarTabOverlap = " << qApp->style()->pixelMetric(QStyle::PM_TabBarTabOverlap)
+		<< "\nTabBarTabVSpace = " << qApp->style()->pixelMetric(QStyle::PM_TabBarTabVSpace)
+		<< "\nTabBarBaseHeight = " << qApp->style()->pixelMetric(QStyle::PM_TabBarBaseHeight)
+		<< "\nTabBarBaseOverlap = " << qApp->style()->pixelMetric(QStyle::PM_TabBarBaseOverlap)
+		<< "\nTabBar->height() = " << TabWidget->tabBar()->height()
+		<< '\n';
+    int width = fm.averageCharWidth() * 80 + 2
+		+ qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent);
+    int height = fm.height() * 30
+		+ TabWidget->tabBar()->height()
+		+ 8;
+    resize(width, height);
 
     if (uiMode != 0) {
         setWindowFlags( windowFlags() );
