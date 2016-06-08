--- cmake/create_pkgconfig_file.cmake.orig	2016-06-08 19:40:23 UTC
+++ cmake/create_pkgconfig_file.cmake
@@ -25,5 +25,5 @@ macro (create_pkgconfig_file name desc r
             "\n"
         )
 
-    install(FILES ${_pkgfname} DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
+    install(FILES ${_pkgfname} DESTINATION libdata/pkgconfig)
 endmacro()
