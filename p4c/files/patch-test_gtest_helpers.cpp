--- test/gtest/helpers.cpp.orig	2023-04-25 13:28:10 UTC
+++ test/gtest/helpers.cpp
@@ -19,6 +19,8 @@ limitations under the License.
 #include <sstream>
 #include <stdexcept>
 
+#include <sys/wait.h>
+
 #include "helpers.h"
 
 #include "frontends/common/applyOptionsPragmas.h"
