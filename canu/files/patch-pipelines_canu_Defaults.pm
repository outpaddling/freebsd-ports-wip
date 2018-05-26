--- pipelines/canu/Defaults.pm.orig	2018-02-27 13:46:07 UTC
+++ pipelines/canu/Defaults.pm
@@ -637,6 +637,9 @@ sub setExecDefaults ($$) {
     my $tag         = shift @_;
     my $name        = shift @_;
 
+    $global{"slurmArrayJobLimit"}  = undef;
+    $synops{"slurmArrayJobLimit"}  = "Max jobs that can run at once";
+
     $global{"gridOptions${tag}"}   = undef;
     $synops{"gridOptions${tag}"}   = "Grid engine options applied to $name jobs";
 
