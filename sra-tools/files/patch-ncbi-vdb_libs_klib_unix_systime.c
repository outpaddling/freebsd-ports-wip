--- ncbi-vdb/libs/klib/unix/systime.c.orig	2023-08-07 20:18:51 UTC
+++ ncbi-vdb/libs/klib/unix/systime.c
@@ -142,7 +142,9 @@ LIB_EXPORT KTime_t CC KTimeMakeTime ( const KTime *sel
         t . tm_isdst = self -> dst;
 
         ts = mktime ( &t );
-        ts -= timezone;
+        // FIXME: timezone is a global var under Linux
+	// Is this even necessary?  Use timegm() instead?
+        // ts -= timezone;
     }
 
     return ts;
