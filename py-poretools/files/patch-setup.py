--- setup.py.orig	2021-08-06 00:20:31 UTC
+++ setup.py
@@ -3,7 +3,7 @@ from setuptools import setup
 
 version_py = os.path.join(os.path.dirname(__file__), 'poretools', 'version.py')
 version = open(version_py).read().strip().split('=')[-1].replace('"','').strip()
-print version
+print(version)
 long_description = """
 ``poretools`` is a toolset for working with nanopore sequencing data'
 """
