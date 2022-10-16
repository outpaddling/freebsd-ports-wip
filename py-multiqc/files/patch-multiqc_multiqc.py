--- multiqc/multiqc.py.orig	2022-09-08 21:36:30 UTC
+++ multiqc/multiqc.py
@@ -18,10 +18,16 @@ import jinja2
 import os
 import re
 import rich
-import rich_click as click
+import sys
+if 'LC_ALL' in os.environ and 'LANG' in os.environ:
+    import rich_click as click
+else:
+    print('multiqc: LC_ALL and LANG must be set to a UTF-8 character set')
+    print('in your environment in order for the click module to function.')
+    print('E.g. export LC_ALL=en_US.UTF-8 or setenv LC_ALL en_US.UTF-8')
+    sys.exit()
 import shutil
 import subprocess
-import sys
 import tempfile
 import time
 import traceback
