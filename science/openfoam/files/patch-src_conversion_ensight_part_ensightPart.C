--- src/conversion/ensight/part/ensightPart.C.orig	2015-11-03 10:30:23 UTC
+++ src/conversion/ensight/part/ensightPart.C
@@ -51,7 +51,7 @@ bool Foam::ensightPart::isFieldDefined(c
         {
             const label id = idList[i];
 
-            if (id >= field.size() || isnan(field[id]))
+            if (id >= field.size() || __inline_isnan(field[id]))
             {
                 return false;
             }
