--- build/env.cmake.orig	2022-12-12 20:10:20 UTC
+++ build/env.cmake
@@ -75,6 +75,9 @@ set(CMAKE_CXX_EXTENSIONS OFF)
 if ( ${CMAKE_SYSTEM_NAME} STREQUAL  "Darwin" )
     set(OS "mac")
     set(SHLX "dylib")
+elseif ( ${CMAKE_SYSTEM_NAME} STREQUAL  "FreeBSD" )
+    set(OS "freebsd")
+    set(SHLX "so")
 elseif ( ${CMAKE_SYSTEM_NAME} STREQUAL  "Linux" )
     set(OS "linux")
     set(SHLX "so")
@@ -97,6 +100,8 @@ elseif ( ${_system_processor} STREQUAL "aarch64")
     set(ARCH "arm64")
 elseif ( ${_system_processor} STREQUAL "x86_64")
     set(ARCH "x86_64")
+elseif ( ${_system_processor} STREQUAL "amd64")
+    set(ARCH "x86_64")
 elseif ( ${_system_processor} STREQUAL "AMD64")
     set(ARCH "x86_64")
 else ()
@@ -110,6 +115,9 @@ if ( "mac" STREQUAL ${OS} )
     set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> Scr <TARGET> <LINK_FLAGS> <OBJECTS>")
     set(CMAKE_C_ARCHIVE_FINISH   "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")
     set(CMAKE_CXX_ARCHIVE_FINISH "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")
+elseif( "freebsd" STREQUAL ${OS} )
+    add_compile_definitions( FREEBSD UNIX )
+    set( LMCHECK -lmcheck )
 elseif( "linux" STREQUAL ${OS} )
     add_compile_definitions( LINUX UNIX )
     set( LMCHECK -lmcheck )
@@ -228,6 +236,9 @@ endif()
 
 if ( "mac" STREQUAL ${OS} )
     include_directories(interfaces/os/mac)
+    include_directories(interfaces/os/unix)
+elseif( "freebsd" STREQUAL ${OS} )
+    include_directories(interfaces/os/freebsd)
     include_directories(interfaces/os/unix)
 elseif( "linux" STREQUAL ${OS} )
     include_directories(interfaces/os/linux)
