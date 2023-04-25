--- include/bm/bm_sim/_assert.h.orig	2023-04-25 15:37:20 UTC
+++ include/bm/bm_sim/_assert.h
@@ -25,14 +25,14 @@
 
 namespace bm {
 
-[[ noreturn ]] void _assert(const char* expr, const char* file, int line);
+[[ noreturn ]] void bm_assert(const char* expr, const char* file, int line);
 
 }  // namespace bm
 
 #define _BM_ASSERT(expr) \
-  ((expr) ? (void)0 : bm::_assert(#expr, __FILE__, __LINE__))
+  ((expr) ? (void)0 : bm::bm_assert(#expr, __FILE__, __LINE__))
 
-#define _BM_UNREACHABLE(msg) bm::_assert(msg, __FILE__, __LINE__)
+#define _BM_UNREACHABLE(msg) bm::bm_assert(msg, __FILE__, __LINE__)
 
 #define _BM_UNUSED(x) ((void)x)
 
