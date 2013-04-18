--- dolfin/la/PETScKrylovMatrix.cpp.orig	2012-05-22 16:16:49.000000000 -0500
+++ dolfin/la/PETScKrylovMatrix.cpp	2012-05-22 16:17:14.000000000 -0500
@@ -79,7 +79,7 @@
   if (A)
   {
     // Get size and local size of existing matrix
-    int _m(0), _n(0), _m_local(0), _n_local(0);
+    PetscInt _m(0), _n(0), _m_local(0), _n_local(0);
     MatGetSize(*A, &_m, &_m);
     MatGetLocalSize(*A, &_m_local, &_n_local);
 
