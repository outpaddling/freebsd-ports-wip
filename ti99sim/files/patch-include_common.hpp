--- include/common.hpp.orig	2020-05-25 20:52:23 UTC
+++ include/common.hpp
@@ -116,9 +116,19 @@ template <typename T, size_t N> char( &ArraySizeHelper
 	// Use the environments endian definitions
 	#include <endian.h>
 
-	#define BIG_ENDIAN		__BIG_ENDIAN
+	// Some systems don't define BIG_ENDIAN, etc. in the system header
+
+	#ifndef BIG_ENDIAN
+	#define BIG_ENDIAN	__BIG_ENDIAN
+	#endif
+
+	#ifndef LITTLE_ENDIAN
 	#define LITTLE_ENDIAN	__LITTLE_ENDIAN
-	#define BYTE_ORDER		__BYTE_ORDER
+	#endif
+
+	#ifndef BYTE_ORDER
+	#define BYTE_ORDER	__BYTE_ORDER
+	#endif
 
 #endif
 
