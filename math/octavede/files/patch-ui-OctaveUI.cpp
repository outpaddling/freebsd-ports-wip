--- ui/OctaveUI.cpp.orig	2009-05-13 12:33:51.000000000 -0500
+++ ui/OctaveUI.cpp	2012-04-16 14:59:40.000000000 -0500
@@ -38,6 +38,7 @@
 #endif
 
 #include <readline/readline.h>
+#include <sys/param.h>
 
 #include <iostream>
 #include <sstream>
@@ -890,11 +891,12 @@
   
   octave_value up (newdir);
   octave_value_list out = feval ("cd", up, 1);
+  char cwd[MAXPATHLEN+1];
 
   /*
   int cd_ok = octave_env::chdir ("..");
   */
-  newdir = octave_env::getcwd();
+  newdir = getcwd(cwd, MAXPATHLEN);
 
   //int cd_ok = octave_env::chdir (newdir);
   //if( cd_ok && (newdir.compare(olddir)!=0) )
@@ -927,11 +929,12 @@
 {
   octave_value up ("..");
   octave_value_list out = feval ("cd", up, 1);
+  char cwd[MAXPATHLEN+1];
 
   /*
   int cd_ok = octave_env::chdir ("..");
   */
-  std::string newdir = octave_env::getcwd();
+  std::string newdir = getcwd(cwd, MAXPATHLEN);
   
   //if( cd_ok )
   {
