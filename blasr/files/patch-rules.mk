--- rules.mk.orig	2018-04-30 20:35:13 UTC
+++ rules.mk
@@ -2,9 +2,11 @@ INCDIRS := \
 	${LIBBLASR_INC} \
 	${LIBPBIHDF_INC} \
 	${LIBPBDATA_INC}
+# HDF5 ($LOCALBASE/include/hdf5-18) before PBBAM ($LOCALBASE/include)
+# To avoid hdf5 1.10 headers
 SYSINCDIRS := \
-	${PBBAM_INC} \
 	${HDF5_INC} \
+	${PBBAM_INC} \
 	${BOOST_INC}
 LIBDIRS := \
 	${LIBBLASR_LIB} \
