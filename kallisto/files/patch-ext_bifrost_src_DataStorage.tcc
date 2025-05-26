--- ext/bifrost/src/DataStorage.tcc.orig	2025-05-26 18:09:32 UTC
+++ ext/bifrost/src/DataStorage.tcc
@@ -78,7 +78,7 @@ DataStorage<U>::DataStorage(const DataStorage& o) : co
 
         unitig_cs_link = new atomic<uint64_t>[sz_link];
 
-        for (size_t i = 0; i != sz_link; ++i) unitig_cs_link[i] = o.sz_link[i].load();
+        for (size_t i = 0; i != sz_link; ++i) unitig_cs_link[i] = o.unitig_cs_link[i].load();
     }
 
     if ((o.data != nullptr) && (o.sz_cs != 0)){
