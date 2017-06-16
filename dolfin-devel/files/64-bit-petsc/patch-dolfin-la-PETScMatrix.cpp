--- dolfin/la/PETScMatrix.cpp.orig	2012-05-22 16:25:16.000000000 -0500
+++ dolfin/la/PETScMatrix.cpp	2012-05-22 16:31:56.000000000 -0500
@@ -164,7 +164,7 @@
     MatSetType(*A, MATSEQAIJ);
 
     // Allocate space (using data from sparsity pattern)
-    MatSeqAIJSetPreallocation(*A, PETSC_NULL, reinterpret_cast<int*>(&num_nonzeros[0]));
+    MatSeqAIJSetPreallocation(*A, PETSC_NULL, reinterpret_cast<PetscInt *>(&num_nonzeros[0]));
 
     /*
     // Set column indices
@@ -216,8 +216,8 @@
 
     // Allocate space (using data from sparsity pattern)
     MatMPIAIJSetPreallocation(*A,
-           PETSC_NULL, reinterpret_cast<int*>(&num_nonzeros_diagonal[0]),
-           PETSC_NULL, reinterpret_cast<int*>(&num_nonzeros_off_diagonal[0]));
+           PETSC_NULL, reinterpret_cast<PetscInt *>(&num_nonzeros_diagonal[0]),
+           PETSC_NULL, reinterpret_cast<PetscInt *>(&num_nonzeros_off_diagonal[0]));
 
     // Set some options
     #if PETSC_VERSION_MAJOR == 3 && PETSC_VERSION_MINOR >= 1
@@ -252,8 +252,8 @@
 
   // Get matrix entries (must be on this process)
   MatGetValues(*A,
-               static_cast<int>(m), reinterpret_cast<const int*>(rows),
-               static_cast<int>(n), reinterpret_cast<const int*>(cols),
+               static_cast<int>(m), reinterpret_cast<const PetscInt *>(rows),
+               static_cast<int>(n), reinterpret_cast<const PetscInt *>(cols),
                block);
 }
 //-----------------------------------------------------------------------------
@@ -262,8 +262,8 @@
 {
   dolfin_assert(A);
   MatSetValues(*A,
-               static_cast<int>(m), reinterpret_cast<const int*>(rows),
-               static_cast<int>(n), reinterpret_cast<const int*>(cols),
+               static_cast<int>(m), reinterpret_cast<const PetscInt *>(rows),
+               static_cast<int>(n), reinterpret_cast<const PetscInt *>(cols),
                block, INSERT_VALUES);
 }
 //-----------------------------------------------------------------------------
@@ -272,8 +272,8 @@
 {
   dolfin_assert(A);
   MatSetValues(*A,
-               static_cast<int>(m), reinterpret_cast<const int*>(rows),
-               static_cast<int>(n), reinterpret_cast<const int*>(cols),
+               static_cast<int>(m), reinterpret_cast<const PetscInt *>(rows),
+               static_cast<int>(n), reinterpret_cast<const PetscInt *>(cols),
                block, ADD_VALUES);
 }
 //-----------------------------------------------------------------------------
@@ -294,9 +294,9 @@
 {
   dolfin_assert(A);
 
-  const int *cols = 0;
+  const PetscInt  *cols = 0;
   const double *vals = 0;
-  int ncols = 0;
+  PetscInt  ncols = 0;
   MatGetRow(*A, row, &ncols, &cols, &vals);
 
   // Assign values to std::vectors
@@ -341,7 +341,7 @@
   MatZeroRowsIS(*A, is, null, NULL, NULL);
   #else
   ISCreateGeneral(PETSC_COMM_SELF, static_cast<int>(m),
-                  reinterpret_cast<const int*>(rows), &is);
+                  reinterpret_cast<const PetscInt*>(rows), &is);
   MatZeroRowsIS(*A, is, null);
   #endif
 
@@ -365,7 +365,7 @@
   MatZeroRowsIS(*A, is, one, NULL, NULL);
   #else
   ISCreateGeneral(PETSC_COMM_SELF, static_cast<int>(m),
-                  reinterpret_cast<const int*>(rows), &is);
+                  reinterpret_cast<const PetscInt*>(rows), &is);
   MatZeroRowsIS(*A, is, one);
   #endif
 
