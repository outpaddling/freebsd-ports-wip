--- settings.cpp.orig	2021-07-31 03:36:34 UTC
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
 
@@ -101,7 +101,7 @@ void settings::setDefaultSettings()
 	pwent = getpwuid(getuid());
 	cSetting->setValue("CoreTerminal/Shell", pwent->pw_shell);
 
-	cSetting->setValue("CoreTerminal/Opacity", 70);
+	cSetting->setValue("CoreTerminal/Opacity", 99);
 	cSetting->setValue("CoreTerminal/HistorySize", 500);
     cSetting->setValue("CoreTerminal/KeyTab", "linux");
     cSetting->setValue("CoreTerminal/CursorShape", 0);
