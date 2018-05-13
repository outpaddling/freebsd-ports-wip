--- plink2_base.h.orig	2018-05-11 05:21:46 UTC
+++ plink2_base.h
@@ -444,7 +444,7 @@ typedef uint32_t BoolErr;
 #  define FOPEN_RB "r"
 #  define FOPEN_WB "w"
 #  define FOPEN_AB "a"
-#  ifdef __APPLE__
+#  if defined(__APPLE__) || defined(__FreeBSD__)
 #    define fread_unlocked fread
 #    define fwrite_unlocked fwrite
 #  endif
