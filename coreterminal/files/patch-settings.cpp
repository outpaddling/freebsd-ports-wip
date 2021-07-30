--- settings.cpp.orig	2021-07-30 14:17:49 UTC
+++ settings.cpp
@@ -92,7 +92,7 @@ void settings::setDefaultSettings()
     }
     cSetting->setValue("CoreTerminal/Font", monoFont);
     cSetting->setValue("CoreTerminal/Shell", QDir(PREFIX_PATH).filePath("bin/bash"));
-	cSetting->setValue("CoreTerminal/Opacity", 70);
+	cSetting->setValue("CoreTerminal/Opacity", 100);
 	cSetting->setValue("CoreTerminal/HistorySize", 500);
     cSetting->setValue("CoreTerminal/KeyTab", "linux");
     cSetting->setValue("CoreTerminal/CursorShape", 0);
