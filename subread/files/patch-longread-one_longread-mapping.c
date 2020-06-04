--- longread-one/longread-mapping.c.orig	2020-06-04 20:05:33 UTC
+++ longread-one/longread-mapping.c
@@ -30,7 +30,6 @@
 #ifndef __MINGW32__
 #include <sys/resource.h>
 #endif
-#include <sys/timeb.h>
 #include <sys/stat.h>
 #include <locale.h>
 #include <ctype.h>
@@ -222,12 +221,11 @@ int LRMvalidate_and_init_context(LRMcontext_t ** conte
 
 
 double LRMmiltime(){
-	double ret;
-	struct timeb trp;
-	ftime(&trp);
-	ret = trp.time*1.0+(trp.millitm*1.0/1000.0);
-	return ret;
+	struct timeval trp;
+
+	return trp.tv_sec + trp.tv_usec / 1000000.0;
 }
+
 
 
 void LRMset_default_values_context(LRMcontext_t * context){
