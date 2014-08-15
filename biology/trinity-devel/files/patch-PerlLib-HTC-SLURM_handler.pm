--- PerlLib/HTC/SLURM_handler.pm.orig	2014-08-15 08:34:45.000000000 -0500
+++ PerlLib/HTC/SLURM_handler.pm	2014-08-15 08:35:47.000000000 -0500
@@ -42,10 +42,11 @@
     
     $cmd .= " $shell_script 2>&1 ";
         
+    print STDERR "\nExecuting $cmd\n";
 
     my $job_id_text = `$cmd`;
     
-    # print STDERR "\n$job_id_text\n";
+    print STDERR "\n$job_id_text\n";
     
     my $ret = $?;
     
@@ -82,7 +83,7 @@
         confess "Error, need job ID as parameter";
     }
     
-    # print STDERR "Polling grid to check status of job: $job_id\n";
+    print STDERR "Polling grid to check status of job: $job_id\n";
     
     my $response = `sacct -j $job_id`;
     #print STDERR "Response:\n$response\n";
