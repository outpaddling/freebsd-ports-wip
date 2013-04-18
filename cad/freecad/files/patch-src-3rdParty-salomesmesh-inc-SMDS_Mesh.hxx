--- src/3rdParty/salomesmesh/inc/SMDS_Mesh.hxx.orig	2012-01-07 15:42:30.000000000 -0600
+++ src/3rdParty/salomesmesh/inc/SMDS_Mesh.hxx	2012-01-07 15:43:16.000000000 -0600
@@ -41,6 +41,7 @@
 #include <boost/shared_ptr.hpp>
 #include <set>
 #include <list>
+#include <sys/wait.h>
 
 class SMDS_EXPORT SMDS_Mesh:public SMDS_MeshObject{
 public:
