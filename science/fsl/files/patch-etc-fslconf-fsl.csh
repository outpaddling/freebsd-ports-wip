--- etc/fslconf/fsl.csh.orig	Tue Nov 20 05:22:44 2007
+++ etc/fslconf/fsl.csh	Wed Jan 30 09:48:53 2008
@@ -25,8 +25,8 @@
 # The following variables specify paths for programs and can be changed
 #  or replaced by different programs ( e.g. FSLDISPLAY=open   for MacOSX)
 
-setenv FSLTCLSH $FSLDIR/bin/fsltclsh
-setenv FSLWISH $FSLDIR/bin/fslwish
+setenv FSLTCLSH tclsh8.4
+setenv FSLWISH wish8.4
 
 # The following variables are used for running code in parallel across
 #  several machines ( i.e. for FDT )
