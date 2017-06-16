--- dolfin/graph/MatrixRenumbering.cpp.orig	2011-12-07 15:21:22.000000000 -0600
+++ dolfin/graph/MatrixRenumbering.cpp	2012-05-22 16:06:42.000000000 -0500
@@ -22,6 +22,7 @@
 
 #ifdef HAS_TRILINOS
 
+#include <iostream>
 #include <boost/scoped_array.hpp>
 #include <zoltan_cpp.h>
 
