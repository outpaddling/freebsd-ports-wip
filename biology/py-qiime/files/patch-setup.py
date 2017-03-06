--- setup.py.orig	2015-05-26 14:14:55.000000000 -0500
+++ setup.py	2017-03-05 22:08:04.119386000 -0600
@@ -362,8 +362,8 @@ def build_swarm():
 # invoked
 if all([e not in sys.argv for e in 'egg_info', 'sdist', 'register']):
     catch_install_errors(build_denoiser, 'denoiser')
-    catch_install_errors(download_UCLUST, 'UCLUST')
-    catch_install_errors(build_FastTree, 'FastTree')
+    # catch_install_errors(download_UCLUST, 'UCLUST')
+    # catch_install_errors(build_FastTree, 'FastTree')
     catch_install_errors(build_SortMeRNA, 'SortMeRNA')
     catch_install_errors(build_SUMACLUST, 'SUMACLUST')
     catch_install_errors(build_swarm, 'swarm')
