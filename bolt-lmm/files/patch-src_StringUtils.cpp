--- src/StringUtils.cpp.orig	2017-08-02 23:43:24 UTC
+++ src/StringUtils.cpp
@@ -22,6 +22,7 @@
 #include <cstdio>
 #include <iostream>
 #include <sstream>
+#include <sys/types.h>	// uint
 
 #include "StringUtils.hpp"
 
@@ -102,7 +103,7 @@ namespace StringUtils {
       string prefix, suffix;
       if (str[0] != RANGE_DELIMS[0]) prefix = tokens[0];
       if (str[str.length()-1] != RANGE_DELIMS[2]) suffix = tokens.back();
-      int start = stoi(tokens[startInd]), end = stoi(tokens[endInd]);
+      int start = StringUtils::stoi(tokens[startInd]), end = StringUtils::stoi(tokens[endInd]);
       if (start > end+1 || end > start+1000000) {
 	cerr << "ERROR: Invalid range in template string: " << str << endl;
 	cerr << "  Start: " << start << endl;
