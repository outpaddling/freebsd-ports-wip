--- lumina-checkpass/lumina-checkpass.pro.orig	2022-03-02 23:57:15 UTC
+++ lumina-checkpass/lumina-checkpass.pro
@@ -6,13 +6,13 @@ QT = 
 CONFIG += console
 
 TARGET = lumina-checkpass
-target.path = $$DESTDIR$${PREFIX}/sbin
+target.path = ${DESTDIR}${PREFIX}/sbin
 
 LIBS     += -lpam
 
 SOURCES += main.c
 
-perms.path = $$DESTDIR$${PREFIX}/sbin
-perms.extra = "chmod 4555 $$DESTDIR$${PREFIX}/sbin/lumina-checkpass"
+perms.path = ${DESTDIR}${PREFIX}/sbin
+perms.extra = "chmod 4555 ${DESTDIR}${PREFIX}/sbin/lumina-checkpass"
 
 INSTALLS += target perms
