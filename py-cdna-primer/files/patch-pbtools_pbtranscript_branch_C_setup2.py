--- pbtools/pbtranscript/branch/C/setup2.py.orig	2015-08-13 21:46:35.000000000 -0500
+++ pbtools/pbtranscript/branch/C/setup2.py	2015-08-17 15:00:05.662700853 -0500
@@ -1,9 +1,10 @@
 from distutils.core import setup
 from distutils.extension import Extension
 from Cython.Distutils import build_ext
+import numpy
 
 ext_modules = [#Extension("BioReaders", ["BioReaders.pyx"]), \
-        Extension("c_branch", ["c_branch.pyx"]),\
+        Extension("c_branch", ["c_branch.pyx"],include_dirs=[numpy.get_include()]),\
         Extension("modified_bx_intervals.intersection_unique", ["modified_bx_intervals/intersection_unique.pyx"])]
 
 setup(
@@ -14,3 +15,4 @@
         author='Elizabeth Tseng'
 )
 
+
