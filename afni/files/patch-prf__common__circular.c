--- prf_common_circular.c.orig	2019-05-12 13:42:53 UTC
+++ prf_common_circular.c
@@ -318,8 +318,10 @@ static int show_malloc_stats(char * mesg)
 
    if( show_stats ) {
       fprintf(stderr,"\n----- malloc stats: %s\n", mesg);
-#ifndef DARWIN
+#ifdef __linux__
       malloc_stats();
+#else
+      fprintf(stderr, "No malloc_stats() on this platform.\n");
 #endif
    }
 
