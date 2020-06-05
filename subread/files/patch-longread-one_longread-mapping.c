--- longread-one/longread-mapping.c.orig	2019-09-04 04:22:49 UTC
+++ longread-one/longread-mapping.c
@@ -223,10 +223,25 @@ int LRMvalidate_and_init_context(LRMcontext_t ** conte
 
 double LRMmiltime(){
 	double ret;
+
+#ifdef __FreeBSD__
+
+	struct timeval tp;
+	struct timezone tz;
+	tz.tz_minuteswest=0;
+	tz.tz_dsttime=0;
+	gettimeofday(&tp,&tz);
+ 
+	ret = tp.tv_sec+ 0.001*0.001* tp.tv_usec; 
+
+#else
+
 	struct timeb trp;
 	ftime(&trp);
 	ret = trp.time*1.0+(trp.millitm*1.0/1000.0);
 	return ret;
+
+#endif
 }
 
 
