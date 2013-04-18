--- src/misc_tcl/webhelp.tcl.orig	Wed Aug 22 10:45:09 2007
+++ src/misc_tcl/webhelp.tcl	Wed Oct 24 14:28:10 2007
@@ -16,7 +16,7 @@
 
     } else {
 
-	foreach executable {firefox mozilla netscape iexplorer opera konquerer galeon amaya mosaic lynx w3m links browsex elinks} {
+	foreach executable {konqueror firefox mozilla netscape iexplorer opera lynx w3m links galeon mosaic amaya browsex elinks} {
 	    set executable [auto_execok $executable]
 	    if [string length $executable] {
 		catch { exec sh -c "$executable -remote \"openURL(${prefix}//${file},new-window)\" || $executable ${prefix}//${file} " 2> /dev/null & }
