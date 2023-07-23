--- bamSortByCoordinate.cpp.orig	2022-11-01 14:50:35 UTC
+++ bamSortByCoordinate.cpp
@@ -69,7 +69,7 @@ void bamSortByCoordinate (Parameters &P, ReadAlignChun
                             boolWait=false;
                             totalMem+=newMem;
                         };
-                        sleep(0.1);
+                        usleep(100000);
                     };
                     BAMbinSortByCoordinate(ibin,binN,binS,P.runThreadN,P.outBAMsortTmpDir, P, genome, solo);
                     #pragma omp critical
