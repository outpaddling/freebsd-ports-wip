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
@@ -267,7 +270,36 @@ void CoreTerminal::setWindowProperties()
         setStyleSheet( "#base { background-color: palette(Window); }" );
     }
 
-    resize( 800, 500 );
+    QFontMetrics fm( terminalFont );
+    std::cerr	<< "fm.boundingRect(\"M\").width() = " << fm.boundingRect( "M" ).width() 
+		<< "\nfm.boundingRect(\"M\").height() = " << fm.boundingRect("M").height() 
+		<< "\nfm.averageCharWidth() = " << fm.averageCharWidth()
+		<< "\nfm.height() = " << fm.height()
+		<< "\ntabBar.width() = " << TabWidget->tabBar()->width()
+		<< "\ntabBar.height() = " << TabWidget->tabBar()->height()
+		<< "\nframeGeometry.height() = " << frameGeometry().height()
+		<< "\ngeometry.height() = " << geometry().height()
+		<< "\nPM_ScrollBarExtent = " << qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent) 
+		<< "\nPM_TabBarTabOverlap = " << qApp->style()->pixelMetric(QStyle::PM_TabBarTabOverlap)
+		<< "\nPM_TabBarTabVSpace = " << qApp->style()->pixelMetric(QStyle::PM_TabBarTabVSpace)
+		<< "\nPM_TabBarBaseHeight = " << qApp->style()->pixelMetric(QStyle::PM_TabBarBaseHeight)
+		<< "\nPM_TabBarBaseOverlap = " << qApp->style()->pixelMetric(QStyle::PM_TabBarBaseOverlap)
+		<< "\ntabBar()->height() = " << TabWidget->tabBar()->height()
+		<< "\ntabBar()->tabRect().height() = " << TabWidget->tabBar()->tabRect(0).height()
+		<< '\n';
+    int width = fm.averageCharWidth() * 80 + 2
+		+ qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent);
+    /*
+     * Perfect size =
+     * tabBar->height() +7 for Fusion, +4 for QtCurve, +3 for Windows
+     * tabBar->tabRect(0).height() gets very close:
+     * 36 for Fusion, 33 for QtCurve, 32 for Windows
+     * Needs to be verified for other themes
+     */
+    int height = fm.height() * 30
+		+ TabWidget->tabBar()->tabRect(0).height()
+		+ 1;
+    resize(width, height);
 
     if (uiMode != 0) {
         setWindowFlags( windowFlags() );
