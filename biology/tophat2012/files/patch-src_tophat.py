--- src/tophat.py.orig	2016-03-15 15:52:31.788047092 -0500
+++ src/tophat.py	2016-03-15 15:52:47.356042582 -0500
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
