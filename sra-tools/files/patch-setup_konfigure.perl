--- setup/konfigure.perl.orig	2016-12-01 14:08:53.318187808 -0600
+++ setup/konfigure.perl	2016-12-01 14:27:27.387102433 -0600
@@ -196,9 +196,9 @@ $OPT{'prefix'} = $package_default_prefix
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
@@ -213,8 +213,8 @@ if ($OS eq 'linux') {
 
 print "checking machine architecture... " unless ($AUTORUN);
 println $MARCH unless ($AUTORUN);
-unless ($MARCH =~ /x86_64/i || $MARCH =~ /i?86/i) {
-    println "configure: error: unsupported architecture '$OSTYPE'";
+unless ($MARCH =~ /x86_64/i || $MARCH =~ /i?86/i || $MARCH eq 'amd64') {
+    println "configure: error: unsupported architecture '$MARCH'";
     exit 1;
 }
 
@@ -298,7 +298,7 @@ print "checking for supported architectu
 
 my $BITS;
 
-if ($MARCH =~ /x86_64/i) {
+if ($MARCH =~ /x86_64/i || $MARCH eq 'amd64') {
     $BITS = 64;
 } elsif ($MARCH eq 'fat86') {
     $BITS = '32_64';
@@ -313,7 +313,7 @@ println "$MARCH ($BITS bits) is supporte
 my ($LPFX, $OBJX, $LOBX, $LIBX, $SHLX, $EXEX, $OSINC);
 
 print "checking for supported OS... " unless ($AUTORUN);
-if ($OSTYPE =~ /linux/i) {
+if ($OSTYPE =~ /linux/i || $OSTYPE eq 'FreeBSD') {
     $LPFX = 'lib';
     $OBJX = 'o';
     $LOBX = 'pic.o';
