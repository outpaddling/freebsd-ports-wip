--- libsrc2/hyper.c.orig	2012-09-24 10:19:31.000000000 -0500
+++ libsrc2/hyper.c	2013-10-28 20:53:12.000000000 -0500
@@ -766,7 +766,7 @@
             miicv_setint(icv, MI_ICV_DO_DIM_CONV, TRUE);
           break;
         default:
-          return;
+          return MI_ERROR;
         }
       }
     result = miicv_attach(icv, file_id, var_id);
