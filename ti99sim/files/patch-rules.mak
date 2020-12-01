--- rules.mak.orig	2020-05-25 20:52:22 UTC
+++ rules.mak
@@ -12,10 +12,6 @@ ifndef CXX
 CXX      := g++
 endif
 
-ifneq (,$(findstring /,$(shell whereis ccache)))
-CXX      := ccache $(CXX)
-endif
-
 CFLAGS   += --std=c++2a
 CFLAGS   += -fno-strict-aliasing -fexceptions -fPIC
 CFLAGS   += -fdata-sections -ffunction-sections
@@ -39,10 +35,6 @@ endif
 
 ifeq ($(CFG),Debug)
 DEBUG    := 1
-endif
-
-ifdef ARCH
-CFLAGS   += -march=$(ARCH)
 endif
 
 ifdef LTO
