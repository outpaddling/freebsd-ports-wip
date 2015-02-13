--- fastq-join.cpp.orig	2015-02-13 11:02:32.000000000 -0600
+++ fastq-join.cpp	2015-02-13 11:03:17.000000000 -0600
@@ -125,7 +125,7 @@
 			out[i]=(char *)malloc(strlen(pre)+10);
 			strcpy(out[i], pre);
 			char *p;
-			if (p=strchr(out[i], '%')) {
+			if ( (p=strchr(out[i], '%')) != NULL ) {
 				// substiture instead of append
 				strcpy(p, suffix[i]);
 				strcpy(p+strlen(suffix[i]), pre+(p-out[i])+1);
@@ -180,7 +180,7 @@
 	meminit(rc);
 
 	// read in 1 record from each file
-	while (read_ok=read_fq(fin[0], nrec, &fq[0])) {
+	while ( (read_ok=read_fq(fin[0], nrec, &fq[0])) != 0 ) {
 		for (i=1;i<in_n;++i) {
 		int mate_ok=read_fq(fin[i], nrec, &fq[i]);
 		if (read_ok != mate_ok) {
