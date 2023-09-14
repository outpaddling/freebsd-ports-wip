--- tests/time-max-rss.sh.orig	2023-09-14 02:47:32 UTC
+++ tests/time-max-rss.sh
@@ -32,13 +32,13 @@ time-aux || framework_failure_ "time-aux is missing/no
 env time -o mem-baseline -f "%M" time-aux \
   || framework_failure_ "failed to run time/time-aux (baseline max-rss)"
 
-# Allocate 5MB of RAM
-env time -o mem-5MB -f "%M" time-aux -m 5M \
-  || framework_failure_ "failed to run time/time-aux (5M max-rss)"
+# Allocate 400MB of RAM
+env time -o mem-400MB -f "%M" time-aux -m 400M \
+  || framework_failure_ "failed to run time/time-aux (400M max-rss)"
 
 # Calculate the difference
 b=$(cat mem-baseline) || framework_failure_ "failed to read mem-baseline"
-c=$(cat mem-5MB) || framework_failure_ "failed to read mem-5MB"
+c=$(cat mem-400MB) || framework_failure_ "failed to read mem-400MB"
 d=$(( c - b ))
 
 # On some systems (e.g. OpenSolaris) getrusage(2) returns zero in ru_maxrss.
@@ -48,13 +48,13 @@ test "$b" -eq "0" && test "$c" -eq 0 \
 
 # There could be alot of variation between each invocation,
 # accept a reasonable range
-if test "$d" -ge 5000 && test "$d" -le 6000 ; then
-    : # acceptable values: 5000-6000 KB
+if test "$d" -ge 400000 && test "$d" -le 500000 ; then
+    : # acceptable values: 400000-500000 KB
 else
     cat<<EOF>&2
-time(1) failed to detect 5MB allcoation.
+time(1) failed to detect 400MB allcoation.
   mem-baseline(kb): $b
-  mem-5MB(kb):      $c
+  mem-400MB(kb):      $c
   delta(kb):        $d
 EOF
     fail=1
