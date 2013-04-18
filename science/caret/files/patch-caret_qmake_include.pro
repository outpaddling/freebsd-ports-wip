--- caret_qmake_include.pro.orig	2007-06-07 13:38:00.000000000 -0500
+++ caret_qmake_include.pro	2008-04-01 15:05:56.000000000 -0500
@@ -137,20 +137,15 @@
       VTK_LIBS = ../caret_vtk4_classes/libCaretVtk4Classes.a 
    }
    VTK_LIBS += \
-              -L$(VTK_LIB_DIR) \
-	      -lvtkRendering \
-              -lvtkFiltering \
-              -lvtkGenericFiltering \
-              -lvtkImaging \
-              -lvtkGraphics \
-              -lvtkIO \
-              -lvtkMPEG2Encode \
-              -lvtkFiltering \
-              -lvtkCommon \
-              -lvtkjpeg \
-              -lvtkpng \
-              -lvtkexpat \
-              -lvtkzlib
+	      -L$(VTK_LIB_DIR) \
+	      -lvtkFiltering \
+	      -lvtkGenericFiltering \
+	      -lvtkImaging \
+	      -lvtkGraphics \
+	      -lvtkMPEG2Encode \
+	      -lvtkIO \
+	      -lvtkFiltering \
+	      -lvtkCommon
 }
 
 #
@@ -327,12 +322,17 @@
    #
    # QWT libraries
    #
-   QWT_LIBS = -L$(QWT_LIB_DIR) \
-         -lqwt
+   QWT_LIBS = -L$(QWT_LIB_DIR) -lqwt
 
    QMAKE_CXXFLAGS_RELEASE +=  -Wno-deprecated
    QMAKE_CXXFLAGS_DEBUG += -Wno-deprecated
-}
-
-
 
+   #
+   # for FreeBSD systems
+   #
+   exists( /etc/rc.conf ) { 
+      QMAKE_CXXFLAGS_RELEASE +=  -Wno-deprecated 
+      QMAKE_CXXFLAGS_DEBUG += -Wno-deprecated
+      LIBS += -rpath $(LOCALBASE)/lib/qt4/plugins/imageformats
+   }
+}
