--- PerlLib/HPC/SLURM_handler.pm.orig	2015-02-20 08:40:14.578718581 -0600
+++ PerlLib/HPC/SLURM_handler.pm	2015-02-20 08:40:14.648715555 -0600
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
