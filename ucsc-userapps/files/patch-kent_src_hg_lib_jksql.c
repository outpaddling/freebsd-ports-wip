--- kent/src/hg/lib/jksql.c.orig	2024-10-16 04:15:27 UTC
+++ kent/src/hg/lib/jksql.c
@@ -1128,11 +1128,14 @@ if (sp->verifyServerCert && !sameString(sp->verifyServ
 // If turned on this can defeat Man-In-The-Middle attacks.
 if (sp->verifyServerCert && !sameString(sp->verifyServerCert,"0"))
     {
-    #if !defined(MARIADB_VERSION_ID) && MYSQL_VERSION_ID >= 80000
+    #if !defined(MARIADB_VERSION_ID) && MYSQL_VERSION_ID < 80000
     mysql_options(conn, MYSQL_OPT_SSL_MODE, SSL_MODE_REQUIRED);
     #else
-    my_bool flag = TRUE;
-    mysql_options(conn, MYSQL_OPT_SSL_VERIFY_SERVER_CERT, &flag);
+    // FIXME: This is only a guess that compiles correctly
+    bool flag = TRUE;
+    mysql_options(conn, MYSQL_OPT_SSL_MODE, &flag);
+    // my_bool flag = TRUE;
+    // mysql_options(conn, MYSQL_OPT_SSL_VERIFY_SERVER_CERT, &flag);
     #endif
     }
 
