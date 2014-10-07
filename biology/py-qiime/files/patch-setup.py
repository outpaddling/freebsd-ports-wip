--- setup.py.orig	2014-10-07 13:35:43.000000000 -0500
+++ setup.py	2014-10-07 13:38:33.000000000 -0500
@@ -175,13 +175,13 @@
     else:
         print "GHC not installed, so cannot build the Denoiser binary."
 
-    if app_available('gcc'):
-        build_FastTree()
-    else:
-        print "GCC not installed, so cannot build FastTree"
+#    if app_available('gcc'):
+#        build_FastTree()
+#    else:
+#        print "GCC not installed, so cannot build FastTree"
 
-    if download_UCLUST():
-        print "UCLUST could not be installed."
+#    if download_UCLUST():
+#        print "UCLUST could not be installed."
 
 # taken from PyNAST
 classes = """
