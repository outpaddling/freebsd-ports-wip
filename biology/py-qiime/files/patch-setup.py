--- setup.py.orig	2015-05-26 19:14:55 UTC
+++ setup.py
@@ -362,11 +362,11 @@ def build_swarm():
 # invoked
 if all([e not in sys.argv for e in 'egg_info', 'sdist', 'register']):
     catch_install_errors(build_denoiser, 'denoiser')
-    catch_install_errors(download_UCLUST, 'UCLUST')
-    catch_install_errors(build_FastTree, 'FastTree')
-    catch_install_errors(build_SortMeRNA, 'SortMeRNA')
-    catch_install_errors(build_SUMACLUST, 'SUMACLUST')
-    catch_install_errors(build_swarm, 'swarm')
+    # catch_install_errors(download_UCLUST, 'UCLUST')
+    # catch_install_errors(build_FastTree, 'FastTree')
+    # catch_install_errors(build_SortMeRNA, 'SortMeRNA')
+    # catch_install_errors(build_SUMACLUST, 'SUMACLUST')
+    # catch_install_errors(build_swarm, 'swarm')
 
 classes = """
     Development Status :: 5 - Production/Stable
