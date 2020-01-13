--- src/fastopenblas.h.orig	2018-12-11 05:34:29 UTC
+++ src/fastopenblas.h
@@ -24,9 +24,9 @@
 #include <assert.h>
 #include <iostream>
 extern "C"
-{
-   #include <cblas.h>   // For OpenBlas / Atlas
-}
+//{
+   //#include <cblas.h>   // For OpenBlas / Atlas
+//}
 #include "gsl/gsl_matrix.h"
 
 void fast_cblas_dgemm(const enum CBLAS_ORDER Order,
