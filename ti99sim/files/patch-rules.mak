--- rules.mak.orig	2020-05-25 20:52:22 UTC
+++ rules.mak
@@ -12,23 +12,20 @@ endif
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
+# XLIBS    += -lstdc++fs
 
 WARNINGS := -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers
 WARNINGS += -Wno-implicit-fallthrough
-WARNINGS += -Wno-maybe-uninitialized
+WARNINGS += -Wno-uninitialized
 WARNINGS += -Wcast-qual
 
 INCLUDES := -I../../include
@@ -39,10 +36,6 @@ DEBUG    := 1
 
 ifeq ($(CFG),Debug)
 DEBUG    := 1
-endif
-
-ifdef ARCH
-CFLAGS   += -march=$(ARCH)
 endif
 
 ifdef LTO
