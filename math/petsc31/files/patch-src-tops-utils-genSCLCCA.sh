--- src/tops/utils/genSCLCCA.sh.orig	2012-04-08 19:50:11.000000000 -0500
+++ src/tops/utils/genSCLCCA.sh	2012-04-08 19:50:19.000000000 -0500
@@ -62,7 +62,7 @@
 #echo $scope
 #echo $resolution
 #exit 0
-if [ "$language" == python ] ; then
+if [ "$language" = python ] ; then
   pythonImplLine="<class name=\"$className\" desc=\"python/impl\" />"
 fi;  
 if test "x$mode" = "xscl"; then
@@ -79,7 +79,7 @@
 __EOF1
 for className in $classes; do
     echo "    <class name=\"$className\" desc=\"ior/impl\" />"
-    if [ "$language" == python ] ; then
+    if [ "$language" = python ] ; then
       echo "    <class name=\"$className\" desc=\"python/impl\" />"
     fi
 done
@@ -106,7 +106,7 @@
 __EOF3
 for className in $classes; do
     echo "    <class name=\"$className\" desc=\"ior/impl\" />"
-    if [ "$language" == python ] ; then
+    if [ "$language" = python ] ; then
       echo "    <class name=\"$className\" desc=\"python/impl\" />"
     fi
 done
