--- config/PETSc/Configure.py.orig	2016-10-25 11:16:20.346685000 -0500
+++ config/PETSc/Configure.py	2016-10-25 11:17:04.368713000 -0500
@@ -149,9 +149,9 @@ class Configure(config.base.Configure):
 
   def DumpPkgconfig(self):
     ''' Create a pkg-config file '''
-    if not os.path.exists(os.path.join(self.petscdir.dir,self.arch.arch,'lib','pkgconfig')):
-      os.makedirs(os.path.join(self.petscdir.dir,self.arch.arch,'lib','pkgconfig'))
-    fd = open(os.path.join(self.petscdir.dir,self.arch.arch,'lib','pkgconfig','PETSc.pc'),'w')
+    if not os.path.exists(os.path.join(self.petscdir.dir,self.arch.arch,'libdata','pkgconfig')):
+      os.makedirs(os.path.join(self.petscdir.dir,self.arch.arch,'libdata','pkgconfig'))
+    fd = open(os.path.join(self.petscdir.dir,self.arch.arch,'libdata','pkgconfig','PETSc.pc'),'w')
     if self.framework.argDB['prefix']:
       fd.write('prefix='+self.installdir.dir+'\n')
       fd.write('exec_prefix=${prefix}\n')
