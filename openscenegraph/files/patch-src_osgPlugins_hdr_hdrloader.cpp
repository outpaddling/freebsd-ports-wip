--- src/osgPlugins/hdr/hdrloader.cpp.orig	2025-10-30 13:09:20 UTC
+++ src/osgPlugins/hdr/hdrloader.cpp
@@ -200,7 +200,7 @@ void rawRGBEData(RGBE *_scan, int _len, float *_cols)
 
 void rawRGBEData(RGBE *_scan, int _len, float *_cols)
 {
-    int ii = 0;
+    // int ii = 0;
     while (_len-- > 0) {
         _cols[0] = _scan[0][R] / 255.0f;
         _cols[1] = _scan[0][G] / 255.0f;
@@ -208,7 +208,7 @@ void rawRGBEData(RGBE *_scan, int _len, float *_cols)
         _cols[3] = _scan[0][E] / 255.0f;
         _cols += 4;
         _scan++;
-        ii++;
+        // ii++;
     }
 }
 
@@ -219,7 +219,7 @@ void workOnRGBE(RGBE *_scan, int _len, float *_cols)
 
 void workOnRGBE(RGBE *_scan, int _len, float *_cols)
 {
-    int ii = 0;
+    // int ii = 0;
     while (_len-- > 0) {
         int expo = _scan[0][E] - 128;
         _cols[0] = convertComponent(expo, _scan[0][R]);
@@ -227,7 +227,7 @@ void workOnRGBE(RGBE *_scan, int _len, float *_cols)
         _cols[2] = convertComponent(expo, _scan[0][B]);
         _cols += 3;
         _scan++;
-        ii++;
+        // ii++;
     }
 }
 
