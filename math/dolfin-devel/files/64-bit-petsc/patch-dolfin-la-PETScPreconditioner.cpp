--- dolfin/la/PETScPreconditioner.cpp.orig	2012-05-22 16:35:06.000000000 -0500
+++ dolfin/la/PETScPreconditioner.cpp	2012-05-22 16:41:34.000000000 -0500
@@ -175,14 +175,14 @@
   {
     // Select method and overlap
     PCSetType(pc, _methods.find("additive_schwarz")->second);
-    PCASMSetOverlap(pc, parameters("schwarz")["overlap"]);
+    PCASMSetOverlap(pc, (int)parameters("schwarz")["overlap"]);
 
     // Make sure the data structures have been constructed
     KSPSetUp(*solver.ksp());
 
     // Get sub-solvers and set sub-solver parameters
     KSP* sub_ksps;
-    int num_local(0), first(0);
+    PetscInt num_local(0), first(0);
     PCASMGetSubKSP(pc, &num_local, &first, &sub_ksps);
     for (int i = 0; i < num_local; ++i)
     {
@@ -194,7 +194,7 @@
       //PCFactorSetMatSolverPackage(sub_pc, MAT_SOLVER_UMFPACK);
       //PCSetType(sub_pc, PCILU);
       //KSPSetType(sub_ksps[i], KSPGMRES);
-      PCFactorSetLevels(sub_pc, parameters("ilu")["fill_level"]);
+      PCFactorSetLevels(sub_pc, (int)parameters("ilu")["fill_level"]);
       //PCFactorSetLevels(sub_pc, 4);
       //PCView(sub_pc, PETSC_VIEWER_STDOUT_WORLD);
     }
@@ -215,7 +215,7 @@
     #endif
   }
 
-  PCFactorSetLevels(pc, parameters("ilu")["fill_level"]);
+  PCFactorSetLevels(pc, (int)parameters("ilu")["fill_level"]);
 
   // Make sure options are set
   PCSetFromOptions(pc);
