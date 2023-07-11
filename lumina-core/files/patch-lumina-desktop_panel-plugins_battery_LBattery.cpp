--- lumina-desktop/panel-plugins/battery/LBattery.cpp.orig	2021-12-26 02:33:45 UTC
+++ lumina-desktop/panel-plugins/battery/LBattery.cpp
@@ -35,7 +35,7 @@ void LBattery::updateBattery(bool force){
   QString batt_icon = LSession::batteryIconName(charge, charging);
   if(iconOld != batt_icon){
     label->setPixmap( QIcon::fromTheme(batt_icon).pixmap(label->size()) );
-    if(charge <= 5 && !charging){
+    if(charge <= 10 && !charging){
       //Play some audio warning chime when
       bool playaudio = sessionsettings->value("PlayBatteryLowAudio",true).toBool();
       if( playaudio ){
@@ -47,7 +47,9 @@ void LBattery::updateBattery(bool force){
     iconOld = batt_icon; //save for later
   }
 
-  if(charge<=5 && !charging){ label->setStyleSheet("QLabel{ background: red;}"); }
+  // FIXME: Add popup warning when battery reaches 20% and 10%
+  if(charge<=20 && !charging){ label->setStyleSheet("QLabel{ background: red;}"); }
+  else if(charge<=50 && !charging){ label->setStyleSheet("QLabel{ background: orange;}"); }
   else if(charge>98 && charging){ label->setStyleSheet("QLabel{ background: green;}"); }
   else{ label->setStyleSheet("QLabel{ background: transparent;}"); }
 
