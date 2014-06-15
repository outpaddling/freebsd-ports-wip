--- setup.py.orig	2013-12-11 20:53:03.000000000 -0600
+++ setup.py	2014-06-15 15:08:37.000000000 -0500
@@ -121,7 +121,7 @@
     chdir(denoiser_dir)
 
     # as suggested by the docs in FastTree.c
-    call(['gcc', '-Wall', '-O3', '-finline-functions', '-funroll-loops', '-o',
+    call(['cc', '-Wall', '-O3', '-finline-functions', '-funroll-loops', '-o',
         'FastTree', 'FastTree.c', '-lm'])
 
     # remove the source
@@ -136,7 +136,10 @@
         URL = 'http://www.drive5.com/uclust/uclustq1.2.22_i86darwin64'
     elif platform == 'linux2':
         URL = 'http://www.drive5.com/uclust/uclustq1.2.22_i86linux64'
+    elif re.search('freebsd[0-9]+', platform):
+        URL = 'http://www.drive5.com/uclust/uclustq1.2.22_i86linux32'
     else:
+        print platform
         raise SystemError, ("Platform not supported by UCLUST")
 
     return_value = download_file(URL, 'scripts/', 'uclust')
@@ -150,7 +153,7 @@
     """Check if a binary is available and on the user Path
 
     Inputs:
-    app_name: Name of the binary, i. e. 'ls', 'gcc' etc.
+    app_name: Name of the binary, i. e. 'ls', 'cc' etc.
 
     Output:
     False if the binary is not found, True if the binary is found
@@ -175,7 +178,7 @@
     else:
         print "GHC not installed, so cannot build the Denoiser binary."
 
-    if app_available('gcc'):
+    if app_available('cc'):
         build_FastTree()
     else:
         print "GCC not installed, so cannot build FastTree"
@@ -245,7 +248,7 @@
                     'qiime_test_data':qiime_test_data_files},
       license=__license__,
       keywords=['bioinformatics', 'microbiome', 'microbiology', 'qiime'],
-      platforms=['MacOS', 'Linux'],
+      platforms=['MacOS', 'Linux', 'FreeBSD'],
       install_requires=['numpy >= 1.5.1, <= 1.7.1',
                         'matplotlib >= 1.1.0, <= 1.3.1', 'cogent == 1.5.3',
                         'pynast == 1.2.2', 'qcli', 'gdata',
