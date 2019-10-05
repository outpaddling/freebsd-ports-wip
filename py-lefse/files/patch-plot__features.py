--- plot_features.py.orig	2019-10-05 15:39:11 UTC
+++ plot_features.py
@@ -40,7 +40,7 @@ def read_data(file_data,file_feats,params):
 	with open(file_feats, 'r') as features:
 		feats_to_plot = [(f.split()[:-1],len(f.split()) == 5) for f in features.readlines()]
 	if not feats_to_plot:
-		print "No features to plot\n"
+		print("No features to plot\n")
 		sys.exit(0)
 	feats,cls,class_sl,subclass_sl,class_hierarchy,params['norm_v'] = load_data(file_data, True)	 	
 	if params['feature_num'] > 0: 
@@ -51,7 +51,7 @@ def read_data(file_data,file_feats,params):
 		if params['f'] == "one" and f[0][0] != params['feature_name']: continue
 		features[f[0][0]] = {'dim':float(f[0][1]), 'abundances':feats[f[0][0]], 'sig':f[1], 'cls':cls, 'class_sl':class_sl, 'subclass_sl':subclass_sl, 'class_hierarchy':class_hierarchy} 
 	if not features:
-                print "No features to plot\n"
+                print("No features to plot\n")
                 sys.exit(0)
 	return features
 
@@ -143,7 +143,7 @@ if __name__ == '__main__':
 	features = read_data(params['input_file_1'],params['input_file_2'],params)
 	if params['archive'] == "zip": file = zipfile.ZipFile(params['output_file'], "w")
 	for k,f in features.items():
-		print "Exporting ", k
+		print("Exporting ", k)
 		if params['archive'] == "zip":
 			of = plot("/tmp/"+str(int(f['sig']))+"_"+"-".join(k.split("."))+"."+params['format'],k,f,params)
 			file.write(of, os.path.basename(of), zipfile.ZIP_DEFLATED)
