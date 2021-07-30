--- settings.cpp.orig	2021-04-11 08:34:27 UTC
+++ settings.cpp
@@ -34,6 +34,10 @@
 #include <cprime/themefunc.h>
 #include <cprime/filefunc.h>
 
+#include <sys/types.h>	// getpwuid()
+#include <pwd.h>	// getpwuid()
+#include <unistd.h>	// getuid()
+
 #include "settings.h"
 
 settings::settings()
@@ -60,6 +64,8 @@ settings::~settings()
 
 void settings::setDefaultSettings()
 {
+    struct passwd *pwent;
+
     // Save screenshot directory
     if (!cSetting->value("CoreShot/SaveLocation").toString().count()) {
         QDir().mkpath(QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) + "/Screen Shots");
@@ -104,8 +110,9 @@ void settings::setDefaultSettings()
     cSetting->setValue("CoreKeyboard/Font", genFont.family());
 
     cSetting->setValue("CoreTerminal/Font", monoFont);
-    cSetting->setValue("CoreTerminal/Shell", "/usr/bin/bash");
-    cSetting->setValue("CoreTerminal/Opacity", 70);
+    pwent = getpwuid(getuid());
+    cSetting->setValue("CoreTerminal/Shell", pwent->pw_shell);
+    cSetting->setValue("CoreTerminal/Opacity", 100);
     cSetting->setValue("CoreTerminal/HistorySize", 500);
     cSetting->setValue("CoreTerminal/KeyTab", "linux");
     cSetting->setValue("CoreTerminal/CursorShape", 0);
