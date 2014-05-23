--- trinity-plugins/coreutils/build_parallel_sort.sh.orig	2014-04-23 10:59:35.000000000 -0500
+++ trinity-plugins/coreutils/build_parallel_sort.sh	2014-05-23 17:02:17.000000000 -0500
@@ -1,34 +1,34 @@
-#!/bin/bash
+#!/usr/local/bin/bash
 
-# Chrysalis wants sort in the trinity-plugins/coreutils/bin folder
+# Chrysalis wants gsort in the trinity-plugins/coreutils/bin folder
 # we have to deal with three possibilities
-# 1. sort of the system is recent enough
+# 1. gsort of the system is recent enough
 #    - just symlink it
-# 2. sort is to old
+# 2. gsort is to old
 #    - build it from coreutils
-# 3. sort is to old and building it fails
-#    - create a shellscript that will strip off the "--parallel" so that the old sort works 
+# 3. gsort is to old and building it fails
+#    - create a shellscript that will strip off the "--parallel" so that the old gsort works 
 
 #switch to the folder of this script
 DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
 cd $DIR
 
 # Version has to be at least 8.6 so feature "--parallel"
-VERSIONSTRING=(`sort --version | head -1`)
+VERSIONSTRING=(`gsort --version | head -1`)
 VERSION=${VERSIONSTRING[3]}
 MAJOR=${VERSION%.*}
 MINOR=${VERSION#*.}
 
-# cleanup old sort installation (if existing)
+# cleanup old gsort installation (if existing)
 rm -f ${DIR}/bin/sort
 
-# if system sort is recent enough, just symlink to it
+# if system gsort is recent enough, just symlink to it
 if [ $MAJOR -gt 8 -o $MAJOR -eq 8 -a $MINOR -ge 6 ]; then
-  echo "sort is recent enough, bailing out >&2 "
+  echo "gsort is recent enough, bailing out >&2 "
   mkdir -p ${DIR}/bin
   cd ${DIR}/bin
-  SORTPATH=`which sort`
-  ln -s ${SORTPATH}
+  SORTPATH=`which gsort`
+  ln -s ${SORTPATH} ${DIR}/bin/sort
   chmod +x ${DIR}/bin/sort
   exit 0
 fi 
