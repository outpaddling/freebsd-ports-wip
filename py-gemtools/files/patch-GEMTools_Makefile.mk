--- GEMTools/Makefile.mk.orig	2013-11-18 12:12:33 UTC
+++ GEMTools/Makefile.mk
@@ -7,8 +7,8 @@
 #==================================================================================================
 
 # Utilities
-CC=gcc
-AR=ar
+CC?=gcc
+AR?=ar
 
 # Folders
 FOLDER_BIN=$(ROOT_PATH)/bin
@@ -24,12 +24,12 @@ FOLDER_TEST=$(ROOT_PATH)/test
 FOLDER_TOOLS=$(ROOT_PATH)/tools
 
 # Flags
-ARCH_FLAGS = -D__LINUX__
+ARCH_FLAGS ?= -D__LINUX__
 HAVE_ZLIB = 1
 HAVE_BZLIB = 1
 HAVE_OPENMP = 1
 
-GENERAL_FLAGS=-fPIC -Wall
+GENERAL_FLAGS=-fPIC -Wall $(CFLAGS)
 ifeq ($(HAVE_ZLIB),1)
 GENERAL_FLAGS:=$(GENERAL_FLAGS) -DHAVE_ZLIB
 endif
@@ -40,7 +40,8 @@ ifeq ($(HAVE_OPENMP),1)
 GENERAL_FLAGS:=$(GENERAL_FLAGS) -DHAVE_OPENMP
 endif
 
-OPTIMIZTION_FLAGS=-O4 # -fomit-frame-pointer -ftree-vectorize
+# Get this from CFLAGS
+# OPTIMIZTION_FLAGS=-O4 # -fomit-frame-pointer -ftree-vectorize
 ARCH_FLAGS_OPTIMIZTION_FLAGS= # -msse3 -mssse3 -msse4.2
 
 INCLUDE_FLAGS=-I$(FOLDER_INCLUDE) -I$(FOLDER_RESOURCES_INCLUDE)
