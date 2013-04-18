--- dolfin/la/PETScKrylovSolver.cpp.orig	2012-05-22 16:17:50.000000000 -0500
+++ dolfin/la/PETScKrylovSolver.cpp	2012-05-22 16:24:30.000000000 -0500
@@ -253,7 +253,7 @@
   KSPSolve(*_ksp, *b.vec(), *x.vec());
 
   // Get the number of iterations
-  int num_iterations = 0;
+  PetscInt num_iterations = 0;
   KSPGetIterationNumber(*_ksp, &num_iterations);
 
   // Check if the solution converged and print error/warning if not converged
@@ -369,7 +369,7 @@
 void PETScKrylovSolver::set_petsc_options()
 {
   // GMRES restart parameter
-  KSPGMRESSetRestart(*_ksp, parameters("gmres")["restart"]);
+  KSPGMRESSetRestart(*_ksp, (int)parameters("gmres")["restart"]);
 
   // Non-zero initial guess
   const bool nonzero_guess = parameters["nonzero_initial_guess"];
@@ -383,10 +383,10 @@
 
   // Set tolerances
   KSPSetTolerances(*_ksp,
-                   parameters["relative_tolerance"],
-                   parameters["absolute_tolerance"],
-                   parameters["divergence_limit"],
-                   parameters["maximum_iterations"]);
+                   (int)parameters["relative_tolerance"],
+                   (int)parameters["absolute_tolerance"],
+                   (int)parameters["divergence_limit"],
+                   (int)parameters["maximum_iterations"]);
 }
 //-----------------------------------------------------------------------------
 void PETScKrylovSolver::write_report(int num_iterations,
