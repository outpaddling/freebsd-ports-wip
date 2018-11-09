--- setup.py.orig	2018-11-09 14:44:51 UTC
+++ setup.py
@@ -23,7 +23,7 @@ setup(
     install_requires=[
         'globus-sdk==1.6.1',
         'click>=6.6,<7.0',
-        'jmespath==0.9.2',
+        'jmespath>=0.9.2',
         'configobj>=5.0.6,<6.0.0',
         'requests>=2.0.0,<3.0.0',
         'six>=1.10.0,<2.0.0',
