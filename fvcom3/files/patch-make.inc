--- make.inc.orig	2011-02-04 09:55:11.000000000 -0600
+++ make.inc	2012-04-02 13:51:37.000000000 -0500
@@ -48,7 +48,7 @@
 #========== TOPDIR ========================================================
 # TOPDIR is the directory in which this make file and the fvcom source reside
 
-           TOPDIR        = /zeus/d2/data/fvcom/fvcom_source_mpi
+           TOPDIR        = ${WRKSRC}
 #EXAMPLE
 # TOPDIR = /home/user/cchen/FVCOM_source
 # TOPDIR must be set!
@@ -97,8 +97,8 @@
 #             IOINCS       =  #-I/hosts/mao/usr/medm/install/netcdf/3.6.3/em64t/include
 #             IOLIBS       =  -L/usr/local/lib  -lnetcdf
 #             IOINCS       =  -I/usr/local/include
-             IOLIBS       =  -L/libs  -lmpi -lnetcdf
-             IOINCS       =  -I/usr/local/include
+             IOLIBS       =  -L${LOCALBASE}/lib -lmpi -lnetcdf
+             IOINCS       =  -I${LOCALBASE}/include
 #--------------------------------------------------------------------------
 
 
@@ -482,13 +482,13 @@
 #--------------------------------------------------------------------------
 #  Intel Compiler Definitions
 #--------------------------------------------------------------------------
-         CPP      = /usr/bin/cpp
-         COMPILER = -DIFORT
-         FC       = ifort 
-         CC       = icc
-         CXX      = icpc
-         CFLAGS   = -O3 -xT -ip -lmpi
-         DEBFLGS  = #-check all
+#         CPP      = /usr/bin/cpp
+#         COMPILER = -DIFORT
+#         FC       = ifort 
+#         CC       = icc
+#         CXX      = icpc
+#         CFLAGS   = -O3 -xT -ip -lmpi
+#         DEBFLGS  = #-check all
 # Use 'OPT = -O0 -g' for fast compile to test the make 
 # Use 'OPT = -xP' for fast run on em64t (Hydra and Guppy)
 # Use 'OPT = -xN' for fast run on ia32 (Salmon and Minke)
@@ -528,6 +528,16 @@
 #         OPT      = 
 #         CLIB     = 
 #--------------------------------------------------------------------------
+#  gfortran MPI defs 
+#--------------------------------------------------------------------------
+         CPP      = /usr/bin/cpp 
+         COMPILER = -DGFORTRAN
+#	 CC       = mpicc
+#        FC       = mpif90
+         DEBFLGS  = -g
+         OPT      = -O
+         CLIB     = 
+#--------------------------------------------------------------------------
 #  absoft / mac os x defs
 #--------------------------------------------------------------------------
 #         CPP      = /usr/bin/cpp 
