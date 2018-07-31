--- pipelines/canu/Execution.pm.orig	2018-07-31 21:20:58 UTC
+++ pipelines/canu/Execution.pm
@@ -342,10 +342,6 @@ sub skipStage ($$@) {
 sub getInstallDirectory () {
     my $installDir = $FindBin::RealBin;
 
-    if ($installDir =~ m!^(.*)/\w+-\w+/bin$!) {
-        $installDir = $1;
-    }
-
     return($installDir);
 }
 
