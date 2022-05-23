--- src/conversion/ensight/part/ensightPartIO.C.orig	2015-11-03 10:30:23 UTC
+++ src/conversion/ensight/part/ensightPartIO.C
@@ -63,7 +63,7 @@ void Foam::ensightPart::writeFieldList
     {
         forAll(idList, i)
         {
-            if (idList[i] >= field.size() || isnan(field[idList[i]]))
+            if (idList[i] >= field.size() || __inline_isnan(field[idList[i]]))
             {
                 os.writeUndef();
             }
@@ -80,7 +80,7 @@ void Foam::ensightPart::writeFieldList
         // no idList => perNode
         forAll(field, i)
         {
-            if (isnan(field[i]))
+            if (__inline_isnan(field[i]))
             {
                 os.writeUndef();
             }
