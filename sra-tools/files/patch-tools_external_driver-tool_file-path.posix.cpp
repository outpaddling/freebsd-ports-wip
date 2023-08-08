--- tools/external/driver-tool/file-path.posix.cpp.orig	2023-07-10 16:23:35 UTC
+++ tools/external/driver-tool/file-path.posix.cpp
@@ -193,7 +193,12 @@ static char const *find_executable_path(char const *co
 FilePath FilePath::fullPathToExecutable(char const *const *const argv, char const *const *const envp, char const *const *const extra)
 {
     char const *path;
-#if LINUX
+// FIXME: Temporary hack for testing
+#if BSD
+    char full_path[1024];
+    snprintf(full_path, 1024, "/usr/local/bin/%s", argv[0]);
+    path = full_path;
+#elif LINUX
     path = "/proc/self/exe";
 #elif MAC
     path = find_executable_path(extra, argv[0]);
