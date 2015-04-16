--- sys/melder_strings.cpp.orig	2015-04-15 19:19:03.000000000 -0500
+++ sys/melder_strings.cpp	2015-04-15 19:19:15.000000000 -0500
@@ -386,7 +386,7 @@
 	expandIfNecessary (char32)
 	my string [my length] = character;
 	my length ++;
-	my string [my length] = U'\0';
+	my string [my length] = (char32)'\0';
 }
 
 void MelderString_get (MelderString *me, wchar_t *destination) {
