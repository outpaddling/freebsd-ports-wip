--- gene-algorithms.c.orig	2018-10-08 04:32:12 UTC
+++ gene-algorithms.c
@@ -27,10 +27,7 @@
 #include <unistd.h>
 #include <sys/stat.h>
 #include <sys/types.h>
-
-#ifndef FREEBSD
-#include <sys/timeb.h>
-#endif
+#include <sys/time.h>
 
 #include "subread.h"
 #include "input-files.h"
@@ -44,7 +41,7 @@ void non_func(const char * fmt, ...)
 
 void subread_lock_release(subread_lock_t * lock)
 {
-	#ifdef MACOS
+	#ifdef __APPLE__
 	pthread_mutex_unlock(lock);
 	#else
 	pthread_spin_unlock(lock);
@@ -53,7 +50,7 @@ void subread_lock_release(subread_lock_t
 void subread_lock_occupy(subread_lock_t * lock)
 {
 
-	#ifdef MACOS
+	#ifdef __APPLE__
 	pthread_mutex_lock(lock);
 	#else
 	pthread_spin_lock(lock);
@@ -61,7 +58,7 @@ void subread_lock_occupy(subread_lock_t 
 }
 
 void subread_destroy_lock(subread_lock_t * lock) {
-	#ifdef MACOS
+	#ifdef __APPLE__
 	pthread_mutex_destroy(lock);
 	#else
 	pthread_spin_destroy(lock);
@@ -70,7 +67,7 @@ void subread_destroy_lock(subread_lock_t
 
 void subread_init_lock(subread_lock_t * lock)
 {
-	#ifdef MACOS
+	#ifdef __APPLE__
 	pthread_mutex_init(lock, NULL);
 	#else
 	pthread_spin_init(lock, PTHREAD_PROCESS_PRIVATE);
@@ -1556,7 +1553,6 @@ int load_offsets(gene_offset_t* offsets 
 
 double miltime(){
 	double ret;
-	#ifdef FREEBSD
 	struct timeval tp;
 	struct timezone tz;
 	tz.tz_minuteswest=0;
@@ -1565,14 +1561,6 @@ double miltime(){
 	gettimeofday(&tp,&tz);
 
 	ret = tp.tv_sec+ 0.001*0.001* tp.tv_usec; 
-
-	#else
-
-	struct timeb trp;
-	ftime(&trp);
-	ret = trp.time*1.0+(trp.millitm*1.0/1000.0);
-	#endif
-
 	return ret;
 }
 
