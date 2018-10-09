--- GEMTools/Makefile.mk.orig	2018-10-09 01:15:55 UTC
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
@@ -29,7 +29,7 @@ HAVE_ZLIB = 1
 HAVE_BZLIB = 1
 HAVE_OPENMP = 1
 
-GENERAL_FLAGS=-fPIC -Wall
+GENERAL_FLAGS=-fPIC -Wall -std=gnu89
 ifeq ($(HAVE_ZLIB),1)
 GENERAL_FLAGS:=$(GENERAL_FLAGS) -DHAVE_ZLIB
 endif
