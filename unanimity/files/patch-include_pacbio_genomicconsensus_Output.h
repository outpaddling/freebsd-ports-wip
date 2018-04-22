--- include/pacbio/genomicconsensus/Output.h.orig	2018-04-22 00:24:05 UTC
+++ include/pacbio/genomicconsensus/Output.h
@@ -80,8 +80,10 @@ inline void PrintVcfLite(const Variant& 
         << "\tPASS\n";
 }
 
-inline Output::Output(const Settings& settings) : settings_{settings}
+// inline Output::Output(const Settings& settings) : settings_{settings}
+inline Output::Output(const Settings& settings)
 {
+    settings_ = settings;
     // initialize maps
     PacBio::BAM::FastaSequenceQuery fasta{settings_.referenceFilename};
     for (const auto& seq : fasta) {
