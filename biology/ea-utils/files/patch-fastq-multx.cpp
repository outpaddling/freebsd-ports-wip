--- fastq-multx.cpp.orig	2014-09-04 10:44:33.000000000 -0500
+++ fastq-multx.cpp	2015-02-13 15:17:48.000000000 -0600
@@ -100,7 +100,7 @@
 
 
 int main (int argc, char **argv) {
-	char c;
+	int c;
 	bool trim = true;
 	int mismatch = 1;
 	int distance = 2;
@@ -127,12 +127,14 @@
 	bool omode = false;	
 	char *bfil = NULL;
 	while (	(c = getopt (argc, argv, "-DzxnHhbeov:m:B:g:L:l:G:q:d:t:")) != -1) {
+		printf("getopt returned %d (%c)\n", c, c);
 		switch (c) t:{
 		case '\1': 
                        	if (omode) {
 				if (f_oarg<5)
 					out[f_oarg++] = optarg;
 				else {
+					puts("f_oarg >= 5");
 					usage(stderr); return 1;
 				}
 			} else if (!bfil && !guide && !list) 
@@ -140,6 +142,7 @@
 			else if (f_n<5) {
 				in[f_n++] = optarg; 
 			} else {
+				puts("f_n >= 5");
 				usage(stderr); return 1;
 			}
 			break;
@@ -151,7 +154,7 @@
 			}
 			verify = *optarg; break;
 		case 'b': end = 'b'; break;
-		case 'h': usage(stdout); exit(0); break;
+		case 'h': puts("h"); usage(stdout); exit(0); break;
 		case 'H': bcinheader = 1; usefile1=1; break;
 		case 'e': end = 'e'; break;
 		case 'G': group = optarg; break;
@@ -184,6 +187,8 @@
 		}
 	}
 
+	printf("c = %d\n", c);
+
 	if (group && !list) {
 		fprintf(stderr, "Error: -G only works with -l\n");
 		return 1;
@@ -200,6 +205,8 @@
 	}
 
 	if (argc < 3 || !f_n || (!bfil && !guide && !list)) {
+		puts("if (argc < 3 || !f_n || (!bfil && !guide && !list))");
+		fprintf(stderr, "%d %d %d %d %d\n", argc, f_n, bfil, guide, list);
 		usage(stderr);
 		return 1;
 	}
@@ -257,7 +264,7 @@
             if (!strcmp(bcg[bgcnt].b.seq.s,"seq")) continue;
 
             // dual indexed indicated by a dash in the sequence...
-			if (bcg[bgcnt].b.dual=strchr(bcg[bgcnt].b.seq.s,'-')) {
+			if ( (bcg[bgcnt].b.dual=strchr(bcg[bgcnt].b.seq.s,'-')) != NULL ) {
 				*bcg[bgcnt].b.dual = '\0';
 				++bcg[bgcnt].b.dual;
 				bcg[bgcnt].b.dual_n = strlen(bcg[bgcnt].b.dual);
@@ -662,7 +669,7 @@
 				fprintf(stderr, "Barcode file '%s' required format is 'ID SEQ'\n",bfil);
 				return 1;
 			}
-            if (bc[bcnt].dual=strchr(bc[bcnt].seq.s,'-')) {
+            if ( (bc[bcnt].dual=strchr(bc[bcnt].seq.s,'-')) != NULL ) {
                 *bc[bcnt].dual = '\0';
                 ++bc[bcnt].dual;
 				bc[bcnt].dual_n = strlen(bc[bcnt].dual);
@@ -713,7 +720,7 @@
 
         struct fq fq[2]; meminit(fq);
 
-        while (read_ok=read_fq(fin[0], nr, &fq[0])) {
+        while ( (read_ok=read_fq(fin[0], nr, &fq[0])) != 0 ) {
             fq[0].id.s[--fq[0].id.n]='\0';
 
             if (dual)
@@ -848,7 +855,7 @@
 
     // ACTUAL DEMUX HAPPENS HERE
 	// read in 1 record from EACH file supplied
-	while (read_ok=read_fq(fin[0], nrec, &fq[0])) {
+	while ( (read_ok=read_fq(fin[0], nrec, &fq[0])) != 0 ) {
 		for (i=1;i<f_n;++i) {
 			int mate_ok=read_fq(fin[i], nrec, &fq[i]);
 			if (read_ok != mate_ok) {
@@ -1186,7 +1193,7 @@
     }
 
     char *t;
-    while(t=strchr(p,':')) {
+    while( (t=strchr(p,':')) != NULL ) {
         p=t+1;
     }
 
@@ -1210,7 +1217,7 @@
         (*q)[*ns]='\0';
     }
 
-    if (p=strchr(s,'+')) {
+    if ( (p=strchr(s,'+')) != NULL ) {
         *p='\0';
         *ns = p-s;
 
