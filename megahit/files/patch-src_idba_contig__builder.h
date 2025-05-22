--- src/idba/contig_builder.h.orig	2025-05-22 15:40:48 UTC
+++ src/idba/contig_builder.h
@@ -39,7 +39,7 @@ class ContigBuilder {
       contig_ += x.kmer()[x.kmer().size() - 1];
       contig_info_.out_edges_ = x.out_edges();
       contig_info_.kmer_count_ += x.count();
-      contig_info_.counts_ += x.count();
+      contig_info_.counts_.push_back(x.count());
     }
   }
 
@@ -57,15 +57,35 @@ class ContigBuilder {
         contig_info_.out_edges_ = x.out_edges();
         contig_info_.kmer_count_ += x.kmer_count();
         SequenceCount counts = x.counts();
-        contig_info_.counts_ += counts.substr(
-            std::min(-d - contig_info_.kmer_size_ + 1, (int)counts.size()));
+        {
+          int start = std::min(-d - (int)contig_info_.kmer_size_ + 1,
+                               (int)counts.size());
+          contig_info_.counts_.insert(
+            contig_info_.counts_.end(),
+            counts.begin() + start,
+            counts.end()
+          );
+        }
       } else {
         contig_.Append(d, 4);
         contig_.Append(x.contig());
         contig_info_.out_edges_ = x.out_edges();
         contig_info_.kmer_count_ += x.kmer_count();
-        contig_info_.counts_.append(d, 0);
-        contig_info_.counts_ += x.counts();
+        // contig_info_.counts_.append(d, 0);
+        // contig_info_.counts_ += x.counts();
+        
+        // pad with d zeros
+        contig_info_.counts_.insert(
+          contig_info_.counts_.end(),
+          d, 0
+        );
+        // then append the entire counts() vector
+        const SequenceCount &more = x.counts();
+        contig_info_.counts_.insert(
+          contig_info_.counts_.end(),
+          more.begin(),
+          more.end()
+        );
       }
     }
   }
