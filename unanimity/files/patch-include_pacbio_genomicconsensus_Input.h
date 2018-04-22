--- include/pacbio/genomicconsensus/Input.h.orig	2018-04-22 00:16:06 UTC
+++ include/pacbio/genomicconsensus/Input.h
@@ -25,7 +25,8 @@ namespace GenomicConsensus {
 class Input
 {
 public:
-    explicit Input(const Settings& settings) : settings_{settings} {}
+    //explicit Input(const Settings& settings) : settings_{settings} {}
+    explicit Input(const Settings& settings) { settings_ = settings; }
 
     Input() = delete;
     Input(const Input&) = delete;
