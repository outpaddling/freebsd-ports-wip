--- setup.py.orig	2017-02-15 11:02:38.421681000 -0600
+++ setup.py	2017-02-15 11:02:45.861042000 -0600
@@ -11,8 +11,8 @@ def parcel_build(command_subclass):
 
     def parcel_run(self):
         try:
-            call(['make', 'clean'])
-            check_call(['make'])
+            call(['gmake', 'clean'])
+            check_call(['gmake'])
         except Exception as e:
             logging.error(
                 "Unable to build UDT library: {}".format(e))
