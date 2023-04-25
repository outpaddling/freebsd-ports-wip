--- frontends/common/parser_options.cpp.orig	2023-04-25 13:01:16 UTC
+++ frontends/common/parser_options.cpp
@@ -21,6 +21,7 @@ limitations under the License.
 
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 
 #include <regex>
 #include <unordered_set>
