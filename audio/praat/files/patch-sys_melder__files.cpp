--- sys/melder_files.cpp.orig	2015-04-15 19:21:57.000000000 -0500
+++ sys/melder_files.cpp	2015-04-15 19:22:07.000000000 -0500
@@ -301,7 +301,7 @@
 }
 
 bool MelderFile_isNull (MelderFile file) {
-	return file == nullptr || file -> path [0] == '\0';
+	return file == NULL || file -> path [0] == '\0';
 }
 
 void MelderDir_setToNull (MelderDir dir) {
