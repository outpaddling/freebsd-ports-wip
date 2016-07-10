--- main.cpp.orig	2016-07-10 07:40:58.590408000 -0500
+++ main.cpp	2016-07-10 08:19:11.192625000 -0500
@@ -115,6 +115,10 @@ int main(int argc, char *argv[])
 
     else if (next_option == -1)
     {
+	// Strip file://, added by some file browsers
+	if ( memcmp(argv[1], "file://", 7) == 0 )
+	    memmove(argv[1], argv[1]+7, strlen(argv[1]) - 6);
+	puts(argv[1]);
         MainWindow imageViewer;
         if (QApplication::arguments().size() > 1)
             imageViewer.openImageFromCommandLine(QApplication::arguments());
