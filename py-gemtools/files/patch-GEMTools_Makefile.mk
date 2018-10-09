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
