--- ncbi-vdb/libs/kapp/mac/ram.c.orig	2023-08-07 19:52:20 UTC
+++ ncbi-vdb/libs/kapp/mac/ram.c
@@ -46,7 +46,7 @@ rc_t KAppGetTotalRam ( uint64_t * totalRam )
 
     assert ( totalRam != 0 );
 
-    ret = sysctlbyname("hw.memsize", totalRam, &len, NULL, 0 );
+    ret = sysctlbyname("hw.usermem", totalRam, &len, NULL, 0 );
     if ( ret < 0 )
     {
 		int status = errno;
