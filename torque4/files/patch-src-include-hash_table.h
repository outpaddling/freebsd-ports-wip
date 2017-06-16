--- src/include/hash_table.h.orig	2011-12-27 10:31:47.000000000 -0600
+++ src/include/hash_table.h	2011-12-27 10:31:58.000000000 -0600
@@ -80,7 +80,7 @@
 #ifndef HASH_TABLE_H
 #define HASH_TABLE_H
 
-#include "endian.h" /* LITTLE_ENDIAN */
+#include "sys/endian.h" /* LITTLE_ENDIAN */
 
 #ifdef __BYTE_ORDER
 # if __BYTE_ORDER == __LITTLE_ENDIAN
