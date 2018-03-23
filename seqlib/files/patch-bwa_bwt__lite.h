--- bwa/bwt_lite.h.orig	2018-03-23 16:19:47 UTC
+++ bwa/bwt_lite.h
@@ -2,6 +2,7 @@
 #define BWT_LITE_H_
 
 #include <stdint.h>
+#include <sys/types.h>
 
 typedef struct {
 	uint32_t seq_len, bwt_size, n_occ;
