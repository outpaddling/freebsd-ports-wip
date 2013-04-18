--- caret_files/SpecFile.h.orig	2008-10-28 11:16:18.000000000 -0500
+++ caret_files/SpecFile.h	2008-11-23 15:52:06.000000000 -0600
@@ -808,11 +808,11 @@
       // update the allEntries vector
       void updateAllEntries();
       
-      static QString SpecFile::getXmlFileTagName1() { return "file1"; }
+      static QString getXmlFileTagName1() { return "file1"; }
          
-      static QString SpecFile::getXmlFileTagName2() { return "file2"; }
+      static QString getXmlFileTagName2() { return "file2"; }
        
-      static QString SpecFile::getXmlFileTagStructure() { return "structure"; }
+      static QString getXmlFileTagStructure() { return "structure"; }
 
       /// only write selected files flag
       bool writeOnlySelectedFiles;
