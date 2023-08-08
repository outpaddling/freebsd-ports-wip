--- tools/external/driver-tool/sratools.cpp.orig	2023-07-10 16:23:35 UTC
+++ tools/external/driver-tool/sratools.cpp
@@ -577,6 +577,14 @@ static int main(CommandLine const &argv)
 
 } // namespace sratools
 
+#if BSD
+int main(int argc, char *argv[], char *envp[])
+{
+    auto const invocation = CommandLine(argc, argv, envp, nullptr);
+    return sratools::main(invocation);
+}
+#endif
+
 #if MAC
 int main(int argc, char *argv[], char *envp[], char *apple[])
 {
