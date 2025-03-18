--- aligner_seed2.h.orig	2025-03-17 23:38:43 UTC
+++ aligner_seed2.h
@@ -1223,7 +1223,9 @@ class Descent { (public)
 	{
 		// Take just the portion of the read that has aligned up until this
 		// point
+		#ifndef NDEBUG
 		size_t nuninited = 0;
+		#endif
 		size_t ei = edits.size();
 		size_t en = 0;
 		if(e != NULL && e->inited()) {
@@ -1233,7 +1235,9 @@ class Descent { (public)
 		size_t cur = descid_;
 		while(cur != std::numeric_limits<TDescentId>::max()) {
 			if(!df[cur].edit().inited()) {
+				#ifndef NDEBUG
 				nuninited++;
+				#endif
 				assert_leq(nuninited, 2);
 			} else {
 				edits.push_back(df[cur].edit());
