--- city.cpp.orig	2018-07-27 00:13:36 UTC
+++ city.cpp
@@ -59,6 +59,12 @@ static uint32 UNALIGNED_LOAD32(const cha
     #define bswap_32(x) OSSwapInt32(x)
     #define bswap_64(x) OSSwapInt64(x)
 
+#elif defined(__FreeBSD__)
+
+    #include <sys/endian.h>
+    #define bswap_32(x) bswap32(x)
+    #define bswap_64(x) bswap64(x)
+
 #elif defined(__NetBSD__)
 
     #include <sys/types.h>
