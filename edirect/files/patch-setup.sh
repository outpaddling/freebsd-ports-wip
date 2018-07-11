--- setup.sh.orig	2018-07-11 18:06:32 UTC
+++ setup.sh
@@ -2,45 +2,12 @@
 
 DIR="$( cd "$( dirname "$0" )" && pwd )"
 
-cat <<EOF
-
-Trying to establish local installations of any missing Perl modules
-(as logged in $DIR/setup-deps.log).
-Please be patient, as this step may take a little while.
-EOF
-
 cd "$DIR"
 
-mkdir -p _cpan/CPAN
-echo '1;' >> _cpan/CPAN/MyConfig.pm
-if ! perl -I_cpan -Iaux/lib/perl5 setup-deps.pl </dev/null >setup-deps.log 2>&1
-then
-  if grep '^read timeout.*HTTP' setup-deps.log >/dev/null
-  then
-    cat <<EOF
-Unable to access the Comprehensive Perl Archive Network.  You might
-need to set http_proxy and/or ftp_proxy in your user environment.
-Please consult your network administrator for suitable values.
-EOF
-  elif grep '^SSLeay\.xs:.*[Ee]rror:' setup-deps.log >/dev/null
-  then
-    cat <<EOF
-Unable to build Net::SSLeay.  Please install either a prebuilt version
-of this module or OpenSSL development files to build it against.
-EOF
-  fi
-fi
-rm -rf _cpan
-
-if ! perl -Iaux/lib/perl5 -MMozilla::CA -e '1;' 2>/dev/null
-then
-  gzip -cd Mozilla-CA.tar.gz | tar xvf -
-fi
-
 osname=`uname -s`
 cputype=`uname -m`
 case "$osname-$cputype" in
-  Linux-x86_64 )           platform=Linux ;;
+  Linux-x86_64|FreeBSD-amd64 )           platform=Linux ;;
   Darwin-x86_64 )          platform=Darwin ;;
   CYGWIN_NT-* | MINGW*-* ) platform=CYGWIN_NT ;;
   Linux-*arm* )            platform=ARM ;;
