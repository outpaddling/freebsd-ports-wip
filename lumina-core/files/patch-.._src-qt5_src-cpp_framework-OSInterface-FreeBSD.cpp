--- ../src-cpp/framework-OSInterface-FreeBSD.cpp.orig	2021-12-25 20:33:45.000000000 -0600
+++ ../src-cpp/framework-OSInterface-FreeBSD.cpp	2022-02-17 08:14:20.413578000 -0600
@@ -21,24 +21,34 @@
 bool OSInterface::OS_batteryAvailable(){
   static int bat_avail = -1; //this will not change during a single session - keep later calls fast
   if(bat_avail < 0){
-    int val = getCmdOutput("apm -l").join("").toInt();
-    bat_avail = ((val >= 0 && val <= 100) ? 1 : 0 );
+    bat_avail = (sysctlbyname("hw.acpi.battery.life", &life, &len, NULL, 0) == 0);
   }
   return (bat_avail==1);
 }
 
 float OSInterface::OS_batteryCharge(){
-  int charge = getCmdOutput("apm -l").join("").toInt();
-  if(charge > 100){ charge = -1; } //invalid charge
-  return charge;
+  int life;
+  if ( (sysctlbyname("hw.acpi.battery.life", &life, &len, NULL, 0) != 0) ||
+       (life > 100) )
+    life = -1
+  return life;
 }
 
 bool OSInterface::OS_batteryCharging(){
-  return (getCmdOutput("apm -a").join("").simplified() == "1");
+  if ( (sysctlbyname("hw.acpi.battery.state", &state, &len, NULL, 0) == 0) &&
+       (state == ACPI_BATT_STAT_CHARGING) )
+    return true;
+  else
+    return false;
 }
 
 double OSInterface::OS_batterySecondsLeft(){ //Returns: estimated number of seconds remaining
-  return getCmdOutput("apm -t").join("").toDouble();
+  int min, sec;
+  if ( sysctlbyname("hw.acpi.battery.time", &min, &len, NULL, 0) == 0 )
+    sec = min * 60;
+  else
+    sec = -1
+  return sec;
 }
 
 // = Volume =
