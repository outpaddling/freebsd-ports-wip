--- setup.sh.orig	2018-07-06 20:21:06 UTC
+++ setup.sh
@@ -2,36 +2,8 @@
 
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
 if ! perl -Iaux/lib/perl5 -MMozilla::CA -e '1;' 2>/dev/null
 then
   gzip -cd Mozilla-CA.tar.gz | tar xvf -
@@ -56,8 +28,6 @@ fi
 if [ -f xtract."$platform" ]
 then
   chmod +x xtract."$platform"
-else
-  echo "Unable to download xtract executable."
 fi
 
 if [ -n "$platform" ]
@@ -69,8 +39,6 @@ fi
 if [ -f rchive."$platform" ]
 then
   chmod +x rchive."$platform"
-else
-  echo "Unable to download rchive executable."
 fi
 
 echo ""
