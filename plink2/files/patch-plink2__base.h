--- plink2_base.h.orig	2018-05-03 04:10:05 UTC
+++ plink2_base.h
@@ -435,7 +435,7 @@ typedef uint32_t BoolErr;
 #  define FOPEN_RB "r"
 #  define FOPEN_WB "w"
 #  define FOPEN_AB "a"
-#  ifdef __APPLE__
+#  if defined(__APPLE__) || defined(__FreeBSD__)
 #    define fread_unlocked fread
 #    define fwrite_unlocked fwrite
 #  endif
