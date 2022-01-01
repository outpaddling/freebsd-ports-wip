--- multiqc/multiqc.py.orig	2021-07-05 07:13:52 UTC
+++ multiqc/multiqc.py
@@ -11,17 +11,26 @@ from __future__ import print_function
 
 import base64
 import click
+import os
+import sys
+
+if 'LC_ALL' in os.environ and 'LANG' in os.environ:
+    import click
+else:
+    print('multiqc: LC_ALL and LANG must be set to a UTF-8 character set')
+    print('in your environment in order for the click module to function.')
+    print('E.g. export LC_ALL=en_US.UTF-8 or setenv LC_ALL en_US.UTF-8')
+    sys.exit()
+
 from distutils import version
 from distutils.dir_util import copy_tree
 import errno
 import io
 import jinja2
-import os
 import re
 import rich
 import shutil
 import subprocess
-import sys
 import tempfile
 import time
 import traceback
