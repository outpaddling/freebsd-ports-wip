--- src/py/mains/run.py.orig	2015-08-26 17:32:02.000000000 -0500
+++ src/py/mains/run.py	2015-08-26 17:34:55.000000000 -0500
@@ -49,6 +49,8 @@
     We will have a better solution eventually.
     """
     script_fn = job_data["script_fn"]
+    with open(script_fn, 'w') as ofs:
+        ofs.write("#!/usr/bin/env bash\n\n")
     update_env_in_script(script_fn,
         ['PATH', 'PYTHONPATH', 'LD_LIBRARY_PATH'])
     if job_type == "SGE":
