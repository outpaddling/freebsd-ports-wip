--- cmake/Modules/FindTBB.cmake.orig	2021-09-12 13:06:05 UTC
+++ cmake/Modules/FindTBB.cmake
@@ -184,7 +184,7 @@ if(NOT TBB_FOUND)
   ##################################
 
   if(TBB_INCLUDE_DIRS)
-    file(READ "${TBB_INCLUDE_DIRS}/tbb/tbb_stddef.h" _tbb_version_file)
+    file(READ "${TBB_INCLUDE_DIRS}/oneapi/tbb/version.h" _tbb_version_file)
     string(REGEX REPLACE ".*#define TBB_VERSION_MAJOR ([0-9]+).*" "\\1"
         TBB_VERSION_MAJOR "${_tbb_version_file}")
     string(REGEX REPLACE ".*#define TBB_VERSION_MINOR ([0-9]+).*" "\\1"
