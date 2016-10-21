--- cmake/Modules/FindAtlas.cmake.orig	2016-10-05 16:18:26 UTC
+++ cmake/Modules/FindAtlas.cmake
@@ -12,6 +12,7 @@
 set(Atlas_INCLUDE_SEARCH_PATHS
   /usr/include/atlas
   /usr/include/atlas-base
+  /usr/local/include/atlas
   $ENV{Atlas_ROOT_DIR}
   $ENV{Atlas_ROOT_DIR}/include
 )
@@ -19,6 +20,7 @@ set(Atlas_INCLUDE_SEARCH_PATHS
 set(Atlas_LIB_SEARCH_PATHS
   /usr/lib/atlas
   /usr/lib/atlas-base
+  /usr/local/lib
   $ENV{Atlas_ROOT_DIR}
   $ENV{Atlas_ROOT_DIR}/lib
 )
