--- setup.py.orig	2015-07-15 08:52:20.000000000 -0500
+++ setup.py	2017-02-17 11:34:47.515956000 -0600
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
