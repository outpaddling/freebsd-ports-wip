--- src/python-bindings/dc_tool.cpp.orig	2014-09-30 16:17:32.000000000 -0500
+++ src/python-bindings/dc_tool.cpp	2014-11-12 07:06:51.000000000 -0600
@@ -7,6 +7,24 @@
 # include <pyport.h>
 # endif
 
+/*
+ * Totally unacceptable hack for proof-of concept.
+ * #include <Python.h> solves a ctype function overload issue, but causes
+ * a dprintf() conflict.  The undefs disable dprintf() in stdio.h and
+ * probably have other side-effects.
+ */
+
+#ifdef __FreeBSD__
+//#undef _BSD_SOURCE
+//#undef _GNU_SOURCE
+#define dprintf _hide_dprintf
+#define getline _hide_getline
+#include <Python.h>
+#undef getline
+#undef dprintf
+//#define _BSD_SOURCE
+#endif
+
 #include "condor_common.h"
 
 #include <boost/python.hpp>
