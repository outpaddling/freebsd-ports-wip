--- src/plugins/gres/common/gres_common.h.orig	2021-09-21 13:49:48 UTC
+++ src/plugins/gres/common/gres_common.h
@@ -44,7 +44,9 @@
 
 #include "src/common/gres.h"
 #include "src/common/list.h"
+#ifdef __linux__
 #include "src/common/cgroup.h"
+#endif
 
 /*
  * Common validation for what was read in from the gres.conf.
