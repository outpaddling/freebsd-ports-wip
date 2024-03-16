--- multiqc/multiqc.py.orig	2024-02-28 13:56:02 UTC
+++ multiqc/multiqc.py
@@ -24,7 +24,13 @@ import traceback
 import jinja2
 import requests
 import rich
-import rich_click as click
+if 'LC_ALL' in os.environ and 'LANG' in os.environ:
+    import rich_click as click
+else:
+    print('multiqc: LC_ALL and LANG must be set to a UTF-8 character set')
+    print('in your environment in order for the click module to function.')
+    print('E.g. export LC_ALL=en_US.UTF-8 or setenv LC_ALL en_US.UTF-8')
+    sys.exit()
 from packaging import version
 from rich.syntax import Syntax
 
