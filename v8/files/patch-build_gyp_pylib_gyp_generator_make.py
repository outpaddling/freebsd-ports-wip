--- build/gyp/pylib/gyp/generator/make.py.orig	2020-06-09 20:41:02 UTC
+++ build/gyp/pylib/gyp/generator/make.py
@@ -871,6 +871,7 @@ $(obj).$(TOOLSET)/$(TARGET)/%%.o: $(obj)/%%%s FORCE_DO
         self.WriteLn('quiet_cmd_%s = ACTION %s $@' % (name, name))
       if len(dirs) > 0:
         command = 'mkdir -p %s' % ' '.join(dirs) + '; ' + command
+      command = command.replace('python ', '/usr/local/bin/python2.7 ')
 
       cd_action = 'cd %s; ' % Sourceify(self.path or '.')
 
