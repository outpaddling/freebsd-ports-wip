--- settings.cpp.orig	2021-07-31 03:36:34 UTC
+++ settings.cpp
@@ -90,10 +90,10 @@ void settings::setDefaultSettings()
     QFont monoFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
 
     if ( not monoFont.family().count() )
-        monoFont = QFont("monospace", 9);
+        monoFont = QFont("monospace", 14);
 
     if (monoFont.styleHint() != QFont::Monospace) {
-        monoFont = QFont("monospace", 9);
+        monoFont = QFont("monospace", 14);
     }
     cSetting->setValue("CoreTerminal/Font", monoFont);
 
