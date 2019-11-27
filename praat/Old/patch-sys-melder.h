--- sys/melder.h.orig	2013-10-22 13:29:40 UTC
+++ sys/melder.h
@@ -1073,6 +1073,11 @@ class autofile { (public)
 			Melder_fclose (file, tmp);
 		}
 	}
+	// operator () is not working in Sound_files.cpp:226 for some reason
+	FILE * get_ptr(void)
+	{
+		return ptr;
+	}
 };
 
 class autoMelderFile {
