--- src/py/mains/run.py.orig	2015-08-17 22:40:24.000000000 -0500
+++ src/py/mains/run.py	2015-08-26 17:53:21.000000000 -0500
@@ -41,6 +41,7 @@
         content = ifs.read()
     content = prepend_env_paths(content, names)
     with open(fn, 'w') as ofs:
+        ofs.write('#!/usr/bin/env bash\n\n')
         ofs.write(content)
 
 def run_script(job_data, job_type = "SGE" ):
