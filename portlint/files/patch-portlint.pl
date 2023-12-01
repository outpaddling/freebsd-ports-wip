--- portlint.pl.orig	2023-12-01 13:34:52 UTC
+++ portlint.pl
@@ -1406,6 +1406,11 @@ sub checkmakefile {
 			}
 		}
 		$rawwhole .= $_;
+		if (/\\$/) {
+			# Concat continued lines.
+			chomp $rawwhole;
+			chop $rawwhole;
+		}
 	}
 	close(IN);
 
