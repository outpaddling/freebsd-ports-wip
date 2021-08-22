--- setup/konfigure.perl.orig	2021-08-22 14:28:49 UTC
+++ setup/konfigure.perl
@@ -225,7 +225,7 @@ if ($OS eq 'linux') {
 
 print "checking machine architecture... " unless ($AUTORUN);
 println $MARCH unless ($AUTORUN);
-unless ($MARCH =~ /x86_64/i || $MARCH =~ /i?86/i || $MARCH =~ /aarch64/) {
+unless ($MARCH =~ /x86_64/i || $MARCH =~ /amd64/i || $MARCH =~ /i?86/i || $MARCH =~ /aarch64/) {
     println "configure: error: unsupported architecture '$OSTYPE':'$MARCH'";
     exit 1;
 }
@@ -310,7 +310,7 @@ print "checking for supported architecture... " unless
 
 my $BITS;
 
-if ($MARCH =~ /x86_64/i) {
+if ($MARCH =~ /x86_64/i) || ($MARCH =~ /amd64/i) {
     $BITS = 64;
 } elsif ($MARCH eq 'fat86') {
     $BITS = '32_64';
@@ -337,6 +337,16 @@ if ($OSTYPE =~ /linux/i) {
     $OSINC = 'unix';
     $TOOLS = 'gcc' unless ($TOOLS);
     $PYTHON = 'python';
+} elsif ($OSTYPE =~ /freebsd/i) {
+    $LPFX = 'lib';
+    $OBJX = 'o';
+    $LOBX = 'pic.o';
+    $LIBX = 'a';
+    $SHLX = 'so';
+    $EXEX = '';
+    $OSINC = 'unix';
+    $TOOLS = 'clang' unless ($TOOLS);
+    $PYTHON = 'python';
 } elsif ($OSTYPE =~ /darwin/i) {
     $LPFX = 'lib';
     $OBJX = 'o';
@@ -524,7 +534,7 @@ foreach my $href (DEPENDS()) {
             $I = $t if (-e $t);
         }
         push ( @L, File::Spec->catdir($OPT{$o}, 'lib') );
-        push ( @L, File::Spec->catdir($OPT{$o}, 'lib64') );
+        # push ( @L, File::Spec->catdir($OPT{$o}, 'lib64') );
     }
     my ($i, $l) = find_lib($_, $I, @L);
     if (defined $i || $l) {
@@ -946,7 +956,7 @@ EndText
     if ($PKG{LNG} eq 'C') {
         if ($TOOLS =~ /clang/i) {
    L($F, 'SONAME  = -install_name ' .
-               '$(INST_LIBDIR)$(BITS)/$(subst $(VERSION),$(MAJVERS),$(@F)) \\');
+               '$(INST_LIBDIR)/$(subst $(VERSION),$(MAJVERS),$(@F)) \\');
    L($F, '    -compatibility_version $(MAJMIN) -current_version $(VERSION) \\');
    L($F, '    -flat_namespace -undefined suppress');
         } else {
@@ -1055,7 +1065,7 @@ EndText
     L($F, '# directory rules');
     if ($PKG{LNG} eq 'C') {
         L($F, '$(BINDIR) $(LIBDIR) $(ILIBDIR) '
-            . '$(OBJDIR) $(INST_LIBDIR) $(INST_LIBDIR)$(BITS):');
+            . '$(OBJDIR) $(INST_LIBDIR) $(INST_LIBDIR):');
         T($F, 'mkdir -p $@');
     } elsif ($PKG{LNG} eq 'JAVA') {
         # test if we have jni header path
@@ -1088,7 +1098,7 @@ EndText
     if ($OS eq 'linux' || $OS eq 'mac') {
         L($F, '# installation rules');
         L($F,
-        '$(INST_LIBDIR)$(BITS)/%.$(VERSION_LIBX): $(LIBDIR)/%.$(VERSION_LIBX)');
+        '$(INST_LIBDIR)/%.$(VERSION_LIBX): $(LIBDIR)/%.$(VERSION_LIBX)');
         T($F, '@ echo -n "installing \'$(@F)\'... "');
         T($F, '@ if cp $^ $@ && chmod 644 $@;                         \\');
         T($F, '  then                                                 \\');
@@ -1099,7 +1109,7 @@ EndText
         T($F, '      ln -s $(patsubst %$(VERSION),%$(MAJVERS),$(@F)) '
                       . '$(patsubst %$(VERSION_LIBX),%$(LIBX),$@); \\');
         T($F, '      ln -s $(patsubst %$(VERSION_LIBX),%$(LIBX),$(@F)) ' .
-   '$(INST_LIBDIR)$(BITS)/$(patsubst %.$(VERSION_LIBX),%-static.$(LIBX),$(@F));'
+   '$(INST_LIBDIR)/$(patsubst %.$(VERSION_LIBX),%-static.$(LIBX),$(@F));'
                                                               . ' \\');
         T($F, '      echo success;                                    \\');
         T($F, '  else                                                 \\');
@@ -1109,7 +1119,7 @@ EndText
         L($F);
 
         L($F,
-        '$(INST_LIBDIR)$(BITS)/%.$(VERSION_SHLX): $(LIBDIR)/%.$(VERSION_SHLX)');
+        '$(INST_LIBDIR)/%.$(VERSION_SHLX): $(LIBDIR)/%.$(VERSION_SHLX)');
         T($F, '@ echo -n "installing \'$(@F)\'... "');
         T($F, '@ if cp $^ $@ && chmod 755 $@;                         \\');
         T($F, '  then                                                 \\');
@@ -1179,7 +1189,7 @@ EndText
 	    print $F "    \$_{MAJVERS_EXEX } = '" . expand($E_MAJVERS_EXEX) . "';\n";
 	    print $F "    \$_{INCDIR       } = '" . expand("$Bin/.."      ) . "';\n";
 	    if ($PKG{LNG} ne 'PYTHON') {
-	        print $F "  \$_{BINDIR$BITS} = '" . expand($E_BINDIR      ) . "';\n";
+	        print $F "  \$_{BINDIR} = '" . expand($E_BINDIR      ) . "';\n";
 	        print $F "  \$_{LIBDIR$BITS} = '" . expand($E_LIBDIR      ) . "';\n";
 	    } elsif ($OPT{PYTHON_LIB_PATH}) {
 	        print $F "  \$_{LIBDIR$BITS} = '$OPT{PYTHON_LIB_PATH}';\n";
@@ -1418,7 +1428,7 @@ sub find_in_dir {
                 ++$found;
             }
             if (! $found) {
-                my $libdir = File::Spec->catdir($dir, 'lib' . $BITS);
+                my $libdir = File::Spec->catdir($dir, 'lib');
                 my $f = File::Spec->catdir($libdir, $lib);
                 print "\tchecking $f\n\t" if ($OPT{'debug'});
                 if (-e $f) {
