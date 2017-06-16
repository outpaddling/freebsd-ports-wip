--- sdk/build/bamboo-build.sh.orig	2017-02-08 15:59:46.435509000 -0600
+++ sdk/build/bamboo-build.sh	2017-02-08 16:00:10.194367000 -0600
@@ -43,12 +43,12 @@ fi
 # as we want to see them as we read the log
 # and as a at the tail end which bamboo will show us.
 function do_make () {
-  do_section "make ${@}";
-  make ${@}
+  do_section "gmake ${@}";
+  gmake ${@}
   make_rv=$?
   if [ "${make_rv}" != 0 ]
   then
-    do_error_push "'make ${@}' exited with '${make_rv}'"
+    do_error_push "'gmake ${@}' exited with '${make_rv}'"
   fi
 }
 
