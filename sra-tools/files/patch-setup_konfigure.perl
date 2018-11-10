--- setup/konfigure.perl.orig	2018-07-24 17:46:27 UTC
+++ setup/konfigure.perl
@@ -200,9 +200,9 @@ $OPT{'prefix'} = $package_default_prefix
 my $AUTORUN = $OPT{status};
 print "checking system type... " unless ($AUTORUN);
 my ($OS, $ARCH, $OSTYPE, $MARCH, @ARCHITECTURES) = OsArch();
-println $OSTYPE unless ($AUTORUN);
+println "'$OSTYPE'" unless ($AUTORUN);
 
-unless ($OSTYPE =~ /linux/i || $OSTYPE =~ /darwin/i || $OSTYPE eq 'win') {
+unless ($OSTYPE =~ /linux/i || $OSTYPE =~ /darwin/i || $OSTYPE eq 'win' || $OSTYPE eq 'FreeBSD') {
     println "configure: error: unsupported system '$OSTYPE'";
     exit 1;
 }
@@ -223,8 +223,8 @@ if ($OS eq 'linux') {
 
 print "checking machine architecture... " unless ($AUTORUN);
 println $MARCH unless ($AUTORUN);
-unless ($MARCH =~ /x86_64/i || $MARCH =~ /i?86/i) {
-    println "configure: error: unsupported architecture '$OSTYPE'";
+unless ($MARCH =~ /x86_64/i || $MARCH =~ /i?86/i || $MARCH eq 'amd64') {
+    println "configure: error: unsupported architecture '$MARCH'";
     exit 1;
 }
 
@@ -308,7 +308,7 @@ print "checking for supported architectu
 
 my $BITS;
 
-if ($MARCH =~ /x86_64/i) {
+if ($MARCH =~ /x86_64/i || $MARCH eq 'amd64') {
     $BITS = 64;
 } elsif ($MARCH eq 'fat86') {
     $BITS = '32_64';
@@ -332,6 +332,15 @@ if ($OSTYPE =~ /linux/i) {
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
+    $TOOLS = 'clang' unless ($TOOLS);
 } elsif ($OSTYPE =~ /darwin/i) {
     $LPFX = 'lib';
     $OBJX = 'o';
