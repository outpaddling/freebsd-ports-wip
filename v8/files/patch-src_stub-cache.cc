--- src/stub-cache.cc.orig	2020-06-09 19:09:33 UTC
+++ src/stub-cache.cc
@@ -1382,7 +1382,7 @@ Handle<Code> StubCompiler::GetCodeWithFlags(Code::Flag
                                             Handle<String> name) {
   return (FLAG_print_code_stubs && !name.is_null())
       ? GetCodeWithFlags(flags, *name->ToCString())
-      : GetCodeWithFlags(flags, reinterpret_cast<char*>(NULL));
+      : GetCodeWithFlags(flags, static_cast<char*>(NULL));
 }
 
 
