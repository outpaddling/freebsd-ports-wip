--- src/BlockedBloomFilter.cpp.orig	2023-10-10 12:00:01 UTC
+++ src/BlockedBloomFilter.cpp
@@ -606,7 +606,9 @@ DualBlockedBloomFilter::DualBlockedBloomFilter(const s
 }
 
 DualBlockedBloomFilter::DualBlockedBloomFilter(const DualBlockedBloomFilter& o) :   table_(nullptr), blocks_(o.blocks_), nb_bits_per_elem(o.nb_bits_per_elem),
-                                                                                    k_(o.k_), M_u64(o.M_u64), seed1(o.seed1), seed2(o.seed2), ush(o.ush) {
+                                                                                    k_(o.k_), M_u64(o.M_u64), seed1(o.seed1), seed2(o.seed2) {
+
+    memcpy(ush, o.ush, sizeof(ush));
 
     if (blocks_ != 0) {
 
