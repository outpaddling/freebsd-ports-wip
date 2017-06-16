--- ./src/cpp/core/include/core/r_util/RTokenizer.hpp.orig	2013-12-13 11:17:24.000000000 -0500
+++ ./src/cpp/core/include/core/r_util/RTokenizer.hpp	2013-12-13 11:17:41.000000000 -0500
@@ -25,7 +25,7 @@
 #include <boost/regex_fwd.hpp>
 
 // On Linux confirm that wchar_t is Unicode
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__STDC_ISO_10646__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__STDC_ISO_10646__)
    #error "wchar_t is not Unicode"
 #endif
 
