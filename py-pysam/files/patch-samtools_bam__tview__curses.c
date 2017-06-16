--- samtools/bam_tview_curses.c.orig	2015-04-29 09:32:28 UTC
+++ samtools/bam_tview_curses.c
@@ -25,6 +25,8 @@ DEALINGS IN THE SOFTWARE.  */
 
 #undef _HAVE_CURSES
 
+#define	_CURSES_LIB	1
+
 #if _CURSES_LIB == 0
 #elif _CURSES_LIB == 1
 #include <curses.h>
