--- src/conversion/ensight/part/ensightPart.C.orig	2015-11-25 15:36:00.999186869 -0600
+++ src/conversion/ensight/part/ensightPart.C	2015-11-25 15:45:35.474156401 -0600
@@ -51,7 +51,7 @@
         {
             const label id = idList[i];
 
-            if (id >= field.size() || isnan(field[id]))
+            if (id >= field.size() || __inline_isnan(field[id]))
             {
                 return false;
             }
