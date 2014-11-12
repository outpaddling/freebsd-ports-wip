--- src/python-bindings/secman.cpp.orig	2014-09-30 16:17:32.000000000 -0500
+++ src/python-bindings/secman.cpp	2014-11-11 18:13:02.000000000 -0600
@@ -7,6 +7,20 @@
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
+#undef _BSD_SOURCE
+//#undef _GNU_SOURCE
+#include <Python.h>
+#define _BSD_SOURCE
+#endif
+
 #include "condor_common.h"
 
 #include <boost/python.hpp>
