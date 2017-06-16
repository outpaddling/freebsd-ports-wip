--- cmake/modules/FindPETSc.cmake.orig	2011-12-07 15:21:22.000000000 -0600
+++ cmake/modules/FindPETSc.cmake	2012-05-22 18:02:08.000000000 -0500
@@ -116,7 +116,7 @@
   set(PETSC_INCLUDE ${PETSC_INCLUDE} ${PETSC_CC_INCLUDES})
   petsc_get_variable(PETSC_LIB_BASIC PETSC_LIB_BASIC)
   petsc_get_variable(PETSC_LIB_DIR PETSC_LIB_DIR)
-  set(PETSC_LIB "-L${PETSC_LIB_DIR} ${PETSC_LIB_BASIC}")
+  set(PETSC_LIB "-L${PETSC_LIB_DIR} ${PETSC_LIB_BASIC} -llapack -lblas -lX11")
 
   # Remove temporary Makefile
   file(REMOVE ${petsc_config_makefile})
