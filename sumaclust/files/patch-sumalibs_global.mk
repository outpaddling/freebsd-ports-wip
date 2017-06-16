--- sumalibs/global.mk.orig	2017-03-06 11:59:25.317874611 -0600
+++ sumalibs/global.mk	2017-03-06 11:59:37.670886446 -0600
@@ -1,8 +1,8 @@
 
-CC=gcc
+CC?=gcc
 LDFLAGS=
 
-CFLAGS = -O3 -w
+CFLAGS ?= -O3 -w
 
 default: all
 
