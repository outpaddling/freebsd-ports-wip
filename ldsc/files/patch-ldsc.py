--- ldsc.py.orig	2018-05-04 19:40:22 UTC
+++ ldsc.py
@@ -9,6 +9,8 @@ LDSC is a command line tool for estimati
 
 '''
 from __future__ import division
+import sys
+sys.path.append("/usr/local/libexec/ldsc")
 import ldscore.ldscore as ld
 import ldscore.parse as ps
 import ldscore.sumstats as sumstats
