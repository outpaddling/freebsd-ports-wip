--- src/bm_sim/_assert.cpp.orig	2023-04-25 19:10:08 UTC
+++ src/bm_sim/_assert.cpp
@@ -25,7 +25,7 @@
 
 namespace bm {
 
-void _assert(const char* expr, const char* file, int line) {
+void bm_assert(const char* expr, const char* file, int line) {
   std::cerr << "Assertion '" << expr << "' failed, file '" << file
             << "' line '" << line << "'.\n";
   std::abort();
