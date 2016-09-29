--- cmake/uny-config.cmake.orig	2016-09-29 18:16:18.923193000 -0500
+++ cmake/uny-config.cmake	2016-09-29 18:16:38.635334000 -0500
@@ -1,6 +1,6 @@
 # Config generation
 
-find_git_sha1(UNANIMITY_GIT_SHA1)
+# find_git_sha1(UNANIMITY_GIT_SHA1)
 
 file (STRINGS "${UNY_RootDir}/CHANGELOG.md" UNANIMITY_CHANGELOG)
 
