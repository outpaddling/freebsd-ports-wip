--- libgputils/gpcofflink.c.orig	2014-07-31 08:37:29.000000000 -0500
+++ libgputils/gpcofflink.c	2015-06-13 13:14:59.000000000 -0500
@@ -21,6 +21,7 @@
 
 #include "stdhdr.h"
 #include "libgputils.h"
+#include <sys/endian.h>
 
 gp_boolean gp_relocate_to_shared = false;
 
@@ -762,11 +763,17 @@
 
     /* make sure the section count matches */
     if (object->class->rom_width == 8) {
+      fprintf(stderr, "Using i_memory_get\n");
       object->class->i_memory_get(new->data, new->address, &number, NULL, NULL);
     }
     else {
+      fprintf(stderr, "Using _read_table_data\n");
       number = _read_table_data(object->class, new, new->address);
     }
+//#if BYTE_ORDER == BIG_ENDIAN
+    number = bswap16(number);
+//#endif
+    fprintf(stderr, "number = %u  count = %d\n", number, count);
     assert(number == count);
   }
 }
