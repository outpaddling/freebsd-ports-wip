--- setup.py.orig	2016-05-26 08:55:22.000000000 -0500
+++ setup.py	2017-02-24 13:38:44.023975000 -0600
@@ -11,8 +11,8 @@ def parcel_build(command_subclass):
 
     def parcel_run(self):
         try:
-            call(['make', 'clean'])
-            check_call(['make'])
+            # call(['gmake', 'clean'])
+            check_call(['gmake'])
         except Exception as e:
             logging.error(
                 "Unable to build UDT library: {}".format(e))
@@ -60,12 +60,12 @@ setup(
         'develop': ParcelDevelop,
     },
     install_requires=[
-        'requests==2.5.1',
-        'progressbar==2.3',
-        'Flask==0.10.1',
-        'intervaltree==2.0.4',
-        'termcolor==1.1.0',
-        'cmd2==0.6.8',
+        'requests>=2.5.1',
+        'progressbar>=2.3',
+        'Flask>=0.10.1',
+        'intervaltree>=2.0.4',
+        'termcolor>=1.1.0',
+        'cmd2>=0.6.8',
     ],
     package_data={
         "parcel": [
