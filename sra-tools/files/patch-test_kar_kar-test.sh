--- test/kar/kar-test.sh.orig	2017-10-27 02:08:53 UTC
+++ test/kar/kar-test.sh
@@ -38,6 +38,10 @@ case $UNAME in
     (Linux)
         OS=linux
         ;;
+    (FreeBSD)
+        OS=bsd
+        MD5TOOL=/sbin/md5
+        ;;
     (Darwin)
         OS=mac
         MD5TOOL=/sbin/md5
@@ -129,7 +133,7 @@ test_create_options ()
                     exit 1
                 fi
                 ;;
-            (Darwin)
+            (Darwin|FreeBSD)
                 if [ ! -x $MD5TOOL ]
                 then
                     echo "could not locate executable md5 tool"
