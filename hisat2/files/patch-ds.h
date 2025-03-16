--- ds.h.orig	2025-03-16 19:53:10 UTC
+++ ds.h
@@ -4111,9 +4111,9 @@ class RedBlack { (protected)
 				parent->right = n;
 			}
 			n->parent = parent;
-			int thru = 0;
+			// int thru = 0;
 			while(true) {
-				thru++;
+				// thru++;
 				parent = n->parent;
 				if(parent != NULL) assert(parent->repOk());
 				if(parent == NULL && n->red) {
