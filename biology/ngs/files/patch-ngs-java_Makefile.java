--- ngs-java/Makefile.java.orig	2016-10-07 16:59:36.000000000 -0500
+++ ngs-java/Makefile.java	2016-12-06 15:31:59.187111197 -0600
@@ -57,7 +57,7 @@ all std: $(TARGETS)
 
 PROFILE_FILE = $(ROOT)/etc/profile.d/ngs-java
 JAR_TARGET = $(INST_JARDIR)/ngs-java.jar
-DOC_TARGET = $(INST_SHAREDIR)/doc/
+DOC_TARGET = $(INST_SHAREDIR)/doc/ngs
 
 ifeq (linux, $(OS))
     ifeq (0, $(shell id -u))
@@ -102,17 +102,17 @@ $(INST_JARDIR)/ngs-java.jar.$(VERSION): 
 	  fi
 
 ifeq ($(OS),mac)
-    SED = sed -ibak
+    SED = gsed -ibak
 else
-    SED = sed -i
+    SED = gsed -i
 endif
 
 copyexamples:
-	@ echo "Installing examples to $(INST_SHAREDIR)/examples-java..."
-	@ mkdir -p $(INST_SHAREDIR)/examples-java
-	@ cp $(TOP)/examples/Makefile $(INST_SHAREDIR)/examples-java
-	@ $(SED) "s/NGS_CLASS_PATH = ../NGS_CLASS_PATH = $(subst /,\\/,$(INST_JARDIR)/ngs-java.jar)/" $(INST_SHAREDIR)/examples-java/Makefile
-	@ cp -r $(TOP)/examples/examples $(INST_SHAREDIR)/examples-java
+	@ echo "Installing examples to $(INST_SHAREDIR)/examples/ngs/examples-java..."
+	@ mkdir -p $(INST_SHAREDIR)/examples/ngs/examples-java
+	@ cp $(TOP)/examples/Makefile $(INST_SHAREDIR)/examples/ngs/examples-java
+	@ $(SED) "s/NGS_CLASS_PATH = ../NGS_CLASS_PATH = $(subst /,\\/,$(INST_JARDIR)/ngs-java.jar)/" $(INST_SHAREDIR)/examples/ngs/examples-java/Makefile
+	@ cp -r $(TOP)/examples/examples $(INST_SHAREDIR)/examples/ngs/examples-java
 
 copydocs:
 	@ echo "Copying html docs to $(DOC_TARGET)..."
@@ -120,7 +120,7 @@ copydocs:
 	@ cp -r $(LIBDIR)/javadoc/* $(DOC_TARGET)
 
 
-TO_UNINSTALL = $(INST_JARDIR)/ngs-java.jar* $(DOC_TARGET) $(INST_SHAREDIR)/examples-java
+TO_UNINSTALL = $(INST_JARDIR)/ngs-java.jar* $(DOC_TARGET) $(INST_SHAREDIR)/examples/ngs/examples-java
 TO_UNINSTALL_AS_ROOT = $(PROFILE_FILE).sh $(PROFILE_FILE).csh
 
 uninstall:
