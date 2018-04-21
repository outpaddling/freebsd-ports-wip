--- common/utility/visitstream.h.orig	2018-04-21 14:14:28 UTC
+++ common/utility/visitstream.h
@@ -49,6 +49,7 @@
 
 #else
 // Include iostream and some using statements.
+#include <cctype>
 #include <iostream>
 
 using std::cerr;
