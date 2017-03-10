--- gcta.h.orig	2017-03-10 10:33:39.109610000 -0600
+++ gcta.h	2017-03-10 10:35:10.788255000 -0600
@@ -17,9 +17,9 @@
 #define EIGEN_YES_I_KNOW_SPARSE_MODULE_IS_NOT_STABLE_YET
 #endif
 
-#ifndef EIGEN_USE_MKL_ALL
-#define EIGEN_USE_MKL_ALL
-#endif
+//#ifndef EIGEN_USE_MKL_ALL
+//#define EIGEN_USE_MKL_ALL
+//#endif
 
 #include "CommFunc.h"
 #include "StrFunc.h"
@@ -36,8 +36,8 @@
 #include <unsupported/Eigen/SparseExtra>
 #include <unsupported/Eigen/IterativeSolvers>
 #include <omp.h>
-#include <mkl_cblas.h>
-#include <mkl_lapack.h>
+#include <cblas.h>
+//#include <lapack.h>
 
 using namespace Eigen;
 using namespace std;
