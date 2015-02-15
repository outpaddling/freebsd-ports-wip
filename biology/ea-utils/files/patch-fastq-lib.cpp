--- fastq-lib.cpp.orig	2015-02-14 10:58:47.000000000 -0600
+++ fastq-lib.cpp	2015-02-14 10:59:01.000000000 -0600
@@ -160,7 +160,7 @@
         if (!strcmp(ext,".gz")) {
             char *tmp=(char *)malloc(strlen(f)+100);
             if (strchr(m,'w')) {
-                    strcpy(tmp, "gzip -3 --rsyncable > '");
+                    strcpy(tmp, "gzip -3 > '");
                     strcat(tmp, f);
                     strcat(tmp, "'");
             } else {
