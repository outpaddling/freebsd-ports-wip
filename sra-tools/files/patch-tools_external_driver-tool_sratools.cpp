--- tools/external/driver-tool/sratools.cpp.orig	2023-07-10 16:23:35 UTC
+++ tools/external/driver-tool/sratools.cpp
@@ -585,6 +585,14 @@ int main(int argc, char *argv[], char *envp[], char *a
 }
 #endif
 
+#ifdef BSD
+int main(int argc, char *argv[], char *envp[])
+{
+    auto const invocation = CommandLine(argc, argv, envp, nullptr);
+    return sratools::main(invocation);
+}
+#endif
+
 #if LINUX
 int main(int argc, char *argv[], char *envp[])
 {
