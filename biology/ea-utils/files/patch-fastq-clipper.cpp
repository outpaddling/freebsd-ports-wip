--- fastq-clipper.cpp.orig	2015-02-13 11:10:07.000000000 -0600
+++ fastq-clipper.cpp	2015-02-13 11:10:27.000000000 -0600
@@ -115,7 +115,7 @@
 	int adapter_len[MAX_ADAPTER_NUM+1];
 	char *p;
 	int adapter_count=0;
-	while (p=strtok(a,":")) {
+	while ( (p=strtok(a,":")) != NULL ) {
 		a = NULL;					// strtok requirement
                 adapters[adapter_count] = p;
                 adapter_len[adapter_count] = strlen(p);         // append to list
