--- falcon_kit/run_support.py.orig	2016-07-21 20:46:53.249074412 -0500
+++ falcon_kit/run_support.py	2016-07-21 20:47:34.697069657 -0500
@@ -35,6 +35,7 @@ def update_env_in_script(fn, names):
         content = ifs.read()
     content = _prepend_env_paths(content, names)
     with open(fn, 'w') as ofs:
+	ofs.write('#!/usr/bin/env bash\n\n')
         ofs.write(content)
 
 def use_tmpdir_for_files(basenames, src_dir, link_dir):
