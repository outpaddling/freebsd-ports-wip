
# FIXME: Why is this needed here but not in other files using the same header?

--- src/condor_gridmanager/azurejob.cpp.orig	2018-07-08 15:08:18 UTC
+++ src/condor_gridmanager/azurejob.cpp
@@ -29,7 +29,7 @@
 
 #ifdef WIN32
 #else
-#include <uuid/uuid.h>
+#include <uuid.h>
 #endif
 
 #include "gridmanager.h"
