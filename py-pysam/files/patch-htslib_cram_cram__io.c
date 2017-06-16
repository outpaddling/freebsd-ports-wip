--- htslib/cram/cram_io.c.orig	2015-04-29 09:32:28 UTC
+++ htslib/cram/cram_io.c
@@ -64,6 +64,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 #include <sys/stat.h>
 #include <math.h>
 #include <ctype.h>
+#include <unistd.h>
 
 #include "cram/cram.h"
 #include "cram/os.h"
