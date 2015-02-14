--- fastq-join.cpp.orig	2014-09-04 10:44:33.000000000 -0500
+++ fastq-join.cpp	2015-02-14 10:42:54.000000000 -0600
@@ -53,15 +53,17 @@
     bool norevcomp = false;
     bool allow_ex = false;
 
-	while (	(c = getopt (argc, argv, "-dRnbeo:t:v:m:p:r:xV")) != -1) {
+	while (	((c = getopt (argc, argv, "dRnbeo:t:v:m:p:r:xV")) != -1) 
+		|| (optind < argc) ) {
+		// fprintf(stderr, "%c %s\n", c, optarg);
 		switch (c) {
-		case '\1':
+		case -1:
 			if (!in[0]) 
-				in[0]=optarg;
+				in[0]=argv[optind++];
 			else if (!in[1])		
-				in[1]=optarg;
+				in[1]=argv[optind++];
 			else if (!in[2])		
-				in[2]=optarg;
+				in[2]=argv[optind++];
 			else {
 				usage(stderr); return 1;
 			}
@@ -87,6 +89,7 @@
                         }
                         verify = *optarg; break;
 		case '?': 
+		     puts(optarg);
 		     if (strchr("otvmpr", optopt))
 		       fprintf (stderr, "Option -%c requires an argument.\n", optopt);
 		     else if (isprint(optopt))
@@ -125,7 +128,7 @@
 			out[i]=(char *)malloc(strlen(pre)+10);
 			strcpy(out[i], pre);
 			char *p;
-			if (p=strchr(out[i], '%')) {
+			if ( (p=strchr(out[i], '%')) != NULL ) {
 				// substiture instead of append
 				strcpy(p, suffix[i]);
 				strcpy(p+strlen(suffix[i]), pre+(p-out[i])+1);
@@ -180,7 +183,7 @@
 	meminit(rc);
 
 	// read in 1 record from each file
-	while (read_ok=read_fq(fin[0], nrec, &fq[0])) {
+	while ( (read_ok=read_fq(fin[0], nrec, &fq[0])) != 0 ) {
 		for (i=1;i<in_n;++i) {
 		int mate_ok=read_fq(fin[i], nrec, &fq[i]);
 		if (read_ok != mate_ok) {
