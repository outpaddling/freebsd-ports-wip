--- src/OpenFOAM/primitives/ints/uint/uint.H.orig	2015-11-03 10:30:23 UTC
+++ src/OpenFOAM/primitives/ints/uint/uint.H
@@ -35,6 +35,7 @@ SourceFiles
 #ifndef uint_H
 #define uint_H
 
+#include <sys/types.h>
 #include "uint32.H"
 #include "uint64.H"
 
