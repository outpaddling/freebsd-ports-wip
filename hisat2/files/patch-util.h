--- util.h.orig	2025-03-16 20:03:42 UTC
+++ util.h
@@ -43,7 +43,8 @@ char* itoa10(const T& value, char* result) {
 	// Only apply negative sign for base 10
 	if(std::numeric_limits<T>::is_signed) {
 		// Avoid compiler warning in cases where T is unsigned
-		if (value <= 0 && value != 0) *out++ = '-';
+		// if (value <= 0 && value != 0) *out++ = '-';
+		if (value < 0) *out++ = '-';
 	}
 	reverse( result, out );
 	*out = 0; // terminator
