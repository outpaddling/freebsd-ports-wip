--- etc/fslconf/fslmachtype.sh.orig	Tue Jul  3 07:23:09 2007
+++ etc/fslconf/fslmachtype.sh	Wed Aug 15 17:13:12 2007
@@ -11,7 +11,7 @@
 #### Identify machine ####
 machtype=""
 
-system_type=`uname -s`
+system_type=`/usr/bin/uname -s`
 case ${system_type} in
     SunOS)
 	AWK=nawk
@@ -27,11 +27,18 @@
 if [ $? -eq 0 ]; then
     # GCC is installed
     gcc_version=`echo $gcc_version | $AWK -F . '{ printf "%s.%s", $1,$2 }'`
-    gcc_host=`gcc -dumpmachine`
+    if [ `/usr/bin/uname` = FreeBSD ]; then
+        gcc_host=`/usr/bin/uname -m`-`/usr/bin/uname`
+    else
+        gcc_host=`gcc -dumpmachine`
+    fi
 
     gcc_cpu_type=`echo $gcc_host | $AWK -F - '{ printf "%s", $1; }'`
     gcc_os_vendor=`echo $gcc_host | $AWK -F - '{ printf "%s", $2; }'`
     gcc_os_name=`echo $gcc_host | $AWK -F - '{ printf "%s", $3; }'`
+    #echo $gcc_cpu_type
+    #echo $gcc_os_vendor
+    #echo $gcc_os_name
 
     case ${system_type} in
 	Darwin)
@@ -59,6 +66,9 @@
 	    ;;
 	SunOS)
 	    gcc_host="${gcc_cpu_type}-${gcc_os_name}"
+	    ;;
+	FreeBSD)
+	    gcc_host="${gcc_cpu_type}-${gcc_os_vendor}"
 	    ;;
 	*)
 	    gcc_host="${gcc_cpu_type}-${gcc_os_vendor}-${gcc_os_name}"
