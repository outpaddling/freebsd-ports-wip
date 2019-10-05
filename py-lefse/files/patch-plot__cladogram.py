--- plot_cladogram.py.orig	2019-10-05 15:37:03 UTC
+++ plot_cladogram.py
@@ -288,7 +288,7 @@ def draw_tree(out_file,tree,params):
 		params['clade_sep'] *= 0.75 	 
 		seps = [params['clade_sep']*sep/(float(depth-i+1)*0.25) for i in range(1,len(tree['nlev'])+1)]
 		totseps = sum([s*nlev[i] for i,s in enumerate(seps[:-1])])
-	if clade_sep_err: print 'clade_sep parameter too large, lowered to',params['clade_sep']
+	if clade_sep_err: print('clade_sep parameter too large, lowered to',params['clade_sep'])
 
 	fig = plt.figure(edgecolor=params['back_color'],facecolor=params['back_color'])
 	ax = fig.add_subplot(111, polar=True, frame_on=False, axis_bgcolor=params['back_color'] )
