--- ncbi-vdb/setup/konfigure.perl.orig	2021-08-17 18:53:09 UTC
+++ ncbi-vdb/setup/konfigure.perl
@@ -192,7 +192,7 @@ if ($OPT{'help'}) {
 foreach (@ARGV) {
     @_ = split('=');
     next if ($#_ != 1);
-    $OPT{$_[0]} = $_[1] if ($_[0] eq 'CXX' || $_[0] eq 'LDFLAGS');
+    $OPT{$_[0]} = $_[1] if ($_[0] eq 'CC' || $_[0] eq 'CXX' || $_[0] eq 'LDFLAGS');
 }
 
 println "Configuring $PACKAGE_NAME package";
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
+if ($MARCH =~ /(x86_|amd)64/i) {
     $BITS = 64;
 } elsif ($MARCH eq 'fat86') {
     $BITS = '32_64';
@@ -337,6 +337,19 @@ if ($OSTYPE =~ /linux/i) {
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
+    unless ($TOOLS) {
+        $TOOLS = 'clang';
+        $TOOLS = $OPT{TOOLS} if ($OPT{TOOLS});
+    }
+    $PYTHON = $ENV{FREEBSD_PYTHON_CMD};
 } elsif ($OSTYPE =~ /darwin/i) {
     $LPFX = 'lib';
     $OBJX = 'o';
@@ -362,17 +375,19 @@ my ($ARCH_FL, $DBG, $OPT, $PIC, $INC, $MD, $LDFLAGS) =
 
 print "checking for supported tool chain... " unless ($AUTORUN);
 
+$CC      = $OPT{CC     } if ($OPT{CC     });
 $CPP     = $OPT{CXX    } if ($OPT{CXX    });
 $LDFLAGS = $OPT{LDFLAGS} if ($OPT{LDFLAGS});
 
 if ($TOOLS =~ /gcc$/) {
     $CPP  = 'g++' unless ($CPP);
-    $CC   = "$TOOLS -c";
+    $CC   = 'gcc' unless ($CC);
+    $LD   = $CC;
+    $CC   = "$CC -c";
     $CP   = "$CPP -c";
     $AR   = 'ar rc';
     $ARX  = 'ar x';
     $ARLS = 'ar t';
-    $LD   = $TOOLS;
     $LP   = $CPP;
 
     $DBG = '-g -DDEBUG';
@@ -382,21 +397,24 @@ if ($TOOLS =~ /gcc$/) {
     $MD  = '-MD';
 } elsif ($TOOLS eq 'clang') {
     $CPP  = 'clang++' unless ($CPP);
-    $CC   = 'clang -c';
-    my $versionMin = '-mmacosx-version-min=10.10';
+    $CC   = 'clang' unless ($CC);
+    $LD   = $CC;
+    $CC   = "$CC -c";
+    my $versionMin = '';
+    $versionMin = '-mmacosx-version-min=10.6' if ($OSTYPE =~ /darwin/i);
     $CP   = "$CPP -c $versionMin";
     if ($BITS ne '32_64') {
         $ARCH_FL = '-arch i386' if ($BITS == 32);
         $OPT = '-O3';
         $AR      = 'ar rc';
-        $LD      = "clang $ARCH_FL";
+        $LD      = "$LD $ARCH_FL";
         $LP      = "$CPP $versionMin $ARCH_FL";
     } else {
         $MAKE_MANIFEST = '( echo "$^" > $@/manifest )';
         $ARCH_FL       = '-arch i386 -arch x86_64';
         $OPT    = '-O3';
         $AR     = 'libtool -static -o';
-        $LD     = "clang -Wl,-arch_multiple $ARCH_FL -Wl,-all_load";
+        $LD     = "$LD -Wl,-arch_multiple $ARCH_FL -Wl,-all_load";
         $LP     = "$CPP $versionMin -Wl,-arch_multiple $ARCH_FL -Wl,-all_load";
     }
     $ARX  = 'ar x';
@@ -838,14 +856,13 @@ OS_ARCH = \$(shell perl \$(TOP)/setup/os-arch.perl)
 # install paths
 EndText
 
-    L($F, "INST_BINDIR = $OPT{'bindir'}"      ) if ($OPT{'bindir'});
-    L($F, "INST_LIBDIR = $OPT{'libdir'}"      ) if ($OPT{'libdir'});
-    L($F, "INST_INCDIR = $OPT{'includedir'}"  ) if ($OPT{'includedir'});
-    L($F, "INST_SCHEMADIR = $OPT{'shemadir'}" ) if ($OPT{'shemadir'});
-    L($F, "INST_SHAREDIR = $OPT{'sharedir'}"  ) if ($OPT{'sharedir'});
-    L($F, "INST_JARDIR = $OPT{'javadir'}"     ) if ($OPT{'javadir'});
-    L($F, "INST_PYTHONDIR = $OPT{'pythondir'}") if ($OPT{'pythondir'});
-
+    L($F, "INST_BINDIR = \$(DESTDIR)$OPT{'bindir'}"      ) if ($OPT{'bindir'});
+    L($F, "INST_LIBDIR = \$(DESTDIR)$OPT{'libdir'}"      ) if ($OPT{'libdir'});
+    L($F, "INST_INCDIR = \$(DESTDIR)$OPT{'includedir'}"  ) if ($OPT{'includedir'});
+    L($F, "INST_SCHEMADIR = \$(DESTDIR)$OPT{'shemadir'}" ) if ($OPT{'shemadir'});
+    L($F, "INST_SHAREDIR = \$(DESTDIR)$OPT{'sharedir'}"  ) if ($OPT{'sharedir'});
+    L($F, "INST_JARDIR = \$(DESTDIR)$OPT{'javadir'}"     ) if ($OPT{'javadir'});
+    L($F, "INST_PYTHONDIR = \$(DESTDIR)$OPT{'pythondir'}") if ($OPT{'pythondir'});
     my ($E_VERSION_SHLX, $VERSION_SHLX,
         $E_MAJVERS_SHLX , $MAJMIN_SHLX, $MAJVERS_SHLX);
     if ($OSTYPE =~ /darwin/i) {
@@ -908,7 +925,7 @@ MAJMIN_EXEX  = \$(EXEX).\$(MAJMIN)
 MAJVERS_EXEX = \$(EXEX).\$(MAJVERS)
 
 # system architecture and wordsize
-ARCH = $ARCH
+override ARCH = $ARCH
 EndText
 
     L($F, "# ARCH = $ARCH ( $MARCH )") if ($ARCH ne $MARCH);
@@ -944,7 +961,7 @@ EndText
     }
     L($F, "PIC     = $PIC") if ($PIC);
     if ($PKG{LNG} eq 'C') {
-        if ($TOOLS =~ /clang/i) {
+        if ($OSTYPE =~ /darwin/i) {
    L($F, 'SONAME  = -install_name ' .
                '$(INST_LIBDIR)$(BITS)/$(subst $(VERSION),$(MAJVERS),$(@F)) \\');
    L($F, '    -compatibility_version $(MAJMIN) -current_version $(VERSION) \\');
@@ -1055,7 +1072,7 @@ EndText
     L($F, '# directory rules');
     if ($PKG{LNG} eq 'C') {
         L($F, '$(BINDIR) $(LIBDIR) $(ILIBDIR) '
-            . '$(OBJDIR) $(INST_LIBDIR) $(INST_LIBDIR)$(BITS):');
+            . '$(OBJDIR) $(INST_LIBDIR):');
         T($F, 'mkdir -p $@');
     } elsif ($PKG{LNG} eq 'JAVA') {
         # test if we have jni header path
@@ -1085,12 +1102,12 @@ EndText
     L($F, 'export CONFIGURE_FOUND_XML2');
     L($F);
 
-    if ($OS eq 'linux' || $OS eq 'mac') {
+    if ($OS eq 'linux' || $OS eq 'bsd' || $OS eq 'mac') {
         L($F, '# installation rules');
         L($F,
-        '$(INST_LIBDIR)$(BITS)/%.$(VERSION_LIBX): $(LIBDIR)/%.$(VERSION_LIBX)');
+        '$(INST_LIBDIR)/%.$(VERSION_LIBX): $(LIBDIR)/%.$(VERSION_LIBX)');
         T($F, '@ echo -n "installing \'$(@F)\'... "');
-        T($F, '@ if cp $^ $@ && chmod 644 $@;                         \\');
+        T($F, '@ if ${BSD_INSTALL_DATA} $^ $@ && chmod 644 $@;                         \\');
         T($F, '  then                                                 \\');
         T($F, '      rm -f $(patsubst %$(VERSION),%$(MAJVERS),$@) '
                      . '$(patsubst %$(VERSION_LIBX),%$(LIBX),$@) '
@@ -1099,7 +1116,7 @@ EndText
         T($F, '      ln -s $(patsubst %$(VERSION),%$(MAJVERS),$(@F)) '
                       . '$(patsubst %$(VERSION_LIBX),%$(LIBX),$@); \\');
         T($F, '      ln -s $(patsubst %$(VERSION_LIBX),%$(LIBX),$(@F)) ' .
-   '$(INST_LIBDIR)$(BITS)/$(patsubst %.$(VERSION_LIBX),%-static.$(LIBX),$(@F));'
+   '$(INST_LIBDIR)/$(patsubst %.$(VERSION_LIBX),%-static.$(LIBX),$(@F));'
                                                               . ' \\');
         T($F, '      echo success;                                    \\');
         T($F, '  else                                                 \\');
@@ -1109,15 +1126,15 @@ EndText
         L($F);
 
         L($F,
-        '$(INST_LIBDIR)$(BITS)/%.$(VERSION_SHLX): $(LIBDIR)/%.$(VERSION_SHLX)');
+        '$(INST_LIBDIR)/%.$(VERSION_SHLX): $(LIBDIR)/%.$(VERSION_SHLX)');
         T($F, '@ echo -n "installing \'$(@F)\'... "');
-        T($F, '@ if cp $^ $@ && chmod 755 $@;                         \\');
+        T($F, '@ if ${BSD_INSTALL_LIB} $^ $@ && chmod 755 $@;                         \\');
         T($F, '  then                                                 \\');
         if ($OS ne 'mac') {
           T($F, '      rm -f $(patsubst %$(VERSION),%$(MAJVERS),$@) '
                       . '$(patsubst %$(VERSION_SHLX),%$(SHLX),$@);    \\');
         }
-        if ($OS eq 'linux') {
+        if ($OS eq 'linux' || $OS eq 'bsd') {
           T($F, '      ln -s $(@F) $(patsubst %$(VERSION),%$(MAJVERS),$@); \\');
         } elsif ($OS eq 'mac') {
           T($F, '      ln -sf $(@F) '
@@ -1136,7 +1153,7 @@ EndText
 
         L($F, '$(INST_BINDIR)/%$(VERSION_EXEX): $(BINDIR)/%$(VERSION_EXEX)');
         T($F, '@ echo -n "installing \'$(@F)\'... "');
-        T($F, '@ if cp $^ $@ && chmod 755 $@;                         \\');
+        T($F, '@ if ${BSD_INSTALL_PROGRAM} $^ $@ && chmod 755 $@;                         \\');
         T($F, '  then                                                 \\');
         T($F, '      rm -f $(patsubst %$(VERSION),%$(MAJVERS),$@) '
                       . '$(patsubst %$(VERSION_EXEX),%$(EXEX),$@);     \\');
@@ -1418,7 +1435,7 @@ sub find_in_dir {
                 ++$found;
             }
             if (! $found) {
-                my $libdir = File::Spec->catdir($dir, 'lib' . $BITS);
+                my $libdir = File::Spec->catdir($dir, 'lib');
                 my $f = File::Spec->catdir($libdir, $lib);
                 print "\tchecking $f\n\t" if ($OPT{'debug'});
                 if (-e $f) {
@@ -1640,12 +1657,12 @@ sub find_lib {
 
 sub check_compiler {
     my ($t, $n, $I, @l) = @_;
-    my $tool = $TOOLS;
+    my $tool = $CC;
 
     if ($t eq 'L') {
         print "checking for $n library... ";
     } elsif ($t eq 'O') {
-        if ($tool && ($tool =~ /gcc$/ || $tool =~ /g\+\+$/)) {
+        if ($tool && ($tool =~ /gcc/ || $tool =~ /g\+\+/)) {
             print "checking whether $tool accepts $n... ";
         } else {
             return;
@@ -1718,7 +1735,7 @@ sub check_compiler {
                 }
             }
             my $gcc = "| $tool -xc $flags " . ($I ? "-I$I " : ' ')
-                                      . ($l ? "-L$l " : ' ') . "- $library";
+                                      . ($l ? "-L$l " : ' ') . "-o a.out - $library";
             $gcc .= ' 2> /dev/null' unless ($OPT{'debug'});
 
             open GCC, $gcc or last;
