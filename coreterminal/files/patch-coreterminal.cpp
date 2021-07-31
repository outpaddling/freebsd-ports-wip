--- coreterminal.cpp.orig	2021-07-31 03:36:34 UTC
+++ coreterminal.cpp
@@ -267,7 +267,10 @@ void CoreTerminal::setWindowProperties()
         setStyleSheet( "#base { background-color: palette(Window); }" );
     }
 
-    resize( 800, 500 );
+    // FIXME: Compute window size based on font
+    // resize( 816, 607 );	// 80x30 with 12pt mono
+    // resize( 951, 705 );	// 85x30 with 14pt mono
+    resize( 896, 726 );	// 80x30 with 14pt mono
 
     if (uiMode != 0) {
         setWindowFlags( windowFlags() );
