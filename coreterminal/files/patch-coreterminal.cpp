--- coreterminal.cpp.orig	2022-06-03 10:02:31 UTC
+++ coreterminal.cpp
@@ -254,7 +254,7 @@ void CoreTerminal::setWindowProperties()
 //    }
 
 	int rows = smi->getValue("CoreTerminal", "Rows", 30);
-	int cols = smi->getValue("CoreTerminal", "Columns", 120);
+	int cols = smi->getValue("CoreTerminal", "Columns", 80);
 
 	auto screenSize = QApplication::primaryScreen()->availableSize();
 	int w = qMin(screenSize.width(), getWidthByColumn(cols));
