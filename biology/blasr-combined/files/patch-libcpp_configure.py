--- libcpp/configure.py.orig	2015-08-15 09:22:58.000000000 -0500
+++ libcpp/configure.py	2015-08-17 12:55:22.000000000 -0500
@@ -91,7 +91,7 @@
 """%(dict(thisdir=thisdir))
 
 def get_OS_STRING():
-    G_BUILDOS_CMD = """bash -c 'set -e; set -o pipefail; id=$(lsb_release -si | tr "[:upper:]" "[:lower:]"); rel=$(lsb_release -sr); case $id in ubuntu) printf "$id-%04d\n" ${rel/./};; centos) echo "$id-${rel%%.*}";; *) echo "$id-$rel";; esac' 2>/dev/null"""
+    G_BUILDOS_CMD = """printf `uname`-`uname -r | cut -d - -f 1`'\n'"""
     return shell(G_BUILDOS_CMD)
 def get_PREBUILT():
     cmd = 'cd ../../../../prebuilt.out 2>/dev/null && pwd || echo -n notfound'
