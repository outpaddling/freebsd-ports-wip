--- ngs-python/setup/konfigure.perl.orig	2016-10-07 16:59:36.000000000 -0500
+++ ngs-python/setup/konfigure.perl	2016-12-06 14:54:40.035267343 -0600
@@ -198,7 +198,7 @@ print "checking system type... " unless 
 my ($OS, $ARCH, $OSTYPE, $MARCH, @ARCHITECTURES) = OsArch();
 println $OSTYPE unless ($AUTORUN);
 
-unless ($OSTYPE =~ /linux/i || $OSTYPE =~ /darwin/i || $OSTYPE eq 'win') {
+unless ($OSTYPE =~ /linux/i || $OSTYPE =~ /darwin/i || $OSTYPE eq 'win' || $OSTYPE eq 'FreeBSD') {
     println "configure: error: unsupported system '$OSTYPE'";
     exit 1;
 }
@@ -213,8 +213,8 @@ if ($OS eq 'linux') {
 
 print "checking machine architecture... " unless ($AUTORUN);
 println $MARCH unless ($AUTORUN);
-unless ($MARCH =~ /x86_64/i || $MARCH =~ /i?86/i) {
-    println "configure: error: unsupported architecture '$OSTYPE'";
+unless ($MARCH =~ /amd64/i || $MARCH =~ /i?86/i) {
+    println "configure: error: unsupported architecture '$MARCH'";
     exit 1;
 }
 
@@ -298,7 +298,7 @@ print "checking for supported architectu
 
 my $BITS;
 
-if ($MARCH =~ /x86_64/i) {
+if ($MARCH =~ /amd64/i) {
     $BITS = 64;
 } elsif ($MARCH eq 'fat86') {
     $BITS = '32_64';
@@ -322,6 +322,15 @@ if ($OSTYPE =~ /linux/i) {
     $EXEX = '';
     $OSINC = 'unix';
     $TOOLS = 'gcc' unless ($TOOLS);
+} elsif ($OSTYPE eq 'FreeBSD') {
+    $LPFX = 'lib';
+    $OBJX = 'o';
+    $LOBX = 'pic.o';
+    $LIBX = 'a';
+    $SHLX = 'so';
+    $EXEX = '';
+    $OSINC = 'unix';
+    $TOOLS = 'cc' unless ($TOOLS);
 } elsif ($OSTYPE =~ /darwin/i) {
     $LPFX = 'lib';
     $OBJX = 'o';
@@ -377,7 +386,7 @@ if ($TOOLS =~ /gcc$/) {
         $LP      = "$CPP $versionMin $ARCH_FL";
     } else {
         $MAKE_MANIFEST = '( echo "$^" > $@/manifest )';
-        $ARCH_FL       = '-arch i386 -arch x86_64';
+        $ARCH_FL       = '-arch i386 -arch amd64';
         $OPT    = '-O3';
         $AR     = 'libtool -static -o';
         $LD     = "clang -Wl,-arch_multiple $ARCH_FL -Wl,-all_load";
@@ -400,6 +409,7 @@ if ($TOOLS =~ /gcc$/) {
 
     $DBG = '-g';
 } elsif ($TOOLS eq 'vc++') {
+} elsif ($TOOLS eq 'cc') {
 } else {
     die "unrecognized tool chain '$TOOLS'";
 }
@@ -999,7 +1009,7 @@ EndText
     L($F, 'export CONFIGURE_FOUND_XML2');
     L($F);
 
-    if ($OS eq 'linux' || $OS eq 'mac') {
+    if ($OS eq 'linux' || $OS eq 'mac' || $OS eq 'FreeBSD') {
         L($F, '# installation rules');
         L($F,
         '$(INST_LIBDIR)$(BITS)/%.$(VERSION_LIBX): $(LIBDIR)/%.$(VERSION_LIBX)');
@@ -1031,7 +1041,7 @@ EndText
           T($F, '      rm -f $(patsubst %$(VERSION),%$(MAJVERS),$@) '
                       . '$(patsubst %$(VERSION_SHLX),%$(SHLX),$@);    \\');
         }
-        if ($OS eq 'linux') {
+        if ($OS eq 'linux' || $OS eq 'FreeBSD') {
           T($F, '      ln -s $(@F) $(patsubst %$(VERSION),%$(MAJVERS),$@); \\');
         } elsif ($OS eq 'mac') {
           T($F, '      ln -sf $(@F) '
