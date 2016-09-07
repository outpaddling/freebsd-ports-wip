--- /usr/wip/biology/pbbam/work/pbbam-e46654e0e0b816230c16f4a6132c1feff633a62a/src/MD5.cpp.orig	2016-09-07 15:07:09.794164044 -0500
+++ /usr/wip/biology/pbbam/work/pbbam-e46654e0e0b816230c16f4a6132c1feff633a62a/src/MD5.cpp	2016-09-07 15:07:17.228158588 -0500
@@ -40,7 +40,7 @@
 // Author: Brett Bowman
 
 #include "pbbam/MD5.h"
-#include <cram/md5.h>
+#include <openssl/md5.h>
 
 namespace PacBio {
 namespace BAM {
