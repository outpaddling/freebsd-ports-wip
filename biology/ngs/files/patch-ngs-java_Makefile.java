--- ngs-java/Makefile.java.orig	2016-12-06 13:17:36.829430000 -0600
+++ ngs-java/Makefile.java	2016-12-06 13:17:53.416098000 -0600
@@ -102,9 +102,9 @@ $(INST_JARDIR)/ngs-java.jar.$(VERSION): 
 	  fi
 
 ifeq ($(OS),mac)
-    SED = sed -ibak
+    SED = gsed -ibak
 else
-    SED = sed -i
+    SED = gsed -i
 endif
 
 copyexamples:
