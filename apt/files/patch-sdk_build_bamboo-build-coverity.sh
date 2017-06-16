--- sdk/build/bamboo-build-coverity.sh.orig	2017-02-08 15:57:45.757060000 -0600
+++ sdk/build/bamboo-build-coverity.sh	2017-02-08 15:59:14.264076000 -0600
@@ -47,12 +47,12 @@ fi
 # as we want to see them as we read the log
 # and as a at the tail end which bamboo will show us.
 function do_make () {
-  do_section "make ${@}";
-  make ${@}
-  make_rv=$?
+  do_section "gmake ${@}";
+  gmake ${@}
+  gmake_rv=$?
   if [ "${make_rv}" != 0 ]
   then
-    do_error_push "'make ${@}' exited with '${make_rv}'"
+    do_error_push "'gmake ${@}' exited with '${make_rv}'"
   fi
 }
 
