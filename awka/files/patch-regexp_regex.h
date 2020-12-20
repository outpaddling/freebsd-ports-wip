--- regexp/regex.h.orig	2020-12-20 21:43:30 UTC
+++ regexp/regex.h
@@ -540,7 +540,7 @@ extern int re_exec _RE_ARGS ((const char *));
 /* POSIX compatibility.  */
 /* extern int regcomp _RE_ARGS ((awka_regexp *__preg, const char *__pattern,
                               int __cflags)); */
-extern awka_regexp * awka_regcomp _RE_ARGS ((char *__pattern, char gsub));
+extern awka_regexp * awka_regcomp _RE_ARGS ((char *__pattern, int gsub));
 
 extern int awka_regexec _RE_ARGS ((awka_regexp *__preg,
                               char *__string, size_t __nmatch,
