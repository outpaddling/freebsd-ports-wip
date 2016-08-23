--- src/cpp/core/include/core/r_util/RTokenizer.hpp.orig	2012-03-05 13:16:46.000000000 -0600
+++ src/cpp/core/include/core/r_util/RTokenizer.hpp	2012-03-05 13:18:28.000000000 -0600
@@ -23,7 +23,7 @@
 #include <boost/regex_fwd.hpp>
 
 // On Linux confirm that wchar_t is Unicode
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__STDC_ISO_10646__)
+#if defined(linux) && !defined(__STDC_ISO_10646__)
    #error "wchar_t is not Unicode"
 #endif
 
