--- fastq-multx.cpp.orig	2014-09-04 10:44:33.000000000 -0500
+++ fastq-multx.cpp	2015-02-15 10:59:34.000000000 -0600
@@ -100,7 +100,7 @@
 
 
 int main (int argc, char **argv) {
-	char c;
+	int c;
 	bool trim = true;
 	int mismatch = 1;
 	int distance = 2;
@@ -126,8 +126,24 @@
 	int i;
 	bool omode = false;	
 	char *bfil = NULL;
-	while (	(c = getopt (argc, argv, "-DzxnHhbeov:m:B:g:L:l:G:q:d:t:")) != -1) {
+
+        /*
+         * The leading '-' in optstr for processing non-option args as
+         * option 1 is a GNU extension and doesn't work on BSD, OS X, etc.
+         * A simple alternative in many cases is to replace case 1 with
+         * case -1 and continue the loop until optind == argc after
+         * getopt returns -1.  The global optarg is not set in this
+         * case, but we can access the argument as argv[optind++] instead.
+	 * In this case, I altered the specific cases instead, since all
+	 * the non-option arguments should be bound to option arguments.
+         */
+
+	while (	(c = getopt (argc, argv, "-DzxnHhbeo:v:m:B:g:L:l:G:q:d:t:")) != -1) {
 		switch (c) t:{
+		/* 
+		 * FIXME: This code is obsoleted by code inserted
+		 * under 'l' and 'o' below, which does not rely on
+		 * GNU extensions.
 		case '\1': 
                        	if (omode) {
 				if (f_oarg<5)
@@ -143,7 +159,18 @@
 				usage(stderr); return 1;
 			}
 			break;
-                case 'o': omode=true; break;
+		*/
+                case 'o':
+			omode=true;
+			out[f_oarg++] = optarg;
+			// Is it acceptable to have multiple filenames
+			// after one -o?
+			while ( (f_oarg < 5 ) && (optind < argc) 
+				&& (argv[optind][0] != '-') )
+			{
+				out[f_oarg++] = argv[optind++];
+			}
+			break;
                 case 'v': 
 			if (strlen(optarg)>1) {
 				fprintf(stderr, "Option -v requires a single character argument");
@@ -160,7 +187,12 @@
 			in[f_n++] = optarg;
 			out[f_oarg++] = "n/a";
 			break;
-		case 'l': list = optarg; usefile1=0; break;
+		case 'l':
+			list = optarg;
+			usefile1=0;
+			while ( (f_n < 5 ) && argv[optind][0] != '-' )
+				in[f_n++] = argv[optind++];
+			break;
 		case 'L': list = optarg; usefile1=1; break;
 		case 'B': bfil = optarg; list = NULL; break;
 		case 'x': trim = false; break;
@@ -257,7 +289,7 @@
             if (!strcmp(bcg[bgcnt].b.seq.s,"seq")) continue;
 
             // dual indexed indicated by a dash in the sequence...
-			if (bcg[bgcnt].b.dual=strchr(bcg[bgcnt].b.seq.s,'-')) {
+			if ( (bcg[bgcnt].b.dual=strchr(bcg[bgcnt].b.seq.s,'-')) != NULL ) {
 				*bcg[bgcnt].b.dual = '\0';
 				++bcg[bgcnt].b.dual;
 				bcg[bgcnt].b.dual_n = strlen(bcg[bgcnt].b.dual);
@@ -662,7 +694,7 @@
 				fprintf(stderr, "Barcode file '%s' required format is 'ID SEQ'\n",bfil);
 				return 1;
 			}
-            if (bc[bcnt].dual=strchr(bc[bcnt].seq.s,'-')) {
+	    if ( (bc[bcnt].dual=strchr(bc[bcnt].seq.s,'-')) != NULL ) {
                 *bc[bcnt].dual = '\0';
                 ++bc[bcnt].dual;
 				bc[bcnt].dual_n = strlen(bc[bcnt].dual);
@@ -713,7 +745,7 @@
 
         struct fq fq[2]; meminit(fq);
 
-        while (read_ok=read_fq(fin[0], nr, &fq[0])) {
+	while ( (read_ok=read_fq(fin[0], nr, &fq[0])) != 0 ) {
             fq[0].id.s[--fq[0].id.n]='\0';
 
             if (dual)
@@ -848,7 +880,7 @@
 
     // ACTUAL DEMUX HAPPENS HERE
 	// read in 1 record from EACH file supplied
-	while (read_ok=read_fq(fin[0], nrec, &fq[0])) {
+	while ( (read_ok=read_fq(fin[0], nrec, &fq[0])) != 0 ) {
 		for (i=1;i<f_n;++i) {
 			int mate_ok=read_fq(fin[i], nrec, &fq[i]);
 			if (read_ok != mate_ok) {
@@ -1186,7 +1218,7 @@
     }
 
     char *t;
-    while(t=strchr(p,':')) {
+    while( (t=strchr(p,':')) != NULL ) {
         p=t+1;
     }
 
@@ -1210,7 +1242,7 @@
         (*q)[*ns]='\0';
     }
 
-    if (p=strchr(s,'+')) {
+    if ( (p=strchr(s,'+')) != NULL ) {
         *p='\0';
         *ns = p-s;
 
