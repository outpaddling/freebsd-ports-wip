--- munge_sumstats.py.orig	2018-05-04 19:53:59 UTC
+++ munge_sumstats.py
@@ -1,5 +1,7 @@
 #!/usr/local/bin/python2.7
 from __future__ import division
+import sys
+sys.path.append("/usr/local/libexec/ldsc")
 import pandas as pd
 import numpy as np
 import os
