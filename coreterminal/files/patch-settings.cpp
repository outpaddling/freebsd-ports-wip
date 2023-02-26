--- settings.cpp.orig	2022-06-18 05:51:28 UTC
+++ settings.cpp
@@ -92,11 +92,11 @@ void settings::setDefaultSettings()
 	QFont monoFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
 
 	if (not monoFont.family().count()) {
-		monoFont = QFont("monospace", 9);
+		monoFont = QFont("monospace", 12);
 	}
 
 	if (monoFont.styleHint() != QFont::Monospace) {
-		monoFont = QFont("monospace", 9);
+		monoFont = QFont("monospace", 12);
 	}
 
 
@@ -135,7 +135,7 @@ void settings::setDefaultSettings()
 	cSetting->setValue("CoreTerminal/ColorScheme", "WhiteOnBlack");
 	cSetting->setValue("CoreTerminal/TERM", "xterm-256color");
 	cSetting->setValue("CoreTerminal/Rows", 30);
-	cSetting->setValue("CoreTerminal/Columns", 120);
+	cSetting->setValue("CoreTerminal/Columns", 80);
 
 
 	// CorePDF
