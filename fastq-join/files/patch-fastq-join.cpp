--- fastq-join.cpp.orig	2015-12-15 23:32:25 UTC
+++ fastq-join.cpp
@@ -126,7 +126,7 @@ int main (int argc, char **argv) {
 			out[i]=(char *)malloc(strlen(pre)+10);
 			strcpy(out[i], pre);
 			char *p;
-			if (p=strchr(out[i], '%')) {
+			if ((p=strchr(out[i], '%'))) {
 				// substiture instead of append
 				strcpy(p, suffix[i]);
 				strcpy(p+strlen(suffix[i]), pre+(p-out[i])+1);
@@ -181,7 +181,7 @@ int main (int argc, char **argv) {
 	meminit(rc);
 
 	// read in 1 record from each file
-	while (read_ok=read_fq(fin[0], nrec, &fq[0])) {
+	while ((read_ok=read_fq(fin[0], nrec, &fq[0]))) {
 		for (i=1;i<in_n;++i) {
 		int mate_ok=read_fq(fin[i], nrec, &fq[i]);
 		if (read_ok != mate_ok) {
@@ -401,7 +401,7 @@ int main (int argc, char **argv) {
 
 void usage(FILE *f) {
 	fprintf(f,
-"Usage: fastq-join [options] <read1.fq> <read2.fq> [mate.fq] -o <read.%.fq>\n"
+"Usage: fastq-join [options] <read1.fq> <read2.fq> [mate.fq] -o <read.%%.fq>\n"
 "Version: %s.%d\n"
 "\n"
 "Joins two paired-end reads on the overlapping ends.\n"
