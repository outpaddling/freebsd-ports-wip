--- nicksrc/gds.c.orig	2015-03-06 16:21:28 UTC
+++ nicksrc/gds.c
@@ -347,7 +347,7 @@ int ewens(int *a, int n, double theta) 
      int i, k, maxcat=0 ;
      double t, x ;
 
-    if (n==0) return ;
+    if (n==0) return 0;
     a[0] = maxcat = 1 ;
     for (i=1 ; i< n ; i++)  {
      t = theta/ ((double) i + theta) ;
