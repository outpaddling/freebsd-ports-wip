--- src/tops/utils/genSCLCCAmulti.sh.orig	2012-04-08 19:50:28.000000000 -0500
+++ src/tops/utils/genSCLCCAmulti.sh	2012-04-08 19:50:36.000000000 -0500
@@ -59,7 +59,7 @@
 #echo $scope
 #echo $resolution
 #exit 0
-if [ "$language" == python ] ; then
+if [ "$language" = python ] ; then
   pythonImplLine="<class name=\"$className\" desc=\"python/impl\" />"
 fi;  
 if test "x$mode" = "xscl"; then
@@ -76,7 +76,7 @@
 __EOF1
 for className in $classes; do
     echo "    <class name=\"$className\" desc=\"ior/impl\" />"
-    if [ "$language" == python ] ; then
+    if [ "$language" = python ] ; then
       echo "    <class name=\"$className\" desc=\"python/impl\" />"
     fi
 done
@@ -103,7 +103,7 @@
 __EOF3
 for className in $classes; do
     echo "    <class name=\"$className\" desc=\"ior/impl\" />"
-    if [ "$language" == python ] ; then
+    if [ "$language" = python ] ; then
       echo "    <class name=\"$className\" desc=\"python/impl\" />"
     fi
 done
