--- src/Gui/SoFCCSysDragger.cpp.orig	2024-08-22 11:50:13 UTC
+++ src/Gui/SoFCCSysDragger.cpp
@@ -96,7 +96,7 @@ TDragger::TDragger()
 {
     SO_KIT_CONSTRUCTOR(TDragger);
 
-#if defined(Q_OS_MACOS)
+#if defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD)
     this->ref();
 #endif
 
@@ -400,7 +400,7 @@ TPlanarDragger::TPlanarDragger()
 TPlanarDragger::TPlanarDragger()
 {
     SO_KIT_CONSTRUCTOR(TPlanarDragger);
-#if defined(Q_OS_MACOS)
+#if defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD)
     this->ref();
 #endif
 
@@ -698,7 +698,7 @@ RDragger::RDragger()
 RDragger::RDragger()
 {
     SO_KIT_CONSTRUCTOR(RDragger);
-#if defined(Q_OS_MACOS)
+#if defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD)
     this->ref();
 #endif
 
@@ -1007,6 +1007,10 @@ SoFCCSysDragger::SoFCCSysDragger()
     : axisScale(1.0f, 1.0f, 1.0f)
 {
     SO_KIT_CONSTRUCTOR(SoFCCSysDragger);
+
+#if defined(Q_OS_MAC) || defined(Q_OS_FREEBSD)
+    this->ref();
+#endif
 
     SO_KIT_ADD_CATALOG_ENTRY(annotation, So3DAnnotation, TRUE, geomSeparator, "", TRUE);
     SO_KIT_ADD_CATALOG_ENTRY(scaleNode, SoScale, TRUE, annotation, "", TRUE);
