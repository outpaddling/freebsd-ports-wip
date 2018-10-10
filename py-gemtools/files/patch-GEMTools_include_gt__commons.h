--- GEMTools/include/gt_commons.h.orig	2018-10-10 13:15:37 UTC
+++ GEMTools/include/gt_commons.h
@@ -125,7 +125,7 @@
 #define gt_expect_false(condition) __builtin_expect(condition,0)
 
 // GemTools Inline
-#define GT_INLINE inline
+#define GT_INLINE
 
 // Macro Stringify
 #define GT_QUOTE(value) #value
