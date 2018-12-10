--- build/cmake/macros/SystemSpecificInformations.cmake.orig	2018-12-10 21:54:15 UTC
+++ build/cmake/macros/SystemSpecificInformations.cmake
@@ -265,7 +265,8 @@ if(UNIX)
     set( SYSTEM_NAME "freebsd_${FREEBSD_RELEASE}" )
     set( CONDOR_FREEBSD ON )
     set( BSD_UNIX ON )
-    # FIXME: Is there a >= to replace all the MATCHES operators below?
+    # FreeBSD 8 and later just use CONDOR_FREEBSD
+    # FreeBSD 9 and later require utmpx
     if(FREEBSD_MAJOR MATCHES "4" )
       set( CONDOR_FREEBSD4 ON )
     elseif(FREEBSD_MAJOR MATCHES "5" )
@@ -276,17 +277,7 @@ if(UNIX)
       set( CONDOR_FREEBSD7 ON )
     elseif(FREEBSD_MAJOR MATCHES "8" )
       set( CONDOR_FREEBSD8 ON )
-    elseif(FREEBSD_MAJOR MATCHES "9" )
-      set( CONDOR_FREEBSD9 ON )
-      set( CONDOR_UTMPX ON )
-    elseif(FREEBSD_MAJOR MATCHES "10" )
-      set( CONDOR_FREEBSD10 ON )
-      set( CONDOR_UTMPX ON )
-    elseif(FREEBSD_MAJOR MATCHES "11" )
-      set( CONDOR_FREEBSD11 ON )
-      set( CONDOR_UTMPX ON )
-    elseif(FREEBSD_MAJOR MATCHES "12" )
-      set( CONDOR_FREEBSD11 ON )
+    elseif(FREEBSD_MAJOR GREATER "8" )
       set( CONDOR_UTMPX ON )
     endif()
     if( CMAKE_SYSTEM_PROCESSOR MATCHES "amd64" )
