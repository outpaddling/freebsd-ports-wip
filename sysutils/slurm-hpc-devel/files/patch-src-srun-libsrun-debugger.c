--- src/srun/libsrun/debugger.c.orig	2013-03-27 10:59:55.000000000 -0500
+++ src/srun/libsrun/debugger.c	2013-03-27 11:00:39.000000000 -0500
@@ -38,6 +38,10 @@
  *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 \*****************************************************************************/
 
+#if defined(__FreeBSD__)
+#include <signal.h>
+#endif
+
 #if HAVE_CONFIG_H
 #  include "config.h"
 #endif
