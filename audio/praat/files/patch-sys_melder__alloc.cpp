--- sys/melder_alloc.cpp.orig	2015-04-15 19:17:12.000000000 -0500
+++ sys/melder_alloc.cpp	2015-04-15 19:18:22.000000000 -0500
@@ -317,8 +317,8 @@
 }
 
 int Melder_str32cmp (const char32 *string1, const char32 *string2) {
-	if (string1 == NULL) string1 = U"";
-	if (string2 == NULL) string2 = U"";
+	if (string1 == NULL) string1 = (char32 *)"";
+	if (string2 == NULL) string2 = (char32 *)"";
 	return str32cmp (string1, string2);
 }
 
