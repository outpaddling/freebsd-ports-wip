--- example/run_example_reml2.sh.orig	2017-11-11 16:45:15 UTC
+++ example/run_example_reml2.sh
@@ -1,4 +1,6 @@
-../bolt \
+#!/bin/sh -e
+
+bolt \
     --bfile=EUR_subset \
     --phenoFile=EUR_subset.pheno.covars \
     --phenoCol=PHENO \
