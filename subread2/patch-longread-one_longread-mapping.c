--- longread-one/longread-mapping.c.orig	2018-11-08 14:56:26 UTC
+++ longread-one/longread-mapping.c
@@ -28,7 +28,7 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/resource.h>
-#include <sys/timeb.h>
+#include <sys/time.h>
 #include <sys/stat.h>
 #include <locale.h>
 #include <ctype.h>
@@ -220,11 +220,12 @@ int LRMvalidate_and_init_context(LRMcont
 
 
 double LRMmiltime(){
-	double ret;
-	struct timeb trp;
-	ftime(&trp);
-	ret = trp.time*1.0+(trp.millitm*1.0/1000.0);
-	return ret;
+	//struct timeb trp;
+	//ftime(&trp);
+	//ret = trp.time*1.0+(trp.millitm*1.0/1000.0);
+	struct timeval trp;
+
+	return trp.tv_sec + trp.tv_usec / 1000000.0;
 }
 
 
