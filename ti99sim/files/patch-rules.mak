--- rules.mak.orig	2020-05-25 20:52:22 UTC
+++ rules.mak
@@ -12,23 +12,21 @@ endif
 CXX      := g++
 endif
 
-ifneq (,$(findstring /,$(shell whereis ccache)))
-CXX      := ccache $(CXX)
-endif
-
 CFLAGS   += --std=c++2a
 CFLAGS   += -fno-strict-aliasing -fexceptions -fPIC
 CFLAGS   += -fdata-sections -ffunction-sections
 CFLAGS   += -funsigned-char
+CFLAGS   += -Wno-deprecated-declarations
 
 LFLAGS   += -Wl,--gc-sections
 LFLAGS   += -rdynamic
 
-XLIBS    += -lstdc++fs
+# This is redundant, defined in rules.mk
+# XLIBS    += -lstdc++fs
 
 WARNINGS := -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers
 WARNINGS += -Wno-implicit-fallthrough
-WARNINGS += -Wno-maybe-uninitialized
+WARNINGS += -Wno-uninitialized
 WARNINGS += -Wcast-qual
 
 INCLUDES := -I../../include
@@ -74,6 +72,9 @@ OS       := OS_LINUX
 
 ifeq ($(OSTYPE),Linux)
 OS       := OS_LINUX
+ifneq (,$(findstring /,$(shell whereis ccache)))
+CXX      := ccache $(CXX)
+endif
 endif
 
 ifeq ($(OSTYPE),FreeBSD)
