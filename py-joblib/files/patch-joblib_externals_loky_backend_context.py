--- joblib/externals/loky/backend/context.py.orig	2023-06-29 15:14:21 UTC
+++ joblib/externals/loky/backend/context.py
@@ -11,6 +11,7 @@
 #
 import os
 import sys
+import sysctl
 import math
 import subprocess
 import traceback
@@ -274,6 +275,9 @@ def _count_physical_cores():
             )
             cpu_info = cpu_info.stdout
             cpu_count_physical = int(cpu_info)
+        # Maybe also openbsd, dragonfly, etc?
+        elif sys.platform.startswith('freebsd'):
+            cpu_count_physical = int(sysctl.filter("kern.smp.cores")[0].value);
         else:
             raise NotImplementedError(f"unsupported platform: {sys.platform}")
 
