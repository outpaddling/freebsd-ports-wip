--- cmake/uny-gitsha1.cmake.orig	2016-09-12 19:55:43 UTC
+++ cmake/uny-gitsha1.cmake
@@ -7,7 +7,7 @@ set(__find_git_sha1 YES)
 function(find_git_sha1 _GIT_SHA1)
     find_package(Git QUIET REQUIRED)
     execute_process(COMMAND
-        "${GIT_EXECUTABLE}" "describe" "--always" "--dirty=*"
+        echo 054c595
         WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
         RESULT_VARIABLE res
         OUTPUT_VARIABLE out
