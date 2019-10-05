--- plot_res.py.orig	2019-10-05 15:38:33 UTC
+++ plot_res.py
@@ -44,7 +44,7 @@ def read_data(input_file,output_file,otu_only):
             rows = [line.strip().split()[:-1] for line in inp.readlines() if len(line.strip().split())>3 and len(line.strip().split()[0].split('.'))==8] # a feature with length 8 will have an OTU id associated with it
     classes = list(set([v[2] for v in rows if len(v)>2]))
     if len(classes) < 1: 
-        print "No differentially abundant features found in "+input_file
+        print("No differentially abundant features found in "+input_file)
         os.system("touch "+output_file)
         sys.exit()
     data = {}
@@ -94,9 +94,9 @@ def plot_histo_hor(path,params,data,bcl,report_feature
         ax.barh(pos[i],vv, align='center', color=col, label=lab, height=0.8, edgecolor=params['fore_color'])
     mv = max([abs(float(v[3])) for v in data['rows']])  
     if report_features:
-        print 'OTU\tLDA_score\tCLass'
+        print('OTU\tLDA_score\tCLass')
         for i in out_data:
-            print '%s\t%s\t%s' %(i, out_data[i][0], out_data[i][1])
+            print('%s\t%s\t%s' %(i, out_data[i][0], out_data[i][1]))
     for i,r in enumerate(data['rows']):
         indcl = cls.index(data['rows'][i][2])
         if params['n_scl'] < 0: rr = r[0]
@@ -156,9 +156,9 @@ def plot_histo_ver(path,params,data,report_features):
         vv = fabs(float(v[3])) 
         ax.bar(pos[i],vv, align='center', color=col, label=lab)
     if report_features:
-        print 'OTU\tLDA_score\tCLass'
+        print('OTU\tLDA_score\tCLass')
         for i in out_data:
-            print '%s\t%s\t%s' %(i, out_data[i][0], out_data[i][1])
+            print('%s\t%s\t%s' %(i, out_data[i][0], out_data[i][1]))
     xticks(pos,nam,rotation=-20, ha = 'left',size=params['feature_font_size'])  
     ax.set_title(params['title'],size=params['title_font_size'])
     ax.set_ylabel("LDA SCORE (log 10)")
