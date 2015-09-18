--- nicksrc/gds.c.orig	2015-09-18 11:00:01.000000000 -0500
+++ nicksrc/gds.c	2015-09-18 11:00:24.000000000 -0500
@@ -347,7 +347,7 @@
      int i, k, maxcat=0 ;
      double t, x ;
 
-    if (n==0) return ;
+    if (n==0) return 0;
     a[0] = maxcat = 1 ;
     for (i=1 ; i< n ; i++)  {
      t = theta/ ((double) i + theta) ;
