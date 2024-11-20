--- src/slic3r/GUI/GUI_Utils.cpp
+++ src/slic3r/GUI/GUI_Utils.cpp
@@ -106,7 +106,7 @@ int get_dpi_for_window(wxWindow *window)
         if (hdc == NULL) { return DPI_DEFAULT; }
         return GetDeviceCaps(hdc, LOGPIXELSX);
     }
-#elif defined __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
     // TODO
     return DPI_DEFAULT;
 #elif defined __APPLE__
