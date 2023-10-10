--- src/BlockedBloomFilter.cpp.orig	2023-10-09 14:58:56 UTC
+++ src/BlockedBloomFilter.cpp
@@ -606,7 +606,10 @@ DualBlockedBloomFilter::DualBlockedBloomFilter(const s
 }
 
 DualBlockedBloomFilter::DualBlockedBloomFilter(const DualBlockedBloomFilter& o) :   table_(nullptr), blocks_(o.blocks_), nb_bits_per_elem(o.nb_bits_per_elem),
-                                                                                    k_(o.k_), M_u64(o.M_u64), seed1(o.seed1), seed2(o.seed2), ush(o.ush) {
+                                                                                    k_(o.k_), M_u64(o.M_u64), seed1(o.seed1), seed2(o.seed2) {
+
+    // memcpy(ush, o.ush, sizeof(ush));
+    std::copy(std::begin(o.ush), std::end(o.ush), std::begin(ush));
 
     if (blocks_ != 0) {
 
