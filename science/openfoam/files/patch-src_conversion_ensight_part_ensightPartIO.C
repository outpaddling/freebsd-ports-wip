--- src/conversion/ensight/part/ensightPartIO.C.orig	2015-11-25 15:46:18.783150490 -0600
+++ src/conversion/ensight/part/ensightPartIO.C	2015-11-25 15:46:35.750154549 -0600
@@ -63,7 +63,7 @@
     {
         forAll(idList, i)
         {
-            if (idList[i] >= field.size() || isnan(field[idList[i]]))
+            if (idList[i] >= field.size() || __inline_isnan(field[idList[i]]))
             {
                 os.writeUndef();
             }
@@ -80,7 +80,7 @@
         // no idList => perNode
         forAll(field, i)
         {
-            if (isnan(field[i]))
+            if (__inline_isnan(field[i]))
             {
                 os.writeUndef();
             }
