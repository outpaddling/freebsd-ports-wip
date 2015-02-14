--- fastq-mcf.cpp.orig	2014-09-04 10:44:33.000000000 -0500
+++ fastq-mcf.cpp	2015-02-14 10:41:19.000000000 -0600
@@ -265,7 +265,7 @@
     meminit(phred_adjust);
 
     int option_index = 0;
-    while (	(c = getopt_long(argc, argv, "-nf0uXUVHKSRdbehp:o:O:l:s:m:t:k:x:P:q:L:C:w:F:D:",long_options,&option_index)) != -1) {
+    while ( ((c = getopt_long(argc, argv, "nf0uXUVHKSRdbehp:o:O:l:s:m:t:k:x:P:q:L:C:w:F:D:",long_options,&option_index)) != -1) || (optind < argc) ) {
 		switch (c) {
 			case '\0':
                 { 
@@ -338,7 +338,7 @@
                     }
                     break;
                 }
-			case '\1': 
+			case -1: 
 				if (!afil) 
 					afil = optarg; 
 				else if (i_n<MAX_FILES) 
@@ -370,7 +370,7 @@
 			case 'P': phred = (char) atoi(optarg); break;
 			case 'D': duplen = atoi(optarg); break;
 			case 'h': usage(stdout); return 1; 
-			case 'o': if (!o_n < MAX_FILES) 
+			case 'o': if (!(o_n < MAX_FILES)) 
 						  ofil[o_n++] = optarg;
 					  break;
                		case 'O': nreadsout = atoi(optarg); break;
@@ -685,7 +685,7 @@
 				for(a=0;a<acnt;++a) {
 					char *p;
 					// search whole seq for 15 char "end" of adap string
-					if (p = strstr(s+1, ad[a].escan)) { 
+					if ( (p = strstr(s+1, ad[a].escan)) != NULL ) { 
 						if (debug > 1) fprintf(stderr, "  END S: %s A: %s (%s), P: %d, SL: %d, Z:%d\n", s, ad[a].id, ad[a].escan, (int) (p-s), ns, (p-s) == ns-SCANLEN);
                         // found at the very end
 						if ((p-s) == ns-SCANLEN) 
@@ -838,12 +838,12 @@
 				}
 
                 char *p;
-                if (p=strstr(ad[a].id, "_3p")) {
+                if ( (p=strstr(ad[a].id, "_3p")) != NULL ) {
                     if (p[3] == '\0' || p[3] == '_') {
                         ad[a].end[i]='e'; 
 					    cnt = ad[a].ecnt[i];
                     }
-                } else if (p=strstr(ad[a].id, "_5p")) {
+                } else if ( (p=strstr(ad[a].id, "_5p")) != NULL ) {
                     if (p[3] == '\0' || p[3] == '_') {
                         ad[a].end[i]='b';
                         cnt = ad[a].bcnt[i];
@@ -961,7 +961,7 @@
     google::sparse_hash_map <std::string, int>::const_iterator lookup_it;
 
     bool io_ok = true;
-    while (read_ok=fin[0].read_fq(nrec, &fq[0])) {
+    while ( (read_ok=fin[0].read_fq(nrec, &fq[0])) != 0 ) {
                 if (nreadsout && (wrec == nreadsout)) break;
 		for (i=1;i<i_n;++i) {
 			int mok=fin[1].read_fq(nrec, &fq[i]);
@@ -1686,7 +1686,7 @@
 }
 
 bool  arg_int_pair(const char *optarg, int &a, int&b) {
-    if (!strchr(optarg, ',')) {
+    if ( strchr(optarg, ',') == NULL ) {
         return false;
     }
     a=atoi(optarg);
