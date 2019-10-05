--- format_input.py.orig	2019-10-05 15:39:44 UTC
+++ format_input.py
@@ -358,7 +358,7 @@ def  check_params_for_biom_case(params, CommonArea):
 			else:
 				FlagError = True
 		if FlagError == True:		#* If the User passed an invalid class
-			print "**Invalid biom class or subclass passed - Using defaults: First metadata=class, Second Metadata=subclass\n"
+			print("**Invalid biom class or subclass passed - Using defaults: First metadata=class, Second Metadata=subclass\n")
 			params['class'] =  2
 			params['subclass'] =  3
 	return params
