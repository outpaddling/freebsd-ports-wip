--- settings.cpp.orig	2021-07-31 15:02:29 UTC
+++ settings.cpp
@@ -90,10 +90,10 @@ void settings::setDefaultSettings()
     QFont monoFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
 
     if ( not monoFont.family().count() )
-        monoFont = QFont("monospace", 9);
+        monoFont = QFont("monospace", 12);
 
     if (monoFont.styleHint() != QFont::Monospace) {
-        monoFont = QFont("monospace", 9);
+        monoFont = QFont("monospace", 12);
     }
     cSetting->setValue("CoreTerminal/Font", monoFont);
 
