--- src/tophat.py.orig	2014-06-24 13:58:01 UTC
+++ src/tophat.py
@@ -9,6 +9,9 @@ Copyright (c) 2008 Cole Trapnell. All ri
 Updated and maintained by Daehwan Kim and Geo Pertea since Jul 2010.
 """
 import sys
+
+sys.path.insert(0,"/usr/local/samtools0119/bin")
+
 try:
     import psyco
     psyco.full()
