--- setup.py.orig	2015-01-20 19:53:18 UTC
+++ setup.py
@@ -2,7 +2,7 @@ import os
 import uuid
 import glob
 from setuptools import setup, find_packages
-from pip.req import parse_requirements
+# from pip.req import parse_requirements
 
 
 if os.environ.get('USER','') == 'vagrant':
@@ -10,8 +10,8 @@ if os.environ.get('USER','') == 'vagrant':
 
 os.chdir(os.path.normpath(os.path.join(os.path.abspath(__file__), os.pardir)))
 
-install_reqs = parse_requirements('requirements.txt', session=uuid.uuid1())
-reqs = [str(ir.req) for ir in install_reqs]
+# install_reqs = parse_requirements('requirements.txt', session=uuid.uuid1())
+# reqs = [str(ir.req) for ir in install_reqs]
 
 setup(
     name = "oligotyping",
@@ -41,5 +41,5 @@ setup(
     include_package_data = True,
     package_data={'': ['Oligotyping/utils/html/scripts/*', 'Oligotyping/utils/html/static/*', 'Oligotyping/utils/html/templates/*']},
 
-    install_requires=reqs,
+    # install_requires=reqs,
 )
