--- cityhash/city.cc.orig	2014-10-06 12:28:25 UTC
+++ cityhash/city.cc
@@ -69,6 +69,12 @@ static uint32 UNALIGNED_LOAD32(const cha
 #define bswap_64(x) bswap64(x)
 #endif
 
+#elif defined(__FreeBSD__)
+
+#include <sys/endian.h>
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
+
 #else
 
 #include <byteswap.h>
