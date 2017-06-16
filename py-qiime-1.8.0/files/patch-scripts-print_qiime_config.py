--- scripts/print_qiime_config.py.orig	2014-10-09 10:38:26.000000000 -0500
+++ scripts/print_qiime_config.py	2014-10-09 10:40:02.000000000 -0500
@@ -262,7 +262,7 @@
 
     def test_python_supported_version(self):
         """python is in path and version is supported """
-        acceptable_version = (2,7,3)
+        acceptable_version = (2,7,8)
         command = 'python --version'
         proc = Popen(command,shell=True,universal_newlines=True, \
                          stdout=PIPE,stderr=STDOUT)
@@ -285,7 +285,7 @@
     def test_numpy_suported_version(self):
         """numpy version is supported """
         min_acceptable_version = (1,5,1)
-        max_acceptable_version = (1,7,1)
+        max_acceptable_version = (1,8,1)
         try:
             from numpy import __version__ as numpy_lib_version
             version = tuple(map(int,numpy_lib_version.split('.')))
@@ -304,7 +304,7 @@
     def test_matplotlib_suported_version(self):
         """matplotlib version is supported """
         min_acceptable_version = (1,1,0)
-        max_acceptable_version = (1,3,1)
+        max_acceptable_version = (1,4,0)
         try:
             from matplotlib import __version__ as matplotlib_lib_version
             version = tuple(map(int,matplotlib_lib_version.split('.')))
@@ -345,7 +345,7 @@
 
     def test_FastTree_supported_version(self):
         """FastTree is in path and version is supported """
-        acceptable_version = (2,1,3)
+        acceptable_version = (2,1,7)
         self.assertTrue(app_path('FastTree'),
          "FastTree not found. This may or may not be a problem depending on "+\
          "which components of QIIME you plan to use.")
