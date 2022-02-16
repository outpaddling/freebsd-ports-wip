--- libLumina/LuminaOS-FreeBSD.cpp.orig	2022-02-16 22:46:44 UTC
+++ libLumina/LuminaOS-FreeBSD.cpp
@@ -301,7 +301,7 @@ bool LOS::hasBattery(){
 
 //Battery Charge Level
 int LOS::batteryCharge(){ //Returns: percent charge (0-100), anything outside that range is counted as an error
-  int charge = LUtils::getCmdOutput("apm -l").join("").toInt();
+  int charge = LUtils::getCmdOutput("sysctl -n hw.acpi.battery.life").join("").toInt();
   if(charge > 100){ charge = -1; } //invalid charge
   return charge;
 }
