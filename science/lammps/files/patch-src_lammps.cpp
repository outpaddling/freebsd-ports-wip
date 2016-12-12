--- src/lammps.cpp.orig	2016-12-12 16:46:57.897629559 -0600
+++ src/lammps.cpp	2016-12-12 16:48:36.563604485 -0600
@@ -432,8 +432,11 @@ LAMMPS::LAMMPS(int narg, char **arg, MPI
   int mpisize;
   MPI_Type_size(MPI_LMP_TAGINT,&mpisize);
   if (mpisize != sizeof(tagint))
+  {
+      fprintf(stderr,"mpisize = %u sizeof(tagint) = %u\n", mpisize, sizeof(tagint));
       error->all(FLERR,"MPI_LMP_TAGINT and tagint in "
                  "lmptype.h are not compatible");
+  }
   MPI_Type_size(MPI_LMP_BIGINT,&mpisize);
   if (mpisize != sizeof(bigint))
       error->all(FLERR,"MPI_LMP_BIGINT and bigint in "
