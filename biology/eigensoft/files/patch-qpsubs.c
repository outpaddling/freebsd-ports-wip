--- qpsubs.c.orig	2015-09-18 11:02:56.000000000 -0500
+++ qpsubs.c	2015-09-18 11:03:23.000000000 -0500
@@ -2252,7 +2252,7 @@
     free2D(&btop, nblocks);
     free2D(&bbot, nblocks);
 
-    return ;
+    return 0.0;
 
 }
 
