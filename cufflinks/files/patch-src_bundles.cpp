--- src/bundles.cpp.orig	2013-04-04 09:41:19.000000000 -0500
+++ src/bundles.cpp	2016-11-23 11:56:22.628486000 -0600
@@ -22,7 +22,7 @@ using boost::math::binomial;
 //struct ScaffoldSorter
 //{
 //	ScaffoldSorter(RefSequenceTable& _rt) : rt(_rt) {} 
-//	bool operator()(shared_ptr<Scaffold const> lhs, shared_ptr<Scaffold const> rhs)
+//	bool operator()(boost::shared_ptr<Scaffold const> lhs, boost::shared_ptr<Scaffold const> rhs)
 //	{
 //        assert (lhs);
 //        assert (rhs);
@@ -46,7 +46,7 @@ using boost::math::binomial;
 struct ScaffoldSorter
 {
 	ScaffoldSorter(RefSequenceTable& _rt) : rt(_rt) {} 
-	bool operator()(shared_ptr<Scaffold const> lhs, shared_ptr<Scaffold const> rhs)
+	bool operator()(boost::shared_ptr<Scaffold const> lhs, boost::shared_ptr<Scaffold const> rhs)
 	{
         //assert (lhs);
         //assert (rhs);
@@ -74,7 +74,7 @@ struct ScaffoldSorter
 //FIXME: needs refactoring
 void load_ref_rnas(FILE* ref_mRNA_file, 
 				   RefSequenceTable& rt,
-				   vector<shared_ptr<Scaffold> >& ref_mRNAs,
+				   vector<boost::shared_ptr<Scaffold> >& ref_mRNAs,
 				   bool loadSeqs,
 				   bool loadFPKM) 
 {
@@ -221,14 +221,14 @@ void load_ref_rnas(FILE* ref_mRNA_file, 
 					GFREE(rna_seq);
 				}
                 
-				shared_ptr<Scaffold> scaff(new Scaffold());
+				boost::shared_ptr<Scaffold> scaff(new Scaffold());
                 *scaff = ref_scaff;
                 assert (scaff);
 				ref_mRNAs.push_back(scaff); 
 			}
 		}
         
-        BOOST_FOREACH (shared_ptr<Scaffold> s, ref_mRNAs)
+        BOOST_FOREACH (boost::shared_ptr<Scaffold> s, ref_mRNAs)
         {
             assert (s);
         }
@@ -268,7 +268,7 @@ bool HitBundle::add_hit(const MateHit& h
 
 struct HitlessScaffold
 {
-	bool operator()(shared_ptr<Scaffold> x)
+	bool operator()(boost::shared_ptr<Scaffold> x)
 	{
 		return x->mate_hits().empty();
 	}
@@ -280,7 +280,7 @@ bool unmapped_hit(const MateHit& x)
 }
 
 
-bool HitBundle::add_open_hit(shared_ptr<ReadGroupProperties const> rg_props,
+bool HitBundle::add_open_hit(boost::shared_ptr<ReadGroupProperties const> rg_props,
                              const ReadHit* bh,
 							 bool expand_by_partner)
 {
@@ -432,7 +432,7 @@ void HitBundle::finalize_open_mates()
 
 void HitBundle::remove_hitless_scaffolds()
 {
-	vector<shared_ptr<Scaffold> >::iterator new_end = remove_if(_ref_scaffs.begin(),
+	vector<boost::shared_ptr<Scaffold> >::iterator new_end = remove_if(_ref_scaffs.begin(),
 												   _ref_scaffs.end(),
 												   HitlessScaffold());
 	_ref_scaffs.erase(new_end, _ref_scaffs.end());	
@@ -523,15 +523,15 @@ void HitBundle::combine(const vector<Hit
     while(true)
     {
         int next_bundle = -1;
-        shared_ptr<Scaffold> next_scaff; 
+        boost::shared_ptr<Scaffold> next_scaff; 
         for(size_t i = 0; i < in_bundles.size(); ++i)
         {
-            const vector<shared_ptr<Scaffold> >& curr_scaffs = in_bundles[i]->_ref_scaffs;
+            const vector<boost::shared_ptr<Scaffold> >& curr_scaffs = in_bundles[i]->_ref_scaffs;
             
             if (indices[i] == curr_scaffs.size())
                 continue;
             
-            shared_ptr<Scaffold> curr_scaff = curr_scaffs[indices[i]];
+            boost::shared_ptr<Scaffold> curr_scaff = curr_scaffs[indices[i]];
             
             if (next_bundle == -1 || scaff_lt_rt_oplt(*curr_scaff, *next_scaff))
             {
@@ -600,11 +600,11 @@ void HitBundle::finalize(bool is_combine
             
         }
 		sort(_ref_scaffs.begin(), _ref_scaffs.end(), scaff_lt_rt_oplt_sp);
-		vector<shared_ptr<Scaffold> >::iterator new_end = unique(_ref_scaffs.begin(), 
+		vector<boost::shared_ptr<Scaffold> >::iterator new_end = unique(_ref_scaffs.begin(), 
 												_ref_scaffs.end(),
 												StructurallyEqualScaffolds());
 		_ref_scaffs.erase(new_end, _ref_scaffs.end());
-        vector<shared_ptr<Scaffold> >(_ref_scaffs).swap(_ref_scaffs);
+        vector<boost::shared_ptr<Scaffold> >(_ref_scaffs).swap(_ref_scaffs);
 	}
 	
     for (size_t j = 0; j < _ref_scaffs.size(); ++j)
@@ -677,7 +677,7 @@ double BundleFactory::next_valid_alignme
         if (!_hit_fac->get_hit_from_buf(hit_buf, tmp, false))
             continue;
         
-		if (tmp.ref_id() == 12638153115695167477)  // corresponds to SAM "*" under FNV hash. unaligned read record 
+		if (tmp.ref_id() == 12638153115695167477ULL)  // corresponds to SAM "*" under FNV hash. unaligned read record 
             continue;
         
 		raw_mass += tmp.mass();
@@ -718,7 +718,7 @@ double BundleFactory::next_valid_alignme
             (*next_mask_scaff)->ref_id() != tmp.ref_id())
         {
             bool found_scaff = false;
-            vector<shared_ptr<Scaffold> >::iterator curr_mask_scaff = mask_gtf_recs.begin();
+            vector<boost::shared_ptr<Scaffold> >::iterator curr_mask_scaff = mask_gtf_recs.begin();
             for (size_t i = 0; i < _mask_scaff_offsets.size(); ++i)
             {
                 if (_mask_scaff_offsets[i].first == tmp.ref_id())
@@ -1605,8 +1605,8 @@ void inspect_map(BundleFactory& bundle_f
 		p_bar = ProgressBar("Inspecting reads and determining fragment length distribution.",bundle_factory.ref_table().size());
 	RefID last_chrom = 0;
 
-	long double map_mass = 0.0;
-    long double norm_map_mass = 0.0;
+	double map_mass = 0.0;
+    double norm_map_mass = 0.0;
 	
 	int min_len = numeric_limits<int>::max();
 	int max_len = def_max_frag_len;
@@ -1618,13 +1618,13 @@ void inspect_map(BundleFactory& bundle_f
 	size_t total_non_redundant_hits = 0;
 	
 	//To be used for quartile normalization
-	vector<long double> mass_dist; 	
+	vector<double> mass_dist; 	
 	
 	// Store the maximum read length for "first" and "second" reads to report to user.
 	int max_1 = 0;
 	int max_2 = 0;
 	
-	shared_ptr<MultiReadTable> mrt(new MultiReadTable());
+	boost::shared_ptr<MultiReadTable> mrt(new MultiReadTable());
 	
 	while(true)
 	{
@@ -1750,7 +1750,7 @@ void inspect_map(BundleFactory& bundle_f
 			// Annotation provided and single isoform gene
 			{
 				int start, end, mate_length;
-				shared_ptr<Scaffold> scaff = bundle.ref_scaffolds()[0];
+				boost::shared_ptr<Scaffold> scaff = bundle.ref_scaffolds()[0];
 				if (scaff->map_frag(hits[i], start, end, mate_length))
 				{
 					if (mate_length >= min_len && mate_length <= max_len)
@@ -1844,7 +1844,7 @@ void inspect_map(BundleFactory& bundle_f
 	
 	vector<double> frag_len_pdf(max_len+1, 0.0);
 	vector<double> frag_len_cdf(max_len+1, 0.0);
-    long double tot_count = accumulate(frag_len_hist.begin(), frag_len_hist.end(), 0.0 );
+    double tot_count = accumulate(frag_len_hist.begin(), frag_len_hist.end(), 0.0 );
     bool empirical = false;
 	
 	if (user_provided_fld && has_pairs && tot_count >= 10000)
@@ -1935,7 +1935,7 @@ void inspect_map(BundleFactory& bundle_f
     
     std_dev = sqrt(std_dev);
 	
-	shared_ptr<ReadGroupProperties> rg_props = bundle_factory.read_group_properties();
+	boost::shared_ptr<ReadGroupProperties> rg_props = bundle_factory.read_group_properties();
 
     FLDSource source = DEFAULT;
     if (empirical)
@@ -1947,7 +1947,7 @@ void inspect_map(BundleFactory& bundle_f
         source = USER;
     }
 
-	shared_ptr<EmpDist const> fld(new EmpDist(frag_len_pdf, frag_len_cdf, frag_len_mode, mean, std_dev, min_len, max_len, source));
+	boost::shared_ptr<EmpDist const> fld(new EmpDist(frag_len_pdf, frag_len_cdf, frag_len_mode, mean, std_dev, min_len, max_len, source));
 	rg_props->multi_read_table(mrt);
 	rg_props->frag_len_dist(fld);
 	rg_props->normalized_map_mass(norm_map_mass);
@@ -1957,9 +1957,9 @@ void inspect_map(BundleFactory& bundle_f
     {
         fprintf(stderr, "> Map Properties:\n");
         //if (lib_norm_method == QUARTILE)
-        //    fprintf(stderr, ">\tUpper Quartile: %.2Lf\n", norm_map_mass);
-        fprintf(stderr, ">\tNormalized Map Mass: %.2Lf\n", norm_map_mass);
-        fprintf(stderr, ">\tRaw Map Mass: %.2Lf\n", map_mass);
+        //    fprintf(stderr, ">\tUpper Quartile: %.2lf\n", norm_map_mass);
+        fprintf(stderr, ">\tNormalized Map Mass: %.2lf\n", norm_map_mass);
+        fprintf(stderr, ">\tRaw Map Mass: %.2lf\n", map_mass);
         if (corr_multi)
             fprintf(stderr,">\tNumber of Multi-Reads: %zu (with %zu total hits)\n", mrt->num_multireads(), mrt->num_multihits()); 
     //	if (has_pairs)
