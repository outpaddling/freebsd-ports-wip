--- ebwt.cpp.orig	2019-07-07 18:54:07 UTC
+++ ebwt.cpp
@@ -51,7 +51,7 @@ string adjustEbwtBase(const string& cmdline,
 		size_t st = str.find_last_of("/\\");
 		if(st != string::npos) {
 			str.erase(st);
-			str += "/indexes/";
+			str += "../share/bowtie/indexes/";
 		} else {
 			str = "indexes/";
 		}
