--- dolfin/la/PETScBaseMatrix.cpp.orig	2011-12-07 15:21:22.000000000 -0600
+++ dolfin/la/PETScBaseMatrix.cpp	2012-05-22 16:16:00.000000000 -0500
@@ -39,7 +39,7 @@
 
   if (A)
   {
-    int m(0), n(0);
+    PetscInt m(0), n(0);
     MatGetSize(*A, &m, &n);
     if (dim == 0)
       return m;
@@ -62,7 +62,7 @@
 
   if (A)
   {
-    int m(0), n(0);
+    PetscInt m(0), n(0);
     MatGetOwnershipRange(*A, &m, &n);
     return std::make_pair(m, n);
   }
