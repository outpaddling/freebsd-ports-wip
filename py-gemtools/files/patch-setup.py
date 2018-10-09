--- setup.py.orig	2013-11-18 12:33:07 UTC
+++ setup.py
@@ -1,5 +1,5 @@
-from distribute_setup import use_setuptools
-use_setuptools()
+# from distribute_setup import use_setuptools
+# use_setuptools()
 
 #
 # make sur ewe use gcc on mac os x
@@ -236,7 +236,7 @@ class install(_install):
 
 
 def compile_gemtools():
-        process = subprocess.Popen(['make'], shell=True, cwd='GEMTools')
+        process = subprocess.Popen(['gmake'], shell=True, cwd='GEMTools')
         if process.wait() != 0:
             print >> sys.stderr, """
 
