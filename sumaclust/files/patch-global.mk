--- global.mk.orig	2015-07-16 07:36:45.000000000 -0500
+++ global.mk	2017-03-06 11:56:45.503093472 -0600
@@ -9,15 +9,18 @@ LIBLCS   = ./sumalibs/liblcs/liblcs.a
 LIBFILE  = ./sumalibs/libfile/libfile.a
 LIBUTILS = ./sumalibs/libutils/libutils.a
 
-CC=gcc
-LDFLAGS=
+CC?=gcc
+#LDFLAGS=
 
+MKDIR	?= mkdir
+INSTALL	?= install
+STRIP	?= strip
 
-ifeq ($(CC),gcc)
-        CFLAGS = -O3 -s -DOMP_SUPPORT -fopenmp -w
-else
-        CFLAGS = -O3 -w
-endif
+#ifeq ($(CC),gcc)
+        CFLAGS += -s -DOMP_SUPPORT -fopenmp -w
+#else
+        #CFLAGS = -O3 -w
+#endif
 
 
 default: all
@@ -42,4 +45,4 @@ default: all
 	$(MAKE) -C ./sumalibs/libfile
 
 ./sumalibs/libutils/libutils.a:
-	$(MAKE) -C ./sumalibs/libutils
\ No newline at end of file
+	$(MAKE) -C ./sumalibs/libutils
