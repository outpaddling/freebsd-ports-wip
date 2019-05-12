--- misc_math.c.orig	2019-05-10 21:23:56 UTC
+++ misc_math.c
@@ -1,5 +1,12 @@
 
+/* For older libm */
+double log2(double n)
+{
+    return log(n) / log(2.0);
+}
+
 /* move from Deconvolve.c into libmri.a         21 Jun 2010 [rickr] */
+
 
 double legendre( double x , int m )   /* Legendre polynomials over [-1,1] */
 {
