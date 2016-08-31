--- libs/Common/Types.h.orig	2016-04-06 20:59:29 UTC
+++ libs/Common/Types.h
@@ -331,7 +331,7 @@ FORCEINLINE T RANDOM() { return (T(1)/RA
 # define __BIG_ENDIAN 1
 # define __PDP_ENDIAN 2
 # define __BYTE_ORDER __LITTLE_ENDIAN
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 # include <machine/endian.h>
 #elif defined(__GNUC__)
 # include <endian.h>
