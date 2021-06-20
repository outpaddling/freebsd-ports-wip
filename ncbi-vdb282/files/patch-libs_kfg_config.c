--- libs/kfg/config.c.orig	2017-07-14 21:55:36 UTC
+++ libs/kfg/config.c
@@ -2558,7 +2558,7 @@ bool load_from_std_location ( KConfig *s
     const char * std_locs [] =
     {
 #if ! WINDOWS
-        "/etc/ncbi",
+        @@PREFIX@@ "/etc/ncbi",
 #else
         "/c/ncbi",
 #endif
@@ -2816,6 +2816,8 @@ void add_predefined_nodes ( KConfig * se
     #define OS "win"
 #elif SUN
     #define OS "sun"
+#elif BSD
+    #define OS "bsd"
 #else
     #error unrecognized OS
 #endif
