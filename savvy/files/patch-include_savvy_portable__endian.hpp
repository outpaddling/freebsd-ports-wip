--- include/savvy/portable_endian.hpp.orig	2019-01-14 21:40:53 UTC
+++ include/savvy/portable_endian.hpp
@@ -49,14 +49,14 @@
 
 # include <sys/endian.h>
 
-# define be16toh(x) betoh16(x)
-# define le16toh(x) letoh16(x)
+// # define be16toh(x) betoh16(x)
+// # define le16toh(x) letoh16(x)
 
-# define be32toh(x) betoh32(x)
-# define le32toh(x) letoh32(x)
+// # define be32toh(x) betoh32(x)
+// # define le32toh(x) letoh32(x)
 
-# define be64toh(x) betoh64(x)
-# define le64toh(x) letoh64(x)
+// # define be64toh(x) betoh64(x)
+// # define le64toh(x) letoh64(x)
 
 #elif defined(__WINDOWS__)
 
@@ -115,4 +115,4 @@
 
 #endif
 
-#endif
\ No newline at end of file
+#endif
