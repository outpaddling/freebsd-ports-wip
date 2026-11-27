--- libLumina/LuminaOS-FreeBSD.cpp.orig	2025-07-19 13:47:16 UTC
+++ libLumina/LuminaOS-FreeBSD.cpp
@@ -9,6 +9,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
+#include <sys/param.h> // __FreeBSD_version
 #include <dev/acpica/acpiio.h>
 
 #include <QDebug>
@@ -172,10 +173,29 @@ int LOS::audioVolume(){ //Returns: audio volume as a p
      audiovolume = out;
   }else{
     //probe the system for the current volume (other utils could be changing it)
+    // mixer interface changed in FreeBSD 14
+    // 13 and prior: mixer -S vol outputs
+    // vol:50:50
+    // 14 and later, there is no -S flag, and vol is a fraction, not a %
+    // mixer -o vol outputs
+    // vol.volume=0.75:0.75
+    //      vol.mute=0
+    // Might be better to use the mixer API instead
+#if __FreeBSD_version < 1400000
       QString info = LUtils::getCmdOutput("mixer -S vol").join(":").simplified(); //ignores any other lines
       if(!info.isEmpty()){
         int L = info.section(":",1,1).toInt();
         int R = info.section(":",2,2).toInt();
+#else
+      // Produce something like vol.volume=0.26:0.26=vol.mute=0=
+      // Multiple lines are joined, separated by '='
+      QString info = LUtils::getCmdOutput("mixer -o vol").join("=").simplified();
+      if(!info.isEmpty()){
+        int L = info.section(QRegularExpression("[=:]"),1,1).toDouble() * 100.0;
+        int R = info.section(QRegularExpression("[=:]"),2,2).toDouble() * 100.0;
+#endif
+
+
         if(L>R){ out = L; }
         else{ out = R; }
 	if(out != audiovolume){
@@ -196,10 +216,27 @@ void LOS::setAudioVolume(int percent){
   if(remoteSession){
     LUtils::runCmd(QString("pactl set-sink-volume @DEFAULT_SINK@ ")+QString::number(percent)+"%");
   }else{
-    QString info = LUtils::getCmdOutput("mixer -S vol").join(":").simplified(); //ignores any other lines
-    if(!info.isEmpty()){
-      int L = info.section(":",1,1).toInt();
-      int R = info.section(":",2,2).toInt();
+    // mixer interface changed in FreeBSD 14
+    // 13 and prior: mixer -S vol outputs
+    // vol:50:50
+    // 14 and later, there is no -S flag, and vol is a fraction, not a %
+    // mixer -o vol outputs
+    // vol.volume=0.75:0.75
+    //      vol.mute=0
+    // Might be better to use the mixer API instead
+#if __FreeBSD_version < 1400000
+      QString info = LUtils::getCmdOutput("mixer -S vol").join(":").simplified(); //ignores any other lines
+      if(!info.isEmpty()){
+        int L = info.section(":",1,1).toInt();
+        int R = info.section(":",2,2).toInt();
+#else
+      // Produce something like vol.volume=0.26:0.26=vol.mute=0=
+      // Multiple lines are joined, separated by '='
+      QString info = LUtils::getCmdOutput("mixer -o vol").join("=").simplified();
+      if(!info.isEmpty()){
+        int L = info.section(QRegularExpression("[=:]"),1,1).toDouble() * 100.0;
+        int R = info.section(QRegularExpression("[=:]"),2,2).toDouble() * 100.0;
+#endif
       int diff = L-R;
       if((percent == L) && (L==R)){ return; } //already set to that volume
       if(diff<0){ R=percent; L=percent+diff; } //R Greater
@@ -208,7 +245,11 @@ void LOS::setAudioVolume(int percent){
       if(L<0){L=0;}else if(L>100){L=100;}
       if(R<0){R=0;}else if(R>100){R=100;}
       //Run Command
+#if __FreeBSD_version < 1400000
       LUtils::runCmd("mixer vol "+QString::number(L)+":"+QString::number(R));
+#else
+      LUtils::runCmd("mixer vol="+QString::number(L/100.0)+":"+QString::number(R/100.0));
+#endif
     }
   }
   audiovolume = percent; //save for checking later
@@ -221,15 +262,36 @@ void LOS::changeAudioVolume(int percentdiff){
   if(remoteSession){
     LUtils::runCmd(QString("pactl set-sink-volume @DEFAULT_SINK@ ")+((percentdiff>0)?"+" : "") + QString::number(percentdiff)+"%");
   }else{
-    QString info = LUtils::getCmdOutput("mixer -S vol").join(":").simplified(); //ignores any other lines
-    if(!info.isEmpty()){
-      int L = info.section(":",1,1).toInt() + percentdiff;
-      int R = info.section(":",2,2).toInt() + percentdiff;
+    // mixer interface changed in FreeBSD 14
+    // 13 and prior: mixer -S vol outputs
+    // vol:50:50
+    // 14 and later, there is no -S flag, and vol is a fraction, not a %
+    // mixer -o vol outputs
+    // vol.volume=0.75:0.75
+    //      vol.mute=0
+    // Might be better to use the mixer API instead
+#if __FreeBSD_version < 1400000
+      QString info = LUtils::getCmdOutput("mixer -S vol").join(":").simplified(); //ignores any other lines
+      if(!info.isEmpty()){
+        int L = info.section(":",1,1).toInt();
+        int R = info.section(":",2,2).toInt();
+#else
+      // Produce something like vol.volume=0.26:0.26=vol.mute=0=
+      // Multiple lines are joined, separated by '='
+      QString info = LUtils::getCmdOutput("mixer -o vol").join("=").simplified();
+      if(!info.isEmpty()){
+        int L = info.section(QRegularExpression("[=:]"),1,1).toDouble() * 100.0;
+        int R = info.section(QRegularExpression("[=:]"),2,2).toDouble() * 100.0;
+#endif
       //Check bounds
       if(L<0){L=0;}else if(L>100){L=100;}
       if(R<0){R=0;}else if(R>100){R=100;}
       //Run Command
+#if __FreeBSD_version < 1400000
       LUtils::runCmd("mixer vol "+QString::number(L)+":"+QString::number(R));
+#else
+      LUtils::runCmd("mixer vol="+QString::number(L/100.0)+":"+QString::number(R/100.0));
+#endif
     }
   }
 }
