--- config/install.py.orig	2016-10-25 10:23:02.355697000 -0500
+++ config/install.py	2016-10-25 10:24:27.982071000 -0500
@@ -76,6 +76,7 @@ class Installer(script.Script):
     self.destIncludeDir    = os.path.join(self.destDir, 'include')
     self.destConfDir       = os.path.join(self.destDir, 'lib','petsc','conf')
     self.destLibDir        = os.path.join(self.destDir, 'lib')
+    self.destLibdataDir    = os.path.join(self.destDir, 'libdata')
     self.destBinDir        = os.path.join(self.destDir, 'bin')
     self.installIncludeDir = os.path.join(self.installDir, 'include')
     self.installBinDir     = os.path.join(self.installDir, 'bin')
@@ -223,7 +224,7 @@ class Installer(script.Script):
     import shutil
     for file in ['rules', 'variables','petscrules', 'petscvariables']:
       self.fixConfFile(os.path.join(self.destConfDir,file))
-    self.fixConfFile(os.path.join(self.destLibDir,'pkgconfig','PETSc.pc'))
+    self.fixConfFile(os.path.join(self.destLibdataDir,'pkgconfig','PETSc.pc'))
     return
 
   def createUninstaller(self):
