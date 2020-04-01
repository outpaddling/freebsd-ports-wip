--- setup.py.orig	2020-04-01 00:20:56 UTC
+++ setup.py
@@ -25,7 +25,7 @@ setup(
     install_requires=[
         "globus-sdk==1.9.0",
         "click>=7.1.1,<8.0",
-        "jmespath==0.9.4",
+        "jmespath>=0.9.4",
         "configobj>=5.0.6,<6.0.0",
         "requests>=2.0.0,<3.0.0",
         "six>=1.10.0,<2.0.0",
