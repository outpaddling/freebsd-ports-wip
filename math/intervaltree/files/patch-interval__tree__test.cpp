--- interval_tree_test.cpp.orig	2015-11-21 14:18:07 UTC
+++ interval_tree_test.cpp
@@ -49,11 +49,11 @@ int main() {
 
     // generate a test set of target intervals
     for (int i = 0; i < 10000; ++i) {
-        intervals.push_back(randomInterval<bool, unsigned long>(100000, 1000, 100000 + 1, true));
+        intervals.push_back(randomInterval<bool, unsigned int>(100000, 1000, 100000 + 1, true));
     }
     // and queries
     for (int i = 0; i < 5000; ++i) {
-        queries.push_back(randomInterval<bool, unsigned long>(100000, 1000, 100000 + 1, true));
+        queries.push_back(randomInterval<bool, unsigned int>(100000, 1000, 100000 + 1, true));
     }
 
     typedef chrono::high_resolution_clock Clock;
