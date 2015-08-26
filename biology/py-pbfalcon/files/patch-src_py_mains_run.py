--- src/py/mains/run.py.orig	2015-08-17 22:40:24.000000000 -0500
+++ src/py/mains/run.py	2015-08-26 17:44:16.000000000 -0500
@@ -49,6 +49,9 @@
     We will have a better solution eventually.
     """
     script_fn = job_data["script_fn"]
+    f = open(script_fn, 'w')
+    f.write("#!/usr/bin/env bash\n\n")
+    f.close()
     update_env_in_script(script_fn,
         ['PATH', 'PYTHONPATH', 'LD_LIBRARY_PATH'])
     if job_type == "SGE":
