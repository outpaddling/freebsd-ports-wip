--- qpsubs.c.orig	2015-03-06 16:21:28 UTC
+++ qpsubs.c
@@ -2252,7 +2252,7 @@ double doinbreed(double *inb, double *in
     free2D(&btop, nblocks);
     free2D(&bbot, nblocks);
 
-    return ;
+    return 0.0;
 
 }
 
