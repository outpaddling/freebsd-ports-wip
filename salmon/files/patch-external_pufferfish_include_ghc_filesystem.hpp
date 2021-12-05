--- external/pufferfish/include/ghc/filesystem.hpp.orig	2021-12-05 16:57:38 UTC
+++ external/pufferfish/include/ghc/filesystem.hpp
@@ -50,7 +50,7 @@
 
 #if defined(__APPLE__) && defined(__MACH__)
 #define GHC_OS_MACOS
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #define GHC_OS_LINUX
 #elif defined(_WIN64)
 #define GHC_OS_WINDOWS
