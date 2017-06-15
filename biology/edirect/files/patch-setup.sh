--- setup.sh.orig	2017-06-15 18:33:36 UTC
+++ setup.sh
@@ -2,30 +2,8 @@
 
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
-if ! perl -I_cpan setup-deps.pl </dev/null >setup-deps.log 2>&1
-then
-  if grep '^read timeout.*HTTP' setup-deps.log >/dev/null
-  then
-    cat <<EOF
-Unable to access the Comprehensive Perl Archive Network.  You might
-need to set http_proxy and/or ftp_proxy in your user environment.
-Please consult your network administrator for suitable values.
-EOF
-  fi
-fi
-rm -rf _cpan
-
 if ! perl -Iaux/lib/perl5 -MMozilla::CA -e '1;' 2>/dev/null
 then
   gzip -cd Mozilla-CA.tar.gz | tar xvf -
@@ -42,11 +20,6 @@ esac
 if [ -f xtract."$osname" ]
 then
   chmod +x xtract."$osname"
-else
-  echo "Unable to download a prebuilt xtract executable; attempting to"
-  echo "build one from xtract.go.  A Perl fallback is also available, and"
-  echo "will be used if necessary, so please disregard any errors below."
-  go build -o xtract."$osname" xtract.go
 fi
 
 echo ""
