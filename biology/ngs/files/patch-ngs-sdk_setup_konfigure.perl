--- ngs-sdk/setup/konfigure.perl.orig	2016-10-07 16:59:36.000000000 -0500
+++ ngs-sdk/setup/konfigure.perl	2016-12-01 17:48:02.080526000 -0600
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
@@ -312,6 +312,11 @@ println "$MARCH ($BITS bits) is supporte
 # determine OS and related norms
 my ($LPFX, $OBJX, $LOBX, $LIBX, $SHLX, $EXEX, $OSINC);
 
+# tool chain
+my ($CPP, $CC, $CP, $AR, $ARX, $ARLS, $LD, $LP, $MAKE_MANIFEST);
+my ($JAVAC, $JAVAH, $JAR);
+my ($ARCH_FL, $DBG, $OPT, $PIC, $INC, $MD, $LDFLAGS) = ('');
+
 print "checking for supported OS... " unless ($AUTORUN);
 if ($OSTYPE =~ /linux/i) {
     $LPFX = 'lib';
@@ -322,6 +327,30 @@ if ($OSTYPE =~ /linux/i) {
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
+
+    $CPP  = 'c++' unless ($CPP);
+    $CC   = "$TOOLS -c";
+    $CP   = "$CPP -c";
+    $AR   = 'ar rc';
+    $ARX  = 'ar x';
+    $ARLS = 'ar t';
+    $LD   = $TOOLS;
+    $LP   = $CPP;
+
+    $DBG = '-g -DDEBUG';
+    $OPT = '-O2';
+    $PIC = '-fPIC';
+    $INC = '-I';
+    $MD  = '-MD';
 } elsif ($OSTYPE =~ /darwin/i) {
     $LPFX = 'lib';
     $OBJX = 'o';
@@ -339,11 +368,6 @@ if ($OSTYPE =~ /linux/i) {
 
 println "$OSTYPE ($OS) is supported" unless ($AUTORUN);
 
-# tool chain
-my ($CPP, $CC, $CP, $AR, $ARX, $ARLS, $LD, $LP, $MAKE_MANIFEST);
-my ($JAVAC, $JAVAH, $JAR);
-my ($ARCH_FL, $DBG, $OPT, $PIC, $INC, $MD, $LDFLAGS) = ('');
-
 print "checking for supported tool chain... " unless ($AUTORUN);
 
 $CPP     = $OPT{CXX    } if ($OPT{CXX    });
@@ -364,7 +388,7 @@ if ($TOOLS =~ /gcc$/) {
     $PIC = '-fPIC';
     $INC = '-I';
     $MD  = '-MD';
-} elsif ($TOOLS eq 'clang') {
+} elsif ($OSTYPE =~ /darwin/i && $TOOLS eq 'clang') {
     $CPP  = 'clang++' unless ($CPP);
     $CC   = 'clang -c';
     my $versionMin = '-mmacosx-version-min=10.6';
@@ -399,7 +423,7 @@ if ($TOOLS =~ /gcc$/) {
     $JAR   = 'jar cf';
 
     $DBG = '-g';
-} elsif ($TOOLS eq 'vc++') {
+} elsif ($TOOLS eq 'vc++' || $TOOLS eq 'cc') {
 } else {
     die "unrecognized tool chain '$TOOLS'";
 }
