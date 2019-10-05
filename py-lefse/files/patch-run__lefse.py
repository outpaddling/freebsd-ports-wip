--- run_lefse.py.orig	2019-10-05 15:37:24 UTC
+++ run_lefse.py
@@ -62,27 +62,27 @@ if __name__ == '__main__':
 	nf = 0
 	for feat_name,feat_values in feats.items():
 		if params['verbose']:
-			print "Testing feature",str(nf),": ",feat_name,
+			print("Testing feature",str(nf),": ",feat_name,)
 			nf += 1
 		kw_ok,pv = test_kw_r(cls,feat_values,params['anova_alpha'],sorted(cls.keys()))
 		if not kw_ok:
-			if params['verbose']: print "\tkw ko" 
+			if params['verbose']: print("\tkw ko")
 			del feats[feat_name]
 			wilcoxon_res[feat_name] = "-"
 			continue
-		if params['verbose']: print "\tkw ok\t",
+		if params['verbose']: print("\tkw ok\t",)
 		
 		if not params['wilc']: continue
 		kw_n_ok += 1	
 		res_wilcoxon_rep = test_rep_wilcoxon_r(subclass_sl,class_hierarchy,feat_values,params['wilcoxon_alpha'],params['multiclass_strat'],params['strict'],feat_name,params['min_c'],params['only_same_subcl'],params['curv'])
 		wilcoxon_res[feat_name] = str(pv) if res_wilcoxon_rep else "-"
 		if not res_wilcoxon_rep:
-			if params['verbose']: print "wilc ko" 
+			if params['verbose']: print("wilc ko")
 			del feats[feat_name]
-		elif params['verbose']: print "wilc ok\t"
+		elif params['verbose']: print("wilc ok\t")
 		
 	if len(feats) > 0:
-		print "Number of significantly discriminative features:", len(feats), "(", kw_n_ok, ") before internal wilcoxon"
+		print("Number of significantly discriminative features:", len(feats), "(", kw_n_ok, ") before internal wilcoxon")
 		if params['lda_abs_th'] < 0.0:
 			lda_res,lda_res_th = dict([(k,0.0) for k,v in feats.items()]), dict([(k,v) for k,v in feats.items()])
 		else:
@@ -90,8 +90,8 @@ if __name__ == '__main__':
 			elif params['rank_tec'] == 'svm': lda_res,lda_res_th = test_svm(cls,feats,class_sl,params['n_boots'],params['f_boots'],params['lda_abs_th'],0.0,params['svm_norm'])	
 			else: lda_res,lda_res_th = dict([(k,0.0) for k,v in feats.items()]), dict([(k,v) for k,v in feats.items()])
 	else: 
-		print "Number of significantly discriminative features:", len(feats), "(", kw_n_ok, ") before internal wilcoxon"
-		print "No features with significant differences between the two classes"
+		print("Number of significantly discriminative features:", len(feats), "(", kw_n_ok, ") before internal wilcoxon")
+		print("No features with significant differences between the two classes")
 		lda_res,lda_res_th = {},{}
 	outres = {}
 	outres['lda_res_th'] = lda_res_th
@@ -99,5 +99,5 @@ if __name__ == '__main__':
 	outres['cls_means'] = cls_means
 	outres['cls_means_kord'] = kord
 	outres['wilcox_res'] = wilcoxon_res
-	print "Number of discriminative features with abs LDA score >",params['lda_abs_th'],":",len(lda_res_th) 
+	print("Number of discriminative features with abs LDA score >",params['lda_abs_th'],":",len(lda_res_th))
 	save_res(outres,params["output_file"])
