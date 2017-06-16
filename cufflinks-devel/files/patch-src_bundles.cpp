--- src/bundles.cpp.orig	2016-03-03 12:04:11.232043412 -0600
+++ src/bundles.cpp	2016-03-03 12:06:09.220035232 -0600
@@ -698,7 +698,7 @@ double BundleFactory::next_valid_alignme
         if (!_hit_fac->get_hit_from_buf(hit_buf, tmp, false))
             continue;
         
-		if (tmp.ref_id() == 12638153115695167477)  // corresponds to SAM "*" under FNV hash. unaligned read record 
+		if (tmp.ref_id() == 12638153115695167477LL)  // corresponds to SAM "*" under FNV hash. unaligned read record 
             continue;
         
 		raw_mass += tmp.mass();
