--- settings.cpp.orig	2021-07-31 03:36:18 UTC
+++ settings.cpp
@@ -75,13 +75,13 @@ void settings::setDefaultSettings()
     QFont genFont = QFontDatabase::systemFont(QFontDatabase::GeneralFont);
     QFont monoFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
     if ( not genFont.family().count() )
-        genFont = QFont("Cantarell", 9);
+        genFont = QFont("Cantarell", 12);
 
     if ( not monoFont.family().count() )
-        monoFont = QFont("monospace", 9);
+        monoFont = QFont("monospace", 12);
 
     if (monoFont.styleHint() != QFont::Monospace) {
-        monoFont = QFont("monospace", 9);
+        monoFont = QFont("monospace", 12);
     }
 
 	// CoreAction
@@ -113,7 +113,7 @@ void settings::setDefaultSettings()
 	pwent = getpwuid(getuid());
 	cSetting->setValue("CoreTerminal/Shell", pwent->pw_shell);
 
-    cSetting->setValue("CoreTerminal/Opacity", 70);
+    cSetting->setValue("CoreTerminal/Opacity", 99);
     cSetting->setValue("CoreTerminal/HistorySize", 500);
     cSetting->setValue("CoreTerminal/KeyTab", "linux");
     cSetting->setValue("CoreTerminal/CursorShape", 0);
