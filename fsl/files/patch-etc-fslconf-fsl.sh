--- etc/fslconf/fsl.sh.orig	Wed Jan 30 09:50:32 2008
+++ etc/fslconf/fsl.sh	Wed Jan 30 09:50:52 2008
@@ -26,8 +26,8 @@
 # The following variables specify paths for programs and can be changed
 #  or replaced by different programs ( e.g. FSLDISPLAY=open   for MacOSX)
 
-FSLTCLSH=$FSLDIR/bin/fsltclsh
-FSLWISH=$FSLDIR/bin/fslwish
+FSLTCLSH=tclsh8.4
+FSLWISH=wish8.4
 
 export FSLTCLSH FSLWISH 
 
