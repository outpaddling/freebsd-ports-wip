--- fastq-clipper.cpp.orig	2014-09-04 10:44:33.000000000 -0500
+++ fastq-clipper.cpp	2015-02-14 09:25:21.000000000 -0600
@@ -54,13 +54,14 @@
 	int i;
 	
 	char *a = NULL, *f = NULL;
-	while (	(c = getopt (argc, argv, "-hedbp:i:o:l:m:x::")) != -1) {
+	while (	( (c = getopt (argc, argv, "hedbp:i:o:l:m:x::")) != -1) 
+		|| (optind < argc) ) {
 		switch (c) {
-		case '\1': 
+		case -1: 
 			if (!f) 
-				f=optarg; 
+				f=argv[optind++]; 
 			else if (!a) 
-				a=optarg; 
+				a=argv[optind++]; 
 			else {
 				usage(stderr); return 1;
 			}
@@ -115,7 +116,7 @@
 	int adapter_len[MAX_ADAPTER_NUM+1];
 	char *p;
 	int adapter_count=0;
-	while (p=strtok(a,":")) {
+	while ( (p=strtok(a,":")) != NULL ) {
 		a = NULL;					// strtok requirement
                 adapters[adapter_count] = p;
                 adapter_len[adapter_count] = strlen(p);         // append to list
