--- clustalx.pro.orig	2019-03-20 14:46:33 UTC
+++ clustalx.pro
@@ -6,6 +6,7 @@ TEMPLATE = app
 TARGET = clustalx
 CONFIG += release static
 QT += xml
+QT += widgets
 VERSION = 2.1
 win32 {
    DEFINES += OS_WINDOWS
