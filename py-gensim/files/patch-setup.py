--- setup.py.orig	2017-06-21 16:59:43 UTC
+++ setup.py
@@ -88,17 +88,17 @@ http://api.mongodb.org/python/current/in
     # the following is needed to be able to add numpy's include dirs... without
     # importing numpy directly in this script, before it's actually installed!
     # http://stackoverflow.com/questions/19919905/how-to-bootstrap-numpy-installation-in-setup-py
-    def finalize_options(self):
-            build_ext.finalize_options(self)
+    # def finalize_options(self):
+            # build_ext.finalize_options(self)
             # Prevent numpy from thinking it is still in its setup process:
             # https://docs.python.org/2/library/__builtin__.html#module-__builtin__
-            if isinstance(__builtins__, dict):
-                __builtins__["__NUMPY_SETUP__"] = False
-            else:
-                __builtins__.__NUMPY_SETUP__ = False
+            # if isinstance(__builtins__, dict):
+                # __builtins__["__NUMPY_SETUP__"] = False
+            # else:
+                # __builtins__.__NUMPY_SETUP__ = False
 
-            import numpy
-            self.include_dirs.append(numpy.get_include())
+            # import numpy
+            # self.include_dirs.append(numpy.get_include())
 
 
 
@@ -284,9 +284,9 @@ setup(
     ],
 
     test_suite="gensim.test",
-    setup_requires=[
-        'numpy >= 1.11.3'
-    ],
+    # setup_requires=[
+        # 'numpy >= 1.11.3'
+    # ],
     install_requires=[
         'numpy >= 1.11.3',
         'scipy >= 0.19.0',
