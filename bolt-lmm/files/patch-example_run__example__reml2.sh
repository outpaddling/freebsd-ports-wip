--- example/run_example_reml2.sh.orig	2017-08-03 00:12:17 UTC
+++ example/run_example_reml2.sh
@@ -1,4 +1,6 @@
-../bolt \
+#!/bin/sh -e
+
+bolt \
     --bfile=EUR_subset \
     --phenoFile=EUR_subset.pheno.covars \
     --phenoCol=PHENO \
