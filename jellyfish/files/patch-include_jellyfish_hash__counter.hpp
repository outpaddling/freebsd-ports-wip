--- include/jellyfish/hash_counter.hpp.orig	2019-05-13 07:43:45 UTC
+++ include/jellyfish/hash_counter.hpp
@@ -206,7 +206,7 @@ class hash_counter { (protected)
       try {
         new_ary_   = new array(ary_->size() * 2, ary_->key_len(), ary_->val_len(),
                                ary_->max_reprobe(), ary_->reprobes());
-       } catch(typename array::ErrorAllocation e) {
+       } catch(typename array::ErrorAllocation &e) {
         new_ary_ = 0;
       }
     }
