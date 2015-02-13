--- fastq-multx.cpp.orig	2014-09-04 10:44:33.000000000 -0500
+++ fastq-multx.cpp	2015-02-13 11:02:00.000000000 -0600
@@ -257,7 +257,7 @@
             if (!strcmp(bcg[bgcnt].b.seq.s,"seq")) continue;
 
             // dual indexed indicated by a dash in the sequence...
-			if (bcg[bgcnt].b.dual=strchr(bcg[bgcnt].b.seq.s,'-')) {
+			if ( (bcg[bgcnt].b.dual=strchr(bcg[bgcnt].b.seq.s,'-')) != NULL ) {
 				*bcg[bgcnt].b.dual = '\0';
 				++bcg[bgcnt].b.dual;
 				bcg[bgcnt].b.dual_n = strlen(bcg[bgcnt].b.dual);
@@ -662,7 +662,7 @@
 				fprintf(stderr, "Barcode file '%s' required format is 'ID SEQ'\n",bfil);
 				return 1;
 			}
-            if (bc[bcnt].dual=strchr(bc[bcnt].seq.s,'-')) {
+            if ( (bc[bcnt].dual=strchr(bc[bcnt].seq.s,'-')) != NULL ) {
                 *bc[bcnt].dual = '\0';
                 ++bc[bcnt].dual;
 				bc[bcnt].dual_n = strlen(bc[bcnt].dual);
@@ -713,7 +713,7 @@
 
         struct fq fq[2]; meminit(fq);
 
-        while (read_ok=read_fq(fin[0], nr, &fq[0])) {
+        while ( (read_ok=read_fq(fin[0], nr, &fq[0])) != 0 ) {
             fq[0].id.s[--fq[0].id.n]='\0';
 
             if (dual)
@@ -848,7 +848,7 @@
 
     // ACTUAL DEMUX HAPPENS HERE
 	// read in 1 record from EACH file supplied
-	while (read_ok=read_fq(fin[0], nrec, &fq[0])) {
+	while ( (read_ok=read_fq(fin[0], nrec, &fq[0])) != 0 ) {
 		for (i=1;i<f_n;++i) {
 			int mate_ok=read_fq(fin[i], nrec, &fq[i]);
 			if (read_ok != mate_ok) {
@@ -1186,7 +1186,7 @@
     }
 
     char *t;
-    while(t=strchr(p,':')) {
+    while( (t=strchr(p,':')) != NULL ) {
         p=t+1;
     }
 
@@ -1210,7 +1210,7 @@
         (*q)[*ns]='\0';
     }
 
-    if (p=strchr(s,'+')) {
+    if ( (p=strchr(s,'+')) != NULL ) {
         *p='\0';
         *ns = p-s;
 
