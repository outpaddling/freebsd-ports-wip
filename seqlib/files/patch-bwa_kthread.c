--- bwa/kthread.c.orig	2018-03-23 15:38:01 UTC
+++ bwa/kthread.c
@@ -1,6 +1,7 @@
 #include <pthread.h>
 #include <stdlib.h>
 #include <limits.h>
+#include <inttypes.h>
 
 /************
  * kt_for() *
