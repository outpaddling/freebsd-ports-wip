--- pipelines/canu/Defaults.pm.orig	2018-02-27 13:46:07 UTC
+++ pipelines/canu/Defaults.pm
@@ -637,6 +637,12 @@ sub setExecDefaults ($$) {
     my $tag         = shift @_;
     my $name        = shift @_;
 
+    $global{"slurmCormhapTaskLimit"}  = undef;
+    $synops{"slurmCormhapTaskLimit"}  = "Max corhmap tasks that can run at once";
+
+    $global{"slurmArrayTaskLimit"}  = undef;
+    $synops{"slurmArrayTaskLimit"}  = "Max tasks that can run at once";
+
     $global{"gridOptions${tag}"}   = undef;
     $synops{"gridOptions${tag}"}   = "Grid engine options applied to $name jobs";
 
