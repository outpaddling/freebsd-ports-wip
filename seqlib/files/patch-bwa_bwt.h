--- bwa/bwt.h.orig	2018-03-23 16:13:13 UTC
+++ bwa/bwt.h
@@ -30,6 +30,7 @@
 
 #include <stdint.h>
 #include <stddef.h>
+#include <sys/types.h>
 
 // requirement: (OCC_INTERVAL%16 == 0); please DO NOT change this line because some part of the code assume OCC_INTERVAL=0x80
 #define OCC_INTV_SHIFT 7
