--- global.mk.orig	2015-07-16 12:36:45 UTC
+++ global.mk
@@ -12,6 +12,9 @@ LIBUTILS = ./sumalibs/libutils/libutils.
 CC=gcc
 LDFLAGS=
 
+MKDIR	?= mkdir
+INSTALL	?= install
+STRIP	?= strip
 
 ifeq ($(CC),gcc)
         CFLAGS = -O3 -s -DOMP_SUPPORT -fopenmp -w
@@ -42,4 +45,4 @@ default: all
 	$(MAKE) -C ./sumalibs/libfile
 
 ./sumalibs/libutils/libutils.a:
-	$(MAKE) -C ./sumalibs/libutils
\ No newline at end of file
+	$(MAKE) -C ./sumalibs/libutils
