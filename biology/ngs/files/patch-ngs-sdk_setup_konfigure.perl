--- ngs-sdk/setup/konfigure.perl.orig	2016-12-01 14:37:54.744063653 -0600
+++ ngs-sdk/setup/konfigure.perl	2016-12-01 14:40:59.721050742 -0600
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
