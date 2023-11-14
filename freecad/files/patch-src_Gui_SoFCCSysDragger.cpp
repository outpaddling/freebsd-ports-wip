--- src/Gui/SoFCCSysDragger.cpp.orig	2023-11-14 12:35:18 UTC
+++ src/Gui/SoFCCSysDragger.cpp
@@ -90,6 +90,8 @@ TDragger::TDragger()
 {
     SO_KIT_CONSTRUCTOR(TDragger);
 
+    this->ref();
+
     SO_KIT_ADD_CATALOG_ENTRY(translatorSwitch, SoSwitch, TRUE, geomSeparator, "", TRUE);
     SO_KIT_ADD_CATALOG_ENTRY(translator, SoSeparator, TRUE, translatorSwitch, "", TRUE);
     SO_KIT_ADD_CATALOG_ENTRY(translatorActive, SoSeparator, TRUE, translatorSwitch, "", TRUE);
@@ -367,6 +369,8 @@ RDragger::RDragger()
 {
     SO_KIT_CONSTRUCTOR(RDragger);
 
+    this->ref();
+
     SO_KIT_ADD_CATALOG_ENTRY(rotatorSwitch, SoSwitch, TRUE, geomSeparator, "", TRUE);
     SO_KIT_ADD_CATALOG_ENTRY(rotator, SoSeparator, TRUE, rotatorSwitch, "", TRUE);
     SO_KIT_ADD_CATALOG_ENTRY(rotatorActive, SoSeparator, TRUE, rotatorSwitch, "", TRUE);
@@ -649,6 +653,8 @@ SoFCCSysDragger::SoFCCSysDragger()
     ,scaleInited(false)
 {
     SO_KIT_CONSTRUCTOR(SoFCCSysDragger);
+
+    this->ref();
 
     SO_KIT_ADD_CATALOG_ENTRY(annotation, SoAnnotation, TRUE, geomSeparator, "", TRUE);
     SO_KIT_ADD_CATALOG_ENTRY(scaleNode, SoScale, TRUE, annotation, "", TRUE);
