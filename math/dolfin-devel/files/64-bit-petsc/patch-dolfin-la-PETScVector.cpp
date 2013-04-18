--- dolfin/la/PETScVector.cpp.orig	2012-05-22 16:42:14.000000000 -0500
+++ dolfin/la/PETScVector.cpp	2012-05-22 16:55:33.000000000 -0500
@@ -223,7 +223,7 @@
   if (local_size == 0)
     return;
 
-  std::vector<int> rows(local_size);
+  std::vector<PetscInt> rows(local_size);
   for (uint i = 0; i < local_size; ++i)
     rows[i] = i + n0;
 
@@ -246,7 +246,7 @@
     return;
 
   // Build array of global indices
-  std::vector<int> rows(local_size);
+  std::vector<PetscInt> rows(local_size);
   for (uint i = 0; i < local_size; ++i)
     rows[i] = i + n0;
 
@@ -269,7 +269,7 @@
     return;
 
   // Build array of global indices
-  std::vector<int> rows(local_size);
+  std::vector<PetscInt> rows(local_size);
   for (uint i = 0; i < local_size; ++i)
     rows[i] = i + n0;
 
@@ -279,8 +279,8 @@
 void PETScVector::get_local(double* block, uint m, const uint* rows) const
 {
   dolfin_assert(x);
-  int _m = static_cast<int>(m);
-  const int* _rows = reinterpret_cast<const int*>(rows);
+  PetscInt _m = static_cast<PetscInt>(m);
+  const PetscInt* _rows = reinterpret_cast<const PetscInt*>(rows);
 
   // Handle case that m = 0 (VecGetValues is collective -> must be called be
   //                         all processes)
@@ -306,7 +306,7 @@
     const uint local_size = n1 - n0;
 
     // Build list of rows, and get from ghosted vector
-    std::vector<int> local_rows(m);
+    std::vector<PetscInt> local_rows(m);
     for (uint i = 0; i < m; ++i)
     {
       if (rows[i] >= n0 && rows[i] < n1)
@@ -331,7 +331,7 @@
   if (m == 0)
     return;
 
-  VecSetValues(*x, m, reinterpret_cast<const int*>(rows), block, INSERT_VALUES);
+  VecSetValues(*x, m, reinterpret_cast<const PetscInt*>(rows), block, INSERT_VALUES);
 }
 //-----------------------------------------------------------------------------
 void PETScVector::add(const double* block, uint m, const uint* rows)
@@ -341,7 +341,7 @@
   if (m == 0)
     return;
 
-  VecSetValues(*x, m, reinterpret_cast<const int*>(rows), block, ADD_VALUES);
+  VecSetValues(*x, m, reinterpret_cast<const PetscInt*>(rows), block, ADD_VALUES);
 }
 //-----------------------------------------------------------------------------
 void PETScVector::apply(std::string mode)
@@ -360,7 +360,7 @@
 //-----------------------------------------------------------------------------
 dolfin::uint PETScVector::size() const
 {
-  int n = 0;
+  PetscInt n = 0;
   if (x)
     VecGetSize(*x, &n);
   return static_cast<uint>(n);
@@ -368,7 +368,7 @@
 //-----------------------------------------------------------------------------
 dolfin::uint PETScVector::local_size() const
 {
-  int n = 0;
+  PetscInt n = 0;
   if (x)
     VecGetLocalSize(*x, &n);
   return static_cast<uint>(n);
@@ -377,7 +377,10 @@
 std::pair<dolfin::uint, dolfin::uint> PETScVector::local_range() const
 {
   std::pair<uint, uint> range;
-  VecGetOwnershipRange(*x, (int*) &range.first, (int*) &range.second);
+  PetscInt tempFirst = range.first, tempSecond = range.second;
+  VecGetOwnershipRange(*x, &tempFirst, &tempSecond);
+  range.first = tempFirst;
+  range.second = tempSecond;
   dolfin_assert(range.first <= range.second);
   return range;
 }
@@ -542,7 +545,7 @@
   dolfin_assert(x);
 
   double value = 0.0;
-  int position = 0;
+  PetscInt position = 0;
   VecMin(*x, &position, &value);
   return value;
 }
@@ -552,7 +555,7 @@
   dolfin_assert(x);
 
   double value = 0.0;
-  int position = 0;
+  PetscInt position = 0;
   VecMax(*x, &position, &value);
   return value;
 }
@@ -661,10 +664,10 @@
   }
 
   // Prepare data for index sets (global indices)
-  const int* global_indices = reinterpret_cast<const int*>(indices.data().get());
+  const PetscInt* global_indices = reinterpret_cast<const PetscInt*>(indices.data().get());
 
   // Prepare data for index sets (local indices)
-  const int n = indices.size();
+  const PetscInt n = indices.size();
 
   // PETSc will bail out if it receives a NULL pointer even though m == 0.
   // Can't return from function since function calls are collective.
@@ -769,9 +772,9 @@
     // Clear ghost indices map
     ghost_global_to_local.clear();
 
-    const int* _ghost_indices = 0;
+    const PetscInt* _ghost_indices = 0;
     if (ghost_indices.size() > 0)
-      _ghost_indices = reinterpret_cast<const int*>(&ghost_indices[0]);
+      _ghost_indices = reinterpret_cast<const PetscInt*>(&ghost_indices[0]);
 
     VecCreateGhost(PETSC_COMM_WORLD, local_size, PETSC_DECIDE,
                    ghost_indices.size(), _ghost_indices, x.get());
