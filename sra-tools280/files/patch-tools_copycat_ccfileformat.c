--- tools/copycat/ccfileformat.c.orig	2017-08-03 16:17:04 UTC
+++ tools/copycat/ccfileformat.c
@@ -184,11 +184,11 @@ rc_t CCFileFormatMake (CCFileFormat ** p
             KConfigRelease ( kfg );
             if ( rc == 0 )
             {
-                char magicpath[1024];
-                size_t num_writ;
-                rc = string_printf ( magicpath, sizeof ( magicpath ), &num_writ, "%S/magic", bindir );
-                StringWhack ( bindir );
-                if ( rc == 0 )
+//                char magicpath[1024];
+//                size_t num_writ;
+//                rc = string_printf ( magicpath, sizeof ( magicpath ), &num_writ, "%S/magic", bindir );
+//                StringWhack ( bindir );
+//                if ( rc == 0 )
                 {
                     rc = KExtFileFormatMake (&self->ext, exttable, sizeof (exttable) - 1,
                                              formattable, sizeof (formattable) - 1);
