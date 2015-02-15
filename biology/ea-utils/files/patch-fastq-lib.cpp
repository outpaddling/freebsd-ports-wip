--- fastq-lib.cpp.orig	2014-09-04 10:44:33.000000000 -0500
+++ fastq-lib.cpp	2015-02-15 10:46:25.000000000 -0600
@@ -160,7 +160,11 @@
         if (!strcmp(ext,".gz")) {
             char *tmp=(char *)malloc(strlen(f)+100);
             if (strchr(m,'w')) {
-                    strcpy(tmp, "gzip -3 --rsyncable > '");
+		    /*
+		     * --rsyncable seems to have been removed from recent
+		     * versions of gzip.
+		     */
+                    strcpy(tmp, "gzip -3 > '");
                     strcat(tmp, f);
                     strcat(tmp, "'");
             } else {
