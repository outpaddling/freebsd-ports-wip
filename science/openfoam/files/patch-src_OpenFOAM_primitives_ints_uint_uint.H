--- src/OpenFOAM/primitives/ints/uint/uint.H.orig	2015-11-25 13:34:22.210695589 -0600
+++ src/OpenFOAM/primitives/ints/uint/uint.H	2015-11-25 13:35:24.450699355 -0600
@@ -35,6 +35,7 @@
 #ifndef uint_H
 #define uint_H
 
+#include <sys/types.h>
 #include "uint32.H"
 #include "uint64.H"
 
