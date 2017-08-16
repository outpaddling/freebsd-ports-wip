--- src/FreqTable.h.orig	2017-08-15 21:07:23.727334208 -0500
+++ src/FreqTable.h	2017-08-15 21:08:13.064328811 -0500
@@ -15,7 +15,7 @@ public:
     };
     void remove(const T& t) {
         if (this->data.find(t) == this->data.end()) {
-            return false;
+            return;
         }
         this->data[t] -- ;
         this->isSorted = false;
