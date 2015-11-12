--- nifti/cifti/afni_xml.h.orig	2015-11-11 21:47:45.000000000 -0600
+++ nifti/cifti/afni_xml.h	2015-11-11 21:48:01.000000000 -0600
@@ -5,6 +5,7 @@
 #define AXML_MAX_ELEN  128   /* maximum element length */
 
 #include <stdio.h>
+#include <inttypes.h>
 
 /* ----------------------------------------------------------------------
    This code is for generic reading of xml into structures.
