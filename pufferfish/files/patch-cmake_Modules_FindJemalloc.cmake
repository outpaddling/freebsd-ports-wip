--- cmake/Modules/FindJemalloc.cmake.orig	2019-12-19 17:41:20 UTC
+++ cmake/Modules/FindJemalloc.cmake
@@ -10,7 +10,7 @@
 find_package(PkgConfig)
 pkg_check_modules(PC_JEMALLOC QUIET libjemalloc)
 
-find_path(JEMALLOC_INCLUDE_DIR jemalloc/jemalloc.h
+find_path(JEMALLOC_INCLUDE_DIR malloc_np.h
   HINTS
     ${JEMALLOC_ROOT} ENV JEMALLOC_ROOT
     ${PC_JEMALLOC_MINIMAL_INCLUDEDIR}
