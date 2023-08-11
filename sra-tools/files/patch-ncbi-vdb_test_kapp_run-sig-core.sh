--- ncbi-vdb/test/kapp/run-sig-core.sh.orig	2023-08-11 13:37:24 UTC
+++ ncbi-vdb/test/kapp/run-sig-core.sh
@@ -27,6 +27,7 @@ BINARY_PATH="$1"
 HOST_OS="$2"
 BUILD_TYPE="$3"
 
+# FIXME: Is this necessary?  Why not just use kill -s QUIT or kill -QUIT?
 SIGQUIT=3
 
 function killFromBackground ()
@@ -34,7 +35,11 @@ function killFromBackground ()
     PARENT_PID=$1
     for I in 1 2 3 4 5
     do
-        COMMAND="ps -ef|awk '\$3==${PARENT_PID} && \$8==\"${BINARY_PATH}\"  {print \$2}'"
+        if [ "$HOST_OS" = "bsd" ]; then
+            COMMAND="ps awwo pid,ppid,command|awk '\$2==${PARENT_PID} && \$3==\"${BINARY_PATH}\"  {print \$1}'"
+        else
+            COMMAND="ps -ef|awk '\$3==${PARENT_PID} && \$8==\"${BINARY_PATH}\"  {print \$2}'"
+        fi
         eval PID=\`${COMMAND}\`
         if [ "$PID" = "" ]; then
             sleep 1
@@ -63,6 +68,13 @@ if [ "$HOST_OS" = "mac" ]; then
    fi
 
    CORE_FOLDER="/core/"
+elif [ "$HOST_OS" = "bsd" ]; then
+   if [ "`ulimit -c`" = "0" ] || [ "`/sbin/sysctl -n kern.coredump`" != "1" ]; then
+       echo "Core files are disabled. Skipping core file tests"
+       exit 0
+   fi
+
+   CORE_FOLDER="./"
 elif [ "$HOST_OS" = "linux" ]; then
    if [ "`ulimit -c`" = "0" ]; then
        echo "Core files are disabled. Skipping core file tests"
@@ -92,7 +104,11 @@ wait
 BINARY_PID=`cat killed.pid`
 rm killed.pid
 
-CORE_FILE="${CORE_FOLDER}core.${BINARY_PID}"
+if [ "$HOST_OS" = "bsd" ]; then
+    CORE_FILE="${CORE_FOLDER}${BINARY_PATH##*/}.core"
+else
+    CORE_FILE="${CORE_FOLDER}core.${BINARY_PID}"
+fi
 
 if [ "$BUILD_TYPE" = "dbg" ]; then
    if [ -f $CORE_FILE ]; then
