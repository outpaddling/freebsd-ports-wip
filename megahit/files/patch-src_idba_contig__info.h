--- src/idba/contig_info.h.orig	2025-05-22 15:40:54 UTC
+++ src/idba/contig_info.h
@@ -14,12 +14,13 @@
 
 #include <algorithm>
 #include <deque>
+#include <vector>
 #include <istream>
 #include <ostream>
 #include <string>
 
 typedef uint32_t SequenceCountUnitType;
-typedef std::basic_string<SequenceCountUnitType> SequenceCount;
+typedef std::vector<SequenceCountUnitType> SequenceCount;
 
 class ContigBuilder;
 
