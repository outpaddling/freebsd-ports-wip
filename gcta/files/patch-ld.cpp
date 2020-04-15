--- ld.cpp.orig	2020-04-15 01:52:59 UTC
+++ ld.cpp
@@ -1004,7 +1004,10 @@ void gcta::calcu_max_ld_rsq_blk(eigenVector &multi_rsq
         }
 
 
-        SelfAdjointEigenSolver<MatrixXf> pca(rsq_sub.array());
+	// Fixed compile by removing (rsq_sub.array())
+	// Apparently constructor doesn't come in a 1 arg version
+	// What's the equivalent?
+        SelfAdjointEigenSolver<MatrixXf> pca; // (rsq_sub.array());
 
                 // debug
        // ofstream tmp("tmp_R.txt");
